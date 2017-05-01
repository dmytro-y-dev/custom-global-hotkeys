#include "ExecuteFileAction.h"

using CustomGlobalHotkeys::Action::ExecuteFileAction;

ExecuteFileAction::ExecuteFileAction(
	const wchar_t* lpExecutable,
	const wchar_t* lpParameters,
	const wchar_t* lpWorkingDirectory
): 
	m_lpExecutable(lpExecutable),
	m_lpParameters(lpParameters),
	m_lpWorkingDirectory(lpWorkingDirectory)
{
}
