#pragma once
#include "afxwin.h"

extern CString m_strTmpFile;
extern int Filtersize;

// filtersize 对话框

class filtersize : public CDialogEx
{
	DECLARE_DYNAMIC(filtersize)

public:
	filtersize(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~filtersize();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_filtersize };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangefiltersize();
	afx_msg void OnBnClickedoutdir();
	afx_msg void OnBnClickedOk();
	CEdit m_filtersize;
	afx_msg void OnEnChangedirshow();
	afx_msg void OnBnClickedCancel();
};
