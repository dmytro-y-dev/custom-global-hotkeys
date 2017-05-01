#pragma once

#include <Abstract/Action/ActionInterface.h>

namespace CustomGlobalHotkeys {
	namespace Action {
		class ExecuteFileAction : public ActionInterface
		{
		public:
			ExecuteFileAction(
				const wchar_t* lpExecutable,
				const wchar_t* lpParameters = 0,
				const wchar_t* lpWorkingDirectory = 0
			);

			virtual void execute() const = 0;

		protected:
			const wchar_t* m_lpExecutable;
			const wchar_t* m_lpParameters;
			const wchar_t* m_lpWorkingDirectory;
		};
	}
}