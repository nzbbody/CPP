#ifndef NET_CONFIG_I_H
#define NET_CONFIG_I_H

#include <data_types.h>
#include <memory_i.h>
#include <singleton_i.h>
#include <string/string_i.h>
#include <event_timer_i.h>

#define MAC_SIZE	32

typedef struct  
{
	t_uint64	m_dataInPerSecond;
	t_uint64	m_dataOutPerSecond;
	t_uint64	m_dataInTotal;
	t_uint64	m_dataOutTotal;
}NetRealTimeInfo;

typedef struct 
{
	t_int8 eth_str[48];								//网卡名称
	t_int8 ip_str[sizeof("255.255.255.255")];		//Ip地址
	t_int8 submask_str[sizeof("255.255.255.255")];	//子网掩码
	t_int8 boardcast_str[sizeof("255.255.255.255")];//广播地址
	t_int8 gateway_str[sizeof("255.255.255.255")];	//网关地址
	t_int32 eth_speed;
	t_int8 mac_str[MAC_SIZE];
	
	NetRealTimeInfo	m_realInfo;	//网卡实时信息
}Device;

class DLL_EXPORT NetDeviceInfo
{
public:
	NetDeviceInfo();
	virtual ~NetDeviceInfo();

public:
	t_int32 init();

	t_int32 getAllNetDevice(std::vector<Device>& deviceList);
	t_int32 getNetDevice(stringI deviceName, Device& deviceResult);
	t_int32 setNetDevice(const Device& dev);

	t_int32 realInfoTimerCb(void);

public:
	static t_int32 REFLUSHTIMERCALLBACK(void*);
	
private:
	t_int32 getNetDeviceList();
	t_int32 getDeviceGateway();
	void updateDeviceRealInfo(Device &device);

private:
	std::vector<Device>		m_netDeviceVector;
	eventTimerI				m_reflushTimer;
	mutexI					m_netDeviceLock;
};

typedef singletonI<NetDeviceInfo> g_netDeviceInfoSingleton;
#endif
