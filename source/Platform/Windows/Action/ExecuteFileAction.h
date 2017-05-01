#pragma once

#include <windows.h>

#include <Abstract/Action/ExecuteFileAction.h>

namespace CustomGlobalHotkeys {
	namespace Platform {
		namespace Windows {
			namespace Action {
				class ExecuteFileAction : public CustomGlobalHotkeys::Action::ExecuteFileAction
				{
				public:
					ExecuteFileAction(
						const wchar_t* lpExecutable,
						const wchar_t* lpParameters = 0,
						const wchar_t* lpWorkingDirectory = 0
					);

					virtual void execute() const;
				};
			}
		}
	}
}
