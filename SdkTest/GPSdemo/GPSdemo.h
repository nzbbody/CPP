// GPSdemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGPSdemoApp:
// �йش����ʵ�֣������ GPSdemo.cpp
//

class CGPSdemoApp : public CWinApp
{
public:
	CGPSdemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGPSdemoApp theApp;