#pragma once
extern CString m_strTmpFile1;

// Filepath �Ի���

class Filepath : public CDialogEx
{
	DECLARE_DYNAMIC(Filepath)

public:
	Filepath(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Filepath();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedoutdir();
	afx_msg void OnBnClickedCancel();
};
