// thermo_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include/include.h"
#include "include/tag_define.h"
#include "include/rapidxml/rapidxml.hpp"
#include "include/rapidxml/rapidxml_utils.hpp"
#include "include/rapidxml/rapidxml_print.hpp"
#include <memory>

#pragma comment(lib, "../bin/dhnetsdk.lib")
#pragma comment(lib, "../bin/dhconfigsdk.lib")

const auto g_waitTime = 10000;

using namespace rapidxml;



template <typename T>
void print_optregion(const T& stOption)
{
	PRINT(stOption.bOptimizedRegion);
	PRINT(stOption.nOptimizedROIType);

	for (auto rIdx = 0; rIdx < stOption.nCustomRegion; ++rIdx)
	{
		std::cout << "custom region " << rIdx << ": ["
			<< stOption.stCustomRegions[rIdx].nLeft << ", "
			<< stOption.stCustomRegions[rIdx].nTop << ", "
			<< stOption.stCustomRegions[rIdx].nRight << ", "
			<< stOption.stCustomRegions[rIdx].nBottom
			<< "]" << std::endl;
	}
}

void print_range(const RANGE& stRange)
{
	std::cout << "[" << stRange.fMin << ", " << stRange.fMax << "] ";
	
	if (stRange.abStep)
	{
		std::cout << "Step: " << stRange.fStep;
	}
	if (stRange.abDefault)
	{
		std::cout << "Default: " << stRange.fDefault;
	}
	std::cout << std::endl;
}

#define PRINT_RANGE(r) \
do \
{\
	std::cout << #r << ": "; print_range(r);\
} while (0)

void input_time(NET_TIME& stTime)
{
	INPUT(stTime.dwYear);
	INPUT(stTime.dwMonth);
	INPUT(stTime.dwDay);
	INPUT(stTime.dwHour);
	INPUT(stTime.dwMinute);
	INPUT(stTime.dwSecond);
}

#define INPUT_TIME(t) \
do \
{\
	std::cout << #t << ": " << std::endl; input_time(t);\
} while (0)

BOOL CALLBACK cbMessCallBack(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	if (lCommand == DH_ALARM_HEATIMG_TEMPER)
	{
		const auto& info = *(ALARM_HEATIMG_TEMPER_INFO*)pBuf; 
		PRINT(info.nAlarmContion);
		PRINT(info.nResult);
		//PRINT(info.nValue);
	}

	std::cout << "cbMessCallBack" << std::endl;

	return TRUE;
}

void CALLBACK cbRadiometryAttachCB(LLONG lAttachHandle, NET_RADIOMETRY_DATA* pBuf, int nBufLen, LDWORD dwUser)
{
	PRINT(pBuf->stMetaData.nLength);
}












bool ParseXml(CFG_RADIOMETRY_RULE_INFO& info)
{
	char* buf = NULL;

	FILE* pFile = fopen("rules.xml", "rb");
	if (pFile == NULL)
	{
		return 0;
	}
	// 从文件结尾，向后偏移0个字节，也就是移到文件结尾
	if (fseek(pFile, 0, SEEK_END) == -1) 
	{
		return 0;
	}
	// 获取当前位置，也就是文件的字节个数
	fpos_t fPos = 0;
	fgetpos(pFile, &fPos);
	// 从文件开头，向后偏移0个字节，也就是移到文件开头
	fseek(pFile, 0, SEEK_SET);
	// 动态分配内存
	buf = (char *)malloc(fPos * sizeof(char)+1);
	memset(buf, 0, fPos * sizeof(char)+1);
	// 把文件流读入到buf中，每次读取一个字节【sizeof(char)】,读取fPos次
	fread(buf, sizeof(char), fPos, pFile);
	fclose(pFile);


	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		int i =0;

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), M_Count) == 0)
			{
				info.nCount = atoi(node->value());
			}
			else if(strcmp(node->name(), M_RadioMetryRule) == 0)
			{
				int j = 0; 
				int k = 0;
				for(xml_node<>* node2 = node->first_node(); node2 != NULL; node2 = node2->next_sibling())
				{
					if (strcmp(node2->name(), M_Enable) == 0)
					{
						info.stRule[i].bEnable = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_PresetId) == 0)
					{
						info.stRule[i].nPresetId = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_RuleId) == 0)
					{
						info.stRule[i].nRuleId = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_Name) == 0)
					{
						strncpy(info.stRule[i].szName, node2->value(),127);
					}
					else if (strcmp(node2->name(), M_MeterType) == 0)
					{
						info.stRule[i].nMeterType = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_CoordinateCnt) == 0)
					{
						info.stRule[i].nCoordinateCnt = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_Point) == 0)
					{
						for(xml_attribute<>* attr = node2->first_attribute();
							attr != NULL; attr= attr->next_attribute())
						{
							if(strcmp(attr->name(), M_Point_X) == 0)
							{
								info.stRule[i].stCoordinates[j].nX = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Point_Y) == 0)
							{
								info.stRule[i].stCoordinates[j].nY = atoi(attr->value());
							}							
						}
						++j;
					}
					else if (strcmp(node2->name(), M_SamplePeriod) == 0)
					{
						info.stRule[i].nSamplePeriod = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_AlarmSetCount) == 0)
					{
						info.stRule[i].nAlarmSettingCnt = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_RadioMetryAlarmSet) == 0)
					{
						for(xml_attribute<>* attr = node2->first_attribute();
							attr != NULL; attr= attr->next_attribute())
						{
							if(strcmp(attr->name(), M_Id) == 0)
							{
								info.stRule[i].stAlarmSetting[k].nId = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Enable) == 0)
							{
								info.stRule[i].stAlarmSetting[k].bEnable = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_ResultType) == 0)
							{
								info.stRule[i].stAlarmSetting[k].nResultType = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_AlarmCondition) == 0)
							{
								info.stRule[i].stAlarmSetting[k].nAlarmCondition = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Threshold) == 0)
							{
								info.stRule[i].stAlarmSetting[k].fThreshold = atof(attr->value());
							}
							else if(strcmp(attr->name(), M_Hysteresis) == 0)
							{
								info.stRule[i].stAlarmSetting[k].fHysteresis = atof(attr->value());
							}
							else if(strcmp(attr->name(), M_Duration) == 0)
							{
								info.stRule[i].stAlarmSetting[k].nDuration = atoi(attr->value());
							}
						}
						++k;
					}
					else if (strcmp(node2->name(), M_RadioMetryLocalParam) == 0)
					{
						for(xml_attribute<>* attr = node2->first_attribute();
							attr != NULL; attr= attr->next_attribute())
						{
							if(strcmp(attr->name(), M_Enable) == 0)
							{
								info.stRule[i].stLocalParameters.bEnable = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_ObjectEmissivity) == 0)
							{
								info.stRule[i].stLocalParameters.fObjectEmissivity = atof(attr->value());
							}
							else if(strcmp(attr->name(), M_ObjectDistance) == 0)
							{
								info.stRule[i].stLocalParameters.nObjectDistance = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_RefalectedTemp) == 0)
							{
								info.stRule[i].stLocalParameters.nRefalectedTemp = atoi(attr->value());
							}
						}
					}					
				}

				++i;
			}
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}



















int main()
{
	NET_RUN(CLIENT_Init, 0, 0);

	section_mark("login device");

	// 254
	char ip[32] = "172.16.4.232", usr[32] = "admin", pwd[32] = "admin";
	int port = 37777;
	
	int err = 0;

	auto loginId = CLIENT_LoginEx(ip, port, usr, pwd, 0, NULL,NULL, &err);
	if (!loginId)
	{
		NETSDK_ERROR(CLIENT_LoginEx);
		press_to_continue();
		return EXIT_FAILURE;
	}

	int chnIndex = 0;

	//int ptzCmd = GetPTZCmd(pduReq->_ptzCmd);
	//int bOK = CLIENT_DHPTZControlEx(loginId, chnIndex, 14,0, 0, 0, 0);


	//int ff = 0;
	//return 0;


	//if (prompt("test Radiometry Notification"))
	//{
	//	int nChannel;
	//	INPUT(nChannel);

	//	NET_IN_RADIOMETRY_ATTACH stIn = {sizeof(stIn), nChannel, cbRadiometryAttachCB};
	//	NET_OUT_RADIOMETRY_ATTACH stOut = {sizeof(stOut)};
	//	auto attachHandle = CLIENT_RadiometryAttach(loginId, &stIn, &stOut, g_waitTime);
	//	if (!attachHandle)
	//	{
	//		NETSDK_ERROR(CLIENT_RadiometryAttach);
	//		press_to_continue();
	//		return EXIT_FAILURE;
	//	}

	//	NET_IN_RADIOMETRY_FETCH stInFetch = {sizeof(stInFetch), nChannel};
	//	NET_OUT_RADIOMETRY_FETCH stOutFetch = {sizeof(stOutFetch)};

	//	NET_RUN(CLIENT_RadiometryFetch, loginId, &stInFetch, &stOutFetch, g_waitTime);
	//	PRINT(stOutFetch.nStatus);

	//	if (prompt("detach"))
	//	{
	//		NET_RUN(CLIENT_RadiometryDetach, attachHandle);
	//	}
	//	
	//	NET_RUN(CLIENT_RadiometryFetch, loginId, &stInFetch, &stOutFetch, g_waitTime);
	//	PRINT(stOutFetch.nStatus);
	//}

	//if (prompt("test NET_THERMO_GRAPHY_CAPS"))
	//{
	//	NET_IN_THERMO_GETCAPS stIn = {sizeof(stIn)};
	//	NET_OUT_THERMO_GETCAPS stOut = {sizeof(stOut)};

	//	INPUT(stIn.nChannel);

	//	NET_RUN(CLIENT_GetDevCaps, loginId, NET_THERMO_GRAPHY_CAPS, &stIn, &stOut, g_waitTime);

	//	PRINT_RANGE(stOut.stBrightness);
	//}

	//if (prompt("test CFG_CMD_THERMO_GRAPHY"))
	//{
	//	int error = 0;
	//	std::string json("json buf");
	//	json.reserve(32*1024);

	//	int nChannel;
	//	INPUT(nChannel);

	//	section_mark_channel(nChannel, "get config");

	//	NET_RUN(CLIENT_GetNewDevConfig, loginId, CFG_CMD_THERMO_GRAPHY, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
	//	CFG_THERMOGRAPHY_INFO stThermoInfo = {0};
	//	_mem_zero(stThermoInfo);

	//	CLIENT_ParseData(CFG_CMD_THERMO_GRAPHY, &json[0], &stThermoInfo, sizeof(stThermoInfo), NULL);
	//	for (auto mIdx = 0; mIdx < stThermoInfo.nModeCount; ++mIdx)
	//	{
	//		print("config for mode ", mIdx) << ":" << std::endl;
	//		const auto& stOption = stThermoInfo.stOptions[mIdx];
	//		
	//		PRINT(stOption.nEZoom);
	//		PRINT(stOption.nColorization);
	//		PRINT(stOption.nSmartOptimizer);
	//		PRINT(stOption.nThermographyGamma);

	//		print_optregion(stOption);
	//	}

	//	section_mark_channel(nChannel, "set config");

	//	INPUT(stThermoInfo.stOptions[nChannel].nEZoom);
	//	INPUT(stThermoInfo.stOptions[nChannel].nColorization);
	//	INPUT(stThermoInfo.stOptions[nChannel].nSmartOptimizer);
	//	INPUT(stThermoInfo.stOptions[nChannel].nThermographyGamma);
	//	
	//	CLIENT_PacketData(CFG_CMD_THERMO_GRAPHY, &stThermoInfo, sizeof(stThermoInfo), &json[0], json.capacity());

	//	NET_RUN(CLIENT_SetNewDevConfig, loginId, CFG_CMD_THERMO_GRAPHY, nChannel, &json[0], json.capacity(), NULL, NULL);
	//}
	//
	//if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_PRESET"))
	//{
	//	NET_IN_THERMO_GET_PRESETINFO stIn = {sizeof(stIn), 0, NET_THERMO_MODE_DEFAULT};
	//	NET_OUT_THERMO_GET_PRESETINFO stOut = {sizeof(stOut)};

	//	INPUT(stIn.nChannel);

	//	NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_PRESET, &stIn, &stOut, NULL, g_waitTime);

	//	const auto& stOption = stOut.stInfo;

	//	PRINT(stOption.nBrightness);
	//	PRINT(stOption.nSharpness);
	//	PRINT(stOption.nEZoom);
	//	PRINT(stOption.nColorization);
	//	PRINT(stOption.nSmartOptimizer);
	//	PRINT(stOption.nThermographyGamma);

	//	print_optregion(stOption.stOptRegion);
	//}

	//if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_OPTREGION"))
	//{
	//	NET_IN_THERMO_GET_OPTREGION stIn = {sizeof(stIn)};
	//	NET_OUT_THERMO_GET_OPTREGION stOut = {sizeof(stOut)};
	//	
	//	INPUT(stIn.nChannel);

	//	NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_OPTREGION, &stIn, &stOut, NULL, g_waitTime);

	//	print_optregion(stOut.stInfo);
	//}

	//if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO"))
	//{
	//	NET_IN_THERMO_GET_EXTSYSINFO stIn = {sizeof(stIn)};
	//	NET_OUT_THERMO_GET_EXTSYSINFO stOut = {sizeof(stOut)};

	//	INPUT(stIn.nChannel);

	//	NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO, &stIn, &stOut, NULL, g_waitTime);
	//	
	//	PRINT(stOut.stInfo.szSerialNumber);
	//	PRINT(stOut.stInfo.szFirmwareVersion);
	//	PRINT(stOut.stInfo.szLibVersion);
	//	PRINT(stOut.stInfo.szSoftwareVersion);

	//}

	//if (prompt("test NET_CTRL_DEV_THERMO_GRAPHY_ENSHUTTER"))
	//{
	//	NET_IN_THERMO_EN_SHUTTER stIn = {sizeof(stIn)};
	//	NET_OUT_THERMO_EN_SHUTTER stOut = {sizeof(stOut)};

	//	INPUT(stIn.bEnable);

	//	NET_RUN(CLIENT_ControlDeviceEx, loginId, DH_CTRL_THERMO_GRAPHY_ENSHUTTER, &stIn, &stOut, g_waitTime);
	//}

	//if (prompt("test NET_RADIOMETRY_CAPS"))
	//{
	//	NET_IN_RADIOMETRY_GETCAPS stIn = {sizeof(stIn)};
	//	NET_OUT_RADIOMETRY_GETCAPS stOut = {sizeof(stOut)};

	//	INPUT(stIn.nChannel);

	//	NET_RUN(CLIENT_GetDevCaps, loginId, NET_RADIOMETRY_CAPS, &stIn, &stOut, g_waitTime);

	//	PRINT_RANGE(stOut.stObjectEmissivity);
	//}

	//if (prompt("test CFG_CMD_THERMOMETRY_RULE"))
	//{

	//	int error = 0;
	//	std::string json("json buf");
	//	json.reserve(1024*1024);

	//	CFG_RADIOMETRY_RULE_INFO* aa = new CFG_RADIOMETRY_RULE_INFO;
	//	CFG_RADIOMETRY_RULE_INFO& stThermometryRuleInfo = *aa;
	//	_mem_zero(stThermometryRuleInfo);

	//	ParseXml(stThermometryRuleInfo);

	//
	//	int nChannel =1;
	//	// 可以设置成功
	//	CLIENT_PacketData(CFG_CMD_THERMOMETRY_RULE, &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), &json[0], json.capacity());
	//	int dd = CLIENT_SetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL,NULL,g_waitTime);
	//
	//	printf("Set Result[%d]",dd);

	//}
	



	//if (prompt("test CFG_CMD_THERMOMETRY_RULE"))
	//{

	//	int error = 0;
	//	std::string json("json buf");
	//	json.reserve(32*1024);

	//	CFG_RADIOMETRY_RULE_INFO* aa = new CFG_RADIOMETRY_RULE_INFO;
	//	CFG_RADIOMETRY_RULE_INFO& stThermometryRuleInfo = *aa;
	//	_mem_zero(stThermometryRuleInfo);

	//	int nChannel =0;
	//	// 获取成功，获取的结果也是对的
	//	int dd = CLIENT_GetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
	//	
	//	printf("Get Result[%d]",dd);
	//	_mem_zero(stThermometryRuleInfo);
	//	CLIENT_ParseData(CFG_CMD_THERMOMETRY_RULE, &json[0], &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), NULL);




		//return ;

		//int totalCount = 65;

		//stThermometryRuleInfo.nCount = totalCount;

		//int count1 = 65;		
		//int nPresetId = 1;

		//for(int i =0; i < count1; ++i)
		//{
		//	CFG_RADIOMETRY_RULE& rule = stThermometryRuleInfo.stRule[i];

		//	rule.bEnable = 1;
		//	rule.nPresetId = nPresetId;
		//	rule.nRuleId = i+1;
		//	sprintf(rule.szName,"dian_%d",i+1);
		//	rule.nMeterType = 1;

		//	rule.nCoordinateCnt = 1;
		//	rule.stCoordinates[0].nX  = 1500;
		//	rule.stCoordinates[0].nY  = 1000+i*500;

		//	rule.nAlarmSettingCnt = 1;
		//	rule.stAlarmSetting[0].nId =0;
		//	rule.stAlarmSetting[0].bEnable =0;
		//	rule.stAlarmSetting[0].nResultType =1;
		//	rule.stAlarmSetting[0].nAlarmCondition =1;
		//	rule.stAlarmSetting[0].fThreshold =20.0;
		//	rule.stAlarmSetting[0].fHysteresis =0.1;
		//	rule.stAlarmSetting[0].nDuration =30;
		//}
		//

		//nPresetId = 2;
		//for(int i =count1; i < totalCount; ++i)
		//{
		//	CFG_RADIOMETRY_RULE& rule = stThermometryRuleInfo.stThermometryRule[i];

		//	rule.bEnable = 1;
		//	rule.nPresetId = nPresetId;
		//	rule.nRuleId = i-3;
		//	sprintf(rule.szName,"dian_%d",i+1);
		//	rule.nMeterType = 1;

		//	rule.nCoordinateCnt = 1;
		//	rule.stCoordinates[0].nX  = 1500;
		//	rule.stCoordinates[0].nY  = 1000+i*500;

		//	//rule.nAlarmSettingCnt = 1;
		//	//rule.stAlarmSetting[0].nId =0;
		//	//rule.stAlarmSetting[0].bEnable =0;
		//	//rule.stAlarmSetting[0].nResultType =1;
		//	//rule.stAlarmSetting[0].nAlarmCondition =1;
		//	//rule.stAlarmSetting[0].fThreshold =20.0;
		//	//rule.stAlarmSetting[0].fHysteresis =0.1;
		//	//rule.stAlarmSetting[0].nDuration =30;
		//}


	//	// 可以设置成功
	//	CLIENT_PacketData(CFG_CMD_THERMOMETRY_RULE, &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), &json[0], json.capacity());
	//	dd = CLIENT_SetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL,NULL,g_waitTime);
	//
	//	printf("Set Result[%d]",dd);

	//}
	

	//if (prompt("test CFG_CMD_THERMOMETRY"))
	{
		int error = 0;
		std::string json("json buf");
		json.reserve(32*1024);

		int nChannel = 1;
		int nPresetId = 1;

		CFG_RADIOMETRY_RULE_INFO* aa = new CFG_RADIOMETRY_RULE_INFO;

		CFG_RADIOMETRY_RULE_INFO& stThermometryRuleInfo = *aa;

		section_mark_channel(nChannel, "set config");
		_mem_zero(stThermometryRuleInfo);
		stThermometryRuleInfo.nCount = 2;
		CFG_RADIOMETRY_RULE& rule = stThermometryRuleInfo.stRule[0];

		rule.bEnable = 1;
		rule.nPresetId = nPresetId;
		rule.nRuleId = 1;
		sprintf(rule.szName,"dian111fff");
		rule.nMeterType = 1;

		rule.nCoordinateCnt = 1;
		rule.stCoordinates[0].nX  = 1500;
		rule.stCoordinates[0].nY  = 2700;

		rule.nAlarmSettingCnt = 1;
		rule.stAlarmSetting[0].nId =0;
		rule.stAlarmSetting[0].bEnable =0;
		rule.stAlarmSetting[0].nResultType =1;
		rule.stAlarmSetting[0].nAlarmCondition =1;
		rule.stAlarmSetting[0].fThreshold =20.0;
		rule.stAlarmSetting[0].fHysteresis =0.1;
		rule.stAlarmSetting[0].nDuration =30;


		CFG_RADIOMETRY_RULE& rule2 = stThermometryRuleInfo.stRule[1];

		rule2.bEnable = 1;
		rule2.nPresetId = nPresetId;
		rule2.nRuleId = 2;
		sprintf(rule2.szName,"xian222ggg");
		rule2.nMeterType = 2;

		rule2.nCoordinateCnt = 2;
		rule2.stCoordinates[0].nX  = 1000;
		rule2.stCoordinates[0].nY  = 1000;
		rule2.stCoordinates[1].nX  = 2000;
		rule2.stCoordinates[1].nY  = 2000;

		rule2.nAlarmSettingCnt = 1;
		rule2.stAlarmSetting[0].nId =0;
		rule2.stAlarmSetting[0].bEnable =0;
		rule2.stAlarmSetting[0].nResultType =1;
		rule2.stAlarmSetting[0].nAlarmCondition =1;
		rule2.stAlarmSetting[0].fThreshold =20.0;
		rule2.stAlarmSetting[0].fHysteresis =0.1;
		rule2.stAlarmSetting[0].nDuration =123;
		//

		int timeOut = 100000;

		int dd = 0;

		//// 获取成功，获取的结果也是对的
		//int dd = CLIENT_GetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
		//
		//printf("Get Result[%d]",dd);
		//_mem_zero(stThermometryRuleInfo);
		//CLIENT_ParseData(CFG_CMD_THERMOMETRY_RULE, &json[0], &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), NULL);


		// 可以设置成功
		CLIENT_PacketData(CFG_CMD_THERMOMETRY_RULE, &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), &json[0], json.capacity());
		dd = CLIENT_SetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL,NULL,timeOut);
	
		printf("Set Result[%d]",dd);

		// 获取成功，获取的结果也是对的
		dd = CLIENT_GetNewDevConfig(loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
		
		printf("Get Result[%d]",dd);
		_mem_zero(stThermometryRuleInfo);
		CLIENT_ParseData(CFG_CMD_THERMOMETRY_RULE, &json[0], &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), NULL);
	}
	

	if (prompt("test CFG_CMD_TEMP_STATISTICS"))
	{
		int error = 0;
		std::string json("json buf");
		json.reserve(32*1024);

		int nChannel;
		INPUT(nChannel);

		section_mark_channel(nChannel, "get config");

		NET_RUN(CLIENT_GetNewDevConfig, loginId, CFG_CMD_TEMP_STATISTICS, nChannel, &json[0], json.capacity(), NULL, g_waitTime);

		CFG_TEMP_STATISTICS_INFO stTempStaticsInfo = {0};
		_mem_zero(stTempStaticsInfo);

		CLIENT_ParseData(CFG_CMD_TEMP_STATISTICS, &json[0], &stTempStaticsInfo, sizeof(stTempStaticsInfo), NULL);

		for (int i(0); i < stTempStaticsInfo.nCount; ++i)
		{
			const auto& stStatistics = stTempStaticsInfo.stStatistics[i];

			PRINT(stStatistics.szName);
			PRINT(stStatistics.bEnable);
			PRINT(stStatistics.nMeterType);
			PRINT(stStatistics.nPeriod);
		}

		section_mark_channel(nChannel, "set config");

		for (int i(0); i < stTempStaticsInfo.nCount; ++i)
		{
			auto& stStatistics = stTempStaticsInfo.stStatistics[i];

			PRINT(stStatistics.szName);
			INPUT(stStatistics.bEnable);
			INPUT(stStatistics.nMeterType);
			INPUT(stStatistics.nPeriod);
		}

		CLIENT_PacketData(CFG_CMD_TEMP_STATISTICS, &stTempStaticsInfo, sizeof(stTempStaticsInfo), &json[0], json.capacity());

		NET_RUN(CLIENT_SetNewDevConfig, loginId, CFG_CMD_TEMP_STATISTICS, nChannel, &json[0], json.capacity(), NULL, NULL);
		
	}

	if (prompt("test NET_QUERY_DEV_RADIOMETRY_POINT_TEMPER"))
	{
		NET_IN_RADIOMETRY_GETPOINTTEMPER stIn = {sizeof(stIn)};
		NET_OUT_RADIOMETRY_GETPOINTTEMPER stOut = {sizeof(stOut)};

		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_RADIOMETRY_POINT_TEMPER, &stIn, &stOut, NULL, g_waitTime);

		PRINT(stOut.stPointTempInfo.fTemperAver);
	}

	if (prompt("test NET_QUERY_DEV_RADIOMETRY_TEMPER"))
	{
		NET_IN_RADIOMETRY_GETTEMPER stIn = {sizeof(stIn)};
		auto& stCondition = stIn.stCondition;
		INPUT(stCondition.nChannel);
		INPUT(stCondition.nMeterType);
		INPUT(stCondition.nPresetId);
		INPUT(stCondition.nRuleId);
		INPUT(stCondition.szName);

		NET_OUT_RADIOMETRY_GETTEMPER stOut = {sizeof(stOut)};

		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_RADIOMETRY_TEMPER, &stIn, &stOut, NULL, g_waitTime);
		PRINT(stOut.stTempInfo.fTemperAver);
	}

	if (prompt("test NET_CTRL_DEV_RADIOMETRY_SETOSDMARK"))
	{
		NET_IN_RADIOMETRY_SETOSDMARK stIn = {sizeof(stIn)};
		NET_OUT_RADIOMETRY_SETOSDMARK stOut = {sizeof(stOut)};

		auto& stCondition = stIn.stCondition;
		INPUT(stCondition.nChannel);
		INPUT(stCondition.nMeterType);
		INPUT(stCondition.nPresetId);
		INPUT(stCondition.nRuleId);
		INPUT(stCondition.szName);

		NET_RUN(CLIENT_ControlDeviceEx, loginId, DH_CTRL_RADIOMETRY_SETOSDMARK, &stIn, &stOut, g_waitTime);
	}

	if (prompt("test NET_FIND_RADIOMETRY"))
	{
		NET_IN_RADIOMETRY_STARTFIND stInStart = {sizeof(stInStart)};
		NET_OUT_RADIOMETRY_STARTFIND stOutStart = {sizeof(stOutStart)};

		INPUT(stInStart.nChannel);
		INPUT(stInStart.nMeterType);
		INPUT_TIME(stInStart.stStartTime);
		INPUT_TIME(stInStart.stEndTime);
		
		NET_RUN(CLIENT_StartFind, loginId, NET_FIND_RADIOMETRY, &stInStart, &stOutStart, g_waitTime);

		NET_IN_RADIOMETRY_DOFIND stInDo = {sizeof(stInDo), stOutStart.nFinderHanle, 0, 1};
		NET_OUT_RADIOMETRY_DOFIND stOutDo = {sizeof(stOutDo)};

		NET_RUN(CLIENT_DoFind, loginId, NET_FIND_RADIOMETRY, &stInDo, &stOutDo, g_waitTime);

		NET_IN_RADIOMETRY_STOPFIND stInStop = {sizeof(stInStop), stOutStart.nFinderHanle};
		NET_OUT_RADIOMETRY_STOPFIND stOutStop = {sizeof(stOutStop)};

		NET_RUN(CLIENT_StopFind, loginId, NET_FIND_RADIOMETRY, &stInStop, &stOutStop, g_waitTime);
	}

	if (prompt("test DH_ALARM_HEATIMG_TEMPER"))
	{
		CLIENT_SetDVRMessCallBack(cbMessCallBack, NULL);

		NET_RUN(CLIENT_StartListenEx, loginId);

		if (prompt("Stop Listen"))
		{
			NET_RUN(CLIENT_StopListen, loginId);
		}
	}

	press_to_continue();
	return 0;
}

