
// MyTeechartTest1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyTeechartTest1.h"
#include "MyTeechartTest1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyTeechartTest1Dlg �Ի���




CMyTeechartTest1Dlg::CMyTeechartTest1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyTeechartTest1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyTeechartTest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_Teechart1);
	DDX_Control(pDX, IDC_TEECOMMANDER1, m_TeeCommand1);
}

BEGIN_MESSAGE_MAP(CMyTeechartTest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMyTeechartTest1Dlg ��Ϣ�������

BOOL CMyTeechartTest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	m_TeeCommand1.put_ChartLink(m_Teechart1.get_ChartLink());

	m_Teechart1.RemoveAllSeries();
	
	m_Teechart1.AddSeries(scArea);
	linSeries = ((CSeries)m_Teechart1.Series(0));
	linSeries.FillSampleValues(16);
	linSeries.put_Title(CString("First Series"));
	linSeries.put_Color(RGB(25,10,155));

	m_Teechart1.AddSeries(scLine);
	linSeries = ((CSeries)m_Teechart1.Series(1));
	linSeries.FillSampleValues(16);
	linSeries.put_Title(CString("Second Series"));
	linSeries.put_Color(RGB(125,210,15));

	//m_Teechart1.Series(0).FillSampleValues(16);//��ʾ���������
	//m_Teechart1.Series(0).SetTitle("Area Series");
	//m_Teechart1.AddSeries(scLine);	
	//m_Teechart1.Series(1).FillSampleValues(16);
	//m_Teechart1.Series(1).SetTitle("Line Series");
	//m_Teechart1.AddSeries(scBar);	
	//m_Teechart1.Series(2).FillSampleValues(16);
	//m_Teechart1.Series(2).SetTitle("Bar Series");//�趨����series
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyTeechartTest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyTeechartTest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyTeechartTest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

