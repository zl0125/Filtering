// TThreshold.cpp : 实现文件
//

#include "stdafx.h"
#include "Filtering.h"
#include "TThreshold.h"
#include "afxdialogex.h"
#include "F_Select.h"

int D0 = -1;
CString m_strTmpFile2;
// TThreshold 对话框

IMPLEMENT_DYNAMIC(TThreshold, CDialogEx)

TThreshold::TThreshold(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Thresholdvalue, pParent)
{

}

TThreshold::~TThreshold()
{
}

void TThreshold::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_thnum, m_thnum);
}


BEGIN_MESSAGE_MAP(TThreshold, CDialogEx)
	ON_EN_CHANGE(IDC_thnum, &TThreshold::OnEnChangethnum)
	ON_BN_CLICKED(IDC_outdir, &TThreshold::OnBnClickedoutdir)
	ON_BN_CLICKED(IDOK, &TThreshold::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &TThreshold::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_dirshow, &TThreshold::OnEnChangedirshow)
END_MESSAGE_MAP()


// TThreshold 消息处理程序


void TThreshold::OnEnChangethnum()
{
	CString str;
	m_thnum.GetWindowText(str);
	D0 = _tstoi(str);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void TThreshold::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Elfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("指数低通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ehfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("指数高通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ilfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("理想低通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ihfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("理想高通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void TThreshold::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void TThreshold::OnBnClickedCancel()
{
	D0 = -1;
	m_strTmpFile2 = _T("");
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void TThreshold::OnEnChangedirshow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
