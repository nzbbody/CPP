
#include "Talk.h"
#include "RenderManager.h"
#include "DH_VideoRender.h"
#include "DevConfig.h"
#include "DevConfigEx.h"
#include "DecoderDevice.h"
#include "../dhdvr/ParseString.h"

#ifdef WIN32
#include "Alaw_encoder.c"
#include "./depend/hisamr.h"
#endif

DHNET_NAMESPACE_BEGIN


CTalk::CTalk(CManager *pManager)
	: m_pManager(pManager)
{
	m_ARStartSuc = FALSE;
	m_render = NULL;
	m_iEncodeFlag = 0;
	m_hisEncodeHandle = 0;
}

CTalk::~CTalk()
{

}

int CTalk::Init()
{
	m_render = m_pManager->GetRenderManager().GetRender((HWND)0xFFFFFFFF);
	if (0 == (int)m_render || -1 == (int)m_render)
	{
		m_render = NULL;
	}

#ifdef WIN32
	if (NULL == m_hisEncodeHandle) 
	{
		if (HI_SUCCESS != AMR_Encode_Init(&m_hisEncodeHandle, 0)) 
		{
			m_hisEncodeHandle = NULL;
			m_pManager->SetLastError(NET_ILLEGAL_PARAM);
			return NET_ILLEGAL_PARAM;
		}
	}
#endif

	return 0;
}

int CTalk::UnInit()
{
	m_cs.Lock();

	{
		list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
		for (; it != m_talkhandlelist.end(); it++)
		{
			if (*it)
			{
				if ((*it)->pTalkChannel)
				{
					(*it)->pTalkChannel->close((*it)->pTalkChannel);
				}
				delete (*it);
			}
		}
		m_talkhandlelist.clear();
	}
	
	{
		list<LPTALKBROADCASTINFO>::iterator it = m_broadcastlist.begin();
		for (; it != m_broadcastlist.end(); it++)
		{
			if (*it)
			{
				if ((*it)->pTalkChannel)
				{
					(*it)->pTalkChannel->close((*it)->pTalkChannel);
				}
				delete (*it);
			}
		}
		m_broadcastlist.clear();
	}
	
	m_cs.UnLock();
	
	if (m_ARStartSuc && m_render != NULL)
	{		
		m_render->CloseAudioRecord();
		m_ARStartSuc = FALSE;
	}

	if (m_render != NULL)
	{
		m_pManager->GetRenderManager().ReleaseRender(m_render);
		m_render = NULL;
	}

#ifdef WIN32
	if (m_hisEncodeHandle != NULL) 
	{
		AMR_Encode_Exit(&m_hisEncodeHandle);
		m_hisEncodeHandle = NULL;
	}
#endif
	
	return 0;
}

/*
 * 摘要：开始语音对讲
 */
// LONG CTalk::StartTalk(LONG lLoginID, pfAudioDataCallBack pfcb, DWORD dwUser)
// {
// 	afk_device_s *device = (afk_device_s *)lLoginID;
// 
// 	// 查询是直连方式还是服务器方式
// 	int nTalkMode = 0;
// 	BOOL bServerMode = FALSE;
// 	device->get_info(device, dit_talk_use_mode, &nTalkMode);
// 	bServerMode = nTalkMode==1? TRUE:FALSE;
// 
// 	// 查询指定的双方音频格式
// 	AUDIO_ATTR_T stTalkEncodeType = {0};
// 	device->get_info(device, dit_talk_encode_type, &stTalkEncodeType);
// 
// 	m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K8BPCM;
// 	m_FrameLength = 1024;
// 	m_dwSampleRate = 8000;
// 	m_nAudioBit = 8;
// 	
// 	if (stTalkEncodeType.iAudioType == 0xFFFF)	// 为了兼容性，默认方式就为PCM
// 	{
// 		stTalkEncodeType.iAudioType = 0;
// 		int	bufLen = sizeof(DIALOG_CAPS)+16*sizeof(AUDIO_ATTR_T);
// 		char* capBuf = new char[bufLen];
// 		if (NULL == capBuf)
// 		{
// 			m_pManager->SetLastError(NET_SYSTEM_ERROR);
// 			return 0;
// 		}
// 		
// 		int retlen = 0;
// 		int iRet = m_pManager->GetDevConfig().QuerySystemInfo(lLoginID, SYSTEM_INFO_TALK_ATTR, capBuf, bufLen, &retlen, QUERY_WAIT);
// 		if (iRet >= 0 && retlen >= sizeof(DIALOG_CAPS) && ((retlen-sizeof(DIALOG_CAPS))%sizeof(AUDIO_ATTR_T))==0) 
// 		{
// 			DIALOG_CAPS* pDialogCap = (DIALOG_CAPS*)capBuf;
// 			if (0 == pDialogCap->iAudioTypeNum)
// 			{
// 				delete[] capBuf;
// 				m_pManager->SetLastError(NET_UNSUPPORTED);
// 				return 0;
// 			}
// 			AUDIO_ATTR_T* pAAT = NULL;
// 			for (int i = 0; i < pDialogCap->iAudioTypeNum; i++)
// 			{
// 				pAAT = (AUDIO_ATTR_T*)(capBuf+sizeof(DIALOG_CAPS)+i*sizeof(AUDIO_ATTR_T));
// 				
// 				if(1==pAAT->iAudioType && m_dwAudioEncodeType<INTERNEL_ENCODE_TYPE_8K16BNEWPCM)
// 				{
// 					//设备支持带头信息的PCM 8K 16 Bit
// 					m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K16BNEWPCM;
// 					m_FrameLength = 1024;
// 					m_dwSampleRate = pAAT->dwSampleRate;
// 					m_nAudioBit = pAAT->iAudioBit;
// 				}
// 			}
// 		}
// 		
// 		if (capBuf != NULL)
// 		{
// 			delete[] capBuf;
// 			capBuf = NULL;
// 		}
// 	}
// 	else if (stTalkEncodeType.iAudioType == 0)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K8BPCM;
// 		m_FrameLength = 1024;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 	else if (stTalkEncodeType.iAudioType == 1)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K16BNEWPCM;
// 		m_FrameLength = 1024;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 	else if (stTalkEncodeType.iAudioType == 2)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G711A8K16B;
// 		m_FrameLength = 1280;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 	else if (stTalkEncodeType.iAudioType == 3)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_AMR8K16B;
// 		m_FrameLength = 320;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 	else if (stTalkEncodeType.iAudioType == 4)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G711U8K16B;
// 		m_FrameLength = 320;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 	else if (stTalkEncodeType.iAudioType == 5)
// 	{
// 		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G7268K16B;
// 		m_FrameLength = 320;
// 		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
// 		m_nAudioBit = stTalkEncodeType.iAudioBit;
// 	}
// 
// 	// 直连方式开启解码
// 	if (!bServerMode)
// 	{
// 		if (NULL == m_render) 
// 		{
// 			m_pManager->SetLastError(NET_NO_TALK_CHANNEL);
// 			return 0;
// 		}
// 
// 		if (m_render->StartDec(FALSE, 
// 			(INTERNEL_ENCODE_TYPE_8K16BNEWPCM==m_dwAudioEncodeType || INTERNEL_ENCODE_TYPE_G711A8K16B==m_dwAudioEncodeType || INTERNEL_ENCODE_TYPE_AMR8K16B==m_dwAudioEncodeType || INTERNEL_ENCODE_TYPE_G711U8K16B==m_dwAudioEncodeType || INTERNEL_ENCODE_TYPE_G7268K16B==m_dwAudioEncodeType) ? 2 : 1) < 0)
// 		{
// 			m_pManager->SetLastError(NET_RENDER_SOUND_ON_ERROR);
// 			return 0;
// 		}
// 	}
// 
// 	LONG lRet = 0;
// 	m_cs.Lock();
// 
// 	afk_talk_channel_param_s talkchannelpar;
// 	LPTALKHANDLEINFO pstTalkInfo = NULL;
// 
// 	// 一个登入只有一个语音对讲
// 	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
// 	for (;it != m_talkhandlelist.end(); it++)
// 	{
// 		if ((*it)->lDevHandle == lLoginID)
// 		{
// 			m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
// 			goto FAILED;
// 		}
// 	}
// 
// 	// 创建语音对讲通道
// 	pstTalkInfo = new TALKHANDLEINFO;
// 	if (NULL == pstTalkInfo)
// 	{
// 		m_pManager->SetLastError(NET_SYSTEM_ERROR);
// 		goto FAILED;
// 	}
// 	memset((void *)pstTalkInfo, 0, sizeof(TALKHANDLEINFO));
// 	memset((void *)&talkchannelpar, 0, sizeof(afk_channel_param_s));
// 	talkchannelpar.base.udata = (void *)pstTalkInfo;
// 	talkchannelpar.base.func = CTalk::TalkFunc;
// 	talkchannelpar.no = pstTalkInfo->iChannelId;
// 	talkchannelpar.nEncodeType = stTalkEncodeType.iAudioType==0?1:stTalkEncodeType.iAudioType;
// 	talkchannelpar.nAudioBit = stTalkEncodeType.iAudioBit;
// 	talkchannelpar.dwSampleRate = stTalkEncodeType.dwSampleRate;
// 	
// 	pstTalkInfo->pTalkChannel = (afk_channel_s *)device->open_channel(device, AFK_CHANNEL_TYPE_TALK, &talkchannelpar);
// 	if (NULL == pstTalkInfo->pTalkChannel)
// 	{
// 		m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
// 		goto FAILED;
// 	}
// 
// 	pstTalkInfo->lDevHandle = lLoginID;
// 	pstTalkInfo->pfcb = pfcb;
// 	pstTalkInfo->dwUser = dwUser;
// 	m_talkhandlelist.push_back(pstTalkInfo);
// 	
// 	lRet = (LONG)pstTalkInfo;
// 	goto END;
// 
// FAILED:
// 	if (pstTalkInfo != NULL)
// 	{
// 		if (pstTalkInfo->pTalkChannel != NULL)
// 		{
// 			pstTalkInfo->pTalkChannel->close(pstTalkInfo->pTalkChannel);
// 		}
// 		delete pstTalkInfo;
// 	}
// 
// 	if (!bServerMode)
// 	{
// 		if (m_render != NULL)
// 		{
// 			m_render->CloseAudio();
// 			m_render->StopDec();
// 		}
// 	}
// 
// END:
// 	m_cs.UnLock();
// 	return lRet;
// }
LONG CTalk::StartTalk(LONG lLoginID, pfAudioDataCallBack pfcb, DWORD dwUser)
{
	afk_device_s *device = (afk_device_s *)lLoginID;

	// 查询是直连方式还是服务器方式
	int nTalkMode = 0;
	BOOL bServerMode = FALSE;
	device->get_info(device, dit_talk_use_mode, &nTalkMode);
	bServerMode = nTalkMode==1? TRUE:FALSE;
	int nProtocolVer = 0;

	// 查询指定的双方音频格式
	AUDIO_ATTR_T stTalkEncodeType = {0};
	device->get_info(device, dit_talk_encode_type, &stTalkEncodeType);

	m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K8BPCM;
	m_FrameLength = 1024;
	m_dwSampleRate = 8000;
	m_nAudioBit = 8;
	
	if (stTalkEncodeType.iAudioType == 0xFFFF)	// 为了兼容性，默认方式就为PCM
	{
		stTalkEncodeType.iAudioType = 0;
		int	bufLen = sizeof(DIALOG_CAPS)+16*sizeof(AUDIO_ATTR_T);
		char* capBuf = new char[bufLen];
		if (NULL == capBuf)
		{
			m_pManager->SetLastError(NET_SYSTEM_ERROR);
			return 0;
		}
		
		int retlen = 0;
		int iRet = m_pManager->GetDevConfig().QuerySystemInfo(lLoginID, SYSTEM_INFO_TALK_ATTR, capBuf, bufLen, &retlen, QUERY_WAIT);
		if (iRet >= 0 && retlen >= sizeof(DIALOG_CAPS) && ((retlen-sizeof(DIALOG_CAPS))%sizeof(AUDIO_ATTR_T))==0) 
		{
			DIALOG_CAPS* pDialogCap = (DIALOG_CAPS*)capBuf;
			if (0 == pDialogCap->iAudioTypeNum)
			{
				delete[] capBuf;
				m_pManager->SetLastError(NET_UNSUPPORTED);
				return 0;
			}
			AUDIO_ATTR_T* pAAT = NULL;
			for (int i = 0; i < pDialogCap->iAudioTypeNum; i++)
			{
				pAAT = (AUDIO_ATTR_T*)(capBuf+sizeof(DIALOG_CAPS)+i*sizeof(AUDIO_ATTR_T));
				
				if(1==pAAT->iAudioType && m_dwAudioEncodeType<INTERNEL_ENCODE_TYPE_8K16BNEWPCM)
				{
					//设备支持带头信息的PCM 8K 16 Bit
					m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K16BNEWPCM;
					m_FrameLength = 1024;
					m_dwSampleRate = pAAT->dwSampleRate;
					m_nAudioBit = pAAT->iAudioBit;
				}
			}
		}
		
		if (capBuf != NULL)
		{
			delete[] capBuf;
			capBuf = NULL;
		}
	}
	else if (stTalkEncodeType.iAudioType == 0)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K8BPCM;
		m_FrameLength = 1024;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}
	else if (stTalkEncodeType.iAudioType == 1)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_8K16BNEWPCM;
		m_FrameLength = 1024;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}
	else if (stTalkEncodeType.iAudioType == 2)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G711A8K16B;
		m_FrameLength = 1280;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}
	else if (stTalkEncodeType.iAudioType == 3)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_AMR8K16B;
		m_FrameLength = 320;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}
	else if (stTalkEncodeType.iAudioType == 4)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G711U8K16B;
		m_FrameLength = 320;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}
	else if (stTalkEncodeType.iAudioType == 5)
	{
		m_dwAudioEncodeType = INTERNEL_ENCODE_TYPE_G7268K16B;
		m_FrameLength = 320;
		m_dwSampleRate = stTalkEncodeType.dwSampleRate;
		m_nAudioBit = stTalkEncodeType.iAudioBit;
	}

	// 直连方式开启解码
	if (!bServerMode)
	{
		if (NULL == m_render) 
		{
			m_pManager->SetLastError(NET_NO_TALK_CHANNEL);
			return 0;
		}


		if (m_render->StartDec(FALSE, 
			(INTERNEL_ENCODE_TYPE_8K16BNEWPCM==m_dwAudioEncodeType || 
			 INTERNEL_ENCODE_TYPE_G711A8K16B==m_dwAudioEncodeType || 
			 INTERNEL_ENCODE_TYPE_AMR8K16B==m_dwAudioEncodeType || 
			 INTERNEL_ENCODE_TYPE_G711U8K16B==m_dwAudioEncodeType || 
			 INTERNEL_ENCODE_TYPE_G7268K16B==m_dwAudioEncodeType ||
			 INTERNEL_ENCODE_TYPE_AAC8K16B ==m_dwAudioEncodeType) ? 2 : 1) < 0)
		{
			m_pManager->SetLastError(NET_RENDER_SOUND_ON_ERROR);
			return 0;
		}
 
#ifdef _DEBUG
		OutputDebugString("Start Decode.\n");
#endif

	}

	LONG lRet = 0;
	m_cs.Lock();

	afk_talk_channel_param_s talkchannelpar = {0};
	LPTALKHANDLEINFO pstTalkInfo = NULL;

	// 一个登入只有一个语音对讲
	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
	for (;it != m_talkhandlelist.end(); it++)
	{
// 		if ((*it)->lDevHandle == lLoginID)
// 		{
// 			m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
// 			goto FAILED;
// 		}
		int nChannle = -1;
		device->get_info(device, dit_talk_channel_flag, (void*)&nChannle);
		if ((*it)->lDevHandle == lLoginID && (*it)->iChannelId == nChannle)
		{
	//		printf("only one channel\n");
			m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
			goto FAILED;
		}
	}

	// 创建语音对讲通道
	pstTalkInfo = new TALKHANDLEINFO;
	if (NULL == pstTalkInfo)
	{
		m_pManager->SetLastError(NET_SYSTEM_ERROR);
		goto FAILED;
	}
	memset((void *)pstTalkInfo, 0, sizeof(TALKHANDLEINFO));
	memset((void *)&talkchannelpar, 0, sizeof(afk_channel_param_s));
	talkchannelpar.base.udata = (void *)pstTalkInfo;
	talkchannelpar.base.func = CTalk::TalkFunc;
	//talkchannelpar.no = pstTalkInfo->iChannelId;
	device->get_info(device, dit_talk_channel_flag, (void*)&talkchannelpar.no);
	talkchannelpar.nEncodeType = stTalkEncodeType.iAudioType==0?1:stTalkEncodeType.iAudioType;
	talkchannelpar.nAudioBit = stTalkEncodeType.iAudioBit;
	talkchannelpar.dwSampleRate = stTalkEncodeType.dwSampleRate;

	device->get_info(device, dit_protocol_version, (void*)&nProtocolVer);
	if(nProtocolVer >= 6)//大于6版本，动态多连接方式
	{
		int ret = m_pManager->GetDevConfigEx().SetupSession(lLoginID, 0, &talkchannelpar.connect_param);
		if (ret < 0)
		{
		//	printf("set upSession failed\n");
			m_pManager->SetLastError(ret);
			return 0;
		}
		pstTalkInfo->nConnectID = talkchannelpar.connect_param.nConnectID;
		pstTalkInfo->nEncodeType = talkchannelpar.nEncodeType;
	}
	
	pstTalkInfo->pTalkChannel = (afk_channel_s *)device->open_channel(device, AFK_CHANNEL_TYPE_TALK, &talkchannelpar);
	if (NULL == pstTalkInfo->pTalkChannel)
	{
	//	printf("AFK_CHANNEL_TYPE_TALK failed\n");
		m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
		goto FAILED;
	}

	if(nProtocolVer >= 6)
	{
		//请求对讲
		REQUEST_TALK requestTalk = {0};
		requestTalk.nChannel = talkchannelpar.no;
		requestTalk.nConnectID = talkchannelpar.connect_param.nConnectID;
		requestTalk.nEncodeType = talkchannelpar.nEncodeType;
		requestTalk.nStart = 1;
		char szBuffer[512] = {0};
		int nRetLen = 0;
		int ret = m_pManager->GetDecoderDevice().SysQueryInfo(lLoginID, AFK_REQUEST_TALK, (void*)&requestTalk, 
															szBuffer, 512, &nRetLen, 3000);
		if(ret < 0)
		{
			m_pManager->GetDevConfigEx().DestroySession(lLoginID, talkchannelpar.connect_param.nConnectID);
			if(nRetLen > 0)
			{
				char szValue[48] = {0};
				char* p = GetProtocolValue(szBuffer, "ErrorReason:", "\r\n", szValue, 48);
				if(p != NULL)
				{
					int nError = atoi(szValue);
					if(nError < 0 || nError > 4)
					{
						m_pManager->SetLastError(NET_ERROR_TALK_FAILED);
					}
					else
					{
						m_pManager->SetLastError(nError+NET_ERROR_TALK_REJECT);
					}
				}
			}
			else
			{
				m_pManager->SetLastError(NET_ERROR_TALK_FAILED);
			}
			goto FAILED;
		}
	}
	
	pstTalkInfo->iChannelId = talkchannelpar.no;
	pstTalkInfo->lDevHandle = lLoginID;
	pstTalkInfo->pfcb = pfcb;
	pstTalkInfo->dwUser = dwUser;
	m_talkhandlelist.push_back(pstTalkInfo);
	
	lRet = (LONG)pstTalkInfo;
	goto END;

FAILED:
	if (pstTalkInfo != NULL)
	{
		if (pstTalkInfo->pTalkChannel != NULL)
		{
			pstTalkInfo->pTalkChannel->close(pstTalkInfo->pTalkChannel);
		}
		delete pstTalkInfo;
	}

	if (!bServerMode)
	{
		if (m_render != NULL)
		{
			m_render->CloseAudio();
			m_render->StopDec();
		}
	}

END:
	m_cs.UnLock();
	return lRet;
}
/*
 * 摘要：设置音量，范围0 -- 0xFFFF
 */
BOOL CTalk::SetVolume(LONG lTalkHandle, WORD wVolume)
{
	BOOL bRet = FALSE;
	m_cs.Lock();

	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
	for (; it != m_talkhandlelist.end(); it++)
	{
		if (lTalkHandle == (LONG)(*it))
		{
			break;
		}
	}

	if (it == m_talkhandlelist.end())
	{
		m_pManager->SetLastError(NET_INVALID_HANDLE);
		bRet = FALSE;
		goto END;
	}
	
	if (NULL == m_render) 
	{
		m_pManager->SetLastError(NET_NO_TALK_CHANNEL);
		bRet = FALSE;
		goto END;
	}

	bRet = m_render->SetAudioVolume(wVolume);
	if (!bRet)
	{
		m_pManager->SetLastError(NET_RENDER_SET_VOLUME_ERROR);
		goto END;
	}

END:
	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：发送音频数据到设备
 */
LONG CTalk::SendData2Dev(afk_channel_s *pChannel, char *pSendBuf, DWORD dwBufSize)
{
	LONG lRet = 0;

	if (NULL == pChannel || NULL == pSendBuf || 0 == dwBufSize)
	{
		m_pManager->SetLastError(NET_ILLEGAL_PARAM);
		return -1;
	}

	struct afk_talk_info_s tempst;
	tempst.data = pSendBuf;
	tempst.datalen = dwBufSize;
	if (1 == pChannel->set_info(pChannel, 0, &tempst))
	{
		lRet = dwBufSize;
	}

	return lRet;
}

/*
 * 摘要：发送采集的音频数据，返回值为发送字节数
 */
LONG CTalk::TalkSendData(LONG lTalkHandle, char *pSendBuf, DWORD dwBufSize)
{
	LONG lRet = 0;
	m_cs.Lock();

	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
	for (; it != m_talkhandlelist.end(); it++)
	{
		if ((LONG)(*it) == lTalkHandle)
		{
			break;
		}
	}

	if (it == m_talkhandlelist.end() || NULL == (*it))
	{
		m_pManager->SetLastError(NET_INVALID_HANDLE);
		lRet = -1;
		goto END;
	}

	lRet = SendData2Dev((*it)->pTalkChannel, pSendBuf, dwBufSize);

END:
	m_cs.UnLock();
	return lRet;
}

/*
 * 摘要：启动本地录音
 */
BOOL CTalk::RecordStart()
{
	BOOL bRet = FALSE;
	m_cs.Lock();
	
	m_ARStartSuc=FALSE;
	bRet = m_render->OpenAudioRecord(CTalk::RecordFunc,m_nAudioBit,m_dwSampleRate,m_FrameLength,0,(long)this);	
	if(bRet)
	{
		m_ARStartSuc=TRUE;
		goto END;
	}	
	m_pManager->SetLastError(NET_ERROR);

END:
	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：停止本地录音
 */
BOOL CTalk::RecordStop()
{
	BOOL bRet = FALSE;
	m_cs.Lock();

	if(m_ARStartSuc)
	{
		bRet = m_render->CloseAudioRecord();
	}

	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：解码播放接收到的音频数据
 */
void CTalk::AudioDec(char *pAudioDataBuf, DWORD dwBufSize)
{
	if (NULL == m_render)
	{
		return;
	}

	if (INTERNEL_ENCODE_TYPE_8K8BPCM == m_dwAudioEncodeType)
	{
		for (int i = 0; i < dwBufSize; i++)
		{
			pAudioDataBuf[i] += 128;
		}
	}

	m_render->Play((BYTE*)pAudioDataBuf, dwBufSize);
}

/*
 * 摘要：停止语音对讲
 */
BOOL CTalk::StopTalk(LONG lTalkHandle)
{
// 	BOOL bRet = TRUE;
// 	m_cs.Lock();
// 	
// 	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
// 	for (; it != m_talkhandlelist.end(); it++)
// 	{
// 		if ((LONG)(*it) == lTalkHandle)
// 		{
// 			break;
// 		}
// 	}
// 
// 	if (it == m_talkhandlelist.end())
// 	{
// 		bRet = FALSE;
// 		m_pManager->SetLastError(NET_ERROR);
// 		goto END;
// 	}
// 
// 	if (*it)
// 	{
// 		if ((*it)->pTalkChannel)
// 		{
// 			(*it)->pTalkChannel->close((*it)->pTalkChannel);
// 		}
// 		delete (*it);
// 	}
// 	m_talkhandlelist.erase(it);
// 
// 	if (m_render != NULL)
// 	{
// 		if (m_render->StopDec() < 0)
// 		{
// #ifdef DEBUG
// 			OutputDebugString("stop dec while stop talk failed!\n");
// #endif
// 		}
// 
// 		if (!m_render->CloseAudio())
// 		{
// #ifdef DEBUG
// 			OutputDebugString("stop dec while stop talk failed!\n");
// #endif
// 		}
// 	}
// 	
// END:
// 	m_cs.UnLock();
// 	return bRet;

	BOOL bRet = TRUE;
	m_cs.Lock();
	
	list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
	for (; it != m_talkhandlelist.end(); it++)
	{
		if ((LONG)(*it) == lTalkHandle)
		{
			break;
		}
	}
	
	if (it == m_talkhandlelist.end())
	{
		bRet = FALSE;
		m_pManager->SetLastError(NET_ERROR);
		goto END;
	}
	
	if (*it)
	{
		if ((*it)->pTalkChannel)
		{
			(*it)->pTalkChannel->close((*it)->pTalkChannel);
#ifdef _DEBUG
			OutputDebugString("Destroy Session.\n");
#endif
			LPTALKHANDLEINFO lpTalkInfo = (*it);
			int nProtocolVer = 0;
			afk_device_s* device = 	(afk_device_s*)lpTalkInfo->lDevHandle;
			device->get_info(device, dit_protocol_version, (void*)&nProtocolVer);
			if(nProtocolVer >= 6)//大于6版本，动态多连接方式
			{
				//请求对讲
				REQUEST_TALK requestTalk = {0};
				requestTalk.nChannel = lpTalkInfo->iChannelId;
				requestTalk.nConnectID = lpTalkInfo->nConnectID;
				requestTalk.nEncodeType = lpTalkInfo->nEncodeType;
				requestTalk.nStart = 0;
				char szBuffer[512] = {0};
				int nRetLen = 0;
				//不判断返回值了，即使失败，也得继续下面的操作。
				int ret = m_pManager->GetDecoderDevice().SysQueryInfo(lpTalkInfo->lDevHandle, AFK_REQUEST_TALK, (void*)&requestTalk, 
					szBuffer, 512, &nRetLen, 3000);
				
				m_pManager->GetDevConfigEx().DestroySession(lpTalkInfo->lDevHandle, lpTalkInfo->nConnectID);
			}
		}
		delete (*it);
	}
	m_talkhandlelist.erase(it);
	
	if (m_render != NULL)
	{
		if (m_render->StopDec() < 0)
		{
#ifdef DEBUG
			OutputDebugString("stop dec while stop talk failed!\n");
#endif
		}
#ifdef _DEBUG
		OutputDebugString("Stop Decode.\n");
#endif
		if (!m_render->CloseAudio())
		{
#ifdef DEBUG
			OutputDebugString("stop dec while stop talk failed!\n");
#endif
		}
	}
	
END:
	
	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：增加设备到广播组里，本地采集到的数据会自动转发给广播组里的设备。
 *       先跟一台设备进行语音对讲，指定了对讲语音格式，然后加入其它设备。
 */
BOOL CTalk::BroadcastAddDev(LONG lLoginID)
{
	if (m_pManager->IsDeviceValid((afk_device_s *)lLoginID) < 0)
    {
		m_pManager->SetLastError(NET_INVALID_HANDLE);
        return FALSE;
    }
	
	m_cs.Lock();

	list<LPTALKBROADCASTINFO>::iterator it = m_broadcastlist.begin();
	for (; it != m_broadcastlist.end(); it++)
	{
		if ((*it)->lDevHandle == lLoginID)
		{
			m_cs.UnLock();
			m_pManager->SetLastError(NET_ERROR);
			return FALSE;
		}
	}

	BOOL bRet = FALSE;
	afk_device_s *device = (afk_device_s *)lLoginID;
	afk_talk_channel_param_s talkchannelpar;
	LPTALKBROADCASTINFO ptmpinfo = NULL;
	ptmpinfo = new TALKBROADCASTINFO;
	if (NULL == ptmpinfo)
	{
		m_pManager->SetLastError(NET_SYSTEM_ERROR);
		goto FAILED;
	}
	memset((void *)ptmpinfo, 0, sizeof(TALKBROADCASTINFO));
	memset((void *)&talkchannelpar, 0, sizeof(afk_talk_channel_param_s));
	talkchannelpar.base.udata = (void *)ptmpinfo;
	talkchannelpar.base.func = NULL;
	talkchannelpar.no = ptmpinfo->iChannelId;
	talkchannelpar.nEncodeType = m_dwAudioEncodeType==0?1:m_dwAudioEncodeType;
	talkchannelpar.nAudioBit = m_nAudioBit;
	talkchannelpar.dwSampleRate = m_dwSampleRate;
	ptmpinfo->pTalkChannel = (afk_channel_s *)device->open_channel(device, AFK_CHANNEL_TYPE_TALK, &talkchannelpar);
	if (NULL == ptmpinfo->pTalkChannel)
	{
		m_pManager->SetLastError(NET_OPEN_CHANNEL_ERROR);
		goto FAILED;
	}
	ptmpinfo->lDevHandle = lLoginID;
	m_broadcastlist.push_back(ptmpinfo);
	bRet = TRUE;
	goto END;

FAILED:
	bRet = FALSE;
	if (ptmpinfo != NULL)
	{
		if (ptmpinfo->pTalkChannel)
		{
			ptmpinfo->pTalkChannel->close(ptmpinfo->pTalkChannel);
		}
		delete ptmpinfo;
	}
END:
	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：从广播组里删除设备
 */
BOOL CTalk::BroadcastDelDev(LONG lLoginID)
{
	BOOL bRet = FALSE;
	m_cs.Lock();
	
	list<LPTALKBROADCASTINFO>::iterator it = m_broadcastlist.begin();
	for (; it != m_broadcastlist.end(); it++)
	{
		if ((*it) && (*it)->lDevHandle == lLoginID)
		{
			if ((*it)->pTalkChannel)
			{
				(*it)->pTalkChannel->close((*it)->pTalkChannel);
			}
			delete (*it);
			m_broadcastlist.erase(it);
			break;
		}
	}
	if (m_broadcastlist.end() == it)
	{
		m_pManager->SetLastError(NET_ERROR);
		bRet = FALSE;
	}

	m_cs.UnLock();
	return bRet;
}

/*
 * 摘要：音频编码--初始化(特定标准格式->大华格式)
 */
int CTalk::InitAudioEncode(DH_AUDIO_FORMAT aft)
{
	if (aft.byFormatTag != 0 || aft.nChannels != 1 || aft.wBitsPerSample != 16 || aft.nSamplesPerSec != 8000)
	{
		m_iEncodeFlag = 0;
		m_pManager->SetLastError(NET_ILLEGAL_PARAM);
		return NET_ILLEGAL_PARAM;
	}

	m_iEncodeFlag = 1;
	return 0;
}

/*
 * 摘要：音频编码--数据编码
 */
int	CTalk::AudioEncode(LONG lHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen)
{
	if (0 == m_iEncodeFlag)
	{
		m_pManager->SetLastError(NET_AUDIOENCODE_NOTINIT);
		return NET_AUDIOENCODE_NOTINIT;
	}

	if (NULL == lpInBuf || NULL == lpInLen || NULL == lpOutBuf || NULL == lpOutLen || 0 == *lpInLen)
	{
		m_pManager->SetLastError(NET_ILLEGAL_PARAM);
		return NET_ILLEGAL_PARAM;
	}

	if (*lpInLen >= MAX_ENCODE_LEN*2)
	{
		*lpInLen = MAX_ENCODE_LEN*2;
		m_pManager->SetLastError(NET_DATA_TOOLONGH);
		return NET_DATA_TOOLONGH;
	}

	if (*lpOutLen < (*lpInLen/2 + 8))
	{
		*lpOutLen = *lpInLen/2 + 8;
		m_pManager->SetLastError(NET_INSUFFICIENT_BUFFER);
		return NET_INSUFFICIENT_BUFFER;
	}
	
	int iRet = 0;
	int iCount = 0;
	int iDataLen = (*lpInLen>>1);
	unsigned short *p16 = (unsigned short *)lpInBuf;
	lpOutBuf[iCount++] = 0x00;
	lpOutBuf[iCount++] = 0x00;
	lpOutBuf[iCount++] = 0x01;
	lpOutBuf[iCount++] = 0xf0;
	lpOutBuf[iCount++] = 0x07;
	lpOutBuf[iCount++] = 0x02;
	*(unsigned short *)(lpOutBuf+iCount) = (unsigned short)iDataLen;
	iCount += 2;

	for (int i = 0; i < iDataLen; i++)
	{
		lpOutBuf[iCount++] = (BYTE)(*p16>>8);
		p16++;
	}
	
	*lpOutLen = iCount;	
	*lpInLen = 0;
	
	return iRet;
}

/*
 * 摘要：音频编码--完成退出
 */
int CTalk::ReleaseAudioEncode()
{
	m_iEncodeFlag = 0;

	return 0;
}

/*
 * 摘要：关闭一个设备所有通道
 */
int CTalk::CloseChannelOfDevice(afk_device_s * pdev)
{
	int iRet = 0;
	m_cs.Lock();
	
	{
		list<LPTALKHANDLEINFO>::iterator it = m_talkhandlelist.begin();
		for (; it != m_talkhandlelist.end(); it++)
		{
			if ((*it)->lDevHandle == LONG(pdev))
			{
				if ((*it)->pTalkChannel != NULL)
				{
					(*it)->pTalkChannel->close((*it)->pTalkChannel);
				}
				delete (*it);
				m_talkhandlelist.erase(it);
				break;
			}
		}
	}

	{
		list<LPTALKBROADCASTINFO>::iterator it = m_broadcastlist.begin();
		for (; it != m_broadcastlist.end(); it++)
		{
			if ((*it)->lDevHandle == LONG(pdev))
			{
				if ((*it)->pTalkChannel != NULL)
				{
					(*it)->pTalkChannel->close((*it)->pTalkChannel);
				}
				delete (*it);
				m_broadcastlist.erase(it);
				break;
			}
		}
	}

	m_cs.UnLock();
	return iRet;
}

/*
 * 摘要：接收到设备的对讲数据
 */
int WINAPI CTalk::TalkFunc(afk_handle_t object, unsigned char *data, unsigned int datalen, void *param, void *udata)
{
	LPTALKHANDLEINFO pTalkHandle = (LPTALKHANDLEINFO)udata;
	if (pTalkHandle == NULL || 0 == datalen)
	{
		return -1;
	}

	if (pTalkHandle->pfcb)
	{
		pTalkHandle->pfcb((LONG)pTalkHandle, (char *)data, datalen, 1, pTalkHandle->dwUser);
	}
	
	return 0;
}

/*
 * 摘要：对采集到的PCM数据进行编码
 */
void WINAPI CTalk::RecordFunc(LPBYTE pDataBuffer, DWORD DataLength, long user)
{
#ifdef WIN32
	
	if (NULL == pDataBuffer || 0 == DataLength)
	{
		return;
	}
	
	CTalk *ptalk = (CTalk *)user;
	if (NULL == ptalk)
	{
		return;
	}

	char* pCbData = new char[DataLength+100];
	if (NULL == pCbData) 
	{
		return;
	}

	int iCbLen = 0;
	
	if ((ptalk->GetAudioEncodeType() == INTERNEL_ENCODE_TYPE_8K8BPCM) || (ptalk->GetAudioEncodeType() == INTERNEL_ENCODE_TYPE_8K16BNEWPCM)) 
	{
		if (ptalk->GetAudioEncodeBit() == 8)
		{
			for( int j = 0 ; j < DataLength; j++)
			{
				*(pDataBuffer + j) += 128;
			}
		}

		pCbData[0] = 0x00;
		pCbData[1] = 0x00;
		pCbData[2] = 0x01;
		pCbData[3] = 0xF0;
		
		pCbData[4] = (8 == ptalk->GetAudioEncodeBit()) ? 0x07:0x0C;	//pcm8:0x07; pcm16:0x0C
		pCbData[5] = 0x02;//8k
		*(DWORD*)(pCbData+6) = DataLength;
		memcpy(pCbData+8, pDataBuffer, DataLength);
		
		iCbLen = 8+DataLength;
		/*
		//从16bit转至8bit
		iCbLen = DataLength+8;

		DWORD dwRecordDataSize = DataLength;
		unsigned short *p16 = (unsigned short *)pDataBuffer;
		BYTE *pu8 = (BYTE *)pDataBuffer;
		int i = 0;

		dwRecordDataSize = DataLength>>1;
		
		while(dwRecordDataSize>0)
		{
			pCbData[i++]=0x00;
			pCbData[i++]=0x00;
			pCbData[i++]=0x01;
			pCbData[i++]=0xF0;
			
			pCbData[i++]=0x07;//pcm8
			pCbData[i++]=0x02;//8k
			
			if(dwRecordDataSize>=1024)
			{
				pCbData[i++]=0x00;
				pCbData[i++]=0x04;
				
				for(int j=0;j<1024;j++)
				{
					pCbData[i++]=BYTE(*p16>>8);
					p16++;
				}
				dwRecordDataSize-=1024;
			}
			else
			{
				pCbData[i++]=BYTE(dwRecordDataSize&0xff);
				pCbData[i++]=BYTE(dwRecordDataSize>>8);
				for(int j=0;j<(int)dwRecordDataSize;j++)
				{		
					pCbData[i++]=BYTE(*p16>>8);
					p16++;
				}
				dwRecordDataSize=0;
			}
			iCbLen = i;
		}
		*/
	}
	else if (ptalk->GetAudioEncodeType() == INTERNEL_ENCODE_TYPE_G711A8K16B)
	{		
		if (g711a_Encode((char*)pDataBuffer, pCbData+8, DataLength, &iCbLen) != 1)
		{
			delete[] pCbData;
			return;
		}
		
		//大华码流格式帧头
		pCbData[0] = 0x00;
		pCbData[1] = 0x00;
		pCbData[2] = 0x01;
		pCbData[3] = 0xF0;

		pCbData[4] = 0x0E; //G711A
		pCbData[5] = 0x02;
		pCbData[6] = BYTE(iCbLen&0xff);
		pCbData[7] = BYTE(iCbLen>>8);
		
		iCbLen += 8;
	
	}
	else if (ptalk->GetAudioEncodeType() == INTERNEL_ENCODE_TYPE_AMR8K16B)
	{
		//AMR encode
		iCbLen = AMR_Encode_Frame(ptalk->GetHisEncodeHandle(),(HI_S16*)pDataBuffer, (HI_U8*)(pCbData+8),MR102,MIME);
		if (iCbLen <= 0)
		{
			delete[] pCbData;
			return;
		}
		
		pCbData[0]=0x00;
		pCbData[1]=0x00;
		pCbData[2]=0x01;
		pCbData[3]=0xF0;
		
		pCbData[4]=0x14; //AMR
		pCbData[5]=0x02;
		pCbData[6]=BYTE(iCbLen&0xff);
		pCbData[7]=BYTE(iCbLen>>8);

		iCbLen += 8;
	}
	else if (ptalk->GetAudioEncodeType() == INTERNEL_ENCODE_TYPE_G711U8K16B)
	{
		if (g711u_Encode((char*)pDataBuffer, pCbData+8, DataLength, &iCbLen) != 1)
		{
			delete[] pCbData;
			return;
		}

		//大华码流格式帧头
		pCbData[0] = 0x00;
		pCbData[1] = 0x00;
		pCbData[2] = 0x01;
		pCbData[3] = 0xF0;

		pCbData[4] = 0x0A; //G711u
		pCbData[5] = 0x02;
		pCbData[6] = BYTE(iCbLen&0xff);
		pCbData[7] = BYTE(iCbLen>>8);
		
		iCbLen += 8;
	}
	else
	{
		delete[] pCbData;
		return;
	}
	
	ptalk->m_cs.Lock();

	{
		list<LPTALKHANDLEINFO>::iterator it = ptalk->m_talkhandlelist.begin();
		for (; it != ptalk->m_talkhandlelist.end(); it++)
		{
			if (*it && (*it)->pfcb)
			{
				(*it)->pfcb(LONG(*it), pCbData, iCbLen, 0, (*it)->dwUser);
			}
		}
	}
	
	{
		list<LPTALKBROADCASTINFO>::iterator it = ptalk->m_broadcastlist.begin();
		for (; it != ptalk->m_broadcastlist.end(); it++)
		{
			if ((*it) && (*it)->pTalkChannel)
			{
				ptalk->SendData2Dev(((*it)->pTalkChannel), pCbData, iCbLen);
			}
		}
	}

	ptalk->m_cs.UnLock();

	delete[] pCbData;

#endif
}


DHNET_NAMESPACE_END






