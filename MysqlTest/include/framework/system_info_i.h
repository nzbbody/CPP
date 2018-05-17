#ifndef SYSTEMINFO_I_H
#define SYSTEMINFO_I_H

#include <framework_i.h>

#define NAME_LENTH 128

#define MAX_NUM		100

typedef struct systemBlockStruct
{
	t_int8 partitionName[NAME_LENTH];
	t_uint64 partitionSize;
	t_uint64 partitionFree;
}partitionInfo;

typedef struct systemPartitionInfo
{
	partitionInfo m_disk[MAX_NUM];
	t_int32 m_partionNum;
}diskInfo;

namespace SYSTEMINFO
{
	t_int32 getCpuRate(t_float32 &cpuRate);
	t_int32 getMemRate(t_float32 &memRate);
	void getDiskInfo(diskInfo& tDiskInfo);
}

#endif
