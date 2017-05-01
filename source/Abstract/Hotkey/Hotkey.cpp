#include "Hotkey.h"

using CustomGlobalHotkeys::Hotkey::Hotkey;
using CustomGlobalHotkeys::Action::TActionSharedPtr;

Hotkey::Hotkey(
	TKeyModifiers modifiers,
	TVirtualKeyCode code,
	TActionSharedPtr action
):
	m_modifiers(modifiers),
	m_code(code),
	m_action(std::move(action))
{
}

Hotkey::Hotkey(
	TKeyModifiers modifiers,
	TVirtualKeyCode code,
	IAction* action
):
	Hotkey(
		modifiers,
		code,
		TActionSharedPtr(action)
	)
{
}

TActionSharedPtr Hotkey::getAction() const
{
	return m_action;
}

TVirtualKeyCode Hotkey::getCode() const
{
	return m_code;
}

TKeyModifiers Hotkey::getModifiers() const
{
	return m_modifiers;
}

void Hotkey::setAction(TActionSharedPtr action)
{
	m_action = action;
}

void Hotkey::setCode(TVirtualKeyCode code)
{
	m_code = code;
}

void Hotkey::setModifiers(TKeyModifiers modifiers)
{
	m_modifiers = modifiers;
}
