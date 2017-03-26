#include "Win32APIErrorException.h"

Win32APIErrorException::Win32APIErrorException(DWORD errorCode) :
	std::exception(), m_errorCode(errorCode)
{
	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, m_errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL
	);

	m_errorText = new char[size+1];
	strncpy(m_errorText, messageBuffer, size+1);

	LocalFree(messageBuffer);
}

char const* Win32APIErrorException::what() const
{
	return m_errorText;
}