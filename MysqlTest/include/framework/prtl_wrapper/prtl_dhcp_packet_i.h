

#ifndef _PRTL_DHCP_PACKET_I_H
#define _PRTL_DHCP_PACKET_I_H

#include <framework_i.h>
#include <prtl_wrapper/prtl_packet_i.h>


#define VERSION			1

#define DHCPPACKETHEAD	

#define MAX_PROTOCALLEN	5
#define MAX_COMMANDLEN	48
#define MAX_MODULELEN	48
#define	DHCP_STR_HOST_LEN	48
#define MAX_DHCPHEADLEN		256
typedef enum 
{
	DHCP_REQUEST = 1,
	DHCP_RESPONSE,
	DHCP_NOTIFY,

}dhcpPacketType;


class prtlDhcpPacketI : public prtlPacketI
{

public:
	prtlDhcpPacketI();
	virtual ~prtlDhcpPacketI();

public:
	virtual stringI getProtocal();
	virtual t_int32 getVersion();

	virtual t_int32 setMethod(t_int8 *command);
	virtual t_int32 getMethod(stringI &command);

	virtual t_int32 setPacketType(t_int32 reqOrRes);
	virtual t_int32 getPacketType();

	virtual t_int32	setModule(t_int8 *module);
	virtual t_int32	getModule(stringI &module);
	
	virtual t_int32 setBody(t_int8 *body, t_int32 bodyLen);
	virtual t_int8* getBody(t_int32 &bodyLen);

	virtual t_int32 setSequence(t_uint32 sequence);
	virtual t_int32 getSequence(t_uint32 &sequence);

	virtual t_int32 setSession(const t_uint32 session);
	virtual t_int32 getSession(t_uint32 &sequence);
public:
	stringI		m_protocal;
	t_int32		m_version;
	stringI		m_command;
	t_int32		m_type;
	stringI		m_module;
	t_uint32 	m_sequence;
	t_uint32	m_session;
	t_int32		m_textlen;
	t_int8		*m_text;

};

#endif
