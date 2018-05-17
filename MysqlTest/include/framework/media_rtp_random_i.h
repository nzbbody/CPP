#ifndef _MDEIA_RANDOM_I_H
#define _MDEIA_RANDOM_I_H

#include <data_types.h>
#include <trace/trace_i.h>
#include <time.h>

class DLL_EXPORT mediaRandomI
{
public:
	mediaRandomI();
	mediaRandomI(t_uint32 seed);
	virtual ~mediaRandomI();

public:
	/** 
	* 	func name:	getRandom16
	*	@brief:		回去16位的随机数
	*	@return:	16位随机数；
	*	@author:	he_hairan
	*	@note:		2013-5-3
	*
	*/
	t_uint16 getRandom16();
	/** 
	* 	func name:	getRandom32
	*	@brief:		回去32位的随机数
	*	@return:	32位随机数；
	*	@author:	he_hairan
	*	@note:		2013-5-3
	*
	*/
	t_uint32 getRandom32();
	/** 
	* 	func name:	pickSeed
	*	@brief:		种种子
	*	@return:	16位随机数；
	*	@author:	he_hairan
	*	@note:		2013-5-3
	*
	*/
	t_uint32 pickSeed();
	/** 
	* 	func name:	setSeed
	*	@brief:		设置种子
	*	@param：	seed：种子
	*	@author:	he_hairan
	*	@note:		2013-5-3
	*
	*/
	void setSeed(t_uint32 seed);

public:
	t_uint64 state;
};

#endif
