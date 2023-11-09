// filtersize.cpp : 实现文件
//

#include "stdafx.h"
#include "Filtering.h"
#include "filtersize.h"
#include "afxdialogex.h"
#include "F_Select.h"

int Filtersize = 0;
CString m_strTmpFile;
// filtersize 对话框

IMPLEMENT_DYNAMIC(filtersize, CDialogEx)

filtersize::filtersize(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_filtersize, pParent)
{

}

filtersize::~filtersize()
{
}

void filtersize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_filtersize, m_filtersize);
}


BEGIN_MESSAGE_MAP(filtersize, CDialogEx)
	ON_EN_CHANGE(IDC_filtersize, &filtersize::OnEnChangefiltersize)
	ON_BN_CLICKED(IDC_outdir, &filtersize::OnBnClickedoutdir)
	ON_BN_CLICKED(IDOK, &filtersize::OnBnClickedOk)
	ON_EN_CHANGE(IDC_dirshow, &filtersize::OnEnChangedirshow)
	ON_BN_CLICKED(IDCANCEL, &filtersize::OnBnClickedCancel)
END_MESSAGE_MAP()


// filtersize 消息处理程序


void filtersize::OnEnChangefiltersize()
{
	CString str;
	m_filtersize.GetWindowText(str);
	Filtersize = _tstoi(str);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void filtersize::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Mfilter_num==1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("均值滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile);
		}
	}
	if (MDfilter_num==1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("中值滤波"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//获取文件路径
			m_strTmpFile = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile);
		}
	}
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void filtersize::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void filtersize::OnEnChangedirshow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void filtersize::OnBnClickedCancel()
{
	Filtersize = 0;
	CString m_strTmpFile = _T("");
	EndDialog(IDCANCEL);
	// TODO: 在此添加控件通知处理程序代码
}
