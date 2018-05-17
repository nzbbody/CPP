
#ifndef _DATETIME_I_H
#define _DATETIME_I_H

#include <data_types.h>

typedef struct timeval timeval_t;

typedef struct datetime datetime_t;

typedef enum
{
	datetime_invalid,
	datetime_equal,
	datetime_less,
	datetime_greater,
}datetime_compare;

struct datetime
{
	t_int16 year;
	t_int8 month;
	t_int8 day;

	t_int8 hour;
	t_int8 minute;
	t_int8 second;

	t_int8 week;

};
/** 
*
* 	func name	:		datetimeUpdate
*	@brief		:	  更新平台时间
*	@param		:	 
*	@return		:  
*	@author		:   
*   @date		:    
*	@modify	    : hehairan add 注释头 2013-05-02
*/
t_int32 datetimeUpdate(void *arg);


#endif
