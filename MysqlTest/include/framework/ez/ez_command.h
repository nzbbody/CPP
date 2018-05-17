

#ifndef _EZ_COMMAND_H
#define _EZ_COMMAND_H


#include <data_types.h>
#include <ez/ez_cli.h>

//ƽ̨�˳�����

t_int32 cliExit(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);

extern struct ezCliElement elExit;

//������Ϣ����
t_int32 traceFlagSet(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);

extern struct ezCliElement elTraceConfig;

//�ڴ��������
t_int32 mmTraceSet(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezTraceCmd;

//�����ӽڵ�����
t_int32 enterNode(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);
extern struct ezCliElement ezEnterNode;

//�鿴�汾����
t_int32 showVersion(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezGetVersion;

t_int32 ezPingFunc(t_handler cli, t_int32 argc, t_int8 **argv,void *userPtr);
extern struct ezCliElement ezPing;

//�鿴��ǰ������
t_int32 showEzcliTree(t_handler cli, t_int32 argc, t_int8 **argv, void *userPtr);
extern struct ezCliElement ezCommandHelp;
#endif

