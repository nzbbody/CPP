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
	int				_OptFlag;			//������ʶ
	int				_ActionId;			//����ID
	int				_SeqId;				//���
	int				_ActionTypeId;		//��������Id
	string			_Desc;				//����

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
	int					_OptFlag;				//������ʶ
	int					_PointId;			//Ѳ���Id
	int					_SeqId;				//���
	string				_PointName;			//Ѳ�������
	string				_TargetCode;		//һ���豸����
	int					_AnalyseType;		//��������
	int					_StayTime;			//ͣ��ʱ��
	string				_Desc;				//����
	vector<IisAction>	_VecAction;			//�����б�
	int 				_TaskId;			//����������Id

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
	int					_OptFlag;				//������ʶ
	int					_TaskId;				//����ID
	int					_SeqId;					//ִ��˳��
	string				_TaskName;				//��������
	int					_TaskType;				//��������
	string				_TargetCode;			//һ���豸����
	int					_Status;				//��ǰ״̬
	vector<IisPoint>	_VecPoint;				//Ѳ����б�
	int					_PlanId;				//�ƻ�ID

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
	int				_OptFlag;				//������ʶ
	int				_TimeTemplateId;		//�ƻ�Id        
	int				_TimeTemplateType;		//ʱ��ģ��Id
	string			_Desc;					//����
	string			_Config;				//������Ϣ

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
	int				_OptFlag;				//������ʶ
	int				_PlanId;				//�ƻ�Id        
	int				_TimeTemplateId;		//ʱ��ģ��Id
	int				_Interval;				//ִ�м��
	int				_IntParam1;				//int���� 
	string			_StrParam1;				//str����
	string			_Desc;					//����
	vector<IisTask>	_VecTask;				//�����б�
	IisTimeTemplate	_IisTimeTemplate;		//ʱ��ģ��

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

	// ��bbb�滻aaa
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