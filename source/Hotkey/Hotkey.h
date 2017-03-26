#pragma once

#include <memory>

#include <Action/Action.h>
#include "HotkeyTypes.h"

class Hotkey
{
public:
	Hotkey(
		TKeyModifiers modifiers,
		TVirtualKeyCode code,
		std::shared_ptr<Action> action
	);

	std::shared_ptr<Action> getAction() const;
	TVirtualKeyCode getCode() const;
	TKeyModifiers getModifiers() const;

	void setAction(std::shared_ptr<Action> action);
	void setCode(TVirtualKeyCode code);
	void setModifiers(TKeyModifiers modifiers);

private:
	TKeyModifiers m_modifiers;
	TVirtualKeyCode m_code;
	std::shared_ptr<Action> m_action;
};