// TThreshold2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Filtering.h"
#include "TThreshold2.h"
#include "afxdialogex.h"
#include "F_Select.h"

int D1 = -1;
int a=-1;
CString m_strTmpFile3;
// TThreshold2 �Ի���

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


// TThreshold2 ��Ϣ�������


void TThreshold2::OnBnClickedoutdir()
{
	CString strFilter;
	strFilter = "dat file (*.jpg)|*.jpg; *.png||";
	if (Blfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("������˹��ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile3 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile3);
		}
	}
	if (Bhfilter_num == 1) {
		CFileDialog TmpDlg(FALSE, _T("jpg"), _T("������˹��ͨ�˲�"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, this);

		if (TmpDlg.DoModal() == IDOK)
		{
			//��ȡ�ļ�·��
			m_strTmpFile3 = TmpDlg.GetPathName();
			SetDlgItemText(IDC_dirshow, m_strTmpFile3);
		}
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void TThreshold2::OnEnChangethnum()
{
	CString str;
	m_d1.GetWindowText(str);
	D1 = _tstoi(str);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void TThreshold2::OnEnChangethnum2()
{
	CString str1;
	m_a.GetWindowText(str1);
	a = _tstoi(str1);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void TThreshold2::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void TThreshold2::OnBnClickedCancel()
{
	D1 = -1;
	m_strTmpFile3 = _T("");
	a = -1;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void TThreshold2::OnEnChangedirshow()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
