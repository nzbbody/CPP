#ifndef MEDIA_SWITCH_I_H
#define MEDIA_SWITCH_I_H

#include<media_unit_i.h>

class mediaDispatchI
{
public:
	mediaDispatchI();
	virtual ~mediaDispatchI();

public:
	static t_int32 dispatch(mediaUnitI* unit1, mediaUnitI* unit2);//��������mediaUnit֮��ĵ��ȹ�ϵ
	static t_int32 undispatch(mediaUnitI* unit1, mediaUnitI* unit2);//ȡ������mediaUnit֮��ĵ��ȹ�ϵ

};
#endif
