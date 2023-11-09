// Filepath.cpp : 实现文件
//

#include "stdafx.h"
#include "Filtering.h"
#include "Filepath.h"
#include "afxdialogex.h"

CString m_strTmpFile1;
// Filepath 对话框

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


// Filepath 消息处理程序


void Filepath::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	CFileDialog TmpDlg(FALSE, _T("jpg"), _T("锐化"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

	if (TmpDlg.DoModal() == IDOK)
	{
		//获取文件路径
		m_strTmpFile1 = TmpDlg.GetPathName();
		SetDlgItemText(IDC_dirshow, m_strTmpFile1);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Filepath::OnBnClickedCancel()
{
	m_strTmpFile1 = _T("");
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
