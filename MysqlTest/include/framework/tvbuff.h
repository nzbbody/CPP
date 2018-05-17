/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _TVBUFF_H
#define _TVBUFF_H

#include <data_types.h>

#define TVBUFF_SIZE 4096
struct tvbuff
{
	t_int8 *realData;
	t_int32 length;
	t_int32 reportLength;
	t_int32 leftLength;


	t_int8 *nextOffset;
};

enum tvbuffType{
	TVBUFF_REAL_DATA,
	TVBUFF_SUBSET,
	TVBUFF_COMPOSITE
};

struct tvbuff * tvbuffNew(tvbuffType tvbType);
void tvbuffFree(struct tvbuff *tvb);

t_bool tvbResetOffset(struct tvbuff *tvb);
t_int8 *tvbGetRealData(struct tvbuff *tvb);
t_int32 tvbGetReportLength(struct tvbuff *tvb);
t_bool tvbPutChar(struct tvbuff *tvb, t_int8 ch);
t_bool tvbGetChar(struct tvbuff *tvb, t_int8 *ch);
t_bool tvbPutCharBuf(struct tvbuff *tvb, const t_int8 *buf, t_int32 length);

#endif
