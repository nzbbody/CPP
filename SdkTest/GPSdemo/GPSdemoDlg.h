// GPSdemoDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "dhnetsdk.h"
#include "dhassistant.h"

// CGPSdemoDlg 对话框
class CGPSdemoDlg : public CDialog
{
// 构造
public:
	CGPSdemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GPSDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_IP;
	long m_Port;
	CString m_User;
	CString m_PSW;
	CListCtrl m_GPSInfo;
	LONG LoginID;
	GPS_Info GpsInfo;
	int Num;
	void SetGPSInfo(GPS_Info GpsInfo);
	afx_msg void OnLogin();
	afx_msg void OnLogout();
	afx_msg void OnDestroy();
};
