// TThreshold.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Filtering.h"
#include "TThreshold.h"
#include "afxdialogex.h"
#include "F_Select.h"

int D0 = -1;
CString m_strTmpFile2;
// TThreshold �Ի���

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


// TThreshold ��Ϣ�������


void TThreshold::OnEnChangethnum()
{
	CString str;
	m_thnum.GetWindowText(str);
	D0 = _tstoi(str);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void TThreshold::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Elfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("ָ����ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ehfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("ָ����ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ilfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("�����ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	if (Ihfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("�����ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile2 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile2);
		}
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void TThreshold::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void TThreshold::OnBnClickedCancel()
{
	D0 = -1;
	m_strTmpFile2 = _T("");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void TThreshold::OnEnChangedirshow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
