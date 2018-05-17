 #ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef __PLAYRECT_defined
#define __PLAYRECT_defined
typedef struct __PLAYRECT
{
    int x;                               
    int y;                                  
    int uWidth;                            
    int uHeight;                            
}PLAYRECT;
#endif


#if (defined(_WIN32)) //windows
#define NET_DVR_API  extern "C"__declspec(dllimport)
typedef  unsigned _int64 UINT64;
#elif defined(__linux__) //linux
typedef     unsigned int    DWORD;
typedef     unsigned short  WORD;
typedef     unsigned short  USHORT;
typedef     int            LONG;
typedef  	unsigned char	BYTE ;
typedef     int BOOL;
typedef     unsigned int   	UINT;
typedef 	void* 			LPVOID;
typedef 	void* 			HANDLE;
typedef     unsigned int*  LPDWORD; 
typedef  unsigned long long UINT64;

#ifndef    TRUE
#define    TRUE	1
#endif
#ifndef    FALSE
#define	   FALSE 0
#endif
#ifndef    NULL
#define	   NULL 0
#endif

#define __stdcall 
#define CALLBACK  

#ifndef __HWND_defined
#define __HWND_defined
typedef PLAYRECT HWND;
#endif

#define NET_DVR_API extern "C"
typedef unsigned int   COLORKEY;
typedef unsigned int    COLORREF;

#ifndef __HDC_defined
#define __HDC_defined
typedef struct __DC
{
    void*   surface;                        // SDL���ڵ�Surface
    HWND    hWnd;                           // HDC���ڵĴ��ھ��
}DC;
#endif

typedef DC* HDC;

typedef struct tagInitInfo
{
    int uWidth;
    int uHeight;
}INITINFO;
#endif

//�궨��
#define MAX_NAMELEN			    16		//DVR���ص�½��
#define MAX_RIGHT			    32		//�豸֧�ֵ�Ȩ�ޣ�1-12��ʾ����Ȩ�ޣ�13-32��ʾԶ��Ȩ�ޣ�
#define NAME_LEN			    32      //�û�������
#define PASSWD_LEN			    16      //���볤��
#define SERIALNO_LEN		    48      //���кų���
#define MACADDR_LEN			    6       //mac��ַ����
#define MAX_ETHERNET		    2       //�豸������̫����
#define MAX_NETWORK_CARD        4       //�豸�������������Ŀ
#define PATHNAME_LEN		    128     //·������
#define MAX_PRESET_V13          16      //Ԥ�õ�

#define MAX_TIMESEGMENT_V30	    8       //9000�豸���ʱ�����
#define MAX_TIMESEGMENT		    4       //8000�豸���ʱ�����

#define MAX_SHELTERNUM			4       //8000�豸����ڵ�������
#define MAX_DAYS				7       //ÿ������
#define PHONENUMBER_LEN			32      //pppoe���ź�����󳤶�

#define MAX_DISKNUM_V30			33		//9000�豸���Ӳ����/* ���33��Ӳ��(����16������SATAӲ�̡�1��eSATAӲ�̺�16��NFS��) */
#define MAX_DISKNUM		        16      //8000�豸���Ӳ����
#define MAX_DISKNUM_V10		    8       //1.2�汾֮ǰ�汾

#define MAX_WINDOW_V30			32      //9000�豸������ʾ��󲥷Ŵ�����
#define MAX_WINDOW				16      //8000�豸���Ӳ����
#define MAX_VGA_V30				4       //9000�豸���ɽ�VGA��
#define MAX_VGA			    	1       //8000�豸���ɽ�VGA��

#define MAX_USERNUM_V30			32      //9000�豸����û���
#define MAX_USERNUM			    16      //8000�豸����û���
#define MAX_EXCEPTIONNUM_V30	32      //9000�豸����쳣������
#define MAX_EXCEPTIONNUM		16      //8000�豸����쳣������
#define MAX_LINK				6       //8000�豸��ͨ�������Ƶ��������

#define MAX_DECPOOLNUM			4       //��·������ÿ������ͨ������ѭ��������
#define MAX_DECNUM				4       //��·��������������ͨ������ʵ��ֻ��һ������������������
#define MAX_TRANSPARENTNUM		2       //��·���������������͸��ͨ����
#define MAX_CYCLE_CHAN			16      //��·�����������Ѳͨ����
#define MAX_CYCLE_CHAN_V30      64      //�����Ѳͨ��������չ��
#define MAX_DIRNAME_LENGTH		80      //���Ŀ¼����
#define MAX_WINDOWS				16      //��󴰿���

#define MAX_STRINGNUM_V30		8		//9000�豸���OSD�ַ�������
#define MAX_STRINGNUM			4       //8000�豸���OSD�ַ�������
#define MAX_STRINGNUM_EX		8       //8000������չ
#define MAX_AUXOUT_V30			16      //9000�豸����������
#define MAX_AUXOUT			    4       //8000�豸����������
#define MAX_HD_GROUP			16      //9000�豸���Ӳ������
#define MAX_NFS_DISK			8       //8000�豸���NFSӲ����

#define IW_ESSID_MAX_SIZE	    32      //WIFI��SSID�ų���
#define IW_ENCODING_TOKEN_MAX	32      //WIFI��������ֽ���
#define MAX_SERIAL_NUM			64	    //���֧�ֵ�͸��ͨ��·��
#define MAX_DDNS_NUMS	        10      //9000�豸������ddns��
#define MAX_DOMAIN_NAME		    64		/* ����������� */
#define MAX_EMAIL_ADDR_LEN	    48      //���email��ַ����
#define MAX_EMAIL_PWD_LEN		32      //���email���볤��

#define MAXPROGRESS		        100     //�ط�ʱ�����ٷ���
#define MAX_SERIALNUM	        2       //8000�豸֧�ֵĴ����� 1-232�� 2-485
#define CARDNUM_LEN		        20      //���ų���
#define MAX_VIDEOOUT_V30        4       //9000�豸����Ƶ�����
#define MAX_VIDEOOUT	        2       //8000�豸����Ƶ�����

#define MAX_PRESET_V30			    256		/* 9000�豸֧�ֵ���̨Ԥ�õ��� */
#define MAX_TRACK_V30			    256		/* 9000�豸֧�ֵ���̨�켣�� */
#define MAX_CRUISE_V30			    256		/* 9000�豸֧�ֵ���̨Ѳ���� */
#define MAX_PRESET				    128		/* 8000�豸֧�ֵ���̨Ԥ�õ��� */
#define MAX_TRACK				    128		/* 8000�豸֧�ֵ���̨�켣�� */
#define MAX_CRUISE				    128		/* 8000�豸֧�ֵ���̨Ѳ���� */

#define CRUISE_MAX_PRESET_NUMS	    32 	    /* һ��Ѳ������Ѳ���� */

#define MAX_SERIAL_PORT             8       //9000�豸֧��232������
#define MAX_PREVIEW_MODE            8       /* �豸֧�����Ԥ��ģʽ��Ŀ 1����,4����,9����,16����.... */
#define MAX_MATRIXOUT               16      /* ���ģ������������ */
#define LOG_INFO_LEN                11840   /* ��־������Ϣ */
#define DESC_LEN                    16      /* ��̨�����ַ������� */
#define PTZ_PROTOCOL_NUM            200     /* 9000���֧�ֵ���̨Э���� */

#define MAX_AUDIO			        1       //8000�����Խ�ͨ����
#define MAX_AUDIO_V30			    2       //9000�����Խ�ͨ����
#define MAX_CHANNUM			        16      //8000�豸���ͨ����
#define MAX_ALARMIN			        16      //8000�豸��󱨾�������
#define MAX_ALARMOUT		        4       //8000�豸��󱨾������
//9000 IPC����
#define MAX_ANALOG_CHANNUM          32      //���32��ģ��ͨ��
#define MAX_ANALOG_ALARMOUT         32      //���32·ģ�ⱨ����� 
#define MAX_ANALOG_ALARMIN          32      //���32·ģ�ⱨ������

#define MAX_IP_DEVICE               32      //������������IP�豸��
#define MAX_IP_DEVICE_V40           64      // ������������IP�豸�� ��������64�� IVMS 2000�����豸
#define MAX_IP_CHANNEL              32      //������������IPͨ����
#define MAX_IP_ALARMIN              128     //�����������౨��������
#define MAX_IP_ALARMOUT             64      //�����������౨�������

#define MAX_RECORD_FILE_NUM         20      // ÿ��ɾ�����߿�¼������ļ���
//SDK_V31 ATM
#define MAX_ACTION_TYPE	        12	    //�Զ���Э����ӽ�����Ϊ�����Ϊ���� 
#define MAX_ATM_PROTOCOL_NUM    256   //ÿ�����뷽ʽ��Ӧ��ATM���Э����
#define  ATM_CUSTOM_PROTO       1025   //�Զ���Э�� ֵΪ1025
#define ATM_PROTOCOL_SORT       4       //ATMЭ����� 
#define ATM_DESC_LEN            32      //ATM�����ַ�������
// SDK_V31 ATM

/* ���֧�ֵ�ͨ���� ���ģ��������IP֧�� */
#define MAX_CHANNUM_V30               ( MAX_ANALOG_CHANNUM + MAX_IP_CHANNEL )//64
#define MAX_ALARMOUT_V30              ( MAX_ANALOG_ALARMOUT + MAX_IP_ALARMOUT )//96
#define MAX_ALARMIN_V30               ( MAX_ANALOG_ALARMIN + MAX_IP_ALARMIN )//160

#define MAX_LANERECT_NUM        5    //�����ʶ��������
#define MAX_FORTIFY_NUM     10   //��󲼷�����
#define MAX_INTERVAL_NUM    4    //���ʱ��������
#define MAX_CHJC_NUM        3    //�����ʡ�ݼ���ַ�����
#define MAX_VL_NUM          5    //���������Ȧ����
#define MAX_DRIVECHAN_NUM       16       //��󳵵���
#define MAX_COIL_NUM             3        //�����Ȧ����
#define MAX_SIGNALLIGHT_NUM    6   //����źŵƸ���

/*******************ȫ�ִ����� begin**********************/	
#define NET_DVR_NOERROR 					0	//û�д���
#define NET_DVR_PASSWORD_ERROR 				1	//�û����������
#define NET_DVR_NOENOUGHPRI 				2	//Ȩ�޲���
#define NET_DVR_NOINIT 						3	//û�г�ʼ��
#define NET_DVR_CHANNEL_ERROR 				4	//ͨ���Ŵ���
#define NET_DVR_OVER_MAXLINK 				5	//���ӵ�DVR�Ŀͻ��˸����������
#define NET_DVR_VERSIONNOMATCH				6	//�汾��ƥ��
#define NET_DVR_NETWORK_FAIL_CONNECT		7	//���ӷ�����ʧ��
#define NET_DVR_NETWORK_SEND_ERROR			8	//�����������ʧ��
#define NET_DVR_NETWORK_RECV_ERROR			9	//�ӷ�������������ʧ��
#define NET_DVR_NETWORK_RECV_TIMEOUT		10	//�ӷ������������ݳ�ʱ
#define NET_DVR_NETWORK_ERRORDATA			11	//���͵���������
#define NET_DVR_ORDER_ERROR					12	//���ô������
#define NET_DVR_OPERNOPERMIT				13	//�޴�Ȩ��
#define NET_DVR_COMMANDTIMEOUT				14	//DVR����ִ�г�ʱ
#define NET_DVR_ERRORSERIALPORT				15	//���ںŴ���
#define NET_DVR_ERRORALARMPORT				16	//�����˿ڴ���
#define NET_DVR_PARAMETER_ERROR 			17  //��������
#define NET_DVR_CHAN_EXCEPTION				18	//������ͨ�����ڴ���״̬
#define NET_DVR_NODISK						19	//û��Ӳ��
#define NET_DVR_ERRORDISKNUM				20	//Ӳ�̺Ŵ���
#define NET_DVR_DISK_FULL					21	//������Ӳ����
#define NET_DVR_DISK_ERROR					22	//������Ӳ�̳���
#define NET_DVR_NOSUPPORT					23	//��������֧��
#define NET_DVR_BUSY						24	//������æ
#define NET_DVR_MODIFY_FAIL					25	//�������޸Ĳ��ɹ�
#define NET_DVR_PASSWORD_FORMAT_ERROR		26	//���������ʽ����ȷ
#define NET_DVR_DISK_FORMATING				27	//Ӳ�����ڸ�ʽ����������������
#define NET_DVR_DVRNORESOURCE				28	//DVR��Դ����
#define	NET_DVR_DVROPRATEFAILED				29  //DVR����ʧ��
#define NET_DVR_OPENHOSTSOUND_FAIL 			30  //��PC����ʧ��
#define NET_DVR_DVRVOICEOPENED 				31  //�����������Խ���ռ��
#define	NET_DVR_TIMEINPUTERROR				32  //ʱ�����벻��ȷ
#define	NET_DVR_NOSPECFILE					33  //�ط�ʱ������û��ָ�����ļ�
#define NET_DVR_CREATEFILE_ERROR			34	//�����ļ�����
#define	NET_DVR_FILEOPENFAIL				35  //���ļ�����
#define	NET_DVR_OPERNOTFINISH				36  //�ϴεĲ�����û�����
#define	NET_DVR_GETPLAYTIMEFAIL				37  //��ȡ��ǰ���ŵ�ʱ�����
#define	NET_DVR_PLAYFAIL					38  //���ų���
#define NET_DVR_FILEFORMAT_ERROR			39  //�ļ���ʽ����ȷ
#define NET_DVR_DIR_ERROR					40	//·������
#define NET_DVR_ALLOC_RESOURCE_ERROR		41  //��Դ�������
#define NET_DVR_AUDIO_MODE_ERROR			42	//����ģʽ����
#define NET_DVR_NOENOUGH_BUF				43	//������̫С
#define NET_DVR_CREATESOCKET_ERROR		 	44	//����SOCKET����
#define NET_DVR_SETSOCKET_ERROR				45	//����SOCKET����
#define NET_DVR_MAX_NUM						46	//�����ﵽ���
#define NET_DVR_USERNOTEXIST				47	//�û�������
#define NET_DVR_WRITEFLASHERROR				48  //дFLASH����
#define NET_DVR_UPGRADEFAIL					49  //DVR����ʧ��
#define NET_DVR_CARDHAVEINIT				50  //���뿨�Ѿ���ʼ����
#define NET_DVR_PLAYERFAILED				51	//���ò��ſ���ĳ������ʧ��
#define NET_DVR_MAX_USERNUM					52  //�豸���û����ﵽ���
#define NET_DVR_GETLOCALIPANDMACFAIL		53  //��ÿͻ��˵�IP��ַ��������ַʧ��
#define NET_DVR_NOENCODEING					54	//��ͨ��û�б���
#define NET_DVR_IPMISMATCH					55	//IP��ַ��ƥ��
#define NET_DVR_MACMISMATCH					56	//MAC��ַ��ƥ��
#define NET_DVR_UPGRADELANGMISMATCH			57	//�����ļ����Բ�ƥ��
#define NET_DVR_MAX_PLAYERPORT				58	//������·���ﵽ���
#define NET_DVR_NOSPACEBACKUP				59	//�����豸��û���㹻�ռ���б���
#define NET_DVR_NODEVICEBACKUP				60	//û���ҵ�ָ���ı����豸
#define NET_DVR_PICTURE_BITS_ERROR			61	//ͼ����λ����������24ɫ
#define NET_DVR_PICTURE_DIMENSION_ERROR		62	//ͼƬ��*�����ޣ� ��128*256
#define NET_DVR_PICTURE_SIZ_ERROR			63	//ͼƬ��С���ޣ���100K
#define NET_DVR_LOADPLAYERSDKFAILED			64	//���뵱ǰĿ¼��Player Sdk����
#define NET_DVR_LOADPLAYERSDKPROC_ERROR		65	//�Ҳ���Player Sdk��ĳ���������
#define NET_DVR_LOADDSSDKFAILED				66	//���뵱ǰĿ¼��DSsdk����
#define NET_DVR_LOADDSSDKPROC_ERROR		    67	//�Ҳ���DsSdk��ĳ���������
#define NET_DVR_DSSDK_ERROR					68	//����Ӳ�����DsSdk��ĳ������ʧ��
#define NET_DVR_VOICEMONOPOLIZE				69	//��������ռ
#define NET_DVR_JOINMULTICASTFAILED			70	//����ಥ��ʧ��
#define NET_DVR_CREATEDIR_ERROR				71	//������־�ļ�Ŀ¼ʧ��
#define NET_DVR_BINDSOCKET_ERROR			72	//���׽���ʧ��
#define NET_DVR_SOCKETCLOSE_ERROR			73	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�
#define NET_DVR_USERID_ISUSING			    74	//ע��ʱ�û�ID���ڽ���ĳ����
#define NET_DVR_SOCKETLISTEN_ERROR			75	//����ʧ��
#define NET_DVR_PROGRAM_EXCEPTION			76	//�����쳣
#define NET_DVR_WRITEFILE_FAILED			77	//д�ļ�ʧ��
#define NET_DVR_FORMAT_READONLY				78  //��ֹ��ʽ��ֻ��Ӳ��
#define NET_DVR_WITHSAMEUSERNAME		    79  //�û����ýṹ�д�����ͬ���û���
#define NET_DVR_DEVICETYPE_ERROR            80  /*�������ʱ�豸�ͺŲ�ƥ��*/
#define NET_DVR_LANGUAGE_ERROR              81  /*�������ʱ���Բ�ƥ��*/
#define NET_DVR_PARAVERSION_ERROR           82  /*�������ʱ�����汾��ƥ��*/
#define NET_DVR_IPCHAN_NOTALIVE             83  /*Ԥ��ʱ���IPͨ��������*/
#define NET_DVR_RTSP_SDK_ERROR				84	/*���ظ���IPCͨѶ��StreamTransClient.dllʧ��*/
#define NET_DVR_CONVERT_SDK_ERROR			85	/*����ת���ʧ��*/
#define NET_DVR_IPC_COUNT_OVERFLOW			86  /*��������ip����ͨ����*/
#define NET_DVR_PARAMMODE_ERROR             88 //ͼ����ǿ�ǣ�����ģʽ��������Ӳ������ʱ���ͻ��˽�����������ʱ����ֵ��
//2009-01-04 
#define NET_DVR_CODESPITTER_OFFLINE			89 //��Ƶ�ۺ�ƽ̨�������������
#define NET_DVR_BACKUP_COPYING				90  //�豸���ڱ���
//2010-01-16
#define NET_DVR_CHAN_NOTSUPPORT             91  // ͨ����֧�ָò���

#define NET_DVR_CALLINEINVALID                  92  // �߶���λ��̫���л򳤶��߲�����б 
#define NET_DVR_CALCANCELCONFLICT               93  // ȡ���궨��ͻ����������˹���ȫ�ֵ�ʵ�ʴ�С�ߴ����
#define NET_DVR_CALPOINTOUTRANGE                94 	// �궨�㳬����Χ 
#define NET_DVR_FILTERRECTINVALID               95  // �ߴ������������Ҫ��
// 2010-5-28

// ���д�����
#define RAID_ERROR_INDEX	200
#define NET_DVR_NAME_NOT_ONLY               (RAID_ERROR_INDEX + 0)  // �����Ѵ���
#define NET_DVR_OVER_MAX_ARRAY              (RAID_ERROR_INDEX + 1 ) // ���дﵽ����
#define NET_DVR_OVER_MAX_VD                 (RAID_ERROR_INDEX + 2 ) // ������̴ﵽ����
#define NET_DVR_VD_SLOT_EXCEED              (RAID_ERROR_INDEX + 3 ) // ������̲�λ����
#define NET_DVR_PD_STATUS_INVALID           (RAID_ERROR_INDEX + 4 ) // �ؽ�����������������״̬����
#define NET_DVR_PD_BE_DEDICATE_SPARE        (RAID_ERROR_INDEX + 5 ) // �ؽ�����������������Ϊָ���ȱ�
#define NET_DVR_PD_NOT_FREE                 (RAID_ERROR_INDEX + 6 ) // �ؽ����������������̷ǿ���
#define NET_DVR_CANNOT_MIG2NEWMODE          (RAID_ERROR_INDEX + 7 ) // ���ܴӵ�ǰ����������Ǩ�Ƶ��µ���������
#define NET_DVR_MIG_PAUSE                   (RAID_ERROR_INDEX + 8 ) // Ǩ�Ʋ�������ͣ
#define NET_DVR_MIG_CANCEL                  (RAID_ERROR_INDEX + 9 ) // ����ִ�е�Ǩ�Ʋ�����ȡ��
#define NET_DVR_EXIST_VD                    (RAID_ERROR_INDEX + 10) // �����������ϴ���������̣��޷�ɾ������
#define NET_DVR_TARGET_IN_LD_FUNCTIONAL     (RAID_ERROR_INDEX + 11) // ������������Ϊ���������ɲ����ҹ�������
#define NET_DVR_HD_IS_ASSIGNED_ALREADY      (RAID_ERROR_INDEX + 12) // ָ�����������̱�����Ϊ�������
#define NET_DVR_INVALID_HD_COUNT            (RAID_ERROR_INDEX + 13) // ��������������ָ����RAID�ȼ���ƥ��
#define NET_DVR_LD_IS_FUNCTIONAL            (RAID_ERROR_INDEX + 14) // �����������޷��ؽ�
#define NET_DVR_BGA_RUNNING                 (RAID_ERROR_INDEX + 15) // ��������ִ�еĺ�̨����
#define NET_DVR_LD_NO_ATAPI                 (RAID_ERROR_INDEX + 16) // �޷���ATAPI�̴����������
#define NET_DVR_MIGRATION_NOT_NEED          (RAID_ERROR_INDEX + 17) // ��������Ǩ��
#define NET_DVR_HD_TYPE_MISMATCH            (RAID_ERROR_INDEX + 18) // �������̲�����ͬ������
#define NET_DVR_NO_LD_IN_DG                 (RAID_ERROR_INDEX + 19) // ��������̣��޷����д������
#define NET_DVR_NO_ROOM_FOR_SPARE           (RAID_ERROR_INDEX + 20) // ���̿ռ��С���޷���ָ��Ϊ�ȱ���
#define NET_DVR_SPARE_IS_IN_MULTI_DG        (RAID_ERROR_INDEX + 21) // �����ѱ�����Ϊĳ�����ȱ���
#define NET_DVR_DG_HAS_MISSING_PD           (RAID_ERROR_INDEX + 22) // ����ȱ����

// ���ܴ����� 
#define VCA_ERROR_INDEX                     300 // ���ܴ���������
#define NET_DVR_ID_ERROR                    (VCA_ERROR_INDEX + 0)   // ����ID������
#define NET_DVR_POLYGON_ERROR               (VCA_ERROR_INDEX + 1)   // ����β�����Ҫ��
#define NET_DVR_RULE_PARAM_ERROR            (VCA_ERROR_INDEX + 2)   // �������������
#define NET_DVR_RULE_CFG_CONFLICT           (VCA_ERROR_INDEX + 3)   // ������Ϣ��ͻ
#define NET_DVR_CALIBRATE_NOT_READY         (VCA_ERROR_INDEX + 4)   // ��ǰû�б궨��Ϣ
#define NET_DVR_CAMERA_DATA_ERROR           (VCA_ERROR_INDEX + 5)   // ���������������
#define NET_DVR_CALIBRATE_DATA_UNFIT        (VCA_ERROR_INDEX + 6)	// ���Ȳ�����б�������ڱ궨
#define NET_DVR_CALIBRATE_DATA_CONFLICT     (VCA_ERROR_INDEX + 7)	// �궨��������Ϊ���е㹲�߻���λ��̫����
#define NET_DVR_CALIBRATE_CALC_FAIL         (VCA_ERROR_INDEX + 8)	// ������궨����ֵ����ʧ��
#define	NET_DVR_CALIBRATE_LINE_OUT_RECT		(VCA_ERROR_INDEX + 9)	// ����������궨�߳�����������Ӿ��ο�
#define NET_DVR_ENTER_RULE_NOT_READY		(VCA_ERROR_INDEX + 10)	// û�����ý�������
#define NET_DVR_AID_RULE_NO_INCLUDE_LANE	(VCA_ERROR_INDEX + 11)	// ��ͨ�¼�������û�а�����������ֵӵ�º����У�
#define NET_DVR_LANE_NOT_READY				(VCA_ERROR_INDEX + 12)	// ��ǰû�����ó���
#define NET_DVR_RULE_INCLUDE_TWO_WAY		(VCA_ERROR_INDEX + 13)	// �¼������а���2�ֲ�ͬ����
#define NET_DVR_LANE_TPS_RULE_CONFLICT      (VCA_ERROR_INDEX + 14)  // ���������ݹ����ͻ
#define NET_DVR_NOT_SUPPORT_EVENT_TYPE      (VCA_ERROR_INDEX + 15)  // ��֧�ֵ��¼�����
#define NET_DVR_LANE_NO_WAY                 (VCA_ERROR_INDEX + 16)  // ����û�з���
#define NET_DVR_SIZE_FILTER_ERROR           (VCA_ERROR_INDEX + 17)  // �ߴ���˿򲻺���

#define NET_DVR_RTSP_GETPORTFAILED			        407  //rtsp �õ��˿ڴ���
#define NET_DVR_RTSP_DESCRIBESENDTIMEOUT			411  //rtsp decribe ���ͳ�ʱ
#define NET_DVR_RTSP_DESCRIBESENDERROR				412  //rtsp decribe ����ʧ��
#define NET_DVR_RTSP_DESCRIBERECVTIMEOUT			413  //rtsp decribe ���ճ�ʱ
#define NET_DVR_RTSP_DESCRIBERECVDATALOST			414  //rtsp decribe �������ݴ���
#define NET_DVR_RTSP_DESCRIBERECVERROR			    415  //rtsp decribe ����ʧ��
#define NET_DVR_RTSP_DESCRIBESERVERERR				416  //rtsp decribe ����������401,501�ȴ���

#define NET_DVR_RTSP_SETUPSENDTIMEOUT			    421  //rtsp setup ���ͳ�ʱ
#define NET_DVR_RTSP_SETUPSENDERROR					422  //rtsp setup ���ʹ���
#define NET_DVR_RTSP_SETUPRECVTIMEOUT				423  //rtsp setup ���ճ�ʱ
#define NET_DVR_RTSP_SETUPRECVDATALOST				424  //rtsp setup �������ݴ���
#define NET_DVR_RTSP_SETUPRECVERROR					425  //rtsp setup ����ʧ��
#define NET_DVR_RTSP_OVER_MAX_CHAN					426  //rtsp setup ����������401,501�ȴ���,�������������

#define NET_DVR_RTSP_PLAYSENDTIMEOUT			    431  //rtsp play ���ͳ�ʱ
#define NET_DVR_RTSP_PLAYSENDERROR					432  //rtsp play ���ʹ���
#define NET_DVR_RTSP_PLAYRECVTIMEOUT				433  //rtsp play ���ճ�ʱ
#define NET_DVR_RTSP_PLAYRECVDATALOST				434  //rtsp play �������ݴ���
#define NET_DVR_RTSP_PLAYRECVERROR					435  //rtsp play ����ʧ��
#define NET_DVR_RTSP_PLAYSERVERERR					436  //rtsp play ����������401,501�ȴ���

#define NET_DVR_RTSP_TEARDOWNSENDTIMEOUT			441  //rtsp teardown ���ͳ�ʱ
#define NET_DVR_RTSP_TEARDOWNSENDERROR				442  //rtsp teardown ���ʹ���
#define NET_DVR_RTSP_TEARDOWNRECVTIMEOUT			443  //rtsp teardown ���ճ�ʱ
#define NET_DVR_RTSP_TEARDOWNRECVDATALOST			444  //rtsp teardown �������ݴ���
#define NET_DVR_RTSP_TEARDOWNRECVERROR				445  //rtsp teardown ����ʧ��
#define NET_DVR_RTSP_TEARDOWNSERVERERR				446  //rtsp teardown ����������401,501�ȴ���

#define  NET_PLAYM4_NOERROR					    500	//no error
#define	 NET_PLAYM4_PARA_OVER				    501	//input parameter is invalid;
#define  NET_PLAYM4_ORDER_ERROR				    502	//The order of the function to be called is error.
#define	 NET_PLAYM4_TIMER_ERROR				    503	//Create multimedia clock failed;
#define  NET_PLAYM4_DEC_VIDEO_ERROR			    504	//Decode video data failed.
#define  NET_PLAYM4_DEC_AUDIO_ERROR			    505	//Decode audio data failed.
#define	 NET_PLAYM4_ALLOC_MEMORY_ERROR		    506	//Allocate memory failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR			    507	//Open the file failed.
#define  NET_PLAYM4_CREATE_OBJ_ERROR		    508	//Create thread or event failed
#define  NET_PLAYM4_CREATE_DDRAW_ERROR		    509	//Create DirectDraw object failed.
#define  NET_PLAYM4_CREATE_OFFSCREEN_ERROR      510	//failed when creating off-screen surface.
#define  NET_PLAYM4_BUF_OVER			        511	//buffer is overflow
#define  NET_PLAYM4_CREATE_SOUND_ERROR	        512	//failed when creating audio device.	
#define	 NET_PLAYM4_SET_VOLUME_ERROR	        513	//Set volume failed
#define  NET_PLAYM4_SUPPORT_FILE_ONLY	        514	//The function only support play file.
#define  NET_PLAYM4_SUPPORT_STREAM_ONLY	        515	//The function only support play stream.
#define  NET_PLAYM4_SYS_NOT_SUPPORT		        516	//System not support.
#define  NET_PLAYM4_FILEHEADER_UNKNOWN          517	//No file header.
#define  NET_PLAYM4_VERSION_INCORRECT	        518	//The version of decoder and encoder is not adapted.  
#define  NET_PALYM4_INIT_DECODER_ERROR          519	//Initialize decoder failed.
#define  NET_PLAYM4_CHECK_FILE_ERROR	        520	//The file data is unknown.
#define  NET_PLAYM4_INIT_TIMER_ERROR	        521	//Initialize multimedia clock failed.
#define	 NET_PLAYM4_BLT_ERROR			        522	//Blt failed.
#define  NET_PLAYM4_UPDATE_ERROR		        523	//Update failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR_MULTI       524   //openfile error, streamtype is multi
#define  NET_PLAYM4_OPEN_FILE_ERROR_VIDEO       525   //openfile error, streamtype is video
#define  NET_PLAYM4_JPEG_COMPRESS_ERROR         526   //JPEG compress error
#define  NET_PLAYM4_EXTRACT_NOT_SUPPORT         527	//Don't support the version of this file.
#define  NET_PLAYM4_EXTRACT_DATA_ERROR          528	//extract video data failed.

#define NET_QOS_OK								 700					//no error
#define NET_QOS_ERROR							 (NET_QOS_OK - 1)		//qos error
#define NET_QOS_ERR_INVALID_ARGUMENTS			 (NET_QOS_OK - 2)		//invalid arguments 
#define NET_QOS_ERR_SESSION_NOT_FOUND			 (NET_QOS_OK - 3)		//session net found
#define NET_QOS_ERR_LIB_NOT_INITIALIZED          (NET_QOS_OK - 4)		//lib not initialized
#define NET_QOS_ERR_OUTOFMEM                     (NET_QOS_OK - 5)		//outtofmem
#define NET_QOS_ERR_PACKET_UNKNOW                (NET_QOS_OK - 10)		//packet unknow
#define NET_QOS_ERR_PACKET_VERSION               (NET_QOS_OK - 11)		//packet version error
#define NET_QOS_ERR_PACKET_LENGTH                (NET_QOS_OK - 12)		//packet length error
#define NET_QOS_ERR_PACKET_TOO_BIG               (NET_QOS_OK - 13)		//packet too big
#define NET_QOS_ERR_SCHEDPARAMS_INVALID_BANDWIDTH (NET_QOS_OK - 20)		//schedparams invalid bandwidth
#define NET_QOS_ERR_SCHEDPARAMS_BAD_FRACTION      (NET_QOS_OK - 21)		//schedparams bad fraction
#define NET_QOS_ERR_SCHEDPARAMS_BAD_MINIMUM_INTERVAL (NET_QOS_OK - 22)	//schedparams bad minimum interval
/*******************ȫ�ִ����� end**********************/

/*************************************************
NET_DVR_IsSupport()����ֵ
1��9λ�ֱ��ʾ������Ϣ��λ����TRUE)��ʾ֧�֣�
**************************************************/
#define NET_DVR_SUPPORT_DDRAW			0x01//֧��DIRECTDRAW�������֧�֣��򲥷������ܹ�����
#define NET_DVR_SUPPORT_BLT				0x02//�Կ�֧��BLT�����������֧�֣��򲥷������ܹ�����
#define NET_DVR_SUPPORT_BLTFOURCC		0x04//�Կ�BLT֧����ɫת���������֧�֣���������������������RGBת����
#define NET_DVR_SUPPORT_BLTSHRINKX		0x08//�Կ�BLT֧��X����С�������֧�֣�ϵͳ������������ת����
#define NET_DVR_SUPPORT_BLTSHRINKY		0x10//�Կ�BLT֧��Y����С�������֧�֣�ϵͳ������������ת����
#define NET_DVR_SUPPORT_BLTSTRETCHX		0x20//�Կ�BLT֧��X��Ŵ������֧�֣�ϵͳ������������ת����
#define NET_DVR_SUPPORT_BLTSTRETCHY		0x40//�Կ�BLT֧��Y��Ŵ������֧�֣�ϵͳ������������ת����
#define NET_DVR_SUPPORT_SSE				0x80//CPU֧��SSEָ�Intel Pentium3����֧��SSEָ�
#define NET_DVR_SUPPORT_MMX				0x100//CPU֧��MMXָ���Intel Pentium3����֧��SSEָ�

/**********************��̨�������� begin*************************/	
#define LIGHT_PWRON		2	/* ��ͨ�ƹ��Դ */
#define WIPER_PWRON		3	/* ��ͨ��ˢ���� */
#define FAN_PWRON		4	/* ��ͨ���ȿ��� */
#define HEATER_PWRON	5	/* ��ͨ���������� */
#define AUX_PWRON1		6	/* ��ͨ�����豸���� */
#define AUX_PWRON2		7	/* ��ͨ�����豸���� */
#define SET_PRESET		8	/* ����Ԥ�õ� */
#define CLE_PRESET		9	/* ���Ԥ�õ� */

#define ZOOM_IN			11	/* �������ٶ�SS���(���ʱ��) */
#define ZOOM_OUT		12	/* �������ٶ�SS��С(���ʱ�С) */
#define FOCUS_NEAR      13  /* �������ٶ�SSǰ�� */
#define FOCUS_FAR       14  /* �������ٶ�SS��� */
#define IRIS_OPEN       15  /* ��Ȧ���ٶ�SS���� */
#define IRIS_CLOSE      16  /* ��Ȧ���ٶ�SS��С */

#define TILT_UP			21	/* ��̨��SS���ٶ����� */
#define TILT_DOWN		22	/* ��̨��SS���ٶ��¸� */
#define PAN_LEFT		23	/* ��̨��SS���ٶ���ת */
#define PAN_RIGHT		24	/* ��̨��SS���ٶ���ת */
#define UP_LEFT			25	/* ��̨��SS���ٶ���������ת */
#define UP_RIGHT		26	/* ��̨��SS���ٶ���������ת */
#define DOWN_LEFT		27	/* ��̨��SS���ٶ��¸�����ת */
#define DOWN_RIGHT		28	/* ��̨��SS���ٶ��¸�����ת */
#define PAN_AUTO		29	/* ��̨��SS���ٶ������Զ�ɨ�� */

#define FILL_PRE_SEQ	30	/* ��Ԥ�õ����Ѳ������ */
#define SET_SEQ_DWELL	31	/* ����Ѳ����ͣ��ʱ�� */
#define SET_SEQ_SPEED	32	/* ����Ѳ���ٶ� */
#define CLE_PRE_SEQ		33	/* ��Ԥ�õ��Ѳ��������ɾ�� */
#define STA_MEM_CRUISE	34	/* ��ʼ��¼�켣 */
#define STO_MEM_CRUISE	35	/* ֹͣ��¼�켣 */
#define RUN_CRUISE		36	/* ��ʼ�켣 */
#define RUN_SEQ			37	/* ��ʼѲ�� */
#define STOP_SEQ		38	/* ֹͣѲ�� */
#define GOTO_PRESET		39	/* ����ת��Ԥ�õ� */

/**********************��̨�������� end*************************/	

/*************************************************
�ط�ʱ���ſ�������궨�� 
NET_DVR_PlayBackControl
NET_DVR_PlayControlLocDisplay
NET_DVR_DecPlayBackCtrl�ĺ궨��
����֧�ֲ鿴����˵���ʹ���
**************************************************/	
#define NET_DVR_PLAYSTART		1//��ʼ����
#define NET_DVR_PLAYSTOP		2//ֹͣ����
#define NET_DVR_PLAYPAUSE		3//��ͣ����
#define NET_DVR_PLAYRESTART		4//�ָ�����
#define NET_DVR_PLAYFAST		5//���
#define NET_DVR_PLAYSLOW		6//����
#define NET_DVR_PLAYNORMAL		7//�����ٶ�
#define NET_DVR_PLAYFRAME		8//��֡��
#define NET_DVR_PLAYSTARTAUDIO	9//������
#define NET_DVR_PLAYSTOPAUDIO	10//�ر�����
#define NET_DVR_PLAYAUDIOVOLUME	11//��������
#define NET_DVR_PLAYSETPOS		12//�ı��ļ��طŵĽ���
#define NET_DVR_PLAYGETPOS		13//��ȡ�ļ��طŵĽ���
#define NET_DVR_PLAYGETTIME		14//��ȡ��ǰ�Ѿ����ŵ�ʱ��(���ļ��طŵ�ʱ����Ч)
#define NET_DVR_PLAYGETFRAME	15//��ȡ��ǰ�Ѿ����ŵ�֡��(���ļ��طŵ�ʱ����Ч)
#define NET_DVR_GETTOTALFRAMES  16//��ȡ��ǰ�����ļ��ܵ�֡��(���ļ��طŵ�ʱ����Ч)
#define NET_DVR_GETTOTALTIME    17//��ȡ��ǰ�����ļ��ܵ�ʱ��(���ļ��طŵ�ʱ����Ч)
#define NET_DVR_THROWBFRAME		20//��B֡
#define NET_DVR_SETSPEED		24//���������ٶ�
#define NET_DVR_KEEPALIVE		25//�������豸������(����ص�����������2�뷢��һ��)
#define NET_DVR_PLAYSETTIME		26//������ʱ�䶨λ
#define NET_DVR_PLAYGETTOTALLEN		27//��ȡ��ʱ��طŶ�Ӧʱ����ڵ������ļ����ܳ���

//Զ�̰����������£�
/* key value send to CONFIG program */
#define KEY_CODE_1 1
#define KEY_CODE_2 2
#define KEY_CODE_3 3
#define KEY_CODE_4 4
#define KEY_CODE_5 5
#define KEY_CODE_6 6
#define KEY_CODE_7 7
#define KEY_CODE_8 8
#define KEY_CODE_9 9
#define KEY_CODE_0 10
#define KEY_CODE_POWER 11
#define KEY_CODE_MENU 12
#define KEY_CODE_ENTER 13
#define KEY_CODE_CANCEL 14
#define KEY_CODE_UP 15
#define KEY_CODE_DOWN 16
#define KEY_CODE_LEFT 17
#define KEY_CODE_RIGHT 18
#define KEY_CODE_EDIT 19
#define KEY_CODE_ADD 20
#define KEY_CODE_MINUS 21
#define KEY_CODE_PLAY 22
#define KEY_CODE_REC 23
#define KEY_CODE_PAN 24
#define KEY_CODE_M 25
#define KEY_CODE_A 26
#define KEY_CODE_F1 27
#define KEY_CODE_F2 28

/* for PTZ control */
#define KEY_PTZ_UP_START KEY_CODE_UP
#define KEY_PTZ_UP_STOP 32

#define KEY_PTZ_DOWN_START KEY_CODE_DOWN
#define KEY_PTZ_DOWN_STOP 33

#define KEY_PTZ_LEFT_START KEY_CODE_LEFT
#define KEY_PTZ_LEFT_STOP 34

#define KEY_PTZ_RIGHT_START KEY_CODE_RIGHT
#define KEY_PTZ_RIGHT_STOP 35

#define KEY_PTZ_AP1_START KEY_CODE_EDIT /* ��Ȧ+ */
#define KEY_PTZ_AP1_STOP 36

#define KEY_PTZ_AP2_START KEY_CODE_PAN /* ��Ȧ- */
#define KEY_PTZ_AP2_STOP 37

#define KEY_PTZ_FOCUS1_START KEY_CODE_A /* �۽�+ */
#define KEY_PTZ_FOCUS1_STOP 38

#define KEY_PTZ_FOCUS2_START KEY_CODE_M /* �۽�- */
#define KEY_PTZ_FOCUS2_STOP 39

#define KEY_PTZ_B1_START 40 /* �䱶+ */
#define KEY_PTZ_B1_STOP 41

#define KEY_PTZ_B2_START 42 /* �䱶- */
#define KEY_PTZ_B2_STOP 43

//9000����
#define KEY_CODE_11 44
#define KEY_CODE_12 45
#define KEY_CODE_13 46
#define KEY_CODE_14 47
#define KEY_CODE_15 48
#define KEY_CODE_16 49

#define AUDIOTALKTYPE_G722       0
#define AUDIOTALKTYPE_G711_MU    1
/*************************������������ begin*******************************/
//����NET_DVR_SetDVRConfig��NET_DVR_GetDVRConfig,ע�����Ӧ�����ýṹ

#define NET_DVR_GET_DEVICECFG		100		//��ȡ�豸����
#define NET_DVR_SET_DEVICECFG		101		//�����豸����
#define NET_DVR_GET_NETCFG			102		//��ȡ�������
#define NET_DVR_SET_NETCFG			103		//�����������
#define NET_DVR_GET_PICCFG			104		//��ȡͼ�����
#define NET_DVR_SET_PICCFG			105		//����ͼ�����
#define NET_DVR_GET_COMPRESSCFG		106		//��ȡѹ������
#define NET_DVR_SET_COMPRESSCFG		107		//����ѹ������
#define NET_DVR_GET_RECORDCFG		108		//��ȡ¼��ʱ�����
#define NET_DVR_SET_RECORDCFG		109		//����¼��ʱ�����
#define NET_DVR_GET_DECODERCFG		110		//��ȡ����������
#define NET_DVR_SET_DECODERCFG		111		//���ý���������
#define NET_DVR_GET_RS232CFG 		112		//��ȡ232���ڲ���
#define NET_DVR_SET_RS232CFG		113		//����232���ڲ���
#define NET_DVR_GET_ALARMINCFG 		114		//��ȡ�����������
#define NET_DVR_SET_ALARMINCFG		115		//���ñ����������
#define NET_DVR_GET_ALARMOUTCFG 	116		//��ȡ�����������
#define NET_DVR_SET_ALARMOUTCFG		117		//���ñ����������
#define NET_DVR_GET_TIMECFG 		118		//��ȡDVRʱ��
#define NET_DVR_SET_TIMECFG			119		//����DVRʱ��
#define NET_DVR_GET_PREVIEWCFG 		120		//��ȡԤ������
#define NET_DVR_SET_PREVIEWCFG		121		//����Ԥ������
#define NET_DVR_GET_VIDEOOUTCFG 	122		//��ȡ��Ƶ�������
#define NET_DVR_SET_VIDEOOUTCFG		123		//������Ƶ�������
#define NET_DVR_GET_USERCFG 		124		//��ȡ�û�����
#define NET_DVR_SET_USERCFG			125		//�����û�����
#define NET_DVR_GET_EXCEPTIONCFG 	126		//��ȡ�쳣����
#define NET_DVR_SET_EXCEPTIONCFG	127		//�����쳣����
#define NET_DVR_GET_ZONEANDDST		128		//��ȡʱ������ʱ�Ʋ���
#define NET_DVR_SET_ZONEANDDST		129		//����ʱ������ʱ�Ʋ���
#define NET_DVR_GET_SHOWSTRING		130		//��ȡ�����ַ�����
#define NET_DVR_SET_SHOWSTRING		131		//���õ����ַ�����
#define NET_DVR_GET_EVENTCOMPCFG	132		//��ȡ�¼�����¼�����
#define NET_DVR_SET_EVENTCOMPCFG	133		//�����¼�����¼�����

#define NET_DVR_GET_FTPCFG			134		//��ȡץͼ��FTP����(����)
#define NET_DVR_SET_FTPCFG			135		//����ץͼ��FTP����(����)

#define NET_DVR_GET_AUXOUTCFG		140		//��ȡ�������������������(HS�豸�������2006-02-28)
#define NET_DVR_SET_AUXOUTCFG		141		//���ñ������������������(HS�豸�������2006-02-28)
#define NET_DVR_GET_PREVIEWCFG_AUX 	142		//��ȡ-sϵ��˫���Ԥ������(-sϵ��˫���2006-04-13)
#define NET_DVR_SET_PREVIEWCFG_AUX	143		//����-sϵ��˫���Ԥ������(-sϵ��˫���2006-04-13)

/*********************************���ܲ��ֽӿ� begin***************************************/
//��Ϊ��Ӧ��NET_VCA_RULECFG��
#define NET_DVR_SET_RULECFG		152	//������Ϊ��������
#define NET_DVR_GET_RULECFG	    153	//��ȡ��Ϊ��������
//����궨������NET_DVR_TRACK_CFG ��
#define NET_DVR_SET_TRACK_CFG  160//������������ò��� 
#define NET_DVR_GET_TRACK_CFG  161//��ȡ��������ò���

//���ܷ�����ȡ�����ýṹ
#define NET_DVR_SET_IVMS_STREAMCFG		162		//�������ܷ�����ȡ������
#define NET_DVR_GET_IVMS_STREAMCFG		163		//��ȡ���ܷ�����ȡ������
//���ܿ��Ʋ����ṹ
#define NET_DVR_SET_VCA_CTRLCFG			164	 //�������ܿ��Ʋ���
#define NET_DVR_GET_VCA_CTRLCFG			165	 //��ȡ���ܿ��Ʋ���

//��������NET_VCA_MASK_REGION_LIST
#define NET_DVR_SET_VCA_MASK_REGION		166	 //���������������
#define NET_DVR_GET_VCA_MASK_REGION		167	 //��ȡ�����������

//ATM�������� NET_VCA_ENTER_REGION
#define NET_DVR_SET_VCA_ENTER_REGION	168	 //���ý����������
#define NET_DVR_GET_VCA_ENTER_REGION	169	 //��ȡ�����������

//�궨������NET_VCA_LINE_SEGMENT_LIST
#define NET_DVR_SET_VCA_LINE_SEGMENT	170	 //���ñ궨��
#define NET_DVR_GET_VCA_LINE_SEGMENT	171	 //��ȡ�궨��

// ivms��������NET_IVMS_MASK_REGION_LIST
#define NET_DVR_SET_IVMS_MASK_REGION	172	 //����IVMS�����������
#define NET_DVR_GET_IVMS_MASK_REGION	173	 //��ȡIVMS�����������
// ivms����������NET_IVMS_ENTER_REGION
#define NET_DVR_SET_IVMS_ENTER_REGION	174	 //����IVMS�����������
#define NET_DVR_GET_IVMS_ENTER_REGION	175	 //��ȡIVMS�����������

#define NET_DVR_SET_IVMS_BEHAVIORCFG    176	//�������ܷ�������Ϊ�������
#define NET_DVR_GET_IVMS_BEHAVIORCFG	177	//��ȡ���ܷ�������Ϊ�������

// IVMS �طż���
#define NET_DVR_IVMS_SET_SEARCHCFG		178	//����IVMS�طż�������
#define NET_DVR_IVMS_GET_SEARCHCFG		179	//��ȡIVMS�طż�������

#define NET_DVR_SET_POSITION_TRACK       180     // ���ó�������������Ϣ
#define NET_DVR_GET_POSITION_TRACK       181     // ��ȡ��������������Ϣ

#define NET_DVR_SET_CALIBRATION         182    // ���ñ궨��Ϣ
#define NET_DVR_GET_CALIBRATION         183    // ��ȡ�궨��Ϣ

#define NET_DVR_SET_PDC_RULECFG         184    // ����������ͳ�ƹ���
#define NET_DVR_GET_PDC_RULECFG         185    // ��ȡ������ͳ�ƹ���

#define NET_DVR_SET_PU_STREAMCFG        186     // ����ǰ��ȡ���豸��Ϣ
#define NET_DVR_GET_PU_STREAMCFG        187     // ��ȡǰ��ȡ���豸��Ϣ

#define NET_VCA_SET_SIZE_FILTER         194     // ����ȫ�ֳߴ������
#define NET_VCA_GET_SIZE_FILTER         195     // ��ȡȫ�ֳߴ������

#define NET_DVR_SET_TRACK_PARAMCFG       196     // ����������ز˵�����
#define NET_DVR_GET_TRACK_PARAMCFG       197     // ��ȡ������ز˵�����

#define NET_DVR_SET_DOME_MOVEMENT_PARAM 198     // ���������о����
#define NET_DVR_GET_DOME_MOVEMENT_PARAM 199     // ��ȡ�����о����

/**************************************���ܲ��ֽӿ� begin**********************************/


#define NET_DVR_GET_PICCFG_EX		200		//��ȡͼ�����(SDK_V14��չ����)
#define NET_DVR_SET_PICCFG_EX		201		//����ͼ�����(SDK_V14��չ����)
#define NET_DVR_GET_USERCFG_EX 		202		//��ȡ�û�����(SDK_V15��չ����)
#define NET_DVR_SET_USERCFG_EX		203		//�����û�����(SDK_V15��չ����)
#define NET_DVR_GET_COMPRESSCFG_EX	204		//��ȡѹ������(SDK_V15��չ����2006-05-15)
#define NET_DVR_SET_COMPRESSCFG_EX	205		//����ѹ������(SDK_V15��չ����2006-05-15)


#define NET_DVR_GET_NETAPPCFG		222		//��ȡ����Ӧ�ò��� NTP/DDNS/EMAIL
#define NET_DVR_SET_NETAPPCFG		223		//��������Ӧ�ò��� NTP/DDNS/EMAIL
#define NET_DVR_GET_NTPCFG			224		//��ȡ����Ӧ�ò��� NTP
#define NET_DVR_SET_NTPCFG			225		//��������Ӧ�ò��� NTP
#define NET_DVR_GET_DDNSCFG			226		//��ȡ����Ӧ�ò��� DDNS
#define NET_DVR_SET_DDNSCFG			227		//��������Ӧ�ò��� DDNS
//��ӦNET_DVR_EMAILPARA
#define NET_DVR_GET_EMAILCFG		228		//��ȡ����Ӧ�ò��� EMAIL
#define NET_DVR_SET_EMAILCFG		229		//��������Ӧ�ò��� EMAIL

#define NET_DVR_GET_NFSCFG			230		/* NFS disk config */
#define NET_DVR_SET_NFSCFG			231		/* NFS disk config */

#define NET_DVR_GET_SHOWSTRING_EX	238		//��ȡ�����ַ�������չ(֧��8���ַ�)
#define NET_DVR_SET_SHOWSTRING_EX	239		//���õ����ַ�������չ(֧��8���ַ�)
#define NET_DVR_GET_NETCFG_OTHER	244		//��ȡ�������
#define NET_DVR_SET_NETCFG_OTHER	245		//�����������

//��ӦNET_DVR_EMAILCFG�ṹ
#define NET_DVR_GET_EMAILPARACFG	250		//Get EMAIL parameters
#define NET_DVR_SET_EMAILPARACFG	251		//Setup EMAIL parameters


#define NET_DVR_GET_DDNSCFG_EX		274	//��ȡ��չDDNS����
#define NET_DVR_SET_DDNSCFG_EX		275	//������չDDNS����

#define	NET_DVR_SET_PTZPOS			292		//��̨����PTZλ��
#define	NET_DVR_GET_PTZPOS			293		//��̨��ȡPTZλ��
#define	NET_DVR_GET_PTZSCOPE		294		//��̨��ȡPTZ��Χ

/*********************************���ܽ�ͨ�¼�begin***************************************/
#define NET_DVR_GET_REFERENCE_REGION   400          // ��ȡ�ο�����
#define NET_DVR_SET_REFERENCE_REGION   401          // ���òο�����

#define NET_DVR_GET_TRAFFIC_MASK_REGION     402     // ��ȡ��ͨ�¼���������
#define NET_DVR_SET_TRAFFIC_MASK_REGION     403     //  ���ý�ͨ�¼���������

// #define NET_DVR_GET_SCENE_MODE          404         // ��ȡ����ģʽ
// #define NET_DVR_SET_SCENE_MODE          405         // ���ó���ģʽ 

#define NET_DVR_SET_AID_RULECFG         404         // ���ý�ͨ�¼��������
#define NET_DVR_GET_AID_RULECFG         405         // ��ȡ��ͨ�¼��������

#define NET_DVR_SET_TPS_RULECFG         406         // ���ý�ͨͳ�ƹ������
#define NET_DVR_GET_TPS_RULECFG         407         // ��ȡ��ͨͳ�ƹ������

#define NET_DVR_SET_LANECFG				408			// ���ó�������
#define	NET_DVR_GET_LANECFG				409			// ��ȡ��������


/*********************************���ܽ�ͨ�¼�end***************************************/
#define NET_DVR_SET_FACEDETECT_RULECFG     420         // ��������������
#define NET_DVR_GET_FACEDETECT_RULECFG     421         // ��ȡ����������

/***************************DS9000��������(_V30) begin *****************************/
//����(NET_DVR_NETCFG_V30�ṹ)
#define NET_DVR_GET_NETCFG_V30		    1000		//��ȡ�������
#define NET_DVR_SET_NETCFG_V30		    1001		//�����������

//ͼ��(NET_DVR_PICCFG_V30�ṹ)
#define NET_DVR_GET_PICCFG_V30		    1002		//��ȡͼ�����
#define NET_DVR_SET_PICCFG_V30		    1003		//����ͼ�����

//¼��ʱ��(NET_DVR_RECORD_V30�ṹ)
#define NET_DVR_GET_RECORDCFG_V30	    1004		//��ȡ¼�����
#define NET_DVR_SET_RECORDCFG_V30	    1005		//����¼�����

//�û�(NET_DVR_USER_V30�ṹ)
#define NET_DVR_GET_USERCFG_V30 	    1006		//��ȡ�û�����
#define NET_DVR_SET_USERCFG_V30		    1007		//�����û�����

//9000DDNS��������(NET_DVR_DDNSPARA_V30�ṹ)
#define     NET_DVR_GET_DDNSCFG_V30		1010		//��ȡDDNS(9000��չ)
#define     NET_DVR_SET_DDNSCFG_V30		1011		//����DDNS(9000��չ)

//EMAIL����(NET_DVR_EMAILCFG_V30�ṹ)
#define NET_DVR_GET_EMAILCFG_V30		1012	//��ȡEMAIL���� 
#define NET_DVR_SET_EMAILCFG_V30		1013	//����EMAIL���� 

//Ѳ������ (NET_DVR_CRUISE_PARA�ṹ)
#define 	NET_DVR_GET_CRUISE			1020		
#define 	NET_DVR_SET_CRUISE			1021		


//��������ṹ���� (NET_DVR_ALARMINCFG_V30�ṹ)
#define 	NET_DVR_GET_ALARMINCFG_V30			1024		
#define 	NET_DVR_SET_ALARMINCFG_V30			1025

//��������ṹ���� (NET_DVR_ALARMOUTCFG_V30�ṹ)
#define 	NET_DVR_GET_ALARMOUTCFG_V30			1026		
#define 	NET_DVR_SET_ALARMOUTCFG_V30			1027

//��Ƶ����ṹ���� (NET_DVR_VIDEOOUT_V30�ṹ)
#define 	NET_DVR_GET_VIDEOOUTCFG_V30			1028		
#define 	NET_DVR_SET_VIDEOOUTCFG_V30			1029	

//�����ַ��ṹ���� (NET_DVR_SHOWSTRING_V30�ṹ)
#define 	NET_DVR_GET_SHOWSTRING_V30			1030		
#define 	NET_DVR_SET_SHOWSTRING_V30			1031

//�쳣�ṹ���� (NET_DVR_EXCEPTION_V30�ṹ)
#define 	NET_DVR_GET_EXCEPTIONCFG_V30		1034		
#define 	NET_DVR_SET_EXCEPTIONCFG_V30		1035

//����232�ṹ���� (NET_DVR_RS232CFG_V30�ṹ)
#define 	NET_DVR_GET_RS232CFG_V30			1036		
#define 	NET_DVR_SET_RS232CFG_V30			1037

//����Ӳ�̽���ṹ���� (NET_DVR_NET_DISKCFG�ṹ)
#define		NET_DVR_GET_NET_DISKCFG				1038		//����Ӳ�̽����ȡ
#define		NET_DVR_SET_NET_DISKCFG				1039		//����Ӳ�̽�������
//ѹ������ (NET_DVR_COMPRESSIONCFG_V30�ṹ)
#define     NET_DVR_GET_COMPRESSCFG_V30	        1040		
#define     NET_DVR_SET_COMPRESSCFG_V30	        1041		

//��ȡ485���������� (NET_DVR_DECODERCFG_V30�ṹ)
#define     NET_DVR_GET_DECODERCFG_V30		    1042		//��ȡ����������
#define     NET_DVR_SET_DECODERCFG_V30		    1043		//���ý���������

//��ȡԤ������ (NET_DVR_PREVIEWCFG_V30�ṹ)
#define     NET_DVR_GET_PREVIEWCFG_V30		    1044		//��ȡԤ������
#define     NET_DVR_SET_PREVIEWCFG_V30		    1045		//����Ԥ������

//����Ԥ������ (NET_DVR_PREVIEWCFG_AUX_V30�ṹ)
#define     NET_DVR_GET_PREVIEWCFG_AUX_V30		1046		//��ȡ����Ԥ������
#define     NET_DVR_SET_PREVIEWCFG_AUX_V30		1047		//���ø���Ԥ������

//IP�������ò��� ��NET_DVR_IPPARACFG�ṹ��
#define     NET_DVR_GET_IPPARACFG               1048        //��ȡIP����������Ϣ 
#define     NET_DVR_SET_IPPARACFG               1049        //����IP����������Ϣ

//IP��������������ò��� ��NET_DVR_IPALARMINCFG�ṹ��
#define     NET_DVR_GET_IPALARMINCFG            1050        //��ȡIP�����������������Ϣ 
#define     NET_DVR_SET_IPALARMINCFG            1051        //����IP�����������������Ϣ

//IP��������������ò��� ��NET_DVR_IPALARMOUTCFG�ṹ��
#define     NET_DVR_GET_IPALARMOUTCFG           1052        //��ȡIP�����������������Ϣ 
#define     NET_DVR_SET_IPALARMOUTCFG           1053        //����IP�����������������Ϣ

//Ӳ�̹����Ĳ�����ȡ (NET_DVR_HDCFG�ṹ)
#define     NET_DVR_GET_HDCFG			        1054	    //��ȡӲ�̹������ò���
#define     NET_DVR_SET_HDCFG			        1055	    //����Ӳ�̹������ò���
//��������Ĳ�����ȡ (NET_DVR_HDGROUP_CFG�ṹ)
#define     NET_DVR_GET_HDGROUP_CFG			    1056	    //��ȡ����������ò���
#define     NET_DVR_SET_HDGROUP_CFG			    1057	    //��������������ò���

//�豸������������(NET_DVR_COMPRESSION_AUDIO�ṹ)
#define     NET_DVR_GET_COMPRESSCFG_AUD         1058        //��ȡ�豸�����Խ��������
#define     NET_DVR_SET_COMPRESSCFG_AUD         1059        //�����豸�����Խ��������

//IP�������ò��� ��NET_DVR_IPPARACFG_V31�ṹ��
#define     NET_DVR_GET_IPPARACFG_V31            1060        //��ȡIP����������Ϣ 
#define     NET_DVR_SET_IPPARACFG_V31            1061        //����IP����������Ϣ

// ͨ����Դ���� (NET_DVR_IPPARACFG_V40�ṹ)
#define NET_DVR_GET_IPPARACFG_V40               1062        // ��ȡIP��������
#define NET_DVR_SET_IPPARACFG_V40               1063        // ����IP��������

#define NET_DVR_GET_CCDPARAMCFG              1067       //IPC��ȡCCD��������
#define NET_DVR_SET_CCDPARAMCFG              1068       //IPC����CCD��������

#define NET_DVR_GET_IOINCFG		                1070    //��ȡץ�Ļ�IO�������
#define NET_DVR_SET_IOINCFG		                1071	 //����ץ�Ļ�IO�������

#define NET_DVR_GET_IOOUTCFG		            1072    //��ȡץ�Ļ�IO�������
#define NET_DVR_SET_IOOUTCFG		            1073	 //����ץ�Ļ�IO�������

#define NET_DVR_GET_FLASHCFG		            1074    //��ȡIO������������
#define NET_DVR_SET_FLASHCFG		            1075	 //����IO������������

#define NET_DVR_GET_LIGHTSNAPCFG		        1076    //��ȡץ�Ļ����̵Ʋ���
#define NET_DVR_SET_LIGHTSNAPCFG	        	1077	 //����ץ�Ļ����̵Ʋ���

#define NET_DVR_GET_MEASURESPEEDCFG		        1078    //��ȡץ�Ļ����ٲ���
#define NET_DVR_SET_MEASURESPEEDCFG		        1079	 //����ץ�Ļ����ٲ���

#define NET_DVR_GET_IMAGEOVERLAYCFG	            1080//��ȡץ�Ļ�ͼ�������Ϣ����
#define NET_DVR_SET_IMAGEOVERLAYCFG	            1081//����ץ�Ļ�ͼ�������Ϣ����

#define NET_DVR_GET_SNAPCFG	                    1082//��ȡ��IO����ץ�Ĺ�������
#define NET_DVR_SET_SNAPCFG	                    1083//���õ�IO����ץ�Ĺ�������

#define NET_DVR_GET_VTPPARAM		            1084//��ȡ������Ȧ����
#define NET_DVR_SET_VTPPARAM		            1085//����������Ȧ����

#define NET_DVR_GET_SNAPENABLECFG					1086//��ȡץ�Ļ�ʹ�ܲ���
#define NET_DVR_SET_SNAPENABLECFG					1087//����ץ�Ļ�ʹ�ܲ���

#define NET_DVR_GET_POSTEPOLICECFG      1088        //��ȡ���ڵ羯����
#define NET_DVR_SET_POSTEPOLICECFG      1089        //���ÿ��ڵ羯����

#define NET_DVR_GET_JPEGCFG_V30					1090		//��ȡץͼ��JPEG����(����)
#define NET_DVR_SET_JPEGCFG_V30					1091		//����ץͼ��JPEG����(����)

#define NET_DVR_GET_SPRCFG	                    1092    //��ȡ����ʶ�����
#define NET_DVR_SET_SPRCFG	                    1093    //���ó���ʶ�����

#define NET_DVR_GET_PLCCFG    1094   //��ȡ�������Ȳ�������
#define NET_DVR_SET_PLCCFG    1095  //���ó������Ȳ�������

#define NET_DVR_GET_DEVICESTATECFG              1096   //��ȡ�豸��ǰ״̬����

#define NET_DVR_GET_DEVICECFG_V40	1100//��ȡ��չ�豸���� 
#define NET_DVR_SET_DEVICECFG_V40	1101//������չ�豸����

#define NET_DVR_GET_ZEROCHANCFG   	1102	//��ȡ��ͨ��ѹ������ 
#define NET_DVR_SET_ZEROCHANCFG  	1103	//������ͨ��ѹ������

#define NET_DVR_GET_ZERO_PREVIEWCFG_V30 1104    // ��ȡ��ͨ��Ԥ����������
#define NET_DVR_SET_ZERO_PREVIEWCFG_V30 1105    // ������ͨ��Ԥ����������

#define NET_DVR_SET_ZERO_ZOOM	1106     //������ͨ������������ 
#define NET_DVR_GET_ZERO_ZOOM	1107     //��ȡ��ͨ������������

#define	NET_DVR_NATASSOCIATECFG_GET	1110    //��ȡNAT���������Ϣ
#define	NET_DVR_NATASSOCIATECFG_SET	1111     //����NAT���������Ϣ

#define NET_DVR_GET_SNMPCFG   	                1112    //��ȡSNMP���� 
#define NET_DVR_SET_SNMPCFG  	                1113    //����SNMP����

#define	NET_DVR_VIDEOPLATFORMALARMCFG_GET	1130//��ȡ��Ƶ�ۺ�ƽ̨��������
#define	NET_DVR_VIDEOPLATFORMALARMCFG_SET	1131//������Ƶ�ۺ�ƽ̨��������

#define NET_DVR_GET_RAID_ADAPTER_INFO   1134    // ��ȡ��������Ϣ
#define NET_DVR_SET_RAID_ADAPTER_INFO   1135    // ������������Ϣ   


//����������
#define     NET_DVR_GET_NETCFG_MULTI            1161        //��ȡ����������
#define     NET_DVR_SET_NETCFG_MULTI            1162        //���ö���������

#define NET_DVR_SET_SENSOR_CFG					1180        // ����ģ��������
#define NET_DVR_GET_SENSOR_CFG					1181        // ��ȡģ��������
#define NET_DVR_SET_ALARMIN_PARAM				1182		// ���ñ����������
#define NET_DVR_GET_ALARMIN_PARAM				1183		// ��ȡ�����������
#define NET_DVR_SET_ALARMOUT_PARAM				1184		// ���ñ����������
#define NET_DVR_GET_ALARMOUT_PARAM				1185		// ��ȡ�����������
#define NET_DVR_SET_SIREN_PARAM					1186		// ���þ��Ų���
#define NET_DVR_GET_SIREN_PARAM					1187		// ��ȡ���Ų���
#define NET_DVR_SET_ALARM_RS485CFG				1188		// ���ñ�������485����
#define NET_DVR_GET_ALARM_RS485CFG				1189		// ��ȡ��������485����
#define NET_DVR_GET_ALARMHOST_MAIN_STATUS		1190		// ��ȡ����������Ҫ״̬
#define NET_DVR_GET_ALARMHOST_OTHER_STATUS		1191		// ��ȡ������������״̬
#define NET_DVR_SET_ALARMHOST_ENABLECFG			1192		//��ȡ��������ʹ��״̬
#define NET_DVR_GET_ALARMHOST_ENABLECFG			1193		//���ñ�������ʹ��״̬
#define NET_DVR_SET_ALARM_CAMCFG				1194		// ������Ƶ�ۺ�ƽ̨��������CAM��������
#define NET_DVR_GET_ALARM_CAMCFG				1195		// ������Ƶ�ۺ�ƽ̨��������CAM��������
#define NET_DVR_GET_GATEWAY_CFG                 1196        // ��ȡ�Ž���������
#define NET_DVR_SET_GATEWAY_CFG                 1197        // �����Ž���������

#define NET_DVR_GET_ZOOMCAMCFG                  1200        //��ȡһ���ǰ�˲���
#define NET_DVR_SET_ZOOMCAMCFG                  1201        //����һ���ǰ�˲���

#define     NET_DVR_GET_ISCSI_CFG                   11070     // ��ȡISCSI�洢����Э�� 
#define     NET_DVR_SET_ISCSI_CFG                   11071     // ��ȡISCSI�洢����Э�� 

/***************************DS9000��������(_V30) end *****************************/

/*************************������������ end*******************************/


/*******************�����ļ�����־��������ֵ*************************/
#define NET_DVR_FILE_SUCCESS		1000	//����ļ���Ϣ
#define NET_DVR_FILE_NOFIND			1001	//û���ļ�
#define NET_DVR_ISFINDING			1002	//���ڲ����ļ�
#define	NET_DVR_NOMOREFILE			1003	//�����ļ�ʱû�и�����ļ�
#define	NET_DVR_FILE_EXCEPTION		1004	//�����ļ�ʱ�쳣

/*********************�ص��������� begin************************/
#define COMM_ALARM					0x1100	//8000������Ϣ�����ϴ�
#define	COMM_TRADEINFO				0x1500  //ATMDVR�����ϴ�������Ϣ

#define COMM_ALARM_V30				0x4000	//9000������Ϣ�����ϴ�
#define COMM_IPCCFG			        0x4001	//9000�豸IPC�������øı䱨����Ϣ�����ϴ�
#define COMM_IPCCFG_V31			    0x4002	//9000�豸IPC�������øı䱨����Ϣ�����ϴ���չ 9000_1.1
#define COMM_IPCCFG_V40             0x4003  // IVMS 2000 ��������� NVR IPC�������øı�ʱ������Ϣ�ϴ�


/*************�����쳣����(��Ϣ��ʽ, �ص���ʽ(����))****************/
#define EXCEPTION_EXCHANGE			0x8000	//�û�����ʱ�쳣
#define EXCEPTION_AUDIOEXCHANGE		0x8001	//�����Խ��쳣
#define EXCEPTION_ALARM				0x8002	//�����쳣
#define EXCEPTION_PREVIEW			0x8003	//����Ԥ���쳣
#define EXCEPTION_SERIAL			0x8004	//͸��ͨ���쳣
#define EXCEPTION_RECONNECT			0x8005	//Ԥ��ʱ����
#define EXCEPTION_ALARMRECONNECT	0x8006	//����ʱ����
#define EXCEPTION_SERIALRECONNECT	0x8007	//͸��ͨ������
#define SERIAL_RECONNECTSUCCESS 0x8008	//͸��ͨ�������ɹ�
#define EXCEPTION_PLAYBACK	        0x8010	//�ط��쳣
#define EXCEPTION_DISKFMT	        0x8011	//Ӳ�̸�ʽ��
#define EXCEPTION_PASSIVEDECODE     0x8012  //���������쳣
#define EXCEPTION_EMAILTEST             0x8013  // �ʼ������쳣    
#define EXCEPTION_BACKUP                0x8014  // �����쳣
#define PREVIEW_RECONNECTSUCCESS      0x8015  //Ԥ��ʱ�����ɹ�
#define ALARM_RECONNECTSUCCESS     0x8016  //����ʱ�����ɹ�
//2010-11-10 the third generation sdk
#define RESUME_EXCHANGE				0x8017	//�û������ָ�(3g �豸)
/********************Ԥ���ص�����*********************/
#define NET_DVR_SYSHEAD			1	//ϵͳͷ����
#define NET_DVR_STREAMDATA		2	//��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ�
#define NET_DVR_AUDIOSTREAMDATA	3	//��Ƶ������
#define NET_DVR_STD_VIDEODATA	4	//��׼��Ƶ������
#define NET_DVR_STD_AUDIODATA	5	//��׼��Ƶ������

//�豸�ͺ�(DVR����)
/* �豸���� */
#define DVR							1				/*����δ�����dvr���ͷ���NETRET_DVR*/
#define ATMDVR						2				/*atm dvr*/
#define DVS							3				/*DVS*/
#define DEC							4				/* 6001D */
#define ENC_DEC						5				/* 6001F */
#define DVR_HC						6				/*8000HC*/
#define DVR_HT						7				/*8000HT*/
#define DVR_HF						8				/*8000HF*/
#define DVR_HS						9				/* 8000HS DVR(no audio) */
#define DVR_HTS						10              /* 8016HTS DVR(no audio) */
#define DVR_HB						11              /* HB DVR(SATA HD) */
#define DVR_HCS						12              /* 8000HCS DVR */
#define DVS_A						13              /* ��ATAӲ�̵�DVS */
#define DVR_HC_S					14              /* 8000HC-S */
#define DVR_HT_S					15              /* 8000HT-S */
#define DVR_HF_S					16              /* 8000HF-S */
#define DVR_HS_S					17              /* 8000HS-S */
#define ATMDVR_S					18              /* ATM-S */
#define LOWCOST_DVR					19				/*7000Hϵ��*/
#define DEC_MAT						20              /*��·������*/
#define DVR_MOBILE					21				/* mobile DVR */                 
#define DVR_HD_S					22              /* 8000HD-S */
#define DVR_HD_SL					23				/* 8000HD-SL */
#define DVR_HC_SL					24				/* 8000HC-SL */
#define DVR_HS_ST					25				/* 8000HS_ST */
#define DVS_HW						26              /* 6000HW */
#define DS630X_D					27              /* ��·������ */
#define DS640X_HD					28				/*640X���������*/
#define DS610X_D                    29              /*610X������*/
#define IPCAM						30				/*IP �����*/
#define MEGA_IPCAM					31				/*852F&852MF*/
#define IPCAM_X62MF					32				/*862MF���Խ���9000�豸*/
#define ITCCAM                      35              /*���ܸ������������*/
#define ZOOMCAM                     38              /*һ���*/
#define IPDOME                      40              /*IP �������*/
#define IPDOME_MEGA200              41              /*IP 200��������*/
#define IPDOME_MEGA130              42              /*IP 130��������*/
#define IPMOD						50				/*IP ģ��*/
#define IDS6501_HF_P                60              // 6501 ���� 
#define IDS6101_HF_A                61              //����ATM
#define IDS6002_HF_B                62          //˫�����٣�DS6002-HF/B
#define IDS6101_HF_B	            63              //��Ϊ������DS6101-HF/B DS6101-HF/B_SATA
#define IDS52XX		                64          //���ܷ�����IVMS
#define IDS90XX						65				// 9000����
#define IDS8104_AHL_S_HX            66          // ��������ʶ�� ATM
#define IDS8104_AHL_S_H             67              // ˽������ʶ�� ATM
#define IDS91XX						68				// 9100����
#define IIP_CAM_B                   69              // ������ΪIP�����
#define DS71XX_H					71				/* DS71XXH_S */
#define DS72XX_H_S					72				/* DS72XXH_S */
#define DS73XX_H_S					73				/* DS73XXH_S */
#define DS72XX_HF_S                 74              //DS72XX_HF_S
#define DS73XX_HFI_S                75              //DS73XX_HFI_S
#define DS76XX_H_S					76				/* DVR,e.g. DS7604_HI_S */
#define DS76XX_N_S					77				/* NVR,e.g. DS7604_NI_S */
#define DS81XX_HS_S					81				/* DS81XX_HS_S */
#define DS81XX_HL_S					82				/* DS81XX_HL_S */
#define DS81XX_HC_S					83				/* DS81XX_HC_S */
#define DS81XX_HD_S					84				/* DS81XX_HD_S */
#define DS81XX_HE_S					85				/* DS81XX_HE_S */
#define DS81XX_HF_S					86				/* DS81XX_HF_S */
#define DS81XX_AH_S					87				/* DS81XX_AH_S */
#define DS81XX_AHF_S				88				/* DS81XX_AHF_S */
#define DS90XX_HF_S		            90              /*DS90XX_HF_S*/
#define DS91XX_HF_S					91              /*DS91XX_HF_S*/
#define DS91XX_HD_S					92              /*91XXHD-S(MD)*/
#define IDS90XX_A					93				// 9000���� ATM
#define IDS91XX_A					94				// 9100���� ATM
#define DS95XX_N_S					95              /*DS95XX_N_S NVR �����κ����*/
#define DS96XX_N_SH					96              /*DS96XX_N_SH NVR*/
#define DS90XX_HF_SH                97              /*DS90XX_HF_SH */   
#define DS91XX_HF_SH                98              /*DS91XX_HF_SH */
#define DS_B10_XY                   100             /*��Ƶ�ۺ�ƽ̨�豸�ͺ�(X:�����Ƭ����Y:�����Ƭ��)*/
#define DS_6504HF_B10               101             /*��Ƶ�ۺ�ƽ̨�ڲ�������*/
#define DS_6504D_B10                102             /*��Ƶ�ۺ�ƽ̨�ڲ�������*/
#define DS_1832_B10                 103             /*��Ƶ�ۺ�ƽ̨�ڲ������*/
#define DS_6401HFH_B10              104             /*��Ƶ�ۺ�ƽ̨�ڲ����˰�*/
#define DS_65XXHC					105				//65XXHC DVS
#define DS_65XXHC_S					106				//65XXHC-SATA DVS
#define DS_65XXHF					107				//65XXHF DVS
#define DS_65XXHF_S					108				//65XXHF-SATA DVS
#define DS_6500HF_B                 109             //65 rack DVS
#define IVMS_6200_C                 110             // iVMS-6200(/C)  
#define IVMS_6200_B                 111             // iVMS-6200(/B)
#define DS_72XXHV_ST15				112				//72XXHV_ST15 DVR
#define DS_72XXHV_ST20				113				//72XXHV_ST20 DVR
#define IVMS_6200_T			        114             // IVMS-6200(/T)
#define IVMS_6200_BP                115             // IVMS-6200(/BP)
#define DS_81XXHC_ST				116				//DS_81XXHC_ST
#define DS_81XXHS_ST				117				//DS_81XXHS_ST
#define DS_81XXAH_ST				118				//DS_81XXAH_ST
#define DS_81XXAHF_ST				119				//DS_81XXAHF_ST
#define DS_66XXDVS				    120				//66XX DVS

#define DS_1964_B10                 121             /*��Ƶ�ۺ�ƽ̨�ڲ�������*/
#define DS_B10N04_IN				122             /*��Ƶ�ۺ�ƽ̨�ڲ���������*/
#define DS_B10N04_OUT				123             /*��Ƶ�ۺ�ƽ̨�ڲ��������*/
#define DS_B10N04_INTEL             124             /*��Ƶ�ۺ�ƽ̨�ڲ�����*/
#define DS_6408HFH_B10E_RM          125             //V6����
#define DS_B10N64F1_RTM             126             //V6��������DSP
#define DS_B10N64F1D_RTM            127             //V6������DSP
#define DS_B10_SDS                  128             //��Ƶ�ۺ�ƽ̨���������
#define DS_B10_DS                   129             //��Ƶ�ۺ�ƽ̨�������
#define DS_6401HFH_B10V    			130     	    //VGA���������
#define DS_6504D_B10B               131             /*��Ƶ�ۺ�ƽ̨�ڲ����������*/
#define DS_6504D_B10H               132             /*��Ƶ�ۺ�ƽ̨�ڲ����������*/
#define DS_6504D_B10V               133             /*��Ƶ�ۺ�ƽ̨�ڲ�VGA������*/

#define DS_19DXX					145				/*������ر�������*/	
#define DS_19XX                     146             /*1900ϵ�б�������*/ 

#define IDS_8104_AHFL_S_H           171             // 8104ATM 
#define IDS_65XX_HF_A               172             // 65 ATM
#define IDS90XX_HF_RH               173             // 9000 ����RH
#define IDS91XX_HF_RH               174             // 9100 ����RH�豸
#define IDS_65XX_HF_B               175             // 65 ��Ϊ����
#define IDS_65XX_HF_P               176             // 65 ����ʶ��


#define DS90XX_HF_RH                181             // 9000 RH
#define DS91XX_HF_RH                182             // 9100 RH�豸
#define DS78XX_SE                   183             // DVR_78se

#define ENCODER_SERVER				200			// ���뿨������
#define DECODER_SERVER              201         // ���뿨������
#define PCNVR_SERVER                202         // PCNVR�洢������
/**********************�豸���� end***********************/

/*************************************************
�������ýṹ������(����_V30Ϊ9000����)
**************************************************/

/////////////////////////////////////////////////////////////////////////
//Уʱ�ṹ����
typedef struct
{
	DWORD dwYear;		//��
	DWORD dwMonth;		//��
	DWORD dwDay;		//��
	DWORD dwHour;		//ʱ
	DWORD dwMinute;		//��
	DWORD dwSecond;		//��
}NET_DVR_TIME, *LPNET_DVR_TIME;

//ʱ���(�ӽṹ)
typedef struct
{
	//��ʼʱ��
    BYTE byStartHour;
	BYTE byStartMin;
	//����ʱ��
	BYTE byStopHour;
	BYTE byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

/*�豸�������쳣������ʽ*/
#define NOACTION			0x0				/*����Ӧ*/
#define WARNONMONITOR		0x1				/*�������Ͼ���*/
#define WARNONAUDIOOUT		0x2				/*��������*/
#define UPTOCENTER			0x4				/*�ϴ�����*/
#define TRIGGERALARMOUT		0x8				/*�����������*/

//�������쳣�����ṹ(�ӽṹ)(�ദʹ��)(9000��չ)
typedef struct
{
	DWORD	dwHandleType;	/*������ʽ,������ʽ��"��"���*/
	/*0x00: ����Ӧ*/
	/*0x01: �������Ͼ���*/
	/*0x02: ��������*/
	/*0x04: �ϴ�����*/
	/*0x08: �����������*/
	/*0x10: Jpegץͼ���ϴ�EMail*/
	BYTE byRelAlarmOut[MAX_ALARMOUT_V30];  
    //�������������ͨ��,�������������,Ϊ1��ʾ���������
}NET_DVR_HANDLEEXCEPTION_V30, *LPNET_DVR_HANDLEEXCEPTION_V30;

//�������쳣�����ṹ(�ӽṹ)(�ദʹ��)
typedef struct
{
	DWORD	dwHandleType;			/*������ʽ,������ʽ��"��"���*/
	/*0x00: ����Ӧ*/
	/*0x01: �������Ͼ���*/
	/*0x02: ��������*/
	/*0x04: �ϴ�����*/
	/*0x08: �����������*/
	/*0x10: Jpegץͼ���ϴ�EMail*/
	BYTE byRelAlarmOut[MAX_ALARMOUT];  //�������������ͨ��,�������������,Ϊ1��ʾ���������
}NET_DVR_HANDLEEXCEPTION, *LPNET_DVR_HANDLEEXCEPTION;

//DVR�豸����
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR����
	DWORD dwDVRID;				//DVR ID,����ң���� //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//�Ƿ�ѭ��¼��,0:����; 1:��
	//���²��ɸ���
	BYTE sSerialNumber[SERIALNO_LEN];  //���к�
	DWORD dwSoftwareVersion;			//�����汾��,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwSoftwareBuildDate;			//������������,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP�����汾,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwDSPSoftwareBuildDate;		// DSP������������,0xYYYYMMDD
	DWORD dwPanelVersion;				// ǰ���汾,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwHardwareVersion;	// Ӳ���汾,��16λ�����汾,��16λ�Ǵΰ汾
	BYTE byAlarmInPortNum;		//DVR�����������
	BYTE byAlarmOutPortNum;		//DVR�����������
	BYTE byRS232Num;			//DVR 232���ڸ���
	BYTE byRS485Num;			//DVR 485���ڸ���
	BYTE byNetworkPortNum;		//����ڸ���
	BYTE byDiskCtrlNum;			//DVR Ӳ�̿���������
	BYTE byDiskNum;				//DVR Ӳ�̸���
	BYTE byDVRType;				//DVR����, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				//DVR ͨ������
	BYTE byStartChan;			//��ʼͨ����,����DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR ����·��
	BYTE byVGANum;				//VGA�ڵĸ���
	BYTE byUSBNum;				//USB�ڵĸ���
    BYTE byAuxoutNum;			//���ڵĸ���
    BYTE byAudioNum;			//�����ڵĸ���
    BYTE byIPChanNum;			//�������ͨ����
}NET_DVR_DEVICECFG, *LPNET_DVR_DEVICECFG;

/*
IP��ַ
*/
typedef struct
{		
	char	sIpV4[16];						/* IPv4��ַ */
	BYTE	byIPv6[128];						/* ���� */
}NET_DVR_IPADDR, *LPNET_DVR_IPADDR;


/*
�������ݽṹ(�ӽṹ)(9000��չ)
*/
typedef struct 
{
	NET_DVR_IPADDR	struDVRIP;          					//DVR IP��ַ
	NET_DVR_IPADDR	struDVRIPMask;  //DVR IP��ַ����
	DWORD	dwNetInterface;   								//����ӿ�1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M����Ӧ
	WORD	wDVRPort;										//�˿ں�
	WORD	wMTU;											//����MTU���ã�Ĭ��1500��
	BYTE	byMACAddr[MACADDR_LEN];							// ������ַ
	BYTE    byRes[2];              //����
}NET_DVR_ETHERNET_V30, *LPNET_DVR_ETHERNET_V30;

/*
�������ݽṹ(�ӽṹ)
*/
typedef struct
{
	char sDVRIP[16];          //DVR IP��ַ
	char sDVRIPMask[16];      //DVR IP��ַ����
	DWORD dwNetInterface;     //����ӿ� 1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M����Ӧ
	WORD wDVRPort;		      //�˿ں�
	BYTE byMACAddr[MACADDR_LEN];		//��������������ַ
}NET_DVR_ETHERNET;

//pppoe�ṹ
typedef struct 
{
	DWORD	dwPPPOE;										//0-������,1-����
	BYTE	sPPPoEUser[NAME_LEN];							//PPPoE�û���
	char	sPPPoEPassword[PASSWD_LEN];						// PPPoE����
	NET_DVR_IPADDR	struPPPoEIP;							//PPPoE IP��ַ
}NET_DVR_PPPOECFG, *LPNET_DVR_PPPOECFG;

//�������ýṹ(9000��չ)
typedef struct
{	
	DWORD dwSize;
	NET_DVR_ETHERNET_V30	struEtherNet[MAX_ETHERNET];		//��̫����
	NET_DVR_IPADDR	struRes1[2];					/*����*/
	NET_DVR_IPADDR	struAlarmHostIpAddr;					/* ��������IP��ַ */
	WORD	wRes2[2];								/* ���� */
	WORD	wAlarmHostIpPort;								/* ���������˿ں� */
	BYTE    byUseDhcp;                                      /* �Ƿ�����DHCP 0xff-��Ч 0-������ 1-����*/
	BYTE	byRes3;
	NET_DVR_IPADDR	struDnsServer1IpAddr;					/* ����������1��IP��ַ */
	NET_DVR_IPADDR	struDnsServer2IpAddr;					/* ����������2��IP��ַ */
	BYTE	byIpResolver[MAX_DOMAIN_NAME];					/* IP����������������IP��ַ */
	WORD	wIpResolverPort;								/* IP�����������˿ں� */
	WORD	wHttpPortNo;									/* HTTP�˿ں� */
	NET_DVR_IPADDR	struMulticastIpAddr;					/* �ಥ���ַ */
	NET_DVR_IPADDR	struGatewayIpAddr;						/* ���ص�ַ */
	NET_DVR_PPPOECFG struPPPoE;	
    BYTE    byRes[64];
} NET_DVR_NETCFG_V30, *LPNET_DVR_NETCFG_V30;

//���������������ṹ
typedef struct 
{
	NET_DVR_IPADDR struDVRIP;           //DVR IP��ַ
	NET_DVR_IPADDR struDVRIPMask;           //DVR IP��ַ����
	DWORD dwNetInterface;    //����ӿ�1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M/1000M����Ӧ
	BYTE byRes1[2]; 
	WORD wMTU;             //����MTU���ã�Ĭ��1500��
	BYTE byMACAddr[MACADDR_LEN]; //������ַ��ֻ������ʾ
	BYTE byRes2[2]; //����
	BYTE byUseDhcp;                          /* �Ƿ�����DHCP */
	BYTE byRes3[3];
	NET_DVR_IPADDR struGatewayIpAddr;     /* ���ص�ַ */
	NET_DVR_IPADDR struDnsServer1IpAddr; /* ����������1��IP��ַ */
	NET_DVR_IPADDR struDnsServer2IpAddr; /* ����������2��IP��ַ */
}NET_DVR_ETHERNET_MULTI, *LPNET_DVR_ETHERNET_MULTI;

//�������������ýṹ
typedef struct
{
	DWORD  dwSize;
	BYTE   byDefaultRoute;        //Ĭ��·�ɣ�0��ʾstruEtherNet[0]��1��ʾstruEtherNet[1]
	BYTE   byNetworkCardNum;      //�豸ʵ�ʿ����õ�������Ŀ
	BYTE   byRes[2]; //����
	NET_DVR_ETHERNET_MULTI struEtherNet[MAX_NETWORK_CARD]; //��̫����
	NET_DVR_IPADDR         struManageHost1IpAddr;     /* ����������IP��ַ */
	NET_DVR_IPADDR         struManageHost2IpAddr;     /* ����������IP��ַ */
	NET_DVR_IPADDR	       struAlarmHostIpAddr; /* ��������IP��ַ */
	WORD wManageHost1Port;     /* �����������˿ں� */
	WORD wManageHost2Port;     /* �����������˿ں� */
	WORD wAlarmHostIpPort;     /* ���������˿ں� */
	BYTE  byIpResolver[MAX_DOMAIN_NAME];     /* IP����������������IP��ַ */
	WORD wIpResolverPort; /* IP�����������˿ں� */
	WORD wDvrPort; //ͨѶ�˿� Ĭ��8000 
	WORD wHttpPortNo; /* HTTP�˿ں� */
	BYTE  byRes2[6];
	NET_DVR_IPADDR   struMulticastIpAddr; /* �ಥ���ַ */
	NET_DVR_PPPOECFG struPPPoE;
	BYTE        byRes3[24];
}NET_DVR_NETCFG_MULTI, *LPNET_DVR_NETCFG_MULTI;

//�������ýṹ
typedef struct
{
	DWORD dwSize;
	NET_DVR_ETHERNET struEtherNet[MAX_ETHERNET];		/* ��̫���� */
	char sManageHostIP[16];		//Զ�̹���������ַ
	WORD wManageHostPort;		//Զ�̹��������˿ں�
	char sIPServerIP[16];            //IPServer��������ַ
	char sMultiCastIP[16];     //�ಥ���ַ
	char sGatewayIP[16];       	//���ص�ַ
	char sNFSIP[16];			//NFS����IP��ַ
	BYTE sNFSDirectory[PATHNAME_LEN];//NFSĿ¼
	DWORD dwPPPOE;				//0-������,1-����
	BYTE sPPPoEUser[NAME_LEN];	//PPPoE�û���
	char sPPPoEPassword[PASSWD_LEN];// PPPoE����
	char sPPPoEIP[16];			//PPPoE IP��ַ(ֻ��)
	WORD wHttpPort;				//HTTP�˿ں�
}NET_DVR_NETCFG, *LPNET_DVR_NETCFG;

//ͨ��ͼ��ṹ
//�ƶ����(�ӽṹ)(9000��չ)
typedef struct 
{
	BYTE byMotionScope[64][96];									/*�������,0-96λ,��ʾ64��,����96*64��С���,Ϊ1��ʾ���ƶ��������,0-��ʾ����*/
	BYTE byMotionSensitive;										/*�ƶ����������, 0 - 5,Խ��Խ����,oxff�ر�*/
	BYTE byEnableHandleMotion;									/* �Ƿ����ƶ���� 0���� 1����*/ 
	BYTE byRes;											/* ���� */
	char reservedData;	
	NET_DVR_HANDLEEXCEPTION_V30 struMotionHandleType;				/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*����ʱ��*/
	BYTE byRelRecordChan[MAX_CHANNUM_V30];									/* ����������¼��ͨ��*/
}NET_DVR_MOTION_V30, *LPNET_DVR_MOTION_V30;

//�ƶ����(�ӽṹ)
typedef struct 
{
	BYTE byMotionScope[18][22];	/*�������,����22*18��С���,Ϊ1��ʾ�ĺ�����ƶ��������,0-��ʾ����*/
	BYTE byMotionSensitive;		/*�ƶ����������, 0 - 5,Խ��Խ����,0xff�ر�*/
	BYTE byEnableHandleMotion;	/* �Ƿ����ƶ���� */
	char reservedData[2];
	NET_DVR_HANDLEEXCEPTION strMotionHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM]; //����������¼��ͨ��,Ϊ1��ʾ������ͨ��
}NET_DVR_MOTION, *LPNET_DVR_MOTION;

//�ڵ�����(�ӽṹ)(9000��չ)  �����С704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* �Ƿ������ڵ����� ,0-��,1-�������� 2-�������� 3-��������*/
	WORD wHideAlarmAreaTopLeftX;			/* �ڵ������x���� */
	WORD wHideAlarmAreaTopLeftY;			/* �ڵ������y���� */
	WORD wHideAlarmAreaWidth;				/* �ڵ�����Ŀ� */
	WORD wHideAlarmAreaHeight;				/*�ڵ�����ĸ�*/
	NET_DVR_HANDLEEXCEPTION_V30 strHideAlarmHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//����ʱ��
}NET_DVR_HIDEALARM_V30, *LPNET_DVR_HIDEALARM_V30;
//�ڵ�����(�ӽṹ)  �����С704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* �Ƿ������ڵ����� ,0-��,1-�������� 2-�������� 3-��������*/
	WORD wHideAlarmAreaTopLeftX;			/* �ڵ������x���� */
	WORD wHideAlarmAreaTopLeftY;			/* �ڵ������y���� */
	WORD wHideAlarmAreaWidth;				/* �ڵ�����Ŀ� */
	WORD wHideAlarmAreaHeight;				/*�ڵ�����ĸ�*/
	NET_DVR_HANDLEEXCEPTION strHideAlarmHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
}NET_DVR_HIDEALARM, *LPNET_DVR_HIDEALARM;

//�źŶ�ʧ����(�ӽṹ)(9000��չ)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* �Ƿ����źŶ�ʧ���� */
	NET_DVR_HANDLEEXCEPTION_V30 strVILostHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//����ʱ��
}NET_DVR_VILOST_V30, *LPNET_DVR_VILOST_V30;

//�źŶ�ʧ����(�ӽṹ)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* �Ƿ����źŶ�ʧ���� */
	NET_DVR_HANDLEEXCEPTION strVILostHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
}NET_DVR_VILOST, *LPNET_DVR_VILOST;

//�ڵ�����(�ӽṹ)
typedef struct 
{
	WORD wHideAreaTopLeftX;				/* �ڵ������x���� */
	WORD wHideAreaTopLeftY;				/* �ڵ������y���� */
	WORD wHideAreaWidth;				/* �ڵ�����Ŀ� */
	WORD wHideAreaHeight;				/*�ڵ�����ĸ�*/
}NET_DVR_SHELTER, *LPNET_DVR_SHELTER;

typedef struct
{
	BYTE byBrightness;  	/*����,0-255*/
	BYTE byContrast;    	/*�Աȶ�,0-255*/	
	BYTE bySaturation;  	/*���Ͷ�,0-255*/
	BYTE byHue;    			/*ɫ��,0-255*/
}NET_DVR_COLOR, *LPNET_DVR_COLOR;


//ͨ��ͼ��ṹ(9000��չ)
typedef struct
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* ֻ�� ��Ƶ��ʽ 1-NTSC 2-PAL*/
	NET_DVR_COLOR struColor;//	ͼ�����
	char reservedData [60];/*����*/
	//��ʾͨ����
	DWORD dwShowChanName; // Ԥ����ͼ�����Ƿ���ʾͨ������,0-����ʾ,1-��ʾ �����С704*576
	WORD wShowNameTopLeftX;				/* ͨ��������ʾλ�õ�x���� */
	WORD wShowNameTopLeftY;				/* ͨ��������ʾλ�õ�y���� */
	//��Ƶ�źŶ�ʧ����
	NET_DVR_VILOST_V30 struVILost;
	NET_DVR_VILOST_V30 struRes;		/*����*/
	//�ƶ����
	NET_DVR_MOTION_V30 struMotion;
	//�ڵ�����
	NET_DVR_HIDEALARM_V30 struHideAlarm;
	//�ڵ�  �����С704*576
	DWORD dwEnableHide;		/* �Ƿ������ڵ� ,0-��,1-��*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// Ԥ����ͼ�����Ƿ���ʾOSD,0-����ʾ,1-��ʾ �����С704*576
	WORD wOSDTopLeftX;				/* OSD��x���� */
	WORD wOSDTopLeftY;				/* OSD��y���� */
	BYTE byOSDType;					/* OSD����(��Ҫ�������ո�ʽ) */
	/* 0: XXXX-XX-XX ������ */
	/* 1: XX-XX-XXXX ������ */
	/* 2: XXXX��XX��XX�� */
	/* 3: XX��XX��XXXX�� */
	/* 4: XX-XX-XXXX ������*/
	/* 5: XX��XX��XXXX�� */
	BYTE byDispWeek;				/* �Ƿ���ʾ���� */
	BYTE byOSDAttrib;				/* OSD����:͸������˸ */
	/* 0: ����ʾOSD */
	/* 1: ͸��,��˸ */
	/* 2: ͸��,����˸ */
	/* 3: ��˸,��͸�� */
	/* 4: ��͸��,����˸ */
    BYTE byHourOSDType;				/* OSDСʱ��:0-24Сʱ��,1-12Сʱ�� */
	BYTE byRes[64];
}NET_DVR_PICCFG_V30, *LPNET_DVR_PICCFG_V30;

//ͨ��ͼ��ṹSDK_V14��չ
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* ֻ�� ��Ƶ��ʽ 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*����,0-255*/
	BYTE byContrast;    	/*�Աȶ�,0-255*/
	BYTE bySaturation;  	/*���Ͷ�,0-255 */
	BYTE byHue;    			/*ɫ��,0-255*/
	//��ʾͨ����
	DWORD dwShowChanName; // Ԥ����ͼ�����Ƿ���ʾͨ������,0-����ʾ,1-��ʾ �����С704*576
	WORD wShowNameTopLeftX;				/* ͨ��������ʾλ�õ�x���� */
	WORD wShowNameTopLeftY;				/* ͨ��������ʾλ�õ�y���� */
	//�źŶ�ʧ����
	NET_DVR_VILOST struVILost;
	//�ƶ����
	NET_DVR_MOTION struMotion;
	//�ڵ�����
	NET_DVR_HIDEALARM struHideAlarm;
	//�ڵ�  �����С704*576
	DWORD dwEnableHide;		/* �Ƿ������ڵ� ,0-��,1-��*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// Ԥ����ͼ�����Ƿ���ʾOSD,0-����ʾ,1-��ʾ �����С704*576
	WORD wOSDTopLeftX;				/* OSD��x���� */
	WORD wOSDTopLeftY;				/* OSD��y���� */
	BYTE byOSDType;					/* OSD����(��Ҫ�������ո�ʽ) */
	/* 0: XXXX-XX-XX ������ */
	/* 1: XX-XX-XXXX ������ */
	/* 2: XXXX��XX��XX�� */
	/* 3: XX��XX��XXXX�� */
	/* 4: XX-XX-XXXX ������*/
	/* 5: XX��XX��XXXX�� */
	BYTE byDispWeek;				/* �Ƿ���ʾ���� */
	BYTE byOSDAttrib;				/* OSD����:͸������˸ */
	/* 0: ����ʾOSD */
	/* 1: ͸��,��˸ */
	/* 2: ͸��,����˸ */
	/* 3: ��˸,��͸�� */
	/* 4: ��͸��,����˸ */
	BYTE byHourOsdType;		/* OSDСʱ��:0-24Сʱ��,1-12Сʱ�� */
}NET_DVR_PICCFG_EX, *LPNET_DVR_PICCFG_EX;

//ͨ��ͼ��ṹ(SDK_V13��֮ǰ�汾)
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* ֻ�� ��Ƶ��ʽ 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*����,0-255*/
	BYTE byContrast;    	/*�Աȶ�,0-255*/
	BYTE bySaturation;  	/*���Ͷ�,0-255 */
	BYTE byHue;    			/*ɫ��,0-255*/
	//��ʾͨ����
	DWORD dwShowChanName; // Ԥ����ͼ�����Ƿ���ʾͨ������,0-����ʾ,1-��ʾ �����С704*576
	WORD wShowNameTopLeftX;				/* ͨ��������ʾλ�õ�x���� */
	WORD wShowNameTopLeftY;				/* ͨ��������ʾλ�õ�y���� */
	//�źŶ�ʧ����
	NET_DVR_VILOST struVILost;
	//�ƶ����
	NET_DVR_MOTION struMotion;
	//�ڵ�����
	NET_DVR_HIDEALARM struHideAlarm;
	//�ڵ�  �����С704*576
	DWORD dwEnableHide;		/* �Ƿ������ڵ� ,0-��,1-��*/
	WORD wHideAreaTopLeftX;				/* �ڵ������x���� */
	WORD wHideAreaTopLeftY;				/* �ڵ������y���� */
	WORD wHideAreaWidth;				/* �ڵ�����Ŀ� */
	WORD wHideAreaHeight;				/*�ڵ�����ĸ�*/
	//OSD
	DWORD dwShowOsd;// Ԥ����ͼ�����Ƿ���ʾOSD,0-����ʾ,1-��ʾ �����С704*576
	WORD wOSDTopLeftX;				/* OSD��x���� */
	WORD wOSDTopLeftY;				/* OSD��y���� */
	BYTE byOSDType;					/* OSD����(��Ҫ�������ո�ʽ) */
	/* 0: XXXX-XX-XX ������ */
	/* 1: XX-XX-XXXX ������ */
	/* 2: XXXX��XX��XX�� */
	/* 3: XX��XX��XXXX�� */
	/* 4: XX-XX-XXXX ������*/
	/* 5: XX��XX��XXXX�� */
	BYTE byDispWeek;				/* �Ƿ���ʾ���� */
	BYTE byOSDAttrib;				/* OSD����:͸������˸ */
	/* 0: ����ʾOSD */
	/* 1: ͸��,��˸ */
	/* 2: ͸��,����˸ */
	/* 3: ��˸,��͸�� */
	/* 4: ��͸��,����˸ */
	char reservedData2;
}NET_DVR_PICCFG, *LPNET_DVR_PICCFG;

//����ѹ������(�ӽṹ)(9000��չ)
typedef struct 
{
	BYTE byStreamType;		//�������� 0-��Ƶ��, 1-������, ��ʾ�¼�ѹ������ʱ���λ��ʾ�Ƿ�����ѹ������
	BYTE byResolution;  	//�ֱ���0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5��������,6-QVGA(320*240), 
	                        //16-VGA��640*480��, 17-UXGA��1600*1200��, 18-SVGA ��800*600��,
	                        //19-HD720p��1280*720��,20-XVGA,  21-HD900p, 27-1920*1080, 
							//28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048,32-2448*1200,
							//33-2448*800,34-XGA��1024*768����35-SXGA��1280*1024��	
	BYTE byBitrateType;		//�������� 0:������, 1:������
	BYTE byPicQuality;		//ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-��
	DWORD dwVideoBitrate; 	//��Ƶ���� 0-���� 1-16K 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//���λ(31λ)�ó�1��ʾ���Զ�������, 0-30λ��ʾ����ֵ��
	DWORD dwVideoFrameRate;	//֡�� 0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; V2.0�汾���¼�14-15; 15-18; 16-22;
	WORD  wIntervalFrameI;  //I֡���
	//2006-08-11 ���ӵ�P֡�����ýӿڣ����Ը���ʵʱ����ʱ����
	BYTE  byIntervalBPFrame;//0-BBP֡; 1-BP֡; 2-��P֡
 	BYTE  byres1;        //����
 	BYTE  byVideoEncType;   //��Ƶ�������� 0 ˽��h264;1��׼h264; 2��׼mpeg4; 3-M-JPEG
 	BYTE  byAudioEncType;   //��Ƶ�������� 0-OggVorbis;1-G711_U;2-G711_A
 	BYTE  byres[10];//���ﱣ����Ƶ��ѹ������
}NET_DVR_COMPRESSION_INFO_V30, *LPNET_DVR_COMPRESSION_INFO_V30;

//ͨ��ѹ������(9000��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_V30 struNormHighRecordPara;    //¼�� ��Ӧ8000����ͨ
	NET_DVR_COMPRESSION_INFO_V30 struRes;//���� char reserveData[28];
    NET_DVR_COMPRESSION_INFO_V30 struEventRecordPara;       //�¼�����ѹ������
	NET_DVR_COMPRESSION_INFO_V30 struNetPara;               //����(������)
}NET_DVR_COMPRESSIONCFG_V30, *LPNET_DVR_COMPRESSIONCFG_V30;

//����ѹ������(�ӽṹ)
typedef struct 
{
	BYTE byStreamType;		//��������0-��Ƶ��,1-������,��ʾѹ������ʱ���λ��ʾ�Ƿ�����ѹ������
	BYTE byResolution;  	//�ֱ���0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(����ר��)
	BYTE byBitrateType;		//��������0:�����ʣ�1:������
	BYTE  byPicQuality;		//ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-��
	DWORD dwVideoBitrate; 	//��Ƶ���� 0-���� 1-16K(����) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
							// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
							//���λ(31λ)�ó�1��ʾ���Զ�������, 0-30λ��ʾ����ֵ(MIN-32K MAX-8192K)��
	DWORD dwVideoFrameRate;	//֡�� 0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20;
}NET_DVR_COMPRESSION_INFO, *LPNET_DVR_COMPRESSION_INFO;

//ͨ��ѹ������
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO struRecordPara; //¼��/�¼�����¼��
	NET_DVR_COMPRESSION_INFO struNetPara;	//����/����
}NET_DVR_COMPRESSIONCFG, *LPNET_DVR_COMPRESSIONCFG;

//����ѹ������(�ӽṹ)(��չ) ����I֡���
typedef struct 
{
	BYTE byStreamType;		//��������0-��Ƶ��, 1-������
	BYTE byResolution;  	//�ֱ���0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(����ר��)
	BYTE byBitrateType;		//��������0:�����ʣ�1:������
	BYTE  byPicQuality;		//ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-��
	DWORD dwVideoBitrate; 	//��Ƶ���� 0-���� 1-16K(����) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//���λ(31λ)�ó�1��ʾ���Զ�������, 0-30λ��ʾ����ֵ(MIN-32K MAX-8192K)��
	DWORD dwVideoFrameRate;	//֡�� 0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0����14-15, 15-18, 16-22;
	WORD  wIntervalFrameI;  //I֡���
	//2006-08-11 ���ӵ�P֡�����ýӿڣ����Ը���ʵʱ����ʱ����
	BYTE  byIntervalBPFrame;//0-BBP֡; 1-BP֡; 2-��P֡
	BYTE  byRes;
}NET_DVR_COMPRESSION_INFO_EX, *LPNET_DVR_COMPRESSION_INFO_EX;

//ͨ��ѹ������(��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX struRecordPara; //¼��
	NET_DVR_COMPRESSION_INFO_EX struNetPara;	//����
}NET_DVR_COMPRESSIONCFG_EX, *LPNET_DVR_COMPRESSIONCFG_EX;


//ʱ���¼���������(�ӽṹ)
typedef struct 
{
	NET_DVR_SCHEDTIME struRecordTime;
	BYTE byRecordType;	//0:��ʱ¼��1:�ƶ���⣬2:����¼��3:����|������4:����&����, 5:�����, 6: ����¼��
	char reservedData[3];
}NET_DVR_RECORDSCHED, *LPNET_DVR_RECORDSCHED;

//ȫ��¼���������(�ӽṹ)
typedef struct 
{
	WORD wAllDayRecord;				/* �Ƿ�ȫ��¼�� 0-�� 1-��*/
	BYTE byRecordType;				/* ¼������ 0:��ʱ¼��1:�ƶ���⣬2:����¼��3:����|������4:����&���� 5:�����, 6: ����¼��*/
	char reservedData;
}NET_DVR_RECORDDAY, *LPNET_DVR_RECORDDAY;

//ͨ��¼���������(9000��չ)
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwRecord;  						/*�Ƿ�¼�� 0-�� 1-��*/
	NET_DVR_RECORDDAY	struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED	struRecordSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	DWORD	dwRecordTime;					/* ¼����ʱ���� 0-5�룬 1-20�룬 2-30�룬 3-1���ӣ� 4-2���ӣ� 5-5���ӣ� 6-10����*/
	DWORD	dwPreRecordTime;				/* Ԥ¼ʱ�� 0-��Ԥ¼ 1-5�� 2-10�� 3-15�� 4-20�� 5-25�� 6-30�� 7-0xffffffff(������Ԥ¼) */
	DWORD	dwRecorderDuration;				/* ¼�񱣴���ʱ�� */
	BYTE	byRedundancyRec;	/*�Ƿ�����¼��,��Ҫ����˫���ݣ�0/1*/
	BYTE	byAudioRec;		/*¼��ʱ����������ʱ�Ƿ��¼��Ƶ���ݣ������д˷���*/
	BYTE	byReserve[10];	
}NET_DVR_RECORD_V30, *LPNET_DVR_RECORD_V30;

//ͨ��¼���������
typedef struct 
{
	DWORD dwSize;
	DWORD dwRecord;  /*�Ƿ�¼�� 0-�� 1-��*/
	NET_DVR_RECORDDAY struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	DWORD dwRecordTime;	/* ¼��ʱ�䳤�� */
	DWORD dwPreRecordTime;	/* Ԥ¼ʱ�� 0-��Ԥ¼ 1-5�� 2-10�� 3-15�� 4-20�� 5-25�� 6-30�� 7-0xffffffff(������Ԥ¼) */
}NET_DVR_RECORD, *LPNET_DVR_RECORD;

//��̨Э����ṹ����
typedef struct
{ 
    DWORD dwType;               /*����������ֵ*/    
    BYTE  byDescribe[DESC_LEN]; /*������������������8000�е�һ��*/    
}NET_DVR_PTZ_PROTOCOL;

typedef struct
{    
    DWORD   dwSize;    
    NET_DVR_PTZ_PROTOCOL struPtz[PTZ_PROTOCOL_NUM];/*���200��PTZЭ��*/    
    DWORD   dwPtzNum;           /*��Ч��ptzЭ����Ŀ����0��ʼ(������ʱ��1)*/
    BYTE    byRes[8];
}NET_DVR_PTZCFG, *LPNET_DVR_PTZCFG;

/***************************��̨����(end)******************************/

//ͨ��������(��̨)��������(9000��չ)
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//������(bps)��0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k;
	BYTE byDataBit;// �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ;
	BYTE byStopBit;// ֹͣλ 0��1λ��1��2λ;
	BYTE byParity;// У�� 0����У�飬1����У�飬2��żУ��;
	BYTE byFlowcontrol;// 0���ޣ�1��������,2-Ӳ����
	WORD wDecoderType;//����������, ��0��ʼ����ӦptzЭ���б���NET_DVR_IPC_PROTO_LIST�õ�
	WORD wDecoderAddress;	/*��������ַ:0 - 255*/
	BYTE bySetPreset[MAX_PRESET_V30];		/* Ԥ�õ��Ƿ�����,0-û������,1-����*/
	BYTE bySetCruise[MAX_CRUISE_V30];		/* Ѳ���Ƿ�����: 0-û������,1-���� */
	BYTE bySetTrack[MAX_TRACK_V30];		    /* �켣�Ƿ�����,0-û������,1-����*/
}NET_DVR_DECODERCFG_V30, *LPNET_DVR_DECODERCFG_V30;

//ͨ��������(��̨)��������
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;       //������(bps)��0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k;
	BYTE byDataBit;         // �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ;
	BYTE byStopBit;         // ֹͣλ 0��1λ��1��2λ;
	BYTE byParity;          // У�� 0����У�飬1����У�飬2��żУ��;
	BYTE byFlowcontrol;     // 0���ޣ�1��������,2-Ӳ����
	WORD wDecoderType;      //����������  NET_DVR_IPC_PROTO_LIST�еõ�
	WORD wDecoderAddress;	/*��������ַ:0 - 255*/
	BYTE bySetPreset[MAX_PRESET];		/* Ԥ�õ��Ƿ�����,0-û������,1-����*/
	BYTE bySetCruise[MAX_CRUISE];		/* Ѳ���Ƿ�����: 0-û������,1-���� */
	BYTE bySetTrack[MAX_TRACK];		/* �켣�Ƿ�����,0-û������,1-����*/
}NET_DVR_DECODERCFG, *LPNET_DVR_DECODERCFG;

//ppp��������(�ӽṹ)
typedef struct 
{
	NET_DVR_IPADDR struRemoteIP;	//Զ��IP��ַ
	NET_DVR_IPADDR struLocalIP;		//����IP��ַ
	char sLocalIPMask[16];			//����IP��ַ����
	BYTE sUsername[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byPPPMode;					//PPPģʽ, 0��������1������
	BYTE byRedial;					//�Ƿ�ز� ��0-��,1-��
	BYTE byRedialMode;				//�ز�ģʽ,0-�ɲ�����ָ��,1-Ԥ�ûز�����
	BYTE byDataEncrypt;				//���ݼ���,0-��,1-��
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //�绰����
}NET_DVR_PPPCFG_V30, *LPNET_DVR_PPPCFG_V30;

//ppp��������(�ӽṹ)
typedef struct 
{
	char sRemoteIP[16];				//Զ��IP��ַ
	char sLocalIP[16];				//����IP��ַ
	char sLocalIPMask[16];			//����IP��ַ����
	BYTE sUsername[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byPPPMode;					//PPPģʽ, 0��������1������
	BYTE byRedial;					//�Ƿ�ز� ��0-��,1-��
	BYTE byRedialMode;				//�ز�ģʽ,0-�ɲ�����ָ��,1-Ԥ�ûز�����
	BYTE byDataEncrypt;				//���ݼ���,0-��,1-��
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //�绰����
}NET_DVR_PPPCFG, *LPNET_DVR_PPPCFG;

//RS232���ڲ�������(9000��չ)
typedef struct
{
    DWORD dwBaudRate;   /*������(bps)��0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k;*/
    BYTE byDataBit;     /* �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ */
    BYTE byStopBit;     /* ֹͣλ 0��1λ��1��2λ */
    BYTE byParity;      /* У�� 0����У�飬1����У�飬2��żУ�� */
    BYTE byFlowcontrol; /* 0���ޣ�1��������,2-Ӳ���� */
    DWORD dwWorkMode;   /* ����ģʽ��0��232��������PPP���ţ�1��232�������ڲ������ƣ�2��͸��ͨ��  3- ptzģʽ 4-������ģʽ*/
}NET_DVR_SINGLE_RS232;

//RS232���ڲ�������(9000��չ)
typedef struct 
{
	DWORD dwSize;
    NET_DVR_SINGLE_RS232 struRs232[MAX_SERIAL_PORT];/*ע�⣺�˽ṹ�޸��ˣ�ԭ���ǵ����ṹ�������޸�Ϊ������ṹ*/
	NET_DVR_PPPCFG_V30 struPPPConfig;
}NET_DVR_RS232CFG_V30, *LPNET_DVR_RS232CFG_V30;

//RS232���ڲ�������
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//������(bps)��0��50��1��75��2��110��3��150��4��300��5��600��6��1200��7��2400��8��4800��9��9600��10��19200�� 11��38400��12��57600��13��76800��14��115.2k;
	BYTE byDataBit;// �����м�λ 0��5λ��1��6λ��2��7λ��3��8λ;
	BYTE byStopBit;// ֹͣλ 0��1λ��1��2λ;
	BYTE byParity;// У�� 0����У�飬1����У�飬2��żУ��;
	BYTE byFlowcontrol;// 0���ޣ�1��������,2-Ӳ����
	DWORD dwWorkMode;// ����ģʽ��0��խ������(232��������PPP����)��1������̨(232�������ڲ�������)��2��͸��ͨ��
	NET_DVR_PPPCFG struPPPConfig;
}NET_DVR_RS232CFG, *LPNET_DVR_RS232CFG;

//���������������(9000��չ)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* ���� */
	BYTE byAlarmType;	            //����������,0������,1������
	BYTE byAlarmInHandle;	        /* �Ƿ��� 0-������ 1-����*/
    BYTE byChannel;                 // �������봥������ʶ��ͨ��
    BYTE byRes1[1];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //����������¼��ͨ��,Ϊ1��ʾ������ͨ��
	BYTE byEnablePreset[MAX_CHANNUM_V30];		/* �Ƿ����Ԥ�õ� 0-��,1-��*/
	BYTE byPresetNo[MAX_CHANNUM_V30];			/* ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ㡣*/
	BYTE byRes2[192];					/*����*/
	BYTE byEnableCruise[MAX_CHANNUM_V30];		/* �Ƿ����Ѳ�� 0-��,1-��*/
	BYTE byCruiseNo[MAX_CHANNUM_V30];			/* Ѳ�� */
	BYTE byEnablePtzTrack[MAX_CHANNUM_V30];		/* �Ƿ���ù켣 0-��,1-��*/
	BYTE byPTZTrack[MAX_CHANNUM_V30];			/* ���õ���̨�Ĺ켣��� */
    BYTE byRes3[16];
}NET_DVR_ALARMINCFG_V30, *LPNET_DVR_ALARMINCFG_V30;

//���������������
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* ���� */
	BYTE byAlarmType;	//����������,0������,1������
	BYTE byAlarmInHandle;	/* �Ƿ��� 0-������ 1-����*/
    BYTE byChannel;                 // �������봥������ʶ��ͨ��
    BYTE byRes;                     
    NET_DVR_HANDLEEXCEPTION struAlarmHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM]; //����������¼��ͨ��,Ϊ1��ʾ������ͨ��
	BYTE byEnablePreset[MAX_CHANNUM];		/* �Ƿ����Ԥ�õ� 0-��,1-��*/
	BYTE byPresetNo[MAX_CHANNUM];			/* ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ㡣*/
	BYTE byEnableCruise[MAX_CHANNUM];		/* �Ƿ����Ѳ�� 0-��,1-��*/
	BYTE byCruiseNo[MAX_CHANNUM];			/* Ѳ�� */
	BYTE byEnablePtzTrack[MAX_CHANNUM];		/* �Ƿ���ù켣 0-��,1-��*/
	BYTE byPTZTrack[MAX_CHANNUM];			/* ���õ���̨�Ĺ켣��� */
}NET_DVR_ALARMINCFG, *LPNET_DVR_ALARMINCFG;


//�ϴ�������Ϣ(9000��չ)
typedef struct 
{
	DWORD dwAlarmType;/*0-�ź�������,1-Ӳ����,2-�źŶ�ʧ,3���ƶ����,4��Ӳ��δ��ʽ��,5-��дӲ�̳���,6-�ڵ�����,7-��ʽ��ƥ��, 8-�Ƿ�����, 9-��Ƶ�ź��쳣��
                        10-¼���쳣 11- ���ܳ����仯  12-�����쳣 */
	DWORD dwAlarmInputNumber;/*��������˿�*/
	BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30];/*����������˿ڣ�Ϊ1��ʾ��Ӧ���*/
	BYTE byAlarmRelateChannel[MAX_CHANNUM_V30];/*������¼��ͨ����Ϊ1��ʾ��Ӧ¼��, dwAlarmRelateChannel[0]��Ӧ��1��ͨ��*/
	BYTE byChannel[MAX_CHANNUM_V30];/*dwAlarmTypeΪ2��3,6��9��10ʱ����ʾ�ĸ�ͨ����dwChannel[0]��Ӧ��1��ͨ��*/
	BYTE byDiskNumber[MAX_DISKNUM_V30];/*dwAlarmTypeΪ1,4,5ʱ,��ʾ�ĸ�Ӳ��, dwDiskNumber[0]��Ӧ��1��Ӳ��*/
#ifdef SDK_CHEZAI
	NET_DVR_ADDIT_POSITION GPS_pos;  /* GPS��λ��Ϣ */
#endif
}NET_DVR_ALARMINFO_V30, *LPNET_DVR_ALARMINFO_V30;


typedef struct 
{
	DWORD dwAlarmType;/*0-�ź�������,1-Ӳ����,2-�źŶ�ʧ,3���ƶ����,4��Ӳ��δ��ʽ��,5-��дӲ�̳���,6-�ڵ�����,7-��ʽ��ƥ��, 8-�Ƿ�����, 9-��Ƶ�ź��쳣��10-¼���쳣 11- ���ܳ����仯*/
	DWORD dwAlarmInputNumber;/*��������˿�*/
	DWORD dwAlarmOutputNumber[MAX_ALARMOUT];/*����������˿ڣ���һλΪ1��ʾ��Ӧ��һ�����*/
	DWORD dwAlarmRelateChannel[MAX_CHANNUM];/*������¼��ͨ������һλΪ1��ʾ��Ӧ��һ·¼��, dwAlarmRelateChannel[0]��Ӧ��1��ͨ��*/
	DWORD dwChannel[MAX_CHANNUM];/*dwAlarmTypeΪ2��3,6,9,10ʱ����ʾ�ĸ�ͨ����dwChannel[0]λ��Ӧ��1��ͨ��*/
	DWORD dwDiskNumber[MAX_DISKNUM];/*dwAlarmTypeΪ1,4,5ʱ,��ʾ�ĸ�Ӳ��, dwDiskNumber[0]λ��Ӧ��1��Ӳ��*/
}NET_DVR_ALARMINFO, *LPNET_DVR_ALARMINFO;




//////////////////////////////////////////////////////////////////////////////////////
//IPC�����������
/* IP�豸�ṹ */
typedef struct 
{
    DWORD dwEnable;				    /* ��IP�豸�Ƿ����� */
    BYTE sUserName[NAME_LEN];		/* �û��� */
    BYTE sPassword[PASSWD_LEN];	    /* ���� */ 
    NET_DVR_IPADDR struIP;			/* IP��ַ */
    WORD wDVRPort;			 	    /* �˿ں� */
    BYTE byRes[34];				/* ���� */
}NET_DVR_IPDEVINFO, *LPNET_DVR_IPDEVINFO;

//ipc�����豸��Ϣ��չ��֧��ip�豸����������
typedef struct tagNET_DVR_IPDEVINFO_V31
{
    BYTE byEnable;				    //��IP�豸�Ƿ���Ч
	BYTE byProType;					//Э�����ͣ�0-˽��Э�飬1-����Э�飬2-����
    BYTE byEnableQuickAdd;        // 0 ��֧�ֿ�������  1 ʹ�ÿ������� 
    // ����������Ҫ�豸IP��Э�����ͣ�������Ϣ���豸Ĭ��ָ��
    BYTE byRes1;					//�����ֶΣ���0
    BYTE sUserName[NAME_LEN];		//�û���
    BYTE sPassword[PASSWD_LEN];	    //����
    BYTE byDomain[MAX_DOMAIN_NAME];	//�豸����
    NET_DVR_IPADDR struIP;			//IP��ַ
    WORD wDVRPort;			 	    // �˿ں�
    BYTE byRes2[34];				//�����ֶΣ���0
}NET_DVR_IPDEVINFO_V31, *LPNET_DVR_IPDEVINFO_V31;

/* IPͨ��ƥ����� */
typedef struct 
{
    BYTE byEnable;					/* ��ͨ���Ƿ����� */
    BYTE byIPID;					/* IP�豸ID ȡֵ1- MAX_IP_DEVICE */
    BYTE byChannel;					/* ͨ���� */
	BYTE byres[33];					//����,��0
} NET_DVR_IPCHANINFO, *LPNET_DVR_IPCHANINFO;

/* IP�������ýṹ */
typedef struct 
{
    DWORD dwSize;			                            /* �ṹ��С */
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];    /* IP�豸 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* ģ��ͨ���Ƿ����ã��ӵ͵��߱�ʾ1-32ͨ����0��ʾ��Ч 1��Ч */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IPͨ�� */    
}NET_DVR_IPPARACFG, *LPNET_DVR_IPPARACFG;
/* ��չIP�������ýṹ */
typedef struct tagNET_DVR_IPPARACFG_V31
{
    DWORD dwSize;			                            /* �ṹ��С */
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];    /* IP�豸 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* ģ��ͨ���Ƿ����ã��ӵ͵��߱�ʾ1-32ͨ����0��ʾ��Ч 1��Ч */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IPͨ�� */    
}NET_DVR_IPPARACFG_V31, *LPNET_DVR_IPPARACFG_V31;

typedef  struct tagNET_DVR_IPSERVER_STREAM
{
    BYTE    byEnable;   // �Ƿ�����
    BYTE    byRes[3];               // �����ֽ�
    NET_DVR_IPADDR struIPServer;    //IPServer ��ַ
    WORD    wPort;                  //IPServer �˿�
    WORD    wDvrNameLen;            // DVR ���Ƴ���
    BYTE    byDVRName[NAME_LEN];    // DVR����
    WORD    wDVRSerialLen;          // ���кų���
    WORD    byRes1[2];              // �����ֽ�
    BYTE    byDVRSerialNumber[SERIALNO_LEN];    // DVR���кų���
    BYTE    byUserName[NAME_LEN];   // DVR ��½�û���
    BYTE    byPassWord[PASSWD_LEN]; // DVR��½����
    BYTE    byChannel;              // DVR ͨ��
    BYTE    byRes2[11];             //  �����ֽ�
}NET_DVR_IPSERVER_STREAM, *LPNET_DVR_IPSERVER_STREAM;

/*��ý���������������*/
typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG
{
    BYTE	byValid;			/*�Ƿ�������ý�������ȡ��,0��ʾ��Ч����0��ʾ��Ч*/
    BYTE	byRes1[3];
    NET_DVR_IPADDR  struDevIP;      
    WORD	wDevPort;			/*��ý��������˿�*/    
    BYTE	byTransmitType;		/*����Э������ 0-TCP��1-UDP*/
    BYTE	byRes2[69];
}NET_DVR_STREAM_MEDIA_SERVER_CFG,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG;

//�豸ͨ����Ϣ
typedef struct tagNET_DVR_DEV_CHAN_INFO
{
    NET_DVR_IPADDR 	struIP;		    //DVR IP��ַ
    WORD 	wDVRPort;			 	//�˿ں�
    BYTE 	byChannel;				//ͨ����
    BYTE	byTransProtocol;		//����Э������0-TCP��1-UDP
    BYTE	byTransMode;			//��������ģʽ 0�������� 1��������
    BYTE	byFactoryType;			/*ǰ���豸��������,ͨ���ӿڻ�ȡ*/
    BYTE	byRes[6];
    BYTE    byDomain[MAX_DOMAIN_NAME];	//�豸����
    BYTE	sUserName[NAME_LEN];	//���������½�ʺ�
    BYTE	sPassword[PASSWD_LEN];	//�����������
}NET_DVR_DEV_CHAN_INFO,*LPNET_DVR_DEV_CHAN_INFO;

typedef struct tagNET_DVR_PU_STREAM_CFG
{
    DWORD								dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG	struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG,*LPNET_DVR_PU_STREAM_CFG;

typedef union tagNET_DVR_GET_STREAM_UNION
{
    NET_DVR_IPCHANINFO      struChanInfo;	/*IPͨ����Ϣ*/
    NET_DVR_IPSERVER_STREAM struIPServerStream;  // IPServerȥ��
    NET_DVR_PU_STREAM_CFG  struPUStream;     //  ͨ��ǰ���豸��ȡ��ý��ȥ��
}NET_DVR_GET_STREAM_UNION, *LPNET_DVR_GET_STREAM_UNION;

typedef enum
{
    IP_DEVICE = 0,
    STREAM_MEDIA,
    IPSERVER
}GET_STREAM_TYPE;

typedef struct tagNET_DVR_STREAM_MODE
{
    BYTE    byGetStreamType; //ȡ����ʽ��0-ֱ�Ӵ��豸ȡ����1-����ý��ȡ����2-ͨ��IPServer���ip��ַ��ȡ��
    BYTE    byRes[3];      // �����ֽ�
    NET_DVR_GET_STREAM_UNION uGetStream;    // ��ͬȡ����ʽ�ṹ��
}NET_DVR_STREAM_MODE, *LPNET_DVR_STREAM_MODE;
/*��չIP���������豸*/
typedef struct tagNET_DVR_IPPARACFG_V40
{
    DWORD      dwSize;			                /* �ṹ��С */
    DWORD      dwAChanNum;					//���ģ��ͨ������
    DWORD      dwDChanNum;                  //����ͨ������
    DWORD      dwStartDChan;		            //��ʼ����ͨ��
    BYTE       byAnalogChanEnable[MAX_CHANNUM_V30];    /* ģ��ͨ���Ƿ����ã��ӵ͵��߱�ʾ1-64ͨ����0��ʾ��Ч 1��Ч */
    NET_DVR_IPDEVINFO_V31   struIPDevInfo[MAX_IP_DEVICE_V40];      /* IP�豸 */
    NET_DVR_STREAM_MODE  struStreamMode [MAX_CHANNUM_V30];
    BYTE            byRes2[20];                 // �����ֽ�
}NET_DVR_IPPARACFG_V40, *LPNET_DVR_IPPARACFG_V40;

/* ����������� */
typedef struct 
{
    BYTE byIPID;					/* IP�豸IDȡֵ1- MAX_IP_DEVICE */
    BYTE byAlarmOut;				/* ��������� */
    BYTE byRes[18];					/* ���� */
}NET_DVR_IPALARMOUTINFO, *LPNET_DVR_IPALARMOUTINFO;

/* IP����������ýṹ */
typedef struct 
{
    DWORD dwSize;			                        /* �ṹ��С */    
   NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];/* IP������� */
}NET_DVR_IPALARMOUTCFG, *LPNET_DVR_IPALARMOUTCFG;

/* ����������� */
typedef struct 
{
    BYTE byIPID;					/* IP�豸IDȡֵ1- MAX_IP_DEVICE */
    BYTE byAlarmIn;					/* ��������� */
    BYTE byRes[18];					/* ���� */
}NET_DVR_IPALARMININFO, *LPNET_DVR_IPALARMININFO;

/* IP�����������ýṹ */
typedef struct 
{
    DWORD dwSize;			                        /* �ṹ��С */    
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];/* IP�������� */
}NET_DVR_IPALARMINCFG, *LPNET_DVR_IPALARMINCFG;

//ipc alarm info
typedef struct tagNET_DVR_IPALARMINFO
{
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];            /* IP�豸 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* ģ��ͨ���Ƿ����ã�0-δ���� 1-���� */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IPͨ�� */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP�������� */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP������� */
}NET_DVR_IPALARMINFO, *LPNET_DVR_IPALARMINFO;

//ipc���øı䱨����Ϣ��չ 9000_1.1
typedef struct tagNET_DVR_IPALARMINFO_V31
{
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];            /* IP�豸 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* ģ��ͨ���Ƿ����ã�0-δ���� 1-���� */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IPͨ�� */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP�������� */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP������� */   
}NET_DVR_IPALARMINFO_V31, *LPNET_DVR_IPALARMINFO_V31;

typedef struct tagNET_DVR_IPALARMINFO_V40
{
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE_V40];           // IP�豸
    BYTE     byAnalogChanEnable[MAX_CHANNUM_V30];           /* ģ��ͨ���Ƿ����ã�0-δ���� 1-���� */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_CHANNUM_V30];	        /* IPͨ�� */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP�������� */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP������� */   
    BYTE                    byRes[20];                          // �����ֽ�
}NET_DVR_IPALARMINFO_V40, *LPNET_DVR_IPALARMINFO_V40;

typedef enum _HD_STAT_
{
	HD_STAT_OK					=	0,  /* ���� */
	HD_STAT_UNFORMATTED			=	1,  /* δ��ʽ�� */
	HD_STAT_ERROR           	=	2,  /* ���� */
	HD_STAT_SMART_FAILED    	=	3,  /* SMART״̬ */
	HD_STAT_MISMATCH        	=	4,  /* ��ƥ�� */
	HD_STAT_IDLE            	=	5,  /* ����*/
	NET_HD_STAT_OFFLINE     	=	6  /*�����̴���δ����״̬ */	
}HD_STAT;


//����Ӳ����Ϣ����
typedef struct
{
    DWORD dwHDNo;         /*Ӳ�̺�, ȡֵ0~MAX_DISKNUM_V30-1*/
    DWORD dwCapacity;     /*Ӳ������(��������)*/
    DWORD dwFreeSpace;    /*Ӳ��ʣ��ռ�(��������)*/
    DWORD dwHdStatus;     /*Ӳ��״̬(��������) HD_STAT*/
    BYTE  byHDAttr;       /*0-Ĭ��, 1-����; 2-ֻ��*/
	BYTE  byHDType;		  /*0-����Ӳ��,1-ESATAӲ��,2-NASӲ��,3-iSCSIӲ�� 4-Array�������*/
    BYTE  byDiskDriver;   // ֵ ������ASCII�ַ� 
	BYTE  byRes1[1];
    DWORD dwHdGroup;      /*�����ĸ����� 1-MAX_HD_GROUP*/
    BYTE  byRes2[120];
}NET_DVR_SINGLE_HD, *LPNET_DVR_SINGLE_HD;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDCount;          /*Ӳ����(��������)*/
    NET_DVR_SINGLE_HD struHDInfo[MAX_DISKNUM_V30];//Ӳ����ز�������Ҫ����������Ч��
}NET_DVR_HDCFG, *LPNET_DVR_HDCFG;

//����������Ϣ����
typedef struct
{
    DWORD dwHDGroupNo;       /*�����(��������) 1-MAX_HD_GROUP*/        
    BYTE byHDGroupChans[MAX_CHANNUM_V30]; /*�����Ӧ��¼��ͨ��, 0-��ʾ��ͨ����¼�󵽸����飬1-��ʾ¼�󵽸�����*/
    BYTE byRes[8];
}NET_DVR_SINGLE_HDGROUP, *LPNET_DVR_SINGLE_HDGROUP;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDGroupCount;        /*��������(��������)*/
    NET_DVR_SINGLE_HDGROUP struHDGroupAttr[MAX_HD_GROUP];//Ӳ����ز�������Ҫ����������Ч��
}NET_DVR_HDGROUP_CFG, *LPNET_DVR_HDGROUP_CFG;
                                       

//�������Ų����Ľṹ
typedef struct
{
    DWORD dwSize;
    DWORD dwMajorScale;    /* ����ʾ 0-�����ţ�1-����*/
    DWORD dwMinorScale;    /* ����ʾ 0-�����ţ�1-����*/
    DWORD dwRes[2];
}NET_DVR_SCALECFG, *LPNET_DVR_SCALECFG;



//DVR�������(9000��չ)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* ���� */
	DWORD dwAlarmOutDelay;	/* �������ʱ��(-1Ϊ���ޣ��ֶ��ر�) */
	//0-5��,1-10��,2-30��,3-1����,4-2����,5-5����,6-10����,7-�ֶ�
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT_V30];/* �����������ʱ��� */
    BYTE byRes[16];
}NET_DVR_ALARMOUTCFG_V30, *LPNET_DVR_ALARMOUTCFG_V30;

//DVR�������
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* ���� */
	DWORD dwAlarmOutDelay;	/* �������ʱ��(-1Ϊ���ޣ��ֶ��ر�) */
	//0-5��,1-10��,2-30��,3-1����,4-2����,5-5����,6-10����,7-�ֶ�
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT];/* �����������ʱ��� */
}NET_DVR_ALARMOUTCFG, *LPNET_DVR_ALARMOUTCFG;

//DVR����Ԥ������(9000��չ)
typedef struct 
{
    DWORD dwSize;
    BYTE byPreviewNumber;//Ԥ����Ŀ,0-1����,1-4����,2-9����,3-16����,0xff:�����
    BYTE byEnableAudio;//�Ƿ�����Ԥ��,0-��Ԥ��,1-Ԥ��
    WORD wSwitchTime;//�л�ʱ��,0-���л�,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
    BYTE bySwitchSeq[MAX_PREVIEW_MODE][MAX_WINDOW_V30];//�л�˳��,���lSwitchSeq[i]Ϊ 0xff��ʾ����
    BYTE byRes[24];
}NET_DVR_PREVIEWCFG_V30, *LPNET_DVR_PREVIEWCFG_V30;
//DVR����Ԥ������
typedef struct 
{
	DWORD dwSize;
	BYTE byPreviewNumber;//Ԥ����Ŀ,0-1����,1-4����,2-9����,3-16����,0xff:�����
	BYTE byEnableAudio;//�Ƿ�����Ԥ��,0-��Ԥ��,1-Ԥ��
	WORD wSwitchTime;//�л�ʱ��,0-���л�,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
	BYTE bySwitchSeq[MAX_WINDOW];//�л�˳��,���lSwitchSeq[i]Ϊ 0xff��ʾ����
}NET_DVR_PREVIEWCFG, *LPNET_DVR_PREVIEWCFG;

//DVR��Ƶ���
typedef struct 
{
	WORD wResolution;							/* �ֱ��� */
	WORD wFreq;									/* ˢ��Ƶ�� */
	DWORD dwBrightness;							/* ���� */
}NET_DVR_VGAPARA;

/*
* MATRIX��������ṹ
*/
typedef struct
{		
	WORD	wOrder[MAX_ANALOG_CHANNUM];		/* Ԥ��˳��, 0xff��ʾ��Ӧ�Ĵ��ڲ�Ԥ�� */
	WORD	wSwitchTime;				/* Ԥ���л�ʱ�� */
	BYTE	res[14];
}NET_DVR_MATRIXPARA_V30, *LPNET_DVR_MATRIXPARA_V30;

typedef struct 
{
	WORD wDisplayLogo;						/* ��ʾ��Ƶͨ���� */
	WORD wDisplayOsd;						/* ��ʾʱ�� */
}NET_DVR_MATRIXPARA;

typedef struct 
{
	BYTE byVideoFormat;						/* �����ʽ,0-PAL,1-NTSC */
	BYTE byMenuAlphaValue;					/* �˵��뱳��ͼ��Աȶ� */
	WORD wScreenSaveTime;					/* ��Ļ����ʱ�� 0-�Ӳ�,1-1����,2-2����,3-5����,4-10����,5-20����,6-30���� */
	WORD wVOffset;							/* ��Ƶ���ƫ�� */
	WORD wBrightness;						/* ��Ƶ������� */
	BYTE byStartMode;						/* ��������Ƶ���ģʽ(0:�˵�,1:Ԥ��)*/
	BYTE byEnableScaler;                    /* �Ƿ��������� (0-������, 1-����)*/
}NET_DVR_VOOUT;

//DVR��Ƶ���(9000��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT_V30];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA_V30];	/* VGA���� */
	NET_DVR_MATRIXPARA_V30 struMatrixPara[MAX_MATRIXOUT];		/* MATRIX���� */
    BYTE byRes[16];
}NET_DVR_VIDEOOUT_V30, *LPNET_DVR_VIDEOOUT_V30;

//DVR��Ƶ���
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA];	/* VGA���� */
	NET_DVR_MATRIXPARA struMatrixPara;		/* MATRIX���� */
}NET_DVR_VIDEOOUT, *LPNET_DVR_VIDEOOUT;

//���û�����(�ӽṹ)(9000��չ)
typedef struct
{
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byLocalRight[MAX_RIGHT];	/* ����Ȩ�� */
	/*����0: ���ؿ�����̨*/
	/*����1: �����ֶ�¼��*/
	/*����2: ���ػط�*/
	/*����3: �������ò���*/
	/*����4: ���ز鿴״̬����־*/
	/*����5: ���ظ߼�����(��������ʽ�����������ػ�)*/
    /*����6: ���ز鿴���� */
    /*����7: ���ع���ģ���IP camera */
    /*����8: ���ر��� */
    /*����9: ���عػ�/���� */    
	BYTE byRemoteRight[MAX_RIGHT];/* Զ��Ȩ�� */	
	/*����0: Զ�̿�����̨*/
	/*����1: Զ���ֶ�¼��*/
	/*����2: Զ�̻ط� */
	/*����3: Զ�����ò���*/
	/*����4: Զ�̲鿴״̬����־*/
	/*����5: Զ�̸߼�����(��������ʽ�����������ػ�)*/
	/*����6: Զ�̷��������Խ�*/
	/*����7: Զ��Ԥ��*/
	/*����8: Զ�����󱨾��ϴ����������*/
	/*����9: Զ�̿��ƣ��������*/
	/*����10: Զ�̿��ƴ���*/	
    /*����11: Զ�̲鿴���� */
    /*����12: Զ�̹���ģ���IP camera */
    /*����13: Զ�̹ػ�/���� */
	BYTE byNetPreviewRight[MAX_CHANNUM_V30];		/* Զ�̿���Ԥ����ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byLocalPlaybackRight[MAX_CHANNUM_V30];	/* ���ؿ��Իطŵ�ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byNetPlaybackRight[MAX_CHANNUM_V30];	/* Զ�̿��Իطŵ�ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byLocalRecordRight[MAX_CHANNUM_V30];		/* ���ؿ���¼���ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byNetRecordRight[MAX_CHANNUM_V30];		/* Զ�̿���¼���ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byLocalPTZRight[MAX_CHANNUM_V30];		/* ���ؿ���PTZ��ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byNetPTZRight[MAX_CHANNUM_V30];			/* Զ�̿���PTZ��ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	BYTE byLocalBackupRight[MAX_CHANNUM_V30];		/* ���ر���Ȩ��ͨ�� 0-��Ȩ�ޣ�1-��Ȩ��*/
	NET_DVR_IPADDR struUserIP;		/* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */
	BYTE byMACAddr[MACADDR_LEN];	/* ������ַ */
	BYTE byPriority;				/* ���ȼ���0xff-�ޣ�0--�ͣ�1--�У�2--�� */
                                    /*
                                    �ޡ�����ʾ��֧�����ȼ�������
                                    �͡���Ĭ��Ȩ��:�������غ�Զ�̻ط�,���غ�Զ�̲鿴��־��״̬,���غ�Զ�̹ػ�/����
                                    �С����������غ�Զ�̿�����̨,���غ�Զ���ֶ�¼��,���غ�Զ�̻ط�,�����Խ���Զ��Ԥ��
                                          ���ر���,����/Զ�̹ػ�/����
                                    �ߡ�������Ա
                                    */
	BYTE	byAlarmOnRight;         // ��������ڲ���Ȩ��
	BYTE	byAlarmOffRight;        // ��������ڳ���Ȩ��
	BYTE	byBypassRight;          // �����������·Ȩ��
	BYTE	byRes[14];	
}NET_DVR_USER_INFO_V30, *LPNET_DVR_USER_INFO_V30;

//���û�����(SDK_V15��չ)(�ӽṹ)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	DWORD dwLocalRight[MAX_RIGHT];	/* Ȩ�� */
	/*����0: ���ؿ�����̨*/
	/*����1: �����ֶ�¼��*/
	/*����2: ���ػط�*/
	/*����3: �������ò���*/
	/*����4: ���ز鿴״̬����־*/
	/*����5: ���ظ߼�����(��������ʽ�����������ػ�)*/
	DWORD dwLocalPlaybackRight;		/* ���ؿ��Իطŵ�ͨ�� bit0 -- channel 1*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* Ȩ�� */
	/*����0: Զ�̿�����̨*/
	/*����1: Զ���ֶ�¼��*/
	/*����2: Զ�̻ط� */
	/*����3: Զ�����ò���*/
	/*����4: Զ�̲鿴״̬����־*/
	/*����5: Զ�̸߼�����(��������ʽ�����������ػ�)*/
	/*����6: Զ�̷��������Խ�*/
	/*����7: Զ��Ԥ��*/
	/*����8: Զ�����󱨾��ϴ����������*/
	/*����9: Զ�̿��ƣ��������*/
	/*����10: Զ�̿��ƴ���*/
	DWORD dwNetPreviewRight;		/* Զ�̿���Ԥ����ͨ�� bit0 -- channel 1*/
	DWORD dwNetPlaybackRight;		/* Զ�̿��Իطŵ�ͨ�� bit0 -- channel 1*/
	char sUserIP[16];				/* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */
	BYTE byMACAddr[MACADDR_LEN];	/* ������ַ */
}NET_DVR_USER_INFO_EX, *LPNET_DVR_USER_INFO_EX;

//���û�����(�ӽṹ)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	DWORD dwLocalRight[MAX_RIGHT];	/* Ȩ�� */
	/*����0: ���ؿ�����̨*/
	/*����1: �����ֶ�¼��*/
	/*����2: ���ػط�*/
	/*����3: �������ò���*/
	/*����4: ���ز鿴״̬����־*/
	/*����5: ���ظ߼�����(��������ʽ�����������ػ�)*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* Ȩ�� */
	/*����0: Զ�̿�����̨*/
	/*����1: Զ���ֶ�¼��*/
	/*����2: Զ�̻ط� */
	/*����3: Զ�����ò���*/
	/*����4: Զ�̲鿴״̬����־*/
	/*����5: Զ�̸߼�����(��������ʽ�����������ػ�)*/
	/*����6: Զ�̷��������Խ�*/
	/*����7: Զ��Ԥ��*/
	/*����8: Զ�����󱨾��ϴ����������*/
	/*����9: Զ�̿��ƣ��������*/
	/*����10: Զ�̿��ƴ���*/
	char sUserIP[16];				/* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */
	BYTE byMACAddr[MACADDR_LEN];	/* ������ַ */
}NET_DVR_USER_INFO, *LPNET_DVR_USER_INFO;


//DVR�û�����(9000��չ)
typedef struct
{
	DWORD dwSize;
	NET_DVR_USER_INFO_V30 struUser[MAX_USERNUM_V30];
}NET_DVR_USER_V30, *LPNET_DVR_USER_V30;

//DVR�û�����(SDK_V15��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO_EX struUser[MAX_USERNUM];
}NET_DVR_USER_EX, *LPNET_DVR_USER_EX;

//DVR�û�����
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO struUser[MAX_USERNUM];
}NET_DVR_USER, *LPNET_DVR_USER;

//DVR�쳣����(9000��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION_V30 struExceptionHandleType[MAX_EXCEPTIONNUM_V30];
	/*����0-����,1- Ӳ�̳���,2-���߶�,3-��������IP ��ַ��ͻ, 4-�Ƿ�����, 5-����/�����Ƶ��ʽ��ƥ��, 6-��Ƶ�ź��쳣, 7-¼���쳣*/
}NET_DVR_EXCEPTION_V30, *LPNET_DVR_EXCEPTION_V30;

//DVR�쳣����
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION struExceptionHandleType[MAX_EXCEPTIONNUM];
	/*����0-����,1- Ӳ�̳���,2-���߶�,3-��������IP ��ַ��ͻ,4-�Ƿ�����, 5-����/�����Ƶ��ʽ��ƥ��, 6-��Ƶ�ź��쳣*/
}NET_DVR_EXCEPTION, *LPNET_DVR_EXCEPTION;

//ͨ��״̬(9000��չ)
typedef struct 
{
	BYTE byRecordStatic; //ͨ���Ƿ���¼��,0-��¼��,1-¼��
	BYTE bySignalStatic; //���ӵ��ź�״̬,0-����,1-�źŶ�ʧ
	BYTE byHardwareStatic;//ͨ��Ӳ��״̬,0-����,1-�쳣,����DSP����
	BYTE byRes1;		//����
	DWORD dwBitRate;//ʵ������
	DWORD dwLinkNum;//�ͻ������ӵĸ���
	NET_DVR_IPADDR struClientIP[MAX_LINK];//�ͻ��˵�IP��ַ
    DWORD dwIPLinkNum;//�����ͨ��ΪIP���룬��ô��ʾIP���뵱ǰ��������
	BYTE byRes[12];
}NET_DVR_CHANNELSTATE_V30, *LPNET_DVR_CHANNELSTATE_V30;

//ͨ��״̬
typedef struct 
{
	BYTE byRecordStatic; //ͨ���Ƿ���¼��,0-��¼��,1-¼��
	BYTE bySignalStatic; //���ӵ��ź�״̬,0-����,1-�źŶ�ʧ
	BYTE byHardwareStatic;//ͨ��Ӳ��״̬,0-����,1-�쳣,����DSP����
	char reservedData;		//����
	DWORD dwBitRate;//ʵ������
	DWORD dwLinkNum;//�ͻ������ӵĸ���
	DWORD dwClientIP[MAX_LINK];//�ͻ��˵�IP��ַ
}NET_DVR_CHANNELSTATE, *LPNET_DVR_CHANNELSTATE;

//Ӳ��״̬
typedef struct 
{
	DWORD dwVolume;//Ӳ�̵�����
	DWORD dwFreeSpace;//Ӳ�̵�ʣ��ռ�
	DWORD dwHardDiskStatic; //Ӳ�̵�״̬,0-�,1-����,2-������
}NET_DVR_DISKSTATE, *LPNET_DVR_DISKSTATE;

//DVR����״̬(9000��չ)
typedef struct 
{
	DWORD dwDeviceStatic; 	//�豸��״̬,0-����,1-CPUռ����̫��,����85%,2-Ӳ������,���紮������
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];
	NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30];//ͨ����״̬
	BYTE  byAlarmInStatic[MAX_ALARMIN_V30]; //�����˿ڵ�״̬,0-û�б���,1-�б���
	BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30]; //��������˿ڵ�״̬,0-û�����,1-�б������
	DWORD  dwLocalDisplay;//������ʾ״̬,0-����,1-������
    BYTE  byAudioChanStatus[MAX_AUDIO_V30];//��ʾ����ͨ����״̬ 0-δʹ�ã�1-ʹ����, 0xff��Ч
    BYTE  byRes[10];
}NET_DVR_WORKSTATE_V30, *LPNET_DVR_WORKSTATE_V30;

//DVR����״̬
typedef struct 
{
	DWORD dwDeviceStatic; 	//�豸��״̬,0-����,1-CPUռ����̫��,����85%,2-Ӳ������,���紮������
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM];
	NET_DVR_CHANNELSTATE struChanStatic[MAX_CHANNUM];//ͨ����״̬
	BYTE  byAlarmInStatic[MAX_ALARMIN]; //�����˿ڵ�״̬,0-û�б���,1-�б���
	BYTE  byAlarmOutStatic[MAX_ALARMOUT]; //��������˿ڵ�״̬,0-û�����,1-�б������
	DWORD  dwLocalDisplay;//������ʾ״̬,0-����,1-������
}NET_DVR_WORKSTATE, *LPNET_DVR_WORKSTATE;

/************************DVR��־ begin***************************/


/* ���� */
//������
#define MAJOR_ALARM						0x1
//������
#define MINOR_ALARM_IN					0x1		/* �������� */
#define MINOR_ALARM_OUT					0x2		/* ������� */
#define MINOR_MOTDET_START				0x3		/* �ƶ���ⱨ����ʼ */
#define MINOR_MOTDET_STOP				0x4		/* �ƶ���ⱨ������ */
#define MINOR_HIDE_ALARM_START			0x5		/* �ڵ�������ʼ */
#define MINOR_HIDE_ALARM_STOP			0x6		/* �ڵ��������� */
#define MINOR_VCA_ALARM_START			0x7		/*���ܱ�����ʼ*/
#define MINOR_VCA_ALARM_STOP			0x8		/*���ܱ���ֹͣ*/
#define MINOR_ITS_ALARM_START           0x09    // ��ͨ�¼�������ʼ
#define MINOR_ITS_ALARM_STOP            0x0A    // ��ͨ�¼���������
//2010-11-10 ���籨����־
#define MINOR_NETALARM_START            0x0b    /*���籨����ʼ*/
#define MINOR_NETALARM_STOP             0x0c    /*���籨������*/
//2010-12-16 ��������־����"MINOR_ALARM_IN"���ʹ��
#define MINOR_NETALARM_RESUME			0x0d	/*���籨���ָ�*/
/* �쳣 */
//������
#define MAJOR_EXCEPTION					0x2
//������
#define MINOR_VI_LOST					0x21	/* ��Ƶ�źŶ�ʧ */
#define MINOR_ILLEGAL_ACCESS			0x22	/* �Ƿ����� */
#define MINOR_HD_FULL					0x23	/* Ӳ���� */
#define MINOR_HD_ERROR					0x24	/* Ӳ�̴��� */
#define MINOR_DCD_LOST					0x25	/* MODEM ����(������ʹ��) */
#define MINOR_IP_CONFLICT				0x26	/* IP��ַ��ͻ */
#define MINOR_NET_BROKEN				0x27	/* ����Ͽ�*/
#define MINOR_REC_ERROR                 0x28    /* ¼����� */
#define MINOR_IPC_NO_LINK               0x29    /* IPC�����쳣 */
#define MINOR_VI_EXCEPTION              0x2a    /* ��Ƶ�����쳣(ֻ���ģ��ͨ��) */
#define MINOR_IPC_IP_CONFLICT           0x2b    /*ipc ip ��ַ ��ͻ*/
#define MINOR_SENCE_EXCEPTION           0x2c    // �����쳣

//2009-12-16 ������Ƶ�ۺ�ƽ̨��־����
#define MINOR_FANABNORMAL				0x31	/* ��Ƶ�ۺ�ƽ̨������״̬�쳣 */
#define MINOR_FANRESUME					0x32	/* ��Ƶ�ۺ�ƽ̨������״̬�ָ����� */
#define MINOR_SUBSYSTEM_ABNORMALREBOOT	0x33	/* ��Ƶ�ۺ�ƽ̨��6467�쳣���� */
#define MINOR_MATRIX_STARTBUZZER		0x34	/* ��Ƶ�ۺ�ƽ̨��dm6467�쳣������������ */

//2010-01-22 ������Ƶ�ۺ�ƽ̨�쳣��־������
#define MINOR_NET_ABNORMAL				0x35	/*����״̬�쳣*/
#define MINOR_MEM_ABNORMAL				0x36	/*�ڴ�״̬�쳣*/
#define MINOR_FILE_ABNORMAL				0x37	/*�ļ�״̬�쳣*/
#define MINOR_PANEL_ABNORMAL			0x38 /*ǰ��������쳣*/
#define MINOR_PANEL_RESUME				0x39 /*ǰ���ָ�����*/	
#define MINOR_RS485_DEVICE_ABNORMAL		0x3a 	/*RS485����״̬�쳣*/
#define MINOR_RS485_DEVICE_REVERT		0x3b    /*RS485����״̬�쳣�ָ�*/
/* ���� */
//������
#define MAJOR_OPERATION					0x3
//������
#define MINOR_START_DVR					0x41	/* ���� */
#define MINOR_STOP_DVR					0x42	/* �ػ� */
#define MINOR_STOP_ABNORMAL				0x43	/* �쳣�ػ� */
#define MINOR_REBOOT_DVR                0x44    /*���������豸*/

#define MINOR_LOCAL_LOGIN				0x50	/* ���ص�½ */
#define MINOR_LOCAL_LOGOUT				0x51	/* ����ע����½ */
#define MINOR_LOCAL_CFG_PARM			0x52	/* �������ò��� */
#define MINOR_LOCAL_PLAYBYFILE          0x53	/* ���ذ��ļ��طŻ����� */
#define MINOR_LOCAL_PLAYBYTIME          0x54	/* ���ذ�ʱ��طŻ�����*/
#define MINOR_LOCAL_START_REC			0x55	/* ���ؿ�ʼ¼�� */
#define MINOR_LOCAL_STOP_REC			0x56	/* ����ֹͣ¼�� */
#define MINOR_LOCAL_PTZCTRL				0x57	/* ������̨���� */
#define MINOR_LOCAL_PREVIEW				0x58	/* ����Ԥ�� (������ʹ��)*/
#define MINOR_LOCAL_MODIFY_TIME         0x59	/* �����޸�ʱ��(������ʹ��) */
#define MINOR_LOCAL_UPGRADE             0x5a	/* �������� */
#define MINOR_LOCAL_RECFILE_OUTPUT      0x5b    /* ���ر���¼���ļ� */
#define MINOR_LOCAL_FORMAT_HDD          0x5c    /* ���س�ʼ��Ӳ�� */
#define MINOR_LOCAL_CFGFILE_OUTPUT      0x5d    /* �������������ļ� */
#define MINOR_LOCAL_CFGFILE_INPUT       0x5e    /* ���뱾�������ļ� */
#define MINOR_LOCAL_COPYFILE            0x5f    /* ���ر����ļ� */
#define MINOR_LOCAL_LOCKFILE            0x60    /* ��������¼���ļ� */
#define MINOR_LOCAL_UNLOCKFILE          0x61    /* ���ؽ���¼���ļ� */
#define MINOR_LOCAL_DVR_ALARM           0x62    /* �����ֶ�����ʹ�������*/
#define MINOR_IPC_ADD                   0x63    /* ��������IPC */
#define MINOR_IPC_DEL                   0x64    /* ����ɾ��IPC */
#define MINOR_IPC_SET                   0x65    /* ��������IPC */
#define MINOR_LOCAL_START_BACKUP		0x66	/* ���ؿ�ʼ���� */
#define MINOR_LOCAL_STOP_BACKUP			0x67	/* ����ֹͣ����*/
#define MINOR_LOCAL_COPYFILE_START_TIME 0x68	/* ���ر��ݿ�ʼʱ��*/
#define MINOR_LOCAL_COPYFILE_END_TIME	0x69	/* ���ر��ݽ���ʱ��*/
#define MINOR_LOCAL_ADD_NAS             0x6a	/*������������Ӳ�� ��nfs��iscsi��*/
#define MINOR_LOCAL_DEL_NAS             0x6b	/* ����ɾ��nas�� ��nfs��iscsi��*/
#define MINOR_LOCAL_SET_NAS             0x6c	/* ��������nas�� ��nfs��iscsi��*/

#define MINOR_REMOTE_LOGIN				0x70	/* Զ�̵�¼ */
#define MINOR_REMOTE_LOGOUT				0x71	/* Զ��ע����½ */
#define MINOR_REMOTE_START_REC			0x72	/* Զ�̿�ʼ¼�� */
#define MINOR_REMOTE_STOP_REC			0x73	/* Զ��ֹͣ¼�� */
#define MINOR_START_TRANS_CHAN			0x74	/* ��ʼ͸������ */
#define MINOR_STOP_TRANS_CHAN			0x75	/* ֹͣ͸������ */
#define MINOR_REMOTE_GET_PARM			0x76	/* Զ�̻�ȡ���� */
#define MINOR_REMOTE_CFG_PARM			0x77	/* Զ�����ò��� */
#define MINOR_REMOTE_GET_STATUS         0x78	/* Զ�̻�ȡ״̬ */
#define MINOR_REMOTE_ARM				0x79	/* Զ�̲��� */
#define MINOR_REMOTE_DISARM				0x7a	/* Զ�̳��� */
#define MINOR_REMOTE_REBOOT				0x7b	/* Զ������ */
#define MINOR_START_VT					0x7c	/* ��ʼ�����Խ� */
#define MINOR_STOP_VT					0x7d	/* ֹͣ�����Խ� */
#define MINOR_REMOTE_UPGRADE			0x7e	/* Զ������ */
#define MINOR_REMOTE_PLAYBYFILE         0x7f	/* Զ�̰��ļ��ط� */
#define MINOR_REMOTE_PLAYBYTIME         0x80	/* Զ�̰�ʱ��ط� */
#define MINOR_REMOTE_PTZCTRL			0x81	/* Զ����̨���� */
#define MINOR_REMOTE_FORMAT_HDD         0x82    /* Զ�̸�ʽ��Ӳ�� */
#define MINOR_REMOTE_STOP               0x83    /* Զ�̹ػ� */
#define MINOR_REMOTE_LOCKFILE			0x84	/* Զ�������ļ� */
#define MINOR_REMOTE_UNLOCKFILE         0x85	/* Զ�̽����ļ� */
#define MINOR_REMOTE_CFGFILE_OUTPUT     0x86    /* Զ�̵��������ļ� */
#define MINOR_REMOTE_CFGFILE_INTPUT     0x87    /* Զ�̵��������ļ� */
#define MINOR_REMOTE_RECFILE_OUTPUT     0x88    /* Զ�̵���¼���ļ� */
#define MINOR_REMOTE_DVR_ALARM          0x89    /* Զ���ֶ�����ʹ�������*/
#define MINOR_REMOTE_IPC_ADD			0x8a	/* Զ������IPC */
#define MINOR_REMOTE_IPC_DEL			0x8b	/* Զ��ɾ��IPC */
#define MINOR_REMOTE_IPC_SET			0x8c	/* Զ������IPC */
#define MINOR_REBOOT_VCA_LIB            0x8d    /*�������ܿ�*/
#define MINOR_REMOTE_ADD_NAS            0x8e   /* Զ������nas�� ��nfs��iscsi��*/
#define MINOR_REMOTE_DEL_NAS            0x8f   /* Զ��ɾ��nas�� ��nfs��iscsi��*/
#define MINOR_REMOTE_SET_NAS            0x90   /* Զ������nas�� ��nfs��iscsi��*/

//2010-05-26 ������ѶDVR��־����
#define MINOR_LOCAL_START_REC_CDRW      0x91   /* ���ؿ�ʼ��¼ */
#define MINOR_LOCAL_STOP_REC_CDRW       0x92   /* ����ֹͣ��¼ */
#define MINOR_REMOTE_START_REC_CDRW     0x93   /* Զ�̿�ʼ��¼ */
#define MINOR_REMOTE_STOP_REC_CDRW      0x94   /* Զ��ֹͣ��¼ */

//2009-12-16 ������Ƶ�ۺ�ƽ̨��־����
#define MINOR_SUBSYSTEMREBOOT           0xa0	/*��Ƶ�ۺ�ƽ̨��dm6467 ��������*/
#define MINOR_MATRIX_STARTTRANSFERVIDEO 0xa1	/*��Ƶ�ۺ�ƽ̨�������л���ʼ����ͼ��*/
#define MINOR_MATRIX_STOPTRANSFERVIDEO	0xa2	/*��Ƶ�ۺ�ƽ̨�������л�ֹͣ����ͼ��*/
#define MINOR_REMOTE_SET_ALLSUBSYSTEM   0xa3	/*��Ƶ�ۺ�ƽ̨����������6467��ϵͳ��Ϣ*/
#define MINOR_REMOTE_GET_ALLSUBSYSTEM   0xa4	/*��Ƶ�ۺ�ƽ̨����ȡ����6467��ϵͳ��Ϣ*/
#define MINOR_REMOTE_SET_PLANARRAY      0xa5	/*��Ƶ�ۺ�ƽ̨�����üƻ���Ѳ��*/
#define MINOR_REMOTE_GET_PLANARRAY      0xa6	/*��Ƶ�ۺ�ƽ̨����ȡ�ƻ���Ѳ��*/
#define MINOR_MATRIX_STARTTRANSFERAUDIO 0xa7	/*��Ƶ�ۺ�ƽ̨�������л���ʼ������Ƶ*/
#define MINOR_MATRIX_STOPRANSFERAUDIO   0xa8	/*��Ƶ�ۺ�ƽ̨�������л�ֹͣ������Ƶ*/
#define MINOR_LOGON_CODESPITTER         0xa9	/*��Ƶ�ۺ�ƽ̨����½�����*/
#define MINOR_LOGOFF_CODESPITTER        0xaa	/*��Ƶ�ۺ�ƽ̨���˳������*/

//2010-01-22 ������Ƶ�ۺ�ƽ̨�н�����������־
#define MINOR_START_DYNAMIC_DECODE 		0xb0	/*��ʼ��̬����*/
#define MINOR_STOP_DYNAMIC_DECODE		0xb1	/*ֹͣ��̬����*/
#define MINOR_GET_CYC_CFG				0xb2	/*��ȡ������ͨ����Ѳ����*/
#define MINOR_SET_CYC_CFG				0xb3	/*���ý���ͨ����Ѳ����*/
#define MINOR_START_CYC_DECODE			0xb4	/*��ʼ��Ѳ����*/
#define MINOR_STOP_CYC_DECODE			0xb5	/*ֹͣ��Ѳ����*/
#define MINOR_GET_DECCHAN_STATUS		0xb6	/*��ȡ����ͨ��״̬*/
#define MINOR_GET_DECCHAN_INFO			0xb7	/*��ȡ����ͨ����ǰ��Ϣ*/
#define MINOR_START_PASSIVE_DEC			0xb8	/*��ʼ��������*/
#define MINOR_STOP_PASSIVE_DEC			0xb9	/*ֹͣ��������*/
#define MINOR_CTRL_PASSIVE_DEC			0xba	/*���Ʊ�������*/
#define MINOR_RECON_PASSIVE_DEC			0xbb	/*������������*/
#define MINOR_GET_DEC_CHAN_SW			0xbc	/*��ȡ����ͨ���ܿ���*/
#define MINOR_SET_DEC_CHAN_SW			0xbd	/*���ý���ͨ���ܿ���*/
#define MINOR_CTRL_DEC_CHAN_SCALE		0xbe	/*����ͨ�����ſ���*/
#define MINOR_SET_REMOTE_REPLAY			0xbf	/*����Զ�̻ط�*/
#define MINOR_GET_REMOTE_REPLAY			0xc0	/*��ȡԶ�̻ط�״̬*/
#define MINOR_CTRL_REMOTE_REPLAY		0xc1	/*Զ�̻طſ���*/
#define MINOR_SET_DISP_CFG				0xc2	/*������ʾͨ��*/
#define MINOR_GET_DISP_CFG				0xc3	/*��ȡ��ʾͨ������*/
#define MINOR_SET_PLANTABLE				0xc4	/*���üƻ���Ѳ��*/
#define MINOR_GET_PLANTABLE				0xc5	/*��ȡ�ƻ���Ѳ��*/
#define MINOR_START_PPPPOE				0xc6	/*��ʼPPPoE����*/
#define MINOR_STOP_PPPPOE				0xc7	/*����PPPoE����*/
#define MINOR_UPLOAD_LOGO				0xc8	/*�ϴ�LOGO*/
//2010-12-16 ��������־
#define MINOR_REMOTE_BYPASS             0xd0    /* Զ����·*/
#define MINOR_REMOTE_UNBYPASS           0xd1    /* Զ����·�ָ�*/
#define MINOR_REMOTE_SET_ALARMIN_CFG    0xd2    /* Զ�����ñ����������*/
#define MINOR_REMOTE_GET_ALARMIN_CFG    0xd3    /* Զ�̻�ȡ�����������*/
#define MINOR_REMOTE_SET_ALARMOUT_CFG   0xd4    /* Զ�����ñ����������*/
#define MINOR_REMOTE_GET_ALARMOUT_CFG   0xd5    /* Զ�̻�ȡ�����������*/
#define MINOR_REMOTE_ALARMOUT_OPEN_MAN  0xd6    /* Զ���ֶ������������*/
#define MINOR_REMOTE_ALARMOUT_CLOSE_MAN 0xd7    /* Զ���ֶ��رձ������*/
#define MINOR_REMOTE_ALARM_ENABLE_CFG   0xd8    /* Զ�����ñ���������RS485����ʹ��״̬*/
#define MINOR_DBDATA_OUTPUT				0xd9	/* �������ݿ��¼ */
#define MINOR_DBDATA_INPUT				0xda	/* �������ݿ��¼ */
#define MINOR_MU_SWITCH					0xdb	/* �����л� */
#define MINOR_MU_PTZ					0xdc	/* ����PTZ���� */

#define MINOR_LOCAL_CONF_REB_RAID       0x101           /*���������Զ��ؽ�*/
#define MINOR_LOCAL_CONF_SPARE          0x102           /*���������ȱ�*/
#define MINOR_LOCAL_ADD_RAID            0x103           /*���ش�������*/
#define MINOR_LOCAL_DEL_RAID            0x104           /*����ɾ������*/
#define MINOR_LOCAL_MIG_RAID            0x105           /*����Ǩ������*/
#define MINOR_LOCAL_REB_RAID            0x106           /* �����ֶ��ؽ�����*/
#define MINOR_LOCAL_QUICK_CONF_RAID     0x107           /*����һ������*/
#define MINOR_LOCAL_ADD_VD              0x108           /*���ش����������*/
#define MINOR_LOCAL_DEL_VD              0x109           /*����ɾ���������*/
#define MINOR_LOCAL_RP_VD               0x10a           /*�����޸��������*/
#define MINOR_LOCAL_FORMAT_EXPANDVD     0X10b           /*������չ�����������*/
#define MINOR_LOCAL_RAID_UPGRADE        0X10c           /*����raid������*/    
#define MINOR_REMOTE_CONF_REB_RAID      0x111           /*Զ�������Զ��ؽ�*/
#define MINOR_REMOTE_CONF_SPARE         0x112            /*Զ�������ȱ�*/
#define MINOR_REMOTE_ADD_RAID           0x113           /*Զ�̴�������*/
#define MINOR_REMOTE_DEL_RAID           0x114           /*Զ��ɾ������*/
#define MINOR_REMOTE_MIG_RAID           0x115           /*Զ��Ǩ������*/
#define MINOR_REMOTE_REB_RAID           0x116           /* Զ���ֶ��ؽ�����*/
#define MINOR_REMOTE_QUICK_CONF_RAID    0x117           /*Զ��һ������*/
#define MINOR_REMOTE_ADD_VD             0x118           /*Զ�̴����������*/
#define MINOR_REMOTE_DEL_VD             0x119           /*Զ��ɾ���������*/
#define MINOR_REMOTE_RP_VD              0x11a           /*Զ���޸��������*/
#define MINOR_REMOTE_FORMAT_EXPANDVD    0X11b           /*Զ�������������*/
#define MINOR_REMOTE_RAID_UPGRADE       0X11c           /*Զ��raid������*/    

/*��־������Ϣ*/
//������
#define MAJOR_INFORMATION               0x4     /*������Ϣ*/
//������
#define MINOR_HDD_INFO                  0xa1 /*Ӳ����Ϣ*/
#define MINOR_SMART_INFO                0xa2 /*SMART��Ϣ*/
#define MINOR_REC_START                 0xa3 /*��ʼ¼��*/
#define MINOR_REC_STOP                  0xa4 /*ֹͣ¼��*/
#define MINOR_REC_OVERDUE				0xa5 /*����¼��ɾ��*/
#define MINOR_LINK_START				0xa6 //����ǰ���豸
#define MINOR_LINK_STOP					0xa7 //�Ͽ�ǰ���豸��
#define MINOR_NET_DISK_INFO				0xa8 //����Ӳ����Ϣ
#define MINOR_RAID_INFO                 0xa9 //raid�����Ϣ

typedef enum tagALARMHOST_MAJOR_TYPE
{
    MAJOR_ALARMHOST_ALARM = 1,
    MAJOR_ALARMHOST_EXCEPTION,
    MAJOR_ALARMHOST_OPERATION,
    MAJ0R_ALARMHOST_EVENT
}ALARMHOST_MAJOR_TYPE;

typedef enum tagALARMHOST_MINOR_TYPE
{
    // ���� 
    MINOR_SHORT_CIRCUIT =0x01,      // ��·����
    MINOR_BROKEN_CIRCUIT,           // ��·����
    MINOR_ALARM_RESET,              // ������λ
    MINOR_ALARM_NORMAL,				// �����ָ�����
    MINOR_PASSWORD_ERROR,			// �����������3�������������
    MINOR_ID_CARD_ILLEGALLY,		// �Ƿ���Ӧ��ID
    MINOR_KEYPAD_REMOVE,			// ���̷���
    MINOR_KEYPAD_REMOVE_RESTORE,	// ���̷���λ
    MINOR_DEV_REMOVE,				// �豸����
    MINOR_DEV_REMOVE_RESTORE,		// �豸����λ
    MINOR_BELOW_ALARM_LIMIT1,		// ģ�������ڱ�����1
    MINOR_BELOW_ALARM_LIMIT2,		// ģ�������ڱ�����2
    MINOR_BELOW_ALARM_LIMIT3,		// ģ�������ڱ�����3
    MINOR_BELOW_ALARM_LIMIT4,		// ģ�������ڱ�����4
    MINOR_ABOVE_ALARM_LIMIT1,		// ģ�������ڱ�����1
    MINOR_ABOVE_ALARM_LIMIT2,		// ģ�������ڱ�����2
    MINOR_ABOVE_ALARM_LIMIT3,		// ģ�������ڱ�����3
    MINOR_ABOVE_ALARM_LIMIT4,		// ģ�������ڱ�����4

    // �쳣
    MINOR_POWER_ON      = 0x01,	// �ϵ�
    MINOR_POWER_OFF,				// ����
    MINOR_WDT_RESET,				// WDT ��λ
    MINOR_LOW_BATTERY_VOLTAGE,		// ���ص�ѹ��
    MINOR_AC_LOSS,					// ������ϵ�
    MINOR_AC_RESTORE,				// ������ָ�
    MINOR_RTC_EXCEPTION,			// RTCʵʱʱ���쳣
    MINOR_NETWORK_CONNECT_FAILURE,	// �������Ӷ�
    MINOR_NETWORK_CONNECT_RESTORE,	// �������ӻָ�
    MINOR_TEL_LINE_CONNECT_FAILURE,	// �绰�����Ӷ�
    MINOR_TEL_LINE_CONNECT_RESTORE,	// �绰�����ӻָ�
    MINOR_EXPANDER_BUS_LOSS,		// ��չ����ģ�����
    MINOR_EXPANDER_BUS_RESTORE,		// ��չ����ģ����߻ָ�
    MINOR_KEYPAD_BUS_LOSS,			// ��������ģ�����
    MINOR_KEYPAD_BUS_RESTORE,		// ��������ģ����߻ָ�
    MINOR_SENSOR_FAILURE,			// ģ��������������
    MINOR_SENSOR_RESTORE,			// ģ�����������ָ�
    MINOR_RS485_CONNECT_FAILURE,	// RS485ͨ�����Ӷ�
    MINOR_RS485_CONNECT_RESTORE,	// RS485ͨ�����Ӷϻָ�

    // ���� 
    MINOR_GUARD         = 0x01,	// ����
    MINOR_UNGUARD,					// ����
    MINOR_BYPASS,					// ��·
    MINOR_DURESS_ACCESS,			// Ю��
    MINOR_ALARMHOST_LOCAL_REBOOT,	// ��������
    MINOR_ALARMHOST_REMOTE_REBOOT,	// Զ������
    MINOR_ALARMHOST_LOCAL_UPGRADE,	// ��������
    MINOR_ALARMHOST_REMOTE_UPGRADE,	// Զ������
    MINOR_RECOVERY_DEFAULT_PARAM,	// �ָ�Ĭ�ϲ���
    MINOR_ALARM_OUTPUT,				// ���Ʊ������
    MINOR_ACCESS_OPEN,				// �����Ž���
    MINOR_ACCESS_CLOSE,				// �����Ž���
    MINOR_SIREN_OPEN,				// ���ƾ��ſ�
    MINOR_SIREN_CLOSE,				// ���ƾ��Ź�
    MINOR_MOD_ZONE_CONFIG,		// �޸ķ�������
    MINOR_MOD_ALARMOUT_CONIFG,	// ���Ʊ����������
    MINOR_MOD_ANALOG_CONFIG,		// �޸�ģ��������
    MINOR_RS485_CONFIG,				// �޸�485ͨ������
    MINOR_PHONE_CONFIG,				// �޸Ĳ�������
    MINOR_ADD_ADMIN,        // ���ӹ���Ա
    MINOR_MOD_ADMIN_PW,	// �޸Ĺ���Ա����
    MINOR_DEL_ADMIN,		// �ϳ�����Ա
    MINOR_ADD_NETUSER,		// ��˲���Ա
    MINOR_MOD_NETUSER_PW,	// �޸ĺ�˲���Ա����
    MINOR_DEL_NETUSER,				// ɾ����˲���Ա
    MINOR_ADD_OPERATORUSER,			// ����ǰ�˲���Ա
    MINOR_MOD_OPERATORUSER_PW,		//�޸�ǰ�˲���Ա����
    MINOR_DEL_OPERATORUSER,			// ɾ��ǰ�˲���Ա
    MINOR_ADD_KEYPADUSER,			// ���Ӽ���/�������û�	
    MINOR_DEL_KEYPADUSER,			// ɾ������/�������û�	
    MINOR_REMOTEUSER_LOGIN,		// Զ���û���½
    MINOR_REMOTEUSER_LOGOUT,		// Զ���û�ע��
    MINOR_REMOTE_GUARD,				// Զ�̲���
    MINOR_REMOTE_UNGUARD,			// Զ�̳���
    MINOR_MOD_HOST_CONFIG,          // �޸���������
    MINOR_RESTORE_BYPASS,			// ��·�ָ�

    // �¼� 
    MINOR_SCHOOLTIME_IRGI_B = 0x01,		// B��Уʱ
    MINOR_SCHOOLTIME_SDK,				// SDKУʱ
    MINOR_SCHOOLTIME_SELFTEST			// ��ʱ�Լ�Уʱ
}ALARMHOST_MINOR_TYPE;

//����־��������ΪMAJOR_OPERATION=03��������ΪMINOR_LOCAL_CFG_PARM=0x52����MINOR_REMOTE_GET_PARM=0x76����MINOR_REMOTE_CFG_PARM=0x77ʱ��dwParaType:����������Ч���京�����£�
#define PARA_VIDEOOUT	0x1
#define PARA_IMAGE		0x2
#define PARA_ENCODE		0x4
#define PARA_NETWORK	0x8
#define PARA_ALARM		0x10
#define PARA_EXCEPTION	0x20
#define PARA_DECODER	0x40    /*������*/
#define PARA_RS232		0x80
#define PARA_PREVIEW	0x100
#define PARA_SECURITY	0x200
#define PARA_DATETIME	0x400
#define PARA_FRAMETYPE	0x800    /*֡��ʽ*/
#define PARA_VCA_RULE   0x1001  //��Ϊ���� 
#define PARA_VCA_CTRL   0x1002  //�������ܿ�����Ϣ
#define PARA_VCA_PLATE  0x1003 //  ����ʶ��

#define PARA_CODESPLITTER 0x2000 /*���������*/
//2010-01-22 ������Ƶ�ۺ�ƽ̨��־��Ϣ������
#define PARA_RS485		  0x2001			/* RS485������Ϣ*/
#define PARA_DEVICE		  0x2002			/* �豸������Ϣ*/
#define PARA_HARDDISK	  0x2003			/* Ӳ��������Ϣ */
#define PARA_AUTOBOOT	  0x2004			/* �Զ�����������Ϣ*/
#define PARA_HOLIDAY	  0x2005			/* �ڼ���������Ϣ*/			
#define PARA_IPC		  0x2006			/* IPͨ������ */	

//��־��Ϣ(9000��չ)
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//������ 1-����; 2-�쳣; 3-����; 0xff-ȫ��
	DWORD	dwMinorType;//������ 0-ȫ��;
	BYTE	sPanelUser[MAX_NAMELEN]; //���������û���
	BYTE	sNetUser[MAX_NAMELEN];//����������û���
	NET_DVR_IPADDR	struRemoteHostAddr;//Զ��������ַ
	DWORD	dwParaType;//��������,9000�豸MINOR_START_VT/MINOR_STOP_VTʱ����ʾ�����Խ��Ķ��Ӻ�
	DWORD	dwChannel;//ͨ����
	DWORD	dwDiskNumber;//Ӳ�̺�
	DWORD	dwAlarmInPort;//��������˿�
	DWORD	dwAlarmOutPort;//��������˿�
    DWORD   dwInfoLen;
    char    sInfo[LOG_INFO_LEN];
}NET_DVR_LOG_V30, *LPNET_DVR_LOG_V30;

//��־��Ϣ
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//������ 1-����; 2-�쳣; 3-����; 0xff-ȫ��
	DWORD	dwMinorType;//������ 0-ȫ��;
	BYTE	sPanelUser[MAX_NAMELEN]; //���������û���
	BYTE	sNetUser[MAX_NAMELEN];//����������û���
	char	sRemoteHostAddr[16];//Զ��������ַ
	DWORD	dwParaType;//��������
	DWORD	dwChannel;//ͨ����
	DWORD	dwDiskNumber;//Ӳ�̺�
	DWORD	dwAlarmInPort;//��������˿�
	DWORD	dwAlarmOutPort;//��������˿�
}NET_DVR_LOG, *LPNET_DVR_LOG;

/************************DVR��־ end***************************/

/************************������������������־���� begin************************************************/
typedef struct tagNET_DVR_ALARMHOST_SEARCH_LOG_PARAM
{
    WORD            wMajorType;		// ������
    WORD            wMinorType;		// ������ 
    NET_DVR_TIME    struStartTime;	// ��ʼʱ�� 
    NET_DVR_TIME    struEndTime;	// ����ʱ��
    BYTE            byRes[8];		// �����ֽ�
}NET_DVR_ALARMHOST_SEARCH_LOG_PARAM, LPNET_DVR_ALARMHOST_SEARCH_LOG_PARAM;

typedef struct tagNET_DVR_ALARMHOST_LOG_RET
{
    NET_DVR_TIME	struLogTime;                //  ��־ʱ��
    BYTE		    sUserName[NAME_LEN];     // �����û�
    NET_DVR_IPADDR	struIPAddr;                 // ����IP��ַ
    WORD		    wMajorType;                 // ������ 
    WORD		    wMinorType;                 // ������
    WORD	    	wParam;	                    // ��������
    BYTE		    byRes[10];
    DWORD		    dwInfoLen;	                // ������Ϣ����
    char			sInfo[LOG_INFO_LEN];       // ������Ϣ
}NET_DVR_ALARMHOST_LOG_RET, *LPNET_DVR_ALARMHOST_LOG_RET;

/*************************������������������־���� end***********************************************/

//�������״̬(9000��չ)
typedef struct 
{
	BYTE Output[MAX_ALARMOUT_V30];
}NET_DVR_ALARMOUTSTATUS_V30, *LPNET_DVR_ALARMOUTSTATUS_V30;

//�������״̬
typedef struct 
{
	BYTE Output[MAX_ALARMOUT];
}NET_DVR_ALARMOUTSTATUS, *LPNET_DVR_ALARMOUTSTATUS;

//������Ϣ
typedef struct 
{
	USHORT m_Year;
	USHORT m_Month;
	USHORT m_Day;
	USHORT m_Hour;
	USHORT m_Minute;
	USHORT m_Second;
	BYTE DeviceName[24];	//�豸����
	DWORD dwChannelNumer;	//ͨ����
	BYTE CardNumber[32];	//����
	char cTradeType[12];	//��������
	DWORD dwCash;			//���׽��
}NET_DVR_TRADEINFO, *LPNET_DVR_TRADEINFO;


//ATMר��
/****************************ATM(begin)***************************/
#define NCR		0
#define DIEBOLD	1
#define WINCOR_NIXDORF	2
#define SIEMENS	3
#define OLIVETTI	4
#define FUJITSU	5
#define HITACHI	6
#define SMI		7
#define IBM		8
#define BULL	9
#define YiHua	10
#define LiDe	11
#define GDYT	12
#define Mini_Banl	13
#define GuangLi	14
#define DongXin	15
#define ChenTong	16
#define NanTian	17
#define XiaoXing	18
#define GZYY	19
#define QHTLT	20
#define DRS918	21
#define KALATEL	22
#define NCR_2	23	
#define NXS		24


/*֡��ʽ*/
typedef struct 
{
	BYTE code[12];		/* ���� */
}NET_DVR_FRAMETYPECODE;


//ATM����
typedef struct 
{
	DWORD dwSize;
	char sATMIP[16];						/* ATM IP��ַ */
	DWORD dwATMType;						/* ATM���� */
	DWORD dwInputMode;						/* ���뷽ʽ	0-�������� 1-������� 2-����ֱ������ 3-����ATM��������*/
	DWORD dwFrameSignBeginPos;              /* ���ı�־λ����ʼλ��*/
	DWORD dwFrameSignLength;				/* ���ı�־λ�ĳ��� */
	BYTE  byFrameSignContent[12];			/* ���ı�־λ������ */
	DWORD dwCardLengthInfoBeginPos;			/* ���ų�����Ϣ����ʼλ�� */
	DWORD dwCardLengthInfoLength;			/* ���ų�����Ϣ�ĳ��� */
	DWORD dwCardNumberInfoBeginPos;			/* ������Ϣ����ʼλ�� */
	DWORD dwCardNumberInfoLength;			/* ������Ϣ�ĳ��� */
	DWORD dwBusinessTypeBeginPos;           /* �������͵���ʼλ�� */
	DWORD dwBusinessTypeLength;				/* �������͵ĳ��� */
	NET_DVR_FRAMETYPECODE frameTypeCode[10];/* ���� */
}NET_DVR_FRAMEFORMAT, *LPNET_DVR_FRAMEFORMAT;
//SDK_V31 ATM

/*��������*/
typedef struct	tagNET_DVR_FILTER
{	
	BYTE			        byEnable;			//0,������;1,����
	BYTE					byMode;				//0,ASCII;1,HEX	
    BYTE                    byFrameBeginPos;    // ��Ҫ����Ŀ���ַ�����ʼλ��     
	BYTE					byRes[1];           // �����ֽ�
	BYTE 					byFilterText[16];	//�����ַ���
	BYTE					byRes2[12];         // �����ֽ�
}NET_DVR_FILTER, *LPNET_DVR_FILTER;

//���ݰ����� ���ݰ���ʶ
typedef struct	tagNET_DVR_IDENTIFICAT
{	
	BYTE					byStartMode;		//��ʼ�ַ�ģʽ:0,ASCII;1,HEX
	BYTE					byEndMode;			//�����ַ�ģʽ��0,ASCII;1,HEX
	BYTE					byRes[2];           //�����ֽ�
	NET_DVR_FRAMETYPECODE	struStartCode;		//���ݰ���ʼ��ʶ�ַ�
	NET_DVR_FRAMETYPECODE	struEndCode;		//���ݰ�������ʶ�ַ�
	BYTE					byRes1[12];         //�����ֽ�
}NET_DVR_IDENTIFICAT, *LPNET_DVR_IDENTIFICAT;

typedef struct	tagNET_DVR_PACKAGE_LOCATION/*������Ϣλ��*/
{	
	BYTE 					byOffsetMode;			/*����λ����Ϣģʽ 0,token(�ַ���־ģʽ);1,fix���̶�ģʽ��*/
    BYTE                    byRes1[3];				// �����ֽ�
	DWORD  				    dwOffsetPos;			/*modeΪ1��ʱ��ʹ��,�̶�ƫ�ƴ�С*/
	NET_DVR_FRAMETYPECODE	struTokenCode;			/*��־λ*/
	BYTE					byMultiplierValue;		/*��־λ���ٴγ���*/
	BYTE					byEternOffset;			/*�����ַ�ƫ����*/
	BYTE					byCodeMode;			    /*0,ASCII;1,HEX*/
	BYTE 					byRes2[9];			    //�����ֽ�
}NET_DVR_PACKAGE_LOCATION, *LPNET_DVR_PACKAGE_LOCATION;


typedef struct	tagNET_DVR_PACKAGE_LENGTH//������Ϣ����
{	
	BYTE					byLengthMode;			//�������ͣ�0,�ɱ䳤��;1,�̶�����;2,��������(�ӿ����л�ȡ)
    BYTE                    byRes1[3];              // �����ֽ�
	DWORD  			    	dwFixLength;			    //modeΪ1��ʱ��ʹ��,�̶����ȴ�С
	DWORD					dwMaxLength;            //������Ϣ��󳤶�  byLengthMode Ϊ0 ʱʹ��
	DWORD					dwMinLength;            //������Ϣ��С����  byLengthModeΪ1ʱʹ��
	BYTE					byEndMode;			    //�ɱ䳤�� �ս��ģʽ 0,ASCII;1,HEX	
    BYTE                    byRes2[3];              //�����ֽ�
	NET_DVR_FRAMETYPECODE	struEndCode;		//�ɱ䳤���ս��
	DWORD					dwLengthPos;			//lengthModeΪ2��ʱ��ʹ�ã����ų����ڱ����е�λ��
	DWORD					dwLengthLen;			//lengthModeΪ2��ʱ��ʹ�ã����ų��ȵĳ���
	BYTE					byRes3[8];              // �����ֽ�
}NET_DVR_PACKAGE_LENGTH,* LPNET_DVR_PACKAGE_LENGTH;
 
typedef struct	tagNET_DVR_OSD_POSITION//OSD ���ӵ�λ��
{	
	BYTE					byPositionMode;		//���ӷ�񣬹�2�֣�0������ʾ��1���Զ���
    BYTE                    byRes1[3];          // �����ֽ�
	DWORD 					dwPosX;				//x���꣬���ӷ��Ϊ�Զ���ʱʹ��
	DWORD					dwPosY;				//y���꣬���ӷ��Ϊ�Զ���ʱʹ��
	BYTE					byRes2[8];          //�����ֽ�
}NET_DVR_OSD_POSITION, *LPNET_DVR_OSD_POSITION;

typedef struct	tagNET_DVR_DATE_FORMAT//������ʾ��ʽ
{	
	BYTE					byMonth;			    //Month,0.mm;1.mmm;2.mmmm							
	BYTE 					byDay;				    //Day,0.dd;									
	BYTE 					byYear;				    //Year,0.yy;1.yyyy	
	BYTE					byDateForm;			    //0~5�������յ��������
	BYTE					byRes[20];              // �����ֽ�
	char					chSeprator[4];		    //�ָ���
	char	    			chDisplaySeprator[4];	//��ʾ�ָ���
    BYTE	    			byDisplayForm;			//0~5��3��item���������
	BYTE					res[27];                // �����ֽ�
}NET_DVR_DATE_FORMAT, *LPNET_DVR_DATE_FORMAT;
typedef struct	tagNET_DVRT_TIME_FORMAT//ʱ����ʾ��ʽ
{	
	BYTE					byTimeForm;				//1. HH MM SS;0. HH MM
	BYTE 					byRes1[23];             // �����ֽ�
    BYTE                    byHourMode;             //0,12;1,24 
    BYTE                    byRes2[3];              // �����ֽ�
	char					chSeprator[4]; 			//���ķָ�������ʱû��
	char					chDisplaySeprator[4];	//��ʾ�ָ���
	BYTE	    			byDisplayForm;			//0~5��3��item���������
    BYTE                    byRes3[3];              // �����ֽ�
	BYTE					byDisplayHourMode;		//0,12;1,24 
	BYTE					byRes4[19];             // �����ֽ�
}NET_DVR_TIME_FORMAT, *LPNET_DVR_TIME_FORMAT;

typedef struct tagNET_DVR_OVERLAY_CHANNEL
{	
	BYTE                    byChannel[64];//���ӵ�ͨ�� ÿ���ֽڱ�ʶһ��ͨ���� ����byChannel[0]ֵΪ1��Ӧ����ͨ��1��0��ʾ������ͨ��1��
	DWORD					dwDelayTime;			//������ʱʱ��
	BYTE					byEnableDelayTime;		//�Ƿ����õ�����ʱ
	BYTE					byRes[11];          // �����ֽ�
}NET_DVR_OVERLAY_CHANNEL, *LPNET_DVR_OVERLAY_CHANNEL;

// ATM ������Ϊ��Ϣ
typedef struct tagNET_DVR_ATM_PACKAGE_ACTION
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// ����λ����Ϣ
	NET_DVR_OSD_POSITION		struOsdPosition;    // OSD ����λ��
	NET_DVR_FRAMETYPECODE		struActionCode;		//����������Ϊ��
	NET_DVR_FRAMETYPECODE		struPreCode;		//�����ַ�ǰ���ַ�
	BYTE					byActionCodeMode;		//����������Ϊ��ģʽ0,ASCII;1,HEX
	BYTE					byRes[7];               // �����ֽ�
}NET_DVR_ATM_PACKAGE_ACTION, *LPNET_DVR_ATM_PACKAGE_ACTION;

// ATM ����DATA��Ϣ
typedef struct tagNET_DVR_ATM_PACKAGE_DATE
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// �����ڱ����е�λ����Ϣ
	NET_DVR_DATE_FORMAT		    struDateForm;		//������ʾ��ʽ
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD����λ����Ϣ
	BYTE				    	res[8]; 			// �����ֽ�
}NET_DVR_ATM_PACKAGE_DATE, *LPNET_DVR_ATM_PACKAGE_DATE;


//ATM����ʱ����Ϣ
typedef struct tagNET_DVR_ATM_PACKAGE_TIME
{	
	NET_DVR_PACKAGE_LOCATION	location;		// ʱ���ڱ����е�λ����Ϣ
	NET_DVR_TIME_FORMAT		    struTimeForm;	// ʱ����ʾ��ʽ
	NET_DVR_OSD_POSITION		struOsdPosition;// OSD ����λ����Ϣ
	BYTE					    byRes[8];		// �����ֽ�
}NET_DVR_ATM_PACKAGE_TIME, *LPNET_DVR_ATM_PACKAGE_TIME;


// ATM ����������Ϣ�����ţ����׽�������ţ�
typedef struct tagNET_DVR_ATM_PACKAGE_OTHERS
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation; //����λ����Ϣ
	NET_DVR_PACKAGE_LENGTH	struPackageLength;		//������Ϣ
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD����λ����Ϣ
	NET_DVR_FRAMETYPECODE		struPreCode;		//�����ַ�ǰ���ַ�
	BYTE					res[8];					//�����ֽ�
}NET_DVR_ATM_PACKAGE_OTHERS, *LPNET_DVR_ATM_PACKAGE_OTHERS;


//�û��Զ���Э��
typedef struct tagNET_DVR_ATM_USER_DEFINE_PROTOCOL
{
    NET_DVR_IDENTIFICAT        struIdentification;  //���ı�־
    NET_DVR_FILTER             struFilter; //���ݰ���������
    NET_DVR_ATM_PACKAGE_OTHERS struCardNoPara; //���ӿ�������
    NET_DVR_ATM_PACKAGE_ACTION struTradeActionPara[MAX_ACTION_TYPE]; //���ӽ�����Ϊ���� 0-9 ���ζ�ӦInCard OutCard OverLay SetTime GetStatus Query WithDraw Deposit ChanPass Transfer
    NET_DVR_ATM_PACKAGE_OTHERS struAmountPara; //���ӽ��׽������
    NET_DVR_ATM_PACKAGE_OTHERS struSerialNoPara; //���ӽ����������
    NET_DVR_OVERLAY_CHANNEL    struOverlayChan; //����ͨ������
    NET_DVR_ATM_PACKAGE_DATE   struRes1; //�������ڣ�����
    NET_DVR_ATM_PACKAGE_TIME   struRes2; //����ʱ�䣬����
    BYTE                       byRes3[124];        //����
}NET_DVR_ATM_USER_DEFINE_PROTOCOL, *LPNET_DVR_ATM_USER_DEFINE_PROTOCOL;

typedef struct tagNET_DVR_ATM_FRAMEFORMAT_V30
{		
    DWORD                        dwSize;                 //�ṹ��С
    BYTE					    byEnable;				/*�Ƿ�����0,������;1,����*/
    BYTE					    byInputMode;			/**���뷽ʽ:0-���������1����Э�顢2-���ڼ�����3-����Э��*/
    BYTE					    byRes1[34];              //�����ֽ� 
    NET_DVR_IPADDR		    	struAtmIp;				/*ATM ��IP �������ʱʹ�� */
    WORD					    wAtmPort;				/* ����Э�鷽ʽʱ��ʹ��*/
    BYTE					    byRes2[2];              // �����ֽ�
    DWORD					    dwAtmType;				/*ATMЭ�����ͣ���NET_DVR_ATM_PROTOCOL�ṹ�л�ȡ���������Ϊ�Զ���ʱʹ���û��Զ���Э��*/
    NET_DVR_ATM_USER_DEFINE_PROTOCOL   struAtmUserDefineProtocol; //�û��Զ���Э�飬��ATM����Ϊ�Զ�ʱ��Ҫʹ�øö���
    BYTE					    byRes3[8];
}NET_DVR_ATM_FRAMEFORMAT_V30, *LPNET_DVR_ATM_FRAMEFORMAT_V30;


typedef struct  tagNET_DVR_ATM_PROTO_TYPE
{
    DWORD dwAtmType; //ATMЭ�����ͣ�ͬʱ��Ϊ������� ATM �����е�dwAtmType �Զ���ʱΪ1025
    char chDesc[ATM_DESC_LEN]; //ATMЭ�������
}NET_DVR_ATM_PROTO_TYPE, *LPNET_DVR_ATM_PROTO_TYPE; //Э����Ϣ���ݽṹ

typedef struct tagNET_DVR_ATM_PROTO_LIST    //ATM Э���б�
{
    DWORD                  dwAtmProtoNum;           // Э���б��ĸ���
    NET_DVR_ATM_PROTO_TYPE struAtmProtoType[MAX_ATM_PROTOCOL_NUM]; //Э���б���Ϣ
}NET_DVR_ATM_PROTO_LIST, *LPNET_DVR_ATM_PROTO_LIST;

typedef struct tagNET_DVR_ATM_PROTOCOL
{
    DWORD dwSize;
    NET_DVR_ATM_PROTO_LIST struNetListenList; // �������Э������
    NET_DVR_ATM_PROTO_LIST struSerialListenList; //���ڼ���Э������
    NET_DVR_ATM_PROTO_LIST struNetProtoList;     //����Э������
    NET_DVR_ATM_PROTO_LIST struSerialProtoList;   //����Э������
    NET_DVR_ATM_PROTO_TYPE struCustomProto;        //�Զ���Э��
}NET_DVR_ATM_PROTOCOL, *LPNET_DVR_ATM_PROTOCOL;
// SDK_V31

/*****************************DS-6001D/F(begin)***************************/
//DS-6001D Decoder
typedef struct 
{
	BYTE byEncoderIP[16];		//�����豸���ӵķ�����IP
	BYTE byEncoderUser[16];		//�����豸���ӵķ��������û���
	BYTE byEncoderPasswd[16];	//�����豸���ӵķ�����������
	BYTE bySendMode;			//�����豸���ӷ�����������ģʽ
	BYTE byEncoderChannel;		//�����豸���ӵķ�������ͨ����
	WORD wEncoderPort;			//�����豸���ӵķ������Ķ˿ں�
	BYTE reservedData[4];		//����
}NET_DVR_DECODERINFO, *LPNET_DVR_DECODERINFO;

typedef struct 
{
	BYTE byEncoderIP[16];		//�����豸���ӵķ�����IP
	BYTE byEncoderUser[16];		//�����豸���ӵķ��������û���
	BYTE byEncoderPasswd[16];	//�����豸���ӵķ�����������
	BYTE byEncoderChannel;		//�����豸���ӵķ�������ͨ����
	BYTE bySendMode;			//�����豸���ӵķ�����������ģʽ
	WORD wEncoderPort;			//�����豸���ӵķ������Ķ˿ں�
	DWORD dwConnectState;		//�����豸���ӷ�������״̬
	BYTE reservedData[4];		//����
}NET_DVR_DECODERSTATE, *LPNET_DVR_DECODERSTATE;

/*�����豸�����붨��*/
#define NET_DEC_STARTDEC		1
#define NET_DEC_STOPDEC			2
#define NET_DEC_STOPCYCLE		3
#define NET_DEC_CONTINUECYCLE	4
/*���ӵ�ͨ������*/
typedef struct 
{
	char sDVRIP[16];				/* DVR IP��ַ */
	WORD wDVRPort;			 		/* �˿ں� */
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byChannel;					/* ͨ���� */
	BYTE byLinkMode;				/* ����ģʽ */
	BYTE byLinkType;				/* �������� 0�������� 1�������� */
}NET_DVR_DECCHANINFO, *LPNET_DVR_DECCHANINFO;

/*ÿ������ͨ��������*/
typedef struct 
{
	BYTE	byPoolChans;			/*ÿ·����ͨ���ϵ�ѭ��ͨ������, ���4ͨ�� 0��ʾû�н���*/
	NET_DVR_DECCHANINFO struchanConInfo[MAX_DECPOOLNUM];
	BYTE	byEnablePoll;			/*�Ƿ���Ѳ 0-�� 1-��*/
	BYTE	byPoolTime;				/*��Ѳʱ�� 0-���� 1-10�� 2-15�� 3-20�� 4-30�� 5-45�� 6-1���� 7-2���� 8-5���� */
}NET_DVR_DECINFO, *LPNET_DVR_DECINFO;

/*�����豸��������*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwDecChanNum; 		/*����ͨ��������*/
	NET_DVR_DECINFO struDecInfo[MAX_DECNUM];
}NET_DVR_DECCFG, *LPNET_DVR_DECCFG;

//2005-08-01
/* �����豸͸��ͨ������ */
typedef struct 
{
	DWORD dwEnableTransPort;	/* �Ƿ�����͸��ͨ�� 0�������� 1������*/
	char sDecoderIP[16];		/* DVR IP��ַ */
	WORD wDecoderPort;			/* �˿ں� */
	WORD wDVRTransPort;			/* ����ǰ��DVR�Ǵ�485/232�����1��ʾ232����,2��ʾ485���� */
	char cReserve[4];
}NET_DVR_PORTINFO, *LPNET_DVR_PORTINFO;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_PORTINFO struTransPortInfo[MAX_TRANSPARENTNUM]; /* ����0��ʾ232 ����1��ʾ485 */
}NET_DVR_PORTCFG, *LPNET_DVR_PORTCFG;

/* ���������ļ��ط� */
typedef struct 
{
	DWORD dwSize;
	char sDecoderIP[16];		/* DVR IP��ַ */
	WORD wDecoderPort;			/* �˿ں� */
	WORD wLoadMode;				/* �ط�����ģʽ 1�������� 2����ʱ�� */
	union
	{
		BYTE byFile[100];		/* �طŵ��ļ��� */
		struct
		{
			DWORD dwChannel;
			BYTE sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE sPassword[PASSWD_LEN];	/* ���� */
			NET_DVR_TIME struStartTime;	/* ��ʱ��طŵĿ�ʼʱ�� */
			NET_DVR_TIME struStopTime;	/* ��ʱ��طŵĽ���ʱ�� */
		}bytime;
	}mode_size;
}NET_DVR_PLAYREMOTEFILE, *LPNET_DVR_PLAYREMOTEFILE;

/*��ǰ�豸��������״̬*/
typedef struct 
{
	DWORD dwWorkType;		/*������ʽ��1����Ѳ��2����̬���ӽ��롢3���ļ��ط����� 4����ʱ��ط�����*/
	char sDVRIP[16];		/*���ӵ��豸ip*/
	WORD wDVRPort;			/*���Ӷ˿ں�*/
	BYTE byChannel;			/* ͨ���� */
	BYTE byLinkMode;		/* ����ģʽ */
	DWORD	dwLinkType;		/*�������� 0�������� 1��������*/
	union
	{
		struct
		{
			BYTE sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE sPassword[PASSWD_LEN];	/* ���� */
			char cReserve[52];
		}userInfo;
		struct
		{
			BYTE   fileName[100];
		}fileInfo;
		struct
		{
			DWORD	dwChannel;
			BYTE	sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE	sPassword[PASSWD_LEN];	/* ���� */
			NET_DVR_TIME struStartTime;		/* ��ʱ��طŵĿ�ʼʱ�� */
			NET_DVR_TIME struStopTime;		/* ��ʱ��طŵĽ���ʱ�� */
		}timeInfo;
	}objectInfo;
}NET_DVR_DECCHANSTATUS, *LPNET_DVR_DECCHANSTATUS;

typedef struct 
{
	DWORD   dwSize;
	NET_DVR_DECCHANSTATUS struDecState[MAX_DECNUM];
}NET_DVR_DECSTATUS, *LPNET_DVR_DECSTATUS;
/*****************************DS-6001D/F(end)***************************/

//���ַ�����(�ӽṹ)
typedef struct 
{
	WORD wShowString;				// Ԥ����ͼ�����Ƿ���ʾ�ַ�,0-����ʾ,1-��ʾ �����С704*576,�����ַ��Ĵ�СΪ32*32
	WORD wStringSize;				/* �����ַ��ĳ��ȣ����ܴ���44���ַ� */
	WORD wShowStringTopLeftX;		/* �ַ���ʾλ�õ�x���� */
	WORD wShowStringTopLeftY;		/* �ַ�������ʾλ�õ�y���� */
	char sString[44];				/* Ҫ��ʾ���ַ����� */
}NET_DVR_SHOWSTRINGINFO, *LPNET_DVR_SHOWSTRINGINFO;

//�����ַ�(9000��չ)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_V30];				/* Ҫ��ʾ���ַ����� */
}NET_DVR_SHOWSTRING_V30, *LPNET_DVR_SHOWSTRING_V30;

//�����ַ���չ(8���ַ�)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_EX];				/* Ҫ��ʾ���ַ����� */
}NET_DVR_SHOWSTRING_EX, *LPNET_DVR_SHOWSTRING_EX;

//�����ַ�
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM];				/* Ҫ��ʾ���ַ����� */
}NET_DVR_SHOWSTRING, *LPNET_DVR_SHOWSTRING;

/****************************DS9000�����ṹ(begin)******************************/

/*
EMAIL�����ṹ
*/
typedef struct
{		
	DWORD		dwSize;
	BYTE		sAccount[NAME_LEN];				/* �˺�*/ 
	BYTE		sPassword[MAX_EMAIL_PWD_LEN];			/*���� */
	struct
	{
		BYTE	sName[NAME_LEN];				/* ���������� */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* �����˵�ַ */
	}struSender;
	BYTE		sSmtpServer[MAX_EMAIL_ADDR_LEN];	/* smtp������ */
	BYTE		sPop3Server[MAX_EMAIL_ADDR_LEN];	/* pop3������ */
	struct
	{
		BYTE	sName[NAME_LEN];				/* �ռ������� */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* �ռ��˵�ַ */
	}struReceiver[3];							/* ����������3���ռ��� */
	BYTE		byAttachment;					/* �Ƿ������ */
	BYTE		bySmtpServerVerify;				/* ���ͷ�����Ҫ��������֤ */
    BYTE        byMailInterval;                 /* mail interval */
	BYTE        byEnableSSL;					//ssl�Ƿ�����9000_1.1
	WORD        wSmtpPort;						//gmail��465����ͨ��Ϊ25     
	BYTE        byRes[74];						//����
} NET_DVR_EMAILCFG_V30, *LPNET_DVR_EMAILCFG_V30;

/*
DVRʵ��Ѳ�����ݽṹ
*/
typedef struct
{	
	DWORD 	dwSize;
	BYTE	byPresetNo[CRUISE_MAX_PRESET_NUMS];		/* Ԥ�õ�� */
	BYTE 	byCruiseSpeed[CRUISE_MAX_PRESET_NUMS];	/* Ѳ���ٶ� */
	WORD	wDwellTime[CRUISE_MAX_PRESET_NUMS];		/* ͣ��ʱ�� */
	BYTE	byEnableThisCruise;						/* �Ƿ����� */
	BYTE	res[15];
}NET_DVR_CRUISE_PARA, *LPNET_DVR_CRUISE_PARA; 
/****************************DS9000�����ṹ(end)******************************/


//ʱ���
typedef struct 
{
	DWORD dwMonth;		//�� 0-11��ʾ1-12����
	DWORD dwWeekNo;		//�ڼ��� 0����1�� 1����2�� 2����3�� 3����4�� 4�����һ��
	DWORD dwWeekDate;	//���ڼ� 0�������� 1������һ 2�����ڶ� 3�������� 4�������� 5�������� 6��������
	DWORD dwHour;		//Сʱ	��ʼʱ��0��23 ����ʱ��1��23
	DWORD dwMin;		//��	0��59
}NET_DVR_TIMEPOINT;

//����ʱ����
typedef struct 
{
	DWORD dwSize;
	BYTE byRes1[16];			//����
	DWORD dwEnableDST;		//�Ƿ�������ʱ�� 0�������� 1������
	BYTE byDSTBias;	//����ʱƫ��ֵ��30min, 60min, 90min, 120min, �Է��Ӽƣ�����ԭʼ��ֵ
	BYTE byRes2[3];
	NET_DVR_TIMEPOINT struBeginPoint;	//��ʱ�ƿ�ʼʱ��
	NET_DVR_TIMEPOINT struEndPoint;	//��ʱ��ֹͣʱ��
}NET_DVR_ZONEANDDST, *LPNET_DVR_ZONEANDDST;

//ͼƬ����
typedef struct 
{
	/*ע�⣺��ͼ��ѹ���ֱ���ΪVGAʱ��֧��0=CIF, 1=QCIF, 2=D1ץͼ��
	���ֱ���Ϊ3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA,7=XVGA, 8=HD900p
	��֧�ֵ�ǰ�ֱ��ʵ�ץͼ*/
	WORD	wPicSize;				/* 0=CIF, 1=QCIF, 2=D1 3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA*/
	WORD	wPicQuality;			/* ͼƬ����ϵ�� 0-��� 1-�Ϻ� 2-һ�� */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

/* aux video out parameter */
//���������������
typedef struct 
{
	DWORD dwSize;
	DWORD dwAlarmOutChan;                       /* ѡ�񱨾������󱨾�ͨ���л�ʱ�䣺1��������ͨ��: 0:�����/1:��1/2:��2/3:��3/4:��4 */
	DWORD dwAlarmChanSwitchTime;                /* :1�� - 10:10�� */
	DWORD dwAuxSwitchTime[MAX_AUXOUT];			/* ��������л�ʱ��: 0-���л�,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s */
	BYTE  byAuxOrder[MAX_AUXOUT][MAX_WINDOW];	/* �������Ԥ��˳��, 0xff��ʾ��Ӧ�Ĵ��ڲ�Ԥ�� */
}NET_DVR_AUXOUTCFG, *LPNET_DVR_AUXOUTCFG;


//ntp
typedef struct 
{
	BYTE sNTPServer[64];   /* Domain Name or IP addr of NTP server */
	WORD wInterval;		 /* adjust time interval(hours) */
	BYTE byEnableNTP;    /* enable NPT client 0-no��1-yes*/
	signed char cTimeDifferenceH; /* ����ʱ�׼ʱ��� Сʱƫ��-12 ... +13 */
	signed char cTimeDifferenceM;/* ����ʱ�׼ʱ��� ����ƫ��0, 30, 45*/
	BYTE res1;
    WORD wNtpPort;         /* ntp server port 9000���� �豸Ĭ��Ϊ123*/
    BYTE res2[8];
}NET_DVR_NTPPARA, *LPNET_DVR_NTPPARA;

//ddns
typedef struct 
{
	BYTE sUsername[NAME_LEN];  /* DDNS�˺��û���/���� */
	BYTE sPassword[PASSWD_LEN];
	BYTE sDomainName[64];       /* ���� */
	BYTE byEnableDDNS;			/*�Ƿ�Ӧ�� 0-��1-��*/
	BYTE res[15];
}NET_DVR_DDNSPARA, *LPNET_DVR_DDNSPARA;


typedef struct
{
	BYTE byHostIndex;					/* 0-˽��DDNS 1��Dyndns 2��PeanutHull(������)*/
	BYTE byEnableDDNS;					/*�Ƿ�Ӧ��DDNS 0-��1-��*/
	WORD wDDNSPort;						/* DDNS�˿ں� */
	BYTE sUsername[NAME_LEN];			/* DDNS�û���*/
	BYTE sPassword[PASSWD_LEN];			/* DDNS���� */
	BYTE sDomainName[MAX_DOMAIN_NAME];	/* �豸�䱸��������ַ */
	BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNS ��Ӧ�ķ�������ַ��������IP��ַ������ */
	BYTE byRes[16];
}NET_DVR_DDNSPARA_EX, *LPNET_DVR_DDNSPARA_EX;

//9000��չ
typedef struct
{
    BYTE byEnableDDNS;
    BYTE byHostIndex;/* 0-˽��DDNS 1��Dyndns 2��PeanutHull(������) 3- NO-IP*/
    BYTE byRes1[2];
    struct
    {    
        BYTE sUsername[NAME_LEN];			/* DDNS�˺��û���*/
        BYTE sPassword[PASSWD_LEN];			/* ���� */
        BYTE sDomainName[MAX_DOMAIN_NAME];	/* �豸�䱸��������ַ */
        BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNSЭ���Ӧ�ķ�������ַ��������IP��ַ������ */
        WORD wDDNSPort;						/* �˿ں� */
        BYTE byRes[10];
    } struDDNS[MAX_DDNS_NUMS];
    BYTE byRes2[16];
}NET_DVR_DDNSPARA_V30, *LPNET_DVR_DDNSPARA_V30;

//email
typedef struct 
{
	BYTE sUsername[64];  /* �ʼ��˺�/���� */
	BYTE sPassword[64];
	BYTE sSmtpServer[64];
	BYTE sPop3Server[64];
	BYTE sMailAddr[64];   /* email */
	BYTE sEventMailAddr1[64];  /* �ϴ�����/�쳣�ȵ�email */
	BYTE sEventMailAddr2[64];
	BYTE res[16];
}NET_DVR_EMAILPARA, *LPNET_DVR_EMAILPARA;

//�����������
typedef struct 
{
	DWORD  dwSize;
	char  sDNSIp[16];                /* DNS��������ַ */
	NET_DVR_NTPPARA  struNtpClientParam;      /* NTP���� */
	NET_DVR_DDNSPARA struDDNSClientParam;     /* DDNS���� */
	BYTE res[464];			/* ���� */
}NET_DVR_NETAPPCFG, *LPNET_DVR_NETAPPCFG;

//nfs�ṹ����
typedef struct
{
    char sNfsHostIPAddr[16];
    BYTE sNfsDirectory[PATHNAME_LEN];        // PATHNAME_LEN = 128
}NET_DVR_SINGLE_NFS, *LPNET_DVR_SINGLE_NFS;

typedef struct 
{
	DWORD  dwSize;
	NET_DVR_SINGLE_NFS struNfsDiskParam[MAX_NFS_DISK];
}NET_DVR_NFSCFG, *LPNET_DVR_NFSCFG;

typedef struct tagNET_DVR_ISCSI_CFG
{   
    DWORD dwSize;                   // �ṹ��С
    WORD wVrmPort;                  // VRM �����˿�
    BYTE byEnable;                  // �Ƿ����� ISCSI�洢
    BYTE byRes[69];                 // �����ֽ�
    NET_DVR_IPADDR struVrmAddr;          // VRM ip��ַ 16λ
    char chNvtIndexCode[64];        //nvt index Code 
}NET_DVR_ISCSI_CFG, *LPNET_DVR_ISCSI_CFG;  

//Ѳ��������(˽��IP����ר��)
typedef struct
{
    BYTE	PresetNum;	//Ԥ�õ�
    BYTE	Dwell;		//ͣ��ʱ��
    BYTE	Speed;		//�ٶ�
    BYTE	Reserve;	//����
}NET_DVR_CRUISE_POINT, *LPNET_DVR_CRUISE_POINT;

typedef struct 
{
	NET_DVR_CRUISE_POINT struCruisePoint[32];			//���֧��32��Ѳ����
}NET_DVR_CRUISE_RET, *LPNET_DVR_CRUISE_RET;

/************************************��·������(begin)***************************************/
typedef struct 
{
	DWORD	dwSize;
	char	sFirstDNSIP[16];
	char	sSecondDNSIP[16];
	char	sRes[32];
}NET_DVR_NETCFG_OTHER, *LPNET_DVR_NETCFG_OTHER;

typedef struct 
{
	char 	sDVRIP[16];				/* DVR IP��ַ */
	WORD 	wDVRPort;			 	/* �˿ں� */
	BYTE 	byChannel;				/* ͨ���� */
	BYTE	byTransProtocol;			/* ����Э������ 0-TCP, 1-UDP */
	BYTE	byTransMode;				/* ��������ģʽ 0�������� 1��������*/
	BYTE	byRes[3];
	BYTE	sUserName[NAME_LEN];			/* ���������½�ʺ� */
	BYTE	sPassword[PASSWD_LEN];			/* ����������� */
}NET_DVR_MATRIX_DECINFO, *LPNET_DVR_MATRIX_DECINFO;

//����/ֹͣ��̬����
typedef struct 
{
	DWORD	dwSize;				
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* ��̬����ͨ����Ϣ */
}NET_DVR_MATRIX_DYNAMIC_DEC, *LPNET_DVR_MATRIX_DYNAMIC_DEC;

typedef struct  
{
    DWORD 	dwSize;
    DWORD   dwIsLinked;         /* ����ͨ��״̬ 0������ 1���������� 2�������� 3-���ڽ��� */
    DWORD   dwStreamCpRate;     /* Stream copy rate, X kbits/second */
    char    cRes[64];		/* ���� */
}NET_DVR_MATRIX_DEC_CHAN_STATUS, *LPNET_DVR_MATRIX_DEC_CHAN_STATUS;

typedef struct 
{
	DWORD	dwSize;
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* ����ͨ����Ϣ */
	DWORD	dwDecState;	/* 0-��̬���� 1��ѭ������ 2����ʱ��ط� 3�����ļ��ط� */
	NET_DVR_TIME StartTime;		/* ��ʱ��طſ�ʼʱ�� */
	NET_DVR_TIME StopTime;		/* ��ʱ��ط�ֹͣʱ�� */
	char    sFileName[128];		/* ���ļ��ط��ļ��� */
}NET_DVR_MATRIX_DEC_CHAN_INFO, *LPNET_DVR_MATRIX_DEC_CHAN_INFO;

//���ӵ�ͨ������ 2007-11-05
typedef struct 
{
	DWORD dwEnable;					/* �Ƿ����� 0���� 1������*/
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* ��Ѳ����ͨ����Ϣ */
}NET_DVR_MATRIX_DECCHANINFO, *LPNET_DVR_MATRIX_DECCHANINFO;

//2007-11-05 ����ÿ������ͨ��������
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPoolTime;			/*��Ѳʱ�� */
	NET_DVR_MATRIX_DECCHANINFO struchanConInfo[MAX_CYCLE_CHAN];
}NET_DVR_MATRIX_LOOP_DECINFO, *LPNET_DVR_MATRIX_LOOP_DECINFO;

//2007-12-22
typedef struct 
{
	BYTE	baudrate; 	/* ������ */
	BYTE	databits;		/* ����λ */
	BYTE	stopbits;		/* ֹͣλ */
	BYTE	parity;		/* ��żУ��λ */
	BYTE	flowcontrol;	/* ���� */
	BYTE	res[3];
}TTY_CONFIG, *LPTTY_CONFIG;

typedef struct  
{					
	BYTE byTranChanEnable;	/* ��ǰ͸��ͨ���Ƿ�� 0���ر� 1���� */	
	/*
	 *	��·������������1��485���ڣ�1��232���ڶ�������Ϊ͸��ͨ��,�豸�ŷ������£�
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
	/*
	 *	Զ�̴��������������,һ��RS232��һ��RS485
	 *	1��ʾ232����
	 *	2��ʾ485����
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	res1;							/* ���� */
	char	sRemoteDevIP[16];				/* Remote Device IP */
	WORD	wRemoteDevPort;				/* Remote Net Communication Port */
	BYTE	res2[2];						/* ���� */
	TTY_CONFIG RemoteSerialDevCfg;
}NET_DVR_MATRIX_TRAN_CHAN_INFO, *LPNET_DVR_MATRIX_TRAN_CHAN_INFO;

typedef struct  
{
	DWORD dwSize;
	BYTE 	by232IsDualChan; /* ������·232͸��ͨ����ȫ˫���� ȡֵ1��MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* ������·485͸��ͨ����ȫ˫���� ȡֵ1��MAX_SERIAL_NUM */
	BYTE	res[2];	/* ���� */
	NET_DVR_MATRIX_TRAN_CHAN_INFO struTranInfo[MAX_SERIAL_NUM];/*ͬʱ֧�ֽ���MAX_SERIAL_NUM��͸��ͨ��*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG, *LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG;

//2007-12-24 Merry Christmas Eve...
typedef struct 
{
	DWORD	dwSize;
	char	sDVRIP[16];		/* DVR IP��ַ */	
	WORD	wDVRPort;			/* �˿ں� */	
	BYTE	byChannel;			/* ͨ���� */
	BYTE 	byReserve;
	BYTE	sUserName[NAME_LEN];		/* �û��� */
	BYTE	sPassword[PASSWD_LEN];		/* ���� */
	DWORD	dwPlayMode;   	/* 0�����ļ� 1����ʱ��*/        	
	NET_DVR_TIME StartTime;
	NET_DVR_TIME StopTime;
	char    sFileName[128];
}NET_DVR_MATRIX_DEC_REMOTE_PLAY, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY;

/* �ļ��������� */
#define NET_DVR_PLAYSTART		1//��ʼ����
#define NET_DVR_PLAYSTOP		2//ֹͣ����
#define NET_DVR_PLAYPAUSE		3//��ͣ����
#define NET_DVR_PLAYRESTART		4//�ָ�����
#define NET_DVR_PLAYFAST		5//���
#define NET_DVR_PLAYSLOW		6//����
#define NET_DVR_PLAYNORMAL		7//�����ٶ�
#define NET_DVR_PLAYSTARTAUDIO	9//������
#define NET_DVR_PLAYSTOPAUDIO	10//�ر�����
#define NET_DVR_PLAYSETPOS		12//�ı��ļ��طŵĽ���

typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPlayCmd;		/* �������� ���ļ���������*/
	DWORD	dwCmdParam;		/* ����������� */
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL;

typedef struct  
{
	DWORD dwSize;
	DWORD dwCurMediaFileLen;		/* ��ǰ���ŵ�ý���ļ����� */       
	DWORD dwCurMediaFilePosition;	/* ��ǰ�����ļ��Ĳ���λ�� */        
	DWORD dwCurMediaFileDuration;	/* ��ǰ�����ļ�����ʱ�� */        
	DWORD dwCurPlayTime;			/* ��ǰ�Ѿ����ŵ�ʱ�� */        
	DWORD dwCurMediaFIleFrames;		/* ��ǰ�����ļ�����֡�� */        
	DWORD dwCurDataType;			/* ��ǰ������������ͣ�19-�ļ�ͷ��20-�����ݣ� 21-���Ž�����־ */        
	BYTE res[72];	
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS;

//2009-4-11 added by likui ��·������new
typedef struct tagNET_MATRIX_PASSIVEMODE
{
    WORD	wTransProtol;		//����Э�飬0-TCP, 1-UDP, 2-MCAST
    WORD	wPassivePort;		//UDP�˿�, TCPʱĬ��
    NET_DVR_IPADDR  struMcastIP;	//TCP,UDPʱ��Ч, MCASTʱΪ�ಥ��ַ
    BYTE	byStreamType;/* ���ݲ���ģʽ:REAL_TIME_STREAM(1)ʵʱ��,RECORD_STREAM(2)�ļ��� */
    BYTE	byRes[7];
}NET_DVR_MATRIX_PASSIVEMODE, *LPNET_DVR_MATRIX_PASSIVEMODE;

typedef struct tagMATRIX_TRAN_CHAN_INFO 
{					
	BYTE byTranChanEnable;	/* ��ǰ͸��ͨ���Ƿ�� 0���ر� 1���� */	
/*
	 *	��·������������1��485���ڣ�1��232���ڶ�������Ϊ͸��ͨ��,�豸�ŷ������£�
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
/*
	 *	Զ�̴��������������,һ��RS232��һ��RS485
	 *	1��ʾ232����
	 *	2��ʾ485����
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	byRes1;							/* ���� */		
    NET_DVR_IPADDR  struRemoteDevIP;/* Remote Device IP */
	WORD    wRemoteDevPort;				/* Remote Net Communication Port */
    BYTE    byIsEstablished;			/* ͸��ͨ�������ɹ���־��0-û�гɹ���1-�����ɹ� */
    BYTE	byRes2;						/* ���� */
	TTY_CONFIG RemoteSerialDevCfg;
	BYTE  	byUsername[NAME_LEN]; 		/* 32BYTES */
	BYTE   	byPassword[PASSWD_LEN]; 		/* 16BYTES */
	BYTE 	byRes3[16];
} NET_DVR_MATRIX_TRAN_CHAN_INFO_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_INFO_V30;

typedef struct tagMATRIX_TRAN_CHAN_CONFIG 
{
	DWORD   dwSize;
	BYTE 	by232IsDualChan; /* ������·232͸��ͨ����ȫ˫���� ȡֵ1��MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* ������·485͸��ͨ����ȫ˫���� ȡֵ1��MAX_SERIAL_NUM */
	BYTE	vyRes[2];	/* ���� */
	NET_DVR_MATRIX_TRAN_CHAN_INFO_V30 struTranInfo[MAX_SERIAL_NUM];/*ͬʱ֧�ֽ���MAX_SERIAL_NUM��͸��ͨ��*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30;

typedef struct  
{
    DWORD								dwEnable;	/* �Ƿ����� 0���� 1������*/
    NET_DVR_STREAM_MEDIA_SERVER_CFG	streamMediaServerCfg;	
    NET_DVR_DEV_CHAN_INFO 		struDevChanInfo;		/* ��Ѳ����ͨ����Ϣ */
}NET_DVR_MATRIX_CHAN_INFO_V30,*LPNET_DVR_CYC_SUR_CHAN_ELE_V30;

typedef struct  tagMATRIX_LOOP_DECINFO_V30
{
    DWORD							dwSize;
    DWORD							dwPoolTime;		/*��Ѳ���*/
    NET_DVR_MATRIX_CHAN_INFO_V30	struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
} NET_DVR_MATRIX_LOOP_DECINFO_V30,*LPNET_DVR_MATRIX_LOOP_DECINFO_V30;


typedef struct tagDEC_MATRIX_CHAN_INFO_V30
{
    DWORD	dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg;	/*��ý�����������*/
    NET_DVR_DEV_CHAN_INFO 			  struDevChanInfo;		/* ����ͨ����Ϣ */
    DWORD	dwDecState;		/* 0-��̬���� 1��ѭ������ 2����ʱ��ط� 3�����ļ��ط� */
    NET_DVR_TIME StartTime;		/* ��ʱ��طſ�ʼʱ�� */
    NET_DVR_TIME StopTime;		/* ��ʱ��ط�ֹͣʱ�� */
    char    sFileName[128];		/* ���ļ��ط��ļ��� */
    DWORD   dwGetStreamMode;	/*ȡ��ģʽ:1-������2-����*/
    NET_DVR_MATRIX_PASSIVEMODE      struPassiveMode;
    BYTE	byRes[32];
}NET_DVR_MATRIX_DEC_CHAN_INFO_V30,*LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30;

#define MAX_RESOLUTIONNUM    64 //֧�ֵ����ֱ�����Ŀ
typedef struct tagNET_DVR_MATRIX_ABILITY
{
    DWORD dwSize;
    BYTE  byDecNums;
    BYTE  byStartChan;
    BYTE  byVGANums;
    BYTE  byBNCNums;
    BYTE  byVGAWindowMode[8][12];     /*VGA֧�ֵĴ���ģʽ��VGA1�����ɻ�����*/
    BYTE  byBNCWindowMode[4];       	/*BNC֧�ֵĴ���ģʽ*/
    BYTE  byDspNums;   
    BYTE  byHDMINums;//HDMI��ʾͨ����������25��ʼ��
    BYTE  byDVINums;//DVI��ʾͨ����������29��ʼ��
	BYTE  byRes1[13];
	BYTE  bySupportResolution[MAX_RESOLUTIONNUM];//���������ö�ٶ���,һ���ֽڴ���һ���ֱ�����//��֧�֣�1��֧�֣�0����֧��
	BYTE  byHDMIWindowMode[4][8];//HDMI֧�ֵĴ���ģʽ
	BYTE  byDVIWindowMode[4][8];//DVI֧�ֵĴ���ģʽ
	BYTE  byRes2[24];
}NET_DVR_MATRIX_ABILITY, *LPNET_DVR_MATRIX_ABILITY;
//�ϴ�logo�ṹ
typedef struct tagNET_DVR_DISP_LOGOCFG
{
    DWORD		dwCorordinateX;	//ͼƬ��ʾ����X����
    DWORD		dwCorordinateY;	//ͼƬ��ʾ����Y����
    BYTE        byRes1[8];
    BYTE        byFlash;  //�Ƿ���˸1-��˸��0-����˸
    BYTE        byTranslucent; //�Ƿ��͸��1-��͸����0-����͸��
    BYTE		byRes2[6];				//����
    DWORD		dwLogoSize;//LOGO��С������BMP���ļ�ͷ
}NET_DVR_DISP_LOGOCFG,*LPNET_DVR_DISP_LOGOCFG;

/*��������*/
#define NET_DVR_ENCODER_UNKOWN 0 /*δ֪�����ʽ*/
#define NET_DVR_ENCODER_H264   1 /*˽�� 264*/
#define NET_DVR_ENCODER_S264  2 /*Standard H264*/
#define NET_DVR_ENCODER_MPEG4  3 /*MPEG4*/
#define NET_DVR_ORIGINALSTREAM    4 /*Original Stream*/
#define NET_DVR_PICTURE			  5/*Picture*/

/* �����ʽ */
#define NET_DVR_STREAM_TYPE_UNKOWN   0     /*δ֪�����ʽ*/
#define NET_DVR_STREAM_TYPE_PRIVT   1     /*˽�и�ʽ*/
#define NET_DVR_STREAM_TYPE_TS    7   /* TS��� */
#define NET_DVR_STREAM_TYPE_PS   8   /* PS��� */
#define NET_DVR_STREAM_TYPE_RTP  9    /* RTP��� */
#define NET_DVR_STREAM_TYPE_ORIGIN    10 //δ���(��Ƶ�ۺ�ƽ̨������ϵͳ��)

/*����ͨ��״̬*/
typedef struct
{
    BYTE  byDecodeStatus; /*��ǰ״̬:0:δ������1����������*/
    BYTE  byStreamType;    /*��������*/
    BYTE  byPacketType;     /*�����ʽ*/
    BYTE  byRecvBufUsage; /*���ջ���ʹ����*/
    BYTE  byDecBufUsage; /*���뻺��ʹ����*/
    BYTE  byFpsDecV; /*��Ƶ����֡��*/
    BYTE  byFpsDecA; /*��Ƶ����֡��*/
    BYTE  byCpuLoad;     /*DSP CPUʹ����*/ 
    BYTE  byRes1[4];    
    DWORD dwDecodedV; /*�������Ƶ֡*/
    DWORD dwDecodedA; /*�������Ƶ֡*/
    WORD wImgW; /*��������ǰ��ͼ���С,��*/
    WORD wImgH; //��
    BYTE byVideoFormat; /*��Ƶ��ʽ:0-NON,NTSC--1,PAL--2*/
    BYTE byRes2[27];
}NET_DVR_MATRIX_CHAN_STATUS, *LPNET_DVR_MATRIX_CHAN_STATUS;

/*��ʾͨ��״̬*/
#define NET_DVR_MAX_DISPREGION 16         /*ÿ����ʾͨ����������ʾ�Ĵ���*/
//�ֱ���
//
typedef enum
{
	/*VGA*/
    VGA_NOT_AVALIABLE,
    VGA_THS8200_MODE_SVGA_60HZ,    //(800*600)
    VGA_THS8200_MODE_SVGA_75HZ,    //(800*600)
    VGA_THS8200_MODE_XGA_60HZ,     //(1024*768)
    VGA_THS8200_MODE_XGA_70HZ,     //(1024*768)
    VGA_THS8200_MODE_SXGA_60HZ,    //(1280*1024)
    VGA_THS8200_MODE_720P_60HZ,    //(1280*720)
    VGA_THS8200_MODE_1080I_60HZ,   //(1920*1080)
    VGA_THS8200_MODE_1080P_30HZ,   //(1920*1080)
    VGA_THS8200_MODE_UXGA_30HZ,    //(1600*1200)
	/*HDMI*/	
	HDMI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	HDMI_SII9134_MODE_SXGA_60HZ,   //(1280*1024)
	HDMI_SII9134_MODE_SXGA2_60HZ,  //(1280*960)
	HDMI_SII9134_MODE_720P_60HZ,   //(1280*720)	
	HDMI_SII9134_MODE_720P_50HZ,   //(1280*720)		
	HDMI_SII9134_MODE_1080I_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080I_50HZ,  //(1920*1080)	
	HDMI_SII9134_MODE_1080P_25HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_30HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_50HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_UXGA_60HZ,   //(1600*1200)
	/*DVI*/	
	DVI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	DVI_SII9134_MODE_SXGA_60HZ,	   //(1280*1024)
	DVI_SII9134_MODE_SXGA2_60HZ,   //(1280*960)
	DVI_SII9134_MODE_720P_60HZ,	   //(1280*720)	
	DVI_SII9134_MODE_720P_50HZ,    //(1280*720)		
	DVI_SII9134_MODE_1080I_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080I_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_25HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_30HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_UXGA_60HZ     //(1600*1200)
}VGA_MODE;

//��֡�ʶ���
#define           LOW_DEC_FPS_1_2                51
#define           LOW_DEC_FPS_1_4                52
#define           LOW_DEC_FPS_1_8                53
#define           LOW_DEC_FPS_1_16               54

/*��Ƶ��ʽ��׼*/
typedef enum
{
    VS_NON = 0,
    VS_NTSC = 1,
    VS_PAL = 2
}VIDEO_STANDARD;

typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG
{        
    DWORD	dwSize; 
    BYTE	byAudio;			/*��Ƶ�Ƿ���,0-��1-��*/
    BYTE    byAudioWindowIdx;      /*��Ƶ�����Ӵ���*/
    BYTE 	byVgaResolution;      /*VGA�ķֱ���*/
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL,0-NULL*/
    DWORD	dwWindowMode;		/*����ģʽ,����������ȡ,Ŀǰ֧��1,2,4,9,16*/       
    BYTE	byJoinDecChan[MAX_WINDOWS];/*�����Ӵ��ڹ����Ľ���ͨ��*/
    BYTE	byEnlargeStatus;          /*�Ƿ��ڷŴ�״̬��0�����Ŵ�1���Ŵ�*/
    BYTE    byEnlargeSubWindowIndex;//�Ŵ���Ӵ��ں�
	union
	{
		BYTE byRes[16];
		struct
		{
			/*�����Ӵ��ڶ�Ӧ����ͨ������Ӧ�Ľ�����ϵͳ�Ĳ�λ��(������Ƶ�ۺ�ƽ̨�н�����ϵͳ��Ч)*/
			BYTE	 byJoinDecoderId[MAX_WINDOWS];
		}struVideoPlatform;
		struct
		{
			BYTE	 byRes[16];
		}struNotVideoPlatform;
	}struDiff;
	/*���ֹ����壬0-��Ƶ�ۺ�ƽ̨�ڲ���������ʾͨ�����ã�1-������������ʾͨ������*/
	BYTE		byUnionType;
	BYTE		byScale; /*��ʾģʽ��0---��ʵ��ʾ��1---������ʾ( ���BNC )*/
}NET_DVR_VGA_DISP_CHAN_CFG,*LPNET_DVR_VGA_DISP_CHAN_CFG;


/*��ʾͨ��״̬*/
#define NET_DVR_MAX_DISPREGION 16 /*ÿ����ʾͨ����������ʾ�Ĵ���*/
typedef struct
{
    BYTE  byDispStatus;          /*��ʾ״̬��0��δ��ʾ��1��������ʾ*/
    BYTE  byBVGA;                /*0-BNC��1-VGA�� 2-HDMI��3-DVI*/
    BYTE  byVideoFormat;        /*��Ƶ��ʽ:1:NTSC,2:PAL,0-NON*/
    BYTE  byWindowMode;        /*��ǰ����ģʽ*/
    BYTE  byJoinDecChan[MAX_WINDOWS];        /*�����Ӵ��ڹ����Ľ���ͨ��*/
    BYTE  byFpsDisp[NET_DVR_MAX_DISPREGION]; /*ÿ���ӻ������ʾ֡��*/
    BYTE  byRes2[32];
}NET_DVR_DISP_CHAN_STATUS, *LPNET_DVR_DISP_CHAN_STATUS;

#define MAX_DECODECHANNUM   32//��·������������ͨ����
#define MAX_DISPCHANNUM   24//��·�����������ʾͨ����

/*�������豸״̬*/
typedef struct tagNET_DVR_DECODER_WORK_STATUS
{
    DWORD dwSize;
    NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[MAX_DECODECHANNUM]; /*����ͨ��״̬*/
    NET_DVR_DISP_CHAN_STATUS   struDispChanStatus[MAX_DISPCHANNUM];  /*��ʾͨ��״̬*/
    BYTE byAlarmInStatus[MAX_ANALOG_ALARMIN];         /*��������״̬*/
    BYTE byAalarmOutStatus[MAX_ANALOG_ALARMOUT];       /*�������״̬*/
    BYTE byAudioInChanStatus;          /*�����Խ�״̬*/
    BYTE byRes[127];
}NET_DVR_DECODER_WORK_STATUS,*LPNET_DVR_DECODER_WORK_STATUS;

//2009-12-1 ���ӱ������벥�ſ���
typedef struct tagNET_DVR_PASSIVEDECODE_CONTROL
{
    DWORD	dwSize;
    DWORD	dwPlayCmd;		/* �������� ���ļ���������*/
    DWORD	dwCmdParam;		/* ����������� */
    BYTE	byRes[16];//Reverse
}NET_DVR_PASSIVEDECODE_CONTROL,*LPNET_DVR_PASSIVEDECODE_CONTROL;

#define		PASSIVE_DEC_PAUSE			1	/*����������ͣ(���ļ�����Ч)*/
#define		PASSIVE_DEC_RESUME			2	/*�ָ���������(���ļ�����Ч)*/
#define 	PASSIVE_DEC_FAST          	3   /*���ٱ�������(���ļ�����Ч)*/
#define 	PASSIVE_DEC_SLOW			4   /*���ٱ�������(���ļ�����Ч)*/
#define 	PASSIVE_DEC_NORMAL      	5   /*������������(���ļ�����Ч)*/
#define 	PASSIVE_DEC_ONEBYONE      	6  /*�������뵥֡����(����)*/
#define 	PASSIVE_DEC_AUDIO_ON 		7   /*��Ƶ����*/
#define 	PASSIVE_DEC_AUDIO_OFF		8  	 /*��Ƶ�ر�*/
#define		PASSIVE_DEC_RESETBUFFER	    9    /*��ջ�����(���ļ�����Ч)*/
//2009-12-16 ���ӿ��ƽ���������ͨ������
typedef struct tagNET_DVR_MATRIX_DECCHAN_CONTROL
{        
	DWORD	dwSize;
	BYTE	byDecChanScaleStatus;/*����ͨ����ʾ���ſ���,1��ʾ������ʾ��0��ʾ��ʵ��ʾ*/
	BYTE	byRes[67];//Reverse
}NET_DVR_MATRIX_DECCHAN_CONTROL,*LPNET_DVR_MATRIX_DECCHAN_CONTROL;

/************************************��·������(end)***************************************/
//2009-8-19 ��Ƶ�ۺ�ƽ̨�ӿں���
/************************************��Ƶ�ۺ�ƽ̨(begin)***************************************/
#define MAX_SUBSYSTEM_NUM	80   //һ������ϵͳ�������ϵͳ����
#define MAX_SERIALLEN		36  //������кų���
#define MAX_LOOPPLANNUM		16//���ƻ��л���
#define DECODE_TIMESEGMENT 4//�ƻ�����ÿ��ʱ�����
typedef struct tagNET_DVR_SUBSYSTEMINFO
{
    BYTE		bySubSystemType;//��ϵͳ���ͣ�1-��������ϵͳ��2-��������ϵͳ��3-���������ϵͳ��4-����������ϵͳ��5-�������ϵͳ��6-����������ϵͳ��7-������ϵͳ��0-NULL���˲���ֻ�ܻ�ȡ��		
    BYTE		byChan;//��ϵͳͨ���������������ϵͳ������485�����������˲���ֻ�ܻ�ȡ��					
    BYTE		byLoginType;//ע�����ͣ�1-ֱ����2-DNS��3-������
    BYTE		byRes1[5];
    NET_DVR_IPADDR   struSubSystemIP;		/*IP��ַ�����޸ģ�*/
    WORD		wSubSystemPort;        //��ϵͳ�˿ںţ����޸ģ�
    BYTE		byRes2[6];
    NET_DVR_IPADDR  struSubSystemIPMask;//��������
    NET_DVR_IPADDR	struGatewayIpAddr;	/* ���ص�ַ*/   
    BYTE		sUserName[NAME_LEN];	/* �û��� ���˲���ֻ�ܻ�ȡ��*/
    BYTE		sPassword[PASSWD_LEN];	/*���루�˲���ֻ�ܻ�ȡ��*/
    char		sDomainName[MAX_DOMAIN_NAME];//����(���޸�)
    char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS������IP��ַ*/
    BYTE		sSerialNumber[SERIALNO_LEN];//���кţ��˲���ֻ�ܻ�ȡ��
}NET_DVR_SUBSYSTEMINFO, *LPNET_DVR_SUBSYSTEMINFO;

typedef struct tagNET_DVR_ALLSUBSYSTEMINFO
{
    DWORD dwSize;
    NET_DVR_SUBSYSTEMINFO struSubSystemInfo[MAX_SUBSYSTEM_NUM];
    BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO, *LPNET_DVR_ALLSUBSYSTEMINFO;

typedef struct  tagNET_DVR_LOOPPLAN_SUBCFG
{
    DWORD 						    dwSize;
    DWORD							dwPoolTime;		/*��Ѳ�������λ����*/      
    NET_DVR_MATRIX_CHAN_INFO_V30 struChanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
}NET_DVR_LOOPPLAN_SUBCFG,*LPNET_DVR_LOOPPLAN_SUBCFG;

typedef struct tagNET_DVR_ALARMMODECFG
{
    DWORD 	dwSize;
    BYTE	byAlarmMode;//�����������ͣ�1-��Ѳ��2-����		
    WORD	wLoopTime;//��Ѳʱ��, ��λ����			
    BYTE    byRes[9];
}NET_DVR_ALARMMODECFG,*LPNET_DVR_ALARMMODECFG;

typedef struct  tagNET_DVR_CODESPLITTERINFO
{
    DWORD			dwSize;
    NET_DVR_IPADDR   struIP;		/*�����IP��ַ*/
    WORD		wPort;        			//������˿ں�
    BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* �û��� */
    BYTE		sPassword[PASSWD_LEN];	/*���� */
    BYTE        byChan;//�����485��
    BYTE		by485Port;//485�ڵ�ַ
    BYTE		byRes2[14];
} NET_DVR_CODESPLITTERINFO, *LPNET_DVR_CODESPLITTERINFO;

typedef struct tagNET_DVR_ASSOCIATECFG
{
    BYTE	byAssociateType;//�������ͣ�1-����
    WORD	wAlarmDelay;//������ʱ��0��5�룻1��10�룻2��30�룻3��1���ӣ�4��2���ӣ�5��5���ӣ�6��10���ӣ�
    BYTE	byAlarmNum;//�����ţ������ֵ��Ӧ�ø�����ͬ�ı�������ͬ��ֵ
    BYTE	byRes[8];
} NET_DVR_ASSOCIATECFG,*LPNET_DVR_ASSOCIATECFG;

typedef struct tagNET_DVR_DYNAMICDECODE
{
    DWORD						    dwSize;
    NET_DVR_ASSOCIATECFG   		struAssociateCfg;//������̬��������ṹ
    NET_DVR_PU_STREAM_CFG		struPuStreamCfg;//��̬����ṹ
    BYTE							byRes[8];
}NET_DVR_DYNAMICDECODE,*LPNET_DVR_DYNAMICDECODE;

typedef struct  tagNET_DVR_DECODESCHED
{
	NET_DVR_SCHEDTIME  struSchedTime;//
    BYTE  byDecodeType;/*0-�ޣ�1-��Ѳ���룬2-��̬����*/
	BYTE  byLoopGroup;//��Ѳ���
	BYTE  byRes[6];
	NET_DVR_PU_STREAM_CFG struDynamicDec;//��̬����
} NET_DVR_DECODESCHED, *LPNET_DVR_DECODESCHED;

typedef struct tagNET_DVR_PLANDECODE
{
	DWORD dwSize;
	NET_DVR_DECODESCHED struDecodeSched[MAX_DAYS][DECODE_TIMESEGMENT];//��һ��Ϊ��ʼ����9000һ��
	BYTE byRes[8];
} NET_DVR_PLANDECODE,*LPNET_DVR_PLANDECODE;

//end
/************************************��Ƶ�ۺ�ƽ̨(end)***************************************/
typedef struct 
{	/* 12 bytes */
	DWORD	dwSize;
	char	sUserName[32];
	char 	sPassWord[32];
	char 	sFromName[32];			/* Sender *///�ַ����еĵ�һ���ַ������һ���ַ�������"@",�����ַ�����Ҫ��"@"�ַ�
	char 	sFromAddr[48];			/* Sender address */
	char 	sToName1[32];			/* Receiver1 */
	char 	sToName2[32];			/* Receiver2 */
	char 	sToAddr1[48];			/* Receiver address1 */
	char 	sToAddr2[48];			/* Receiver address2 */
	char	sEmailServer[32];		/* Email server address */
	BYTE	byServerType;			/* Email server type: 0-SMTP, 1-POP, 2-IMTP��*/
	BYTE	byUseAuthen;			/* Email server authentication method: 1-enable, 0-disable */
	BYTE	byAttachment;			/* enable attachment */
	BYTE	byMailinterval;			/* mail interval 0-2s, 1-3s, 2-4s. 3-5s*/
} NET_DVR_EMAILCFG, *LPNET_DVR_EMAILCFG;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX  struLowCompression;	//��ʱ¼��
	NET_DVR_COMPRESSION_INFO_EX  struEventCompression;	//�¼�����¼��
}NET_DVR_COMPRESSIONCFG_NEW, *LPNET_DVR_COMPRESSIONCFG_NEW;

//���λ����Ϣ
typedef struct
{
    WORD wAction;//��ȡʱ���ֶ���Ч
    WORD wPanPos;//ˮƽ����
    WORD wTiltPos;//��ֱ����
    WORD wZoomPos;//�䱶����
}NET_DVR_PTZPOS, *LPNET_DVR_PTZPOS;

//�����Χ��Ϣ
typedef struct
{
    WORD wPanPosMin;//ˮƽ����min
    WORD wPanPosMax;//ˮƽ����max
    WORD wTiltPosMin;//��ֱ����min
    WORD wTiltPosMax;//��ֱ����max
    WORD wZoomPosMin;//�䱶����min
    WORD wZoomPosMax;//�䱶����max
}NET_DVR_PTZSCOPE, *LPNET_DVR_PTZSCOPE;

//rtsp���� ipcameraר��
typedef struct
{
    DWORD dwSize;         //����
    WORD  wPort;          //rtsp�����������˿�
    BYTE  byReserve[54];  //Ԥ��
}NET_DVR_RTSPCFG, *LPNET_DVR_RTSPCFG;

/********************************�ӿڲ����ṹ(begin)*********************************/

//NET_DVR_Login()�����ṹ
typedef struct
{
	BYTE sSerialNumber[SERIALNO_LEN];   //���к�
	BYTE byAlarmInPortNum;		        //DVR�����������
	BYTE byAlarmOutPortNum;		        //DVR�����������
	BYTE byDiskNum;				        //DVRӲ�̸���
	BYTE byDVRType;				        //DVR����, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				        //DVR ͨ������
	BYTE byStartChan;			        //��ʼͨ����,����DVS-1,DVR - 1
}NET_DVR_DEVICEINFO, *LPNET_DVR_DEVICEINFO;

//NET_DVR_Login_V30()�����ṹ
typedef struct
{
    BYTE sSerialNumber[SERIALNO_LEN];  //���к�
    BYTE byAlarmInPortNum;		        //�����������
    BYTE byAlarmOutPortNum;		        //�����������
    BYTE byDiskNum;				    //Ӳ�̸���
    BYTE byDVRType;				    //�豸����, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;				    //ģ��ͨ������
    BYTE byStartChan;			        //��ʼͨ����,����DVS-1,DVR - 1
    BYTE byAudioChanNum;                //����ͨ����
    BYTE byIPChanNum;					//�������ͨ������  
	BYTE byZeroChanNum;			//��ͨ��������� //2010-01-16
	BYTE byMainProto;			//����������Э������ 0-private, 1-rtsp
	BYTE bySubProto;				//����������Э������0-private, 1-rtsp
    BYTE bySupport;        //������λ����Ϊ0��ʾ��֧�֣�1��ʾ֧�֣�
                            //bySupport & 0x1, ��ʾ�Ƿ�֧����������
                            //bySupport & 0x2, ��ʾ�Ƿ�֧�ֱ���
                            //bySupport & 0x4, ��ʾ�Ƿ�֧��ѹ������������ȡ
                            //bySupport & 0x8, ��ʾ�Ƿ�֧�ֶ�����
                            //bySupport & 0x10, ��ʾ֧��Զ��SADP
                            //bySupport & 0x20  ��ʾ֧��Raid������
                            //bySupport & 0x40  ��ʾ֧��IPSAN Ŀ¼����
    BYTE byRes1[20];					//����
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

//sdk���绷��ö�ٱ���������Զ������
typedef enum _SDK_NET_ENV
{
    LOCAL_AREA_NETWORK = 0,
        WIDE_AREA_NETWORK
}SDK_NETWORK_ENVIRONMENT;

//��ʾģʽ
typedef enum
{
	NORMALMODE = 0,
	OVERLAYMODE
}DISPLAY_MODE;

//����ģʽ
typedef enum
{
	PTOPTCPMODE = 0,
	PTOPUDPMODE,
	MULTIMODE,
	RTPMODE,
	RESERVEDMODE
}SEND_MODE;

//ץͼģʽ
typedef enum 
{
	BMP_MODE = 0,		//BMPģʽ
	JPEG_MODE = 1		//JPEGģʽ 
}CAPTURE_MODE;

//ʵʱ����ģʽ
typedef enum
{
	MONOPOLIZE_MODE = 1,//��ռģʽ
	SHARE_MODE = 2		//����ģʽ
}REALSOUND_MODE;

//������Ԥ������
typedef struct
{
	LONG lChannel;//ͨ����
	LONG lLinkMode;//���λ(31)Ϊ0��ʾ��������Ϊ1��ʾ�ӣ�0��30λ��ʾ�������ӷ�ʽ: 0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-����Ƶ�ֿ�(TCP)
	HWND hPlayWnd;//���Ŵ��ڵľ��,ΪNULL��ʾ������ͼ��
	char* sMultiCastIP;//�ಥ���ַ
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

//SDK״̬��Ϣ(9000����)
typedef struct 
{
    DWORD dwTotalLoginNum;		//��ǰlogin�û���
    DWORD dwTotalRealPlayNum;	//��ǰrealplay·��
    DWORD dwTotalPlayBackNum;	//��ǰ�طŻ�����·��
    DWORD dwTotalAlarmChanNum;	//��ǰ��������ͨ��·��
    DWORD dwTotalFormatNum;		//��ǰӲ�̸�ʽ��·��
    DWORD dwTotalFileSearchNum;	//��ǰ��־���ļ�����·��
    DWORD dwTotalLogSearchNum;	//��ǰ��־���ļ�����·��
    DWORD dwTotalSerialNum;	    //��ǰ͸��ͨ��·��
    DWORD dwTotalUpgradeNum;	//��ǰ����·��
    DWORD dwTotalVoiceComNum;	//��ǰ����ת��·��
    DWORD dwTotalBroadCastNum;	//��ǰ�����㲥·��
    DWORD dwTotalListenNum;	    //��ǰ�������·��
    DWORD dwEmailTestNum;       //��ǰ�ʼ�����·��
    DWORD dwBackupNum;          // ��ǰ�ļ�����·��
	DWORD dwTotalInquestUploadNum; //��ǰ��Ѷ�ϴ�·��
    DWORD dwRes[6];
}NET_DVR_SDKSTATE, *LPNET_DVR_SDKSTATE;

//SDK����֧����Ϣ(9000����)
typedef struct 
{
    DWORD dwMaxLoginNum;		//���login�û��� MAX_LOGIN_USERS
    DWORD dwMaxRealPlayNum;		//���realplay·�� WATCH_NUM
    DWORD dwMaxPlayBackNum;		//���طŻ�����·�� WATCH_NUM
    DWORD dwMaxAlarmChanNum;	//���������ͨ��·�� ALARM_NUM
    DWORD dwMaxFormatNum;		//���Ӳ�̸�ʽ��·�� SERVER_NUM
    DWORD dwMaxFileSearchNum;	//����ļ�����·�� SERVER_NUM
    DWORD dwMaxLogSearchNum;	//�����־����·�� SERVER_NUM
    DWORD dwMaxSerialNum;	    //���͸��ͨ��·�� SERVER_NUM
    DWORD dwMaxUpgradeNum;	    //�������·�� SERVER_NUM
    DWORD dwMaxVoiceComNum;		//�������ת��·�� SERVER_NUM
    DWORD dwMaxBroadCastNum;	//��������㲥·�� MAX_CASTNUM
    DWORD dwRes[10];
}NET_DVR_SDKABL, *LPNET_DVR_SDKABL;

//�����豸��Ϣ
typedef struct
{   
    BYTE byUserIDValid;                 /* userid�Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE bySerialValid;                 /* ���к��Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE byVersionValid;                /* �汾���Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE byDeviceNameValid;             /* �豸�����Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE byMacAddrValid;                /* MAC��ַ�Ƿ���Ч 0-��Ч��1-��Ч */    
    BYTE byLinkPortValid;               /* login�˿��Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE byDeviceIPValid;               /* �豸IP�Ƿ���Ч 0-��Ч��1-��Ч */
    BYTE bySocketIPValid;               /* socket ip�Ƿ���Ч 0-��Ч��1-��Ч */
    LONG lUserID;                       /* NET_DVR_Login()����ֵ, ����ʱ��Ч */
    BYTE sSerialNumber[SERIALNO_LEN];	/* ���к� */
    DWORD dwDeviceVersion;			    /* �汾��Ϣ ��16λ��ʾ���汾����16λ��ʾ�ΰ汾*/
    char sDeviceName[NAME_LEN];		    /* �豸���� */
    BYTE byMacAddr[MACADDR_LEN];		/* MAC��ַ */    
    WORD wLinkPort;                     /* link port */
    char sDeviceIP[128];    			/* IP��ַ */
    char sSocketIP[128];    			/* ���������ϴ�ʱ��socket IP��ַ */
    BYTE byIpProtocol;                  /* IpЭ�� 0-IPV4, 1-IPV6 */
    BYTE byRes2[11];
}NET_DVR_ALARMER, *LPNET_DVR_ALARMER;

//Ӳ������ʾ�������(�ӽṹ)
typedef struct
{
	long bToScreen;
	long bToVideoOut;
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;
}NET_DVR_DISPLAY_PARA, *LPNET_DVR_DISPLAY_PARA;

//Ӳ����Ԥ������
typedef struct
{
	LONG lChannel;//ͨ����
	LONG lLinkMode; //���λ(31)Ϊ0��ʾ��������Ϊ1��ʾ�ӣ�0��30λ��ʾ�������ӷ�ʽ:0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-�绰�ߣ�5��128k������6��256k������7��384k������8��512k������
	char* sMultiCastIP;
	NET_DVR_DISPLAY_PARA struDisplayPara;
}NET_DVR_CARDINFO, *LPNET_DVR_CARDINFO;

//¼���ļ�����
typedef struct 
{
	char sFileName[100];//�ļ���
	NET_DVR_TIME struStartTime;//�ļ��Ŀ�ʼʱ��
	NET_DVR_TIME struStopTime;//�ļ��Ľ���ʱ��
	DWORD dwFileSize;//�ļ��Ĵ�С
}NET_DVR_FIND_DATA, *LPNET_DVR_FIND_DATA;

//¼���ļ�����(9000)
typedef struct 
{
    char sFileName[100];//�ļ���
    NET_DVR_TIME struStartTime;//�ļ��Ŀ�ʼʱ��
    NET_DVR_TIME struStopTime;//�ļ��Ľ���ʱ��
    DWORD dwFileSize;//�ļ��Ĵ�С
    char sCardNum[32];
    BYTE byLocked;//9000�豸֧��,1��ʾ���ļ��Ѿ�������,0��ʾ�������ļ�
	BYTE byFileType;  //�ļ�����:0����ʱ¼��,1-�ƶ���� ��2������������
	//3-����|�ƶ���� 4-����&�ƶ���� 5-����� 6-�ֶ�¼��
    BYTE byRes[2];
}NET_DVR_FINDDATA_V30, *LPNET_DVR_FINDDATA_V30;

//¼���ļ�����(������)
typedef struct 
{
	char sFileName[100];//�ļ���
	NET_DVR_TIME struStartTime;//�ļ��Ŀ�ʼʱ��
	NET_DVR_TIME struStopTime;//�ļ��Ľ���ʱ��
	DWORD dwFileSize;//�ļ��Ĵ�С
	char sCardNum[32];
}NET_DVR_FINDDATA_CARD, *LPNET_DVR_FINDDATA_CARD;


//¼���ļ����������ṹ
typedef struct 
{
    LONG lChannel;//ͨ����
    DWORD dwFileType;//¼���ļ�����0xff��ȫ����0����ʱ¼��,1-�ƶ���� ��2������������
                    //3-����|�ƶ���� 4-����&�ƶ���� 5-����� 6-�ֶ�¼��
    DWORD dwIsLocked;//�Ƿ����� 0-�����ļ�,1-�����ļ�, 0xff��ʾ�����ļ�
    DWORD dwUseCardNo;//�Ƿ�ʹ�ÿ���
    BYTE sCardNumber[32];//����
    NET_DVR_TIME struStartTime;//��ʼʱ��
    NET_DVR_TIME struStopTime;//����ʱ��
}NET_DVR_FILECOND, *LPNET_DVR_FILECOND;

//��̨����ѡ��Ŵ���С(˽�� ����ר��)
typedef struct 
{
	int xTop;     //������ʼ���x����
	int yTop;     //����������y����
	int xBottom;  //����������x����
	int yBottom;  //����������y����
	int bCounter; //����
}NET_DVR_POINT_FRAME, *LPNET_DVR_POINT_FRAME;

//�����Խ�����
typedef struct tagNET_DVR_COMPRESSION_AUDIO
{
	BYTE  byAudioEncType;   //��Ƶ�������� 0-OggVorbis;1-G711_U;2-G711_A
	BYTE  byres[7];//���ﱣ����Ƶ��ѹ������ 
}NET_DVR_COMPRESSION_AUDIO, *LPNET_DVR_COMPRESSION_AUDIO;

//2009-7-22
#define NET_DVR_GET_AP_INFO_LIST	305//��ȡ����������Դ����
#define NET_DVR_SET_WIFI_CFG		306	//����IP����豸���߲���
#define NET_DVR_GET_WIFI_CFG		307	//��ȡIP����豸���߲���
#define NET_DVR_SET_WIFI_WORKMODE	308	//����IP����豸���ڹ���ģʽ����
#define NET_DVR_GET_WIFI_WORKMODE	309	//��ȡIP����豸���ڹ���ģʽ����

#define IW_ESSID_MAX_SIZE						 32
#define WIFI_WEP_MAX_KEY_COUNT					 4
#define WIFI_WEP_MAX_KEY_LENGTH					 33
#define WIFI_WPA_PSK_MAX_KEY_LENGTH				 63
#define WIFI_WPA_PSK_MIN_KEY_LENGTH				 8
#define WIFI_MAX_AP_COUNT						 20

typedef struct tagNET_DVR_AP_INFO
{
	char  sSsid[IW_ESSID_MAX_SIZE];
	DWORD  dwMode;						/* 0 mange ģʽ;1 ad-hocģʽ���μ�NICMODE */
	DWORD  dwSecurity;           /*0 �����ܣ�1 wep���ܣ�2 wpa-psk;3 wpa-Enterprise;4-WPA2_PSK�μ�WIFISECURITY*/
	DWORD  dwChannel;            /*1-11��ʾ11��ͨ��*/
	DWORD  dwSignalStrength;    /*0-100�ź���������Ϊ��ǿ*/
	DWORD  dwSpeed;               /*����,��λ��0.01mbps*/
}NET_DVR_AP_INFO,*LPNET_DVR_AP_INFO;

typedef struct tagNET_DVR_AP_INFO_LIST
{
	DWORD dwSize;
	DWORD dwCount;        /*����AP������������20*/
	NET_DVR_AP_INFO struApInfo[WIFI_MAX_AP_COUNT];
}NET_DVR_AP_INFO_LIST,*LPNET_DVR_AP_INFO_LIST;

typedef struct tagNET_DVR_WIFIETHERNET
{	
	char sIpAddress[16];				/*IP��ַ*/
	char sIpMask[16];					/*����*/	
	BYTE	byMACAddr[MACADDR_LEN];		/*������ַ��ֻ������ʾ*/
	BYTE	bRes[2];
	DWORD	dwEnableDhcp;				/*�Ƿ�����dhcp  0������ 1����*/
	DWORD	dwAutoDns;					/*�������dhcp�Ƿ��Զ���ȡdns,0���Զ���ȡ 1�Զ���ȡ�����������������dhcpĿǰ�Զ���ȡdns*/	
	char sFirstDns[16];						 /*��һ��dns����*/
	char sSecondDns[16];					 /*�ڶ���dns����*/
	char sGatewayIpAddr[16]; 				/* ���ص�ַ*/
	BYTE   bRes2[8];
}NET_DVR_WIFIETHERNET,*LPNET_DVR_WIFIETHERNET;

typedef struct tagNET_DVR_WIFI_CFG_EX
{
	NET_DVR_WIFIETHERNET struEtherNet;        /*wifi����*/
	char sEssid[IW_ESSID_MAX_SIZE];	 /*SSID*/
	DWORD dwMode;      /* 0 mange ģʽ;1 ad-hocģʽ���μ�*/
	DWORD dwSecurity; /*0-������;1-wep����;2-wpa-psk; 3-WPA_ENTPRISE;4-WPA2_PSK */
	union 
	{
		struct 
		{
			DWORD dwAuthentication;/*0 -����ʽ 1-����ʽ*/
			DWORD dwKeyLength;/* 0 -64λ��1- 128λ��2-152λ*/
			DWORD dwKeyType;/*0 16����;1 ASCI */
			DWORD dwActive;/*0 ������0---3��ʾ����һ����Կ*/
			char sKeyInfo[WIFI_WEP_MAX_KEY_COUNT][WIFI_WEP_MAX_KEY_LENGTH];
		}wep;
		struct 
		{
			DWORD dwKeyLength;/*8-63��ASCII�ַ�*/
			char sKeyInfo[WIFI_WPA_PSK_MAX_KEY_LENGTH];
			BYTE byEncryptType;  /*WPA/WPA2ģʽ�¼�������,0-AES, 1-TKIP*/
		}wpa_psk;
		
	}key;	
}NET_DVR_WIFI_CFG_EX,*LPNET_DVR_WIFI_CFG_EX;

//wifi���ýṹ
typedef struct tagNET_DVR_WIFI_CFG
{
	DWORD dwSize;
	NET_DVR_WIFI_CFG_EX struWifiCfg;
}NET_DVR_WIFI_CFG,*LPNET_DVR_WIFI_CFG;

//wifi����ģʽ
typedef struct tagNET_DVR_WIFI_WORKMODE
{
	DWORD dwSize;
	DWORD dwNetworkInterfaceMode; /*0 �Զ��л�ģʽ��1 ����ģʽ*/
}NET_DVR_WIFI_WORKMODE,*LPNET_DVR_WIFI_WORKMODE;

/******************************��������ȡ*********************************/
//������ȡ����
#define DEVICE_ALL_ABILITY            0x000  //�豸ȫ������
#define DEVICE_SOFTHARDWARE_ABILITY   0x001  //�豸��Ӳ������
#define DEVICE_NETWORK_ABILITY        0x002   //�豸��������
#define DEVICE_ENCODE_ALL_ABILITY     0x003  //�豸���б�������
#define	DEVICE_ENCONE_CURRENT         0x004  //�豸��ǰ��������
#define IPC_FRONT_PARAMETER				0x005	//ipcǰ�˲���
#define IPC_UPGRADE_DESCRIPTION			0x006	//ipc������Ϣ
#define VCA_DEV_ABILITY 	 0x100 //�豸���ܷ�����������
#define VCA_CHAN_ABILITY     0x110 //��Ϊ��������
#define MATRIXDECODER_ABILITY 0x200 //��·��������ʾ����������
#define COMPRESSIONCFG_ABILITY  0x400    //��ȡѹ������������ȡ

//�����ص�����
//��ӦNET_DVR_PLATE_RESULT
#define  COMM_ALARM_PLATE				0x1101	//����ʶ�𱨾���Ϣ
//��ӦNET_VCA_RULE_ALARM
#define  COMM_ALARM_RULE				0x1102	//��Ϊ����������Ϣ
#define  COMM_ALARM_PDC                 0x1103  // ����ͳ�Ʊ�����Ϣ
#define  COMM_ALARM_VIDEOPLATFORM        0x1104  // ��Ƶ�ۺ�ƽ̨����
#define COMM_ALARM_ALARMHOST        0x1105  // ���籨����������
#define  COMM_ALARM_FACE                0x1106   // �������ʶ�𱨾���Ϣ
#define COMM_RULE_INFO_UPLOAD           0x1107  //  �¼�������Ϣ�ϴ�
#define COMM_ALARM_AID                  0x1110      // ��ͨ�¼�������Ϣ
#define COMM_ALARM_TPS                  0x1111  // ��ͨ����ͳ�Ʊ�����Ϣ
#define COMM_SENSOR_VALUE_UPLOAD		0x1120  // ģ��������ʵʱ�ϴ�
#define COMM_SENSOR_ALARM          		0x1121  // ģ���������ϴ�
#define COMM_SWITCH_ALARM				0x1122	// ����������
#define COMM_ALARMHOST_EXCEPTION        0x1123  // �����������ϱ���
//���Ʊ���NET_DVR_PLATE_RESULT
#define COMM_UPLOAD_PLATE_RESULT		0x2800	//�ϴ�������Ϣ

//�ṹ�����궨�� 
#define VCA_MAX_POLYGON_POINT_NUM		10		//����������֧��10����Ķ����
#define MAX_RULE_NUM					8		//����������
#define MAX_TARGET_NUM    				30		//���Ŀ�����
#define MAX_CALIB_PT 					6		//���궨�����
#define MIN_CALIB_PT 					4		//��С�궨�����
#define MAX_TIMESEGMENT_2	    		2		//���ʱ�����
#define MAX_LICENSE_LEN					16		//���ƺ���󳤶�
#define MAX_PLATE_NUM					3		//���Ƹ���
#define MAX_MASK_REGION_NUM				4       //����ĸ���������
#define MAX_SEGMENT_NUM					6        //������궨�����������Ŀ
#define MIN_SEGMENT_NUM					3        //������궨��С��������Ŀ


//���ܿ�����Ϣ
#define MAX_VCA_CHAN  16//�������ͨ����
typedef struct tagNET_VCA_CTRLINFO
{
	BYTE   byVCAEnable;		//�Ƿ�������
	BYTE   byVCAType;	    //�����������ͣ�VCA_CHAN_ABILITY_TYPE 
	BYTE   byStreamWithVCA; //�������Ƿ��������Ϣ
    BYTE   byMode;			//ģʽ��VCA_CHAN_MODE_TYPE ,atm������ʱ����Ҫ����
	BYTE   byRes[4]; 		//����������Ϊ0 
}NET_VCA_CTRLINFO, * LPNET_VCA_CTRLINFO;

//���ܿ�����Ϣ�ṹ
typedef struct tagNET_VCA_CTRLCFG
{
	DWORD dwSize;
	NET_VCA_CTRLINFO  struCtrlInfo[MAX_VCA_CHAN]; 	//������Ϣ,����0��Ӧ�豸����ʼͨ��
	BYTE byRes[16];
}NET_VCA_CTRLCFG, * LPNET_VCA_CTRLCFG;

//�����豸������
typedef struct tagNET_VCA_DEV_ABILITY
{
	DWORD dwSize;			//�ṹ����
	BYTE byVCAChanNum;		//����ͨ������
	BYTE byPlateChanNum; 	//����ͨ������
	BYTE byBBaseChanNum;	//��Ϊ���������
	BYTE byBAdvanceChanNum; //��Ϊ�߼������
	BYTE byBFullChanNum;    //��Ϊ���������
	BYTE byATMChanNum;		//����ATM����
    BYTE byPDCChanNum;      //����ͳ��ͨ������
    BYTE byITSChanNum;      // ��ͨ�¼�ͨ������
    BYTE byBPrisonChanNum;	// ��Ϊ������ͨ������
    BYTE byRes[31];
}NET_VCA_DEV_ABILITY, *LPNET_VCA_DEV_ABILITY;


//��Ϊ������������
typedef enum _VCA_ABILITY_TYPE_
{
    TRAVERSE_PLANE_ABILITY           = 0x01,      //��Խ������
    ENTER_AREA_ABILITY          = 0x02,      //��������
    EXIT_AREA_ABILITY           = 0x04,      //�뿪����
    INTRUSION_ABILITY           = 0x08,      //����
    LOITER_ABILITY               = 0x10,     //�ǻ�
    LEFT_TAKE_ABILITY            = 0x20,     //��Ʒ������ȡ
    PARKING_ABILITY              = 0x40,     //ͣ��
    RUN_ABILITY                  = 0x80,    //�����ƶ�
	HIGH_DENSITY_ABILITY         = 0x100,    //��Ա�ۼ�
	LF_TRACK_ABILITY			 = 0x200,    //�������
    VIOLENT_MOTION_ABILITY		= 0x400,		// �����˶����
    REACH_HIGHT_ABILITY			= 0x800,		// �ʸ߼��
    GET_UP_ABILITY				= 0x1000,	// �������
    LEFT_ABILITY                = 0x2000,       // ��Ʒ����
    TAKE_ABILITY                = 0x4000,       // ��Ʒ��ȡ
    HUMAN_ENTER_ABILITY         = 0x10000000,   //�˿���ATM           ֻ��ATM_PANELģʽ��֧��
    OVER_TIME_ABILITY           = 0x20000000,   //������ʱ            ֻ��ATM_PANELģʽ��֧��
	STICK_UP_ABILITY             = 0x40000000,  //��ֽ��
	INSTALL_SCANNER_ABILITY      = 0x80000000   //��װ������
}VCA_ABILITY_TYPE;


//����ͨ������
typedef enum _VCA_CHAN_ABILITY_TYPE_
{
	VCA_BEHAVIOR_BASE     =  1,   //��Ϊ����������
	VCA_BEHAVIOR_ADVANCE  =  2,   //��Ϊ�����߼���
	VCA_BEHAVIOR_FULL     =  3,   //��Ϊ����������
    VCA_PLATE     		  =  4,   //��������
	VCA_ATM               =  5,    //ATM����
    VCA_PDC               =  6,      // ������ͳ��
    VCA_ITS               =  7,      // ���� ��ͨ�¼�
    VCA_BEHAVIOR_PRISON   =  8,     // ��Ϊ����������      
}VCA_CHAN_ABILITY_TYPE;

//����ATMģʽ����(ATM��������)
typedef enum _VCA_CHAN_MODE_TYPE_
{
    VCA_ATM_PANEL     =  0, //ATM���
    VCA_ATM_SURROUND  =  1,  //ATM����
    VCA_ATM_FACE		= 2	//ATM����
}VCA_CHAN_MODE_TYPE;


//ͨ�������������
typedef struct tagNET_VCA_CHAN_IN_PARAM
{
	BYTE byVCAType;	    //VCA_CHAN_ABILITY_TYPEö��ֵ
	BYTE byMode;		//ģʽ��VCA_CHAN_MODE_TYPE ,atm������ʱ����Ҫ����  ��VCA_TYPE Ϊ��ͨ�¼� ģʽ����TRAFFIC_SCENE_MODE
	BYTE byRes[2]; 	    //����������Ϊ0 
}NET_VCA_CHAN_IN_PARAM, *LPNET_VCA_CHAN_IN_PARAM;


//��Ϊ�������ṹ
typedef struct tagNET_VCA_BEHAVIOR_ABILITY
{
	DWORD dwSize;		 //�ṹ����
	DWORD dwAbilityType; //֧�ֵ��������ͣ���λ��ʾ����VCA_ABILITY_TYPE����
	BYTE byMaxRuleNum;	 //��������
	BYTE byMaxTargetNum; //���Ŀ����
    BYTE	bySupport;		// ֧�ֵĹ�������   ��λ��ʾ  
                            // bySupport & 0x01 ֧�ֱ궨����
    BYTE byRes[9];        //����������Ϊ0
}NET_VCA_BEHAVIOR_ABILITY, *LPNET_VCA_BEHAVIOR_ABILITY;

// ��ͨ�������ṹ
typedef struct tagNET_DVR_ITS_ABILITY
{
    DWORD 	dwSize;             // �ṹ���С
    DWORD 	dwAbilityType;      // ֧�ֵ������б�  ����ITS_ABILITY_TYPE
	BYTE 	byMaxRuleNum;	 	//��������
	BYTE 	byMaxTargetNum; 	//���Ŀ����
   	BYTE	byRes[10];		    // ����
}NET_DVR_ITS_ABILITY, *LPNET_DVR_ITS_ABILITY;

/***********************************end*******************************************/

/************************************���ܲ����ṹ*********************************/
//���ܹ��ýṹ
//����ֵ��һ��,������ֵΪ��ǰ����İٷֱȴ�С, ����ΪС�������λ
//������ṹ
typedef struct tagNET_VCA_POINT
{	
	float fX;								// X������, 0.001~1
	float fY;								//Y������, 0.001~1
}NET_VCA_POINT, *LPNET_VCA_POINT;

//�����ṹ
typedef struct tagNET_VCA_RECT
{
	float fX;               //�߽�����Ͻǵ��X������, 0.001~1
	float fY;               //�߽�����Ͻǵ��Y������, 0.001~1
	float fWidth;           //�߽��Ŀ���, 0.001~1
	float fHeight;          //�߽��ĸ߶�, 0.001~1
}NET_VCA_RECT, *LPNET_VCA_RECT;

//��Ϊ�����¼�����
typedef enum _VCA_EVENT_TYPE_
{
	VCA_TRAVERSE_PLANE		= 0x1,    //��Խ������
	VCA_ENTER_AREA		= 0x2,    //Ŀ���������,֧���������
	VCA_EXIT_AREA		= 0x4,    //Ŀ���뿪����,֧���������
	VCA_INTRUSION		= 0x8,    //�ܽ�����,֧���������
	VCA_LOITER			= 0x10,   //�ǻ�,֧���������
	VCA_LEFT_TAKE		= 0x20,   //��Ʒ������ȡ,֧���������
	VCA_PARKING			= 0x40,   //ͣ��,֧���������
	VCA_RUN				= 0x80,   //�����ƶ�,֧���������
	VCA_HIGH_DENSITY	= 0x100,  //��������Ա�ۼ�,֧���������
    VCA_VIOLENT_MOTION	= 0x200,		// �����˶����
    VCA_REACH_HIGHT		= 0x400,		// �ʸ߼��
    VCA_GET_UP			= 0x800,	// �������
    VCA_LEFT            = 0x1000,   // ��Ʒ����
    VCA_TAKE            = 0x2000,   // ��Ʒ��ȡ
    VCA_HUMAN_ENTER     = 0x10000000,   //�˿���ATM           ֻ��ATM_PANELģʽ��֧��
    VCA_OVER_TIME       = 0x20000000,   //������ʱ            ֻ��ATM_PANELģʽ��֧��
    VCA_STICK_UP        = 0x40000000,  //��ֽ��,֧���������
    VCA_INSTALL_SCANNER = 0x80000000 //��װ������,֧���������
}VCA_EVENT_TYPE;

//�����洩Խ��������
typedef enum _VCA_CROSS_DIRECTION_
{
	VCA_BOTH_DIRECTION,  // ˫�� 
	VCA_LEFT_GO_RIGHT,   // �������� 
	VCA_RIGHT_GO_LEFT    // �������� 
}VCA_CROSS_DIRECTION;

//�߽ṹ
typedef struct tagNET_VCA_LINE
{
	NET_VCA_POINT struStart;    //��� 
	NET_VCA_POINT struEnd;      //�յ�
}NET_VCA_LINE, *LPNET_VCA_LINE;

//����ͽṹ��
typedef struct tagNET_VCA_POLYGON
{
	DWORD dwPointNum;                                  //��Ч�� ���ڵ���3������3����һ��������Ϊ����Ч�����߽�����Ϊ����Ч���� 
	NET_VCA_POINT  struPos[VCA_MAX_POLYGON_POINT_NUM]; //����α߽��,���ʮ�� 
}NET_VCA_POLYGON, *LPNET_VCA_POLYGON;

//���������
typedef struct tagNET_VCA_TRAVERSE_PLANE
{	
    NET_VCA_LINE struPlaneBottom;  //������ױ�
    VCA_CROSS_DIRECTION dwCrossDirection; //��Խ����: 0-˫��1-�����ң�2-���ҵ���
    BYTE byRes1;//����
    BYTE byPlaneHeight; //������߶�
    BYTE byRes2[38];				//����
}NET_VCA_TRAVERSE_PLANE, *LPNET_VCA_TRAVERSE_PLANE;

//����/�뿪�������
typedef struct tagNET_VCA_AREA
{
    NET_VCA_POLYGON struRegion;//����Χ
    BYTE byRes[8];
}NET_VCA_AREA, *LPNET_VCA_AREA;

//���ݱ����ӳ�ʱ������ʶ�����д�ͼƬ�����������IO����һ�£�1�뷢��һ����
//���ֲ���
typedef struct tagNET_VCA_INTRUSION
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration;    //��Ϊ�¼�����ʱ����ֵ: 1-120�룬����5�룬�ж�����Ч������ʱ��  ��ATMϵͳ�д����ļ���ֵΪ 1-1000��
    BYTE byRes[6];
}NET_VCA_INTRUSION, *LPNET_VCA_INTRUSION;

//�ǻ�����
typedef struct tagNET_VCA_PARAM_LOITER
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration; //����ʱ����ֵ��1-120�룬����10��
    BYTE byRes[6];
}NET_VCA_LOITER, *LPNET_VCA_LOITER;

//��Ʒ����/��Ʒ��ȡ����
typedef struct tagNET_VCA_TAKE_LEFT
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration; //����ʱ����ֵ��1-120�룬����10��
    BYTE byRes[6];
}NET_VCA_TAKE_LEFT, *LPNET_VCA_TAKE_LEFT;

//ͣ������
typedef struct tagNET_VCA_PARKING
{
    NET_VCA_POLYGON struRegion;	//����Χ
    WORD wDuration;				//����ʱ����ֵ��1-100�룬����10��
    BYTE byRes[6];
}NET_VCA_PARKING, *LPNET_VCA_PARKING;

//�����ƶ�����
typedef struct tagNET_VCA_RUN
{
	NET_VCA_POLYGON struRegion;	//����Χ
    float  fRunDistance;		//�˿����ƶ�������, ��Χ: [0.1, 1.00] ����ģʽ ʵ��ģʽ(1,20)m/s
    BYTE    byRes1;             // �����ֽ�
    BYTE    byMode;             // 0 ����ģʽ  1 ʵ��ģʽ
    BYTE byRes[2];
}NET_VCA_RUN, *LPNET_VCA_RUN;

//��Ա�ۼ�����
typedef struct tagNET_VCA_HIGH_DENSITY
{
    NET_VCA_POLYGON struRegion;//����Χ
    float           fDensity;       //�ۼ�����, ��Χ: [0.1, 1.0]
    BYTE            byRes;          // �����ֽ�
    WORD            wDuration;      // ������Ա�ۼ�����������ֵ 20-360s
}NET_VCA_HIGH_DENSITY, *LPNET_VCA_HIGH_DENSITY; 

//�����˶�����
typedef struct tagNET_VCA_VIOLENT_MOTION
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration; //���������˶�������ֵ��1-120��
    BYTE  bySensitivity;       //�����Ȳ�������Χ[1,5]
    BYTE byRes[5];
}NET_VCA_VIOLENT_MOTION, *LPNET_VCA_VIOLENT_MOTION; 
// �ʸ߲���
typedef struct tagNET_VCA_REACH_HIGHT
{
    NET_VCA_LINE struVcaLine;   //�ʸ߾�����
    WORD wDuration; //�����ʸ߱�����ֵ��1-120��
    BYTE	byRes[6];           // �����ֽ�
}NET_VCA_REACH_HIGHT, *LPNET_VCA_REACH_HIGHT;

// �𴲲���
typedef struct tagNET_VCA_GET_UP
{
    NET_VCA_POLYGON struRegion; // ����Χ
    WORD	wDuration;	// �����𴲱�����ֵ1-120 ��
    BYTE	byRes[6];		// �����ֽ�
}NET_VCA_GET_UP, * LPNET_VCA_GET_UP;

// ��Ʒ����
typedef struct tagNET_VCA_LEFT
{
    NET_VCA_POLYGON struRegion;     // ����Χ
    WORD      wDuration;      // ������Ʒ����������ֵ 4-60��
    BYTE       byRes[6];       // �����ֽ�
}NET_VCA_LEFT, *LPNET_VCA_LEFT;

// ��Ʒ��ȡ
typedef struct tagNET_VCA_TAKE
{
    NET_VCA_POLYGON struRegion;     // ����Χ
    WORD            wDuration;      // ������Ʒ��ȡ������ֵ4-60��
    BYTE            byRes[6];       // �����ֽ�
}NET_VCA_TAKE, *LPNET_VCA_TAKE;

typedef struct tagNET_VCA_OVER_TIME
{
    NET_VCA_POLYGON     struRegion;    // ����Χ
    WORD               wDuration;  // ��������ʱ����ֵ 4s-60000s
    BYTE   byRes[6];   // �����ֽ�
}NET_VCA_OVER_TIME, *LPNET_VCA_OVER_TIME;

typedef struct tagNET_VCA_HUMAN_ENTER
{
    DWORD                dwRes[23];			//�����ֽ�
}NET_VCA_HUMAN_ENTER, *LPNET_VCA_HUMAN_ENTER;

//��ֽ������
typedef struct tagNET_VCA_STICK_UP
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration; //����ʱ����ֵ��4-60�룬����10��
    BYTE  bySensitivity;       //�����Ȳ�������Χ[1,5]
    BYTE byRes[5];
}NET_VCA_STICK_UP, *LPNET_VCA_STICK_UP; 

//����������
typedef struct tagNET_VCA_SCANNER
{
    NET_VCA_POLYGON struRegion;//����Χ
    WORD wDuration; //��������ʱ�䣺4-60��
    BYTE  bySensitivity;       //�����Ȳ�������Χ[1,5]
    BYTE byRes[5];
}NET_VCA_SCANNER, *LPNET_VCA_SCANNER; 


//�����¼�����
typedef union tagNET_VCA_EVENT_UNION
{
	DWORD                uLen[23];			//����
	NET_VCA_TRAVERSE_PLANE    struTraversePlane;		//��Խ��������� 
	NET_VCA_AREA    	 struArea;			//����/�뿪�������
	NET_VCA_INTRUSION    struIntrusion;		//���ֲ���
	NET_VCA_LOITER       struLoiter;		//�ǻ�����
	NET_VCA_TAKE_LEFT    struTakeTeft;		//��Ʒ����/��Ʒ��ȡ����
	NET_VCA_PARKING      struParking;		//ͣ������
	NET_VCA_RUN          struRun;			//�����ƶ�����
	NET_VCA_HIGH_DENSITY struHighDensity;	//��Ա�ۼ�����  
    NET_VCA_VIOLENT_MOTION struViolentMotion;	// �����˶�
    NET_VCA_REACH_HIGHT	struReachHight;	// �ʸ�
    NET_VCA_GET_UP		struGetUp;		//��
    NET_VCA_LEFT        struLeft;       // ��Ʒ����
    NET_VCA_TAKE        struTake;       // ��Ʒ��ȡ
    NET_VCA_HUMAN_ENTER struHumanEnter; // ��Ա����
	NET_VCA_OVER_TIME   struOvertime;   // ������ʱ
    NET_VCA_STICK_UP 	struStickUp;		//��ֽ��
    NET_VCA_SCANNER 	struScanner;		//���������� 	
}NET_VCA_EVENT_UNION, *LPNET_VCA_EVENT_UNION;

// �ߴ����������
typedef enum _VCA_SIZE_FILTER_MODE_
{
	IMAGE_PIX_MODE, //�������ش�С����
	REAL_WORLD_MODE, //����ʵ�ʴ�С����
    DEFAULT_MODE 	// Ĭ��ģʽ
}SIZE_FILTER_MODE;
//�ߴ������
typedef struct tagNET_VCA_SIZE_FILTER
{
	BYTE    byActive;			//�Ƿ񼤻�ߴ������ 0-�� ��0-��
    BYTE    byMode;		 //������ģʽSIZE_FILTER_MODE
	BYTE    byRes[2];        //��������0
	NET_VCA_RECT struMiniRect;    //��СĿ���,ȫ0��ʾ������
	NET_VCA_RECT struMaxRect;	  //���Ŀ���,ȫ0��ʾ������
}NET_VCA_SIZE_FILTER, *LPNET_VCA_SIZE_FILTER;

//�������ṹ
typedef struct tagNET_VCA_ONE_RULE
{
	BYTE   byActive;					//�Ƿ񼤻����,0-��,��0-��
	BYTE   byRes[7];         			//����������Ϊ0�ֶ�
    BYTE   byRuleName[NAME_LEN];		//��������
	VCA_EVENT_TYPE dwEventType;			//��Ϊ�����¼�����
    NET_VCA_EVENT_UNION uEventParam;	//��Ϊ�����¼�����
    NET_VCA_SIZE_FILTER  struSizeFilter;  //�ߴ������
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//����ʱ��
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //������ʽ 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//����������¼��ͨ��,Ϊ1��ʾ������ͨ��
}NET_VCA_ONE_RULE, *LPNET_VCA_ONE_RULE;

//��Ϊ�������ýṹ��
typedef struct tagNET_VCA_RULECFG
{
	DWORD  dwSize;			//�ṹ����
	BYTE    byPicProType;	//����ʱͼƬ������ʽ 0-������ ��0-�ϴ�
	BYTE    byRes[3];
	NET_DVR_JPEGPARA struPictureParam; 		//ͼƬ���ṹ
	NET_VCA_ONE_RULE  struRule[MAX_RULE_NUM];  //��������
}NET_VCA_RULECFG, *LPNET_VCA_RULECFG;

//��Ŀ��ṹ��
typedef struct tagNET_VCA_TARGET_INFO
{
	DWORD    dwID;				//Ŀ��ID ,��Ա�ۼ����߱���ʱΪ0
	NET_VCA_RECT struRect;      //Ŀ��߽�� 
    BYTE      byRes[4];			//����
}NET_VCA_TARGET_INFO, *LPNET_VCA_TARGET_INFO;

//�򻯵Ĺ�����Ϣ, ��������Ļ�����Ϣ
typedef struct tagNET_VCA_RULE_INFO
{
	BYTE   byRuleID;		    //����ID,0-7
	BYTE   byRes[3];			//����
    BYTE   byRuleName[NAME_LEN]; //��������
	VCA_EVENT_TYPE  dwEventType; //�����¼�����
    NET_VCA_EVENT_UNION uEventParam;//�¼�����
}NET_VCA_RULE_INFO, *LPNET_VCA_RULE_INFO;

//ǰ���豸��ַ��Ϣ�����ܷ����Ǳ�ʾ����ǰ���豸�ĵ�ַ��Ϣ�������豸��ʾ�����ĵ�ַ
typedef struct tagNET_VCA_DEV_INFO
{
	NET_DVR_IPADDR  struDevIP; //ǰ���豸��ַ�� 
	WORD wPort; 			//ǰ���豸�˿ںţ� 
	BYTE byChannel;  		//ǰ���豸ͨ���� 
    BYTE byIvmsChannel;		// Ivms ͨ�� 
} NET_VCA_DEV_INFO, *LPNET_VCA_DEV_INFO;

//��Ϊ��������ϱ��ṹ
typedef struct  tagNET_VCA_RULE_ALARM
{
	DWORD    dwSize;						//�ṹ����
	DWORD    dwRelativeTime;				//���ʱ��
	DWORD    dwAbsTime;						//����ʱ��
	NET_VCA_RULE_INFO     struRuleInfo;		//�¼�������Ϣ
	NET_VCA_TARGET_INFO  struTargetInfo;	//����Ŀ����Ϣ
	NET_VCA_DEV_INFO  	 struDevInfo;		//ǰ���豸��Ϣ
	DWORD dwPicDataLen;						//����ͼƬ�ĳ��� Ϊ0��ʾû��ͼƬ������0��ʾ�ýṹ�������ͼƬ����*/
    BYTE       byPicType;		//  0-��ͨͼƬ 1-�Ա�ͼƬ
    BYTE       byRes[3];		// �����ֽ�
    DWORD      dwRes[3];		/* ����������Ϊ0*/
	BYTE  *pImage;   						//ָ��ͼƬ��ָ��
}NET_VCA_RULE_ALARM, *LPNET_VCA_RULE_ALARM;

//��Ϊ��������DSP��Ϣ���ӽṹ
typedef struct tagNET_VCA_DRAW_MODE
{ 
	DWORD  dwSize;
	BYTE	byDspAddTarget;			//�����Ƿ����Ŀ��
	BYTE    byDspAddRule;			//�����Ƿ���ӹ���
	BYTE	byDspPicAddTarget;		//ץͼ�Ƿ����Ŀ��
	BYTE	byDspPicAddRule;		//ץͼ�Ƿ���ӹ���
	BYTE	byRes[4];			
}NET_VCA_DRAW_MODE, *LPNET_VCA_DRAW_MODE;

//�궨���ӽṹ
typedef struct tagNET_DVR_CB_POINT
{
	NET_VCA_POINT struPoint;     //�궨�㣬���������ǹ����
	NET_DVR_PTZPOS struPtzPos;  //��������PTZ����
	BYTE	byRes[8];
}NET_DVR_CB_POINT, LPNET_DVR_CB_POINT;

//�궨�������ýṹ
typedef struct tagNET_DVR_TRACK_CALIBRATION_PARAM
{	
	BYTE byPointNum;			//��Ч�궨�����
	BYTE byRes[3];				
	NET_DVR_CB_POINT  struCBPoint[MAX_CALIB_PT]; //�궨����
}NET_DVR_TRACK_CALIBRATION_PARAM, *LPNET_DVR_TRACK_CALIBRATION_PARAM;

//������ýṹ
typedef struct tagNET_DVR_TRACK_CFG 
{	
	DWORD dwSize;				//�ṹ����	
    BYTE byEnable;				//�궨ʹ��
    BYTE byFollowChan;          // �����ƵĴ�ͨ��
    BYTE byDomeCalibrate;			//�������ܸ�������궨��1���� 0������ 
    BYTE byRes;					// �����ֽ�
	NET_DVR_TRACK_CALIBRATION_PARAM  struCalParam; //�궨����
}NET_DVR_TRACK_CFG, *LPNET_DVR_TRACK_CFG ;

//����ģʽ
typedef enum _TRACK_MODE_
{
	MANUAL_CTRL = 0,  //�ֶ�����
	ALARM_TRACK    //������������
}TRACK_MODE;

//�ֶ����ƽṹ
typedef struct tagNET_DVR_MANUAL_CTRL_INFO 
{
	NET_VCA_POINT struCtrlPoint;
	BYTE  byRes[8];
}NET_DVR_MANUAL_CTRL_INFO, *LPNET_DVR_MANUAL_CTRL_INFO ;

//����ģʽ�ṹ
typedef struct tagNET_DVR_TRACK_MODE
{
	DWORD dwSize;		//�ṹ����
	BYTE byTrackMode;   //����ģʽ
    BYTE byRuleConfMode;   //�������ø���ģʽ0-�������ø��٣�1-Զ�����ø���
    BYTE byRes[2];   //��������0
	union
	{
		DWORD dwULen[4];
		NET_DVR_MANUAL_CTRL_INFO  struManualCtrl;//�ֶ����ٽṹ
	}uModeParam;
}NET_DVR_TRACK_MODE,*LPNET_DVR_TRACK_MODE;

typedef struct tagNET_DVR_ALARM_JPEG
{
    BYTE    byPicProType;	    /*����ʱͼƬ������ʽ 0-������ 1-�ϴ�*/
    BYTE    byRes[3];           //�����ֽ�
    NET_DVR_JPEGPARA struPicParam; 				/*ͼƬ���ṹ*/
}NET_DVR_ALARM_JPEG, *LPNET_DVR_ALARM_JPEG;

//��������Ϊ��������ṹ
//�������ṹ
typedef struct tagNET_IVMS_ONE_RULE_
{
	BYTE    byActive;           /* �Ƿ񼤻����,0-��, ��0-�� */
	BYTE	byRes1[7];	//����������Ϊ0�ֶ�
	BYTE   byRuleName[NAME_LEN]; //��������
	VCA_EVENT_TYPE dwEventType;   //��Ϊ�����¼�����
    NET_VCA_EVENT_UNION uEventParam;//��Ϊ�����¼�����
    NET_VCA_SIZE_FILTER  struSizeFilter;  //�ߴ������
	BYTE byRes2[68]; /*����������Ϊ0*/
}NET_IVMS_ONE_RULE, *LPNET_IVMS_ONE_RULE;

// �����ǹ���ṹ
typedef struct tagNET_IVMS_RULECFG
{
	NET_IVMS_ONE_RULE  struRule[MAX_RULE_NUM];   //��������
}NET_IVMS_RULECFG, *LPNET_IVMS_RULECFG;

// IVMS��Ϊ�������ýṹ
typedef struct tagNET_IVMS_BEHAVIORCFG
{
    DWORD dwSize;
	BYTE    byPicProType;	    //����ʱͼƬ������ʽ 0-������ ��0-�ϴ�
	BYTE    byRes[3];
	NET_DVR_JPEGPARA struPicParam; 				//ͼƬ���ṹ
	NET_IVMS_RULECFG struRuleCfg[MAX_DAYS][MAX_TIMESEGMENT];//ÿ��ʱ��ζ�Ӧ����
} NET_IVMS_BEHAVIORCFG, *LPNET_IVMS_BEHAVIORCFG;

//���ܷ�����ȡ���ƻ��ӽṹ
typedef struct tagNET_IVMS_DEVSCHED
{
	NET_DVR_SCHEDTIME 	struTime;       //ʱ�����
	NET_DVR_PU_STREAM_CFG struPUStream; //ǰ��ȡ������
}NET_IVMS_DEVSCHED, *LPNET_IVMS_DEVSCHED;

//���ܷ����ǲ������ýṹ
typedef struct tagNET_IVMS_STREAMCFG
{
    DWORD dwSize;
	NET_IVMS_DEVSCHED	struDevSched[MAX_DAYS][MAX_TIMESEGMENT];//��ʱ�������ǰ��ȡ���Լ�������Ϣ
} NET_IVMS_STREAMCFG, *LPNET_IVMS_STREAMCFG;

//��������
typedef struct tagNET_VCA_MASK_REGION
{
    BYTE byEnable;			//�Ƿ񼤻�, 0-�񣬷�0-��
	BYTE byRes[3];         //��������0
	NET_VCA_POLYGON  struPolygon; //���ζ����
}NET_VCA_MASK_REGION, * LPNET_VCA_MASK_REGION;

//�������������ṹ
typedef struct tagNET_VCA_MASK_REGION_LIST
{
	DWORD dwSize;     //�ṹ����
	BYTE byRes[4];     //��������0
	NET_VCA_MASK_REGION  struMask[MAX_MASK_REGION_NUM]; //������������
}NET_VCA_MASK_REGION_LIST, *LPNET_VCA_MASK_REGION_LIST;


//ATM�����������
typedef struct tagNET_VCA_ENTER_REGION//��ֹ����ATM���
{
	DWORD dwSize;
    BYTE byEnable;			//�Ƿ񼤻0-�񣬷�0-��
	BYTE byRes1[3];
	NET_VCA_POLYGON  struPolygon; //��������
	BYTE byRes2[16];
}NET_VCA_ENTER_REGION, * LPNET_VCA_ENTER_REGION;

//IVMS������������
typedef struct tagNET_IVMS_MASK_REGION_LIST
{
	DWORD dwSize;    //�ṹ����
	NET_VCA_MASK_REGION_LIST struList[MAX_DAYS][ MAX_TIMESEGMENT];
}NET_IVMS_MASK_REGION_LIST, *LPNET_IVMS_MASK_REGION_LIST;

//IVMS��ATM�����������
typedef struct tagNET_IVMS_ENTER_REGION
{
	DWORD dwSize;
	NET_VCA_ENTER_REGION  struEnter[MAX_DAYS][ MAX_TIMESEGMENT]; //��������
}NET_IVMS_ENTER_REGION, *LPNET_IVMS_ENTER_REGION;

// ivms ����ͼƬ�ϴ��ṹ
typedef struct tagNET_IVMS_ALARM_JPEG
{
    BYTE                byPicProType;               
    BYTE                byRes[3];
    NET_DVR_JPEGPARA      struPicParam;     
}NET_IVMS_ALARM_JPEG, *LPNET_IVMS_ALARM_JPEG;

// IVMS ���������
typedef struct tagNET_IVMS_SEARCHCFG
{
    DWORD                        dwSize;
    NET_DVR_MATRIX_DEC_REMOTE_PLAY struRemotePlay;// Զ�̻ط�
    NET_IVMS_ALARM_JPEG         struAlarmJpeg; // �����ϴ�ͼƬ����
    NET_IVMS_RULECFG           struRuleCfg;   //IVMS ��Ϊ��������
}NET_IVMS_SEARCHCFG, *LPNET_IVMS_SEARCHCFG;
/************************************end******************************************/

//����Ӳ�̽ṹ����
typedef struct tagNET_DVR_SINGLE_NET_DISK_INFO
{
	BYTE byNetDiskType;						//����Ӳ������, 0-NFS,1-iSCSI
	BYTE byRes1[3];							//����
    NET_DVR_IPADDR struNetDiskAddr;			//����Ӳ�̵�ַ
    BYTE sDirectory[PATHNAME_LEN];			// PATHNAME_LEN = 128
	WORD wPort;							    //iscsi�ж˿ڣ�����ΪĬ��
	BYTE byRes2[66];							//����
}NET_DVR_SINGLE_NET_DISK_INFO, *LPNET_DVR_SINGLE_NET_DISK_INFO;

#define MAX_NET_DISK	16//�������Ӳ�̸���

typedef struct tagNET_DVR_NET_DISKCFG 
{
    DWORD  dwSize;
    NET_DVR_SINGLE_NET_DISK_INFO struNetDiskParam[MAX_NET_DISK];
}NET_DVR_NET_DISKCFG, *LPNET_DVR_NET_DISKCFG;

//�¼�����
//������
typedef enum _MAIN_EVENT_TYPE_
{
	EVENT_MOT_DET = 0,		//�ƶ����
	EVENT_ALARM_IN = 1,		//��������
	EVENT_VCA_BEHAVIOR = 2,	// ��Ϊ����
//     EVENT_VCA_ITS     = 3      // ��ͨ�¼�     
}MAIN_EVENT_TYPE;

//��Ϊ���������Ͷ�Ӧ�Ĵ����ͣ� 0xffff��ʾȫ��
typedef enum _BEHAVIOR_MINOR_TYPE_
{
	EVENT_TRAVERSE_PLANE     = 0,    // ��Խ������
	EVENT_ENTER_AREA,				//Ŀ���������,֧���������
	EVENT_EXIT_AREA,				//Ŀ���뿪����,֧���������
	EVENT_INTRUSION,				 // �ܽ�����,֧���������
	EVENT_LOITER,				 //�ǻ�,֧���������
	EVENT_LEFT_TAKE,				//��Ʒ������ȡ,֧���������
	EVENT_PARKING,					//ͣ��,֧���������
	EVENT_RUN,					//�����ƶ�,֧���������
	EVENT_HIGH_DENSITY,				 //��������Ա�ۼ�,֧���������
    EVENT_STICK_UP,				//��ֽ��,֧���������
    EVENT_INSTALL_SCANNER,				//��װ������,֧���������
    EVENT_OPERATE_OVER_TIME,        // ������ʱ
    EVENT_FACE_DETECT,              // �쳣����
    EVENT_LEFT,                     // ��Ʒ����
    EVENT_TAKE                      // ��Ʒ��ȡ
}BEHAVIOR_MINOR_TYPE;

// typedef enum tagITS_MINOR_TYPE
// {
//     ITS_EVENT_CONGESTION    = 0,    // ӵ��
//     ITS_EVENT_PARKING,              // ͣ��
//     ITS_EVENT_INVERSE,              // ����
//     ITS_EVENT_PEDESTRIAN,           // ����
//     ITS_EVENT_DEBRIS                // �������������Ƭ
// }ITS_MINOR_TYPE;

#define SEARCH_EVENT_INFO_LEN 300	//�¼���Ϣ����

//�¼���������
typedef struct tagNET_DVR_SEARCH_EVENT_PARAM
{
	WORD wMajorType;			//0-�ƶ���⣬1-��������, 2-�����¼�
	WORD wMinorType;			//����������- ���������ͱ仯��0xffff��ʾȫ��
	NET_DVR_TIME struStartTime;	//�����Ŀ�ʼʱ�䣬ֹͣʱ��: ͬʱΪ(0, 0) ��ʾ�������ʱ�俪ʼ���������ǰ���4000���¼�
	NET_DVR_TIME struEndTime;	//
	BYTE byRes[132];			//����
	union	
	{
		BYTE byLen[SEARCH_EVENT_INFO_LEN];		  
		struct//��������
		{
			BYTE byAlarmInNo[MAX_ALARMIN_V30];    //��������ţ�byAlarmInNo[0]����1���ʾ�����ɱ�������1�������¼�
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_ALARMIN_V30];
		}struAlarmParam;
		struct//�ƶ����
		{
			BYTE byMotDetChanNo[MAX_CHANNUM_V30];//�ƶ����ͨ����byMotDetChanNo[0]����1���ʾ������ͨ��1�����ƶ���ⴥ�����¼�
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_CHANNUM_V30];
		}struMotionParam;
		struct//��Ϊ����
		{
			BYTE byChanNo[MAX_CHANNUM_V30];	//�����¼���ͨ��
			BYTE byRuleID;					//����ID��0xff��ʾȫ��
			BYTE byRes1[43];				//����
		}struVcaParam;
//         struct
//         {
//             BYTE    byChanNo[MAX_CHANNUM_V30];
//             BYTE    byAidRuleID;    // ��ͨ�¼� ����ID��0xff��ʾȫ�� 
//             BYTE    byRes[199];
//         }struITSParam;
	}uSeniorParam;
}NET_DVR_SEARCH_EVENT_PARAM, *LPNET_DVR_SEARCH_EVENT_PARAM;

//���ҷ��ؽ��
typedef struct tagNET_DVR_SEARCH_EVENT_RET
{
	WORD wMajorType;			//������
	WORD wMinorType;			//������
	NET_DVR_TIME struStartTime;	//�¼���ʼ��ʱ��
	NET_DVR_TIME struEndTime;   //�¼�ֹͣ��ʱ�䣬�����¼�ʱ�Ϳ�ʼʱ��һ��
	BYTE byChan[MAX_CHANNUM_V30];	
	BYTE byRes[36];
	union		
	{
		struct//����������
		{
			DWORD dwAlarmInNo;     //���������
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struAlarmRet;
		struct//�ƶ������
		{
			DWORD dwMotDetNo;	//�ƶ����ͨ��
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struMotionRet;
		struct//��Ϊ�������  
		{
			DWORD dwChanNo;					//�����¼���ͨ����
			BYTE byRuleID;					//����ID
			BYTE byRes1[3];					//����
			BYTE byRuleName[NAME_LEN];		//��������
			NET_VCA_EVENT_UNION uEvent;     //��Ϊ�¼�����
		}struVcaRet;
	}uSeniorRet;
}NET_DVR_SEARCH_EVENT_RET, *LPNET_DVR_SEARCH_EVENT_RET;

//SDK_V35  2009-10-26

// �궨��������
typedef enum tagCALIBRATE_TYPE
{
    PDC_CALIBRATE  = 0x01,  // PDC �궨
    BEHAVIOR_OUT_CALIBRATE  = 0x02, //��Ϊ���ⳡ���궨  
    BEHAVIOR_IN_CALIBRATE = 0x03,    // ��Ϊ���ڳ����궨 
    ITS_CALBIRETE       = 0x04      //  ��ͨ�¼��궨
}CALIBRATE_TYPE;

#define MAX_RECT_NUM  6
typedef struct tagNET_DVR_RECT_LIST
{	
    BYTE    byRectNum;    // ���ο�ĸ���
    BYTE    byRes1[11];  //�����ֽ� 
    NET_VCA_RECT struVcaRect[MAX_RECT_NUM]; // ���Ϊ6��Rect 
}NET_DVR_RECT_LIST, *LPNET_DVR_RECT_LIST;

// PDC �궨����
typedef struct tagNET_DVR_PDC_CALIBRATION
{
    NET_DVR_RECT_LIST struRectList;       // �궨���ο��б�
    BYTE           byRes[120];       // �����ֽ� 
}NET_DVR_PDC_CALIBRATION, *LPNET_DVR_PDC_CALIBRATION;


// �궨�ߵ��������������ʾ��ǰ�궨����ʵ�ʱ�ʾ���Ǹ߶��߻��ǳ����ߡ�
typedef enum tagLINE_MODE
{
    HEIGHT_LINE,        //�߶�������
    LENGTH_LINE        //����������
}LINE_MODE;
/*
�����ñ궨��Ϣ��ʱ�������Ӧλ������ʹ�ܣ���������ز�����
��û������ʹ�ܣ���궨����Ի�ȡ��ص����������
*/
typedef struct tagNET_DVR_CAMERA_PARAM
{
    BYTE    byEnableHeight;     // �Ƿ�ʹ������������߶���
    BYTE    byEnableAngle;      // �Ƿ�ʹ����������������Ƕ�
    BYTE    byEnableHorizon;    // �Ƿ�ʹ�������������ƽ��
    BYTE    byRes[5];   // �����ֽ� 
    float   fCameraHeight;    // ������߶�
    float   fCameraAngle;     // ����������Ƕ�
    float   fHorizon;         // �����еĵ�ƽ��
}NET_DVR_CAMERA_PARAM, *LPNET_DVR_CAMERA_PARAM;
/*
��fValue��ʾĿ��߶ȵ�ʱ��struStartPoint��struEndPoint�ֱ��ʾĿ��ͷ����ͽŲ��㡣
��fValue��ʾ�߶γ��ȵ�ʱ��struStartPoint��struEndPoint�ֱ��ʾ�߶���ʼ����յ㣬
mode��ʾ��ǰ�����߱�ʾ�߶��߻��ǳ����ߡ�
*/
typedef struct tagNET_DVR_LINE_SEGMENT
{
    BYTE            byLineMode;     // ���� LINE_MODE
    BYTE            byRes[3];       // �����ֽ� 
    NET_VCA_POINT   struStartPoint;  
    NET_VCA_POINT   struEndPoint;
    float           fValue;
}NET_DVR_LINE_SEGMENT, *LPNET_DVR_LINE_SEGMENT;

#define  MAX_LINE_SEG_NUM 8

/*
�궨������Ŀǰ��Ҫ4-8�������ߣ��Ի�ȡ�������ز���
*/
typedef struct tagNET_DVR_BEHAVIOR_OUT_CALIBRATION
{
    DWORD                   dwLineSegNum;          // �����߸���
    NET_DVR_LINE_SEGMENT    struLineSegment[MAX_LINE_SEG_NUM];    // ������������
    NET_DVR_CAMERA_PARAM    struCameraParam;    // ���������
    BYTE byRes[20];
}NET_DVR_BEHAVIOR_OUT_CALIBRATION, *LPNET_DVR_BEHAVIOR_OUT_CALIBRATION;

/*
�ýṹ���ʾIAS���ܿ�궨������
���а���һ��Ŀ����һ����Ӧ�ĸ߶ȱ궨�ߣ�
Ŀ���Ϊվ����������Ӿ��ο򣻸߶���������ʶ����ͷ���㵽�ŵ�ı궨�ߣ�
�ù�һ�������ʾ��
*/
typedef struct tagNET_DVR_IN_CAL_SAMPLE
{
    NET_VCA_RECT struVcaRect;   // Ŀ���
    NET_DVR_LINE_SEGMENT struLineSegment;    // �߶ȱ궨��
}NET_DVR_IN_CAL_SAMPLE, *LPNET_DVR_IN_CAL_SAMPLE;

#define  MAX_SAMPLE_NUM 5

typedef struct tagNET_DVR_BEHAVIOR_IN_CALIBRATION 
{
    DWORD    dwCalSampleNum;      //  �궨��������
    NET_DVR_IN_CAL_SAMPLE  struCalSample[MAX_SAMPLE_NUM]; // �궨����������
    NET_DVR_CAMERA_PARAM    struCameraParam;    // ���������
    BYTE byRes[16];
}NET_DVR_BEHAVIOR_IN_CALIBRATION, *LPNET_DVR_BEHAVIOR_IN_CALIBRATION;

#define  CALIB_PT_NUM 4
typedef struct tagNET_DVR_ITS_CALIBRATION
{
    unsigned int dwPointNum; //�궨����
    NET_VCA_POINT struPoint[CALIB_PT_NUM]; //ͼ������
    float       fWidth;
    float       fHeight;
    BYTE        byRes1[100];        // �����ֽ�
}NET_DVR_ITS_CALIBRATION, *LPNET_DVR_ITS_CALIBRATION;

// �궨����������
// ��������ر궨�������Է��ڸýṹ����
typedef union tagNET_DVR_CALIBRATION_PRARM_UNION
{
    BYTE byRes[240];                    //������ṹ��С
    NET_DVR_PDC_CALIBRATION struPDCCalibration;  //PDC �궨����
    NET_DVR_BEHAVIOR_OUT_CALIBRATION  struBehaviorOutCalibration;  //  ��Ϊ���ⳡ���궨  ��ҪӦ����IVS��
    NET_DVR_BEHAVIOR_IN_CALIBRATION  struBehaviorInCalibration;     // ��Ϊ���ڳ����궨����ҪӦ��IAS�� 
    NET_DVR_ITS_CALIBRATION struITSCalibration;
}NET_DVR_CALIBRATION_PRARM_UNION, *LPNET_DVR_CALIBRATION_PRARM_UNION;


// �궨���ýṹ
typedef struct tagNET_DVR_CALIBRATION_CFG
{
    DWORD   dwSize;               //�궨�ṹ��С
    BYTE    byEnable;           // �Ƿ����ñ궨
    BYTE    byCalibrationType;    // �궨���� ���ݲ�ͬ��������������ѡ��ͬ�ı궨 �ο�CALIBRATE_TYPE
    BYTE    byRes1[2];
    NET_DVR_CALIBRATION_PRARM_UNION uCalibrateParam;  // �궨����������
    BYTE    byRes2[12];
}NET_DVR_CALIBRATION_CFG, *LPNET_DVR_CALIBRATION_CFG; 

//����ͳ�Ʒ���ṹ��
typedef struct  tagNET_DVR_PDC_ENTER_DIRECTION
{
    NET_VCA_POINT struStartPoint; //����ͳ�Ʒ�����ʼ��
    NET_VCA_POINT struEndPoint;    // ����ͳ�Ʒ�������� 
}NET_DVR_PDC_ENTER_DIRECTION, *LPNET_DVR_PDC_ENTER_DIRECTION;

typedef struct tagNET_DVR_PDC_RULE_CFG
{
    DWORD           dwSize;              //�ṹ��С
    BYTE            byEnable;             // �Ƿ񼤻����;
    BYTE            byRes1[23];       // �����ֽ� 
    NET_VCA_POLYGON          struPolygon;            // �����
    NET_DVR_PDC_ENTER_DIRECTION  struEnterDirection;    // �������뷽��
} NET_DVR_PDC_RULE_CFG, *LPNET_DVR_PDC_RULE_CFG;

//����������ͳ�Ʋ���  ������Ϊ�ڲ��ؼ��ֲ��� 
// HUMAN_GENERATE_RATE
// Ŀ�������ٶȲ���������PDC������Ŀ����ٶȡ��ٶ�Խ�죬Ŀ��Խ�������ɡ���������Ƶ���������ϲ�ԱȶȽϵ�ʱ���������õĹ��������Сʱ��Ӧ�ӿ�Ŀ�������ٶȣ� ����Ŀ���©�죻��������Ƶ�жԱȶȽϸ�ʱ�����߹�������ϴ�ʱ��Ӧ�ý���Ŀ�������ٶȣ��Լ�����졣Ŀ�������ٶȲ�������5����1���ٶ�������5����죬Ĭ�ϲ���Ϊ3��
// 
// DETECT_SENSITIVE
// Ŀ���������ȿ��Ʋ���������PDC����һ���������򱻼��ΪĿ��������ȡ�������Խ�ߣ���������Խ���ױ����ΪĿ�꣬������Խ����Խ�Ѽ��ΪĿ�ꡣ��������Ƶ���������ϲ�ԱȶȽϵ�ʱ��Ӧ��߼�������ȣ� ����Ŀ���©�죻��������Ƶ�жԱȶȽϸ�ʱ��Ӧ�ý��ͼ�������ȣ��Լ�����졣��Ӧ��������5��������1��������ͣ�5����ߣ�Ĭ�ϼ���Ϊ3��
// TRAJECTORY_LEN
// �켣���ɳ��ȿ��Ʋ�������ʾ���ɹ켣ʱҪ��Ŀ������λ�����ء���Ӧ��������5��������1�����ɳ�������켣����������5�����ɳ�����̣��켣������죬Ĭ�ϼ���Ϊ3��
// TRAJECT_CNT_LEN
// �켣�������ȿ��Ʋ�������ʾ�켣����ʱҪ��Ŀ������λ�����ء���Ӧ��������5��������1������Ҫ�󳤶�����켣����������5������Ҫ�󳤶���̣��켣������죬Ĭ�ϼ���Ϊ3��
// PREPROCESS
// ͼ��Ԥ�������Ʋ�����0 - ��������1 - ������Ĭ��Ϊ0��
// CAMERA_ANGLE
// ������Ƕ���������� 0 - ��б�� 1 - ��ֱ��Ĭ��Ϊ0��
typedef enum tagPDC_PARAM_KEY
{
    HUMAN_GENERATE_RATE = 50,              // Ŀ�������ٶ� ��50��ʼ
    DETECT_SENSITIVE    = 51,               // ���������
}PDC_PARAM_KEY;

typedef struct tagNET_DVR_PDC_TARGET_INFO
{
    DWORD       dwTargetID;                 // Ŀ��id 
    NET_VCA_RECT struTargetRect;               // Ŀ���
    BYTE      byRes1[8];        // �����ֽ�
}NET_DVR_PDC_TARGET_INFO, *LPNET_DVR_PDC_TARGET_INFO;

typedef struct tagNET_DVR_PDC_TARGET_IN_FRAME
{
    BYTE           byTargetNum;                   //Ŀ�����
    BYTE            byRes1[3];
        NET_DVR_PDC_TARGET_INFO  struTargetInfo[MAX_TARGET_NUM];   //Ŀ����Ϣ����
    BYTE    byRes2[8];                  // �����ֽ�
}NET_DVR_PDC_TARGET_IN_FRAME, *LPNET_DVR_PDC_TARGET_IN_FRAME;

typedef struct tagNET_DVR_PDC_ALRAM_INFO
{
    DWORD                       dwSize;           // PDC�����������ϴ��ṹ���С
    BYTE                        byMode;            // 0 ��֡ͳ�ƽ�� 1��Сʱ���ͳ�ƽ��  
    BYTE                        byChannel;           // �����ϴ�ͨ����
    BYTE                        byRes1[2];         // �����ֽ�   
    NET_VCA_DEV_INFO  	 struDevInfo;		        //ǰ���豸��Ϣ
    union		
    {
        struct   // ��֡ͳ�ƽ��ʱʹ��
        {
            DWORD   dwRelativeTime;     // ���ʱ��
            DWORD   dwAbsTime;          // ����ʱ��
            BYTE    byRes[92];            
        }struStatFrame;
        struct
        {
            NET_DVR_TIME                      tmStart; // ͳ����ʼʱ�� 
            NET_DVR_TIME                      tmEnd;  //  ͳ�ƽ���ʱ�� 
            BYTE byRes[92];
        }struStatTime;
    }uStatModeParam;  // ��Ϊһ�������� ��֡��ʱ�����֡��Ŀ����Ϣ ��Сʱ���ͳ�ƽ����Ҫͳ��ʱ�� ����
    DWORD                       dwLeaveNum;        // �뿪����
    DWORD                       dwEnterNum;        // ��������
    BYTE                        byRes2[40];           // �����ֽ�
}NET_DVR_PDC_ALRAM_INFO, *LPNET_DVR_PDC_ALRAM_INFO;


//  ��������Ϣ��ѯ 
typedef struct tagNET_DVR_PDC_QUERY
{
    NET_DVR_TIME tmStart;
    NET_DVR_TIME tmEnd;
    DWORD       dwLeaveNum;
    DWORD        dwEnterNum; 
    BYTE        byRes1[256];
}NET_DVR_PDC_QUERY, *LPNET_DVR_PDC_QUERY;

typedef struct    tagNET_DVR_PTZ_POSITION
{
    // �Ƿ����ó����������ó�����Ϊ�����ʱ����ֶ���Ч������������������ó���λ����Ϣʱ��Ϊʹ��λ
    BYTE byEnable;
    BYTE byRes1[3];  //����
    BYTE byPtzPositionName[NAME_LEN]; //����λ������
    NET_DVR_PTZPOS struPtzPos; //ptz ����
    BYTE byRes2[40];
}NET_DVR_PTZ_POSITION, *LPNET_DVR_PTZ_POSITION;

typedef struct tagNET_DVR_POSITION_RULE_CFG
{
    DWORD                   dwSize;             // �ṹ��С 
    NET_DVR_PTZ_POSITION    struPtzPosition;    // ����λ����Ϣ
    NET_VCA_RULECFG         struVcaRuleCfg;     //��Ϊ��������
    BYTE                    byRes2[80];         // �����ֽ�
}NET_DVR_POSITION_RULE_CFG, *LPNET_DVR_POSITION_RULE_CFG;

/******************************************
����:	NET_DVR_GetPositionRule
����:	��ȡ����λ�ù�����Ϣ
����:	lUserID     NET_DVR_Login_V30����ֵ
        lChannel    ͨ����
        lPositionIndex ��������(Ŀǰ�豸֧��10������)
        lpPositionRuleָ��NET_DVR_POSITION_RULE_CFG�ṹָ��
���:	��
����ֵ: �ɹ�-TRUE   ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);

/******************************************
����:	NET_DVR_SetPositionRule
����:	���ó���λ�ù�����ϢTRAFFIC_SCENE_MODE
����:	lUserID     NET_DVR_Login_V30����ֵ
        lChannel    ͨ����
        lPositionIndex ��������(Ŀǰ�豸֧��10������)
        lpPositionRuleָ��NET_DVR_POSITION_RULE_CFG�ṹָ��
���:	lpPositionRuleָ��NET_DVR_POSITION_RULE_CFG�ṹָ��
����ֵ: �ɹ�-TRUE   ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);

typedef struct tagNET_DVR_LIMIT_ANGLE
{
    BYTE                byEnable;	// �Ƿ����ó�����λ����
    BYTE				byRes1[3];
    NET_DVR_PTZPOS      struUp;     // ����λ
    NET_DVR_PTZPOS      struDown;   // ����λ
    NET_DVR_PTZPOS      struLeft;   // ����λ
    NET_DVR_PTZPOS      struRight;  // ����λ
    BYTE                byRes2[20];
}NET_DVR_LIMIT_ANGLE, *LPNET_DVR_LIMIT_ANGLE;

/******************************************
����:	NET_DVR_SetPositionLimitAngle
����:	���ó���������λ����
����:	lUserID     NET_DVR_Login_V30����ֵ
        lChannel    ͨ����
        lPositionIndex ��������(Ŀǰ�豸֧��10������)
        lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
���:	��
����ֵ: �ɹ�-TRUE   ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/******************************************
����:	NET_DVR_GetPositionLimitAngle
����:	��ȡ����������λ����
����:	lUserID     NET_DVR_Login_V30����ֵ
        lChannel    ͨ����
        lPositionIndex ��������(Ŀǰ�豸֧��10������)
        lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
���:	lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
����ֵ: �ɹ�-TRUE   ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

typedef struct tagNET_DVR_POSITION_INDEX
{
    BYTE    byIndex;    // ��������
    BYTE    byRes1;
    WORD	wDwell;	// ͣ��ʱ�� 
    BYTE    byRes2[4];   // �����ֽ�
}NET_DVR_POSITION_INDEX, *LPNET_DVR_POSITION_INDEX;

#define  MAX_POSITION_NUM 10
typedef struct tagNET_DVR_POSITION_TRACK_CFG
{
    DWORD dwSize;
    BYTE    byNum; // ��������
    BYTE    byRes1[3];
    NET_DVR_POSITION_INDEX   struPositionIndex[MAX_POSITION_NUM];
    BYTE    byRes2[8];
}NET_DVR_POSITION_TRACK_CFG, *LPNET_DVR_POSITION_TRACK_CFG;

//Ѳ��·��������Ϣ
typedef struct tagNET_DVR_PATROL_SCENE_INFO
{
    WORD   wDwell;         // ͣ��ʱ�� 30-300
    BYTE   byPositionID;   // ������1-10��Ĭ��0��ʾ��Ѳ���㲻���ӳ���
    BYTE   byRes[5];
}NET_DVR_PATROL_SCENE_INFO, *LPNET_DVR_PATROL_SCENE_INFO;

// ����Ѳ������������Ϣ
typedef struct tagNET_DVR_PATROL_TRACKCFG
{
    DWORD  dwSize;                                 // �ṹ��С
    NET_DVR_PATROL_SCENE_INFO struPatrolSceneInfo[10];    // Ѳ��·��
    BYTE   byRes[16];                              // �����ֽ�
}NET_DVR_PATROL_TRACKCFG, *LPNET_DVR_PATROL_TRACKCFG;

//������ع���˵����ýṹ��
typedef struct tagNET_DVR_TRACK_PARAMCFG
{
    DWORD   dwSize;             // �ṹ��С
    WORD    wAlarmDelayTime;    // ������ʱʱ�䣬Ŀǰ���ֻ֧��ȫ������ ��Χ1-120��
    WORD    wTrackHoldTime;     // �������ٳ���ʱ��  ��Χ0-300��
    BYTE    byTrackMode;        //  ���� IPDOME_TRACK_MODE
    BYTE	 byPreDirection;	// ���ٷ���Ԥ�� 0-������ 1-����
    BYTE 	 byTrackSmooth;	    // ��������  0-������ 1-����
    BYTE	 byZoomAdjust;	// ����ϵ������ �μ��±�
    BYTE	byMaxTrackZoom;	// �����ٱ���ϵ��  0 ��ʾĬ�ϱ���ϵ�� ������о�����й�
    BYTE   byRes[11];          //  �����ֽ�                
}NET_DVR_TRACK_PARAMCFG, *LPNET_DVR_TRACK_PARAMCFG;
// ����ϵ��ֵ�����ʹ�ϵ���±�
// �ȼ�	��������
// �أ�0��	�궨ֵ
// 1	�궨ֵ*0.5
// 2	�궨ֵ*0.65
// 3	�궨ֵ*0.75
// 4	�궨ֵ*0.9
// 5	�궨ֵ*1.1
// 6	�궨ֵ*1.2
// 7	�궨ֵ*1.3

// �����о����
typedef struct tagNET_DVR_DOME_MOVEMENT_PARAM
{
    WORD wMaxZoom;   // ��������ϵ��
    BYTE    byRes[42];  // �����ֽ�
}NET_DVR_DOME_MOVEMENT_PARAM, *LPNET_DVR_DOME_MOVEMENT_PARAM;

/******************************************
����:	NET_DVR_GetPtzPosition
����:   ��ȡ������س���PTZλ����Ϣ
����:	lUserID NET_DVR_Login_v30����ֵ
        lChannel ͨ����
        lPositionID ����λ��ID
        lpPtzPosition ָ��NET_DVR_PTZ_POSITION�ṹָ��
���:	lpPtzPosition ָ��NET_DVR_PTZ_POSITION�ṹָ��
����ֵ: TRUE--�ɹ� FALSE--ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);

/******************************************
����:	NET_DVR_SetPtzPosition
����:	��ȡ������س���PTZλ����Ϣ
����:	lUserID NET_DVR_Login_v30����ֵ
        lChannel ͨ����
        lPositionID ����λ��ID
        lpPtzPosition ָ��NET_DVR_PTZ_POSITION�ṹָ��
���:	
����ֵ: TRUE--�ɹ� FALSE--ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);

/******************************************
����:	NET_DVR_SetPatrolTrack
����:	���ó���Ѳ����������
����:	lUserID NET_DVR_Login_V30����ֵ
        lChannel ͨ����
        lPatrolIndex Ѳ������
        lpPatrolTrack ָ��NET_DVR_PATROL_TRACKCFG�ṹִ��
���:	
����ֵ: TRUE--�ɹ� FALSE--ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

/******************************************
����:	NET_DVR_GetPatrolTrack
����:	��ȡ����Ѳ����������
����:	lUserID NET_DVR_Login_V30����ֵ
        lChannel ͨ����
        lPatrolIndex Ѳ������
        lpPatrolTrack ָ��NET_DVR_PATROL_TRACKCFG�ṹִ��
���:   lpPatrolTrack ָ��NET_DVR_PATROL_TRACKCFG�ṹִ��
����ֵ: TRUE--�ɹ� FALSE--ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

/******************************************
����:	NET_DVR_SetPatrolLimitAngle
����:	���ó���Ѳ��������λ
����:	lUserID NET_DVR_Login_V30����ֵ
        lChannel ͨ����
        lPatrolIndex Ѳ������
        lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
���:	��
����ֵ: TRUE-�ɹ� FALSE-ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/******************************************
����:	NET_DVR_GetPatrolLimitAngle
����:	��ȡ����Ѳ������
����:	lUserID NET_DVR_Login_V30����ֵ
        lChannel ͨ����
        lPatrolIndex Ѳ������
        lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
���:	lpLimitAngle ָ��NET_DVR_LIMIT_ANGLE�ṹ��ָ��
����ֵ: TRUE-�ɹ� FALSE-ʧ��
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/********************************���ܽ�ͨ�¼� begin****************************************/
#define  MAX_REGION_NUM			8       // �����б������Ŀ
#define  MAX_TPS_RULE			8       // ������������Ŀ
#define  MAX_AID_RULE			8      // ����¼�������Ŀ
#define  MAX_LANE_NUM			8		// ��󳵵���Ŀ

//��ͨ�¼����ͣ�
typedef enum tagTRAFFIC_AID_TYPE
{
    CONGESTION          = 0x01,    //ӵ��
    PARKING             = 0x02,    //ͣ��  
    INVERSE             = 0x04,    //����
    PEDESTRIAN          = 0x08,    //����                      
    DEBRIS              = 0x10,    //������ ��������Ƭ 
    SMOKE                = 0x20     //����  
}TRAFFIC_AID_TYPE;

typedef enum tagTRAFFIC_SCENE_MODE
{
	FREEWAY = 0,	//  ���ٻ��ⳡ��
	TUNNEL,         //  ������������
	BRIDGE          //  ������������
}TRAFFIC_SCENE_MODE;

typedef enum tagITS_ABILITY_TYPE
{
    ITS_CONGESTION_ABILITY = 0x01,      //ӵ��
    ITS_PARKING_ABILITY = 0x02,      //ͣ��  
    ITS_INVERSE_ABILITY                = 0x04,      //����
    ITS_PEDESTRIAN_ABILITY             = 0x08,      //����                      
    ITS_DEBRIS_ABILITY                 = 0x10,      //������ ��������Ƭ
    ITS_SMOKE_ABILITY                    = 0x20,      //����-����

    ITS_LANE_VOLUME_ABILITY            = 0x010000,  //��������
    ITS_LANE_VELOCITY_ABILITY          = 0x020000,  //����ƽ���ٶ�
    ITS_TIME_HEADWAY_ABILITY           = 0x040000,  //��ͷʱ��
    ITS_SPACE_HEADWAY_ABILITY          = 0x080000,  //��ͷ���
    ITS_TIME_OCCUPANCY_RATIO_ABILITY   = 0x100000,  //����ռ���ʣ���ʱ����)
    ITS_SPACE_OCCUPANCY_RATIO_ABILITY  = 0x200000,  //����ռ���ʣ��ٷֱȼ��㣨�ռ���)
    ITS_LANE_QUEUE_ABILITY             = 0x400000   //�Ŷӳ���
}ITS_ABILITY_TYPE;

// ��ͨͳ�Ʋ���
typedef enum tagITS_TPS_TYPE
{
    LANE_VOLUME           = 0x01,    //��������
    LANE_VELOCITY         = 0x02,    //�����ٶ�
    TIME_HEADWAY          = 0x04,    //��ͷʱ��
    SPACE_HEADWAY         = 0x08,    //��ͷ���
    TIME_OCCUPANCY_RATIO  = 0x10,    //����ռ���� (ʱ����)
    SPACE_OCCUPANCY_RATIO = 0x20,    //����ռ���ʣ��ٷֱȼ���(�ռ���)
    QUEUE                 = 0x40     //�Ŷӳ���
}ITS_TPS_TYPE; 

typedef struct tagNET_DVR_REGION_LIST 
{
	DWORD	dwSize;	// �ṹ���С
	BYTE    byNum;      // �������
	BYTE    byRes1[3];    // �����ֽ�
	NET_VCA_POLYGON struPolygon[MAX_REGION_NUM]; // ����
	BYTE	byRes2[20];	// �����ֽ�
}NET_DVR_REGION_LIST,*LPNET_DVR_REGION_LIST;


// ����ṹ��
typedef struct tagNET_DVR_DIRECTION
{
    NET_VCA_POINT struStartPoint;   // ������ʼ��
    NET_VCA_POINT struEndPoint;     // ��������� 
}NET_DVR_DIRECTION, *LPNET_DVR_DIRECTION;

// ��������
typedef struct tagNET_DVR_ONE_LANE
{
	BYTE	byEnable; // �����Ƿ�����
	BYTE	byRes1[11];	// �����ֽ�
	BYTE    byLaneName[NAME_LEN];       // ������������
	NET_DVR_DIRECTION struFlowDirection;	// �����ڳ�������
	NET_VCA_POLYGON struPolygon;		// ��������
}NET_DVR_ONE_LANE, *LPNET_DVR_ONE_LANE;

// ��������
typedef struct tagNET_DVR_LANE_CFG
{
	DWORD	dwSize;	// �ṹ���С
	NET_DVR_ONE_LANE struLane[MAX_LANE_NUM];	// �������� �����±���Ϊ����ID��
	BYTE	byRes1[40];	 // �����ֽ�
}NET_DVR_LANE_CFG, *LPNET_DVR_LANE_CFG;

// ��ͨ�¼�����
typedef struct tagNET_DVR_AID_PARAM
{
	WORD    wParkingDuration;       // ͣ������ʱ�� 10-120s
	WORD    wPedestrianDuration;    // ���˳���ʱ�� 1-120s
	WORD    wDebrisDuration;        // ���������ʱ�� 10-120s
	WORD    wCongestionLength;      // ӵ�³�����ֵ  ��Χ��5-200���ף�
	WORD    wCongestionDuration;    // ӵ�³������� 10-120s
	WORD    wInverseDuration;       // ���г���ʱ�� 1-10s
	WORD    wInverseDistance;       // ���о�����ֵ ��λm ��Χ[2-100] Ĭ�� 10��
	WORD    wInverseAngleTolerance; // �����Ƕ�ƫ�� 90-180��  ���������������ļн�
	BYTE    byRes1[28];             //  �����ֽ�
}NET_DVR_AID_PARAM, *LPNET_DVR_AID_PARAM;

// ������ͨ�¼�����ṹ��
typedef struct tagNET_DVR_ONE_AID_RULE
{   
    BYTE    byEnable;   // �Ƿ������¼�����
    BYTE    byRes1[3];  // �����ֽ�
    BYTE    byRuleName[NAME_LEN];   // �������� 
    DWORD   dwEventType;    // ��ͨ�¼�������� TRAFFIC_AID_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; // �ߴ������
    NET_VCA_POLYGON     struPolygon;    // ��������
    NET_DVR_AID_PARAM struAIDParam; //  �¼�����
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//����ʱ��
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //������ʽ 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//����������¼��ͨ��,Ϊ1��ʾ������ͨ��
    BYTE    byRes2[20];
}NET_DVR_ONE_AID_RULE, *LPNET_DVR_ONE_AID_RULE;

// ��ͨ�¼�����
typedef struct tagNET_DVR_AID_RULECFG
{
    DWORD   dwSize;     // �ṹ���С 
    BYTE    byPicProType;	//����ʱͼƬ������ʽ 0-������ ��0-�ϴ�
    BYTE    byRes1[3];  // �����ֽ�
    NET_DVR_JPEGPARA struPictureParam; 		//ͼƬ���ṹ
    NET_DVR_ONE_AID_RULE  struOneAIDRule[MAX_AID_RULE];
    BYTE    byRes2[32];
}NET_DVR_AID_RULECFG, *LPNET_DVR_AID_RULECFG;

// ��ͨͳ�Ʋ����ṹ��
typedef struct tagNET_DVR_ONE_TPS_RULE
{
    BYTE    byEnable;       // �Ƿ�ʹ�ܳ�����ͨ�������
	BYTE	byLaneID;		// ����ID
    BYTE    byRes1[2];
    DWORD   dwCalcType;     // ͳ�Ʋ�������ITS_TPS_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; // �ߴ������ 
    NET_VCA_POLYGON struVitrualLoop;    // ������Ȧ
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//����ʱ��
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	//������ʽ һ��Ϊ�����Ƿ��ϴ����ģ��������ܲ���Ҫ
    BYTE    byRes2[20];  // �����ֽ�
}NET_DVR_ONE_TPS_RULE, *LPNET_DVR_ONE_TPS_RULE;

// ��ͨ����ͳ�ƹ������ýṹ��
typedef struct tagNET_DVR_TPS_RULECFG
{
	DWORD   dwSize;              // �ṹ��С
	NET_DVR_ONE_TPS_RULE struOneTpsRule[MAX_TPS_RULE]; // �±��Ӧ��ͨ����ID
	BYTE    byRes2[40];     // �����ֽ�
}NET_DVR_TPS_RULECFG, *LPNET_DVR_TPS_RULECFG;

// ��ͨ�¼���Ϣ
typedef struct tagNET_DVR_AID_INFO
{
    BYTE            byRuleID;   // ������ţ�Ϊ�������ýṹ�±꣬0-16
    BYTE            byRes1[3];
    BYTE            byRuleName[NAME_LEN]; //  ��������
    DWORD           dwAIDType;  // �����¼�����
    NET_DVR_DIRECTION   struDirect; // ����ָ������   
    BYTE            byRes2[40];  // �����ֽ� 
}NET_DVR_AID_INFO, *LPNET_DVR_AID_INFO;

// ��ͨ�¼����� 
typedef struct tagNET_DVR_AID_ALARM
{
    DWORD               dwSize;         // �ṹ����
    DWORD               dwRelativeTime;	// ���ʱ��
    DWORD               dwAbsTime;		// ����ʱ��
    NET_VCA_DEV_INFO  	struDevInfo;	// ǰ���豸��Ϣ
    NET_DVR_AID_INFO    struAIDInfo;    // ��ͨ�¼���Ϣ
    DWORD               dwPicDataLen;   // ����ͼƬ�ĳ��� Ϊ0��ʾû��ͼƬ������0��ʾ�ýṹ�������ͼƬ����
    BYTE                *pImage;        // ָ��ͼƬ��ָ�� 
    BYTE                byRes[40];      // �����ֽ�  
}NET_DVR_AID_ALARM, *LPNET_DVR_AID_ALARM;

// �������нṹ�� 
typedef struct tagNET_DVR_LANE_QUEUE
{
    NET_VCA_POINT   struHead;       //����ͷ
    NET_VCA_POINT   struTail;       //����β
    DWORD           dwLength;      //ʵ�ʶ��г��� ��λΪ�� [0-500]
}NET_DVR_LANE_QUEUE, *LPNET_DVR_LANE_QUEUE; 

typedef enum tagTRAFFIC_DATA_VARY_TYPE
{
    NO_VARY,         //�ޱ仯 
    VEHICLE_ENTER,   //��������������Ȧ
    VEHICLE_LEAVE,   //�����뿪������Ȧ 
    UEUE_VARY       //���б仯             
}TRAFFIC_DATA_VARY_TYPE; 

typedef struct tagNET_DVR_LANE_PARAM
{
    BYTE    byRuleName[NAME_LEN];                 //������������ 
    BYTE    byRuleID;               // ������ţ�Ϊ�������ýṹ�±꣬0-7 
    BYTE    byVaryType;             // ������ͨ�����仯���� ���� TRAFFIC_DATA_VARY_TYPE
	BYTE	byLaneType;			// �������л�����
	BYTE	byRes1;
    DWORD    dwLaneVolume;	// �������� ��ͳ���ж��ٳ���ͨ��
    DWORD   dwLaneVelocity;      //�����ٶȣ��������
    DWORD   dwTimeHeadway ;      //��ͷʱ�࣬�������
    DWORD   dwSpaceHeadway;      //��ͷ��࣬����������
    float   fSpaceOccupyRation; //����ռ���ʣ��ٷֱȼ��㣨�ռ���)
    NET_DVR_LANE_QUEUE  struLaneQueue;         //�������г���
    NET_VCA_POINT       struRuleLocation;     //��Ȧ��������ĵ�λ��
    BYTE    byRes2[32];
}NET_DVR_LANE_PARAM, *LPNET_DVR_LANE_PARAM;


typedef struct tagNET_DVR_TPS_INFO
{
    DWORD   dwLanNum;   // ��ͨ�����ĳ�����Ŀ
    NET_DVR_LANE_PARAM  struLaneParam[MAX_TPS_RULE];
}NET_DVR_TPS_INFO, *LPNET_DVR_TPS_INFO;

typedef struct tagNET_DVR_TPS_ALARM
{
    DWORD dwSize;   // �ṹ���С
    DWORD       dwRelativeTime;				// ���ʱ��
    DWORD       dwAbsTime;						// ����ʱ��
    NET_VCA_DEV_INFO  	struDevInfo;		// ǰ���豸��Ϣ
    NET_DVR_TPS_INFO  struTPSInfo;     // ��ͨ�¼���Ϣ
	BYTE        byRes1[32];         // �����ֽ�
}NET_DVR_TPS_ALARM, *LPNET_DVR_TPS_ALARM;

// ������������ 
typedef struct tagNET_DVR_FACEDETECT_RULECFG
{
    DWORD          dwSize;              // �ṹ���С
    BYTE           byEnable;            // �Ƿ�����
    BYTE           byres1[3];          // �����ֽ�    
    BYTE           byRuleName[NAME_LEN];
    NET_VCA_POLYGON     struVcaPolygon;    // ��������������
    BYTE           byPicProType;	//����ʱͼƬ������ʽ 0-������ ��0-�ϴ�
    BYTE           bySensitivity;   // ����������
    WORD            wDuration;      // ������������ʱ����ֵ
    NET_DVR_JPEGPARA    struPictureParam; 		//ͼƬ���ṹ
    NET_VCA_SIZE_FILTER struSizeFilter;         //�ߴ������
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//����ʱ��
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //������ʽ 
    BYTE           byRelRecordChan[MAX_CHANNUM_V30];			//����������¼��ͨ��,Ϊ1��ʾ������ͨ��
    BYTE            byRes2[40];         //�����ֽ�
}NET_DVR_FACEDETECT_RULECFG, *LPNET_DVR_FACEDETECT_RULECFG;

typedef struct tagNET_DVR_FACEDETECT_ALARM
{
    DWORD  dwSize;     		// �ṹ��С
    DWORD 	dwRelativeTime; // ���ʱ��
    DWORD	dwAbsTime;			// ����ʱ��
    BYTE        byRuleName[NAME_LEN];   // ��������
    NET_VCA_TARGET_INFO  struTargetInfo;	//����Ŀ����Ϣ
    NET_VCA_DEV_INFO  	 struDevInfo;		//ǰ���豸��Ϣ
    DWORD dwPicDataLen;						//����ͼƬ�ĳ��� Ϊ0��ʾû��ͼƬ������0��ʾ�ýṹ�������ͼƬ����*/
    BYTE		byAlarmPicType;			// 0-�쳣��������ͼƬ 1- ����ͼƬ 
    BYTE   byRes[59];              // �����ֽ�
    BYTE  *pImage;   						//ָ��ͼƬ��ָ��
}NET_DVR_FACEDETECT_ALARM, *LPNET_DVR_FACEDETECT_ALARM;

typedef struct tagNET_DVR_EVENT_PARAM_UNION
{
    DWORD   uLen[3];        	// �������СΪ12�ֽ�
    DWORD  dwHumanIn;  	//�����˽ӽ� 0 - ���� 1- ����  
    float       fCrowdDensity;  // ��Ա�ۼ�ֵ
}NET_DVR_EVENT_PARAM_UNION, *LPNET_DVR_EVENT_PARAM_UNION;

// Ŀǰֻ�����������¼�����Ա�ۼ��¼�ʵʱ�����ϴ�
typedef struct tagNET_DVR_EVENT_INFO
{
    BYTE   byRuleID;				// Rule ID
    BYTE   byRes[3];				// �����ֽ�
    BYTE   byRuleName[NAME_LEN];	// ��������
    DWORD       dwEventType;    		// ����VCA_EVENT_TYPE
    NET_DVR_EVENT_PARAM_UNION uEventParam;  // 
}NET_DVR_EVENT_INFO, *LPNET_DVR_EVENT_INFO;

typedef struct tagNET_DVR_EVENT_INFO_LIST
{
    BYTE			byNum;		// �¼�ʵʱ��Ϣ����
    BYTE			byRes1[3];			// �����ֽ�
    NET_DVR_EVENT_INFO struEventInfo[MAX_RULE_NUM];	// �¼�ʵʱ��Ϣ
}NET_DVR_EVENT_INFO_LIST,*LPNET_DVR_EVENT_INFO_LIST;

typedef struct tagNET_DVR_RULE_INFO_ALARM
{
    DWORD 			dwSize;				// �ṹ���С
    DWORD 		dwRelativeTime; 	// ���ʱ��
    DWORD		dwAbsTime;			// ����ʱ��
    NET_VCA_DEV_INFO  	struDevInfo;		// ǰ���豸��Ϣ
    NET_DVR_EVENT_INFO_LIST struEventInfoList;	//�¼���Ϣ�б�
    BYTE			byRes2[40];			// �����ֽ�
}NET_DVR_RULE_INFO_ALARM, *LPNET_DVR_RULE_INFO_ALARM;

/******************************************
����:	NET_DVR_SetSceneMode
����:	���ó���ģʽ
����:	lUserID: NET_DVR_Login()�ķ���ֵ
        lChannel:  ͨ����
        dwSceneMode: ����ģʽ
���:	
����ֵ: �ɹ�-TRUE ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetSceneMode(LONG  lUserID, LONG lChannel, DWORD dwSceneMode);

/******************************************
����:	NET_DVR_GetSceneMode
����:	��ȡ����ģʽ
����:	lUserID: NET_DVR_Login()�ķ���ֵ
        lChannel:  ͨ����
        pSceneMode ָ�򳡾�ģʽָ��
���:	pSceneMode ָ�򳡾�ģʽָ��
����ֵ: �ɹ�-TRUE ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetSceneMode(LONG lUserID, LONG lChannel, DWORD  *pSceneMode);

/*******************************���ܽ�ͨ�¼� end*****************************************/

#define XXX_MAJOR_VERSION      2

/* �Ӱ汾�ţ������Ż����ֲ��ṹ������ģ���ڼ�������������汾����ʱ���������31 */

#define XXX_SUB_VERSION        3

/* �����汾�ţ�����bug����������31 */

#define XXX_REVISION_VERSION   4

typedef struct tagNET_DVR_VCA_VERSION
{
	WORD    wMajorVersion;		// ���汾��
	WORD    wMinorVersion;		// �ΰ汾��
	WORD    wRevisionNumber;	// ������
	WORD    wBuildNumber;		// �����
	WORD	wVersionYear;		//	�汾����-��
	BYTE	byVersionMonth;		//	�汾����-��
	BYTE	byVersionDay;		//	�汾����-��
	BYTE	byRes[8];			// �����ֽ�
}NET_DVR_VCA_VERSION, *LPNET_DVR_VCA_VERSION;
NET_DVR_API BOOL __stdcall NET_DVR_GetVCAVersion(LONG lUserID, LONG lChannel, LPNET_DVR_VCA_VERSION lpVersion);

/******************************���� end***********************************/

/******************************����ʶ�� begin******************************************/
typedef struct tagNET_DVR_PLATE_PARAM
{	
    BYTE    byPlateRecoMode;    //����ʶ���ģʽ,Ĭ��Ϊ1(��Ƶ����ģʽ)
    BYTE    byBelive;;		    //�������Ŷ���ֵ, ֻ������Ƶʶ��ʽ, ���ݱ������ӳ̶�����, �󴥷��ʸ߾����, ©���ʸ߾����, ������80-90��Χ��
    BYTE    byRes[22];          //�����ֽ�
}NET_DVR_PALTE_PARAM, *LPNET_DVR_PALTE_PARAM;

typedef struct tagNET_DVR_PLATECFG
{	
    DWORD		dwSize;
    DWORD    dwEnable;				           /* �Ƿ�������Ƶ����ʶ�� 0���� 1���� */
    BYTE    byPicProType;	//����ʱͼƬ������ʽ 0-������ ��0-�ϴ�
    BYTE    byRes1[3];  // �����ֽ�
    NET_DVR_JPEGPARA struPictureParam; 		//ͼƬ���ṹ
    NET_DVR_PALTE_PARAM struPlateParam;   // ����ʶ���������
    NET_DVR_HANDLEEXCEPTION struHandleType;	   /* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE    byRelRecordChan[MAX_CHANNUM];        //����������¼��ͨ��,Ϊ1��ʾ������ͨ��
    BYTE   byRes[20];   // �����ֽ�
}NET_DVR_PLATECFG, *LPNET_DVR_PLATECFG;

// ����ʶ�����ӽṹ
typedef struct tagNET_DVR_PLATE_INFO
{
    BYTE  byPlateType;					//��������
    BYTE  byColor;						//������ɫ
    BYTE  byBright;						//��������
    BYTE  byLicenseLen;					//�����ַ�����
    BYTE  byEntireBelieve;					//�������Ƶ����Ŷȣ�-100
    BYTE  byRes[35];					//����
    NET_VCA_RECT	struPlateRect;		//����λ��
    char sLicense[MAX_LICENSE_LEN];		//���ƺ���
    BYTE byBelieve[MAX_LICENSE_LEN];	//����ʶ���ַ������Ŷȣ����⵽����"��A12345", ���Ŷ�Ϊ,20,30,40,50,60,70�����ʾ"��"����ȷ�Ŀ�����ֻ��%��"A"�ֵ���ȷ�Ŀ�������%
}NET_DVR_PLATE_INFO, *LPNET_DVR_PLATE_INFO;

typedef struct tagNET_DVR_PLATERECO_RESULE
{
    DWORD dwSize;
    DWORD    dwRelativeTime;				//���ʱ��
    DWORD    dwAbsTime;						//����ʱ��
    NET_VCA_DEV_INFO struDevInfo;           // ǰ���豸��Ϣ
    NET_DVR_PLATE_INFO struPlateInfo;
    DWORD dwPicDataLen;						//����ͼƬ�ĳ��� Ϊ0��ʾû��ͼƬ������0��ʾ�ýṹ�������ͼƬ����*/
    DWORD dwRes[4];							//����������Ϊ0
    BYTE  *pImage;   						//ָ��ͼƬ��ָ��
}NET_DVR_PLATERECO_RESULE, *LPNET_DVR_PLATERECO_RESULE;

/******************************����ʶ�� end******************************************/


/*******************************��Ƶ�ۺ�ƽ̨***********************************/
//09-11-21
typedef struct 
{
    NET_DVR_TIME strLogTime;
    DWORD	dwMajorType;	//Main type 1-alarm; 2-abnormal; 3-operation; 0xff-all 
    DWORD	dwMinorType;	//Hypo-Type 0-all;
    BYTE	sPanelUser[MAX_NAMELEN]; //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN];//user ID for network operation
    NET_DVR_IPADDR	struRemoteHostAddr;//remote host IP
    DWORD	dwParaType;//parameter type
    DWORD	dwChannel;//channel number
    DWORD	dwDiskNumber;//HD number
    DWORD	dwAlarmInPort;//alarm input port
    DWORD	dwAlarmOutPort;//alarm output port
    DWORD   dwInfoLen;
    BYTE  byDevSequence;//��λ��
    BYTE  byMacAddr[MACADDR_LEN];//MAC��ַ,6
    BYTE  sSerialNumber[SERIALNO_LEN];//���кţ�48
    char  sInfo[LOG_INFO_LEN - SERIALNO_LEN - MACADDR_LEN - 1 ];
}NET_DVR_LOG_MATRIX, *LPNET_DVR_LOG_MATRIX;

//2009-11-21 ��Ƶ�ۺ�ƽ̨
typedef struct tagVEDIOPLATLOG
{
    BYTE bySearchCondition;//����������0-����λ��������1-�����к�������2-��MAC��ַ��������
	//��λ�ţ�0-79����Ӧ��ϵͳ�Ĳ�λ�ţ�
    //0xff����ʾ�������е���־������78K������6467��
    //0xfe����ʾ����78K�ϵ���־��0xfd��������־��0xfc������־����
    BYTE byDevSequence;
    BYTE  sSerialNumber[SERIALNO_LEN];//���кţ�48
    BYTE  byMacAddr[MACADDR_LEN];//MAC��ַ,6
} NET_DVR_VEDIOPLATLOG, *LPNET_DVR_VEDIOPLATLOG;
//2009-11-21

#define VIDEOPLATFORM_SBUCODESYSTEM_ABILITY          0x211 //��Ƶ�ۺ�ƽ̨������ϵͳ������
typedef struct tagNET_DVR_CODESYSTEMABILITY
{
    DWORD dwSize;
    DWORD dwAbilityVersion;//�������汾�ţ���16λ��ʾ���汾����16λ��ʾ�ΰ汾 
    DWORD dwSupportMaxVideoFrameRate;//��λ(K)
	/*��λ:
	0:��ʱ¼��
	1:��ʱ|�¼�����¼�� 
	2:�ƶ����¼��
	3:���翪��������¼��
	4:�ƶ����|���翪��������¼��
	5:�ƶ����&���翪��������¼��
	6:�ܽ��������¼��
	7:������ⴥ��¼��
	8:����ʶ�𴥷�¼��
	9:�ֶ�¼��*/
    DWORD dwSupportRecordType;
    BYTE  bySupportLinkMode;//��λ:��0λ:��ʾ����������1λ:��ʾ������
	BYTE  bySupportStringRow;//֧���ַ���������
    BYTE  byRes1[2];
	/*0-DCIF��1-CIF��2-QCIF��3-4CIF��4-2CIF��6-QVGA(320*240), 16-VGA��17-UXGA��18-SVGA��19-HD720p��20-XVGA��21-HD900p��22-SXGAp��27-HD1080i��28-2560*1920��29-1600*304��30-2048*1536��31-2448*2048��32-2448*1200��33-2448*800 ��34-XGA��1024x768����35-SXGA��1280x1024��*/
	BYTE  byMainStreamSupportResolution[8];//������֧�ֵķֱ��ʣ���λ
	BYTE  bySubStreamSupportResolution[8];//������֧�ֵķֱ��ʣ���λ
	BYTE  byEventStreamSupportResolution[8];//�¼���������֧�ֵķֱ��ʣ���λ
    BYTE  byRes2[100];//����
}NET_DVR_CODESYSTEMABILITY, *LPNET_DVR_CODESYSTEMABILITY;

/********************************end*******************************************/

/******************************ץ�Ļ�*******************************************/
//IO��������
typedef struct tagNET_DVR_IO_INCFG
{
    DWORD   dwSize;
    BYTE    byIoInStatus;//�����IO��״̬��0-�½��أ�1-�����أ�2-�����غ��½��أ�3-�ߵ�ƽ��4-�͵�ƽ
    BYTE	byRes[3];//�����ֽ�
}NET_DVR_IO_INCFG, *LPNET_DVR_IO_INCFG;

//IO�������
typedef struct tagNET_DVR_IO_OUTCFG
{
    DWORD   dwSize;
    BYTE    byDefaultStatus;//IOĬ��״̬��0-�͵�ƽ��1-�ߵ�ƽ 
    BYTE    byIoOutStatus;//IO��Чʱ״̬��0-�͵�ƽ��1-�ߵ�ƽ��2-����
    WORD    wAheadTime;//���IO��ǰʱ�䣬��λus
    DWORD   dwTimePluse;//������ʱ�䣬��λus
    DWORD   dwTimeDelay;//IO��Ч����ʱ�䣬��λus
	BYTE    byFreqMulti;		//��Ƶ����ֵ��Χ[1,15]
	BYTE    byDutyRate;		//ռ�ձȣ�[0,40%]
    BYTE    byRes[2];
}NET_DVR_IO_OUTCFG, *LPNET_DVR_IO_OUTCFG;

//���������
typedef struct tagNET_DVR_FLASH_OUTCFG
{
    DWORD  dwSize;
    BYTE   byMode;//�������˸ģʽ��0-������1-����2-��������3-����
    BYTE   byRelatedIoIn;//����ƹ���������IO�ţ�������ʱ�˲�����Ч��
	BYTE   byRecognizedLane;  /*������IO�ţ���λ��ʾ��bit0��ʾIO1�Ƿ������0-��������1-����*/
	BYTE   byDetectBrightness;/*�Զ��������ʹ�������0-����⣻1-���*/
	BYTE   byBrightnessThreld;/*ʹ�������������ֵ����Χ[0,100],������ֵ��*/
    BYTE   byStartHour;		//��ʼʱ��-Сʱ,ȡֵ��Χ0-23
	BYTE   byStartMinute;		//��ʼʱ��-��,ȡֵ��Χ0-59
	BYTE   byEndHour;		 	//����ʱ��-Сʱ,ȡֵ��Χ0-23
	BYTE   byEndMinute;		//����ʱ��-��,ȡֵ��Χ0-59
	BYTE   byFlashLightEnable;	//���������ʱ��ʹ��:0-��;1-��
	BYTE   byRes[2];
}NET_DVR_FLASH_OUTCFG, *LPNET_DVR_FLASH_OUTCFG;

//���̵ƹ��ܣ�2��IO����һ�飩
typedef struct tagNET_DVR_LIGHTSNAPCFG
{
    DWORD   dwSize;
    BYTE	byLightIoIn;//���̵Ƶ�IO ��
    BYTE	byTrigIoIn;//������IO��
    BYTE	byRelatedDriveWay;//����IO�����ĳ�����
    BYTE	byTrafficLight; //0-�ߵ�ƽ��ƣ��͵�ƽ�̵ƣ�1-�ߵ�ƽ�̵ƣ��͵�ƽ���
    BYTE 	bySnapTimes1; //���ץ�Ĵ���1��0-��ץ�ģ���0-���Ĵ��������5�� 
    BYTE 	bySnapTimes2; //�̵�ץ�Ĵ���2��0-��ץ�ģ���0-���Ĵ��������5�� 
    BYTE	byRes1[2];
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//������ļ��ʱ�䣬ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//�̵����ļ��ʱ�䣬ms
    BYTE	byRecord;//���������¼���־��0-��¼��1-¼��
    BYTE	bySessionTimeout;//���������¼��ʱʱ�䣨�룩
    BYTE	byPreRecordTime;//�����¼��Ƭ��Ԥ¼ʱ��(��)
    BYTE	byVideoDelay;//�����¼��Ƭ����ʱʱ�䣨�룩
    BYTE	byRes2[32];//�����ֽ�
}NET_DVR_LIGHTSNAPCFG, *LPNET_DVR_LIGHTSNAPCFG;

//���ٹ���(2��IO����һ�飩
typedef struct tagNET_DVR_MEASURESPEEDCFG
{
    DWORD   dwSize;
    BYTE	byTrigIo1;   //���ٵ�1��Ȧ
    BYTE	byTrigIo2;   //���ٵ�2��Ȧ
    BYTE	byRelatedDriveWay;//����IO�����ĳ�����
    BYTE	byTestSpeedTimeOut;//����ģʽ��ʱʱ�䣬��λs
    DWORD   dwDistance;//��Ȧ����,cm
    BYTE	byCapSpeed;//����ģʽ�����ٶȣ���λkm/h
    BYTE	bySpeedLimit;//����ֵ����λkm/h
    BYTE 	bySnapTimes1; //��Ȧ1ץ�Ĵ�����0-��ץ�ģ���0-���Ĵ��������5�� 
    BYTE 	bySnapTimes2; //��Ȧ2ץ�Ĵ�����0-��ץ�ģ���0-���Ĵ��������5�� 
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//��Ȧ1���ļ��ʱ�䣬ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//��Ȧ2���ļ��ʱ�䣬ms
    BYTE	byRes[32];//�����ֽ�
}NET_DVR_MEASURESPEEDCFG, *LPNET_DVR_MEASURESPEEDCFG;

//��Ƶ��������
typedef struct tagNET_DVR_VIDEOEFFECT
{
    BYTE byBrightnessLevel; /*0-100*/
    BYTE byContrastLevel; /*0-100*/
    BYTE bySharpnessLevel; /*0-100*/
    BYTE bySaturationLevel; /*0-100*/
    BYTE byHueLevel; /*0-100,��������*/
    BYTE byRes[3];
}NET_DVR_VIDEOEFFECT, *LPNET_DVR_VIDEOEFFECT;

//��������
typedef struct tagNET_DVR_GAIN
{
    BYTE byGainLevel; /*���棺0-100*/
    BYTE byGainUserSet; /*�û��Զ������棻0-100������ץ�Ļ�����CCDģʽ�µ�ץ������*/
    BYTE byRes[2];
    DWORD dwMaxGainValue;/*�������ֵ����λdB*/
}NET_DVR_GAIN, *LPNET_DVR_GAIN;

//��ƽ������
typedef struct tagNET_DVR_WHITEBALANCE
{
    BYTE byWhiteBalanceMode; /*0�ֶ���ƽ��; 1�Զ���ƽ��1����ΧС��; 2 �Զ���ƽ��2����Χ����2200K-15000K��;3�Զ�����3*/
    BYTE byWhiteBalanceModeRGain; /*�ֶ���ƽ��ʱ��Ч���ֶ���ƽ�� R����*/
    BYTE byWhiteBalanceModeBGain; /*�ֶ���ƽ��ʱ��Ч���ֶ���ƽ�� B����*/
    BYTE byRes[5];
}NET_DVR_WHITEBALANCE, *LPNET_DVR_WHITEBALANCE;

//�ع����
typedef struct tagNET_DVR_EXPOSURE
{
    BYTE  byExposureMode; /*0 �ֶ��ع� 1�Զ��ع�*/
    BYTE  byRes[3];
    DWORD dwVideoExposureSet; /* �Զ�����Ƶ�ع�ʱ�䣨��λus��*//*ע:�Զ��ع�ʱ��ֵΪ�ع�����ֵ*/        
    DWORD dwExposureUserSet; /* �Զ����ع�ʱ��,��ץ�Ļ���Ӧ��ʱ��CCDģʽʱ��ץ�Ŀ����ٶ�*/   
    DWORD dwRes;    
} NET_DVR_EXPOSURE, *LPNET_DVR_EXPOSURE;

//����̬����
typedef struct tagNET_DVR_WDR
{
    BYTE byWDREnabled; /*����̬��0 dsibale  1 enable 2 auto*/
    BYTE byWDRLevel1; /*0-F*/
    BYTE byWDRLevel2; /*0-F*/
    BYTE byWDRContrastLevel; /*0-100*/
    BYTE byRes[16];
} NET_DVR_WDR, *LPNET_DVR_WDR;

//��ҹת����������
typedef struct tagNET_DVR_DAYNIGHT
{
    BYTE byDayNightFilterType; /*��ҹ�л���0 day,1 night,2 auto */
    BYTE bySwitchScheduleEnabled; /*0 dsibale  1 enable,(����)*/
    //ģʽ1(����)
    BYTE byBeginTime; /*0-100*/
    BYTE byEndTime; /*0-100*/
    //ģʽ2
    BYTE byDayToNightFilterLevel; //0-7
    BYTE byNightToDayFilterLevel; //0-7
    BYTE byDayNightFilterTime;//(60��)
    BYTE byRes[5];
} NET_DVR_DAYNIGHT, *LPNET_DVR_DAYNIGHT;

//GammaУ��
typedef struct tagNET_DVR_GAMMACORRECT
{
    BYTE byGammaCorrectionEnabled; /*0 dsibale  1 enable*/
    BYTE byGammaCorrectionLevel; /*0-100*/
    BYTE byRes[6];
} NET_DVR_GAMMACORRECT, *LPNET_DVR_GAMMACORRECT;

//���ⲹ������
typedef struct tagNET_DVR_BACKLIGHT
{
    BYTE byBacklightMode; /*���ⲹ��:0 off 1 UP��2 DOWN��3 LEFT��4 RIGHT��5MIDDLE��6�Զ���*/
    BYTE byBacklightLevel; /*0x0-0xF*/
    BYTE byRes1[2];
    DWORD dwPositionX1; //��X����1��
    DWORD dwPositionY1; //��Y����1��
    DWORD dwPositionX2; //��X����2��
    DWORD dwPositionY2; //��Y����2��
    BYTE byRes2[4];
} NET_DVR_BACKLIGHT, *LPNET_DVR_BACKLIGHT;

//���ֽ��빦��
typedef struct tagNET_DVR_NOISEREMOVE
{
    BYTE byDigitalNoiseRemoveEnable; /*0-�����ã�1-��ͨģʽ���ֽ��룬2-ר��ģʽ���ֽ���*/
    BYTE byDigitalNoiseRemoveLevel; /*��ͨģʽ���ֽ��뼶��0x0-0xF*/
	BYTE bySpectralLevel;       /*ר��ģʽ�¿���ǿ�ȣ�0-100*/
    BYTE byTemporalLevel;   /*ר��ģʽ��ʱ��ǿ�ȣ�0-100*/
    BYTE byRes[4];
} NET_DVR_NOISEREMOVE, *LPNET_DVR_NOISEREMOVE;

//CMOSģʽ��ǰ�˾�ͷ����
typedef struct tagNET_DVR_CMOSMODCFG
{
	BYTE byCaptureMod;   //ץ��ģʽ��0-ץ��ģʽ1��1-ץ��ģʽ2
	BYTE byBrightnessGate;//������ֵ
	BYTE byCaptureGain1;   //ץ������1,0-100
	BYTE byCaptureGain2;   //ץ������2,0-100
	DWORD dwCaptureShutterSpeed1;//ץ�Ŀ����ٶ�1
	DWORD dwCaptureShutterSpeed2;//ץ�Ŀ����ٶ�2
	BYTE  byRes[4];
}NET_DVR_CMOSMODECFG, *LPNET_DVR_CMOSMODECFG;

//IPC CCD��������
typedef struct tagNET_DVR_CAMERAPARAMCFG
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*���ȡ��Աȶȡ����Ͷȡ���ȡ�ɫ������*/    
    NET_DVR_GAIN struGain;/*�Զ�����*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*��ƽ��*/
    NET_DVR_EXPOSURE struExposure; /*�ع����*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*GammaУ��*/
    NET_DVR_WDR struWdr;/*����̬*/
    NET_DVR_DAYNIGHT struDayNight;/*��ҹת��*/
    NET_DVR_BACKLIGHT struBackLight;/*���ⲹ��*/
    NET_DVR_NOISEREMOVE struNoiseRemove;/*���ֽ���*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byIrisMode; /*0 �Զ���Ȧ 1�ֶ���Ȧ*/    
    BYTE byMirror ;  /* ����0 off��1- leftright��2- updown��3-center */
    BYTE byDigitalZoom;  /*��������:0 dsibale  1 enable*/
    BYTE byDeadPixelDetect;   /*������,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*�ڵ�ƽ���� ,  0-255*/ 
	BYTE byEptzGate;// EPTZ���ر���:0-�����õ�����̨��1-���õ�����̨
	BYTE byLocalOutputGate;//����������ر���0-��������ر�1-����BNC����� 2-HDMI����ر�  
				     //20-HDMI_720P50�����
					 //21-HDMI_720P60�����
					 //22-HDMI_1080I60�����
					 //23-HDMI_1080I50�����
					 //24-HDMI_1080P24�����
					 //25-HDMI_1080P25�����
					 //26-HDMI_1080P30�����
					 //27-HDMI_1080P50�����
			         //28-HDMI_1080P60�����
	BYTE byCoderOutputMode;//������fpga���ģʽ0ֱͨ3���ذ��
	BYTE byLineCoding; //�Ƿ����б��룺0-��1-��
	BYTE byRes1[3];
	BYTE byDynamicContrastEN;    //��̬�Աȶ���ǿ 0-1
	BYTE byDynamicContrast;    //��̬�Աȶ� 0-100
	BYTE byJPEGQuality;    //JPEGͼ������ 0-100
	NET_DVR_CMOSMODECFG struCmosModeCfg;//CMOSģʽ��ǰ�˲������ã���ͷģʽ����������ȡ
	BYTE byRes2[4];
}NET_DVR_CAMERAPARAMCFG, *LPNET_DVR_CAMERAPARAMCFG;

//������ɫ
typedef enum _VCA_PLATE_COLOR_
{
	VCA_BLUE_PLATE  = 0,       //��ɫ����
	VCA_YELLOW_PLATE,          //��ɫ����
	VCA_WHITE_PLATE,          //��ɫ����
	VCA_BLACK_PLATE           //��ɫ����
}VCA_PLATE_COLOR;

//��������
typedef enum _VCA_PLATE_TYPE_
{
	VCA_STANDARD92_PLATE = 0,	//��׼���ó������
	VCA_STANDARD02_PLATE,		//02ʽ���ó��� 
	VCA_WJPOLICE_PLATE,		    //�侯�� 
	VCA_JINGCHE_PLATE,			//����
	STANDARD92_BACK_PLATE, 	    //���ó�˫��β��
	VCA_SHIGUAN_PLATE,          //ʹ�ݳ���
	VCA_NONGYONG_PLATE,         //ũ�ó�
	VCA_MOTO_PLATE              //Ħ�г�
}VCA_PLATE_TYPE;

//������Ϣ
typedef struct tagNET_DVR_VEHICLE_INFO_
{
    DWORD dwIndex;					//�������
    BYTE  byVehicleType;		//��������
    BYTE  byColorDepth;		//������ɫ��ǳ
    BYTE  byColor;					//������ɫ
    BYTE  byRes1;				//����
    WORD  wSpeed;					//��λkm/h
    WORD  wLength;					//ǰһ�����ĳ�������
	BYTE  byIllegalType;           //0-����;1-����2-����3-����
    BYTE  byRes[35];					//����
}NET_DVR_VEHICLE_INFO, *LPNET_DVR_VEHICLE_INFO;

//���Ƽ����
typedef struct tagNET_DVR_PLATE_RESULT
{
    DWORD   dwSize;						//�ṹ����
    BYTE	byResultType;			//0-��Ƶʶ������-ͼ��ʶ����
	BYTE    byChanIndex;			//ͨ����
    BYTE    byRes1[2];				//����
    DWORD   dwRelativeTime;		//���ʱ���  
    BYTE    byAbsTime[32];		//����ʱ���,yyyymmddhhmmssxxx,e.g.20090810235959999�����룩
    DWORD   dwPicLen;					//ͼƬ����
    DWORD	dwPicPlateLen;			//����СͼƬ����
    DWORD   dwVideoLen;					//¼�����ݳ���
    BYTE	byTrafficLight;				//0-�Ǻ��̵�ץ�ģ�1-�̵�ʱץ�ģ�2-���ʱץ��
    BYTE    byPicNum;				//���ĵ�ͼƬ���
    BYTE	byDriveChan;				//����������
    BYTE	byRes2[33];					//���� 
    NET_DVR_PLATE_INFO  struPlateInfo;    //������Ϣ�ṹ
    NET_DVR_VEHICLE_INFO struVehicleInfo; //������Ϣ
    BYTE	*pBuffer1;   		        // ���ϴ�����ͼƬ��ָ��ָ��ͼƬ��Ϣ�����ϴ�������Ƶ��ָ��ָ����Ƶ��Ϣ�����������ͼƬ����Ƶ��Ϣ����NULL
    BYTE    *pBuffer2;                  // ���ϴ�����ͼƬʱ��ָ����ͼƬ��ָ��
}NET_DVR_PLATE_RESULT, *LPNET_DVR_PLATE_RESULT;
//�������ͼƬ���ݺ�¼�����ݣ�ֻ��һ�֣�ͼƬ����Ϊ����ͼƬ+����СͼƬ

//���Ʊ���NET_DVR_PLATE_RESULT
#define COMM_UPLOAD_PLATE_RESULT		0x2800	//�ϴ�������Ϣ
//ͼ�������Ϣ����        
typedef struct tagNET_DVR_IMAGEOVERLAYCFG
{
	DWORD		dwSize;
	BYTE		byOverlayInfo;//����ʹ�ܿ��أ�0-�����ӣ�1-����
	BYTE		byOverlayMonitorInfo;//�Ƿ���Ӽ�����Ϣ��0-�����ӣ�1-����
	BYTE		byOverlayTime;//�Ƿ����ʱ�䣬0-�����ӣ�1-����
	BYTE		byOverlaySpeed;//�Ƿ�����ٶȣ�0-�����ӣ�1-����
	BYTE		byOverlaySpeeding;//�Ƿ���ӳ��ٱ�����0-�����ӣ�1-����
	BYTE		byOverlayLimitFlag;//�Ƿ�������ٱ�־��0-�����ӣ�1-����
	BYTE		byOverlayPlate;//�Ƿ���ӳ��ƣ�0-�����ӣ�1-����
	BYTE		byOverlayColor;//�Ƿ���ӳ�����ɫ��0-�����ӣ�1-����
    BYTE		byOverlayLength;//�Ƿ���ӳ�����0-�����ӣ�1-����
    BYTE		byOverlayType;//�Ƿ���ӳ��ͣ�0-�����ӣ�1-����
    BYTE		byOverlayColorDepth;//�Ƿ���ӳ�����ɫ��ǳ��0-�����ӣ�1-����
    BYTE		byOverlayDriveChan;//�Ƿ���ӳ�����0-�����ӣ�1-����
    BYTE		byOverlayMilliSec; //���Ӻ�����Ϣ 0-�����ӣ�1-����
	BYTE		byOverlayIllegalInfo; //����Υ����Ϣ 0-�����ӣ�1-����
	BYTE        byOverlayRedOnTime;  //���Ӻ������ʱ�� 0-�����ӣ�1-����
	BYTE		byRes1[5];    //����
	BYTE		byMonitorInfo1[32];    //������Ϣ1
	BYTE		byMonitorInfo2[44]; //������Ϣ2
	BYTE		byRes2[52];    //����
}NET_DVR_IMAGEOVERLAYCFG, *LPNET_DVR_IMAGEOVERLAYCFG;

//��IO����ץ�Ĺ�������
typedef struct tagNET_DVR_SNAPCFG
{
    DWORD   dwSize;
    BYTE	byRelatedDriveWay;//����IO�����ĳ�����
    BYTE 	bySnapTimes; //��Ȧץ�Ĵ�����0-��ץ�ģ���0-���Ĵ�����Ŀǰ���5��  
    WORD	wSnapWaitTime;  //ץ�ĵȴ�ʱ�䣬��λms��ȡֵ��Χ[0,60000]
    WORD	wIntervalTime[MAX_INTERVAL_NUM];//���ļ��ʱ�䣬ms
    BYTE	byRes2[24];//�����ֽ�
}NET_DVR_SNAPCFG, *LPNET_DVR_SNAPCFG;

typedef struct tagNET_DVR_SNAP_ABILITY
{
    DWORD dwSize;
    BYTE  byIoInNum;//IO�������
    BYTE  byIoOutNum;//IO�������
    BYTE  bySingleSnapNum;//��IO��������
    BYTE  byLightModeArrayNum;//���̵�ģʽ����
    BYTE  byMeasureModeArrayNum;//����ģʽ����
	BYTE  byPlateEnable; //����ʶ������
	BYTE  byLensMode;//��ͷģʽ0-CCD,1-CMOS
    BYTE  byRes[29];
} NET_DVR_SNAP_ABILITY, *LPNET_DVR_SNAP_ABILITY;
#define SNAPCAMERA_ABILITY          0x300 //ץ�Ļ�������

typedef struct tagNET_DVR_TRIGCOORDINATE
{
    WORD wTopLeftX; /*��Ȧ���ϽǺ����꣨2���ֽڣ�*/
    WORD wTopLeftY; /*��Ȧ���Ͻ������꣨2���ֽڣ�*/
    WORD wWdith; /*��Ȧ���ȣ�2���ֽڣ�*/
    WORD wHeight; /*��Ȧ�߶ȣ�2���ֽڣ�*/
} NET_DVR_TRIGCOORDINATE, *LPNET_DVR_TRIGCOORDINATE;

typedef enum _PROVINCE_CITY_IDX_
{
	ANHUI_PROVINCE             = 0,              //����
	AOMEN_PROVINCE             = 1,              //����
	BEIJING_PROVINCE           = 2,              //����
	CHONGQING_PROVINCE         = 3,              //����
	FUJIAN_PROVINCE            = 4,              //����
	GANSU_PROVINCE             = 5,              //����
	GUANGDONG_PROVINCE         = 6,              //�㶫
	GUANGXI_PROVINCE           = 7,              //����
	GUIZHOU_PROVINCE           = 8,              //����
	HAINAN_PROVINCE            = 9,              //����
	HEBEI_PROVINCE             = 10,             //�ӱ�
	HENAN_PROVINCE             = 11,             //����
	HEILONGJIANG_PROVINCE      = 12,             //������
	HUBEI_PROVINCE             = 13,             //����
	HUNAN_PROVINCE             = 14,             //����
	JILIN_PROVINCE             = 15,             //����
	JIANGSU_PROVINCE           = 16,             //����
	JIANGXI_PROVINCE           = 17,             //����
	LIAONING_PROVINCE          = 18,             //����
	NEIMENGGU_PROVINCE         = 19,             //���ɹ�
	NINGXIA_PROVINCE           = 20,             //����
	QINGHAI_PROVINCE           = 21,             //�ຣ
	SHANDONG_PROVINCE          = 22,             //ɽ��
	SHANXI_JIN_PROVINCE        = 23,             //ɽ��
	SHANXI_SHAN_PROVINCE       = 24,             //����
	SHANGHAI_PROVINCE          = 25,             //�Ϻ�
	SICHUAN_PROVINCE           = 26,             //�Ĵ�
	TAIWAN_PROVINCE            = 27,             //̨��
	TIANJIN_PROVINCE           = 28,             //���
	XIZANG_PROVINCE            = 29,             //����
	XIANGGANG_PROVINCE         = 30,             //���
	XINJIANG_PROVINCE          = 31,             //�½�
	YUNNAN_PROVINCE            = 32,             //����
	ZHEJIANG_PROVINCE          = 33              //�㽭
}PROVINCE_CITY_IDX;

typedef struct tagNET_DVR_GEOGLOCATION
{
	int iRes[2]; /*����*/
	DWORD dwCity; /*���У����PROVINCE_CITY_IDX */
}NET_DVR_GEOGLOCATION, *LPNET_DVR_GEOGLOCATION;

//����ģʽ
typedef enum _SCENE_MODE_
{
	UNKOWN_SCENE_MODE   = 0,            //δ֪����ģʽ
	HIGHWAY_SCENE_MODE  = 1,            //���ٳ���ģʽ
	SUBURBAN_SCENE_MODE = 2,            //��������ģʽ(����)
	URBAN_SCENE_MODE    = 3,            //��������ģʽ
	TUNNEL_SCENE_MODE   = 4             //��������ģʽ(����)
}SCENE_MODE;

typedef struct tagNET_DVR_VTPARAM
{
    DWORD   dwSize;
	BYTE    byEnable;  /* �Ƿ�ʹ��������Ȧ��0-��ʹ�ã�1-ʹ��*/
	BYTE    byIsDisplay; /* �Ƿ���ʾ������Ȧ��0-����ʾ��1-��ʾ*/
	BYTE    byLoopPos; //���䴥����Ȧ��ƫ��0-���ϣ�1-����
	BYTE    bySnapGain; /*ץ������*/
	DWORD   dwSnapShutter; /*ץ�Ŀ����ٶ�*/
    NET_DVR_TRIGCOORDINATE struTrigCoordinate; //����
    NET_DVR_TRIGCOORDINATE struRes[MAX_VL_NUM];
    BYTE    byTotalLaneNum;/*��Ƶ�����ĳ�����1*/
    BYTE    byPolarLenType; /*ƫ�����ͣ�0������ƫ�񾵣�1����ʩ�͵�ƫ�񾵡�*/
    BYTE	byDayAuxLightMode; /*���츨������ģʽ��0���޸���������1��LED��������2�����������*/
    BYTE	byLoopToCalRoadBright; /*���Լ���·�����ȵĳ���(������Ȧ)*/
    BYTE	byRoadGrayLowTh; /*·�����ȵ���ֵ��ʼ��ֵ1*/
    BYTE	byRoadGrayHighTh; /*·�����ȸ���ֵ��ʼ��ֵ140*/
    WORD	wLoopPosBias; /*���䴥����Ȧλ��30*/
    DWORD   dwHfrShtterInitValue; /*����ͼ���ع�ʱ��ĳ�ʼֵ2000*/
    DWORD   dwSnapShtterInitValue; /*ץ��ͼ���ع�ʱ��ĳ�ʼֵ500*/
    DWORD   dwHfrShtterMaxValue; /*����ͼ���ع�ʱ������ֵ20000*/
    DWORD   dwSnapShtterMaxValue; /*ץ��ͼ���ع�ʱ������ֵ1500*/
    DWORD   dwHfrShtterNightValue; /*��������ͼ���ع�ʱ�������ֵ3000*/
    DWORD   dwSnapShtterNightMinValue; /*����ץ��ͼ���ع�ʱ�����Сֵ3000*/
    DWORD   dwSnapShtterNightMaxValue; /*����ץ��ͼ���ع�ʱ������ֵ5000*/
    DWORD   dwInitAfe; /*����ĳ�ʼֵ200*/
    DWORD   dwMaxAfe; /*��������ֵ400*/
	WORD    wResolutionX;/* �豸��ǰ�ֱ��ʿ�*/
	WORD    wResolutionY;/* �豸��ǰ�ֱ��ʸ�*/
    DWORD   dwGainNightValue; /*�������棬Ĭ��ֵ70*/
	DWORD   dwSceneMode; /*����ģʽ�� ���SCENE_MODE */
	DWORD   dwRecordMode; /*¼���־��0-��¼��1-¼��*/
	NET_DVR_GEOGLOCATION struGeogLocation; /*��ַλ��*/
	BYTE    byTrigFlag[MAX_VL_NUM]; /*������־��0-��ͷ������1-��β������2-��ͷ/��β������*/
	BYTE    byTrigSensitive[MAX_VL_NUM];  /*���������ȣ�1-100*/
	BYTE    byRes2[62];
}NET_DVR_VTPARAM, *LPNET_DVR_VTPARAM;

typedef struct tagNET_DVR_SNAPENABLECFG
{
	DWORD		dwSize;
	BYTE		byPlateEnable;//�Ƿ�֧�ֳ���ʶ��0-��֧�֣�1-֧��
	BYTE 		byRes1[2];   //����
	BYTE        byFrameFlip;   //ͼ���Ƿ�ת 0-����ת��1-��ת
	WORD        wFlipAngle;    //ͼ��ת�Ƕ� 0,90,180,270
	WORD        wLightPhase;   //��λ��ȡֵ��Χ[0, 360]
	BYTE        byLightSyncPower;  //�Ƿ��źŵƵ�Դͬ����0-��ͬ����1-ͬ��
	BYTE 		byFrequency;		//�ź�Ƶ��
	BYTE        byUploadSDEnable;  //�Ƿ��Զ��ϴ�SDͼƬ��0-��1-��
	BYTE 		byRes[61]; //����
}NET_DVR_SNAPENABLECFG, *LPNET_DVR_SNAPENABLECFG;

/* ftp �ϴ�����*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwEnableFTP;			/*�Ƿ�����ftp�ϴ�����*/
	char	sFTPIP[16];				/*ftp ������*/
	DWORD	dwFTPPort;				/*ftp�˿�*/
	BYTE	sUserName[NAME_LEN];	/*�û���*/
	BYTE	sPassword[PASSWD_LEN];	/*����*/
	DWORD	dwDirLevel;	/*0 = ��ʹ��Ŀ¼�ṹ��ֱ�ӱ����ڸ�Ŀ¼,1 = ʹ��1��Ŀ¼,2=ʹ��2��Ŀ¼*/
	WORD 	wTopDirMode;	/* һ��Ŀ¼��0x1 = ʹ���豸��,0x2 = ʹ���豸��,0x3 = ʹ���豸ip��ַ��0x4=ʹ�ü���,0x5=ʹ��ʱ��(����)*/
	WORD 	wSubDirMode;	/* ����Ŀ¼��0x1 = ʹ��ͨ����,0x2 = ʹ��ͨ���ţ�,0x3=ʹ��ʱ��(������),0x4=ʹ�ó�����*/
	BYTE 	byRes[24];
}NET_DVR_FTPCFG, *LPNET_DVR_FTPCFG;

/*����������ͼƬ�����Ԫ�� */
#define PICNAME_ITEM_DEV_NAME 	1		/*�豸��*/
#define PICNAME_ITEM_DEV_NO 	2		/*�豸��*/
#define PICNAME_ITEM_DEV_IP 	3		/*�豸IP*/
#define PICNAME_ITEM_CHAN_NAME 	4		/*ͨ����*/
#define PICNAME_ITEM_CHAN_NO 	5		/*ͨ����*/
#define PICNAME_ITEM_TIME 		6		/*ʱ��*/
#define PICNAME_ITEM_CARDNO		7		/*����*/
#define PICNAME_ITEM_PLATE_NO       8   /*���ƺ���*/
#define PICNAME_ITEM_PLATE_COLOR    9   /*������ɫ*/
#define PICNAME_ITEM_CAR_CHAN       10  /*������*/
#define PICNAME_ITEM_CAR_SPEED      11  /*�����ٶ�*/
#define PICNAME_ITEM_CARCHAN        12  /*����*/
#define PICNAME_MAXITEM 		15

//ͼƬ����
typedef struct 
{
	BYTE 	byItemOrder[PICNAME_MAXITEM];	/*	�����鶨���ļ������Ĺ��� */
	BYTE 	byDelimiter;		/*�ָ�����һ��Ϊ'_'*/
}NET_DVR_PICTURE_NAME, *LPNET_DVR_PICTURE_NAME;

/* ����ץͼ����*/
typedef struct 
{
	BYTE	byStrFlag;	/*�������ݿ�ʼ��*/
	BYTE 	byEndFlag;	/*������*/
	WORD	wCardIdx;	/*���������ʼλ*/
	DWORD 	dwCardLen;	/*���ų���*/
	DWORD   dwTriggerPicChans;	/*��������ͨ���ţ���λ���ӵ�1λ��ʼ�ƣ���0x2��ʾ��һͨ��*/
}NET_DVR_SERIAL_CATCHPIC_PARA, *LPNET_DVR_SERIAL_CATCHPIC_PARA;

//DVRץͼ�������ã����ߣ�
typedef struct 
{
	DWORD	dwSize;
	NET_DVR_JPEGPARA struJpegPara[MAX_CHANNUM_V30];	/*ÿ��ͨ����ͼ�����*/
	WORD	wBurstMode;							/*ץͼ��ʽ,��λ����.0x1=�������봥����0x2=�ƶ���ⴥ�� 0x4=232������0x8=485������0x10=���紥��*/
	WORD	wUploadInterval;					/*ͼƬ�ϴ����(��)[0,65535]*/
	NET_DVR_PICTURE_NAME 	struPicNameRule;	/* ͼƬ�������� */
	BYTE	bySaveToHD;		/*�Ƿ񱣴浽Ӳ��*/
	BYTE	byRes1;
	WORD	wCatchInterval;		/*ץͼ���(����)[0,65535]*/
	BYTE	byRes2[12];
	NET_DVR_SERIAL_CATCHPIC_PARA struRs232Cfg;
	NET_DVR_SERIAL_CATCHPIC_PARA struRs485Cfg;
	DWORD dwTriggerPicTimes[MAX_CHANNUM_V30];	/* ÿ��ͨ��һ�δ������մ��� */
	DWORD dwAlarmInPicChanTriggered[MAX_ALARMIN_V30]; /*��������ץ��ͨ��,��λ���ã��ӵ�1λ��ʼ*/
}NET_DVR_JPEGCFG_V30, *LPNET_DVR_JPEGCFG_V30;

//ץ�Ĵ�������ṹ(����)
typedef struct tagNET_DVR_MANUALSNAP
{
    BYTE byRes[24]; //����
}NET_DVR_MANUALSNAP, *LPNET_DVR_MANUALSNAP;

typedef struct tagNET_DVR_SPRCFG    
{
    DWORD dwSize; 
	BYTE byDefaultCHN[MAX_CHJC_NUM]; /*�豸����ʡ�ݵĺ��ּ�д*/
	BYTE byPlateOSD;    /*0-�����ӳ��Ʋ�ɫͼ,1-���ӳ��Ʋ�ɫͼ*/
	BYTE bySendJPEG1;   /*0-������JPEGͼ1,1-����JPEGͼ1*/
	BYTE bySendJPEG2;   /*0-������JPEGͼ2,1-����JPEGͼ2*/
	WORD wDesignedPlateWidth;   /*������ƿ���*/
	BYTE byTotalLaneNum;  /*ʶ��ĳ�����*/
	BYTE byRes1;      /*����*/
	WORD wRecognizedLane;  /*ʶ��ĳ����ţ���λ��ʾ��bit0��ʾ����1�Ƿ�ʶ��0-��ʶ��1-ʶ��*/
    NET_VCA_RECT struLaneRect[MAX_LANERECT_NUM];  /*����ʶ������*/
	DWORD dwRecogMode;  /*ʶ������ͣ�
	    bit0-����ʶ��0-������ʶ��1-����ʶ��(β��ʶ��) �� 
		bit1-����ʶ���С����ʶ��0-С����ʶ��1-����ʶ�� ��
		bit2-������ɫʶ��0-�����ó�����ɫʶ���ڱ���ʶ���С����ʶ��ʱ��ֹ���ã�1-������ɫʶ��
		bit3-ũ�ó�ʶ��0-������ũ�ó�ʶ��1-ũ�ó�ʶ�� 
		bit4-ģ��ʶ��0-������ģ��ʶ��1-ģ��ʶ��
		bit5-֡��λ�򳡶�λ��0-֡��λ��1-����λ��
		bit6-֡ʶ���ʶ��0-֡ʶ��1-��ʶ�� 
		bit7-���ϻ���죺0-���죬1-���� */
	BYTE byRes2[72];    /*����*/
}NET_DVR_SPRCFG, *LPNET_DVR_SPRCFG;

#define     NET_DVR_GET_PLCCFG    1094   //��ȡ�������Ȳ�������
#define     NET_DVR_SET_PLCCFG    1095  //���ó������Ȳ�������

typedef struct tagNET_DVR_PLCCFG
{
	DWORD dwSize;
	BYTE byPlcEnable;	//�Ƿ����ó������Ȳ�����Ĭ�����ã���0-�رգ�1-���� 
	BYTE byPlateExpectedBright;	//���Ƶ�Ԥ�����ȣ�Ĭ��ֵ50��, ��Χ[0, 100]
	BYTE byRes1[2];	//���� 
	BYTE byTradeoffFlash;     //�Ƿ�������Ƶ�Ӱ��: 0 - ��;  1 - ��(Ĭ��); 
	//ʹ������Ʋ���ʱ, ������Ǽ�������Ƶ�������ǿЧӦ, ����Ҫ��Ϊ1;����Ϊ0
	BYTE byCorrectFactor;     //����ϵ��, ��Χ[0, 100], Ĭ��ֵ50 (��tradeoff_flash�л�ʱ,�ָ�Ĭ��ֵ��
	WORD wLoopStatsEn;  //�Ƿ����Ȧ�����ȣ���λ��ʾ��0-��ͳ�ƣ�1-ͳ��
	BYTE byRes[20];
}NET_DVR_PLCCFG, *LPNET_DVR_PLCCFG;

#define NET_DVR_GET_DEVICESTATECFG              1096   //��ȡ�豸��ǰ״̬����

typedef struct tagNET_DVR_DEVICESTATECFG
{
	DWORD dwSize;
	WORD wPreviewNum; //Ԥ�����Ӹ���
	WORD wFortifyLinkNum; //�������Ӹ���
	NET_DVR_IPADDR struPreviewIP[MAX_LINK];  //Ԥ�����û�IP��ַ
	NET_DVR_IPADDR struFortifyIP[MAX_FORTIFY_NUM]; //�������ӵ��û�IP��ַ
	DWORD dwVideoFrameRate;	//֡�ʣ�0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; 14-15; 15-18; 16-22;
	BYTE byResolution;  	//�ֱ���0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5��������,16-VGA��640*480��, 17-UXGA��1600*1200��, 18-SVGA ��800*600��,19-HD720p��1280*720��,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE bySnapResolution;  	//ץ�ķֱ���0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5��������,16-VGA��640*480��, 17-UXGA��1600*1200��, 18-SVGA ��800*600��,19-HD720p��1280*720��,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE byStreamType; //�������ͣ�0-��������1-������
	BYTE byTriggerType; //����ģʽ��0-��Ƶ������1-��ͨ����
	DWORD dwSDVolume;  //SD������
	DWORD dwSDFreeSpace; //SD��ʣ��ռ�
	BYTE byDetectorState[MAX_DRIVECHAN_NUM][MAX_COIL_NUM];  //������״̬��0-δʹ�ã�1-������2-�쳣
	BYTE byDetectorLinkState; //����������״̬��0-δ���ӣ�1-����
	BYTE byRes2[127]; //����
}NET_DVR_DEVICESTATECFG, *LPNET_DVR_DEVICESTATECFG;

typedef struct tagNET_DVR_POSTEPOLICECFG
{
	DWORD dwSize;
	DWORD dwDistance;//��Ȧ����,��λcm��ȡֵ��Χ[0,20000]
	DWORD	dwLightChan[MAX_SIGNALLIGHT_NUM];	//�źŵ�ͨ����
	BYTE	byCapSpeed;//��־���٣���λkm/h��ȡֵ��Χ[0,255]
	BYTE	bySpeedLimit;//����ֵ����λkm/h��ȡֵ��Χ[0,255]
	BYTE	byTrafficDirection;//��������0-�ɶ�������1-�����򶫣�2-�����򱱣�3-�ɱ�����
	BYTE	byRes[129];//�����ֽ�
}NET_DVR_POSTEPOLICECFG, *LPNET_DVR_POSTEPOLICECFG;


NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);
/***************************** end *********************************************/

#define IPC_PROTOCOL_NUM      50   //ipc Э��������

//Э������
typedef struct tagNET_DVR_PROTO_TYPE
{ 
    DWORD dwType;               /*ipcЭ��ֵ*/    
    BYTE  byDescribe[DESC_LEN]; /*Э�������ֶ�*/    
}NET_DVR_PROTO_TYPE, LPNET_DVR_PROTO_TYPE;

//Э���б�
typedef struct tagNET_DVR_IPC_PROTO_LIST
{    
	DWORD   dwSize; 
	DWORD   dwProtoNum;           /*��Ч��ipcЭ����Ŀ*/   
    NET_DVR_PROTO_TYPE struProto[IPC_PROTOCOL_NUM];   /*��Ч��ipcЭ��*/    
    BYTE    byRes[8];
}NET_DVR_IPC_PROTO_LIST, *LPNET_DVR_IPC_PROTO_LIST;

//������������
typedef struct tagNET_DVR_SMART_SEARCH_PARAM
{
	BYTE	  byChan;					//ͨ����
    BYTE      byRes1[3];
	NET_DVR_TIME struStartTime;		//¼��ʼ��ʱ��
	NET_DVR_TIME struEndTime;		//¼��ֹͣ��ʱ��
    BYTE byMotionScope[64][96];		//�������,0-96λ,��ʾ64��,����96*64��С���,Ϊ1��ʾ���ƶ��������,0-��ʾ����
    BYTE  bySensitivity;   			//����������,1	>80%  2 40%~80%  3 1%~40%
	
    BYTE byRes2[11];
}NET_DVR_SMART_SEARCH_PARAM, *LPNET_DVR_SMART_SEARCH_PARAM;

typedef struct tagNET_DVR_SMART_SEARCH_RET
{
	NET_DVR_TIME struStartTime;	//�ƶ���ⱨ����ʼ��ʱ��
	NET_DVR_TIME struEndTime;   //�¼�ֹͣ��ʱ��
	BYTE byRes[64];
}NET_DVR_SMART_SEARCH_RET, *LPNET_DVR_SMART_SEARCH_RET;

// IPSAN �ļ�Ŀ¼����
typedef struct tagNET_DVR_IPSAN_SERACH_PARAM
{
    NET_DVR_IPADDR  struIP;     // IPSAN IP��ַ
    WORD            wPort;      // IPSAN  �˿�
    BYTE            byRes[10];  // �����ֽ�
}NET_DVR_IPSAN_SERACH_PARAM, *LPNET_DVR_IPSAN_SERACH_PARAM;

typedef struct tagNET_DVR_IPSAN_SERACH_RET
{
    BYTE byDirectory[128];  // ���ص��ļ�Ŀ¼
    BYTE byRes[20];
}NET_DVR_IPSAN_SERACH_RET, *LPNET_DVR_IPSAN_SERACH_RET;

//DVR�豸����
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR����
	DWORD dwDVRID;				//DVR ID,����ң���� //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//�Ƿ�ѭ��¼��,0:����; 1:��
	//���²��ɸ���
	BYTE sSerialNumber[SERIALNO_LEN];  //���к�
	DWORD dwSoftwareVersion;			//�����汾��,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwSoftwareBuildDate;			//������������,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP�����汾,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwDSPSoftwareBuildDate;		// DSP������������,0xYYYYMMDD
	DWORD dwPanelVersion;				// ǰ���汾,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwHardwareVersion;	// Ӳ���汾,��16λ�����汾,��16λ�Ǵΰ汾
	BYTE byAlarmInPortNum;		//DVR�����������
	BYTE byAlarmOutPortNum;		//DVR�����������
	BYTE byRS232Num;			//DVR 232���ڸ���
	BYTE byRS485Num;			//DVR 485���ڸ��� --
	BYTE byNetworkPortNum;		//����ڸ���
	BYTE byDiskCtrlNum;			//DVR Ӳ�̿���������
	BYTE byDiskNum;				//DVR Ӳ�̸���
	BYTE byDVRType;				//DVR����, 1:DVR 2:ATM DVR 3:DVS ......--
	BYTE byChanNum;				//DVR ͨ������
	BYTE byStartChan;			//��ʼͨ����,����DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR ����·��
	BYTE byVGANum;				//VGA�ڵĸ��� --
	BYTE byUSBNum;				//USB�ڵĸ���
    BYTE byAuxoutNum;			//���ڵĸ���
    BYTE byAudioNum;			//�����ڵĸ���
	BYTE byIPChanNum;			//�������ͨ����  --
	BYTE byZeroChanNum;			//��ͨ���������
    BYTE bySupport;        //������λ����Ϊ0��ʾ��֧�֣�1��ʾ֧�֣�
    //bySupport & 0x1, ��ʾ�Ƿ�֧����������
    //bySupport & 0x2, ��ʾ�Ƿ�֧�ֱ���
    //bySupport & 0x4, ��ʾ�Ƿ�֧��ѹ������������ȡ
    //bySupport & 0x8, ��ʾ�Ƿ�֧�ֶ�����
    //bySupport & 0x10, ��ʾ֧��Զ��SADP
    //bySupport & 0x20  ��ʾ֧��Raid������
    // bySupport & 0x40 ��ʾ֧��IPSAN����
	BYTE byEsataUseage;		//Esata��Ĭ����;��0-Ĭ�ϱ��ݣ�1-Ĭ��¼��
    BYTE byIPCPlug;			//0-��֧�ּ��弴�ã�1-֧�ּ��弴��
	BYTE byRes[44];			//����
}NET_DVR_DEVICECFG_V40, *LPNET_DVR_DEVICECFG_V40;

#define MAX_ZEROCHAN_NUM    16
//��ͨ��ѹ�����ò���
typedef struct tagNET_DVR_ZEROCHANCFG
{
	DWORD dwSize;			//�ṹ����
	BYTE  byEnable;			//0-ֹͣ��ͨ�����룬1-��ʾ������ͨ������
	BYTE  byRes1[3];			//����
	DWORD dwVideoBitrate; 	//��Ƶ���� 0-���� 1-16K(����) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//���λ(31λ)�ó�1��ʾ���Զ�������, 0-30λ��ʾ����ֵ(MIN-32K MAX-8192K)��
	DWORD dwVideoFrameRate;	//֡�� 0-ȫ��; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0����14-15, 15-18, 16-22;
	BYTE  byRes2[32];        //����
}NET_DVR_ZEROCHANCFG, *LPNET_DVR_ZEROCHANCFG;

//��ͨ�����Ų���
typedef struct tagNET_DVR_ZERO_ZOOMCFG
{
	DWORD dwSize;			    //�ṹ����
	NET_VCA_POINT  struPoint;	//�����е������
	BYTE byState;			    //���ڵ�״̬��0-��С��1-�Ŵ�  
    BYTE byPreviewNumber;       //Ԥ����Ŀ,0-1����,1-4����,2-9����,3-16���� �ò���ֻ��
	BYTE byPreviewSeq[MAX_WINDOW_V30];//����ͨ����Ϣ �ò���ֻ��
    BYTE byRes[30];				//���� 
}NET_DVR_ZERO_ZOOMCFG, *LPNET_DVR_ZERO_ZOOMCFG;

#define DESC_LEN_64 64
typedef struct tagNET_DVR_SNMPCFG
{
    DWORD   dwSize;			//�ṹ����
    BYTE    byEnable;			//0-����SNMP��1-��ʾ����SNMP
    BYTE    byRes1[3];			//����
    WORD    wVersion;		//snmp �汾  v1 = 1, v2 =2, v3 =3���豸Ŀǰ��֧�� v3
    WORD    wServerPort; //snmp��Ϣ���ն˿ڣ�Ĭ�� 161
    BYTE    byReadCommunity[NAME_LEN]; //����ͬ�壬���31,Ĭ��"public"
    BYTE    byWriteCommunity[NAME_LEN];//д��ͬ��,���31 �ֽ�,Ĭ�� "private"
    BYTE 	byTrapHostIP [DESC_LEN_64];	//��������ip��ַ������֧��IPV4 IPV6����������    
    WORD    wTrapHostPort;   // trap�����˿�
    BYTE    byRes2[102];        // ����
}NET_DVR_SNMPCFG, *LPNET_DVR_SNMPCFG;


#define  PROCESSING          0     //���ڴ���
#define  PROCESS_SUCCESS     100   //�������
#define  PROCESS_EXCEPTION   400   //�����쳣
#define  PROCESS_FAILED      500   //����ʧ��


#define  SOFTWARE_VERSION_LEN 48
typedef struct tagNET_DVR_SADPINFO
{
    NET_DVR_IPADDR  struIP;     // �豸IP��ַ
    WORD            wPort;      // �豸�˿ں�
    WORD            wFactoryType;   // �豸��������
    char        chSoftwareVersion[SOFTWARE_VERSION_LEN];
    char        chSerialNo[16]; // ���к�
    WORD       wEncCnt;       // ����ͨ������
    BYTE	    byMACAddr[MACADDR_LEN];		// MAC ��ַ
    NET_DVR_IPADDR  struSubDVRIPMask;   // DVR IP��ַ����
    NET_DVR_IPADDR  struGatewayIpAddr;  // ����
    NET_DVR_IPADDR	struDnsServer1IpAddr;			/* ����������1��IP��ַ */
    NET_DVR_IPADDR	struDnsServer2IpAddr;			/* ����������2��IP��ַ */
    BYTE        byDns;
    BYTE        byDhcp;
    BYTE        byRes[158];     // �����ֽ�
}NET_DVR_SADPINFO, *LPNET_DVR_SADPINFO;

#define  MAX_SADP_NUM   256   // �������豸�����Ŀ
typedef struct tagNET_DVR_SADPINFO_LIST
{
    DWORD               dwSize;   //  �ṹ��С
    WORD                wSadpNum;   // �������豸��Ŀ
    BYTE                byRes[6];   // �����ֽ�
    NET_DVR_SADPINFO    struSadpInfo[MAX_SADP_NUM]; // ����
}NET_DVR_SADPINFO_LIST, *LPNET_DVR_SADPINFO_LIST;

typedef struct tagNET_DVR_SADP_VERIFY
{
    char chPassword[PASSWD_LEN];
    NET_DVR_IPADDR struOldIP;
    WORD        wOldPort;
    BYTE        byRes[62];
}NET_DVR_SADP_VERIFY, *LPNET_DVR_SADP_VERIFY;

/*******************************���ݽӿ� begin********************************/
//��ȡ�����豸��Ϣ�ӿڶ���
#define DESC_LEN_32          32   //�����ֳ���
#define MAX_NODE_NUM         256  //�ڵ����

typedef struct tagNET_DVR_DESC_NODE
{ 
    int  iValue;           
    BYTE  byDescribe[DESC_LEN_32]; //�����ֶ� 
    DWORD  dwFreeSpace;           //��ȡ�����б�ר��,��λΪM
    BYTE  byRes[12];			  //����  
}NET_DVR_DESC_NODE, *LPNET_DVR_DESC_NODE;

typedef struct tagNET_DVR_DISKABILITY_LIST
{ 
    DWORD     dwSize;            //�ṹ����
    DWORD     dwNodeNum;		 //����������
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //��������  
}NET_DVR_DISKABILITY_LIST, *LPNET_DVR_DISKABILITY_LIST;

//���ݽ����б�
#define BACKUP_SUCCESS                100  //�������

#define BACKUP_SEARCH_DEVICE          300  //�������������豸
#define BACKUP_SEARCH_FILE            301  //��������¼���ļ�

#define BACKUP_EXCEPTION			  400  //�����쳣
#define BACKUP_FAIL					  500  //����ʧ��

#define BACKUP_TIME_SEG_NO_FILE       501  //ʱ�������¼���ļ�
#define BACKUP_NO_RESOURCE            502  //���벻����Դ
#define BACKUP_DEVICE_LOW_SPACE       503  //�����豸��������
#define BACKUP_DISK_FINALIZED         504  //��¼���̷���
#define BACKUP_DISK_EXCEPTION         505  //��¼�����쳣
#define BACKUP_DEVICE_NOT_EXIST       506  //�����豸������
#define BACKUP_OTHER_BACKUP_WORK      507  //���������ݲ����ڽ���
#define BACKUP_USER_NO_RIGHT          508  //�û�û�в���Ȩ��
#define BACKUP_OPERATE_FAIL           509  //����ʧ��

//���ݹ��̽ӿڶ���
typedef struct tagNET_DVR_BACKUP_NAME_PARAM
{
    DWORD dwFileNum;   //�ļ�����
    NET_DVR_FINDDATA_V30 struFileList[MAX_RECORD_FILE_NUM]; //�ļ��б�
    BYTE byDiskDes[DESC_LEN_32];   //���ݴ�������
    BYTE byWithPlayer;      //�Ƿ񱸷ݲ�����
    BYTE byRes[35];         //����
}NET_DVR_BACKUP_NAME_PARAM, *LPNET_DVR_BACKUP_NAME_PARAM;

typedef struct tagNET_DVR_BACKUP_TIME_PARAM
{
    LONG            lChannel;        // ��ʱ�䱸�ݵ�ͨ��
    NET_DVR_TIME    struStartTime;   // ���ݵ���ʼʱ��
    NET_DVR_TIME    struStopTime;    // ���ݵ���ֹʱ��
    BYTE byDiskDes[DESC_LEN_32];     //���ݴ�������
    BYTE byWithPlayer;               //�Ƿ񱸷ݲ�����
    BYTE            byRes[35];       // �����ֽ� 
}NET_DVR_BACKUP_TIME_PARAM, *LPNET_DVR_BACKUP_TIME_PARAM;
/********************************* end *******************************************/

typedef enum _COMPRESSION_ABILITY_TYPE_
{
    COMPRESSION_STREAM_ABILITY = 0, //����ѹ������
		MAIN_RESOLUTION_ABILITY = 1,   //������ѹ���ֱ���
		SUB_RESOLUTION_ABILITY  = 2,   //������ѹ���ֱ���
		EVENT_RESOLUTION_ABILITY =  3,   //�¼�ѹ�������ֱ���
		FRAME_ABILITY = 4,        //֡������
		BITRATE_TYPE_ABILITY = 5,     //λ����������
		BITRATE_ABILITY = 6      //λ������
}COMPRESSION_ABILITY_TYPE;

//�����б�
typedef struct tagNET_DVR_ABILITY_LIST
{ 
    DWORD     dwAbilityType;		//�������� COMPRESSION_ABILITY_TYPE
    BYTE      byRes[32];            //�����ֽ�
    DWORD     dwNodeNum;		//����������
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //��������  
}NET_DVR_ABILITY_LIST, *LPNET_DVR_ABILITY_LIST;

#define MAX_ABILITYTYPE_NUM  12   //���������
// ѹ�����������б�
typedef struct tagNET_DVR_COMPRESSIONCFG_ABILITY
{ 
    DWORD     dwSize;            //�ṹ����
    DWORD     dwAbilityNum;		//�������͸���
    NET_DVR_ABILITY_LIST struAbilityNode[MAX_ABILITYTYPE_NUM]; //��������  
}NET_DVR_COMPRESSIONCFG_ABILITY, *LPNET_DVR_COMPRESSIONCFG_ABILITY;

/********************************9000RH begin****************************************/
#define SUPPORT_PD_NUM			16
#define SUPPORT_ARRAY_NUM		8
#define SUPPORT_VD_NUM			128

typedef enum tagRAID_MODE
{
    RAID0 = 1,
    RAID1,
    RAID10,
    RAID1E,
    RAID5,
    RAID6,
    RAID50,
    JBOD, 
    RAID60
}RAID_MODE;

typedef enum tagHD_SUPPORT_TYPE
{
    HD_TYPE_SATA    = 0x01,
    HD_TYPE_PATA    = 0x02,
    HD_TYPE_SAS     = 0x04,
    HD_TYPE_ATAPI   = 0x08,
    HD_TYPE_TAPE    = 0x10,
    HD_TYPE_SES     = 0x20
}HD_SUPPORT_TYPE;

// ��λ��ʾ λΪ0��ʾ��֧��  1��ʾ֧��
typedef enum tagSUPPORT_RAID_TYPE
{
    RAID0_ABILITY   = 0x0001,
    RAID1_ABILITY   = 0x0002,
    RAID10_ABILITY  = 0x0004,
    RAID1E_ABILITY  = 0x0008,
    RAID5_ABILITY   = 0x0010,
    RAID6_ABILITY   = 0x0020,
    RAID50_ABILITY  = 0x0040,
    JBOD_ABILITY    = 0x0080,
    RAID60_ABILITY  = 0x0100
}SUPPORT_RAID_TYPE;

// �������� 
typedef struct tagNET_DVR_PHY_DISK_INFO
{
    WORD    wPhySlot;         // Ӳ�̲�λ 
    BYTE    byType;         // Ӳ����Ϣ��0 ��ͨ��1ȫ���ȱ���2-�����ȱ�
    BYTE    byStatus;       // Ӳ��״̬�� 1-����
    BYTE    byMode[40];   // Ӳ������ �ַ���
    DWORD   dwHCapacity;    //  ����������32λ ��λkb
    DWORD   dwLCapacity;    //  ����������32λ
    BYTE    byArrrayName[MAX_NAMELEN];
    WORD    wArrayID;          // ��������ID
    BYTE    byRes[102];         // �����ֽ�  
}NET_DVR_PHY_DISK_INFO, *LPNET_DVR_PHY_DISK_INFO;

typedef struct tagNET_DVR_PHY_DISK_LIST
{
    DWORD   dwSize;
    DWORD   dwCount;
    NET_DVR_PHY_DISK_INFO struPhyDiskInfo[SUPPORT_PD_NUM];
}NET_DVR_PHY_DISK_LIST, *LPNET_DVR_PHY_DISK_LIST;

typedef enum tagBGA_TYPE
{
    BGA_REBUILD = 0x01,            // �ؽ�
    BGA_CONSISTENCY_FIX = 0x02,    // һ���Լ�鲢�޸�
    BGA_CONSISTENCY_CHECK = 0x04,  // һ���Լ��
    BGA_INIT_QUICK = 0x08,         // ��ʼ��(��)
    BGA_INIT_BACK = 0x10,          // ��ʼ��(��ȫ)
    BGA_MIGRATION = 0x20,       // Ǩ��
    BGA_INIT_FORE = 0x40,           // ��ʼ��
    BGA_COPYBACK = 0x80             // ��Ǩ
}BGA_TYPE;

typedef enum tagBGA_STATE
{
    BGA_STATE_NONE = 0,     //  �޺�̨����
    BGA_STATE_RUNNING,       //  ��̨������������
    BGA_STATE_ABORTED,       //  ��̨����ȡ��
    BGA_STATE_PAUSED        //  ��̨������ͣ
}BGA_STATE;
typedef struct tagNET_DVR_BGA_INFO
{
	BYTE            byBga;  // ��̨�������� 
	BYTE			 byBgaState;		   /*��������ֵ--��̨����״̬*/
	WORD    	wBgaPercentage;     /*��������ֵ--��̨����ִ�аٷֱ�*/
	BYTE    byRes[4];  // �����ֽ�
}NET_DVR_BGA_INFO, *LPNET_DVR_BGA_INFO;

// ������Ϣ
typedef struct tagNET_DVR_ARRAY_INFO
{
    WORD    wArrayID; // ����ID
    BYTE    byRaidMode; // raidģʽ  ����RAID_MODE
    BYTE    byStatus;  // 0-����1-���̶�ʧ2-������
    DWORD   dwHCapacity; // ����������32λ
    DWORD   dwLCapacity; // ����������32λ
    DWORD   dwHFreeSpace;   // ����ʣ��ռ��32λ
    DWORD   dwLFreeSpace;   // ����ʣ��ռ��32λ
    BYTE    byArrayName[MAX_NAMELEN]; // ��������
    BYTE    byPDCount;  // ����������Ŀ
    BYTE    bySpareCount;   // �ȱ���Ŀ
    BYTE    byRes1[2];
    WORD    wPDSlots[SUPPORT_PD_NUM];	// ������������
    WORD    wSparePDSlots[SUPPORT_PD_NUM];	// �ȱ���������
    NET_DVR_BGA_INFO	struBgaInfo;	// ��̨��������״̬
    BYTE    byRes2[80]; // �����ֽ�
}NET_DVR_ARRAY_INFO, *LPNET_DVR_ARRAY_INFO;

typedef struct tagNET_DVR_ARRAY_LIST
{
    DWORD   dwSize;     // �ṹ���С
    DWORD   dwCount;    // ���и���
    NET_DVR_ARRAY_INFO struArrayInfo[SUPPORT_ARRAY_NUM];
}NET_DVR_ARRAY_LIST, *LPNET_DVR_ARRAY_LIST;

//���������Ϣ
typedef struct tagNET_DVR_VD_INFO
{
    WORD    wSlot;    //������̲�λ  
    BYTE    byStatus; // ״̬0-���� 1-���� 2-��ɾ�� 3-���̶�ʧ 4-���� 5-������ 6-����
    BYTE    byRaidMode; // Raid ģʽ ���� RAID_MODE
    WORD    wArrayID;      // ��������ID
    BYTE    byRepair;   // �Ƿ���Ҫ�޸� 0 ����Ҫ 1��Ҫ
    BYTE    byRes1[1];  // �����ֽ�
    BYTE	byArrayName[MAX_NAMELEN];
    BYTE    byName[MAX_NAMELEN];    // �������������
    DWORD   dwHCapacity;    // �������������32λ
    DWORD   dwLCapacity;    // �������������32λ
    DWORD   dwHFreeSpace;   // �������ʣ��ռ��32λ
    DWORD   dwLFreeSpace;   // �������ʣ��ռ��32λ
    NET_DVR_BGA_INFO	struBgaInfo;	// ��̨����״̬
    BYTE    byRes2[80];
}NET_DVR_VD_INFO, *LPNET_DVR_VD_INFO;

typedef struct tagNET_DVR_VD_LIST
{
    DWORD   dwSize;     // �ṹ���С
    DWORD   dwCount;    // ������̸���
    NET_DVR_VD_INFO struVDInfo[SUPPORT_VD_NUM];  //�����������
}NET_DVR_VD_LIST, *LPNET_DVR_VD_LIST;

typedef struct tagNET_DVR_ADAPTER_VERSION
{
    WORD    wMajorVersion;
    WORD    wMinorVersion;
    WORD    wRevisionNumber;
    WORD    wBuildNumber;
}NET_DVR_ADAPTER_VERSION, *LPNET_DVR_ADAPTER_VERSION;

typedef struct tagNET_DVR_VD_SLOT
{
    WORD wVDSlot;
    BYTE  byAlloc;  // �Ƿ��Ѿ�����
    BYTE    byRes[5];
    DWORD dwHVDSlotSize;	// ������̿ռ��С��32λ
	DWORD dwLVDSlotSize;	// ������̿ռ��С��32λ
}NET_DVR_VD_SLOT, *LPNET_DVR_VD_SLOT;

typedef struct tagNET_DVR_ARRAY_SPACE_ALLOC_INFO
{
    BYTE    byVDSlotCount;						/*current number of slots in DG*/ 
    BYTE    byRes1[3];              // �����ֽ�
    NET_DVR_VD_SLOT struVDSlots[SUPPORT_VD_NUM];
}NET_DVR_ARRAY_SPACE_ALLOC_INFO, *LPNET_DVR_ARRAY_SPACE_ALLOC_INFO;

typedef struct tagNET_DVR_RAID_ADAPTER_INFO
{
    DWORD dwSize;    // �ṹ���С
    NET_DVR_ADAPTER_VERSION struVersion;	// �������汾��
    BYTE    bySlotCount;    //��������λ��
    BYTE    bySupportMigrate;  // Ǩ��(1-֧��  0-��֧��)
    BYTE    bySupportExpand;   // ����  (1-֧��  0-��֧��)
    BYTE    bySupportRebuild;  // �Ƿ�֧���ؽ����� (1��֧�� 0-��֧��)
    WORD    wSlotSupportType; //  ��λ��ʾ HD_SUPPORT_TYPE
    WORD    wSupportRaidType;      // ֧��Raid ���� ��λ��ʾ  
    BYTE    byAutoRebuild;      // 0 ���Զ��ؽ� 1�Զ��ؽ� ����
    BYTE    byRes[27];      // �����ֽ�
}NET_DVR_RAID_ADAPTER_INFO, *LPNET_DVR_RAID_ADAPTER_INFO;

typedef struct tagNET_DVR_OPERATE_ARRAY_PARAM
{
    //�Ƿ�һ������  ���Ϊһ���������򴴽�ʱʱ���֮��Ҫarray���ƣ�������Ҫ��������
    // �����������豸���д���
    BYTE    byRaidMode;     // ����/Ǩ��ʱRaid������
    BYTE    byPDCount;  // ����������Ŀ
    WORD        wArrayID;   // Ǩ�ƻ����ؽ�ʱ��Ҫָ������ID      
    WORD    wPDSlots[SUPPORT_PD_NUM];// �������� 
    BYTE    byName[MAX_NAMELEN];  // array ����
    BYTE    byRes2[20];
}NET_DVR_OPERATE_ARRAY_PARAM, *LPNET_DVR_OPERATE_ARRAY_PARAM;


typedef struct tagNET_DVR_OPERATE_VD_PARAM
{
    WORD    wArrayID;		// ����ID
    BYTE    bySlot;			// �����������ָ����λ
    BYTE    byRes1;			// �����ֽ�
	DWORD	dwHCapacity;	// ������̴�С��32λ
	DWORD	dwLCapacity;	// ������̴�С��32λ
    BYTE    byName[MAX_NAMELEN]; // �����������
    BYTE    byRes2[16];          // �����ֽ� 
}NET_DVR_OPERATE_VD_PARAM, *LPNET_DVR_OPERATE_VD_PARAM;


typedef struct tagNET_DVR_SPARE_DISK_PARAM
{
    WORD    wPDSlot;        // �������̲�λ
    WORD    wArrayID;       // ����������
    BYTE    bySpareType;    // �ȱ����� 1-ȫ���ȱ�  2 ָ������  ��Ϊָ�����е�ʱ����Ҫָ���������е�ID
    BYTE    byRes[7];       // �����ֽ�
}NET_DVR_SPARE_DISK_PARAM, *LPNET_DVR_SPARE_DISK_PARAM;

/********************************9000RH End****************************************/


#define MATRIX_MAXDECSUBSYSTEMCHAN	4//��Ƶ�ۺ�ƽ̨������ϵͳͨ����

//��ȡ������ϵͳ������Ϣ
typedef struct tagNET_DVR_DECSUBSYSTEMJIONSTATUS
{
    BYTE	byJoinStatus;//����״̬��0-û�й�����1-�Ѿ�����
    BYTE	byJoinSubSystem;//��������ϵͳ��λ��
    BYTE	byJoinDispNum;//��������ʾͨ����
    BYTE	byJoinSubWindowNum;//�������Ӵ��ں�
    BYTE	byRes[4];
}NET_DVR_DECSUBSYSTEMJIONSTATUS,LPNET_DVR_DECSUBSYSTEMJIONSTATUS;

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO
{
    BYTE	bySubSystemType;//��ϵͳ���ͣ�0-�ޣ�1-��������ϵͳ��2-��������ϵͳ��3-���������ϵͳ��4-����������ϵͳ,5-�����ϵͳ��6-������ϵͳ
    BYTE	byConnectStatus;//����ϵͳ����״̬��1-����������2-���ӶϿ�
    BYTE    byMatrixNum;//������Ƶ�ۺ�ƽ̨�ţ���ϵͳ������3��4ʱ����
    BYTE	bySubSystemNum;//������ϵͳ��λ�ţ�0~79����ϵͳ������3��4ʱ����    
    NET_DVR_DECSUBSYSTEMJIONSTATUS struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
    BYTE	byBindStatus;//��״̬��0-û�а󶨣�1-�Ѿ��󶨣�����ƴ��ʱ�õ���
    BYTE    byRes[7];
}NET_DVR_SINGLESUBSYSTEMJOININFO,LPNET_DVR_SINGLESUBSYSTEMJOININFO;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO
{
    DWORD dwSize;
    NET_DVR_SINGLESUBSYSTEMJOININFO struSingleSubSystemJoinInfo [MAX_SUBSYSTEM_NUM];//80
    BYTE  byRes[8];
}NET_DVR_ALLDECSUBSYSTEMJOININFO, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO;

//2010-04-13 ����NAT�����������
typedef struct tagNET_DVR_NATASSOCIATECFG
{
	DWORD		  		dwSize;
    NET_DVR_NETCFG_V30  struNatIpAddress[2];//NAT IP��ַ 
	BYTE				byNATEnable;//�Ƿ�����NAT���ܣ�0-�����ã�1-����
	BYTE		  		byRes[63];
}NET_DVR_NATASSOCIATECFG, *LPNET_DVR_NATASSOCIATECFG;

//2010-06-01 ��Ƶ�ۺ�ƽ̨��������
typedef struct tagNET_DVR_TEMPERATUREALARMCFG
{
	BYTE	 byEnableTemperatureAlarm;//ʹ���¶ȳ��ޱ�����0-������1-������
    BYTE	 byRes1[3];
	int 	 iTemperatureUpLimited;	//��ȷ��С�������λ����1234��ʾ�¶�12.34��
	int 	 iTemperatureDownLimited;	
	NET_DVR_HANDLEEXCEPTION_V30 struTempHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*����ʱ��*/
	BYTE	 byRes2[32];
}NET_DVR_TEMPERATUREALARMCFG, *LPNET_DVR_TEMPERATUREALARMCFG;

typedef struct tagNET_DVR_BOARDALARMCFG
{
	BYTE   byEnablePullAlarm;//�Ȳ�α���ʹ�ܣ�1-������0-������
    BYTE   byRes1[3];
	NET_DVR_HANDLEEXCEPTION_V30 struBoardHandleType;	/* ������ʽ */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*����ʱ��*/
	BYTE   byRes2[32];
}NET_DVR_BOARDALARMCFG, *LPNET_DVR_BOARDALARMCFG;


typedef struct tagNET_DVR_VIDEOPLATFORMALARMCFG
{
	DWORD 						 dwSize;
	NET_DVR_TEMPERATUREALARMCFG  struTempAlarmCfg;	
	NET_DVR_BOARDALARMCFG 		 struBoardAlarmCfg;	
    NET_DVR_HANDLEEXCEPTION_V30  struHandleException[MAX_EXCEPTIONNUM];//0-�����쳣��1-��ϵͳ�쳣��2-IP��ַ��ͻ��3-���߶ϣ�4-�Ƿ����ʣ�5-�����쳣��6-ǰ����쳣
    BYTE						 byRes[32];
}NET_DVR_VIDEOPLATFORMALARMCFG,*LPNET_DVR_VIDEOPLATFORMALARMCFG;
//2010-05-17
typedef struct  tagNET_DVR_CODESPLITTERASSOCIATE
{
	DWORD		dwSize;
	NET_DVR_IPADDR   struIP;  /*������IP��ַ*/
	WORD		wPort;        //�������˿ں�
	BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* �û�����32�� */
	BYTE		sPassword[PASSWD_LEN];	/*���� ��16��*/
	BYTE        byChan;//������ͨ����
	BYTE		byRes2[15];
} NET_DVR_CODESPLITTERASSOCIATE, *LPNET_DVR_CODESPLITTERASSOCIATE;

//2010-06-01 ��Ƶ�ۺ�ƽ̨�����ϴ��ṹ
typedef struct tagNET_DVR_MATRIXSUBSYSTEMINFO
{
	BYTE   byMatrixNum;//��Ƶ�ۺ�ƽ̨��
	BYTE	bySubSystemNum;//��ϵͳ��λ��
	BYTE   byRes [14];
} NET_DVR_MATRIXSUBSYSTEMINFO, *LPNET_DVR_MATRIXSUBSYSTEMINFO;

typedef struct tagNET_DVR_VIDEOPLATFORM_ALRAMINFO
{
	DWORD  dwSize;      //�ṹ���С
	BYTE   byAlarmType;	// 0-�γ��Ӱ壬1-�����Ӱ�,2-�¶ȳ����ޱ�����3-�¶ȳ����ޱ�����4-����״̬�쳣��5-��ϵͳ�쳣,6-�Ƿ����ʣ�7-�����쳣����,8-ǰ����쳣����
	BYTE   byRes1[3];
    BYTE   bySubSystemChan[8]; //�Ӱ��λ��,һ���Ӱ�����8����ϵͳ����ֱ��Ӧ�Ĳ�λ�ţ���ϵͳ�쳣ʱ��bySubSystemChan[0]��ʾ��Ӧ��ϵͳ���        
	int    iTemperature;  //�¶ȳ��ޱ���ʱ���ã��¶�ֵ
	BYTE   byMainboardSeq;//�¶ȳ��ޱ���ʱ���ã�0-�����壬1-����
    BYTE   byRes2[3];
    BYTE   byFanSequence[32];//�����쳣ʱ���Ⱥ�    
	NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;// �����쳣����ʱʹ�ã�������
	NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;//�����쳣����ʱʹ�ã�������
	BYTE   byRes3[68];	
}NET_DVR_VIDEOPLATFORM_ALRAMINFO,*LPNET_DVR_VIDEOPLATFORM_ALRAMINFO;

typedef struct
{
    char sFileName[100];//ͼƬ��
    NET_DVR_TIME struTime;//ͼƬ��ʱ��
    DWORD dwFileSize;//ͼƬ�Ĵ�С
    char sCardNum[32];	//����
}NET_DVR_FIND_PICTURE,*LPNET_DVR_FIND_PICTURE;

/***************************��ѶDVR begin *****************************/
#define MAX_INQUEST_PIP_NUM   3     //��ͨ����ʾ�Ļ��л���Ŀ
#define MAX_INQUEST_CDRW_NUM  4     //����¼����Ŀ

typedef struct 
{
	DWORD      dwSize;
    DWORD      dwNum;                       //��¼��������
	DWORD      dwRwSelectPara[MAX_CHANNUM_V30];// �Ƿ�ѡ�иù���
	DWORD      dwModeSelect;                //0��ʾѭ����¼ģʽ  1��ʾ���п�¼ģʽ(Ĭ��ģʽ)
	BYTE	   byRes[24];                   //����
	DWORD	   dwStartCDRW;                 //DVR �����Ѿ���ʼ��¼
	DWORD      dwHdExcp;                    //Ӳ������ ��
	DWORD	   dwInterval;                  //ʱ������10����(0)��20����(1)��30����(2)
	char 	   sLable[64];                  //��������
}NET_DVR_INQUEST_CDRW_CFG, *LPNET_DVR_INQUEST_CDRW_CFG;

typedef struct
{
    char      sFileName[36];			 //�ļ���
    DWORD     dwFileLen;				 //�ļ�����
}NET_DVR_INQUEST_FILEINFO, *LPNET_DVR_INQUEST_FILEINFO;

typedef struct 
{
    DWORD     dwFileNum;			         // ��Ҫ��¼����ɾ�����ļ��������һ��20��
	NET_DVR_INQUEST_FILEINFO struFileInfo[MAX_RECORD_FILE_NUM];
	//�������������ڱ�ʾ��¼���ļ�ʱʹ��
	DWORD     dwCDIndex;				    //��¼����������1:ѡ��1�ſ�¼����2:ѡ��2�ſ�¼���� 3:3�ſ�¼��,4:4�ſ�¼��,5:���п�¼��
	BOOL      bFinalizeDisc;		     	// 0=��¼��֮�󲻷��̣�1=��¼��֮�����
}NET_DVR_INQUEST_FILES, *LPNET_DVR_INQUEST_FILES;

typedef struct {	
	DWORD     dwEnable;			//��¼��״̬�Ƿ���Ч,0-��Ч,1-��Ч	
	DWORD     dwStatus;			//��dwType=0ʱ��0-����������1-�޹��̻�����쳣	
	//��dwType=1��2ʱ��0-��¼������1-�޹��̻�����쳣��
	//   2-�����ѷ��̣�3-���̿ռ䲻�㣬4-�쳣������Ѷ��ֹ	
	//��dwType=3ʱ��0-��¼������1-�޹��̻�����쳣��
	//   2-�����ѷ��̣�3-���̿ռ䲻��	
	BYTE      byRes[16];		//�����ֽ�	
}NET_DVR_INQUEST_CDRW, *LPNET_DVR_INQUEST_CDRW;

typedef struct {	
	DWORD    dwType;                //����״̬��0-��Ѷ��ʼ��1-��Ѷ�����п�¼��2-��Ѷֹͣ��3-��¼��Ѷ�ļ�	
	NET_DVR_INQUEST_CDRW   strCDRWNum[MAX_INQUEST_CDRW_NUM];   //����0��ʾ��¼��1	
	BYTE     byRes[24];             //����	
}NET_DVR_INQUEST_CDRW_STATUS, *LPNET_DVR_INQUEST_CDRW_STATUS;

typedef struct
{
	BYTE     byPipChan;			  //���л���ʾ��ͨ�� 0xFF�ر�
	BYTE     byRes[3];			  //�����ֽ�
	WORD     wTopLeftX;			  //���л���x����
	WORD     wTopLeftY;			  //���л���Y����
}NET_DVR_INQUEST_PIP_PARAM, *LPNET_DVR_INQUEST_PIP_PARAM;

typedef struct 
{
	BYTE     byBaseChan;          //��ʾ���л����ڵ�ͨ��
	BYTE     byBackChan;          //��ʾ���л�����ͨ��
	BYTE     byPIPMode;           //�Ƿ���, 0:�رջ��л����� 1:�򿪻��л�
	BYTE     byRes;               //�����ֽ�
	NET_DVR_INQUEST_PIP_PARAM  strPipPara[MAX_INQUEST_PIP_NUM];  //����λ�õĲ���    
}NET_DVR_INQUEST_PIP_STATUS, *LPNET_DVR_INQUEST_PIP_STATUS;

typedef struct 
{
	BYTE	sSecretKey[16];        /*����������Կ*/
	BYTE	byRes[64];             /*�����ֽ�*/
}NET_DVR_INQUEST_SECRET_INFO, *LPNET_DVR_INQUEST_SECRET_INFO;

/***************************��ѶDVR end *****************************/

//2011-1-13 һ�������
/***************************һ���************************************/
//�ع���������
typedef struct tagNET_DVR_EXPOSUREGAIN
{
	BYTE byExposureMode; /*ģʽ��0 �ֶ��ع� 1�Զ��ع�2��Ȧ���� 3��������*/
	BYTE byIrisMode; /* ��Ȧ0-10 ��F1.6/ F1.8/ F2.0/ F2.4/ F2.8/ F3.4/ F4.0/ F4.8/ F5.6/ F8.0/ F11*/
	BYTE byShutterSet; /*����0-17�� ��/�Զ�x2/�Զ�x3/�Զ�x4/�Զ�x8/�Զ�x16/�Զ�x32/ 1/25 / 1/30 / 1/50 1/60 / 1/100 / 1/250 / 1/500 / 1/1k / 1/2k / 1/4k / 1/10k*/
	BYTE bygainLevel; /*���棺0-��,1-��,2-��*/
    BYTE byRes[8];
}NET_DVR_EXPOSUREGAIN, *LPNET_DVR_EXPOSUREGAIN;

//��ҹת����������
typedef struct tagNET_DVR_DAYNIGHTZC
{
    BYTE byDayNightFilterType; /*ģʽ��0 day,1 night,2 auto */
    BYTE byDayToNightFilterTime; //����ת��ҹ��ʱ0-7��2s/3s/5s/10s/15s/30s/45s/60s
    BYTE byNightToDayFilterTime; //��ҹת������ʱ0-7��2s/3s/5s/10s/15s/30s/45s/60s
    BYTE byDayNightFilterLevel;//�����ȣ�0-��/1-��/2-�� 
    BYTE byRes[4];
}NET_DVR_DAYNIGHTZC, *LPNET_DVR_DAYNIGHTZC;

//�۽�ģʽ
typedef struct tagNET_DVR_FOCUS
{
	BYTE byFocusMode;/*�۽�ģʽ��0 �Զ�1 һ�ξ۽�2 �ֶ�*/
	BYTE byFocusModeChoose;/*�Զ��۽�ģʽ��0 ģʽһ1 ģʽ��*/
	BYTE byMinFocusDistance;/*��С�۽�����0-4��0.1m/0.5m/1.5m/3m/����Զ*/
	BYTE byZoomSpeed;/*�䱶�ٶ�0-4��1/2/3/4/5��5��*/
	BYTE byRes[4];
}NET_DVR_FOCUS, *LPNET_DVR_FOCUS;

typedef struct tagNET_DVR_ZOOMCAMCFG
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*���ȡ��Աȶȡ����Ͷȡ���ȡ�ɫ������*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*��ƽ��*/
    NET_DVR_EXPOSUREGAIN struExposureGain; /*�ع���������*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*GammaУ��*/
	NET_DVR_WDR struWdr;/*����̬*/
	NET_DVR_DAYNIGHTZC struDayNight;/*��ҹת��*/
	NET_DVR_FOCUS struFocus;//�۽�ģʽ
	NET_DVR_BACKLIGHT struBackLight;/*���ⲹ��*/
	NET_DVR_NOISEREMOVE struNoiseRemove;/*���ֽ���*/
	BYTE byLenInit;/*��ͷ��ʼ����0 ��1 ��*/
    BYTE byDigitalZoom;  /*���ַŴ�0-4����/x2/x4/x8/ x12*/
	BYTE byMirror ;  /* ����0   ��;1   ˮƽ;2   ��ֱ;3  ���� */
	BYTE byZoomDisplay;/*������ʾ��0 ��1 ��*/
	BYTE byZoomLimit; /*��������0-17�� /1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byDeadPixelDetect;   /*������,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*�ڵ�ƽ���� ,  0-255*/ 
	BYTE byEptzGate;// EPTZ���ر���:0������̨1������̨
	BYTE byLocalOutputGate;//����������ر���0-��������ر�1-����BNC����� 2-HDMI����ر�  
	//20-HDMI_720P50�����
	//21-HDMI_720P60�����
	//22-HDMI_1080I60�����
	//23-HDMI_1080I50�����
	//24-HDMI_1080P24�����
	//25-HDMI_1080P25�����
	//26-HDMI_1080P30�����
	//27-HDMI_1080P50�����
	//28-HDMI_1080P60�����
	BYTE byCoderOutputMode;//������fpga���ģʽ0ֱͨ3���ذ��
	BYTE byDynamicContrastEN;    //��̬�Աȶ���ǿ 0-1
	BYTE byDynamicContrast;    //��̬�Աȶ� 0-100
	BYTE byJPEGQuality;    //JPEGͼ������ 0-100
	BYTE byRes[66];
}NET_DVR_ZOOMCAMCFG, *LPNET_DVR_ZOOMCAMCFG;
/***************************һ��� end************************************/

/********************************�ӿڲ����ṹ(end)*********************************/


/********************************SDK�ӿں�������*********************************/
NET_DVR_API BOOL __stdcall NET_DVR_Init();
NET_DVR_API BOOL __stdcall NET_DVR_Cleanup();

//NET_DVR_SetDVRMessage����չ
#ifdef _WIN32
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessage(UINT nMessage,HWND hWnd);
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT nMessage, HWND hWnd, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
#elif defined(__linux__)
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT reserved1, void* reserved2, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
/*Linuxר�� */
NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL = 1);
NET_DVR_API BOOL NET_DVR_DrawAreaRelease();
#endif

NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_EX(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_NEW(BOOL (CALLBACK *fMessCallBack_NEW)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, WORD dwLinkDVRPort));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack(BOOL (CALLBACK *fMessageCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, DWORD dwUser), DWORD dwUser);
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime = 3000, DWORD dwTryTimes = 3);
NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval = 30000, BOOL bEnableRecon = TRUE);
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKVersion();
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKBuildVersion();
NET_DVR_API int __stdcall NET_DVR_IsSupport();
NET_DVR_API BOOL __stdcall NET_DVR_StartListen(char *sLocalIP,WORD wLocalPort);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen();

NET_DVR_API LONG __stdcall NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen_V30(LONG lListenHandle);
NET_DVR_API LONG __stdcall NET_DVR_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_DVR_DEVICEINFO lpDeviceInfo);
NET_DVR_API LONG __stdcall NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Logout(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_Logout_V30(LONG lUserID);
NET_DVR_API DWORD __stdcall NET_DVR_GetLastError();
NET_DVR_API char* __stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_SetShowMode(DWORD dwShowType,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRIPByResolveSvr(char *sServerIP, WORD wServerPort, BYTE *sDVRName,WORD wDVRNameLen,BYTE *sDVRSerialNumber,WORD wDVRSerialLen,char* sGetIP);
NET_DVR_API BOOL  __stdcall NET_DVR_GetDVRIPByResolveSvr_EX(char *sServerIP, WORD wServerPort, unsigned char *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP, DWORD *dwPort);

//Ԥ����ؽӿ�
NET_DVR_API LONG __stdcall NET_DVR_PlayDirect(char *sDVRIP, char *sUserName, char *sPassword, \
											  LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay(LONG lUserID,LPNET_DVR_CLIENTINFO lpClientInfo);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
NET_DVR_API BOOL __stdcall NET_DVR_StopRealPlay(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayDirect(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_RigisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayerBufNumber(LONG lRealHandle,DWORD dwBufNum);
NET_DVR_API BOOL __stdcall NET_DVR_ThrowBFrame(LONG lRealHandle,DWORD dwNum);
NET_DVR_API BOOL __stdcall NET_DVR_SetAudioMode(DWORD dwMode);
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_Volume(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopSaveRealData(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetRealDataCallBack(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetStandardDataCallBack(LONG lRealHandle,void(CALLBACK *fStdDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture(LONG lRealHandle,char *sPicFileName);//bmp

//��̬����I֡
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrame(LONG lUserID, LONG lChannel);//������
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//������

//��̨������ؽӿ�
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_Other(LONG lUserID,LONG lChannel,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_Other(LONG lUserID,LONG lChannel,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_EX(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_EX(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_EX(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_EX(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_EX(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZCruise(LONG lUserID,LONG lChannel,LONG lCruiseRoute, LPNET_DVR_CRUISE_RET lpCruiseRet);


//�ļ�������ط�
NET_DVR_API LONG __stdcall NET_DVR_FindFile(LONG lUserID,LONG lChannel,DWORD dwFileType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile(LONG lFindHandle,LPNET_DVR_FIND_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V30(LONG lFindHandle, LPNET_DVR_FINDDATA_V30 lpFindData);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V30(LONG lUserID, LPNET_DVR_FILECOND pFindCond);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose_V30(LONG lFindHandle);

NET_DVR_API BOOL __stdcall NET_DVR_LockFileByName(LONG lUserID, char *sLockFileName);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByName(LONG lUserID, char *sUnlockFileName);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByName(LONG lUserID,char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, HWND hWnd);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl(LONG lPlayHandle,DWORD dwControlCode,DWORD dwInValue,DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBack(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackSaveData(LONG lPlayHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBackSave(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlayBackOsdTime(LONG lPlayHandle, LPNET_DVR_TIME lpOsdTime);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackCaptureFile(LONG lPlayHandle,char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByName(LONG lUserID,char *sDVRFileName,char *sSavedFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopGetFile(LONG lFileHandle);
NET_DVR_API int __stdcall NET_DVR_GetDownloadPos(LONG lFileHandle);
NET_DVR_API int	__stdcall NET_DVR_GetPlayBackPos(LONG lPlayHandle);

//����
NET_DVR_API LONG __stdcall NET_DVR_AdapterUpgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_Upgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_VcalibUpgrade(LONG lUserID, LONG lChannel, char const *sFileName);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeProgress(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);
//Զ�̸�ʽ��Ӳ��
NET_DVR_API LONG __stdcall NET_DVR_FormatDisk(LONG lUserID,LONG lDiskNumber);
NET_DVR_API BOOL __stdcall NET_DVR_GetFormatProgress(LONG lFormatHandle, LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFormatHandle(LONG lFormatHandle);
//����
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan(LONG lAlarmHandle);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
//�����Խ�
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_V30(LONG lUserID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_StopVoiceCom(LONG lVoiceComHandle);
//����ת��
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR_V30(LONG lUserID, DWORD dwVoiceChan, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceComSendData(LONG lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetCurrentAudioCompress(LONG lUserID, LPNET_DVR_COMPRESSION_AUDIO lpCompressAudio);
//�����㲥
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart();
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart_V30(void(CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer, DWORD dwBufSize, void * pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStop();
NET_DVR_API BOOL __stdcall NET_DVR_AddDVR(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_AddDVR_V30(LONG lUserID, DWORD dwVoiceChan);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR_V30(LONG lVoiceHandle);
////////////////////////////////////////////////////////////
//͸��ͨ������
NET_DVR_API LONG __stdcall NET_DVR_SerialStart(LONG lUserID,LONG lSerialPort,void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
//485��Ϊ͸��ͨ��ʱ����Ҫָ��ͨ���ţ���Ϊ��ͬͨ����485�����ÿ��Բ�ͬ(���粨����)
NET_DVR_API BOOL __stdcall NET_DVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SerialStop(LONG lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SendTo232Port(LONG lUserID, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SendToSerialPort(LONG lUserID, DWORD dwSerialPort, DWORD dwSerialIndex, char *pSendBuf, DWORD dwBufSize);

//���� nBitrate = 16000
NET_DVR_API void* __stdcall NET_DVR_InitG722Decoder(int nBitrate = 16000);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG722Frame(void *pDecHandle, unsigned char* pInBuffer, unsigned char* pOutBuffer);
//����
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,unsigned char* pInBuffer, unsigned char* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);

//Զ�̿��Ʊ�����ʾ
NET_DVR_API BOOL __stdcall NET_DVR_ClickKey(LONG lUserID, LONG lKeyIndex);
//Զ�̿����豸���ֶ�¼��
NET_DVR_API BOOL __stdcall NET_DVR_StartDVRRecord(LONG lUserID,LONG lChannel,LONG lRecordType);
NET_DVR_API BOOL __stdcall NET_DVR_StopDVRRecord(LONG lUserID,LONG lChannel);
//���뿨
NET_DVR_API BOOL __stdcall NET_DVR_InitDevice_Card(long *pDeviceTotalChan);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDevice_Card();
NET_DVR_API BOOL __stdcall NET_DVR_InitDDraw_Card(HWND hParent,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDraw_Card();
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_Card(LONG lUserID,LPNET_DVR_CARDINFO lpCardInfo,long lChannelNum);
NET_DVR_API BOOL __stdcall NET_DVR_ResetPara_Card(LONG lRealHandle,LPNET_DVR_DISPLAY_PARA lpDisplayPara);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_ClearSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_RestoreSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetVolume_Card(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_AudioPreview_Card(LONG lRealHandle,BOOL bEnable);
NET_DVR_API LONG __stdcall NET_DVR_GetCardLastError_Card();
NET_DVR_API HANDLE __stdcall NET_DVR_GetChanHandle_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture_Card(LONG lRealHandle, char *sPicFileName);
//��ȡ���뿨���кŴ˽ӿ���Ч������GetBoardDetail�ӿڻ��(2005-12-08֧��)
NET_DVR_API BOOL __stdcall NET_DVR_GetSerialNum_Card(long lChannelNum,DWORD *pDeviceSerialNo);
//��־
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog(LONG lLogHandle, LPNET_DVR_LOG lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose(LONG lLogHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_V30(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, BOOL bOnlySmart = FALSE);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_V30(LONG lLogHandle, LPNET_DVR_LOG_V30 lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose_V30(LONG lLogHandle);
// ����������־
NET_DVR_API LONG __stdcall NET_DVR_FindAlarmHostLog(LONG lUserID, LONG lSelectMode, NET_DVR_ALARMHOST_SEARCH_LOG_PARAM *lpSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextAlarmHostLog(LONG lFindHandle, NET_DVR_ALARMHOST_LOG_RET *lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindAlarmHostLogClose(LONG lFindHandle);
//��ֹ2004��8��5��,��113���ӿ�
//ATM DVR
NET_DVR_API LONG __stdcall NET_DVR_FindFileByCard(LONG lUserID,LONG lChannel,DWORD dwFileType, int nFindType, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
//��ֹ2004��10��5��,��116���ӿ�

//����
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,unsigned char* pInBuffer, unsigned char* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);
//2005-09-15
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
//JPEGץͼ���ڴ�
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture_NEW(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize,  LPDWORD lpSizeReturned);


//2006-02-16
NET_DVR_API int __stdcall NET_DVR_GetRealPlayerIndex(LONG lRealHandle);
NET_DVR_API int __stdcall NET_DVR_GetPlayBackPlayerIndex(LONG lPlayHandle);

//2006-08-28 704-640 ��������
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG(LONG lUserID, DWORD dwScale);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG(LONG lUserID, DWORD *lpOutScale);
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
//2006-08-28 ATM���˿�����
NET_DVR_API BOOL __stdcall NET_DVR_SetATMPortCFG(LONG lUserID, WORD wATMPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetATMPortCFG(LONG lUserID, WORD *LPOutATMPort);

//2006-11-10 ֧���Կ��������
NET_DVR_API BOOL __stdcall NET_DVR_InitDDrawDevice();
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDrawDevice();
NET_DVR_API LONG __stdcall NET_DVR_GetDDrawDeviceTotalNums();
NET_DVR_API BOOL __stdcall NET_DVR_SetDDrawDevice(LONG lPlayPort, DWORD nDeviceNum);

NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn(LONG lRealHandle, LPNET_DVR_POINT_FRAME pStruPointFrame);
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn_EX(LONG lUserID, LONG lChannel, LPNET_DVR_POINT_FRAME pStruPointFrame);

//�����豸DS-6001D/DS-6001F
NET_DVR_API BOOL __stdcall NET_DVR_StartDecode(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERINFO lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecode(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecoderState(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERSTATE lpDecoderState);
//2005-08-01
NET_DVR_API BOOL __stdcall NET_DVR_SetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_DecPlayBackCtrl(LONG lUserID, LONG lChannel, DWORD dwControlCode, DWORD dwInValue,DWORD *LPOutValue, LPNET_DVR_PLAYREMOTEFILE lpRemoteFileInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StartDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlDec(LONG lUserID, LONG lChannel, DWORD dwControlCode);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlScreen(LONG lUserID, LONG lChannel, DWORD dwControl);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecCurLinkStatus(LONG lUserID, LONG lChannel, LPNET_DVR_DECSTATUS lpDecStatus);

//��·������
//2007-11-30 V211֧�����½ӿ� //11
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DYNAMIC_DEC lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopDynamic(LONG lUserID, DWORD dwDecChanNum); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecEnable(LONG lUserID, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_STATUS lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetVideoStandard(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwVideoStandard);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetVideoStandard(LONG lUserID, DWORD dwDecChanNum, DWORD dwVideoStandard);

//2007-12-22 ����֧�ֽӿ� //18
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlayControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwControlCode, DWORD dwInValue, DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetRemotePlayStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS lpOuter);
//2009-4-13 ����
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);

NET_DVR_API LONG __stdcall NET_DVR_MatrixStartPassiveDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_PASSIVEMODE lpPassiveMode /*, void(CALLBACK *fPassiveDataCallBack)(LONG lPassiveHandle, char * pSendBuf, DWORD dwBufSize, DWORD dwStatus, DWORD dwUser), DWORD dwUser*/);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSendData(LONG lPassiveHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopPassiveDecode(LONG lPassiveHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UploadLogo(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_DISP_LOGOCFG lpDispLogoCfg, char *sLogoBuffer);
#define	NET_DVR_SHOWLOGO			1		/*��ʾLOGO*/
#define	NET_DVR_HIDELOGO			2		/*����LOGO*/  
NET_DVR_API BOOL __stdcall NET_DVR_LogoSwitch(LONG lUserID, DWORD dwDecChan, DWORD dwLogoSwitch);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus(LONG lUserID,  LPNET_DVR_DECODER_WORK_STATUS lpDecoderCfg);

#define	DISP_CMD_ENLARGE_WINDOW				1	/*��ʾͨ���Ŵ�ĳ������*/
#define	DISP_CMD_RENEW_WINDOW				2	/*��ʾͨ�����ڻ�ԭ*/

NET_DVR_API BOOL __stdcall NET_DVR_MatrixDiaplayControl(LONG lUserID, DWORD dwDispChanNum, DWORD dwDispChanCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPassiveDecodeControl(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PASSIVEDECODE_CONTROL lpInter);
NET_DVR_API LONG __stdcall NET_DVR_MatrixGetPassiveDecodeStatus(LONG lPassiveHandle);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);

//end
NET_DVR_API BOOL __stdcall NET_DVR_RefreshPlay(LONG lPlayHandle);
//�ָ�Ĭ��ֵ
NET_DVR_API BOOL __stdcall NET_DVR_RestoreConfig(LONG lUserID);
//�������
NET_DVR_API BOOL __stdcall NET_DVR_SaveConfig(LONG lUserID);
//����
NET_DVR_API BOOL __stdcall NET_DVR_RebootDVR(LONG lUserID);
//�ر�DVR
NET_DVR_API BOOL __stdcall NET_DVR_ShutDownDVR(LONG lUserID);

//�������� begin
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState_V30(LONG lUserID, LPNET_DVR_WORKSTATE_V30 lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState(LONG lUserID, LPNET_DVR_WORKSTATE lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_SetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmProtocol(LONG lUserID, LPNET_DVR_ATM_PROTOCOL lpAtmProtocol);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut_V30(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS_V30 lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmOut(LONG lUserID, LONG lAlarmOutPort,LONG lAlarmOutStatic);

//��Ƶ��������
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetVideoEffect(LONG lRealHandle,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetVideoEffect(LONG lRealHandle,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);

//�����ļ�
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_V30(LONG lUserID, char *sOutBuffer, DWORD dwOutSize, DWORD *pReturnSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_EX(LONG lUserID, char *sOutBuffer, DWORD dwOutSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile_EX(LONG lUserID, char *sInBuffer, DWORD dwInSize);

//������־�ļ�д��ӿ�
NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD bLogEnable = 0, char * strLogDir = NULL, BOOL bAutoDel = TRUE);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKState(LPNET_DVR_SDKSTATE pSDKState);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKAbility(LPNET_DVR_SDKABL pSDKAbl);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol(LONG lUserID, NET_DVR_PTZCFG *pPtzcfg);
//ǰ�������
NET_DVR_API BOOL __stdcall NET_DVR_LockPanel(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_UnLockPanel(LONG lUserID);

NET_DVR_API BOOL __stdcall NET_DVR_SetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpOutBuffer, DWORD dwOutBufferSize);

//��������ȡ
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceAbility(LONG lUserID, DWORD dwAbilityType, char* pInBuf, DWORD dwInLength, char* pOutBuf, DWORD dwOutLength);

//2009-8-19 ��Ƶ�ۺ�ƽ̨�ӿں���
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopPlanArray(LONG lUserID, DWORD dwArrayNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopPlanArray(LONG lUserID, DWORD dwArrayNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAlarmShowMode(LONG lUserID, LPNET_DVR_ALARMMODECFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetAlarmShowMode(LONG lUserID, LPNET_DVR_ALARMMODECFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamicAssociateDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_DYNAMICDECODE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmTurn(LONG lUserID, DWORD dwDecChanNum, DWORD dwTurnParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmShowControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwShowMode);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetPlanDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PLANDECODE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetPlanDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PLANDECODE lpInter);

//����
//����/��ȡ�����ؼ���
NET_DVR_API BOOL __stdcall NET_DVR_SetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int nValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int *pValue);

//��ȡ/������Ϊ����Ŀ����ӽӿ�
NET_DVR_API BOOL __stdcall NET_DVR_GetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);
NET_DVR_API BOOL __stdcall NET_DVR_SetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);

//�������ģʽ���ýӿ�
NET_DVR_API BOOL __stdcall NET_DVR_SetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);

//	�������ܿ�
NET_DVR_API BOOL __stdcall NET_VCA_RestartLib(LONG lUserID, LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData_V30(LONG lRealHandle, DWORD dwTransType, char *sFileName);

NET_DVR_API BOOL __stdcall NET_DVR_EncodeG711Frame(unsigned int iType, unsigned char *pInBuffer, unsigned char *pOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG711Frame(unsigned int iType, unsigned char *pInBuffer, unsigned char *pOutBuffer);
//2009-7-22 end

NET_DVR_API LONG __stdcall NET_DVR_FindFileByEvent(LONG lUserID, LPNET_DVR_SEARCH_EVENT_PARAM  lpSearchEventParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextEvent(LONG lSearchHandle, LPNET_DVR_SEARCH_EVENT_RET lpSearchEventRet);
//ֹͣ���� NET_DVR_FindClose

NET_DVR_API LONG __stdcall NET_DVR_FindPDCInfo(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPDCInfo(LONG lFindHandle,LPNET_DVR_PDC_QUERY lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindPDCClose(LONG lFindHandle);

// �궨У�� 
#define NET_DVR_PDC_VERIFY_CALIBRATION  1  //��ֵΪ1��ΪPDC�궨У�� pdc����ֵΪNET_VCA_POINT   ����ֵΪ NET_VCA_RECT�ṹ
#define NET_DVR_VERIFY_BEHAVIOR_CALIBRATION    2    // ��Ϊ�����궨��У�� 
#define NET_DVR_VERIFY_ITS_CALIBRATION		3 	// ���ܽ�ͨ�궨У�� 

NET_DVR_API BOOL __stdcall NET_DVR_VerifyCalibration(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOuterBuffer, DWORD dwOuterBufferSize);
NET_DVR_API BOOL __stdcall  NET_DVR_ResetCounter(LONG lUserID,LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

// SDK_V35
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_MATRIX(LONG lLogHandle, LPNET_DVR_LOG_MATRIX lpLogData);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_Matrix(LONG lUserID, LONG lSelectMode, DWORD dwMajorType, DWORD dwMinorType, LPNET_DVR_VEDIOPLATLOG lpVedioPlatLog, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
//2009-12-17 ������Ƶ�ۺ�ƽ̨������ϵͳ������

//2009-10-26 ץ�Ļ����� begin
NET_DVR_API BOOL __stdcall NET_DVR_ManualSnap(LONG lUserID, LPNET_DVR_MANUALSNAP lpInter, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);
//2009-10-26 ץ�Ļ����� end

//2009-12-22 ������Ƶ�ۺ�ƽ̨��ͨ����ȡPTZЭ��ӿ�
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol_Ex(LONG lUserID, LONG lChannel, NET_DVR_PTZCFG *pPtzcfg);
//2010-01-16

NET_DVR_API LONG __stdcall NET_DVR_StartEmailTest(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_StopEmailTest(LONG lEmailTestHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetEmailTestProgress(LONG lEmailTestHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_GetIPCProtoList(LONG lUserID, LPNET_DVR_IPC_PROTO_LIST lpProtoList);
NET_DVR_API LONG __stdcall NET_DVR_SmartSearch(LONG lUserID,  LPNET_DVR_SMART_SEARCH_PARAM lpSmartSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_SearchNextInfo(LONG lSearchHandle, LPNET_DVR_SMART_SEARCH_RET lpSmartSearchRet);
NET_DVR_API BOOL __stdcall NET_DVR_StopSearch(LONG lSearchHandle);

// IP San �ļ�Ŀ¼����
NET_DVR_API LONG __stdcall NET_DVR_FindIpSanDirectory(LONG lUserID, LPNET_DVR_IPSAN_SERACH_PARAM lpIpsanSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDirectory(LONG lFindHandle, LPNET_DVR_IPSAN_SERACH_RET lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindDirectoryClose(LONG lFindHandle);


typedef void (CALLBACK *REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30 = NULL, void* pUser = NULL, BOOL bBlocked = TRUE);

NET_DVR_API BOOL __stdcall NET_DVR_ZeroStopPlay(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroMakeKeyFrame(LONG lUserID, LONG lZeroChan);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle,DWORD dwControlCode, LPVOID lpInBuffer = NULL, DWORD dwInLen = 0, LPVOID lpOutBuffer = NULL, DWORD *lpOutLen = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroTurnOver(LONG lUserID, LONG lChannel, BOOL bNextPreview);

NET_DVR_API BOOL __stdcall NET_DVR_GetDiskList(LONG lUserID, LPNET_DVR_DISKABILITY_LIST lpDiskList);
NET_DVR_API LONG __stdcall NET_DVR_BackupByName(LONG lUserID, LPNET_DVR_BACKUP_NAME_PARAM lpBackupByName);
NET_DVR_API LONG __stdcall NET_DVR_BackupByTime(LONG lUserID, LPNET_DVR_BACKUP_TIME_PARAM lpBackupBytime);
NET_DVR_API BOOL __stdcall NET_DVR_GetBackupProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_StopBackup(LONG lHandle);

NET_DVR_API BOOL __stdcall NET_DVR_GetSadpInfoList(LONG lUserID, LPNET_DVR_SADPINFO_LIST lpSadpInfoList);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateSadpInfo(LONG lUserID, LPNET_DVR_SADP_VERIFY lpSadpVerify, LPNET_DVR_SADPINFO lpSadpInfo);


NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_SetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);




NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestDeleteFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCDWByFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpCdrwFile);
NET_DVR_API LONG __stdcall NET_DVR_InquestUploadFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_InquestUploadClose(LONG lUploadHandle);
NET_DVR_API LONG __stdcall NET_DVR_InquestGetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStartCDW( LONG lUserID, BOOL bPause);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStopCDW(LONG lUserID, BOOL bCancelWrite);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDWState(LONG lUserID, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCheckSecretKey(LONG lUserID, BOOL *bSecretSet);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetSecretKey(LONG lUserID, LPNET_DVR_INQUEST_SECRET_INFO pSecretInfo);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStreamEncrypt(LONG lUserID, LONG lChannel, BOOL bEncrypt);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetEncryptState(LONG  lUserID, LONG lChannel, BOOL *bEncrypt);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindFile(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindNextFile(LONG lFindHandle, LPNET_DVR_INQUEST_FILEINFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_InquestFindClose(LONG lFindHandle);

//��������ͼƬ
NET_DVR_API LONG __stdcall NET_DVR_FindPicture(LONG lUserID,LONG lChannel,DWORD dwFileType, BOOL bNeedCardNum, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPicture(LONG lFindHandle,LPNET_DVR_FIND_PICTURE lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFindPicture(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture(LONG lUserID,char *sDVRFileName,char *sSavedFileName);

// 9000RH
NET_DVR_API LONG __stdcall NET_DVR_RaidFastConfig(LONG lUserID, char *sName);
NET_DVR_API BOOL __stdcall NET_DVR_FastConfigProcess(LONG lHandle, DWORD *pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFastConfig(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetArraySpaceAlloc(LONG lUserID, DWORD dwSlot, LPNET_DVR_ARRAY_SPACE_ALLOC_INFO lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DelArray(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_CreateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CalcArraySize(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam, UINT64* lpArraySize);
NET_DVR_API BOOL __stdcall NET_DVR_MigrateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_RebuildArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CreateVD(LONG lUserID, LPNET_DVR_OPERATE_VD_PARAM lpVDParam);
NET_DVR_API BOOL __stdcall NET_DVR_DelVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_RepairVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_SetSpareDisk(LONG lUserID, LPNET_DVR_SPARE_DISK_PARAM lpSpareDisk);
NET_DVR_API BOOL __stdcall NET_DVR_GetPDList(LONG lUserID,  LPNET_DVR_PHY_DISK_LIST lpPDList);
NET_DVR_API BOOL __stdcall NET_DVR_GetArrayList(LONG lUserID, LPNET_DVR_ARRAY_LIST lpArrayList);
NET_DVR_API BOOL __stdcall NET_DVR_GetVDList(LONG lUserID, LPNET_DVR_VD_LIST lpVDList);
NET_DVR_API LONG __stdcall NET_DVR_ExpandDisk(LONG    lUserID,DWORD dwVDSLot);
NET_DVR_API BOOL __stdcall NET_DVR_GetExpandProgress(LONG lExpandHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseExpandHandle(LONG lExpandHandle);

/*******************************test*****************************************/

NET_DVR_API LONG __stdcall NET_DVR_AlgoDebugStart(LONG lUserID, LONG lCHannel, void(CALLBACK *fAlgoLibInfoCallBack)(LONG lHandle, LONG lChannel,char *pRecvDataBuffer, DWORD dwBufSize, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugSend(LONG lHandle, LONG lChannel, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugStop(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrint(BOOL bLogPrint);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrintAction(DWORD nLogLevel, DWORD nToDevice, BOOL bEnable, int Reserve1, int Reserve2);



//2010-09-13
#define	NET_DVR_MATRIX_BIGSCREENCFG_GET		1140//��ȡ����ƴ�Ӳ���
#define	NET_DVR_MATRIX_BIGSCREENCFG_SET		1141//���ô���ƴ�Ӳ���

#define		MAX_BIGSCREENNUM	16//������ƴ����

typedef struct tagNET_DVR_SINGLESCREENCFG
{
    BYTE	byScreenSeq;//��Ļ���,0xff��ʾ���ô���
    BYTE	bySubSystemNum;//������ϵͳ��λ��
    BYTE	byDsipNum;//������ϵͳ�϶�Ӧ��ʾͨ����
    BYTE	byRes[9];
}NET_DVR_SINGLESCREENCFG, *LPNET_DVR_SINGLESCREENCFG;

typedef struct tagNET_DVR_BIGSCREENCFG
{
    DWORD					  dwSize;
    BYTE					  byEnable;//����ƴ��ʹ�ܣ�0-��ʹ�ܣ�1-ʹ��
    //����ƴ��ģʽ��1-1��1��2-1��2��3-1��3��4-1��4��5-2��1��6-2��2��7-2��3��8-2��4��
    //9-3��1��10-3��2��11-3��3��12-3��4��13-4��1��14-4��2��15-4��3��16-4��4
    BYTE				      byMode;
    BYTE					  byMainDecodeSystem;//������λ��
    BYTE					  byRes1[5];
    //����ƴ�Ӵ���Ļ��Ϣ
    NET_DVR_SINGLESCREENCFG struFollowSingleScreen[MAX_BIGSCREENNUM]; 
    BYTE					  byRes2[16];
}NET_DVR_BIGSCREENCFG, *LPNET_DVR_BIGSCREENCFG;

//2010-09-15
/****************************************************************
����:��·������ͼ��΢���ӿ�
����˵��:
lUserID: (������ϵͳ)NET_DVR_Login()�ķ���ֵ
dwDispChan:��ʾͨ��
dwPicAdjust:΢������
dwCmdParam��ͼ��΢������
TRUE��ʾ�ɹ�,FALSE��ʾʧ��
*****************************************************************/  
#define	DECODEPIC_LEFTADJUST			1		/*ͼ������*/
#define	DECODEPIC_RIGHTADJUST			2		/*ͼ������*/
#define	DECODEPIC_UPADJUST				3		/*ͼ������*/
#define	DECODEPIC_DOWNADJUST			4		/*ͼ������*/
#define	DECODEPIC_REDUCEADJUST			5		/*ͼ����С*/          
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPicAdjust(LONG lUserID, DWORD dwDispChan, DWORD dwPicAdjust, DWORD dwCmdParam);
/****************************************************************
����:��������¼��ӿ�
����˵��:
lUserID: (������ϵͳ)NET_DVR_Login()�ķ���ֵ
dwChan:����ͨ��
dwAlarmSeq���������
dwRecordTime��¼��ʱ��(��)
dwRes������
TRUE��ʾ�ɹ�,FALSE��ʾʧ��
*****************************************************************/  
NET_DVR_API BOOL __stdcall NET_DVR_AlarmJoinedRecord(LONG lUserID, DWORD dwChan, DWORD dwAlarmSeq, DWORD dwRecordTime, DWORD dwRes);
//2010-09-27
#define 	MAX_UNITEDMATRIX_NUM		8//�����������Ƶ�ۺ�ƽ̨����
#define 	MAX_SUBDOMAIN_NUM		    4//�����������������
typedef struct tagNET_DVR_SUBSERVERINFO
{
	BYTE		bySequence;//��ţ���������������ţ�������Ƶ�ۺ�ƽ̨����ƽ̨�ţ�0��ʾ�޴�ƽ̨\����
	BYTE		byBelongSubDomain;//����ƽ̨��Ч����ʾ�����ĸ�����
	BYTE		byRes1[6];
	DWORD       dwMaxIpcNums;//���ӵ����IPC����
    NET_DVR_IPADDR struSubMatrixIP;		/*IP��ַ*/
    WORD		wSubMatrixPort;        /*��ϵͳ�˿ں�*/
    BYTE		byRes2[6];
}NET_DVR_SUBSERVERINFO, *LPNET_DVR_SUBSERVERINFO;

typedef struct tagNET_DVR_UNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBSERVERINFO struDomainInfo;
	NET_DVR_SUBSERVERINFO struSubDomainInfo[MAX_SUBDOMAIN_NUM];//������Ϣ
	NET_DVR_SUBSERVERINFO struMatrixInfo[MAX_UNITEDMATRIX_NUM];//��Ƶ�ۺ�ƽ̨��Ϣ
    BYTE  byRes[32];
}NET_DVR_UNITEDMATRIXINFO, *LPNET_DVR_UNITEDMATRIXINFO;
/****************************************************************
����:��ȡ����78K������Ϣ
����˵��:
lUserID: NET_DVR_Login()�ķ���ֵ(78K)
lpInter��LPNET_DVR_UNITEDMATRIXINFO�ṹ
����ֵ��TRUE��ʾ�ɹ�,FALSE��ʾʧ��
****************************************************************/			 
NET_DVR_API BOOL __stdcall NET_DVR_GetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_UNITEDMATRIXINFO lpInter);

/*******************************test*****************************************/

typedef struct tagNET_DVR_REGCALLBACKPARAM
{
	char sDeviceID[NAME_LEN];//�豸ID��
	char sPassword[PASSWD_LEN];
	BYTE sSerialNumber[SERIALNO_LEN]; /* �豸���к� */
	DWORD dwDeviceType;//�豸����
	BYTE nStatus;// ������״̬��0���ߣ�1���ߣ�
	/* net type, 0: unknow; 1: 2G wireless networks; 2: 3G wireless networks; 3: line networks */
	BYTE byNetType;	
	BYTE byRes[14];
}NET_DVR_REGCALLBACKPARAM, *LPNET_DVR_REGCALLBACKPARAM;
typedef LONG(CALLBACK * REGCallBack)(LONG lUserID, LPNET_DVR_REGCALLBACKPARAM pRegCallbackParam, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetRegisterCallBack(REGCallBack fRegCallBack, void* pUser);
typedef struct tagNET_DVR_PREVIEWPARAM
{
    BYTE byTransProtol;		//����Э�飬0-TCP, 1-UDP
    BYTE byTransMode;		///* ��������ģʽ 0�������� 1��������*/ 
    NET_DVR_IPADDR struCuIp; //CU��IP��ַ
    WORD wPort;/*CU�˿�*/
    WORD wUdpPort;
    BYTE bySupportQos;//�Ƿ�����QOS,1-���ã�0-������
	BYTE byRes[9];
}NET_DVR_PREVIEWPARAM, *LPNET_DVR_PREVIEWPARAM;
NET_DVR_API BOOL CALLBACK NET_DVR_PreviewRequest(LONG lUserID, LONG lChannel, LPNET_DVR_PREVIEWPARAM lpPreviewParam);

typedef struct tagNET_DVR_PREVIEWCALLBACKPARAM
{
	LONG lChannel;
	BYTE nLinkProtocol;
	BYTE nTransMode;
	BYTE byRes[10];
}NET_DVR_PREVIEWCALLBACKPARAM, *LPNET_DVR_PREVIEWCALLBACKPARAM;
typedef LONG(CALLBACK * PREVIEWRESPONSECallBack)(LONG lUserID, LONG lStreamHandle, LPNET_DVR_PREVIEWCALLBACKPARAM pPewviewCallbackParam,void *pUser);

NET_DVR_API BOOL CALLBACK NET_DVR_SetPreviewResponseCallBack(PREVIEWRESPONSECallBack fPreviewResponseCallBack, void *pUser);


//�ط�
typedef struct tagNET_DVR_PLAYBACKREQUESTPARAM
{
    BYTE byPlayBackMode;		/* �ط�����ģʽ 1�������� 2����ʱ�� */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* �طŵ��ļ��� */
        struct 
        {
            LONG	lChannel;				/*�طŵ�ͨ����*/
            NET_DVR_TIME struStartTime;			/* ��ʱ��طŵĿ�ʼʱ�� */
            NET_DVR_TIME struStopTime;			/* ��ʱ��طŵĽ���ʱ�� */
            BYTE    byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    NET_DVR_IPADDR struCuIp; //CU��IP��ַ
    WORD	wPort;/*CU�˿�*/
    BYTE	byRes2[22];
}NET_DVR_PLAYBACKREQUESTPARAM, *LPNET_DVR_PLAYBACKREQUESTPARAM;
/**************************************************************
                 ����:�ط�����ӿ�
                 ����˵��:
                 lUserID: �豸ע��ID
                 lpPlayBackRequestParam: NET_DVR_PLAYBACKREQUESTPARAM�ṹָ��
                                  ����ֵ��
                                  TRUE�ɹ���FALSEʧ��
***************************************************************/                 
NET_DVR_API BOOL __stdcall NET_DVR_PlaybackRequest(LONG lUserID, LPNET_DVR_PLAYBACKREQUESTPARAM lpPlayBackRequestParam);

//2010-10-06
typedef struct tagNET_DVR_PLAYBACKCALLBACKPARAM
{
    BYTE byPlayBackMode;		/* �ط�����ģʽ 1�������� 2����ʱ�� */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* �طŵ��ļ��� */
        struct 
        {
            LONG    	lChannel;				/*�طŵ�ͨ����*/
            NET_DVR_TIME struStartTime;			/* ��ʱ��طŵĿ�ʼʱ�� */
            NET_DVR_TIME struStopTime;			/* ��ʱ��طŵĽ���ʱ�� */
            BYTE       byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    BYTE byRes2[48];
}NET_DVR_PLAYBACKCALLBACKPARAM, *LPNET_DVR_PLAYBACKCALLBACKPARAM;
/***************************************************************
lUserID���û�ID
lPlaybackHandle���طž��
lpPlaybackParam��LPNET_DVR_PLAYBACKCALLBACKPARAM�ṹ
pUser:�û�����
ע������ֵ��0��ʾ�ϲ�ͨ���ط�������֤ 
****************************************************************/           
typedef LONG(CALLBACK * PLAYBACKRESPONSECallBack)(LONG lUserID, LONG lPlaybackHandle, LPNET_DVR_PLAYBACKCALLBACKPARAM lpPlaybackParam,void *pUser);

/******************************************************************
˵���������豸�˻ط���������Ӧ�ص�����
���������
fPlaybackResponseCallBack:�豸�ط�"����"�ص�����ָ��;
pUser:�û�����
���������
����ֵ:FALSEʧ�ܣ�TRUE�ɹ�
******************************************************************/      
NET_DVR_API BOOL __stdcall NET_DVR_SetPlaybackResponseCallBack(PLAYBACKRESPONSECallBack fPlaybackResponseCallBack, void *pUser);



/************************************************
lUserID���û�ID
lPlayHandle���طž��
lVoiceChannel���Խ�ͨ����
nAudioType����Ƶ���ͣ�0-G722,1-G711
pUser:�û�����
ע������ֵ��0��ʾ�ϲ�ͨ���ط�������֤
************************************************/            
typedef LONG(CALLBACK * VOICERESPONSECallBack)(LONG lUserID, LONG lVoiceHandle, LONG lVoiceChannel, BYTE nAudioType, void *pUser);

/*************************************************
˵���������豸�˶Խ���Ӧ�ص�����
���������
fVoiceResponseCallBack:�豸�Խ��ص�����ָ��;
pUser:�û�����
���������
����ֵ:FALSEʧ�ܣ�TRUE�ɹ�
**************************************************/      
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceResponseCallBack(VOICERESPONSECallBack fVoiceResponseCallBack, void *pUser);

typedef struct tagNET_DVR_VOICEREQUESETPARAM
{
    BYTE	nVoiceChannel;		//�Խ�ͨ����
    BYTE	byRes1[3];
    NET_DVR_IPADDR struCuIp; //CU��IP��ַ
    WORD	 wPort;/*CU�˿�*/
    BYTE	byRes2[10];
}NET_DVR_VOICEREQUESTPARAM, *LPNET_DVR_VOICEREQUESTPARAM;
/************************************************************
              ����:�Խ�����ӿ�
              ����˵��:
              lUserID: �豸ע��ID
              lpVoiceParam: NET_DVR_VOICEREQUESTPARAM�ṹָ��
                            ����ֵ��
                            TRUE�ɹ���FALSEʧ��
**************************************************************/              
NET_DVR_API BOOL __stdcall NET_DVR_VoiceRequest(LONG lUserID, LPNET_DVR_VOICEREQUESTPARAM lpVoiceParam);

typedef struct tagNET_DVR_ALARMSETUPREQUESETPARAM
{
	NET_DVR_IPADDR struAlarmServerIp; //CU��IP��ַ
	WORD	 wPort;/*CU�˿�*/
	BYTE	byRes[2];
}NET_DVR_ALARMSETUPREQUESTPARAM, *LPNET_DVR_ALARMSETUPREQUESTPARAM;
/********************************************************
����:��������ӿ�
����˵��:
lUserID: �豸ע��ID
lpAlarmSetupParam: NET_DVR_ALARMSETUPREQUESTPARAM�ṹָ��
				   ����ֵ��
				   TRUE�ɹ���FALSEʧ��
********************************************************/				   
NET_DVR_API BOOL __stdcall NET_DVR_AlarmSetupRequest(LONG lUserID, LPNET_DVR_ALARMSETUPREQUESTPARAM lpAlarmSetupParam);
		
typedef struct _tagNET_DVR_GPSALARMINFO
{
	DWORD dwUserID;//SDK������豸��id��
	DWORD	dwSpeed;//�ٶ�
	DWORD	dwLongitude;		/* ����*/
	DWORD	dwLatitude;       /* γ��*/
	char	sDirection[2];   /* direction[0]:'E'or'W'(����/����), direction[1]:'N'or'S'(��γ/��γ) */
	BYTE    byRes[2];              /* ����λ */
}NET_DVR_GPSALARMINFO, *LPNET_DVR_GPSALARMINFO;
#define  COMM_ALARM_ALARMGPS        0x1106  //GPS������Ϣ�ϴ�

//ͼƬ��Ϣ�ϴ�
typedef struct tagNET_DVR_PICINFO
{
	DWORD   dwSize;				//�ṹ����
	BYTE    byChanIndex;			//ͨ����
	BYTE    byRes1[3];				//����
	BYTE    byAbsTime[32];		//����ʱ���, yyyymmddhhmmssxxx,
	DWORD   dwPicLen;					//ͼƬ����
	BYTE	byRes2[32];
	BYTE	*pPicBuffer;
}NET_DVR_PICTUREINFO, *LPNET_DVR_PICTUREINFO;
#define COMM_UPLOAD_PICTUREINFO		0x2900	//�ϴ�ͼƬ��Ϣ

//ƽ̨����
typedef struct tagNET_DVR_CMSPARAM
{
	DWORD   dwSize;
	NET_DVR_IPADDR struCmsAddr;
	WORD   wCmsPort;
	BYTE   byRes1[2];
	BYTE   sDeviceID[NAME_LEN];
	BYTE   byPassword[PASSWD_LEN];
	NET_DVR_IPADDR struPicServerAddr;
	WORD   wPicServerPort;
	BYTE   byRes2[82];
}NET_DVR_CMSPARAM, *LPNET_DVR_CMSPARAM;


///���Ź���
#define DIALPASSWD_LEN  32 //3G�������볤��

typedef struct tagNET_DVR_QOSPARAM
{
	WORD wMaxBitUL;	/* the maximum number of kbits/s in up-link traffic */
	WORD wMaxBitDL;	/* the maximum number of kbits/s in down-link traffic */
	BYTE byTrafficClass;	/* 0: conversationnal; 1: streaming; 2: interactive;3: background; 4: subscribed value(default) */
	BYTE byRes[7];
}NET_DVR_QOSPARAM, *LPNET_DVR_QOSPARAM;


typedef struct tagNET_DVR_PPPDPARAM
{
	BYTE byDialNum[NAME_LEN];		/* dial number, eg. "#777" */
	BYTE byUserName[NAME_LEN];	/* user name, eg. "card" */
	BYTE byPassword[DIALPASSWD_LEN];	/* password, eg. "card" */
	BYTE byApn[NAME_LEN];		/* access point name, eg. "cmnet" */
	NET_DVR_IPADDR struLocalIp;/* local IP address */
	NET_DVR_IPADDR struRemoteIp;/* remote IP address */
	WORD wMtuSize;		/* max transfer unit of ppp interface */
	BYTE byVerifyProtocal;	/* IPCP verify protocal: 0: auto; 1: CHAP; 2: PAP */
	BYTE byRes[25];	
}NET_DVR_PPPDPARAM, *LPNET_DVR_PPPDPARAM;

typedef struct tagNET_DVR_DIALPARAM
{
	DWORD dwSize;
	BYTE bEnable3G;		/* 0: disable; 1: enable 3g */
	BYTE byDialMethod;		/* dial methold: 0: auto dial; 1: manual dial; */
	BYTE bySwitchMethod;	/* switch methold: 0: auto switch;1��3G���ȣ�2: manual switch to 2G; 3: manual switch to 3G; */
	BYTE byRes1[11];
	WORD wOffLineTime;		/* auto off line when no connection exist��second */	
	NET_DVR_PPPDPARAM struPppdParam;
	NET_DVR_QOSPARAM struQosParam;
	BYTE byRes2[24];
}NET_DVR_DIALPARAM, *LPNET_DVR_DIALPARAM;

typedef struct tagNET_DVR_DIALREQUEST
{
	BYTE byConnNum;		/*�������*/
	BYTE byNetType;		/* ָ�����ĳ�������Ĭ�ϲ��Ų���������ʱ�˲���û�á�0���Զ���1��CDMA��2��EVDO��3��WCDMA��4��TD-SCDMA */
	BYTE byRes[6];
} NET_DVR_DIALREQUEST, *LPNET_DVR_DIALREQUEST;
/**************************************************
����: 
����˵��:
lUserID: NET_DVR_Login()�ķ���ֵ
lpDialRequest:���Ų�������ṹָ��
lpDialParam: NET_DVR_DIALPARAM�ṹָ��
 ����ֵ��
 TRUE��ʾ�ɹ�,FALSE��ʾʧ��
***************************************************/			 
NET_DVR_API BOOL __stdcall NET_DVR_GetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);

/***************************************************
			 			 ����: 
			 			 ����˵��:
			 lUserID: NET_DVR_Login()�ķ���ֵ
			 lpDialRequest:���Ų�������ṹ
			 lpDialParam: NET_DVR_DIALPARAM�ṹָ��
			 			 ����ֵ��
			 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��	
***************************************************/			 		 
NET_DVR_API BOOL __stdcall NET_DVR_SetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);

			 
/* UIM card information */
typedef enum
{
	UIM_UNKNOWN = 0,
	UIM_VALID = 1,
	UIM_NOVALID = 4,
	UIM_ROAM = 11,
	UIM_NOEXIST = 255
}UIM_INFO;

/* real 3g mode */
typedef enum
{
	 /* evdo */
	RMODE_CDMA1X = 12,
	RMODE_EVDO = 14,
	RMODE_CDMAHYBRID = 18,
	/* wcdma */
	RMODE_GSM = 21,
	RMODE_GPRS = 22,
	RMODE_EDGE = 23,
	RMODE_WCDMA = 24,
	RMODE_HSDPA = 25,
	RMODE_HSUPA = 26,
	RMODE_HSPA = 27,
	/* tdscdma */
	RMODE_TGSM = 31,
	RMODE_TGPRS = 32,
	RMODE_TEDGE = 33,
	RMODE_TDSCDMA = 34,
	RMODE_TDHSDPA = 35,
	RMODE_TDHSUPA = 36,
	RMODE_TDHSPA = 37
}REAL_MODE;

typedef struct tagNET_DVR_DIALSTATUS
{
	 BYTE byRealMode;		/* REAL_MODE ,real 3g mode networks */
	 BYTE byUimCard;		/* UIM_INFO ,UIM card information */
	 BYTE byRes1[6];
	 DWORD dwSignal;			/* signal RSSI */
	 DWORD dwDialStatus;		/* dial status */
	 NET_DVR_IPADDR struLocalIp;	/* wireless networks IP address */
	 NET_DVR_IPADDR struRemoteIp;	/* wireless networks gateway */
	 NET_DVR_IPADDR struNetMask;	/* wireless networks netmask */
	 NET_DVR_IPADDR struDns;		/* wireless networks DNS */	 
	 BYTE  byRes2[16];
}NET_DVR_DIALSTATUS, *LPNET_DVR_DIALSTATUS;

//���Ź���
#define MAX_WHITELIST_NUM	8 //����������
typedef struct tagNET_DVR_SMSRELATIVEPARAM
{
	 DWORD dwSize;
	 BYTE bEnableSmsAlarm;	/* 0: disable; 1: enable 3g */
	 BYTE byRes1[7];
	 BYTE byWhiteList[MAX_WHITELIST_NUM][16];
	 BYTE byRes2[48];
}NET_DVR_SMSRELATIVEPARAM, *LPNET_DVR_SMSRELATIVEPARAM;
typedef struct tagNET_DVR_3GTIME
{
	 WORD wYear;
	 BYTE byMonth;
	 BYTE byDay;
	 BYTE byHour;
	 BYTE byMinute;
	 BYTE bySecond;
	 BYTE byRes;
}NET_DVR_3GTIME,*LPNET_DVR_3GTIME;


typedef struct tagNET_DVR_SMSLISTINFO
{
	 DWORD  dwSize;
	 DWORD dwTotalSmsNum;//��������
	 BYTE  byRes[8];
	 BYTE  *pSmsParam;
	 DWORD dwBufLen;//������ָ�볤�ȣ��������
}NET_DVR_SMSLISTINFO, *LPNET_DVR_SMSLISTINFO;

typedef struct tagNET_DVR_SMSPARAM
{
	 DWORD dwIndex;			/* the index of sms */
	 BYTE byStatus;			/* read yet or not */
	 BYTE byRes[7];
	 NET_DVR_3GTIME struRecvTime;		/* sms receive time */
}NET_DVR_SMSPARAM, *LPNET_DVR_SMSPARAM;
/****************************************************
����: 
����˵��:
lUserID: NET_DVR_Login()�ķ���ֵ
lpStartTime:��ʼʱ��
lpStopTime: ����ʱ��
lpSmsListInfo��NET_DVR_SMSLISTINFO�ṹָ��
����ֵ��
TRUE��ʾ�ɹ�,FALSE��ʾʧ��
******************************************************/					 
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsListInfo(LONG lUserID, LPNET_DVR_3GTIME lpStartTime, LPNET_DVR_3GTIME lpStopTime, LPNET_DVR_SMSLISTINFO lpSmsListInfo);

typedef struct tagNET_DVR_SMSCONTENT
{
	BYTE byPhoneNum[16];
	BYTE byMsg[140];
}NET_DVR_SMSCONTENT, *LPNET_DVR_SMSCONTENT;

/***************************************************
			  			����: ��ȡ��������
			  			����˵��:
			  lUserID: NET_DVR_Login()�ķ���ֵ
			  dwSmsIndex:�������
			  lpSmsContent: NET_DVR_SMSCONTENT�ṹָ��
			  			  ����ֵ��
			  			  TRUE��ʾ�ɹ�,FALSE��ʾʧ��
******************************************************/	 			
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsContent(LONG lUserID, DWORD dwSmsIndex, LPNET_DVR_SMSCONTENT lpSmsContent);

/****************************************************
 ����: ���Ͷ���
   ����˵��:
 lUserID: NET_DVR_Login()�ķ���ֵ
lpSmsContent: NET_DVR_SMSCONTENT�ṹָ��
����ֵ��
TRUE��ʾ�ɹ�,FALSE��ʾʧ��
*****************************************************/			  			  
NET_DVR_API BOOL __stdcall NET_DVR_SendSms(LONG lUserID, LPNET_DVR_SMSCONTENT lpSmsContent);

			  
//pin������
typedef enum
{
	CPIN_READY = 1,
	CPIN_PIN = 2,
	CPIN_PUK = 3,
	CPIN_PIN2 = 4,
	CPIN_PUK2 = 5
}PIN_READY;

typedef struct tagNET_DVR_PINSTATUS
{
	DWORD dwSize;
	BYTE byStatus;		/* PIN status, defination see enum: PIN_READY */
	BYTE byPinTimes;	/* remain input PIN times */
	BYTE byPukTimes;	/* remain input PUK times */	
	BYTE bEnableLock;	/* now the PIN locking function is enabled or not: 0, not enabled lock; 1, lock enabled */
	BYTE byRes[4];
}NET_DVR_PINSTATUS, *LPNET_DVR_PINSTATUS;

typedef enum
{
	PIN_ENABLE = 1,
	PIN_DISABLE = 2,
	PIN_VERIFY = 3,
	PUK_VERIFY = 4,
	PIN_CHANGE = 5
}PIN_CMD;

typedef struct tagNET_DVR_PINCODEPARAM
{
	 DWORD dwSize;
	 BYTE byPinCmd;		/* PIN command, defination see enum: PIN_CMD */
	 BYTE byRes1[3];
	 BYTE byPinCode[8];		/* pin/puk code */
	 BYTE byNewPinCode[8];	/* new pin code */
	 BYTE byRes2[16];
}NET_DVR_PINCODEPARAM, *LPNET_DVR_PINCODEPARAM;

#define NET_DVR_GET_CMSPARA			1170//��ȡƽ̨����
#define NET_DVR_SET_CMSPARA			1171//����ƽ̨����
#define NET_DVR_GET_DIALSTATUS		1172//��ȡ����״̬����
#define NET_DVR_GET_SMSRELATIVEPARA	1173//��ȡ������ز���
#define NET_DVR_SET_SMSRELATIVEPARA	1174//���ö�����ز���
#define NET_DVR_GET_PINSTATUS		1175//��ȡPin״̬
#define NET_DVR_SET_PINCMD			1176//����PIN����
/*************************************************
������:    	NET_DVR_StartServer
���ܣ�������������������
��  ����
		[in]sLocalIP: ����IP��ַ
		[in]wLocalPort: ���ؼ����˿ںţ����û�����
����ֵ��-1��ʾʧ�ܣ�����ֵ��ΪNET_DVR_StopServer�����ľ����������ȡ���������NET_DVR_GetLastError
˵  �����ýӿ���Ҫ�������������������������豸�����ϴ�������ע�ᡢԤ�����󡢻ط����������Խ�����
�����������Ϣ��֧�ֶ��̣߳����뽫�豸��CMS��������ַ���ó�PC����IP��ַ����ӿ��е�sLocalIP����һ�£���
CMS�˿����ó�PC���ļ����˿ںţ���ӿ��е�wLocalPort����һ�£����ý����еĻص�����������ΪNULL��
�����޷����յ��豸�ϴ�������ע�����Ϣ��
*************************************************/
NET_DVR_API LONG __stdcall NET_DVR_StartServer(char *sLocalIP, WORD wLocalPort);
/*************************************************
������:    	NET_DVR_StopServer
��������:	ֹͣ��������DVR������(֧�ֶ��߳�)
�������:   lServerHandle:NET_DVR_StartServer�ķ���ֵ
�������:   			
����ֵ:		HPR_TRUE��ʾ�ɹ�,HPR_FALSE��ʾʧ��
*************************************************/
NET_DVR_API BOOL __stdcall NET_DVR_StopServer(LONG lServerHandle);

/************************************************
            lUserID���û�ID
            lAlarmHandle���������
            pUser:�û�����
            ע������ֵ��0��ʾ�ϲ�ͨ���ط�������֤
************************************************/            
typedef LONG(CALLBACK * ALARMSETUPRESPONSECallBack)(LONG lUserID, LONG lAlarmHandle, void * pUser);
   
/*************************************************
      ˵���������豸�˲�������ص�����
      ���������
      fAlarmSetupResponseCallBack:�豸����������ָ��;
      pUser:�û�����
            ���������
            ����ֵ:FALSEʧ�ܣ�TRUE�ɹ�
**************************************************/            
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmSetupResponseCallBack(ALARMSETUPRESPONSECallBack fAlarmSetupResponseCallBack, void * pUser);

/****************************************************
����: ������������(3G�豸)
����˵��:
[in] wHeartbeatTime������ʱ��������λ���룬15-15�룬30-30�룬60-60�룬120-120�룬180-180�롣Ĭ����15�롣
[in] byOvertimes: ������ʱ����
����ֵ��
TRUE��ʾ�ɹ�,FALSE��ʾʧ��
*****************************************************/			  			  
NET_DVR_API BOOL __stdcall NET_DVR_SetHeartbeatParam(WORD wHeartbeatTime, BYTE byOvertimes);
/*******************************test*****************************************/


/************************************************************************/
#define MAX_ALARMHOST_ALARMIN_NUM	512//���籨��������󱨾��������
#define MAX_ALARMHOST_ALARMOUT_NUM	512//���籨��������󱨾��������

#define ALARMHOST_MAX_AUDIOOUT_NUM		    32//���籨������������������
#define ALARMHOST_MAX_ELECTROLOCK_NUM		32//���籨��������������
#define ALARMHOST_MAX_MOBILEGATE_NUM		32//���籨����������ƶ�����
#define ALARMHOST_MAX_SIREN_NUM             8 // ��󾯺���Ŀ

typedef enum tagSENSOR_TYPE
{
	SENSOR_TYPE_NONE = 0,       //��
	SENSOR_TYPE_TEMPERATURE = 1, // �¶�
	SENSOR_TYPE_HUMIDITY ,      // ʪ��
	SENSOR_TYPE_WINDSPEED,      // ����
	SENSOR_TYPE_GAS,            //����
	SENSOR_TYPE_UNKNOW = 255    //δ����
}SENSOR_TYPE;

typedef struct tagNET_DVR_SENSOR_INFO
{
	DWORD  dwSize;                 // �ṹ���С
	BYTE    byName[MAX_NAMELEN];    // ����������
	BYTE    byEnable;               // �Ƿ����� 
	BYTE    byValid;                // �Ƿ���Ч ����������������(�ò���ֻ�ܻ�ȡ���ܸ�����)
	BYTE    byType;                 // ģ�������� ����SENSOR_TYPE
	BYTE	byAlarmMode;//����ģʽ�����֣�15-HHHH��14-HHHL��12-HHLL��8HLLL��0-LLLL��
	//����1111���������ϣ���1110���������£���1100���������£���1000(��������)��0000(��������)
	float   fMeasureHigh;           // ��������
	float   fMeasureLow;            // ��������
	// ������1-4 ��������
	float	fAlarm1;           //������1
	float	fAlarm2;           //������2
	float	fAlarm3;           //������3
	float	fAlarm4;           //������4
	DWORD   dwOsdCfg;          //ģ�����ַ����ӣ���λ��ʾ0-15��Ӧ��Ƶͨ��1-16
	float	fSensitive;			// �����ȱ�ʾ��ʵʱֵ�ı仯���������ȵķ�Χʱ�����ʾʵʱֵ�����˱仯��������Ϊû�з����仯���磺������Ϊ0.1�����ʾǰ���������ֵ֮�����0.1ʱ������Ϊ���ݷ����仯����0.1����Ҫ�ϴ������Ϊ1�����ʾ�仯����1ʱ�ϱ���
	BYTE    byRes3[116];            // �����ֽ�
}NET_DVR_SENSOR_INFO, *LPNET_DVR_SENSOR_INFO;

typedef struct tagNET_DVR_SIREN_PARAM
{
	DWORD   dwSize;     // �ṹ��С
    BYTE    byName[NAME_LEN];   // ����
	WORD    wDelay;     // ����ӳ� ��λΪ��  0��ʾһֱ�����
    BYTE	byRes1[2];
    BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //��ʾ���Ÿ���ı�������ͨ�� �������������ͬʱ����һ����������������±�0��ʾ��������1���������� 0-������ 1-����
    BYTE    byRes2[68];  // �����ֽڡ�
}NET_DVR_SIREN_PARAM, *LPNET_DVR_SIREN_PARAM;

typedef struct tagNET_DVR_AIR_CONDITION_PARAM
{
	DWORD	dwSize;		// �ṹ���С
	BYTE	byEnable;	// 0--�ػ� 1--����
	BYTE	byMode;		// �յ�ģʽ
	BYTE	byTemperature;	// �¶ȣ�����ֵ��ʾ ͨ��Ϊ16-30��
	BYTE	byRes[9];		// �����ֽ�
}NET_DVR_AIR_CONDITION_PARAM, *LPNET_DVR_AIR_CONDITION_PARAM;

typedef enum tagDETECTOR_TYPE
{
    PANIC_BUTTON = 0,               // ��������
    MAGNETIC_CONTACT,               // �Ŵſ���
    SMOKE_DETECTOR,                 // �̸�̽����
    ACTIVE_INFRARED_DETECTOR,       // ��������̽����
    PASSIVE_INFRARED_DETECTOR,      // ��������̽����
    GLASS_BREAK_DETECTOR,           // ��������̽����
    VIBRATION_DETECTOR,             // ��̽����
    DUAL_TECHNOLOGY_PIR_DETECTOR,   // ˫���ƶ�̽����
    TRIPLE_TECHNOLOGY_PIR_DETECTOR, // ������̽����
    HUMIDITY_DETECTOR,              // ʪ��̽����
    TEMPERATURE_DETECTOR,           // �¸�̽����
    COMBUSTIBLE_GAS_DETECTOR,        // ��ȼ����̽����
    OTHER_DETECTOR = 0xffff          // ����̽����   
}DETECTOR_TYPE;

typedef struct tagNET_DVR_ALARMIN_PARAM
{
	DWORD   dwSize;
	BYTE    byName[NAME_LEN];
	WORD    wDetectorType; // DETECTOR_TYPE
	BYTE    byType;     // ������������ 0-- ��ʱ������1--24Сʱ������2--��ʱ����
	BYTE    byRes1;    
	DWORD	dwParam;    // ��������  ��ʱ������ʱ�೤ʱ�� 
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];/*����ʱ��ʱ���*/
	BYTE    byAssociateAlarmOut[MAX_ALARMHOST_ALARMOUT_NUM];  // ������������������
    BYTE	byAssociateSirenOut[8];		//  ������� ����0 ��ʾ����1 ֵΪ1��ʾ��� 0 ��ʾ�����
    BYTE    byRes[52];      // �����ֽ�
}NET_DVR_ALARMIN_PARAM, *LPNET_DVR_ALARMIN_PARAM;

typedef struct tagNET_DVR_ALARMOUT_PARAM
{
	DWORD   dwSize;             // �ṹ���С
	BYTE    byName[NAME_LEN];   // ����
	WORD    wDelay;             // ����ӳ� ��λ s 0 ��ʾһֱ�����
	BYTE    byRes1[2];          // �����ֽ�
	BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //��ʾ���Ÿ���ı�������ͨ�� �������������ͬʱ����һ����������������±�0��ʾ��������1���������� 0-������ 1-����
    BYTE    byRes2[60]; 
}NET_DVR_ALARMOUT_PARAM, *LPNET_DVR_ALARMOUT_PARAM;

typedef struct tagNET_DVR_ALARMIN_SETUP
{
    BYTE byAssiciateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];//��������ͨ�� �����±�0��Ӧ���������1����������
    BYTE byRes[100];//�����ֽ�
}NET_DVR_ALARMIN_SETUP, *LPNET_DVR_ALARMIN_SETUP;

typedef struct tagNET_DVR_ALARMHOST_MAIN_STATUS
{
	DWORD  dwSize; 
	BYTE   bySetupAlarmStatus[MAX_ALARMHOST_ALARMIN_NUM];//��������ڲ���״̬��(���֧��512����������ڲ�ѯ)��0-��Ӧ��������ڴ��ڳ���״̬��1-��Ӧ��������ڴ��ڲ���״̬
	BYTE   byAlarmInStatus[MAX_ALARMHOST_ALARMIN_NUM];//��������ڱ���״̬��(���֧��512����������ڲ�ѯ)��0-��Ӧ��������ڵ�ǰ�ޱ�����1-��Ӧ��������ڵ�ǰ�б���
	BYTE   byAlarmOutStatus[MAX_ALARMHOST_ALARMOUT_NUM];//���������״̬��(���֧��512����������ڲ�ѯ)��0-��Ӧ����������ޱ�����1-��Ӧ����������б���
    BYTE   byBypassStatus[MAX_ALARMHOST_ALARMIN_NUM];  // ��·״̬ �����±��ʾ0��Ӧ���������1 0-��ʾ���������û����· 1-��ʾ�����������·
	BYTE   byRes[600];      //  �����ֽ�
}NET_DVR_ALARMHOST_MAIN_STATUS, *LPNET_DVR_ALARMHOST_MAIN_STATUS;

typedef struct tagNET_DVR_ALARMHOST_OTHER_STATUS
{
	DWORD  dwSize;
    BYTE   bySirenStatus[ALARMHOST_MAX_SIREN_NUM];    // �������״̬ 0-���Ŵ����ޱ���״̬��1-���Ŵ����б���״̬
    BYTE   byRes[92];             // �����ֽ�
}NET_DVR_ALARMHOST_OTHER_STATUS, *LPNET_DVR_ALARMHOST_OTHER_STATUS;


//ʹ��״̬����
typedef struct tagNET_DVR_ALARMHOST_ENABLECFG
{
	DWORD dwSize;
	BYTE  byAudioOutEnable[ALARMHOST_MAX_AUDIOOUT_NUM];//�������ʹ�ܣ�0-���ܣ�1-ʹ��
	BYTE  byElectroLockEnable[ALARMHOST_MAX_ELECTROLOCK_NUM];//����ʹ�ܣ�0-���ܣ�1-ʹ��
	BYTE  byMobileGateEnable[ALARMHOST_MAX_MOBILEGATE_NUM];//�ƶ���ʹ�ܣ�0-���ܣ�1-ʹ��
	BYTE  bySirenEnable[ALARMHOST_MAX_SIREN_NUM];//����ʹ�ܣ� 0-���ܣ�1-ʹ��
	BYTE  bySerialPurpose;//������;��0-���ڼ�������������1-����PTZ����
	BYTE  byRes[63];	
}NET_DVR_ALARMHOST_ENABLECFG, *LPNET_DVR_ALARMHOST_ENABLECFG;

typedef struct tagNET_DVR_ALARMHOST_ABILITY
{
	DWORD   dwSize;					  // �ṹ���С
	WORD    wTotalAlarmInNum;         // �������������(����),��������
	WORD    wLocalAlarmInNum;         // ���ر��������
	WORD    wExpandAlarmInNum;        // ����չ�ı��������
	WORD    wTotalAlarmOutNum;        // ������������� ���豸֧�ֵ�������
	WORD    wLocalAlarmOutNum;        // ���ر�������ڸ���
	WORD    wExpandAlarmOutNum;       // ����չ�ı��������
	WORD    wTotalRs485Num;           // ������������� ���豸֧�ֵ�������
	WORD    wLocalRs485Num;           // ����485����
	WORD    wExpandRs485Num;          // ����չ��485����
	WORD	wFullDuplexRs485Num;    // ȫ˫����485����
	WORD    wTotalSensorNum;          // ģ���������� (�豸֧�ֵ�����)
	WORD	wLocalSensorNum;		// ����ģ��������
	WORD    wExpandSensorNum;         // ����չ��ģ��������
	WORD    wAudioOutNum;			    //�����������
	WORD    wGatewayNum;			//�Ž�����
	WORD    wElectroLockNum;		    //��������
	WORD    wSirenNum;     			// ����������Ŀ
	WORD    wSubSystemNum;			// �ɻ�����ϵͳ��Ŀ
    WORD    wNetUserNum;            // �����û���
    WORD    wKeyboardUserNum;           // �����û���
    WORD    wOperatorUserNum;           // �����û���
    WORD    byRes[86];				//  �����ֽ�
}NET_DVR_ALARMHOST_ABILITY, *LPNET_DVR_ALARMHOST_ABILITY;


typedef struct tagNET_DVR_ALARM_RS485CFG
{
	DWORD   dwSize;                 // �ṹ���С
	BYTE    sDeviceName[NAME_LEN];  // ǰ���豸���� 
	WORD    wDeviceType;            // ǰ���豸����ALARM_FRONT_DEVICE _TYPE
	WORD    wDeviceProtocol;        // ǰ���豸Э�� ͨ����ȡЭ���б���ȡ	
	DWORD   dwBaudRate;             //������(bps)��0-50��1-75��2-110��3-150��4-300��5-600��6-1200��7-2400��8-4800��9-9600��10-19200��11-38400��12-57600��13-76800��14-115.2k 
	BYTE    byDataBit;              // �����м�λ��0-5λ��1-6λ��2-7λ��3-8λ 
	BYTE    byStopBit;              // ֹͣλ��0-1λ��1-2λ 
	BYTE    byParity;               //�Ƿ�У�飺0-��У�飬1-��У�飬2-żУ�� 
	BYTE    byFlowcontrol;           // �Ƿ����أ�0-�ޣ�1-������,2-Ӳ���� 
	BYTE	byDuplex;				// 0 - ��˫��1- ȫ˫��  ֻ��ͨ��1������ȫ˫��������ֻ���ǰ�˫��
    BYTE    byWorkMode;				// ����ģʽ 0-����̨ 1-͸��ͨ��
    BYTE    byRes[38];              // �����ֽ�
}NET_DVR_ALARM_RS485CFG, *LPNET_DVR_ALARM_RS485CFG;

#define MAX_DEVICE_PROTO_NUM       256
#define MAX_DEVICE_TYPE_NUM			256

// 485ǰ���豸֧��Э���б�
typedef struct tagNET_DVR_DEVICE_PROTO_LIST
{
    DWORD   dwSize;             // �ṹ���С
    DWORD   dwProtoNum;         // Э�����
    NET_DVR_PROTO_TYPE struProtoType[MAX_DEVICE_PROTO_NUM];  // Э������
    BYTE    byRes[12];          // �����ֽ�
}NET_DVR_DEVICE_PROTO_LIST, *LPNET_DVR_DEVICE_PROTO_LIST;

typedef struct tagNET_DVR_DEVICE_TYPE
{
	DWORD	dwType;
	BYTE	byDescribe[DESC_LEN];
}NET_DVR_DEVICE_TYPE, *LPNET_DVR_DEVICE_TYPE;

typedef struct tagNET_DVR_DEVICE_TYPE_LIST
{
	DWORD	dwSize;				// �ṹ���С
	DWORD	dwTypeNum;			// ���͸���
	NET_DVR_DEVICE_TYPE struDeviceType[MAX_DEVICE_TYPE_NUM];
	BYTE	byRes[12];
}NET_DVR_DEVICE_TYPE_LIST, *LPNET_DVR_DEVICE_TYPE_LIST;

#define ALARMHOST_ABILITY     0x500 //���籨������������ 


typedef struct tagNET_DVR_ALARM_DEVICE_USER
{
	DWORD  dwSize;                 // �ṹ���С
	BYTE   sUserName[NAME_LEN];    // �û���
	BYTE	sPassword[PASSWD_LEN];	// ����
    NET_DVR_IPADDR	struUserIP;					/* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */
    BYTE	byMACAddr[MACADDR_LEN];			/* ������ַ */
    BYTE	    byUserType; // 0-��ͨ�û� 1-����Ա�û�
	BYTE   byAlarmOnRight;         // ����Ȩ��
	BYTE   byAlarmOffRight;        // ����Ȩ��
	BYTE   byBypassRight;          // ��·Ȩ��
	BYTE   byOtherRight[MAX_RIGHT];  // ����Ȩ��
	// ����0  ��־Ȩ��
	// ����1  �����ػ�
	// ����2  ��������Ȩ��
	// ����3  ������ȡȨ��
	// ����4  �ָ�Ĭ�ϲ���Ȩ��
	// ����5  �������Ȩ��
	// ����6  PTZ ����Ȩ��(������ʹ��) 
	// ����7  Զ������Ȩ��
	BYTE	byRes2[200];              // �����ֽ�
}NET_DVR_ALARM_DEVICE_USER, *LPNET_DVR_ALARM_DEVICE_USER;

typedef struct tagNET_DVR_KEYBOARD_USER
{
	DWORD 	dwSize; 	// �ṹ���С
	DWORD	dwID;		// �����û�ID
	BYTE	byDefanceArea[MAX_ALARMHOST_ALARMIN_NUM]; //����Ȩ��  �������±��ʾ ���֧��512������ 0 - ��Ȩ�� 1- ��Ȩ��
	BYTE	byRes[560];		// �����ֽ�
}NET_DVR_KEYBOARD_USER, *LPNET_DVR_KEYBOARD_USER;

typedef struct tagNET_DVR_OPERATE_USER
{
	DWORD	dwSize;		// �ṹ���С
	BYTE    sUserName[NAME_LEN];    // �û���
	BYTE    sPassword[PASSWD_LEN];  // ����
	// ��������Ȩ�� ���֧��512������ �������±��ʾ 0 - ��Ȩ�� 1 - ��Ȩ��
	BYTE    byAlarmOnArea[MAX_ALARMHOST_ALARMIN_NUM];   
	// ��������Ȩ�� ���֧��512������ ���±��ʾ 0 - ��Ȩ�� 1 - ��Ȩ��
	BYTE    byAlarmOffArea[MAX_ALARMHOST_ALARMIN_NUM];  
	// ������·Ȩ�� ���֧��512������ ���±��ʾ 0 - ��Ȩ�� 1 - ��Ȩ��
	BYTE    byBypassArea[MAX_ALARMHOST_ALARMIN_NUM];
	BYTE    byRes[560];             //  �����ֽ�
}NET_DVR_OPERATE_USER, *LPNET_DVR_OPERATE_USER;

typedef struct tagNET_DVR_GATEWAY_CFG
{
    DWORD	dwSize;		// �ṹ���С
    BYTE	byName[NAME_LEN];	//  �Ž�����	
    BYTE	byEnable;	// �Ƿ�����
    BYTE	byRes1;		// �����ֽ�
    WORD    wDelayTime;	// ������ʱʱ��	��λΪ��0-65535 0Ϊһֱ����
    BYTE	byRes2[32];	// �����ֽ�
}NET_DVR_GATEWAY_CFG, *LPNET_DVR_GATEWAY_CFG;

typedef struct tagNET_DVR_SENSOR_ALARM
{
    DWORD   dwSize;		        // �ṹ���С
    DWORD   dwAbsTime;	        // ����ʱ����Ϣ  OSD��ʾ��Ϣ
    BYTE    byName[NAME_LEN]; 	// sensor ����
    BYTE    bySensorChannel;    // ģ����ͨ��
    BYTE    byType;             // ģ��������
    BYTE	byAlarmType;	    // 1-��4��2-��3��3-��2��4-��1��5-��1��6-��2��7-��3��8-��4 �͵�ǰģʽ�й�
                                // ���統Ϊ1000ʱ,����1��1��2��3�������ֱ���
    BYTE	byAlarmMode;        //����ģʽ�����֣�-HHHH��-HHHL��-HHLL��HLLL��-LLLL�� ��Ϊƽ̨�����̶��жϹ��� 
    //����1111���������ϣ���1110���������£���1100���������£���1000(��������)��0000(��������)
    float	fValue;		        // ��ǰģ������ֵ
    BYTE	byRes2[32];		    // �����ֽ�
}NET_DVR_SENSOR_ALARM, *LPNET_DVR_SENSOR_ALARM;

typedef struct 
{
    /*Ԥ����Ŀǰ���������ı���û������(���������򣬼���������)*/
    DWORD  dwAlarmType;             
    /*����0��Ӧ��1������˿�*/
    BYTE   byAlarmInputNumber[MAX_ALARMHOST_ALARMIN_NUM];
    BYTE	byRes[160];
}NET_DVR_ALARMHOST_ALARMINFO,*LPNET_DVR_ALARMHOST_ALARMINFO;
// �����������ϴ�
typedef struct tagNET_DVR_SWITCH_ALARM
{
    DWORD dwSize;
    BYTE   byName[NAME_LEN]; 	// switch ����
    WORD  wSwitchChannel;     // ������ͨ��
    BYTE	byAlarmType;		// �������� 
    BYTE 	byRes[41];			// �����ֽ�
}NET_DVR_SWITCH_ALARM, *LPNET_DVR_SWITCH_ALARM;

typedef union tagNET_DVR_ALARMHOST_EXCEPTION_PARAM
{
    DWORD   dwUnionSize[20];        // �������С    
}NET_DVR_ALARMHOST_EXCEPTION_PARAM, *LPNET_DVR_ALARMHOST_EXCEPTION_PARAM;

typedef struct tagNET_DVR_ALARMHOST_EXCEPTION_ALARM
{
    DWORD   dwSize;             // �ṹ���С
    // �쳣����  1-�豸���𱨾� 2-�豸������ָ����� 3-����Դ���籨�� 4-����Դ�����ָ����� 5-�ڲ�ͨ�Ź��ϱ��� 
    // 6-�ڲ�ͨ�Ź��Ϻ�ָ�����  7-485������·�ϱ���  8-������·�Ϻ�ָ����� 9-�Լ�ʧ�ܱ���  10-�Լ�ʧ�ܺ�ָ�����    
    DWORD   dwExceptionType;    
    NET_DVR_ALARMHOST_EXCEPTION_PARAM uExceptionParam;
    BYTE    byRes[16];          // ����
}NET_DVR_ALARMHOST_EXCEPTION_ALARM, *LPNET_DVR_ALARMHOST_EXCEPTION_ALARM;

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetupAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostCloseAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_BypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_UnBypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostAssistantControl(LONG lUserID, DWORD dwType, DWORD dwNumber, DWORD dwCmdParam);

NET_DVR_API BOOL __stdcall NET_DVR_SetAirCondition(LONG lUserID, LONG l485Index, NET_DVR_AIR_CONDITION_PARAM* lpAirConditionParam);

NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceTypeList(LONG lUserID, NET_DVR_DEVICE_TYPE_LIST *lpDeviceTypeList);

NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceProtoList(LONG lUserID, LONG lDeviceType, NET_DVR_DEVICE_PROTO_LIST *lpDeviceProtoList);

NET_DVR_API BOOL __stdcall NET_DVR_GetBatteryVoltage(LONG lUserID, float *pVoltage);

NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);

NET_DVR_API BOOL __stdcall NET_DVR_ControlGateway(LONG lUserID, LONG lGatewayIndex, DWORD dwStaic);

/******************************************
����:	NET_DVR_SetAlarmHostOut
����:	���ñ������(�������� ��������)
����:	lUserID NET_DVR_Login����ֵ 
        lAlarmOutPort ������������� ��1��ʼ  0xffff��ʾȫ�����������
        lAlarmOutStatic �������״̬��0��ֹͣ�����1�����
���:	��
����ֵ: �ɹ�-HPR_TRUE ʧ��-HPR_FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmHostOut(LONG lUserID, LONG lAlarmOutPort, LONG lAlarmOutStatic);

/******************************************
����:	fAlarmHostSerialDataCallBack
����:	����͸��ͨ���ص�����ָ��
����:	lSerialHandle NET_DVR_AlarmHostSerialStart����ֵ
		lPort 485�ڽ������ݵĲ�λ�� ��1��ʼ  232 �ò�����Ч
		lDateType �������� 0-��ʾ���ݽ������� 1-��ʾͨ����֧��͸��ͨ�������485�ڣ�
		pRecvDataBuffer ������ݵĻ�����ָ��
		pUser �û�����
���:	��
����ֵ: ��
******************************************/
typedef void(CALLBACK *fAlarmHostSerialDataCallBack)
(LONG lSerialHandle, LONG lPort, LONG lDateType, char *pRecvDataBuffer, DWORD  dwBufSize,void *pUser);

/******************************************
����:	NET_DVR_AlarmHostSerialStart
����:	�ͱ��������豸����͸��ͨ��
����:	lUserID NET_DVR_Login����ֵ
		lSerialType ����͸��ͨ������  1 - ����232ͨ�� 2 - ����485ͨ��
		cbSerialDataCallBack ָ��fAlarmHostSerialDataCallBack����ָ�룬���ڽ���͸��ͨ������
		dwUser  �û�����
���:	��
����ֵ: -1 ��ʾʧ�� ����ֵ��ΪNET_DVR_AlarmHostSerialSend�Ⱥ������
******************************************/
NET_DVR_API LONG __stdcall NET_DVR_AlarmHostSerialStart(LONG lUserID, LONG lSerialType, fAlarmHostSerialDataCallBack cbSerialDataCallBack, void *pUser);

/******************************************
����:	NET_DVR_AlarmHostSerialSend
����:	��͸��ͨ��ָ����485�ڻ���232�ڷ�������
����:	lSerialHandle NET_DVR_AlarmHostSerialStart����ֵ
		lPort ��Ϊ485͸��ͨ��ʱʹ�ã�485�ڵĲ�λ�ţ���1��ʼ
		pSendBuf ָ�������ݻ�������ָ��
		dwBufSize �������ݵĴ�С
���:	��
����ֵ: �ɹ�-TURE ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialSend(LONG lSerialHandle,LONG lPort,char *pSendBuf,DWORD dwBufSize);

/******************************************
����:	NET_DVR_AlarmHostSerialStop
����:	�ر�͸��ͨ��
����:	lSerialHandle NET_DVR_AlarmHostSerialStart����ֵ
���:	��
����ֵ: �ɹ�-TRUE ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialStop(LONG  lSerialHandle);

#define  MAX_PU_CHAN_NUM    512

typedef struct tagNET_DVR_PU_CHAN_INFO
{
    NET_DVR_IPADDR  struIpAddr;     // ip��ַ
    WORD            wPort;          // �˿�
    WORD            wChannel;       // ͨ��     
    BYTE            byRes[24];      // 
}NET_DVR_PU_CHAN_INFO, *LPNET_DVR_PU_CHAN_INFO;

typedef struct tagNET_DVR_PU_CHAN_LIST
{
    DWORD   dwSize;     // �ṹ��
    DWORD   dwNum;      // ǰ��ͨ������
    NET_DVR_PU_CHAN_INFO struPuChanInfo[MAX_PU_CHAN_NUM];
}NET_DVR_PU_CHAN_LIST, *LPNET_DVR_PU_CHAN_LIST;
/******************************************
����:	NET_DVR_GetMatrixPuChan
����:	��ȡ��Ƶ�ۺ�ƽ̨Cam�ź�Mon��
����:	lUserID NET_DVR_Login_V30����ֵ 
        lChanType   ��ȡͨ�������� 0-Cam�� 1-Mon��
        lpChanList ָ��NET_DVR_PU_CHAN_LIST�ṹָ��
���:	lpChanList ָ��NET_DVR_PU_CHAN_LIST�ṹָ��
����ֵ: �ɹ�-TRUE ʧ��-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetMatrixPuChan(LONG lUserID, LONG lChanType, NET_DVR_PU_CHAN_LIST* lpChanList);


#define  MAX_ALARM_CAM_NUM	32		// ��������CAM������

typedef struct tagNET_DVR_PTZ_CTRL
{
	BYTE    byEnable;   // �Ƿ�����PTZ����
	BYTE    byType;     // PTZ ���Ƶ����� 1- Ԥ�õ� 2 -Ѳ��  3-�켣
	BYTE    byPtzNo;    //  ptz ���Ƶ�Ԥ�õ� Ѳ�� �켣��
	BYTE    byRes[5];    // �����ֽ�
}NET_DVR_PTZ_CTRL, *LPNET_DVR_PTZ_CTRL;

typedef struct tagNET_DVR_ALARM_CAM_INFO
{
	DWORD			dwCamID;      // ������CAMͨ������
	DWORD           dwRecordTime;   // ����¼��ʱ�� ��λΪs  -1��ʾһֱ¼�� 0 ��ʾ��¼��
	DWORD           dwMonID;      // ����Cam��Mon����ʾ
	DWORD           dwResidentTime; // ��Ѳͣ��ʱ�䵥λΪs  -1��ʾһֱͣ�� 0 ��ʾ��ͣ��
	NET_DVR_PTZ_CTRL    struPtzCtrl;    // PTZ������Ϣ
    BYTE			byAlarmOffMode;		// �����л���ǽȡ��ģʽ   0-����ȡ����1-�Զ�ȡ����2-�ֶ�ȡ�� ����ȡ��������ȡ��ʱ����ȡ��������ǽ   �Զ�ȡ��������ȡ��ʱ�ȴ�һ��ʱ���ȡ��������ǽ������Լ����20��  �ֶ�ȡ�����û�ͨ���ֶ��ķ�ʽȡ��
    BYTE            byDevType;		// ���豸Ϊ�����豸ʱ����Ч��ʾ���ܱ����豸ȡ��Դ 1-���뿨	 2-���뿨
    BYTE            byDecChan;		// ��Ϊ����ͨ��Ϊ����ͨ����
    BYTE            byRes[17];      // �����ֽ�
}NET_DVR_ALARM_CAM_INFO, *LPNET_DVR_ALARM_CAM_INFO;

typedef struct tagNET_DVR_ALARM_CAM_CFG
{
	DWORD		dwSize;			// �ṹ���С
	BYTE        byEnable;       // �Ƿ����ñ�������CAM���� �豸Ĭ�ϲ�����
	BYTE        byRes[7];       // �����ֽ�
	DWORD		dwNum;			// ����CAM�����ĸ��� ��ȡ�����ǰ������Ч����  
	NET_DVR_ALARM_CAM_INFO struAlarmCam[MAX_ALARM_CAM_NUM];
}NET_DVR_ALARM_CAM_CFG, *LPNET_DVR_ALARM_CAM_CFG;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmOffMonitor(LONG lUserID, DWORD dwMonID, DWORD dwCamID);

/************************************************************************/

//2010-12-28 ������뿨������ begin
//�µĽ��뿨������������
#define		MAX_DECODE_CARD_NUM			6   //��������뿨��
/********************������뿨���ģʽ�궨��********************/
typedef enum _HD_DISPLAY_FORMAT
{
	HD_DISPLAY_FORMAT_INVALID = 0x00000000,
	HD_DISPLAY_FORMAT_CVBS = 0x00000001,
	HD_DISPLAY_FORMAT_DVI = 0x00000002,
	HD_DISPLAY_FORMAT_VGA = 0x00000004, 
	HD_DISPLAY_FORMAT_HDMI = 0x00000008, 
	HD_DISPLAY_FORMAT_YPbPr = 0x00000010
}HD_DISPLAY_FORMAT,*LPHD_DISPLAY_FORMAT;

/********************������뿨���ģʽ�궨��********************/
typedef struct tagNET_DVR_DECCARD_ABILITY      /*������뿨������*/
{
    BYTE byCardType;      //���뿨����(0:MD,1:MD+,2:HD)
    BYTE byDecNums;      //����ͨ����
    BYTE byDispNums;      //��ʾͨ����
    BYTE byDecStartIdx;     //�׸�����ͨ�������н���ͨ���е�����
    BYTE byDispStartIdx;     //�׸���ʾͨ����������ʾͨ���е�����
    BYTE byDispResolution[80]; //���ģʽ֧�ֵķֱ���
    BYTE byDispFormat[8];     //֧�ֵ����ģʽ(��HD_DISPLAY_FORMAT)
    BYTE byWindowMode[4][8]; //֧�ֵĴ���ģʽ(����1,2,4,9,16))
    BYTE byRes [35];
} NET_DVR_DECCARD_ABILITY,*LPNET_DVR_DECCARD_ABILITY;

typedef struct tagNET_DVR_DECODESVR_ABILITY
{
    DWORD dwSize;      /* �ṹ���С */
    BYTE byCardNums;      /* ���뿨�� */
    BYTE byStartChan;     /* ��ʼͨ���� */
    BYTE byRes1[2];
    NET_DVR_DECCARD_ABILITY struDecCardAbility[MAX_DECODE_CARD_NUM];
	BYTE byRes2[64];
}NET_DVR_DECODESVR_ABILITY, *LPNET_DVR_DECODESVR_ABILITY;
#define DECODECARD_ABILITY 0x220 //���뿨������������
//2010-12-28 ������뿨������ end

//2010-12-28
/*camera���õ�Ԫ�ṹ*/
typedef struct tagNET_DVR_MATRIX_CAMERACFG
{
    DWORD					dwGlobalIndex;//ȫ�ֱ��
    DWORD					dwInterIndex;//�ֲ����
	BYTE					sCamName[NAME_LEN];
    NET_DVR_PU_STREAM_CFG	struPuStreamCfg;
} NET_DVR_MATRIX_CAMERACFG,*LPNET_DVR_MATRIX_CAMERACFG;

typedef struct tagNET_DVR_MATRIX_CAMERALIST
{
	DWORD			dwSize;
	BYTE			byRes[12];
	DWORD			dwCamNum;//CAM����
	BYTE  			*pBuffer;
	DWORD 			dwBufLen;//������ָ�볤�ȣ��������
} NET_DVR_MATRIX_CAMERALIST,*LPNET_DVR_MATRIX_CAMERALIST;
// ����: ��ȡǰ��CAM�б���Ϣ
// ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ
// 			 lpCamListInfo��NET_DVR_MATRIX_CAMERALIST�ṹָ��
// 			 ����ֵ��
// TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_GetCameraListInfo(LONG lUserID, DWORD dwCamNum, DWORD dwStartCam, LPNET_DVR_MATRIX_CAMERALIST lpCamListInfo);

typedef struct tagNET_DVR_DISP_CHAN_INFO
{
    NET_DVR_IPADDR	struIP;				/* ������ IP��ַ */
    WORD 	wDVRPort;			 	/* �˿ں� */
    BYTE 	byDispChannel;			/* ��ʾͨ���� */
    BYTE	byRes[9];
    BYTE	sUserName[NAME_LEN];	/*��½�ʺ� */
    BYTE	sPassword[PASSWD_LEN];	/*���� */
}NET_DVR_DISP_CHAN_INFO,*LPNET_DVR_DISP_CHAN_INFO;

/*monitor���õ�Ԫ�ṹ*/
typedef struct tagNET_DVR_MATRIX_MONITORCFG
{
    DWORD						dwGlobalIndex;//ȫ�ֱ��
    DWORD						dwInterIndex;
	BYTE						sMonName[NAME_LEN];
    NET_DVR_DISP_CHAN_INFO		struDispChanCfg;
} NET_DVR_MATRIX_MONITORCFG,*LPNET_DVR_MATRIX_MONITORCFG;
typedef struct tagNET_DVR_MATRIX_MONITORLIST
{
    DWORD		dwSize;
	BYTE		byRes[12];
	DWORD		dwMonNum;//MON����
	BYTE  		*pBuffer;
	DWORD 		dwBufLen;//������ָ�볤�ȣ��������
} NET_DVR_MATRIX_MONITORLIST,*LPNET_DVR_MATRIX_MONITORLIST;
// ����: ��ȡMONITOR�б���Ϣ
// ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ
// 			 lpMonListInfo��NET_DVR_MATRIX_MONITORLIST�ṹָ��
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_GetMonitorListInfo(LONG lUserID, DWORD dwMonNum, DWORD dwStartMon, LPNET_DVR_MATRIX_MONITORLIST lpMonListInfo);

NET_DVR_API BOOL __stdcall NET_DVR_GetGlobalNum(LONG lUserID, DWORD *dwCamNum, DWORD *dwMonNum);



#define 	MAX_SUBMATRIX_NUM		8//������������ϵͳ����
typedef struct tagNET_DVR_SUBMATRIXINFO
{
	BYTE		byMainMatrix;//�Ƿ�����ϵͳ��1-�ǣ�0-��
	BYTE		bySubMatrixSequence;//��������Ƶ�ۺ�ƽ̨ϵͳ���
	BYTE		byLoginType;//ע�����ͣ�1-ֱ����2-DNS��3-������
	BYTE		byRes1[9];
	NET_DVR_IPADDR   struSubMatrixIP;		/*IP��ַ�����޸ģ�*/
	WORD		wSubMatrixPort;        /*��ϵͳ�˿ںţ����޸ģ�*/
	BYTE		byRes2[6];
	NET_DVR_IPADDR   struSubMatrixIPMask;    /*IP��ַ����*/
	NET_DVR_IPADDR	struGatewayIpAddr;		 /* ���ص�ַ */    
	BYTE		sUserName[NAME_LEN];	/* �û��� ���˲���ֻ�ܻ�ȡ��*/
	BYTE		sPassword[PASSWD_LEN];	/*���� ���˲���ֻ�ܻ�ȡ��*/
	char		sDomainName[MAX_DOMAIN_NAME];//����(���޸�)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS������IP��ַ*/
	BYTE		sSerialNumber[SERIALNO_LEN];//���кţ��˲���ֻ�ܻ�ȡ��
	BYTE		byRes3[16];
}NET_DVR_SUBMATRIXINFO, *LPNET_DVR_SUBMATRIXINFO;

typedef struct tagNET_DVR_ALLUNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBMATRIXINFO struSubMatrixInfo[MAX_SUBMATRIX_NUM];
	BYTE  byRes2[32];
}NET_DVR_ALLUNITEDMATRIXINFO, *LPNET_DVR_ALLUNITEDMATRIXINFO;
		 
// ����:��ȡ��Ƶ�ۺ�ƽ̨��������
// ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ(78K)
// 			 lpInter��LPNET_DVR_ALLUNITEDMATRIXINFO�ṹ
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter);

// ����:������Ƶ�ۺ�ƽ̨��������
// ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ(78K)
// 			 lpInter��LPNET_DVR_ALLUNITEDMATRIXINFO�ṹ
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter);

			 
#define	MAX_GATEWAYTRUNKNUM		1024 //������Ƶ�ۺ�ƽ̨�����·�ɸ�����
	 
typedef struct tagNET_DVR_MATRIXGATEWAYNOTE
{
	 WORD	wTrunkInToOutAbility;//���ߴ�������D1�ı�׼��������4��ʾ֧��4��D1
	 WORD	wTrunkOutToInAbility;//���ߴ�������D1�ı�׼��������4��ʾ֧��4��D1��˫�����ʱ�õ���ֵ
	 BYTE    byRes[4];
	 NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;
	 NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;
}NET_DVR_MATRIXGATEWAYNOTE, *LPNET_DVR_MATRIXGATEWAYNOTE;

typedef struct tagNET_DVR_MATRIXGATEWAYINFO
{
	 DWORD dwSize;
	 NET_DVR_MATRIXGATEWAYNOTE struGatewayNote[MAX_GATEWAYTRUNKNUM];
	 BYTE  byRes [32];
}NET_DVR_MATRIXGATEWAYINFO, *LPNET_DVR_MATRIXGATEWAYINFO;
// 		 ����:��ȡ��Ƶ�ۺ�ƽ̨·������
// 			 ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ(78K)
// 			 lpInter��LPNET_DVR_MATRIXGATEWAYINFO�ṹ
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��		 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);

// 			 ����:������Ƶ�ۺ�ƽ̨·������
// 			 ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ(78K)
// 			 lpInter��LPNET_DVR_MATRIXGATEWAYINFO�ṹ
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��			 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);


typedef struct tagNET_DVR_MATRIXCODESYSTEMINFO
{
	 BYTE   byMatrixNum;//��Ƶ�ۺ�ƽ̨��
	 BYTE	bySubSystemNum;//��ϵͳ��λ��
	 BYTE	byChan;//����ͨ��
	 BYTE   byRes [13];
}NET_DVR_MATRIXCODESYSTEMINFO,*LPNET_DVR_MATRIXCODESYSTEMINFO;
typedef struct tagNET_DVR_MATRIXDECODESYSTEMINFO
{
	 BYTE    byMatrixNum;//��Ƶ�ۺ�ƽ̨��
	 BYTE	bySubSystemNum;//��ϵͳ��λ��
	 BYTE	byDispChan;//��ʾͨ��
	 BYTE	bySubDispChan;//��ʾͨ����ͨ����
	 BYTE    byRes [12];
}NET_DVR_MATRIXDECODESYSTEMINFO,*LPNET_DVR_MATRIXDECODESYSTEMINFO;

typedef struct tagNET_DVR_MATRIXSWITCH
{
	 NET_DVR_MATRIXCODESYSTEMINFO struInputNote;
	 NET_DVR_MATRIXDECODESYSTEMINFO struOutputNote;
	 BYTE	byRes[32];
}NET_DVR_MATRIXSWITCH, *LPNET_DVR_MATRIXSWITCH;
// 		 ����:�л�����
// 			 ����˵��:
// lUserID: NET_DVR_Login()�ķ���ֵ(78K)
// 			 nSwitchMode��1-��ʼ�л���2-ֹͣ�л�
// 			 lpInter��LPNET_DVR_MATRIXSWITCH�ṹ
// 			 ����ֵ��
// 			 TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSpanSwitch(LONG lUserID, BYTE nSwitchMode, LPNET_DVR_MATRIXSWITCH lpInter);

typedef enum {
	ENC_CARD = 0,
	DEC_CARD,
	SD_DEC_CARD,
	FPGA_CARD,
	CS_CARD,
	ALERTOR_CARD,
	NAT_0,
	NAT_1,
	VCA_CARD,
	VGA_DEC_CARD,
	VGA_ENC_CARD,
	ERR_CARD,
} DEV_TYPE;

typedef struct tagNET_DVR_MATRIXSWITCHCTRL
{
	DWORD dwCamId;//�����ȫ�ֱ��
	DWORD dwMonId;//������ȫ�ֱ��
	BYTE  bySubWindowNum;//��������Ӧ�Ӵ��ں�
	/* �л����ͣ�0:�����л���1:���������л���2:����ȡ����0xff:��ʾ��MON�����б���ȫ��ȡ��*/
	BYTE   bySwitchType;
	WORD   wAlarmType;//�����豸���ͣ�1:����������2�������豸
	DWORD  dwResidentTime;/* ��ʾפ��ʱ�䣬0xFFFFFFFF ʱ Ϊ��פ�����������ʾ*/
	BYTE   byVcaDevType;//�������豸������"�����豸"ʱ����DEV_TYPE����
	BYTE   byRes[19];
}NET_DVR_MATRIXSWITCHCTRL, *LPNET_DVR_MATRIXSWITCHCTRL;
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartSwitch(LONG lUserID, LPNET_DVR_MATRIXSWITCHCTRL lpInter);


typedef struct tagNET_DVR_MATRIXDATABASE
{
	//�����ļ����ͣ�1-�����ݿ������ļ���2-�������ݿ������ļ���3-ƽ̨���ݿ������ļ�,0xff���һ��ʧ�ܵ����ݿ����
	DWORD dwDevType; 
	DWORD dwParam; //������������š�����š�ƽ̨��
	BYTE  byFileType;//�ļ����ͣ�1-sql��䣬2-db���
	BYTE  byRes [3];
} NET_DVR_MATRIXDATABASE, *LPNET_DVR_MATRIXDATABASE;


// ����:������Ƶ�ۺ�ƽ̨�����ļ�
// ����˵��:
// lUserID 
// [in] �û�ID�ţ�NET_DVR_Login()��NET_DVR_Login_V30()�ķ���ֵ 
// lpInter:
// [in] LPNET_DVR_MATRIXDATABASE�ṹ
// sInBuffer 
// [in] ������ò����Ļ����� 
// dwInSize 
// [in] ��������С 
// ����ֵ��
// TRUE��ʾ�ɹ�,FALSE��ʾʧ��
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char *sInBuffer,  DWORD dwInSize);



// ����:������Ƶ�ۺ�ƽ̨�����ļ�
// ����˵��:
// lUserID 
// [in] �û�ID�ţ�NET_DVR_Login()��NET_DVR_Login_V30()�ķ���ֵ
// lpInter:
// [in] LPNET_DVR_MATRIXDATABASE�ṹ
// sOutBuffer 
// [out] ������ò����Ļ����� 
// dwOutSize 
// [in] ��������С 
// pReturnSize 
// [out] ʵ�ʻ�õĻ�������С 
// ����ֵ��
// TRUE��ʾ�ɹ�,FALSE��ʾʧ��
// ע�⣺��sOutBuffer = NULL��dwOutSize = 0��pReturnSize != NULLʱ���ڻ�ȡ���������ļ�������Ļ��������ȣ���sOutBuffer != NULL��dwOutSize != 0ʱ���ڻ�ȡ���������ļ�������Ļ��������ݡ�
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char  *sOutBuffer,  DWORD   dwOutSize,  DWORD   *pReturnSize);
typedef struct tagNET_DVR_SUBSYSTEMINFO_V40
{
	/*��ϵͳ���ͣ�1-��������ϵͳ��2-��������ϵͳ��3-���������ϵͳ��4-����������ϵͳ��5-�������ϵͳ��6-����������ϵͳ��7-������ϵͳ��8-V6������ϵͳ��9-V6��ϵͳ��0-NULL���˲���ֻ�ܻ�ȡ��*/
	BYTE		bySubSystemType;
	//��ϵͳͨ���������������ϵͳ������485�����������˲���ֻ�ܻ�ȡ��
	BYTE		byChan;
	BYTE		byLoginType;//ע�����ͣ�1-ֱ����2-DNS��3-������
	BYTE		bySlotNum ;//��λ�ţ��˲���ֻ�ܻ�ȡ
    BYTE		byRes1[4];
	NET_DVR_IPADDR   struSubSystemIP;		/*IP��ַ�����޸ģ�*/
		NET_DVR_IPADDR   struSubSystemIPMask;//��������
	NET_DVR_IPADDR	struGatewayIpAddr;	/* ���ص�ַ */
	WORD		wSubSystemPort;        //��ϵͳ�˿ںţ����޸ģ�
	BYTE		byRes2[6];
    BYTE		sUserName[NAME_LEN];	/* �û��� ���˲���ֻ�ܻ�ȡ��*/
		BYTE		sPassword[PASSWD_LEN];	/*����(���޸�)*/
		char			sDomainName[MAX_DOMAIN_NAME];//����(���޸�)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS������IP��ַ*/
	BYTE		sSerialNumber[SERIALNO_LEN];//���кţ��˲���ֻ�ܻ�ȡ��
	BYTE		byRes3[60];
}NET_DVR_SUBSYSTEMINFO_V40, *LPNET_DVR_SUBSYSTEMINFO_V40;

#define  MAX_SUBSYSTEM_NUM_V40  120
typedef struct tagNET_DVR_ALLSUBSYSTEMINFO_V40
{
	DWORD dwSize;
	NET_DVR_SUBSYSTEMINFO_V40 struSubSystemInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO_V40, *LPNET_DVR_ALLSUBSYSTEMINFO_V40;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);



typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO_V40
{
	/*��ϵͳ���ͣ�1-��������ϵͳ��2-��������ϵͳ��3-���������ϵͳ��4-����������ϵͳ��5-�������ϵͳ��6-����������ϵͳ��7-������ϵͳ��8-V6������ϵͳ��9-V6��ϵͳ��0-NULL���˲���ֻ�ܻ�ȡ��*/
	BYTE	bySubSystemType; 
	BYTE	byConnectStatus;//����ϵͳ����״̬��1-����������2-���ӶϿ�
	BYTE   byMatrixNum;//������Ƶ�ۺ�ƽ̨�ţ���ϵͳ������3��4ʱ����
	BYTE	bySubSystemNum;//������ϵͳ��λ�ţ�0~79����ϵͳ������3��4ʱ����
	NET_DVR_DECSUBSYSTEMJIONSTATUS 
		struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
	BYTE	byBindStatus;//��״̬��0-û�а󶨣�1-�Ѿ��󶨣�����ƴ��ʱ�õ���
	BYTE	bySlotNum ;//��λ�ţ��˲���ֻ�ܻ�ȡ
	BYTE  byRes[66];
}NET_DVR_SINGLESUBSYSTEMJOININFO_V40,LPNET_DVR_SINGLESUBSYSTEMJOININFO_V40;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO_V40
{
	DWORD dwSize;
	NET_DVR_SINGLESUBSYSTEMJOININFO_V40 struSingleSubSystemJoinInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE  byRes[48];
}NET_DVR_ALLDECSUBSYSTEMJOININFO_V40, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo_V40(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40 lpInter);

#define  MAX_OPTICALFIBER_NUM  16
typedef struct tagNET_DVR_SUBSYSTEM_ABILITY
{
	/*��ϵͳ���ͣ�1-��������ϵͳ��2-��������ϵͳ��3-���������ϵͳ��4-����������ϵͳ��5-�������ϵͳ��6-����������ϵͳ��7-������ϵͳ��8-V6������ϵͳ��9-V6��ϵͳ��0-NULL���˲���ֻ�ܻ�ȡ��*/
	BYTE	bySubSystemType;
	BYTE   byChanNum;//��ϵͳͨ����
	BYTE  byStartChan;//��ϵͳ��ʼͨ����
	BYTE	bySlotNum ;//��λ�� 
	BYTE  byRes1[4];
	union
	{
		BYTE byRes[200];
		struct
		{
			BYTE  byVGANums;//VGA��ʾͨ����������1��ʼ��
			BYTE  byBNCNums;//BNC��ʾͨ����������9��ʼ��
			BYTE  byHDMINums;//HDMI��ʾͨ����������25��ʼ��
			BYTE  byDVINums;//DVI��ʾͨ����������29��ʼ��
			BYTE  byRes[196];
		}struDecoderSystemAbility;
		struct
		{
			BYTE  byCoderType;//���������ͣ�0-���壬1-����
			BYTE  byRes[199];
		}struCoderSystemAbility;
		struct
		{
			WORD	wTrunkAbility;//���ߴ�������D1�ı�׼��������4��ʾ֧��4��D1
			BYTE   byOpticalFiberNum;//��������
			BYTE  byRes[197];
		}struInputSystemAbility;
		struct
		{
			WORD	wTrunkAbility;//���ߴ�������D1�ı�׼��������4��ʾ֧��4��D1
			BYTE   byOpticalFiberNum;//��������
			BYTE  byRes[197];
		}struOutputSystemAbility;
		struct
		{
			BYTE	by485Num;//�����ϵͳ��485����
			BYTE	bySlotNum;//ÿ��485��λ��
			BYTE  byRes[198];
		}struCodeSpitterSystemAbility;
		struct
		{
			WORD	wAlarmInNums;
			WORD	wAlarmOutNums;
			/* ��ʶ�������Ƿ����ӣ� 1��ʾ�����ӣ� Ϊ0 ��ʾδ���� */
			BYTE  byAlarmBoxEnable[4][8];
			BYTE  byRes[164];
		}struAlarmHostSystemAbility;
		struct
		{
			BYTE  byOpticalFiberNum;//��������
			BYTE  byRes1[3];
			//���˴�������D1�ı�׼��������4��ʾ֧��4��D1
			WORD	wTrunkAbility[MAX_OPTICALFIBER_NUM/*16*/];
			BYTE  byRes2[164];
		}struInOutputSystemAbility;
	}struAbility;
}NET_DVR_SUBSYSTEM_ABILITY, *LPNET_DVR_SUBSYSTEM_ABILITY;

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY_V40
{
    DWORD dwSize;
	BYTE  byCodeSubSystemNums;//������ϵͳ����
	BYTE  byDecodeSubSystemNums;//������ϵͳ����
	BYTE  bySupportNat;//�Ƿ�֧��NAT��0-��֧�֣�1-֧��
	BYTE  byInputSubSystemNums;//����������ϵͳ����
	BYTE	byOutputSubSystemNums;//���������ϵͳ����
	BYTE	byCodeSpitterSubSystemNums;//�����ϵͳ����
	BYTE	byAlarmHostSubSystemNums;//������ϵͳ����
	BYTE	bySupportBigScreenNum;//��֧��������ƴ������
	BYTE	byVCASubSystemNums;//������ϵͳ����
	BYTE	byV6SubSystemNums;//V6��ϵͳ����
	BYTE	byV6DecoderSubSystemNums;//V6������ϵͳ����
	BYTE  byRes1[9];
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM_V40];
	BYTE	by485Nums;//485���ڸ���
	BYTE	by232Nums;//232���ڸ���
	BYTE	bySerieStartChan;//��ʼͨ��
    BYTE  byRes2[637];
}NET_DVR_VIDEOPLATFORM_ABILITY_V40, *LPNET_DVR_VIDEOPLATFORM_ABILITY_V40;
#define VIDEOPLATFORM_ABILITY_V40          0x230 //��Ƶ�ۺ�ƽ̨������

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY
{
    DWORD dwSize;
	BYTE  byCodeSubSystemNums;//������ϵͳ����
	BYTE  byDecodeSubSystemNums;//������ϵͳ����
	BYTE  bySupportNat;//�Ƿ�֧��NAT��0-��֧�֣�1-֧��
    BYTE  byInputSubSystemNums;//����������ϵͳ����
    BYTE  byOutputSubSystemNums;//���������ϵͳ����
    BYTE  byCodeSpitterSubSystemNums;//�����ϵͳ����
    BYTE  byAlarmHostSubSystemNums;//������ϵͳ����
    BYTE  bySupportBigScreenNum;//��֧��������ƴ������
    BYTE  byVCASubSystemNums;//������ϵͳ����
	BYTE  byRes1[11];   
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM];
    BYTE  by485Nums;//485���ڸ���
    BYTE  by232Nums;//485���ڸ���
    BYTE  bySerieStartChan;//��ʼͨ��
    BYTE  byRes2[637];    
}NET_DVR_VIDEOPLATFORM_ABILITY, *LPNET_DVR_VIDEOPLATFORM_ABILITY;
//��ȡ�������ӿ�
#define VIDEOPLATFORM_ABILITY          0x210 //��Ƶ�ۺ�ƽ̨������

/*********************************9000 2.0 begin***************************************/

#define NET_DVR_GET_HOLIDAY_PARAM_CFG       1240        // ��ȡ�ڼ��ղ���
#define NET_DVR_SET_HOLIDAY_PARAM_CFG       1241        // ���ýڼ��ղ���

#define NET_DVR_GET_MOTION_HOLIDAY_HANDLE   1242        // ��ȡ�ƶ������ձ���������ʽ
#define NET_DVR_SET_MOTION_HOLIDAY_HANDLE   1243        // ��ȡ�ƶ������ձ���������ʽ

#define NET_DVR_GET_VILOST_HOLIDAY_HANDLE   1244        // ��ȡ��Ƶ�źŶ�ʧ���ձ���������ʽ
#define NET_DVR_SET_VILOST_HOLIDAY_HANDLE   1245        // ��ȡ��Ƶ�źŶ�ʧ���ձ���������ʽ

#define NET_DVR_GET_HIDE_HILIDAY_HANDLE     1246        // ��ȡ�ڸǼ��ձ���������ʽ
#define NET_DVR_SET_HIDE_HILIDAY_HANDLE     1247        // �����ڸǼ��ձ���������ʽ

#define NET_DVR_GET_ALARMIN_HOLIDAY_HANDLE  1248        // ��ȡ����������ձ���������ʽ
#define NET_DVR_SET_ALARMIN_HOLIDAY_HANDLE  1249        // ���ñ���������ձ���������ʽ

#define NET_DVR_GET_ALARMOUT_HOLIDAY_HANDLE 1250        // ��ȡ����������ձ���������ʽ
#define NET_DVR_SET_ALARMOUT_HOLIDAY_HANDLE 1251        // ���ñ���������ձ���������ʽ

#define NET_DVR_GET_HOLIDAY_RECORD          1252        // ��ȡ����¼�����
#define NET_DVR_SET_HOLIDAY_RECORD          1253        // ���ü���¼�����

//  ģʽA 
typedef struct tagNET_DVR_HOLIDATE_MODEA
{
    BYTE    byStartMonth;	// ��ʼ�� ��1��ʼ
    BYTE	byStartDay;		// ��ʼ�� ��1��ʼ
    BYTE	byEndMonth;		// ������ 
    BYTE	byEndDay;		// ������
    BYTE	byRes[4];		// �����ֽ�
}NET_DVR_HOLIDATE_MODEA, *LPNET_DVR_HOLIDATE_MODEA;

typedef struct tagNET_DVR_HOLIDATE_MODEB
{
    BYTE	byStartMonth;	// ��1��ʼ
    BYTE	byStartWeekNum;	// �ڼ������� ��1��ʼ 
    BYTE	byStartWeekday;	// ���ڼ�
    BYTE	byEndMonth;		// ��1��ʼ
    BYTE	byEndWeekNum;	// �ڼ������� ��1��ʼ 
    BYTE	byEndWeekday;	// ���ڼ�	
    BYTE	byRes[2];		// �����ֽ� 
}NET_DVR_HOLIDATE_MODEB, *LPNET_DVR_HOLIDATE_MODEB;

typedef struct tagNET_DVR_HOLIDATE_MODEC
{
    WORD	wStartYear;		// ��
    BYTE	byStartMon;		// ��
    BYTE	byStartDay;		// ��
    WORD	wEndYear;		// ��
    BYTE	byEndMon;		// ��
    BYTE	byEndDay;		// ��
}NET_DVR_HOLIDATE_MODEC, *LPNET_DVR_HOLIDATE_MODEC;

typedef union tagNET_DVR_HOLIDATE_UNION
{	
    // �������С 12�ֽ�
    DWORD				    dwSize[3];
    NET_DVR_HOLIDATE_MODEA	struModeA;	// ģʽA
    NET_DVR_HOLIDATE_MODEB	struModeB;	// ģʽB
    NET_DVR_HOLIDATE_MODEC	struModeC;	// ģʽC
}NET_DVR_HOLIDATE_UNION, *LPNET_DVR_HOLIDATE_UNION;

typedef enum tagHOLI_DATE_MODE
{
    HOLIDATE_MODEA = 0,
    HOLIDATE_MODEB,
    HOLIDATE_MODEC
}HOLI_DATE_MODE;

typedef struct tagNET_DVR_HOLIDAY_PARAM
{
    BYTE	byEnable;			// �Ƿ�����
    BYTE	byDateMode;			// ����ģʽ 0-ģʽA 1-ģʽB 2-ģʽC
    BYTE	byRes1[2];			// �����ֽ�
    NET_DVR_HOLIDATE_UNION uHolidate;	// ��������
    BYTE	byName[NAME_LEN];	// ��������
    BYTE	byRes2[20];			// �����ֽ�
}NET_DVR_HOLIDAY_PARAM, *LPNET_DVR_HOLIDAY_PARAM;

#define  MAX_HOLIDAY_NUM	32

typedef struct tagNET_DVR_HOLIDAY_PARAM_CFG
{
    DWORD	dwSize;			// �ṹ���С
    NET_DVR_HOLIDAY_PARAM struHolidayParam[MAX_HOLIDAY_NUM];	// ���ղ���
    DWORD	byRes[40];		// ��������
}NET_DVR_HOLIDAY_PARAM_CFG, *LPNET_DVR_HOLIDAY_PARAM_CFG;

// ���ձ���������ʽ
typedef struct tagNET_DVR_HOLIDAY_HANDLE
{
    DWORD	dwSize;				// �ṹ���С
    NET_DVR_SCHEDTIME              struAlarmTime[MAX_TIMESEGMENT_V30];	// ����ʱ���
    BYTE	byRes2[240];		// �����ֽ�
}NET_DVR_HOLIDAY_HANDLE, *LPNET_DVR_HOLIDAY_HANDLE;

typedef struct tagNET_DVR_HOLIDAY_RECORD
{
    DWORD           dwSize;
    NET_DVR_RECORDDAY     struRecDay;     // ¼�����
    NET_DVR_RECORDSCHED   struRecordSched[MAX_TIMESEGMENT_V30]; // ¼��ʱ���
    BYTE      byRes[20];      //  �����ֽ�
}NET_DVR_HOLIDAY_RECORD, *LPNET_DVR_HOLIDAY_RECORD;
/*********************************9000 2.0 end***************************************/

typedef struct tagNET_DVR_ENCODE_JOINT_PARAM
{
    DWORD	dwSize;			// �ṹ���С
    BYTE	byJointed;		//  0 û�й��� 1 �Ѿ�����
    BYTE	byDevType;		// ���������豸����  1 ���������豸
    BYTE	byRes1[2];		// �����ֽ�
    NET_DVR_IPADDR	struIP;			// �����ı�ȡ���豸IP��ַ
    WORD	wPort;			// �����ı�ȡ���豸�˿ں�
    WORD	wChannel;		// �����ı�ȡ���豸ͨ����
    BYTE	byRes2[20];			// �����ֽ�
}NET_DVR_ENCODE_JOINT_PARAM, *LPNET_DVR_ENCODE_JOINT_PARAM;	


NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetEncodeJoint(LONG lUserID, LONG lChannel, LPNET_DVR_ENCODE_JOINT_PARAM lpEncodeJoint);

typedef struct tagNET_DVR_VCA_CHAN_WORKSTATUS
{
    BYTE	byJointed;				// 0-û�й���  1-�Ѿ�����
    BYTE	byRes1[3];
    NET_DVR_IPADDR	struIP;					// ������ȡ���豸IP��ַ
    WORD	wPort;					// ������ȡ���豸�˿ں�
    WORD	wChannel;				// ������ȡ���豸ͨ����
    BYTE	byVcaChanStatus;		// 0 - δ���� 1 - ����
    BYTE	byRes2[19];				// �����ֽ�
}NET_DVR_VCA_CHAN_WORKSTATUS, *LPNET_DVR_VCA_CHAN_WORKSTATUS;

typedef struct tagNET_DVR_VCA_DEV_WORKSTATUS
{
    DWORD	dwSize;			// �ṹ���С
    BYTE	byDeviceStatus;	// �豸��״̬0 - �������� 1- ����������
    BYTE	byCpuLoad;		// CPUʹ����0-100 �ֱ����ʹ�ðٷ���
    NET_DVR_VCA_CHAN_WORKSTATUS struVcaChanStatus[MAX_VCA_CHAN];
    DWORD	byRes[40];		// �����ֽ�
}NET_DVR_VCA_DEV_WORKSTATUS, *LPNET_DVR_VCA_DEV_WORKSTATUS;

NET_DVR_API BOOL __stdcall NET_DVR_GetVcaDevWorkState(LONG lUserID, LPNET_DVR_VCA_DEV_WORKSTATUS lpWorkState);

#endif //




















