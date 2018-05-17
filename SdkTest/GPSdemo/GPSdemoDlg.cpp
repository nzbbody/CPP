// GPSdemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GPSdemo.h"
#include "GPSdemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
void CALLBACK MyfGPSRev(LONG lLoginID, GPS_Info GpsInfo,DWORD dwUserData);


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGPSdemoDlg �Ի���




CGPSdemoDlg::CGPSdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGPSdemoDlg::IDD, pParent)
	, m_IP(_T("10.7.6.36"))
	, m_Port(37777)
	, m_User(_T("admin"))
	, m_PSW(_T("admin"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGPSdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_IP);
	DDX_Text(pDX, IDC_EDIT2, m_Port);
	DDX_Text(pDX, IDC_EDIT3, m_User);
	DDX_Text(pDX, IDC_EDIT4, m_PSW);
	DDX_Control(pDX, IDC_LIST1, m_GPSInfo);
}

BEGIN_MESSAGE_MAP(CGPSdemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CGPSdemoDlg::OnLogin)
	ON_BN_CLICKED(IDC_BUTTON2, &CGPSdemoDlg::OnLogout)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CGPSdemoDlg ��Ϣ�������

BOOL CGPSdemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CLIENT_Init(NULL,0);
	CLIENT_SetSubcribeGPSCallBack(MyfGPSRev ,(DWORD)this);
	m_GPSInfo.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_GRIDLINES);
	m_GPSInfo.InsertColumn(0,"ID",LVCFMT_CENTER,50);
	m_GPSInfo.InsertColumn(1,"����",LVCFMT_CENTER,130);
	m_GPSInfo.InsertColumn(2,"γ��",LVCFMT_CENTER,130);
	m_GPSInfo.InsertColumn(3,"�ٶ�",LVCFMT_CENTER,120);
	m_GPSInfo.InsertColumn(4,"�߶�",LVCFMT_CENTER,120);
	Num = 0;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGPSdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGPSdemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CGPSdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CALLBACK MyfGPSRev(LONG lLoginID, GPS_Info GpsInfo,DWORD dwUserData)
{
	CGPSdemoDlg* Dlg = (CGPSdemoDlg *)dwUserData;
	Dlg->SetGPSInfo(GpsInfo);
}


void CGPSdemoDlg::OnLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	NET_DEVICEINFO devInfo;
	int error = 0;
	memset(&devInfo,0,sizeof(devInfo));
	LoginID = CLIENT_Login(m_IP.GetBuffer(0),m_Port,m_User.GetBuffer(0),m_PSW.GetBuffer(0),&devInfo,&error);
	if (!LoginID)
	{
		MessageBox("Login failed");
		return;
	}
	CLIENT_SubcribeGPS(LoginID,1,60,1);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
}

void CGPSdemoDlg::OnLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (LoginID)
	{
		CLIENT_Logout(LoginID);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}else
	{
		MessageBox("Logout failed");
	}
	
}


void CGPSdemoDlg::SetGPSInfo(GPS_Info GpsInfo)
{
	CString str;
	str.Format("%d",Num);
	m_GPSInfo.InsertItem(Num,str);
	str.Format("%f",(GpsInfo.longitude-180000000)/1000000);
	m_GPSInfo.SetItemText(Num,1,str);
	str.Format("%f",(GpsInfo.latidude-90000000)/1000000);
	m_GPSInfo.SetItemText(Num,2,str);
	str.Format("%f",(GpsInfo.speed*1.852 )/ 1000.0);
	m_GPSInfo.SetItemText(Num,3,str);
	str.Format("%f",GpsInfo.height);
	m_GPSInfo.SetItemText(Num,4,str);
	Num++;
}

void CGPSdemoDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	CLIENT_Cleanup();
}
