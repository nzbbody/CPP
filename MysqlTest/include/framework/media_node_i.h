
#ifndef MEDIANODE_I_H
#define MEDIANODE_I_H
#include <framework_i.h>
#include <media_socket_i.h>
#include <media_parser_i.h>
#include <media_fifobuffer_i.h>

class mediaUnitI;
typedef enum
{
	MEDIA_NODE_CLOSE,
	MEDIA_NODE_OPEN,
	MEDIA_NODE_CONNECTED,
}mediaNodeStatus;

class mediaNodeI: public socketCbI
{
public:
	mediaNodeI();
	virtual ~mediaNodeI();

public:

	/** 
	* 	func name:	open
	*	@brief:		��һ������
	*	@param:		remoteIp:remotePortԶ�̵�ַ��localIp:localPort���ص�ַ��type��socket����
	*	@return:	E_OK������ִ�гɹ���E_FAIL:����ִ��ʧ��
	*	@author:	zhang_xusheng
	*	@note:		��������Ĭ�ϲ���UDP����
	*
	*/
	virtual t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, t_int8 *localIp, t_uint16 localPort, enumMediaSocket type = TRANS_UDP_CONNECT);
	virtual t_int32 open(t_int8* localIp, t_uint16 localPort, enumMediaSocket type = TRANS_UDP_LISTEN);

	/** 
	* 	func name:	connectTo
	*	@brief:		����һ������
	*	@param:		remoteIp:remotePortԶ�̵�ַ��localIp:localPort���ص�ַ��type��socket����
	*	@return:	E_OK������ִ�гɹ���E_FAIL:����ִ��ʧ��
	*	@author:	zhang_xusheng
	*	@note:		��������Ĭ�ϲ���UDP����
	*
	*/
	virtual t_int32 connectTo(t_int8* remoteIp, t_uint16 remotePort);//��mediaNodeΪUDP������ʱ���ã�����������Ŀ��Զ˷�������
	virtual t_int32 close(t_handler peer);//��mediaNodeΪUDP������ʱ���ã���connectTo���ʹ��

	virtual t_int32 close();//�ر�mediaNodeƽ̨
	virtual t_int32 setCallback(mediaCbI* callback, void* callbackArg);	//����mediaNode�Ļص�����

public:
	//mediaNode�������ݣ�send()����������Զ˷���
	virtual t_int32 send(t_int8* buffer, t_int32 buffLen);
	virtual t_int32 send(mediaRawPacketI* packet);
	virtual t_int32 send(mediaPacketI* packet);

public:	
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);//��mediaNode�յ�����ʱͨ��onData�ص����ϲ��û�
	virtual t_int32 onConnect(t_handler handlerId, void *arg);//��mediaNode���ӽ�����ɺ�ͨ��onConnect֪ͨ�ϲ��û�
	virtual t_int32 onConnect(t_handler handlerId, t_handler peer, t_int8* remoteIp, t_uint16 remotePort);//��mediaNode����������ɺ�ͨ���ýӿ�֪ͨ�ϲ��û�
	virtual t_int32 onDisconnect(t_handler handlerId, void* arg);//��mediaNode�Ͽ�����ʱͨ��onDisconnect֪ͨ�ϲ��û�

public:
	t_int32 onOpenFailed(t_handler handerId);
	t_int32 onCloseFailed(t_handler handerId);

public:
	virtual t_int32 createParser(mediaParserI* parser);//����������ý��Э������Ľ�����
	virtual t_int32 createParserInstance(t_int8* dllPath);
	virtual mediaParserI* getParser();

public:
	virtual t_int8*		getRemoteIp();	//��ȡԶ�����ӵ�IP��ַ
	virtual t_uint16	getRemotePort();//��ȡԶ�����ӵĶ˿ں�	
	virtual t_int8*		getLocalIp();	//��ȡ�������ӵ�IP��ַ
	virtual t_uint16	getLocalPort();	//��ȡ�������ӵĶ˿ں�
	mediaNodeStatus getNodeStatus();	//��ȡ��ǰmediaNode��״̬
	void* getPeerStream();				//��mediaNodeΪpeerStream����ʱר��

public:
	t_int32		setSwitchList(mediaUnitI* group);//���õ�ǰ�����������
	mediaUnitI*	getSwitchList();//��ȡ��ǰ������������

public:
	//����ӿ����ڶ��߳�ģ��ʹ��
	t_int32 threadOpen();
	t_int32 threadClose();
	t_int32 setThreadId(t_int32 threadId);
	t_int32 getThreadId();

private:
	mediaNodeStatus		m_status;			//mediaNode״̬
	mutexI				m_statusLock;		//

private:
	enumMediaSocket		m_socketType;		//mediaNode����������
	mediaSocketI*		m_connect;			//mediaNode������ָ��
	mediaSocketI*		m_exconnect;		//mediaNode������ָ�룬����RTCPЭ������
	mediaCbI*			m_callback;			//mediaNode�Ļص�ָ��
	void*				m_args;				//mediaNode�Ļص�����

	t_int8				m_rIp[sizeof("255.255.255.255")];
	t_uint16			m_rPort;
	t_int8				m_lIp[sizeof("255.255.255.255")];
	t_uint16			m_lPort;

private:
	mediaFIFOBuffer		m_buffer;
private:
	mediaParserI*		m_parser;
	mediaUnitI*			m_switch;
	mutexI				m_switchMutex;

private:
	t_int32				m_threadId;
};

#endif
