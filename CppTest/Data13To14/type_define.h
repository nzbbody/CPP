#ifndef TYPE_DEFINE_H_
#define TYPE_DEFINE_H_

#include <string>
#include <vector>

using namespace std;

struct Device
{
	int			_DomId;
	string		_DevCode;

	vector<Device> _VecDevice;

	Device():_DomId(0), _DevCode("")
	{

	}
};


struct Org
{
	int			_DomId;
	string		_OrgCode;

	int			_ParentDomId;
	string		_ParentOrgCode;

	string		_Title;
	string		_Desc;

	vector<Org> _VecOrg;

	Org()
	{
		_DomId = 0;
		_OrgCode = "";
		_ParentDomId = 0;
		_ParentOrgCode = "";
		_Title = "";
		_Desc  = "";
	}
};





#endif