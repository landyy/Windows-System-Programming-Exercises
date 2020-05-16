// 1_GetSystemInformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
	DWORD Return;
	SYSTEM_INFO Sysinfo;
	WCHAR Buffer[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD Size = MAX_COMPUTERNAME_LENGTH + 1;

	wprintf(L"Printing System Information...\n");

	//no error handling needed
	::GetNativeSystemInfo(
		_Out_ &Sysinfo
	);
	
	wprintf(L"Page Size: %d\n", Sysinfo.dwPageSize);
	wprintf(L"Number of Processors: %d\n", Sysinfo.dwNumberOfProcessors);

	memset(Buffer, 0, MAX_COMPUTERNAME_LENGTH + 1);

	//returns BOOL type so GetLastError Must be used
	Return = ::GetComputerNameW(
		_Out_ Buffer,
		_In_ &Size
	);
	if (Return == 0) {
		wprintf(L"GetComputerNameW returned with error: %d", ::GetLastError);
		return 1;
	}
	else {
		wprintf(L"Computer Name: %ws", Buffer);
	}

	return 0;
}