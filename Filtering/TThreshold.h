#pragma once
#include "afxwin.h"

extern int D0;
extern CString m_strTmpFile2;
// TThreshold 对话框

class TThreshold : public CDialogEx
{
	DECLARE_DYNAMIC(TThreshold)

public:
	TThreshold(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TThreshold();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Thresholdvalue };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_thnum;
	afx_msg void OnEnChangethnum();
	afx_msg void OnBnClickedoutdir();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangedirshow();
};
