#pragma once

#include <memory>

#include <Action/IAction.h>
#include <Hotkey/HotkeyTypes.h>

namespace CustomGlobalHotkeys {
	namespace Hotkey {
		class Hotkey
		{
		typedef CustomGlobalHotkeys::Action::IAction IAction;
		typedef CustomGlobalHotkeys::Action::TActionSharedPtr TActionSharedPtr;

		public:
			Hotkey(
				TKeyModifiers modifiers,
				TVirtualKeyCode code,
				TActionSharedPtr action
			);

			Hotkey(
				TKeyModifiers modifiers,
				TVirtualKeyCode code,
				IAction* action
			);

			TActionSharedPtr getAction() const;
			TVirtualKeyCode getCode() const;
			TKeyModifiers getModifiers() const;

			void setAction(TActionSharedPtr action);
			void setCode(TVirtualKeyCode code);
			void setModifiers(TKeyModifiers modifiers);

		private:
			TKeyModifiers m_modifiers;
			TVirtualKeyCode m_code;
			TActionSharedPtr m_action;
		};
	}
}