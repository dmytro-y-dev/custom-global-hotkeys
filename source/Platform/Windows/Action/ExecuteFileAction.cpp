#include "ExecuteFileAction.h"

using CustomGlobalHotkeys::Platform::Windows::Action::ExecuteFileAction;

ExecuteFileAction::ExecuteFileAction(
	const wchar_t* lpExecutable,
	const wchar_t* lpParameters,
	const wchar_t* lpWorkingDirectory
): CustomGlobalHotkeys::Action::ExecuteFileAction(
	lpExecutable,
	lpParameters,
	lpWorkingDirectory
)
{
}

void ExecuteFileAction::execute() const
{
	ShellExecuteW(0, L"open", m_lpExecutable, m_lpParameters, m_lpWorkingDirectory, SW_SHOWNORMAL);
}
