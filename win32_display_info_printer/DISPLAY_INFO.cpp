#include "DISPLAY_INFO.h"
#include <iostream>
int main() {
	DISPLAY_INFO inf;
	inf.PrintDisplayInfo(false);
}

void DISPLAY_INFO::PrintField(const char* field, WCHAR* charArray)
{
	std::cout << field << ": ";
	printf("%S", charArray);
	std::cout << "\n";
}

void DISPLAY_INFO::PrintFlags(DWORD flags)
{
	if ((flags & DISPLAY_DEVICE_ACTIVE) == DISPLAY_DEVICE_ACTIVE) {
		std::cout << "DISPLAY_DEVICE_ACTIVE, ";
	}

	if ((flags & DISPLAY_DEVICE_MIRRORING_DRIVER) == DISPLAY_DEVICE_MIRRORING_DRIVER) {
		std::cout << "DISPLAY_DEVICE_MIRRORING_DRIVER, ";
	}

	if ((flags & DISPLAY_DEVICE_MODESPRUNED) == DISPLAY_DEVICE_MODESPRUNED) {
		std::cout << "DISPLAY_DEVICE_MODESPRUNED, ";
	}

	if ((flags & DISPLAY_DEVICE_PRIMARY_DEVICE) == DISPLAY_DEVICE_PRIMARY_DEVICE) {
		std::cout << "DISPLAY_DEVICE_PRIMARY_DEVICE, ";
	}

	if ((flags & DISPLAY_DEVICE_REMOVABLE) == DISPLAY_DEVICE_REMOVABLE) {
		std::cout << "DISPLAY_DEVICE_REMOVABLE, ";
	}

	if ((flags & DISPLAY_DEVICE_VGA_COMPATIBLE) == DISPLAY_DEVICE_VGA_COMPATIBLE) {
		std::cout << "DISPLAY_DEVICE_VGA_COMPATIBLE";
	}

	std::cout << "\n";
}

void DISPLAY_INFO::PrintDisplayInfo(bool includePseudoMonitors)
{
	DISPLAY_DEVICE device, de;
	device.cb = sizeof(DISPLAY_DEVICE);

	for (DWORD id = 0; EnumDisplayDevices(NULL, id, &device, 1); id++) {
		std::cout << "------- ID " << id << " -------\n";
		PrintField("Device name", device.DeviceName);
		PrintField("Device string: ", device.DeviceString);
		PrintField("Device Key", device.DeviceKey);
		std::cout << "State flags: ";
		PrintFlags(device.StateFlags);

		de.cb = sizeof(DISPLAY_DEVICE);
		if (EnumDisplayDevices(device.DeviceName, 0, &de, 1))
		{
			std::cout << "Extended State flags: ";
			PrintFlags(de.StateFlags);
			PrintField("Device ID", de.DeviceID);
		}
		std::cout << "\n\n";
	}
}
