#include "Hotkey.h"

Hotkey::Hotkey(
	TKeyModifiers modifiers,
	TVirtualKeyCode code,
	std::shared_ptr<Action> action
) :
	m_modifiers(modifiers),
	m_code(code),
	m_action(std::move(action))
{
}

std::shared_ptr<Action> Hotkey::getAction() const
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

void Hotkey::setAction(std::shared_ptr<Action> action)
{
	m_action = std::move(action);
}

void Hotkey::setCode(TVirtualKeyCode code)
{
	m_code = code;
}

void Hotkey::setModifiers(TKeyModifiers modifiers)
{
	m_modifiers = modifiers;
}
