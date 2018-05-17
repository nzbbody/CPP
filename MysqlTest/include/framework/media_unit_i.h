#ifndef MEDIA_NODE_MANAGER_I_H
#define MEDIA_NODE_MANAGER_I_H
#include <framework_i.h>
#include <media_node_i.h>
#include <media_packet_i.h>

#define PACKET_MAXSIZE	1460

class mediaUnitI : public socketCbI
{
public:
	mediaUnitI();
	virtual ~mediaUnitI();

public:
	t_int32 nodeAddList(mediaNodeI* node);//��mediaUnit�����node
	t_int32 nodeDelList(mediaNodeI* node);//��mediaUnit��ɾ��node
	t_int32 nodeDelAll();//ɾ��mediaUnit������node
	t_int32 nodeListIsEmpty();
public:
	t_int32 unitAddList(mediaUnitI* unit);//���ת��mediaUnit
	t_int32 unitDelList(mediaUnitI* unit);//ɾ��ת��mediaUnit
	t_int32 unitDelAll();//ɾ������mediaUnit

public:
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);//�յ�����
	virtual t_int32 onClose(t_handler handlerId, void *arg);
	virtual t_int32 onConnect(t_handler handlerId, void *arg);
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg);

public:
	t_int32 send(t_int8* buff, t_int32 buffLen);//��������
	t_int32 send(mediaNodeI* node, t_int8* buff, t_int32 buffLen);

private:
	std::vector<mediaNodeI*>	m_nodeList;
	mutexI				m_listLock;
	listI<mediaUnitI*>	m_dispatchList;
	mediaParserI		*m_parse;
};


#endif
