/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */


  
#ifndef _FACTORY_I_H
#define _FACTORY_I_H

#include <modules/support_i.h>

class factoryI : public supportI
{
public:
	virtual t_int32 createInstance(supportI *sI, const mIID &mid, void **result) = 0;
	virtual t_int32 runSelf(t_bool lock) = 0;
};

#endif

