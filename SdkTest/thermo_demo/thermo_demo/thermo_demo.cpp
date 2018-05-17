// thermo_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include/include.h"
#include <memory>

#pragma comment(lib, "../bin/dhnetsdk.lib")
#pragma comment(lib, "../bin/dhconfigsdk.lib")

const auto g_waitTime = 3000;

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
		PRINT(info.nValue);
	}

	std::cout << "cbMessCallBack" << std::endl;

	return TRUE;
}

void CALLBACK cbRadiometryAttachCB(LLONG lAttachHandle, NET_RADIOMETRY_DATA* pBuf, int nBufLen, LDWORD dwUser)
{
	PRINT(pBuf->stMetaData.nLength);
}


int main()
{
	NET_RUN(CLIENT_Init, 0, 0);

	section_mark("login device");

	//char ip[32] = "172.16.4.230", usr[32] = "admin", pwd[32] = "admin";
	char ip[32] = "172.27.2.176", usr[32] = "admin", pwd[32] = "admin";
	//char ip[32] = "172.27.2.254", usr[32] = "admin", pwd[32] = "admin";
	//char ip[32] = "172.27.2.196", usr[32] = "admin", pwd[32] = "admin";
	int port = 37777;

	//INPUT(ip);
	//INPUT(port);
	//INPUT(usr);
	//INPUT(pwd);

	auto loginId = CLIENT_LoginEx(ip, port, usr, pwd, 0, NULL, NULL);
	if (!loginId)
	{
		NETSDK_ERROR(CLIENT_LoginEx);
		press_to_continue();
		return EXIT_FAILURE;
	}

	//typedef void (CALLBACK *fRadiometryAttachCB)(LLONG lAttachHandle, NET_RADIOMETRY_DATA* pBuf, int nBufLen, LDWORD dwUser);

	/*if (prompt("test Radiometry Notification"))
	{
		NET_IN_RADIOMETRY_FETCH stInFetch = {sizeof(stInFetch)};
		NET_OUT_RADIOMETRY_FETCH stOutFetch = {sizeof(stOutFetch)};

		//NET_RUN(CLIENT_RadiometryFetch, loginId, &stInFetch, &stOutFetch, g_waitTime);
		//PRINT(stOutFetch.nStatus);

		NET_IN_RADIOMETRY_ATTACH stIn = {sizeof(stIn)};
		NET_OUT_RADIOMETRY_ATTACH stOut = {sizeof(stOut)};
		stIn.nChannel = 1;
		stIn.cbNotify = cbRadiometryAttachCB;
		auto attachHandle = CLIENT_RadiometryAttach(loginId, &stIn, &stOut, g_waitTime);
		if (!attachHandle)
		{
			NETSDK_ERROR(func);
			press_to_continue();
			return EXIT_FAILURE;
		}
		stInFetch.nChannel = 1;
		NET_RUN(CLIENT_RadiometryFetch, loginId, &stInFetch, &stOutFetch, g_waitTime);
		PRINT(stOutFetch.nStatus);

		getchar();

		//if (prompt("detach"))
		//{
		//	NET_RUN(CLIENT_RadiometryDetach, attachHandle);
		//}
		//
		//NET_RUN(CLIENT_RadiometryFetch, loginId, &stInFetch, &stOutFetch, g_waitTime);
		//PRINT(stOutFetch.nStatus);
	}
	*/

	/*if (prompt("test NET_THERMO_GRAPHY_CAPS"))
	{
		NET_IN_THERMO_GETCAPS stIn = {sizeof(stIn)};
		NET_OUT_THERMO_GETCAPS stOut = {sizeof(stOut)};

		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_GetDevCaps, loginId, NET_THERMO_GRAPHY_CAPS, &stIn, &stOut, g_waitTime);

		PRINT_RANGE(stOut.stBrightness);
	}

	if (prompt("test CFG_CMD_THERMO_GRAPHY"))
	{
		int error = 0;
		std::string json("json buf");
		json.reserve(32*1024);

		int nChannel;
		INPUT(nChannel);

		section_mark_channel(nChannel, "get config");

		NET_RUN(CLIENT_GetNewDevConfig, loginId, CFG_CMD_THERMO_GRAPHY, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
		CFG_THERMOGRAPHY_INFO stThermoInfo = {0};
		_mem_zero(stThermoInfo);

		CLIENT_ParseData(CFG_CMD_THERMO_GRAPHY, &json[0], &stThermoInfo, sizeof(stThermoInfo), NULL);
		for (auto mIdx = 0; mIdx < stThermoInfo.nModeCount; ++mIdx)
		{
			print("config for mode ", mIdx) << ":" << std::endl;
			const auto& stOption = stThermoInfo.stOptions[mIdx];
			
			PRINT(stOption.nEZoom);
			PRINT(stOption.nColorization);
			PRINT(stOption.nSmartOptimizer);
			PRINT(stOption.nThermographyGamma);

			print_optregion(stOption);
		}

		section_mark_channel(nChannel, "set config");

		INPUT(stThermoInfo.stOptions[nChannel].nEZoom);
		INPUT(stThermoInfo.stOptions[nChannel].nColorization);
		INPUT(stThermoInfo.stOptions[nChannel].nSmartOptimizer);
		INPUT(stThermoInfo.stOptions[nChannel].nThermographyGamma);
		
		CLIENT_PacketData(CFG_CMD_THERMO_GRAPHY, &stThermoInfo, sizeof(stThermoInfo), &json[0], json.capacity());

		NET_RUN(CLIENT_SetNewDevConfig, loginId, CFG_CMD_THERMO_GRAPHY, nChannel, &json[0], json.capacity(), NULL, NULL);
	}
	
	if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_PRESET"))
	{
		NET_IN_THERMO_GET_PRESETINFO stIn = {sizeof(stIn), 0, NET_THERMO_MODE_DEFAULT};
		NET_OUT_THERMO_GET_PRESETINFO stOut = {sizeof(stOut)};

		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_PRESET, &stIn, &stOut, NULL, g_waitTime);

		const auto& stOption = stOut.stInfo;

		PRINT(stOption.nBrightness);
		PRINT(stOption.nSharpness);
		PRINT(stOption.nEZoom);
		PRINT(stOption.nColorization);
		PRINT(stOption.nSmartOptimizer);
		PRINT(stOption.nThermographyGamma);

		print_optregion(stOption.stOptRegion);
	}

	if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_OPTREGION"))
	{
		NET_IN_THERMO_GET_OPTREGION stIn = {sizeof(stIn)};
		NET_OUT_THERMO_GET_OPTREGION stOut = {sizeof(stOut)};
		
		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_OPTREGION, &stIn, &stOut, NULL, g_waitTime);

		print_optregion(stOut.stInfo);
	}

	if (prompt("test NET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO"))
	{
		NET_IN_THERMO_GET_EXTSYSINFO stIn = {sizeof(stIn)};
		NET_OUT_THERMO_GET_EXTSYSINFO stOut = {sizeof(stOut)};

		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO, &stIn, &stOut, NULL, g_waitTime);
		
		PRINT(stOut.stInfo.szSerialNumber);
		PRINT(stOut.stInfo.szFirmwareVersion);
		PRINT(stOut.stInfo.szLibVersion);
		PRINT(stOut.stInfo.szSoftwareVersion);

	}

	if (prompt("test NET_CTRL_DEV_THERMO_GRAPHY_ENSHUTTER"))
	{
		NET_IN_THERMO_EN_SHUTTER stIn = {sizeof(stIn)};
		NET_OUT_THERMO_EN_SHUTTER stOut = {sizeof(stOut)};

		INPUT(stIn.bEnable);

		NET_RUN(CLIENT_ControlDeviceEx, loginId, DH_CTRL_THERMO_GRAPHY_ENSHUTTER, &stIn, &stOut, g_waitTime);
	}

	if (prompt("test NET_RADIOMETRY_CAPS"))
	{
		NET_IN_RADIOMETRY_GETCAPS stIn = {sizeof(stIn)};
		NET_OUT_RADIOMETRY_GETCAPS stOut = {sizeof(stOut)};

		INPUT(stIn.nChannel);

		NET_RUN(CLIENT_GetDevCaps, loginId, NET_RADIOMETRY_CAPS, &stIn, &stOut, g_waitTime);

		PRINT_RANGE(stOut.stObjectEmissivity);
	}
	*/
	//if (prompt("test CFG_CMD_THERMOMETRY_RULE"))
	{

		int error = 0;
		std::string json("json buf");
		json.reserve(32*1024);

		int nChannel = 1;
		int nPresetId = 0;

		CFG_THERMOMETRY_RULE_INFO stThermometryRuleInfo = {0};

		//section_mark_channel(nChannel, "set config");
		//_mem_zero(stThermometryRuleInfo);
		//stThermometryRuleInfo.nCount = 2;
		//CFG_RADIOMETRY_RULE& rule = stThermometryRuleInfo.stThermometryRule[0];

		//rule.bEnable = 1;
		//rule.nPresetId = nPresetId;
		//rule.nRuleId = 1;
		//sprintf(rule.szName,"点点点");
		//rule.nMeterType = 1;

		//rule.nCoordinateCnt = 1;
		//rule.stCoordinates[0].nX  = 1500;
		//rule.stCoordinates[0].nY  = 2700;

		//CFG_RADIOMETRY_RULE& rule2 = stThermometryRuleInfo.stThermometryRule[1];

		//rule2.bEnable = 1;
		//rule2.nPresetId = nPresetId;
		//rule2.nRuleId = 2;
		//sprintf(rule2.szName,"张飞n");
		//rule2.nMeterType = 2;

		//rule2.nCoordinateCnt = 2;
		//rule2.stCoordinates[0].nX  = 1000;
		//rule2.stCoordinates[0].nY  = 1000;
		//rule2.stCoordinates[1].nX  = 2000;
		//rule2.stCoordinates[1].nY  = 2000;

		// 可以设置成功
		//CLIENT_PacketData(CFG_CMD_THERMOMETRY_RULE, &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), &json[0], json.capacity());
		//NET_RUN(CLIENT_SetNewDevConfig, loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL, NULL);
	
		// 获取成功，获取的结果也是对的
		NET_RUN(CLIENT_GetNewDevConfig, loginId, CFG_CMD_THERMOMETRY_RULE, nChannel, &json[0], json.capacity(), NULL, g_waitTime);
		_mem_zero(stThermometryRuleInfo);
		CLIENT_ParseData(CFG_CMD_THERMOMETRY_RULE, &json[0], &stThermometryRuleInfo, sizeof(stThermometryRuleInfo), NULL);


		// 获取测温对象的温度
		NET_IN_RADIOMETRY_GETTEMPER stIn = {sizeof(stIn)};
		NET_OUT_RADIOMETRY_GETTEMPER stOut = {sizeof(stOut)};

		for(int i =0; i< stThermometryRuleInfo.nCount; ++i)
		{
			stIn.stCondition.nChannel = nChannel;
			stIn.stCondition.nMeterType = stThermometryRuleInfo.stThermometryRule[i].nMeterType;
			stIn.stCondition.nPresetId = stThermometryRuleInfo.stThermometryRule[i].nPresetId;
			stIn.stCondition.nRuleId = stThermometryRuleInfo.stThermometryRule[i].nRuleId;
			//sprintf(stIn.stCondition.szName,stThermometryRuleInfo.stThermometryRule[i].szName);

			// 返回成功，但是温度的值都是 0
		
			NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_RADIOMETRY_TEMPER, &stIn, &stOut, NULL, g_waitTime);
			PRINT(stOut.stTempInfo.nTemperAver);
		}
		
		NET_IN_RADIOMETRY_GETPOINTTEMPER stIn2 ;
		NET_OUT_RADIOMETRY_GETPOINTTEMPER stOut2 ;

		stIn2.nChannel =nChannel;
		stIn2.stCoordinate.nx = 1500;
		stIn2.stCoordinate.ny = 2700;

		// 返回成功，可以获取温度
		NET_RUN(CLIENT_QueryDevInfo, loginId, NET_QUERY_DEV_RADIOMETRY_POINT_TEMPER, &stIn2, &stOut2, NULL, g_waitTime);
		PRINT(stOut2.stPointTempInfo.nTemperAver);
	}

	if (prompt("test CFG_CMD_THERMOMETRY"))
	{
		int error = 0;
		std::string json("json buf");
		json.reserve(32*1024);

		int nChannel;
		INPUT(nChannel);

		section_mark_channel(nChannel, "get config");

		NET_RUN(CLIENT_GetNewDevConfig, loginId, CFG_CMD_THERMOMETRY, nChannel, &json[0], json.capacity(), NULL, g_waitTime);

		CFG_THERMOMETRY_INFO stThermometryInfo = {0};
		_mem_zero(stThermometryInfo);

		CLIENT_ParseData(CFG_CMD_THERMOMETRY, &json[0], &stThermometryInfo, sizeof(stThermometryInfo), NULL);

		PRINT(stThermometryInfo.nAtmosphericTemperature);
		PRINT(stThermometryInfo.nObjectDistance);
		PRINT(stThermometryInfo.nObjectEmissivity);
		PRINT(stThermometryInfo.nReflectedTemperature);
		PRINT(stThermometryInfo.nRelativeHumidity);
		PRINT(stThermometryInfo.nTemperatureUnit);
		PRINT(stThermometryInfo.bIsothermEnable);
		PRINT(stThermometryInfo.bColorBarDisplay);

		section_mark_channel(nChannel, "set config");

		INPUT(stThermometryInfo.nAtmosphericTemperature);

		CLIENT_PacketData(CFG_CMD_THERMOMETRY, &stThermometryInfo, sizeof(stThermometryInfo), &json[0], json.capacity());

		NET_RUN(CLIENT_SetNewDevConfig, loginId, CFG_CMD_THERMOMETRY, nChannel, &json[0], json.capacity(), NULL, NULL);
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

		PRINT(stOut.stPointTempInfo.nTemperAver);
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
		PRINT(stOut.stTempInfo.nTemperAver);
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

