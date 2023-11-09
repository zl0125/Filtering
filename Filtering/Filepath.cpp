// Filepath.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Filtering.h"
#include "Filepath.h"
#include "afxdialogex.h"

CString m_strTmpFile1;
// Filepath �Ի���

IMPLEMENT_DYNAMIC(Filepath, CDialogEx)

Filepath::Filepath(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Filepath::~Filepath()
{
}

void Filepath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Filepath, CDialogEx)
	ON_BN_CLICKED(IDC_outdir, &Filepath::OnBnClickedoutdir)
	ON_BN_CLICKED(IDCANCEL, &Filepath::OnBnClickedCancel)
END_MESSAGE_MAP()


// Filepath ��Ϣ�������


void Filepath::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	CFileDialog TmpDlg(FALSE, _T("jpg"), _T("��"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

	if (TmpDlg.DoModal() == IDOK)
	{
		//��ȡ�ļ�·��
		m_strTmpFile1 = TmpDlg.GetPathName();
		SetDlgItemText(IDC_dirshow, m_strTmpFile1);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Filepath::OnBnClickedCancel()
{
	m_strTmpFile1 = _T("");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
