#pragma once

#include <windows.h>
#include <stdexcept>

namespace CustomGlobalHotkeys {
	namespace Platform {
		namespace Windows {
			namespace Exception {
				/**
				 * Generates C++ exception from Win32 API error code.
				 */
				class Win32APIErrorException : public std::exception
				{
				public:
					/**
					 * Default constructor.
					 *
					 * @param DWORD errorCode Win32 API error code.
					 */
					Win32APIErrorException(DWORD errorCode);

					/**
					 * Get formatted message that explains Win32 API error.
					 *
					 * @return char* Null-terminated string with message.
					 */
					virtual char const* what() const;

				private:
					DWORD m_errorCode;
					char* m_errorText;
				};
			}
		}
	}
}
