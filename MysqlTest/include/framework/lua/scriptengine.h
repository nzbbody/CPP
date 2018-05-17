//  "$Id: ScriptEngine.h 1883 2006-02-13 03:02:27Z wanghw $"
//   (c) Copyright 1992-2005, ZheJiang Dahua Information Technology Stock CO.LTD.
//                            All Rights Reserved
//
//	�� �� ���� ScriptEngine.h
//	��    ��:  �ű�����ķ�װ,��һʵ��
//	�޸ļ�¼�� 2006-1-20 ������  <wang_hengwen@dhmail.com> Initial Version
//

#ifndef __SCRIPT_ENGINE_H__
#define __SCRIPT_ENGINE_H__

#include "luawrap.h"

class ScriptEngine
	: public LuaWrap
{
public:
	ScriptEngine();
	~ScriptEngine();
	static ScriptEngine * Instance();
private:
	static ScriptEngine *_instance;	
};

#endif


//
// End of "$Id: ScriptEngine.h 1883 2006-02-13 03:02:27Z wanghw $"
//

