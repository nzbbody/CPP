/*******************************************************************************************
* Copyright (c) 2013, 浙江大华系统工程有限公司
* All rights reserved.
*
* 文件名称：ibpXMLMacro.h
*
* 类名： 
*
* 功能描述：XML解析实现宏定义模块
*
* 摘要：XML解析宏定义模块
*
* 版本            作者                  完成日期                           修订记录
* 1.0　           13022                2013年03月04日                      创建
*
*
*
*******************************************************************************************/
#ifndef  IBP_XML_MACRO_H
#define  IBP_XML_MACRO_H


/***************************XML宏定义******************************************************/
#define CGI_MAGIC_TYPE			"application/x-httpd-cgi"
#define INCLUDES_MAGIC_TYPE		"text/x-server-parsed-html"
#define INCLUDES_MAGIC_TYPE3	"text/x-server-parsed-html3"
#define MAP_FILE_MAGIC_TYPE		"application/x-type-map"
#define ASIS_MAGIC_TYPE			"httpd/send-as-is"
#define DIR_MAGIC_TYPE			"httpd/unix-directory"
#define STATUS_MAGIC_TYPE		"application/x-httpd-status"
#define	URLENCODED_MATIC_TYPE	"application/x-www-form-urlencoded"

#define CONTENT_TYPE_XML		1
#define CONTENT_TYPE_SDP		2
#define CONTENT_TYPE_HTTP		3
#define CONTENT_TYPE_HTML		4
#define CONTENT_TYPE_OCTET		5
#define STR_CONTENT_TYPE_XML	"text/xml"
#define STR_CONTENT_TYPE_SDP	"application/sdp"
#define STR_CONTENT_TYPE_HTTP	"application/http"
#define STR_CONTENT_TYPE_HTML	"text/html"
#define STR_CONTENT_TYPE_OCTET	"application/octet-stream"

#define STR_CONTENT_TYPE		"Content-Type"
#define STR_USER_AGENT			"User-Agent"
#define STR_HOST				"Host"
#define STR_X_CLIENT_ADDRESS	"X-Client-Address"
#define STR_X_TRANSACTION_ID	"X-Transaction-ID"
#define STR_CONTENT_LENGTH		"Content-Length"

#define STR_ACCEPT				"Accept"

#define STR_VIA					"Via"
#define STR_DATE				"Date"
#define STR_SERVER				"Server"
#define STR_SET_COOKIE			"Set-Cookie"
#define STR_COOKIE				"Cookie"

#define STR_FROM				"From"
#define STR_TO					"To"
#define STR_CONTACT				"Contact"

#define STR_CSEQ				"CSeq"
#define STR_CALLID				"Call-ID"
#define STR_MAX_FORWARDS		"Max-Forwards"

#define STR_SIP_VERSION			"SIP/2.0"
#define STR_HTTP_VERSION		"HTTP/1.1"
#define STR_RTSP_VERSION		"RTSP/1.0"

#define STR_ACCEPT_ENCODING		"Accept-Encoding"
#define STR_ACCEPT_LANGUAGE		"Accept-Language"
#define STR_ALLOW				"Allow"
#define STR_ALLOW_VALUE         "INVITE, ACK, CANCEL, OPTIONS, BYE, REFER, NOTIFY, MESSAGE, SUBSCRIBE, INFO"
#define STR_BANDWIDTH			"Bandwidth"
#define	STR_BLOCKSIZE			"Blocksize"
#define STR_CONFERENCE			"Conference"
#define STR_CONNECTION			"Connection"
#define STR_CONTENT_BASE		"Content-Base"
#define STR_CONTENT_ENCODING	"Content-Encoding"
#define STR_CONTENT_LANGUAGE	"Content-Language"

#define STR_RANGE				"Range"
#define STR_RTP_INFO			"RTP-Info"
#define STR_SCALE				"Scale"
#define STR_SPEED				"Speed"
#define STR_SESSION				"Session"
#define STR_TIMESTAMP			"Timestamp"
#define STR_TRANSPORT			"Transport"
#define STR_WWW_AUTHENTICATE	"WWW-Authenticate"
#define STR_LAST_MODIFIED		"Last-Modified"
#define STR_EXPIRES				"Expires"
#define STR_VARY				"Vary"
#define STR_UNSUPPORT			"Unsupported"

#define STR_CACHE_CONTROL_X          "Cache-Control"
#define STR_ACCEPT_RETRANSMIT_X      "x-Accept-Retransmit"
#define STR_ACCEPT_DYNAMIC_RATE_X    "x-Accept-Dynamic-Rate"
#define STR_DYNAMIC_RATE_X           "x-Dynamic-Rate"

#define STR_RTSP_PUBLIC				 "Public"
#define STR_RTSP_TOKEN				 "Token"

/*******************************枚举量定义*************************************************************/

typedef enum
{
	eIbpOptType_Invalidate,
	eIbpOptType_Add,
	eIbpOptType_Modify,
	eIbpOptType_Delete
}enumIbpOptType;

typedef enum
{
	ePTZCmd_Unknown,
	ePTZCmd_Up,                     /*向上*/ 
	ePTZCmd_Down,                   /*向下*/ 
	ePTZCmd_Left,		            /*向左*/ 
	ePTZCmd_Right,		            /*向右*/
	ePTZCmd_LeftUp,                 /*左上*/ 
	ePTZCmd_RightUp,                /*右上*/ 
	ePTZCmd_LeftDown,               /*左下*/ 
	ePTZCmd_RightDown,              /*右下*/ 
	ePTZCmd_GotoPreset,             /*转到预置点*/ 
	ePTZCmd_SetPreset,              /*设置预置点*/
	ePTZCmd_ClearPreset,            /*清除预置点*/
	ePTZCmd_QuickOrient,            /*三维快速定位*/ 
	ePTZCmd_Zoom_Tele,              /*焦距拉进*/ 
	ePTZCmd_Zoom_Wide,              /*焦距拉远*/ 
	ePTZCmd_Focus_Near,             /*焦点调进*/ 
	ePTZCmd_Focus_Far,              /*焦点调远*/ 
	ePTZCmd_Iris_Auto,              /*光圈自动调整*/ 
	ePTZCmd_Iris_Large,             /*光圈增大*/ 
	ePTZCmd_Iris_Small,             /*光圈缩小*/ 
	ePTZCmd_Aux_On,                 /*擦拭启动*/ 
	ePTZCmd_Aux_Off,                /*擦拭停止*/ 
	ePTZCmd_Light_On ,              /*灯光控制器开启*/ 
	ePTZCmd_Light_Off,              /*灯光控制器关闭*/ 
	ePTZCmd_StartTour,              /*开始自动巡航*/ 
	ePTZCmd_StopTour,               /*停止自动巡航*/ 
	ePTZCmd_AutoPan_On,             /*水平巡航启动*/ 
	ePTZCmd_AutoPan_Off,            /*水平巡航停止*/   
	ePTZCmd_Menu_Open,              /*打开菜单*/
	ePTZCmd_Menu_Close,             /*关闭菜单*/
	ePTZCmd_Menu_Ok,                /*菜单操作确定*/
	ePTZCmd_Menu_Cancel,            /*菜单操作取消*/
	ePTZCmd_Menu_Up,                /*菜单操作向上*/
	ePTZCmd_Menu_Down,              /*菜单操作向下*/
	ePTZCmd_Menu_Left,              /*菜单操作向左*/
	ePTZCmd_Menu_Right,             /*菜单操作向右*/
	ePTZCmd_Brush_On,               /*灯光雨刷开启*/
	ePTZCmd_Brush_Off,              /*灯光雨刷关闭*/
	ePTZCmd_Matrix,                 /*矩阵上墙*/
	ePTZCmd_IOControl,				/*IO状态控制*/
	ePTZCmd_LockPtz,				/*云台加解锁控制*/

}enumPTZCmd;

/***************************宏定义*******************************************************************/
typedef enum
{
	//100 - 199  本类状态码表示客户端应该继续它的请求响应码
	eSipStatus_Continue = 100,
	eSipStatus_Switching_Protocols,
	eSipStatus_Ringing = 180,
	eSipStatus_CallBeing_Forwarded,
	eSipStatus_Queued,
	eSipStatus_Session_Progress,

	//200 - 299  本类状态码表示客户端的请求成功被接收、理解、接受状态的响应码
	eSipStatus_Ok = 200,
	eSipStatus_Created,
	eSipStatus_Accepted,
	eSipStatus_NonAuthoritative_Infomation,
	eSipStatus_No_Content,
	eSipStatus_Reset_Content,
	eSipStatus_Partial_Content,

	//300 - 399  本类状态码表示需要用户代理采取更进一步的行为来完成请求，重定向服务请求动作响应码
	eSipStatus_Multiple_Choices = 300,
	eSipStatus_Moved_Permanently,
	eSipStatus_Found,
	eSipStatus_See_Other,
	eSipStatus_NotModified,
	eSipStatus_Use_Proxy,
	eSipStatus_Unused,
	eSipStatus_Temporary_Redirect,
	eSipStatus_Alternative_Service = 380,

	//400 - 499  本类状态码表示由于畸形的语法导致服务器无法理解的请求响应码
	eSipStatus_BadRequest = 400,
	eSipStatus_Unauthorized,
	eSipStatus_Payment_Required,
	eSipStatus_Forbidden,
	eSipStatus_NotFound = 404,
	eSipStatus_Method_NotAllowed,
	eSipStatus_NotAcceptable,
	eSipStatus_Proxy_Authentication_Required,
	eSipStatus_Request_TimeOut = 408,
	eSipStatus_Conflict,
	eSipStatus_Gone,
	eSipStatus_Length_Required,
	eSipStatus_Precondition_Failed,
	eSipStatus_Request_Entity_TooLarge,
	eSipStatus_Request_URI_TooLong,
	eSipStatus_Unsupported_Media_Type,
	eSipStatus_Unsupported_URI_Scheme,
	eSipStatus_Bad_Extension,
	eSipStatus_Extension_Required,
	eSipStatus_Interval_Too_Brief,
	eSipStatus_Temporarily_Unavailable = 480,
	eSipStatus_Transaction_NotExist,
	eSipStatus_Loop_Detected,
	eSipStatus_TooMany_Hops,
	eSipStatus_Address_InComplete,
	eSipStatus_Ambiguous,
	eSipStatus_Busy_Here,
	eSipStatus_Request_Terminated,
	eSipStatus_Not_Acceptable_Here,
	eSipStatus_Request_Pending = 491,
	eSipStatus_Undecipherable = 493,
	//eSipStatus_Requested_Range_NotSatisfiable,
	//eSipStatus_Expectation_Failed,

	//500 - 599  本类状态码表示服务器已经明显处于错误的状况下或者无能力执行请求操作响应码
	eSipStatus_Internal_Server_Error = 500,
	eSipStatus_Not_Implemented,
	eSipStatus_Bad_Gateway,
	eSipStatus_Service_Unavailable,
	eSipStatus_Gateway_Timeout,
	eSipStatus_Http_Version_NotSupported,
	eSipStatus_Variant_Also_Varies,
	eSipStatus_Message_Too_Large,

	//600-699 服务器给特定用户有一个最终信息，并不只是在Requets-URI的特定实例有最终信息
	eSipStatus_Final_Busy_EveryWhere = 600,
	eSipStatus_Final_Decline = 603,
	eSipStatus_Final_NotExist_Anywhere = 604,
	eSipStatus_Final_Not_Acceptable = 606


}enumSipStatus;

typedef enum
{
	eDhcpErrorCode_OK = 0,
	eDhcpErrorCode_Unreachable,
	eDhcpErrorCode_Parameter_Error
}dhcpErrorCode;
/**************************************************************************************
PS流码流文本结构基本说明   
I Frame    PS_Header | PS_Map | PES |.......|PES
P Frame    PS_Header | PES | .......|PES
Audio Frame   PS_Header | (PS_Map) | PES  (音频为统一格式，封装在一个PES里面即可)
**************************************************************************************/
typedef enum 
{
	eMMedia_Audio_PCM = 1,
	eMMedia_Audio_ADPCM,
	eMMedia_Audio_G711,
	eMMedia_Audio_G711u,
	eMMedia_Audio_G711a,
	eMMedia_Audio_G721,
	eMMedia_Audio_G722,
	eMMedia_Audio_G723,
	eMMedia_Audio_G723_1,
	eMMedia_Audio_G726,
	eMMedia_Audio_G728,
	eMMedia_Audio_G729,
	eMMedia_Audio_G729A,
	eMMedia_Audio_GIPS,
	eMMedia_Audio_APT_X,
	eMMedia_Audio_LPC,
	eMMedia_Audio_CELP,
	eMMedia_Audio_ACELP,
	eMMedia_Audio_QCELP,
	eMMedia_Audio_NICAM,
	eMMedia_Audio_MPEG_1,
	eMMedia_Audio_MUSICAM,
	eMMedia_Audio_MP3,
	eMMedia_Audio_MPEG_2,
	eMMedia_Audio_WMA,
	eMMedia_Audio_AAC,
	eMMedia_Audio_AC_3,
	eMMedia_Audio_ASPEC,
	eMMedia_Audio_PAC,
	eMMedia_Audio_HR,
	eMMedia_Audio_FR,
	eMMedia_Audio_EFR,
	eMMedia_Audio_AMR,
	eMMedia_Audio_GSM_AMR,
	eMMedia_Audio_EVRC,

	eMMedia_Video_JPEG = 100,
	eMMedia_Video_MJPEG,
	eMMedia_Video_H261,
	eMMedia_Video_H263,
	eMMedia_Video_H264,
	eMMedia_Video_MPEG1,
	eMMedia_Video_MPEG2,
	eMMedia_Video_MPEG4,
	eMMedia_Video_MPEG21,

}enumMultiMedia;

#define   IBP_TYPE_NAME_LEN        64
#define   NETWORK_BUF_MAXLENGTH    16*1024*1024
#define   ALARMPLAN_XML_MAXLENGTH  4000

/***************************单元名称*******************************************************************/
const char IBP_STR_TYPES[][IBP_TYPE_NAME_LEN] = 
{
	"Unknown",
	"CMU",
	"DMU",
	"VTDU",
	"VRU",
	"CLIENT",
	"UAC",
	"LKU",
	"IMS",
	"IIS",
	"IMDS",
	"MCU"
};

const char IBP_STR_PROTYPE[][IBP_TYPE_NAME_LEN] = 
{
	"Unknown",
	"Request",
	"Response",
	"Notify"
};

const char IBP_STR_OPT_TYPES[][IBP_TYPE_NAME_LEN] = 
{
	"Unknown",
	"Add",
	"Modify",
	"Delete"
};

const char IBP_STR_PTZ_CMDS[][IBP_TYPE_NAME_LEN] = 
{
	"Unknown",                /*未知*/
	"Up",                     /*向上*/ 
	"Down",                   /*向下*/ 
	"Left",		              /*向左*/ 
	"Right",		          /*向右*/
	"LeftUp",                 /*左上*/ 
	"RightUp",                /*右上*/ 
	"LeftDown",               /*左下*/ 
	"RightDown",              /*右下*/ 
	"GotoPreset",             /*转到预置点*/ 
	"SetPreset",              /*设置预置点*/
	"ClearPreset",            /*清除预置点*/
	"QuickOrient",            /*三维快速定位*/ 
	"Zoom_Tele",              /*焦距拉进*/ 
	"Zoom_Wide",              /*焦距拉远*/ 
	"Focus_Near",             /*焦点调进*/ 
	"Focus_Far",              /*焦点调远*/ 
	"Iris_Auto",              /*光圈自动调整*/ 
	"Iris_Large",             /*光圈增大*/ 
	"Iris_Small",             /*光圈缩小*/ 
	"Aux_On",                 /*擦拭启动*/ 
	"Aux_Off",                /*擦拭停止*/ 
	"Light_On",               /*灯光开启*/ 
	"Light_Off",              /*灯光关闭*/ 
	"StartTour",              /*开始自动巡航*/ 
	"StopTour",               /*停止自动巡航*/ 
	"AutoPan_On",             /*水平巡航启动*/ 
	"AutoPan_Off",            /*水平巡航停止*/
	"Menu_Open",              /*打开菜单*/
	"Menu_Close",             /*关闭菜单*/
	"Menu_Ok",                /*菜单操作确定*/
	"Menu_Cancel",            /*菜单操作取消*/
	"Menu_Up",                /*菜单操作向上*/
	"Menu_Down",              /*菜单操作向下*/
	"Menu_Left",              /*菜单操作向左*/
	"Menu_Right",             /*菜单操作向右*/
	"Brush_On",               /*灯光雨刷开启*/
	"Brush_Off",              /*灯光雨刷关闭*/
	"Matrix",                 /*矩阵上墙*/
	"IOControl",			  /*IO状态控制*/
	"LockPtz",				  /*云台加解锁控制*/

};

/***************************字段名称定义***************************************************************/
//版本字段定义
#define IBP_PROTO_VERSION				"1.0.0.0"
#define	IBP_XML_VERSION					"1.0"

//XML头字段定义
#define IBP_XML_BODY					"body"
#define IBP_TAG_HEADWORD				"IBPProtocol"
#define IBP_TAG_ROOT					"root"
#define IBP_TAG_VERSION					"version"          
#define IBP_TAG_UNIT					"unit"
#define IBP_TAG_TYPE					"type"
#define IBP_TAG_ID						"id"  
#define IBP_TAG_CMD						"cmd"
#define IBP_TAG_SESSION					"session"
#define IBP_TAG_SEQUENCE				"sequence"
#define IBP_TAG_TAKE_LEN				"takelen"
#define IBP_TAG_BODY_LEN				"bodylen"
#define IBP_TAG_SEQ_ID                  "seqid"

//常用字段定义
#define	IBP_TAG_ORG						"org"
#define	IBP_TAG_ORGNAME					"orgname"
#define IBP_TAG_DEVICE					"device"
#define IBP_TAG_CHANNEL					"channel"
#define	IBP_TAG_ORGID					"orgid"
#define	IBP_TAG_DOMNAME					"domname"
#define	IBP_TAG_SRCDOMID				"srcdomid"
#define	IBP_TAG_DOMID					"domid"
#define	IBP_TAG_LOCALDOM				"localdom"
#define	IBP_TAG_PREDOM					"predom"
#define	IBP_TAG_NEXTDOM					"nextdom"
#define	IBP_TAG_ORGCODE					"orgcode"
#define	IBP_TAG_OLDDOMID				"olddomid"
#define	IBP_TAG_OLDORGCODE				"oldorgcode"
#define	IBP_TAG_OLDDEVCODE				"olddevcode"
#define	IBP_TAG_PARENTORGID				"parentorgid"
#define	IBP_TAG_PARENTDOMID				"parentdomid"
#define	IBP_TAG_PARENTORGCODE			"parentorgcode"
#define	IBP_TAG_PARENTDEVCODE			"parentdevcode"
#define	IBP_TAG_ORGDOMID				"orgdomid"
#define	IBP_TAG_ORGPATH					"orgpath"
#define	IBP_TAG_ORGPOSIDX				"orgposidx"
#define	IBP_TAG_TITLE					"title"
#define	IBP_TAG_UPDATETIME				"updatetime"
#define	IBP_TAG_DESC					"desc"
#define	IBP_TAG_DEVID					"devid"
#define	IBP_TAG_DEVCODE					"devcode"
#define	IBP_TAG_PARENTDEVID				"parentdevid"
#define	IBP_TAG_DEVPATH					"devpath"
#define	IBP_TAG_DEVTYPE					"devtype"
#define IBP_TAG_DEVTYPENAME				"devtypename"
#define	IBP_TAG_MANUF					"manuf"
#define	IBP_TAG_MANUFID					"manufid"
#define	IBP_TAG_MANUFTYPE				"manuftype"
#define	IBP_TAG_STATUS					"status"
#define	IBP_TAG_DEVPOSIDX				"devposidx"
#define IBP_TAG_LOGINNAME				"loginname"
#define IBP_TAG_LOGINPWD				"loginpwd"
#define IBP_TAG_IPADDR					"ipaddr"
#define IBP_TAG_PORTDEV					"portdev"
#define IBP_TAG_STREAMTYPE				"streamtype"
#define IBP_TAG_CHNIDX					"chnidx"
#define IBP_TAG_CHNCODE					"chncode"
#define IBP_TAG_ACCESORY				"accesory"
#define IBP_TAG_CONTRATOR				"contrator"
#define IBP_TAG_LOCATION				"location"
#define IBP_TAG_LOCATIONID				"locationid"
#define IBP_TAG_INSTALLSPOT				"installspot"
#define IBP_TAG_INSTALLTIME				"installtime"
#define IBP_TAG_MAINTAINER				"maintainer"
#define IBP_TAG_PHONE					"phone"
#define IBP_TAG_MODEL					"model"
#define IBP_TAG_VISIBLE					"visible"
#define IBP_TAG_LONGITUDE				"longitude"
#define IBP_TAG_LATITUDE				"latitude"
#define IBP_TAG_MODULENAME				"modulename"
#define IBP_TAG_IPINFO					"ipinfo"
#define IBP_TAG_IP						"ip"
#define IBP_TAG_PORT					"port"
#define IBP_TAG_MYSVRID					"mysvrid"
#define IBP_TAG_YOURSVRID				"yoursvrid"
#define IBP_TAG_SVRID					"svrid"
#define IBP_TAG_FLAG					"flag"
#define IBP_TAG_USER					"user"
#define IBP_TAG_USERTYPE				"usertype"
#define IBP_TAG_USERID					"userid"
#define IBP_TAG_USERNAME				"username"
#define IBP_TAG_PWD						"pwd"
#define IBP_TAG_OLDPWD					"oldpwd"
#define IBP_TAG_NEWPWD					"newpwd"
#define IBP_TAG_MAC						"mac"
#define IBP_TAG_ISSDKALARM				"issdkalarm"
#define IBP_TAG_MEDIANUM				"medianum"
#define IBP_TAG_OPT						"opt"
#define IBP_TAG_OPERATE					"operate"
#define IBP_TAG_OPERATENAME				"operatename"
#define IBP_TAG_ITEM					"item"
#define IBP_TAG_TAKECODE				"takecode"
#define IBP_TAG_TAKECODENAME			"takecodename"
#define IBP_TAG_PARAM					"param"
#define IBP_TAG_INTPARAM1				"intparam1"
#define IBP_TAG_INTPARAM2				"intparam2"
#define IBP_TAG_INTPARAM3				"intparam3"
#define IBP_TAG_INTPARAM4				"intparam4"
#define IBP_TAG_INTPARAM5				"intparam5"
#define IBP_TAG_INTPARAM6				"intparam6"
#define IBP_TAG_INTPARAM7				"intparam7"
#define IBP_TAG_INTPARAM8				"intparam8"
#define IBP_TAG_UINTPARAM1				"uintparam1"
#define IBP_TAG_UINTPARAM2				"uintparam2"
#define IBP_TAG_UINTPARAM3				"uintparam3"
#define IBP_TAG_STRPARAM1				"strparam1"
#define IBP_TAG_STRPARAM2				"strparam2"
#define IBP_TAG_STRPARAM3				"strparam3"
#define IBP_TAG_STRDATA					"strdata"
#define IBP_TAG_INTDATA					"intdata"
#define IBP_TAG_TREEID					"treeid"
#define IBP_TAG_CREATORID				"creatorid"
#define IBP_TAG_TELEPHONE				"telephone"
#define IBP_TAG_BEGINDATE				"begindate"
#define	IBP_TAG_ENDDATE					"enddate"
#define IBP_TAG_LOCKSTATUS				"lockstatus"
#define IBP_TAG_EMAIL					"email"
#define IBP_TAG_ACCNUM					"accnum"
#define IBP_TAG_ADAPNUM					"adapnum"
#define IBP_TAG_TIME					"time"
#define IBP_TAG_DEVNAME					"devname"
#define IBP_TAG_ROLE					"role"
#define IBP_TAG_ROLEID					"roleid"
#define IBP_TAG_RIGHT					"right"
#define IBP_TAG_RIGHTID					"rightid"
#define IBP_TAG_FUNC					"func"
#define IBP_TAG_FUNCID					"funcid"
#define IBP_TAG_DSTFUNCID				"dstfuncid"
#define IBP_TAG_SRCFUNCID				"srcfuncid"
#define IBP_TAG_FUNCTYPE				"functype"
#define IBP_TAG_RIGHTBITS				"rightbits"
#define IBP_TAG_LEVEL					"level"
#define IBP_TAG_STARTTIME				"starttime"
#define IBP_TAG_ENDTIME					"endtime"
#define IBP_TAG_VIDEOTYPE				"videotype"
#define IBP_TAG_SUBSTREAM				"substream"
#define IBP_TAG_TOKEN					"token"
#define IBP_TAG_BANDWIDTH				"bandwidth"
#define IBP_TAG_CPU						"cpu"
#define IBP_TAG_MEMORY					"memory"
#define IBP_TAG_DLLNAME					"dllname"
#define IBP_TAG_PARENTCODE				"parentcode"
#define IBP_TAG_PARENTID				"parentid"
#define IBP_TAG_CHNNAME					"chnname"
#define IBP_TAG_CHNTYPE					"chntype"
#define IBP_TAG_SLAVESVRID				"slavesvrid"
#define IBP_TAG_SLAVEDOMID				"slavedomid"
#define IBP_TAG_SESSIONID				"sessionid"
#define IBP_TAG_PLAYVIDEOTYPE			"playvideotype"
#define IBP_TAG_RATE					"rate"
#define IBP_TAG_TRANSPROTO				"transproto"
#define IBP_TAG_RTSPURL					"rtspurl"
#define IBP_TAG_EXTRADATA				"extradata"
#define IBP_TAG_PLAYTYPE				"playtype"
#define IBP_TAG_SOURCETYPE				"sourcetype"
#define IBP_TAG_FILENAME				"filename"
#define IBP_TAG_VRUID					"vruid"
#define IBP_TAG_DISKID					"diskid"
#define IBP_TAG_FILEHANDLE				"filehandle"
#define IBP_TAG_STREAMPORTFROM			"streamportfrom"
#define IBP_TAG_STREAMPACKTYPE			"streampacktype"
#define IBP_TAG_COUNT					"count"
#define IBP_TAG_POINTX					"pointx"
#define IBP_TAG_POINTY					"pointy"
#define IBP_TAG_WIDTH					"width"
#define IBP_TAG_LENGTH					"length"
#define IBP_TAG_RGB						"rgb"
#define IBP_TAG_ALPHA					"alpha"
#define IBP_TAG_CLIENTID				"clientid"
#define IBP_TAG_STOP					"stop"
#define IBP_TAG_CLIENTNAME				"clientname"
#define IBP_TAG_CLIENTLEVEL				"clientlevel"
#define IBP_TAG_DEPARTMENT				"department"
#define IBP_TAG_INTERVAL				"interval"
#define IBP_TAG_PLANID					"planid"
#define IBP_TAG_TEMPLATEID				"templateid"
#define IBP_TAG_TIMETEMPLATEID			"timetemplateid"
#define IBP_TAG_PLANNAME				"planname"
#define IBP_TAG_VOICEENABLE				"voiceenable"
#define IBP_TAG_RECORDTYPE				"recordtype"
#define IBP_TAG_ALARMTIME				"alarmtime"
#define IBP_TAG_EVENTTIME				"eventtime"
#define IBP_TAG_INFO					"info"
#define IBP_TAG_MSGTXT					"msgtxt"
#define IBP_TAG_LABEL					"label"
#define IBP_TAG_SCSOP					"scsop"
#define IBP_TAG_SCSPRAM					"scspram"
#define IBP_TAG_INDEX					"index"
#define IBP_TAG_NAME					"name"
#define IBP_TAG_SCSID					"scsid"
#define IBP_TAG_CHNNUM					"chnnum"
#define IBP_TAG_ALARMINPUT				"alarminput"
#define IBP_TAG_ALARMOUTPUT				"alarmoutput"
#define IBP_TAG_TALKCHNNUM				"talkchnnum"
#define IBP_TAG_ISUSEDNS				"isusedns"
#define IBP_TAG_ISOPEN					"isopen"
#define IBP_TAG_CARDINFO				"cardinfo"
#define IBP_TAG_REVERED					"revered"
#define IBP_TAG_SVRURL					"svrurl"
#define IBP_TAG_SVRURLFLAG				"svrurlflag"
#define IBP_TAG_TOPACKTYPE				"topacktype"
#define IBP_TAG_FAST					"fast"
#define IBP_TAG_SUBDEVCODE				"subdevcode"
#define IBP_TAG_SUBTYPE					"subtype"
#define IBP_TAG_VAL						"val"
#define IBP_TAG_ISALARM					"isalarm"
#define IBP_TAG_ENABLE					"enable"
#define IBP_TAG_CODE					"code"
#define IBP_TAG_STRITEM					"stritem"
#define IBP_TAG_INTITEM					"intitem"
#define IBP_TAG_LOCKTIME				"locktime"
#define IBP_TAG_HANDLE					"handle"
#define	IBP_TAG_DOMDEVCODE				"domdevcode"
#define	IBP_TAG_SIZE					"size"
#define	IBP_TAG_CURPAGE					"curpage"
#define	IBP_TAG_TOTAL					"total"
#define	IBP_TAG_END						"end"
#define	IBP_TAG_NUM						"num"
#define	IBP_TAG_RES						"res"
#define	IBP_TAG_RESID					"resid"
#define	IBP_TAG_RESTYPE					"restype"
#define	IBP_TAG_RESNAME					"resname"
#define	IBP_TAG_LUASHELL				"luashell"
#define	IBP_TAG_LUACONTENT				"luacontent"
#define	IBP_TAG_TYPEID					"typeid"
#define	IBP_TAG_TYPENAME				"typename"
#define	IBP_TAG_CHARVALUE				"charvalue"
#define	IBP_TAG_NUMVALUE				"numvalue"
#define	IBP_TAG_OTHERDOMID				"otherdomid"
#define	IBP_TAG_SENDALL					"sendall"
#define	IBP_TAG_CLIENTTYPE				"clienttype"
#define	IBP_TAG_PATH					"path"
#define	IBP_TAG_SMALLICON				"smallicon"
#define	IBP_TAG_BIGICON					"bigicon"
#define	IBP_TAG_REMARK					"remark"
#define	IBP_TAG_DEVINDEX				"devindex"
#define	IBP_TAG_AUTODISAPPEAR			"autodisappear"
#define IBP_TAG_CATEGORY				"category"
#define	IBP_TAG_SECOND					"second"
#define	IBP_TAG_CONFIRMOR				"confirmor"
#define	IBP_TAG_CONFIRMTIME				"confirmtime"
#define	IBP_TAG_CONFIRMMSG				"confirmmsg"
#define	IBP_TAG_CONFIRMSTATUS			"confirmstatus"
#define IBP_TAG_HALFSEL					"halfsel"
#define IBP_TAG_CHECKALL				"checkall"
#define IBP_TAG_STREAMID				"streamid"
#define IBP_TAG_ALL						"all"
#define IBP_TAG_FREE					"free"
#define IBP_TAG_LINK					"link"
#define	IBP_TAG_PERCENT					"percent"
#define IBP_TAG_WAY						"way"
#define IBP_TAG_MONDAY					"monday"
#define IBP_TAG_TUESDAY					"tuesday"
#define IBP_TAG_WEDNESDAY				"wednesday"
#define IBP_TAG_THURSDAY				"thursday"
#define IBP_TAG_FRIDAY					"friday"
#define IBP_TAG_SATURDAY				"saturday"
#define IBP_TAG_SUNDAY					"sunday"
#define IBP_TAG_ATTR					"attr"
#define	IBP_TAG_SRCID					"srcid"
#define	IBP_TAG_AREACODE				"areacode"
#define	IBP_TAG_AREATYPE				"areatype"
#define IBP_TAG_MULTI					"multi"
#define IBP_TAG_SLAVEDEVCODE			"slavedevcode"
#define IBP_TAG_MEETID					"meetid"
#define IBP_TAG_CAMERAID				"cameraid"
#define IBP_TAG_THEME					"theme"
#define IBP_TAG_CREATORNAME				"creatorname"
#define	IBP_TAG_NOTIFYCODE				"notifycode"
#define	IBP_TAG_NOTIFYNAME				"notifyname"
#define	IBP_TAG_TASK					"task"
#define	IBP_TAG_TASKID					"taskid"
#define	IBP_TAG_TASKNAME				"taskname"
#define	IBP_TAG_TASKTYPE				"tasktype"
#define	IBP_TAG_WNDNUM					"wndnum"
#define	IBP_TAG_TIMESPAN				"timespan"
#define	IBP_TAG_PREPOINT				"prepoint"
#define	IBP_TAG_CFG						"cfg"
#define	IBP_TAG_CREATORTIME				"creatortime"
#define	IBP_TAG_OUTOFTIME				"outoftime"
#define	IBP_TAG_MAINID					"mainid"
#define	IBP_TAG_SUBID					"subid"
#define	IBP_TAG_GUID					"guid"
#define	IBP_TAG_UPLOADER				"uploader"
#define	IBP_TAG_TIMESCHEDID				"timeschedid"
#define	IBP_TAG_ACT						"act"
#define	IBP_TAG_ACTID					"actid"
#define	IBP_TAG_FILESIZE				"filesize"
#define IBP_TAG_EXTEND					"extend"
#define IBP_TAG_VIDEO					"video"
#define IBP_TAG_EXECTYPE				"exectype"
#define IBP_TAG_CANERR					"canerr"
#define IBP_TAG_POINTS                  "points"
#define IBP_TAG_POINT                   "point"
#define IBP_TAG_RPUDOMID				"rpudomid"
#define IBP_TAG_RPUCODE					"rpucode"
#define IBP_TAG_LOGTIME					"logtime"
#define IBP_TAG_CYCLE					"cycle"
#define	IBP_TAG_PAGE					"page"
#define IBP_TAG_ROOMID					"roomid"
#define IBP_TAG_MODULEID				"moduleid"
#define IBP_TAG_CALLER					"caller"
#define IBP_TAG_CALLEE					"callee"
#define IBP_TAG_SESSTYPE				"sesstype"
#define IBP_TAG_DEVLINKTYPE				"devlinktype"
#define IBP_TAG_ISMASTER				"ismaster"
#define IBP_TAG_TARGETCODE				"targetcode"
#define IBP_TAG_STAYTIME				"staytime"
#define IBP_TAG_ACTION					"action"
#define IBP_TAG_PLAN					"plan"
#define IBP_TAG_CONFIG					"config"
#define IBP_TAG_TIMETEMPLATE			"timetemplate"

//错误码字段定义
#define IBP_TAG_ERRMSG					"errmsg"
#define IBP_TAG_ERRCODE					"errcode"


//DHCP协议字段定义
#define IBP_TAG_DHCPPRO_NAME            "dhtp"
#define IBP_TAG_DHCPPRO_VERSION         10
#define IBP_TAG_LOAD_CODE				"code"
#define IBP_TAG_LOAD_LENGTH				"len"
//XML头定义
#define XML_HEAD						"xml version='1.0' encoding='utf-8'"
#define XML_HEAD_RAPID					"<?xml version='1.0' encoding='utf-8' ?>"
#define XML_HEAD_EX						"xml version='1.0' encoding='utf-8' standalone='no'"
#define XML_HEAD_RAPID_EX				"<?xml version='1.0' encoding='utf-8' standalone='no' ?>"
#define XML_HEAD_RAPID_EXT				"<?xml version='1.0' encoding='utf-8' standalone='no'?>"
#define XML_HEAD_RAPID_EXX				"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"

/******************************************************************************************************
** Session Description Protocol 
******************************************************************************************************/
#define IBP_SDP_BODY_V()  \
	sprintf(sSrc.c_str(), "v=0\r\n");

#define IBP_SDP_BODY_O()  \
	time_t t = time(0); memset(m_cTmp, 0, sizeof(m_cTmp)); GWHTTP_URL_PACKET_U64_NO_SEPARATOR(m_cTmp, t);\
	strcat(sSrc.c_str(), "o=- "); \
	strcat(sSrc.c_str(), sTmp); strcat(sSrc, " "); \
	strcat(sSrc.c_str(), sTmp); strcat(sSrc, " IN IP4 "); \
	strcat(sSrc, m_strOIp);\
	strcat(sSrc, "\r\n");

#define IBP_SDP_BODY_S()  \
	strcat(_xmlString, "s=-"); \
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_I()  \
	strcat(_xmlString, "i=SIP Call"); \
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_C()  \
	strcat(_xmlString, "c=IN IP4 "); \
	strcat(_xmlString, m_strCIp);\
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_T()  \
	strcat(_xmlString, "t=0 0"); \
	strcat(_xmlString,"\r\n");

#define IBP_SDP_BODY_VIDEO_M()  \
	strcat(_xmlString, "m=video ");\
	memset(m_cTmp, 0, sizeof(m_cTmp));AX_OS::itoa(m_nMVideoPort, m_cTmp, 10);strcat(_xmlString, m_cTmp);\
	strcat(_xmlString, " RTP/AVP ");\
	memset(m_cTmp, 0, sizeof(m_cTmp));AX_OS::itoa(m_nMVideoCodingFormat, m_cTmp,10);strcat(_xmlString, m_cTmp);\
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_AUDIO_M()  \
	strcat(_xmlString, "m=audio ");\
	memset(m_cTmp, 0, sizeof(m_cTmp));AX_OS::itoa(m_nMAudioPort, m_cTmp,10);strcat(_xmlString, m_cTmp);\
	strcat(_xmlString, " RTP/AVP ");\
	memset(m_cTmp, 0, sizeof(m_cTmp));AX_OS::itoa(m_nMAudioCodingFormat, m_cTmp,10);strcat(_xmlString, m_cTmp);\
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_A_RTPMAP()  \
	strcat(_xmlString, "a=rtpmap:"); \
	strcat(_xmlString, m_strACodingFormatDetail); \
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_A_FMTP()  \
	strcat(_xmlString, "a=fmtp:"); \
	strcat(_xmlString, m_strACodingConfig); \
	strcat(_xmlString, "\r\n");

#define IBP_SDP_BODY_A(cIn)  \
	strcat(_xmlString, "a="); \
	strcat(_xmlString, cIn); \
	strcat(_xmlString, "\r\n");

/****************************************************************************************************/


//IBP协议串行化XML消息开始部分
#define   PACKET_IBP_BEGIN   \
	rapidxml::xml_document<>  xml; \
	rapidxml::xml_node<>* root = xml.allocate_node(rapidxml::node_pi, xml.allocate_string(XML_HEAD)); \
	xml.append_node(root); \
	rapidxml::xml_node<>* body = xml.allocate_node(rapidxml::node_element, IBP_TAG_HEADWORD, NULL); \
	xml.append_node(body); \
	char   tmp[512] = {0};\
	body->append_attribute(xml.allocate_attribute(IBP_TAG_VERSION, xml.allocate_string(_version.c_str()))); \
	IBPString::unitTypeToName(tmp, (enumIbpUnit)_unit); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_UNIT, xml.allocate_string(tmp))); \
	IBPString::typeIntToStr(tmp, _type);   \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_TYPE, xml.allocate_string(tmp))); \
	IBPString::cmdIntToStr(tmp, (enumIbpCmd)_cmd); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_CMD, xml.allocate_string(tmp))); \
	sprintf(tmp, "%u", _sequence); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_SEQUENCE, xml.allocate_string(tmp))); \
	sprintf(tmp, "%u", _session); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_SESSION, xml.allocate_string(tmp))); \
	if(_takeLen>0){ \
	sprintf(tmp, "%u", _takeLen); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_TAKE_LEN, xml.allocate_string(tmp)));}

//IBP协议串行化XML消息开始部分
#define   PACKET_DHCP_BEGIN   \
	rapidxml::xml_document<>  xml; \
	rapidxml::xml_node<>* root = xml.allocate_node(rapidxml::node_pi, xml.allocate_string(XML_HEAD_EX)); \
	xml.append_node(root); \
	rapidxml::xml_node<>* body = xml.allocate_node(rapidxml::node_element, IBP_TAG_ROOT, NULL); \
	xml.append_node(body); \
	char   tmp[32] = {0}; \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_VERSION, xml.allocate_string(_version.c_str()))); \
	IBPString::unitTypeToName(tmp, (enumIbpUnit)_unit); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_UNIT, xml.allocate_string(tmp))); \
	IBPString::typeIntToStr(tmp, _type);   \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_TYPE, xml.allocate_string(tmp))); \
	IBPString::cmdIntToStr(tmp, (enumIbpCmd)_cmd); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_CMD, xml.allocate_string(tmp))); \
	sprintf(tmp, "%u", _sequence); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_SEQUENCE, xml.allocate_string(tmp))); \
	sprintf(tmp, "%u", _session); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_SESSION, xml.allocate_string(tmp))); \
	if(_takeLen>0){ \
	sprintf(tmp, "%u", _takeLen); \
	body->append_attribute(xml.allocate_attribute(IBP_TAG_TAKE_LEN, xml.allocate_string(tmp)));}

//自定义XML消息开始部分
#define   XML_DEFINE_BEGIN   \
	rapidxml::xml_document<>  xml; \
	rapidxml::xml_node<>* root = xml.allocate_node(rapidxml::node_pi, xml.allocate_string(XML_HEAD_EX)); \
	xml.append_node(root); \
	rapidxml::xml_node<>* body = xml.allocate_node(rapidxml::node_element, IBP_TAG_ROOT, NULL); \
	xml.append_node(body); \
	char   tmp[512] = {0};


//IBP协议串行化一个XML节点，值是字符串
#define IBP_PACKET_XML_NODE_STR(title, var) \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(var)));

//IBP协议串行化一个XML节点，值是整型
#define IBP_PACKET_XML_NODE_INT(title, var) \
	sprintf(tmp, "%d", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是64位整型
#ifdef WIN32 
	#define IBP_PACKET_XML_NODE_INT64(title, var) \
	sprintf(tmp, "%I64d", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));
#else 
	#define IBP_PACKET_XML_NODE_INT64(title, var) \
	sprintf(tmp, "%lld", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));
#endif 

//IBP协议串行化一个XML节点，值是无符号整型
#define IBP_PACKET_XML_NODE_UINT(title, var) \
	sprintf(tmp, "%u", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是64位无符号整型
#ifdef WIN32 
#define IBP_PACKET_XML_NODE_UINT64(title, var) \
	sprintf(tmp, "%I64u", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));
#else 
#define IBP_PACKET_XML_NODE_UINT64(title, var) \
	sprintf(tmp, "%llu", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));
#endif 

//IBP协议串行化一个XML节点，值是浮点型
#define IBP_PACKET_XML_NODE_DOUBLE(title, var) \
	sprintf(tmp, "%f", var); \
	body->append_node(xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点
#define IBP_PACKET_XML_ADD_NODE(title) \
	rapidxml::xml_node<>* node = xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), NULL); \
	body->append_node(node); 


//IBP协议串行化一个XML节点，值是字符串
#define IBP_PACKET_XML_ATTR_STR(title, var) \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(var)));

//IBP协议串行化一个XML节点，值是整型
#define IBP_PACKET_XML_ATTR_INT(title, var) \
	sprintf(tmp, "%d", var); \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是无符号整型
#define IBP_PACKET_XML_ATTR_UINT(title, var) \
	sprintf(tmp, "%u", var); \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是64位整型
#ifdef WIN32 
#define IBP_PACKET_XML_ATTR_INT64(title, var) \
	sprintf(tmp, "%I64d", var); \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));
#else 
#define IBP_PACKET_XML_ATTR_INT64(title, var) \
	sprintf(tmp, "%lld", var); \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));
#endif 

//IBP协议串行化一个XML节点，值是浮点型
#define IBP_PACKET_XML_ATTR_DOUBLE(title, var) \
	sprintf(tmp, "%f", var); \
	node->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

#define IBP_PACKET_XML_ADD_ITEM(title) \
	rapidxml::xml_node<>* item = xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), NULL); \
	node->append_node(item); 

//IBP协议串行化一个XML节点，值是字符串
#define IBP_PACKET_XML_ITEM_STR(title, var) \
	item->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(var)));

//IBP协议串行化一个XML节点，值是整型
#define IBP_PACKET_XML_ITEM_INT(title, var) \
	sprintf(tmp, "%d", var); \
	item->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是无符号整型
#define IBP_PACKET_XML_ITEM_UINT(title, var) \
	sprintf(tmp, "%u", var); \
	item->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是浮点型
#define IBP_PACKET_XML_ITEM_DOUBLE(title, var) \
	sprintf(tmp, "%f", var); \
	item->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

#define IBP_PACKET_XML_ADD_OBJ(title) \
	rapidxml::xml_node<>* dvalue = xml.allocate_node(rapidxml::node_element, xml.allocate_string(title), NULL); \
	item->append_node(dvalue); 

//IBP协议串行化一个XML节点，值是字符串
#define IBP_PACKET_XML_OBJ_STR(title, var) \
	dvalue->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(var)));

//IBP协议串行化一个XML节点，值是整型
#define IBP_PACKET_XML_OBJ_INT(title, var) \
	sprintf(tmp, "%d", var); \
	dvalue->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是无符号整型
#define IBP_PACKET_XML_OBJ_UINT(title, var) \
	sprintf(tmp, "%u", var); \
	dvalue->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化一个XML节点，值是浮点型
#define IBP_PACKET_XML_OBJ_DOUBLE(title, var) \
	sprintf(tmp, "%f", var); \
	dvalue->append_attribute(xml.allocate_attribute(xml.allocate_string(title), xml.allocate_string(tmp)));

//IBP协议串行化XML消息结束部分
#define   PACKET_IBP_END \
	std::string  sOutput = ""; \
	rapidxml::print(std::back_inserter(sOutput), xml, 0); \
	if (sOutput != ""  && sOutput.length() > 0){\
	SAFE_DELETE_V(_body) \
	size_t len = sOutput.length() + 1;	\
	_body = new char[len]; \
	assert(_body); \
	memset(_body, 0, len); \
	memcpy(_body, sOutput.c_str(), len - 1); \
	_bodyLen = (t_uint32)strlen(_body);} \
	xml.clear();

#define   PACKET_TAKE_END \
	std::string  sOutput = ""; \
	rapidxml::print(std::back_inserter(sOutput), xml, 0); \
	if (sOutput != ""  && sOutput.length() > 0){\
	SAFE_DELETE_V(_takeBuf) \
	size_t len = sOutput.length();	\
	_takeBuf = new char[len + 1]; \
	assert(_takeBuf); \
	memset(_takeBuf, 0, len + 1); \
	memcpy(_takeBuf, sOutput.c_str(), len); \
	_takeLen = (t_uint32)strlen(_takeBuf);} \
	xml.clear();

#define   PACKET_IBP_TAKE_END \
	std::string  sOutput = ""; \
	rapidxml::print(std::back_inserter(sOutput), xml, 0); \
	if (sOutput != ""  && sOutput.length() > 0){\
	SAFE_DELETE_V(_body) \
	size_t len = sOutput.length();	\
	_body = new char[len + _takeLen + 1]; \
	assert(_body); \
	memset(_body, 0, len + _takeLen + 1); \
	memcpy(_body, sOutput.c_str(), len); \
	if(_takeBuf != NULL && _takeLen > 0)\
{\
	memcpy(_body + len, _takeBuf, _takeLen);\
	}\
	_bodyLen = (t_uint32)(len + _takeLen);} \
	xml.clear();

#define   PACKET_ALARMPLAN_END \
	std::string  sOutput = ""; \
	rapidxml::print(std::back_inserter(sOutput), xml, 0); \
	if (sOutput != ""  && sOutput.length() > 0){\
	SAFE_DELETE_V(_body) \
	size_t len = sOutput.length();	\
	_body = new char[len + _takeLen + 1]; \
	assert(_body); \
	memset(_body, 0, len + _takeLen + 1); \
	memcpy(_body, sOutput.c_str(), len); \
	if(_xmlbody.length() > 0)\
{\
	memcpy(_body + len, _xmlbody.c_str(), _takeLen);\
	}\
	_bodyLen = (t_uint32)(len + _takeLen);} \
	xml.clear();

//自定义XML消息开始部分
#define   XML_DEFINE_END   \
	std::string  sOutput = ""; \
	rapidxml::print(std::back_inserter(sOutput), xml, 0); \
	t_uint32 len = (t_uint32)sOutput.length(); \
	if(maxlen > len){ \
	if (sOutput != ""  && len > 0){ \
	strcpy(outxml, sOutput.c_str()); \
	outxml[len] = '\0';}else{outxml[0] = '\0';} \
	}else{ret = IBP_Err_SDK_Com_LenOver;} \
	xml.clear();

#endif

