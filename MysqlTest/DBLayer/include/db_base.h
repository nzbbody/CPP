#ifndef DBLAYER_DBBASE_H_
#define DBLAYER_DBBASE_H_

#include "db_define.h"

namespace DBLayer
{
	class DBBase
	{
	public:
		DBBase();
		virtual ~DBBase();

		virtual int Connect(const DBInfo& dbInfo, int timeout) = 0;
		virtual int Disconnect() = 0;
	};
}
#endif