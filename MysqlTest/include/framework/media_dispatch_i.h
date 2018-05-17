#ifndef MEDIA_SWITCH_I_H
#define MEDIA_SWITCH_I_H

#include<media_unit_i.h>

class mediaDispatchI
{
public:
	mediaDispatchI();
	virtual ~mediaDispatchI();

public:
	static t_int32 dispatch(mediaUnitI* unit1, mediaUnitI* unit2);//建立两个mediaUnit之间的调度关系
	static t_int32 undispatch(mediaUnitI* unit1, mediaUnitI* unit2);//取消两个mediaUnit之间的调度关系

};
#endif
