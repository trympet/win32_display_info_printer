#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>

class DISPLAY_INFO
{
private:
	void PrintField(const char* field, WCHAR* charArray);

	void PrintFlags(DWORD flags);

public:
	void PrintDisplayInfo(bool includePseudoMonitors);
};

