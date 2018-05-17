#include "Utils.h"

#include "stdio.h"

void PrintDevice(const DEVICE_NET_INFO& device)
{
	if(device.byIPVersion == 4)
	{
		printf("Version[%d],IP[%s],Port[%d],SubMask[%s],GateWay[%s],Mac[%s],DeviceType[%s],ManuFacture[%d]\n\n",
			device.byIPVersion,
			device.szIP,
			device.nPort,
			device.szSubmask,
			device.szGateway,
			device.szMac,
			device.szDeviceType,
			device.byManuFactory);
	}
	else
	{
		printf("Version[%d],IP[%s],Port[%d],SubMask[%s],GateWay[%s],Mac[%s],DeviceType[%s],ManuFacture[%d]\n\n",
			device.byIPVersion,
			GetIPV6(device.szIP).c_str(),
			device.nPort,
			GetIPV6(device.szSubmask).c_str(),
			GetIPV6(device.szGateway).c_str(),
			device.szMac,
			device.szDeviceType,
			device.byManuFactory);
	}	
}

std::string GetIPV6(const char* const ip)
{
	char ipv6[64] = {0};
	for(int i = 0; i < 16;++i )
	{
		byte aa = 0;
		memcpy(&aa,ip+i,1);

		sprintf(ipv6,"%s%x:",ipv6,aa);
	}
	ipv6[strlen(ipv6)-1] = 0;

	return ipv6;
}
