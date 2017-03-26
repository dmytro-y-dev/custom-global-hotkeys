#pragma once

#include <unordered_map>

#include <Hotkey/Hotkey.h>
#include <Hotkey/HotkeyTypes.h>
#include <HotkeyManager/HotkeyManager.h>
#include <Platform/Windows/Exception/Win32APIErrorException.h>

namespace CustomGlobalHotkeys {
	namespace Platform {
		namespace Windows {
			namespace HotkeyManager {

				/**
				 * Hotkey registration manager registers and unregisters hotkeys using Win32 API calls.
				 */
				class HotkeyManager : public CustomGlobalHotkeys::HotkeyManager::HotkeyManager
				{
				typedef CustomGlobalHotkeys::Hotkey::Hotkey Hotkey;
				typedef CustomGlobalHotkeys::Action::TActionSharedPtr TActionSharedPtr;

				public:
					/**
					 * Default constructor.
					 *
					 * @param HWND associatedWindow Window to associate hotkey with.
					 */
					HotkeyManager(HWND associatedWindow = NULL);

					~HotkeyManager();

					/**
					* Register single hotkey.
					*
					* @param Hotkey hotkey Hotkey to register.
					*
					* @throws Win32APIErrorException When Win32 API call failed.
					*
					* @return THotkeyIdentifier Identifier of currently registered hotkey.
					*/
					THotkeyIdentifier registerHotkey(const Hotkey &hotkey);

					/**
					* Find action that was bound to hotkey.
					*
					* @param THotkeyIdentifier hotkeyId Identifier of registered hotkey to find action for.
					*
					* @return Returns pointer to action, if hotkey was bound; otherwise, returns nullptr.
					*/
					TActionSharedPtr findActionByHotkey(THotkeyIdentifier hotkeyId) const;

					/**
					* Unregister single hotkey.
					*
					* @param THotkeyIdentifier id Identifier of key to unregister.
					*
					* @throws std::out_of_range When hotkey identifier is not registered.
					* @throws Win32APIErrorException When Win32 API call failed.
					*/
					void unregisterHotkey(THotkeyIdentifier id);

					/**
					 * Cycle through all hotkeys and unregister them all.
					 */
					void unregisterAllHotkeys();

				private:
					/**
					 * Get identifier of next hotkey to register.
					 */
					THotkeyIdentifier getNextHotkeyIdentifier();

					/**
					* Generate next hotkey identifier and save it internally for next usages of getNextHotkeyIdentifier().
					*/
					void advanceNextHotkeyIdentifier();

				private:
					HWND m_associatedWindow;
					std::unordered_map<THotkeyIdentifier, Hotkey> m_hotkeys;

					THotkeyIdentifier m_nextHotkeyIdentifier;
				};

			}
		}
	}
}
