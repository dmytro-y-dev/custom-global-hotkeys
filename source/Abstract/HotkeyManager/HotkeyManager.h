#pragma once

#include <unordered_map>

#include <Abstract/Hotkey/Hotkey.h>
#include <Abstract/Hotkey/HotkeyTypes.h>

namespace CustomGlobalHotkeys {
	namespace HotkeyManager {
		/**
		 * Hotkey registration manager registers and unregisters hotkeys.
		 */
		class HotkeyManager
		{
		typedef	CustomGlobalHotkeys::Action::TActionSharedPtr TActionSharedPtr;
		typedef	CustomGlobalHotkeys::Hotkey::Hotkey Hotkey;

		public:
			virtual ~HotkeyManager() {}

			/**
			* Register single hotkey.
			*
			* @param Hotkey hotkey Hotkey to register.
			*
			* @return THotkeyIdentifier Identifier of currently registered hotkey.
			*/
			virtual THotkeyIdentifier registerHotkey(const Hotkey &hotkey) = 0;

			/**
			* Find action that was bound to hotkey.
			*
			* @param THotkeyIdentifier hotkeyId Identifier of registered hotkey to find action for.
			*
			* @return Returns pointer to action, if hotkey was bound; otherwise, returns nullptr.
			*/
			virtual TActionSharedPtr findActionByHotkey(THotkeyIdentifier hotkeyId) const = 0;

			/**
			* Unregister single hotkey.
			*
			* @param THotkeyIdentifier id Identifier of key to unregister.
			*
			* @throws std::out_of_range When hotkey identifier is not registered.
			*/
			virtual void unregisterHotkey(THotkeyIdentifier id) = 0;

			/**
			 * Cycle through all hotkeys and unregister them all.
			 */
			virtual void unregisterAllHotkeys() = 0;
		};
	}
}