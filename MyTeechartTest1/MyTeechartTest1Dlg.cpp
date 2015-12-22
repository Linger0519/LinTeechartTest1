
// MyTeechartTest1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyTeechartTest1.h"
#include "MyTeechartTest1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MAX_DATA_SIZE 20

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
	m_TeeCommand1.put_Color(RGB(233,233,233));
	m_TeeCommand1.put_Vertical(TRUE);//����button��ֱ����

	//����ͼ��Ŀ�Ⱥ͸߶�
	//m_Teechart1.put_Height(400);
	//m_Teechart1.put_Width(600);

	//������ʾģʽ��3D/2D��
	((CAspect)m_Teechart1.get_Aspect()).put_View3D(TRUE);
	((CAspect)m_Teechart1.get_Aspect()).put_Chart3DPercent(30);

	//����ͼ��ı��⣨CTitles\CStrings��
	linTitle = (CTitles)m_Teechart1.get_Header();
	((CStrings)linTitle.get_Text()).Clear();
	((CStrings)linTitle.get_Text()).Add(COleVariant(_T("����Title")));

	//����ͼ��
	linLengend = (CLegend)m_Teechart1.get_Legend();
	linLengend.put_Visible(FALSE);

	//���û���
	linPanel = (CPanel)m_Teechart1.get_Panel();
	linPanel.put_Color(RGB(255,235,205));//����ɫ
	//linPanel.put_BorderStyle(0);//��ʱ���������

	//���û���Ϊ���䱳��
	((CGradient)linPanel.get_Gradient()).put_Visible(TRUE);
	((CGradient)linPanel.get_Gradient()).put_StartColor(RGB(182,182,182));
	((CGradient)linPanel.get_Gradient()).put_EndColor(RGB(250,250,250));

	//��������������
	linAxes = (CAxes)m_Teechart1.get_Axis();
	((CAxis)linAxes.get_Bottom()).put_AutomaticMinimum(FALSE);
	((CAxis)linAxes.get_Bottom()).put_AutomaticMaximum(FALSE);
	((CAxis)linAxes.get_Bottom()).put_Minimum(0);
	((CAxis)linAxes.get_Bottom()).put_Maximum(20);
	
	((CAxisTitle)((CAxis)linAxes.get_Bottom()).get_Title()).put_Caption(_T("x��"));
	((CAxisLabels)((CAxis)linAxes.get_Bottom()).get_Labels()).put_ValueFormat(_T("0.0"));
	((CAxis)linAxes.get_Bottom()).Scroll(1.0,TRUE);//ò��û������

	((CAxis)linAxes.get_Left()).put_AutomaticMinimum(FALSE);
	((CAxis)linAxes.get_Left()).put_AutomaticMaximum(FALSE);
	((CAxis)linAxes.get_Left()).put_Minimum(0);
	((CAxis)linAxes.get_Left()).put_Maximum(300);
	((CAxisTitle)((CAxis)linAxes.get_Left()).get_Title()).put_Caption(_T("y��"));
	((CAxisTitle)((CAxis)linAxes.get_Left()).get_Title()).put_Angle(0);

	//((CAxis)linAxes.get_Depth())


	//ɾ����������
	m_Teechart1.RemoveAllSeries();


	//������������1��ʽ
	COleSafeArray XValues;  
	COleSafeArray YValues; 
	DWORD Xnum[] = {MAX_DATA_SIZE};
	DWORD Ynum[] = {MAX_DATA_SIZE};
	XValues.Create(VT_R8, 1, Xnum);
	YValues.Create(VT_R8, 1, Ynum);
	double tmp;  
	long index=0;  
	for(int i=0; i<MAX_DATA_SIZE; i++)  
	{  
		tmp = i;  
		XValues.PutElement(&index, &tmp);  
		tmp = rand() % 250;  
		YValues.PutElement(&index, &tmp);  
		index++;  
	}
	

	//������������2��ʽ
	VARIANT vAX,vAY;
	VARIANT &AX = vAX;
	VARIANT &AY = vAY;
	SAFEARRAY *psax;
	SAFEARRAY *psay;
	SAFEARRAYBOUND rgsabound;
	rgsabound.cElements=MAX_DATA_SIZE;
	rgsabound.lLbound=0;
	psax=SafeArrayCreate(VT_R8,1,&rgsabound);
	psay=SafeArrayCreate(VT_R8,1,&rgsabound);
	AX.vt=VT_ARRAY|VT_R8;
	AX.parray=psax;
	AY.vt=VT_ARRAY|VT_R8;
	AY.parray=psay;
	double tmp2;
	for (int i=0; i<MAX_DATA_SIZE; i++)
	{
		tmp2 = i;
		SafeArrayPutElement(psax, (LONG *)&i, &tmp);
		tmp2 = rand() % 250;
		SafeArrayPutElement(psay, (LONG *)&i, &tmp);
	}


	//�������
	m_Teechart1.AddSeries(scLine);
	linSeries = ((CSeries)m_Teechart1.Series(0));
	/*for (int i=0; i<MAX_DATA_SIZE; i++)
	{
		linSeries.AddXY(i+1, rand()%250, NULL, RGB(255,0,0));
	}*/
	//linSeries.FillSampleValues(16);
	//linSeries.Clear();
	linSeries.AddArray(MAX_DATA_SIZE, YValues, XValues);//������ӵ�һ�ַ�ʽ
	//linSeries.AddArray(MAX_DATA_SIZE, AX, AY);//������ӵ���һ�ַ�ʽ
	linSeries.put_Title(CString("First Series"));
	linSeries.put_Color(RGB(250,10,15));

	//�Ƿ���ͼ��ÿ��������ʾyֵ
	//((CMarks)linSeries.get_Marks()).put_Visible(TRUE);
	//((CMarks)linSeries.get_Marks()).put_Style(smsValue);//����marks��񣬼�ö��EMarkStyle
	//((CMarks)linSeries.get_Marks()).put_BackColor(RGB(0,255,0));
	//((CMarks)linSeries.get_Marks()).put_Color(RGB(0,0,255));//��������浽����ʲô���???

	//m_Teechart1.AddSeries(scLine);
	//linSeries = ((CSeries)m_Teechart1.Series(1));
	//linSeries.FillSampleValues(16);
	//linSeries.put_Title(CString("Second Series"));
	//linSeries.put_Color(RGB(125,210,15));

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

