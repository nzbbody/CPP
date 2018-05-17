#include "xml_utils.h"
#define M_Size				"size"
#define M_Modes				"modes"
#define M_Colorization		"colorization"
#define M_RoiModes			"roimodes"
#define M_Brightness		"brightness"
#define M_Sharpness			"sharpness"
#define M_EZoom				"ezoom"
#define M_ThermoGraphyGamma	"thermographygamma"
#define M_SmartOptimizer	"smartoptimizer"

#define M_Max				"max"
#define M_Min				"min"
#define M_IsStep			"isstep"
#define M_Step				"step"
#define M_IsDefault			"isdefault"
#define M_Default			"default"
#define M_Reserved			"reserved"

#define M_ThermoGraphyInfo		"thermographyinfo"
#define M_ThermoGraphyOptRegion	"thermographyoptregion"

#define M_IsOptimizedRegion		"isoptimizedregion"
#define M_OptimizedROIType		"optimizedroitype"
#define M_CustomRegion			"customregion"
#define M_Rectangle				"rectangle"

#define M_Left		"left"
#define M_Right		"right"
#define M_Top		"top"
#define M_Bottom	"bottom"

#define M_ThermoSysInfo		"thermosysinfo"
#define M_SerialNumber		"serialnumber"
#define M_SoftwareVersion	"softwareversion"
#define M_FirmwareVersion	"firmwareversion"
#define M_LibVersion		"libversion"

#define M_RadioMetryInfo	"radiometryinfo"
#define M_MeterType			"metertype"
#define M_TemperAver		"temperaver"
#define M_TemperMax			"tempermax"
#define M_TemperMin			"tempermin"
#define M_TemperMid			"tempermid"
#define M_TemperStd			"temperstd"

#define M_Point				"point"
#define M_Point_X			"x"
#define M_Point_Y			"y"

#define M_PresetId			"presetid"
#define M_RuleId			"ruleid"
#define M_MeterType			"metertype"
#define M_ItemName			"itemname"

#define M_Enable			"enable"
#define M_Name				"name"

#define M_ModeCount				"modecount"
#define M_ThermoGraphyOption	"thermographyoption"

#define M_Count					"count"
#define M_RadioMetryRule		"radiometryrule"
#define M_CoordinateCnt			"coordinatecount"
#define M_RadioMetryAlarmSet	"radiometryalarmset"
#define M_AlarmSetCount			"alarmsetcount"
#define M_SamplePeriod			"sampleperiod"

#define M_Id					"id"
#define M_ResultType			"resulttype"
#define M_AlarmCondition		"alarmcondition"
#define M_Threshold				"threshold"
#define M_Hysteresis			"hysteresis"
#define M_Duration				"duration"

#define M_RadioMetryLocalParam		"radiometrylocalparam"
#define M_ObjectEmissivity			"objectemissivity"
#define M_ObjectDistance			"objectdistance"
#define M_RefalectedTemp			"refalectedtemp"

#define M_RelativeHumidity			"relativehumidity"
#define M_AtmosphericTemperature	"atmospherictemperature"
#define M_ReflectedTemperature		"reflectedtemperature"
#define M_TemperatureUnit			"temperatureunit"
#define M_IsothermEnable			"isothermenable"
#define M_ColorBarMax				"colorbarmax"
#define M_ColorBarMin				"colorbarmin"
#define M_ColorBarDisplay			"colorbardisplay"
#define M_HotSpotFollow				"hotspotfollow"
#define M_TemperEnable				"temperenable"

#define M_TempStatistics		"tempstatistics"
#define M_Period				"period"








#define READ_TXT_TO_BUF 	fseek(fp, 0, SEEK_END);\
	fpos_t fPos = 0;\
	fgetpos(fp, &fPos);\
	fseek(fp, 0, SEEK_SET);\
	char* buf = (char *)malloc(fPos * sizeof(char));\
	memset(buf, 0, fPos * sizeof(char));\
	fread(buf, 1, fPos, fp);\
	fclose(fp);

using namespace rapidxml;

/*
bool XmlUtils::ParseXml(CFG_THERMO_GRAPHY_INFO& info)
{
	FILE* fp = fopen("../testxml/0.txt","r");
	READ_TXT_TO_BUF
	
	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		int i =0;
		
		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), M_ModeCount) == 0)
			{
				info.nModeCount = atoi(node->value());
			}
			else if(strcmp(node->name(), M_ThermoGraphyOption) == 0)
			{	
				int j =0;
				for(xml_node<>* node2 = node->first_node(); node2 != NULL; node2 = node2->next_sibling())
				{
					if (strcmp(node2->name(), M_EZoom) == 0)
					{
						info.stOptions[i].nEZoom = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_ThermoGraphyGamma) == 0)
					{
						info.stOptions[i].nThermographyGamma = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_Colorization) == 0)
					{
						info.stOptions[i].nColorization = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_SmartOptimizer) == 0)
					{
						info.stOptions[i].nSmartOptimizer = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_IsOptimizedRegion) == 0)
					{
						info.stOptions[i].bOptimizedRegion = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_OptimizedROIType) == 0)
					{
						info.stOptions[i].nOptimizedROIType = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_CustomRegion) == 0)
					{
						info.stOptions[i].nCustomRegion = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_Rectangle) == 0)
					{
						for(xml_attribute<>* attr = node2->first_attribute();
							attr != NULL; attr= attr->next_attribute())
						{
							if(strcmp(attr->name(), M_Left) == 0)
							{
								info.stOptions[i].stCustomRegions[j].nLeft = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Right) == 0)
							{
								info.stOptions[i].stCustomRegions[j].nRight = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Top) == 0)
							{
								info.stOptions[i].stCustomRegions[j].nTop = atoi(attr->value());
							}
							else if(strcmp(attr->name(), M_Bottom) == 0)
							{
								info.stOptions[i].stCustomRegions[j].nBottom = atoi(attr->value());
							}
						}
						++j;
					}
					else if (strcmp(node2->name(), M_Reserved) == 0)
					{
						strncpy(info.stOptions[i].Reserved,node2->value(),63);
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
*/

bool XmlUtils::ParseXml(CFG_RADIOMETRY_RULE_INFO& info)
{
	//FILE* fp = fopen("../testxml/rules.xml","r");
	//READ_TXT_TO_BUF

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

bool XmlUtils::ParseXml(CFG_TEMP_STATISTICS_INFO& info)
{
	FILE* fp = fopen("../testxml/2.txt","r");
	READ_TXT_TO_BUF

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
			else if(strcmp(node->name(), M_TempStatistics) == 0)
			{				
				for(xml_node<>* node2 = node->first_node(); node2 != NULL; node2 = node2->next_sibling())
				{
					if (strcmp(node2->name(), M_Enable) == 0)
					{
						info.stStatistics[i].bEnable = atoi(node2->value());
					}	
					else if (strcmp(node2->name(), M_Name) == 0)
					{
						strncpy(info.stStatistics[i].szName,node2->value(),127);
					}
					else if (strcmp(node2->name(), M_MeterType) == 0)
					{
						info.stStatistics[i].nMeterType = atoi(node2->value());
					}
					else if (strcmp(node2->name(), M_Period) == 0)
					{
						info.stStatistics[i].nPeriod = atoi(node2->value());
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


bool XmlUtils::ParseXml(CFG_THERMOMETRY_INFO& info)
{
	FILE* fp = fopen("../testxml/3.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), M_RelativeHumidity) == 0)
			{
				info.nRelativeHumidity = atoi(node->value());
			}
			else if (strcmp(node->name(), M_AtmosphericTemperature) == 0)
			{
				info.fAtmosphericTemperature = atof(node->value());
			}
			else if (strcmp(node->name(), M_ObjectEmissivity) == 0)
			{
				info.fObjectEmissivity = atof(node->value());
			}
			else if (strcmp(node->name(), M_ObjectDistance) == 0)
			{
				info.nObjectDistance = atoi(node->value());
			}
			else if (strcmp(node->name(), M_ReflectedTemperature) == 0)
			{
				info.fReflectedTemperature = atof(node->value());
			}
			else if (strcmp(node->name(), M_TemperatureUnit) == 0)
			{
				info.nTemperatureUnit = atoi(node->value());
			}
			else if (strcmp(node->name(), M_IsothermEnable) == 0)
			{
				info.bIsothermEnable = atoi(node->value());
			}
			//else if (strcmp(node->name(), M_ColorBarMax) == 0)
			//{
			//	info.fColorBarMax = atof(node->value());
			//}
			//else if (strcmp(node->name(), M_ColorBarMin) == 0)
			//{
			//	info.nColorBarMin = atoi(node->value());
			//}
			else if (strcmp(node->name(), M_ColorBarDisplay) == 0)
			{
				info.bColorBarDisplay = atoi(node->value());
			}
			else if (strcmp(node->name(), M_HotSpotFollow) == 0)
			{
				info.bHotSpotFollow = atoi(node->value());
			}
			else if (strcmp(node->name(), M_TemperEnable) == 0)
			{
				info.bTemperEnable = atoi(node->value());
			}
		}
	}
	catch(...)
	{
		return false;
	}

	return true;

}



bool XmlUtils::ParseXml(vector<IisPoint>& vecIisPoint)
{
	FILE* fp = fopen("../testxml/4.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), IBP_TAG_POINT) == 0)
			{
				IisPoint iisPoint;
				parseIisPoint(node,iisPoint);
				vecIisPoint.push_back(iisPoint);
			}			
		}
	}
	catch(...)
	{
		return false;
	}

	return true;	
}

bool XmlUtils::ParseXml(vector<IisTask>& vecIisTask)
{
	FILE* fp = fopen("../testxml/5.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), IBP_TAG_TASK) == 0)
			{
				IisTask iisTask;
				parseIisTask(node,iisTask);
				vecIisTask.push_back(iisTask);
			}			
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}

bool XmlUtils::ParseXml(vector<IisPlan>& vecIisPlan)
{
	FILE* fp = fopen("../testxml/6.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), IBP_TAG_PLAN) == 0)
			{
				IisPlan iisPlan;
				parseIisPlan(node,iisPlan);
				vecIisPlan.push_back(iisPlan);
			}			
		}
	}
	catch(...)
	{
		return false;
	}

	return true;

}

bool XmlUtils::parseIisTimeTemplate(rapidxml::xml_node<>* node,IisTimeTemplate& iisTimeTemplate)
{
	for(xml_attribute<>* attr = node->first_attribute();attr != NULL; attr= attr->next_attribute())
	{
		if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
		{
			iisTimeTemplate._OptFlag = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
		{
			iisTimeTemplate._TimeTemplateId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_TYPE) == 0)
		{
			iisTimeTemplate._TimeTemplateType = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_DESC) == 0)
		{
			iisTimeTemplate._Desc = attr->value();
		}
	}

	for(xml_node<>* child = node->first_node(); child != NULL; child = child->next_sibling())
	{
		if(strcmp(child->name(), IBP_TAG_CONFIG) == 0)
		{
			internal::print_element_node(std::back_inserter(iisTimeTemplate._Config), child, 0,0);
		}
	}
	return true;
	
}


bool XmlUtils::parseIisPlan(rapidxml::xml_node<>* node,IisPlan& iisPlan)
{
	for(xml_attribute<>* attr = node->first_attribute();attr != NULL; attr= attr->next_attribute())
	{
		if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
		{
			iisPlan._OptFlag = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
		{
			iisPlan._PlanId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_TIMETEMPLATEID) == 0)
		{
			iisPlan._TimeTemplateId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_INTERVAL) == 0)
		{
			iisPlan._Interval = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_INTPARAM1) == 0)
		{
			iisPlan._IntParam1 = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_STRPARAM1) == 0)
		{
			iisPlan._StrParam1 = attr->value();
		}
		else if(strcmp(attr->name(), IBP_TAG_DESC) == 0)
		{
			iisPlan._Desc = attr->value();
		}
	}

	for(xml_node<>* child = node->first_node(); child != NULL; child = child->next_sibling())
	{
		if(strcmp(child->name(), IBP_TAG_TASK) == 0)
		{
			IisTask iisTask;
			parseIisTask(child,iisTask);
			iisPlan._VecTask.push_back(iisTask);
		}
		else if(strcmp(child->name(), IBP_TAG_TIMETEMPLATE) == 0)
		{
			parseIisTimeTemplate(child,iisPlan._IisTimeTemplate);
		}
	}
	return true;
}

bool XmlUtils::parseIisTask(rapidxml::xml_node<>* node,IisTask& iisTask)
{
	for(xml_attribute<>* attr = node->first_attribute();attr != NULL; attr= attr->next_attribute())
	{
		if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
		{
			iisTask._OptFlag = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
		{
			iisTask._TaskId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_SEQ_ID) == 0)
		{
			iisTask._SeqId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_NAME) == 0)
		{
			iisTask._TaskName = attr->value();
		}
		else if(strcmp(attr->name(), IBP_TAG_TYPE) == 0)
		{
			iisTask._TaskType = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_TARGETCODE) == 0)
		{
			iisTask._TargetCode = attr->value();
		}
		else if(strcmp(attr->name(), IBP_TAG_STATUS) == 0)
		{
			iisTask._Status = atoi(attr->value());
		}
	}

	for(xml_node<>* child = node->first_node(); child != NULL; child = child->next_sibling())
	{
		if(strcmp(child->name(), IBP_TAG_POINT) == 0)
		{
			IisPoint iisPoint;
			parseIisPoint(child,iisPoint);
			iisTask._VecPoint.push_back(iisPoint);
		}
	}
	return true;

}

bool XmlUtils::parseIisPoint(xml_node<>* node,IisPoint& iisPoint)
{
	for(xml_attribute<>* attr = node->first_attribute();attr != NULL; attr= attr->next_attribute())
	{
		if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
		{
			iisPoint._OptFlag = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
		{
			iisPoint._PointId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_SEQ_ID) == 0)
		{
			iisPoint._SeqId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_NAME) == 0)
		{
			iisPoint._PointName = attr->value();
		}
		else if(strcmp(attr->name(), IBP_TAG_TARGETCODE) == 0)
		{
			iisPoint._TargetCode = attr->value();
		}
		else if(strcmp(attr->name(), IBP_TAG_TYPE) == 0)
		{
			iisPoint._AnalyseType = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_STAYTIME) == 0)
		{
			iisPoint._StayTime = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_DESC) == 0)
		{
			iisPoint._Desc = attr->value();
		}
	}

	for(xml_node<>* child = node->first_node(); child != NULL; child = child->next_sibling())
	{
		if(strcmp(child->name(), IBP_TAG_ACTION) == 0)
		{
			IisAction iisAction;
			parseIisAction(child,iisAction);
			iisPoint._VecAction.push_back(iisAction);
		}
	}
	return true;
}

bool XmlUtils::parseIisAction(xml_node<>* node,IisAction& iisAction)
{
	for(xml_attribute<>* attr = node->first_attribute();attr != NULL; attr= attr->next_attribute())
	{
		if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
		{
			iisAction._OptFlag = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
		{
			iisAction._ActionId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_SEQ_ID) == 0)
		{
			iisAction._SeqId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_TYPE) == 0)
		{
			iisAction._ActionTypeId = atoi(attr->value());
		}
		else if(strcmp(attr->name(), IBP_TAG_DESC) == 0)
		{
			iisAction._Desc = attr->value();
		}
	}

	return true;
}


bool XmlUtils::ParseXml(vector<IrArea>& vecIrArea)
{
	FILE* fp = fopen("../testxml/7.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if (strcmp(node->name(), "radiometryrule") == 0)
			{
				IrArea irArea;
				parseIrArea(node,irArea);
				vecIrArea.push_back(irArea);
			}			
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}


bool XmlUtils::parseIrArea(rapidxml::xml_node<>* node,IrArea& irArea)
{
	for(xml_node<>* child = node->first_node(); child != NULL; child = child->next_sibling())
	{
		if(strcmp(child->name(), "ruleid") == 0)
		{
			irArea._RuleId = atoi(child->value());
		}
		else if(strcmp(child->name(), "name") == 0)
		{
			irArea._Name = child->value();
		}
		else if(strcmp(child->name(), "metertype") == 0)
		{
			irArea._Type = atoi(child->value());			
		}
	}

	internal::print_element_node(std::back_inserter(irArea._Content), node, 0,0);


	return true;
}


bool XmlUtils::ParseXml(vector<IisPlanTimeTemplate>& vecPlanTime)
{
	FILE* fp = fopen("../testxml/8.txt","r");
	READ_TXT_TO_BUF

	try
	{
		xml_document<> doc;
		doc.parse<0>(buf);
		xml_node<>* root = doc.first_node();

		for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			if(strcmp(node->name(), IBP_TAG_PLAN) == 0)
			{
				IisPlanTimeTemplate planTime;

				// 解析Attri
				for(xml_attribute<>* attr = node->first_attribute();
					attr != NULL; attr= attr->next_attribute())
				{
					if(strcmp(attr->name(), IBP_TAG_ID) == 0)
					{
						planTime._PlanId = atoi(attr->value());
					}
					else if(strcmp(attr->name(), IBP_TAG_TITLE) == 0)
					{
						planTime._Name = attr->value();
					}
					else if(strcmp(attr->name(), IBP_TAG_TITLE) == 0)
					{
						planTime._Desc = attr->value();
					}
				}



				// 解析timetemplate
				for(xml_node<>* child = node->first_node(); 
					child != NULL; child = child->next_sibling())
				{
					if(strcmp(child->name(), IBP_TAG_TIMETEMPLATE) == 0)
					{
						for(xml_attribute<>* attr = node->first_attribute();
							attr != NULL; attr= attr->next_attribute())
						{
							if(strcmp(attr->name(), IBP_TAG_OPERATE) == 0)
							{
								planTime._TimeTemplateOpt = atoi(attr->value());
							}
							else if(strcmp(attr->name(), IBP_TAG_ID) == 0)
							{
								planTime._TimeTemplateId = atoi(attr->value());
							}							
						}

						internal::print_element_node(std::back_inserter(planTime._TimeTemplateCfg), child, 0,0);
					}					
				}

				vecPlanTime.push_back(planTime);
			}
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}

void XmlUtils::StringReplace(string& str,const string& aaa,const string& bbb)
{
	size_t pos = 0;
	size_t aSize = aaa.size();
	size_t bSize = bbb.size();

	while((pos = str.find(aaa,pos)) != string::npos)
	{
		str.replace(pos,aSize,bbb);
		pos+=bSize;
	}
}