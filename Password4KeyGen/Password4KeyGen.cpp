//#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <iphlpapi.h>

// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")
#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))

int main(void)
{
	// Password 4 is serial number of disk
	DWORD diskSerial;
	GetVolumeInformation(NULL, NULL, NULL, &diskSerial, NULL, NULL, NULL, NULL);
	printf("Password 4: %d\n", diskSerial);


	// Password 5 is using the ipv4 network adapter address ?
	ULONG outBufLen = 15000;
	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
	PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
	pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);

	// Grab ipv4 address
	DWORD ip = 0;
	ip = GetAdaptersAddresses(AF_INET, NULL, NULL, NULL, NULL);
	if (ip == NO_ERROR) {
		pCurrAddresses = pAddresses;
		printf("Password 5: %u\n", pCurrAddresses->IfIndex);
	}
	else
		printf("Error retrieving address. Seems to do this no matter what.\n");
	
	return 0;
}
