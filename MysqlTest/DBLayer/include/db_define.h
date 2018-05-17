#ifndef DBLAYER_DBDEFINE_H_
#define DBLAYER_DBDEFINE_H_

#include <string>

namespace DBLayer
{
	#define SUCCESS 0
	#define FAILURE -1

	#define DBLog "DBLog"

	struct DBInfo
	{	
		std::string _UserName;
		std::string _Password;
		std::string _Host;
		int			_Port;
		std::string _DBName;

		DBInfo()
		{
			_UserName = "";
			_Password = "";
			_Host	  = "";
			_Port     = 0;
			_DBName   = "";
		}
	};
}

#endif
