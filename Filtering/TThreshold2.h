#pragma once
#include "afxwin.h"
extern int D1,a;
extern CString m_strTmpFile3;

// TThreshold2 �Ի���

class TThreshold2 : public CDialogEx
{
	DECLARE_DYNAMIC(TThreshold2)

public:
	TThreshold2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TThreshold2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Thresholdvalue2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedoutdir();
	CEdit m_d1;
	CEdit m_a;
	afx_msg void OnEnChangethnum();
	afx_msg void OnEnChangethnum2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangedirshow();
};
