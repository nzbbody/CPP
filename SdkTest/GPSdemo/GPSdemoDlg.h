// GPSdemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "dhnetsdk.h"
#include "dhassistant.h"

// CGPSdemoDlg �Ի���
class CGPSdemoDlg : public CDialog
{
// ����
public:
	CGPSdemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GPSDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
