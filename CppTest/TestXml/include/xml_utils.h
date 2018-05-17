#ifndef XML_UTILS_H_
#define XML_UTILS_H_

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

#include "dhconfigsdk.h"
#include "ibpXMLMacro.h"
#include <string>

using namespace std;


struct IisAction
{
	int				_OptFlag;			//操作标识
	int				_ActionId;			//动作ID
	int				_SeqId;				//序号
	int				_ActionTypeId;		//动作类型Id
	string			_Desc;				//主题

	IisAction()
	{
		_OptFlag	  = -1;
		_ActionId     = -1;
		_SeqId		  = -1;
		_ActionTypeId = -1;
		_Desc		  = "";
	}
};

struct IisPoint
{
	int					_OptFlag;				//操作标识
	int					_PointId;			//巡检点Id
	int					_SeqId;				//序号
	string				_PointName;			//巡检点名称
	string				_TargetCode;		//一次设备代码
	int					_AnalyseType;		//分析类型
	int					_StayTime;			//停留时间
	string				_Desc;				//描述
	vector<IisAction>	_VecAction;			//动作列表
	int 				_TaskId;			//关联的任务Id

	IisPoint()
	{
		_OptFlag	  = -1;
		_PointId	  = -1;
		_SeqId		  = -1;
		_PointName	  = -1;
		_TargetCode	  = "";
		_AnalyseType  = -1;
		_StayTime     = -1;
		_Desc		  = -1;
		_TaskId		  = -1;		
	}
}; 

struct IisTask
{
	int					_OptFlag;				//操作标识
	int					_TaskId;				//任务ID
	int					_SeqId;					//执行顺序
	string				_TaskName;				//任务名称
	int					_TaskType;				//任务类型
	string				_TargetCode;			//一次设备代码
	int					_Status;				//当前状态
	vector<IisPoint>	_VecPoint;				//巡检点列表
	int					_PlanId;				//计划ID

	IisTask()
	{
		_OptFlag	= -1;
		_TaskId		= -1;			
		_SeqId		= -1;			
		_TaskName	= "";			
		_TaskType	= -1;			
		_TargetCode	="";			
		_Status		= -1;	 
		_PlanId		= -1;
	}
};

struct IisTimeTemplate
{
	int				_OptFlag;				//操作标识
	int				_TimeTemplateId;		//计划Id        
	int				_TimeTemplateType;		//时间模板Id
	string			_Desc;					//描述
	string			_Config;				//配置信息

	IisTimeTemplate()
	{
		_OptFlag		  = 0;
		_TimeTemplateId	  = 0;
		_TimeTemplateType = 0;
		_Desc			  = "";
		_Config			  = "";
	}
};


struct IisPlan
{
	int				_OptFlag;				//操作标识
	int				_PlanId;				//计划Id        
	int				_TimeTemplateId;		//时间模板Id
	int				_Interval;				//执行间隔
	int				_IntParam1;				//int参数 
	string			_StrParam1;				//str参数
	string			_Desc;					//描述
	vector<IisTask>	_VecTask;				//任务列表
	IisTimeTemplate	_IisTimeTemplate;		//时间模板

	IisPlan()
	{
		_OptFlag		= 0;
		_PlanId			= 0;
		_TimeTemplateId = 0;
		_Interval		= 0;
		_IntParam1		= 0;
		_StrParam1		= "";
		_Desc			= "";
	}
};


struct IrArea
{
	int		_RuleId;
	string  _Name;
	int     _Type;
	string _Content;

	IrArea()
	{
		_RuleId  = 0;
		_Name    = "";
		_Type    = 0;
		_Content ="";
	}
};


struct IisPlanTimeTemplate
{
	int		_PlanId;
	string	_Name;
	string  _Desc;

	int		_TimeTemplateOpt;
	int		_TimeTemplateId;	
	string  _TimeTemplateCfg;


	IisPlanTimeTemplate()
	{
		_PlanId	= 0;
		_Name	= "";
		_Desc	= "";

		_TimeTemplateOpt = 0;
		_TimeTemplateId	 = 0;
		_TimeTemplateCfg = "";
	}
};


class XmlUtils
{
public:
	//static bool ParseXml(CFG_THERMO_GRAPHY_INFO& info);
	static bool ParseXml(CFG_RADIOMETRY_RULE_INFO& info);
	static bool ParseXml(CFG_TEMP_STATISTICS_INFO& info);
	static bool ParseXml(CFG_THERMOMETRY_INFO& info);

	static bool ParseXml(vector<IisPoint>& vecIisPoint);
	static bool ParseXml(vector<IisTask>& vecIisTask);
	static bool ParseXml(vector<IisPlan>& vecIisPlan);



	static bool ParseXml(vector<IrArea>& vecIrArea);


	static bool ParseXml(vector<IisPlanTimeTemplate>& vecPlanTime);

	// 用bbb替换aaa
	static void StringReplace(std::string& str,const std::string& aaa,
		const std::string& bbb);

private:
	static bool parseIisPlan(rapidxml::xml_node<>* node,IisPlan& iisPlan);
	static bool parseIisTask(rapidxml::xml_node<>* node,IisTask& iisTask);
	static bool parseIisPoint(rapidxml::xml_node<>* node,IisPoint& iisPoint);
	static bool parseIisAction(rapidxml::xml_node<>* node,IisAction& iisAction);

	static bool parseIisTimeTemplate(rapidxml::xml_node<>* node,IisTimeTemplate& iisTimeTemplate);

	
	static bool parseIrArea(rapidxml::xml_node<>* node,IrArea& irArea);
};


#endif