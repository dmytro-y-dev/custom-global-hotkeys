#include "HotkeyManager.h"

#include <stdexcept>
#include <utility>

#include <windows.h>

HotkeyManager::HotkeyManager(HWND associatedWindow) :
	m_associatedWindow(associatedWindow),
	m_nextHotkeyIdentifier(1)
{
}

HotkeyManager::~HotkeyManager()
{
	this->unregisterAllHotkeys();
}

THotkeyIdentifier HotkeyManager::registerHotkey(const Hotkey &hotkey)
{
	THotkeyIdentifier hotkeyId = this->getNextHotkeyIdentifier();

	// 1. Register hotkey using Win32 API call

	if (RegisterHotKey(m_associatedWindow, hotkeyId, hotkey.getModifiers(), hotkey.getCode()) == 0) {
		throw Win32APIErrorException(GetLastError());
	}

	// 2. Add hotkey to list of known hotkeys

	m_hotkeys.insert(std::make_pair(hotkeyId, hotkey));

	// 3. Calculate next hotkey identifier

	this->advanceNextHotkeyIdentifier();

	return hotkeyId;
}

std::shared_ptr<Action> HotkeyManager::findActionByHotkey(THotkeyIdentifier id) const
{
	auto hotkeyIter = m_hotkeys.find(id);

	if (hotkeyIter == m_hotkeys.end()) {
		return nullptr;
	}

	return hotkeyIter->second.getAction();
}

void HotkeyManager::unregisterHotkey(THotkeyIdentifier id)
{
	// 1. Find hotkey by its id

	auto hotkeyIter = m_hotkeys.find(id);

	if (hotkeyIter == m_hotkeys.end()) {
		throw std::out_of_range("Hotkey with specified identifier is not registered");
	}

	// 2. Unregister hotkey using Win32 API call

	if (UnregisterHotKey(m_associatedWindow, id) == 0) {
		throw Win32APIErrorException(GetLastError());
	}

	// 3. Remove hotkey from list of registered hotkeys

	m_hotkeys.erase(hotkeyIter);
}

void HotkeyManager::unregisterAllHotkeys()
{
	auto hotkeyIter = m_hotkeys.begin(), hotkeyIterLast = m_hotkeys.end();

	while (hotkeyIter != hotkeyIterLast) {
		THotkeyIdentifier hotkeyId = hotkeyIter->first;

		// Call Win32 API to unregister hotkey

		if (UnregisterHotKey(m_associatedWindow, hotkeyId) == 0) {
			throw Win32APIErrorException(GetLastError());
		}

		hotkeyIter = m_hotkeys.erase(hotkeyIter);
	}
}

THotkeyIdentifier HotkeyManager::getNextHotkeyIdentifier()
{
	return m_nextHotkeyIdentifier;
}

void HotkeyManager::advanceNextHotkeyIdentifier()
{
	m_nextHotkeyIdentifier = m_nextHotkeyIdentifier + 1;
}
