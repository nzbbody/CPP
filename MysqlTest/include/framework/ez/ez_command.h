

#ifndef _EZ_COMMAND_H
#define _EZ_COMMAND_H


#include <data_types.h>
#include <ez/ez_cli.h>

//平台退出命令

t_int32 cliExit(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);

extern struct ezCliElement elExit;

//调试信息命令
t_int32 traceFlagSet(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);

extern struct ezCliElement elTraceConfig;

//内存管理命令
t_int32 mmTraceSet(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezTraceCmd;

//进入子节点命令
t_int32 enterNode(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);
extern struct ezCliElement ezEnterNode;

//查看版本命令
t_int32 showVersion(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezGetVersion;

t_int32 ezPingFunc(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezPing;

//查看当前命令树
t_int32 showEzcliTree(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);
extern struct ezCliElement ezCommandHelp;
#endif

