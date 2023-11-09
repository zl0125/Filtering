// TThreshold2.cpp : 实现文件
//

#include "stdafx.h"
#include "Filtering.h"
#include "TThreshold2.h"
#include "afxdialogex.h"
#include "F_Select.h"

int D1 = -1;
int a=-1;
CString m_strTmpFile3;
// TThreshold2 对话框

IMPLEMENT_DYNAMIC(TThreshold2, CDialogEx)

TThreshold2::TThreshold2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Thresholdvalue2, pParent)
{

}

TThreshold2::~TThreshold2()
{
}

void TThreshold2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_thnum, m_d1);
	DDX_Control(pDX, IDC_thnum2, m_a);
}


BEGIN_MESSAGE_MAP(TThreshold2, CDialogEx)
	ON_BN_CLICKED(IDC_outdir, &TThreshold2::OnBnClickedoutdir)
	ON_EN_CHANGE(IDC_thnum, &TThreshold2::OnEnChangethnum)
	ON_EN_CHANGE(IDC_thnum2, &TThreshold2::OnEnChangethnum2)
	ON_BN_CLICKED(IDOK, &TThreshold2::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &TThreshold2::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_dirshow, &TThreshold2::OnEnChangedirshow)
END_MESSAGE_MAP()


// TThreshold2 消息处理程序


void TThreshold2::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Blfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("巴特沃斯低通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile3 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile3);
		}
	}
	if (Bhfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("巴特沃斯高通滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile3 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile3);
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void TThreshold2::OnEnChangethnum()
{
	CString str;
	m_d1.GetWindowText(str);
	D1 = _tstoi(str);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void TThreshold2::OnEnChangethnum2()
{
	CString str1;
	m_a.GetWindowText(str1);
	a = _tstoi(str1);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void TThreshold2::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void TThreshold2::OnBnClickedCancel()
{
	D1 = -1;
	m_strTmpFile3 = _T("");
	a = -1;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void TThreshold2::OnEnChangedirshow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
