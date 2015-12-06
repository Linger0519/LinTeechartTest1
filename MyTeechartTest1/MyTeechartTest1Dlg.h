
// MyTeechartTest1Dlg.h : 头文件
//

#pragma once
#include "tchart1.h"

#include "CSeries.h" 
#include "CAxis.h"
#include "CAxisTitle.h"
#include "CAxisLabels.h"
#include "CAxes.h"
#include "CLegend.h"
#include "CStrings.h"
#include "CTitles.h"
#include "CPanel.h"
#include "CGradient.h"
#include "CAspect.h"
#include "CMarks.h"
#include "teecommander1.h"

// CMyTeechartTest1Dlg 对话框
class CMyTeechartTest1Dlg : public CDialogEx
{
// 构造
public:
	CMyTeechartTest1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYTEECHARTTEST1_DIALOG };

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
	CTchart1 m_Teechart1;
	CSeries linSeries;
	CAxes linAxes;
	CLegend linLengend;
	CTitles linTitle;
	CPanel linPanel;
	CTeecommander1 m_TeeCommand1;
};
