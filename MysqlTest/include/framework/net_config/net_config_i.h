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
	t_int8 eth_str[48];								//��������
	t_int8 ip_str[sizeof("255.255.255.255")];		//Ip��ַ
	t_int8 submask_str[sizeof("255.255.255.255")];	//��������
	t_int8 boardcast_str[sizeof("255.255.255.255")];//�㲥��ַ
	t_int8 gateway_str[sizeof("255.255.255.255")];	//���ص�ַ
	t_int32 eth_speed;
	t_int8 mac_str[MAC_SIZE];
	
	NetRealTimeInfo	m_realInfo;	//����ʵʱ��Ϣ
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
