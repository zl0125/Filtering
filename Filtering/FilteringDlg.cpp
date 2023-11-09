
// FilteringDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Filtering.h"
#include "FilteringDlg.h"
#include "afxdialogex.h"
#include "F_Select.h"

CString infilename;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFilteringDlg �Ի���



CFilteringDlg::CFilteringDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILTERING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFilteringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_inputimg, m_inputimg);
	DDX_Control(pDX, IDC_outimg, m_outimg);
}

BEGIN_MESSAGE_MAP(CFilteringDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_input, &CFilteringDlg::OnBnClickedinput)
	ON_BN_CLICKED(IDC_output, &CFilteringDlg::OnBnClickedoutput)
END_MESSAGE_MAP()


// CFilteringDlg ��Ϣ�������

BOOL CFilteringDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFilteringDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFilteringDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFilteringDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFilteringDlg::OnBnClickedinput()
{

	CFileDialog fileDlg(TRUE, _T("png"), NULL, 0, _T("image Files(*.bmp;*.jpg;*.png)|*.JPG;*.PNG;*.BMP|All Files (*.*) |*.*|"), this);
	fileDlg.DoModal();
	CString path = fileDlg.GetPathName();
	CImage image;
	image.Load(path);
	infilename = path;
	if (path.IsEmpty()) {
		return; // ���pathΪ�գ���ִ���κδ��벢����
	}
	CRect rectControl;
	m_inputimg.GetClientRect(rectControl);

	CDC* pDc = m_inputimg.GetDC();
	rectControl = CRect(rectControl.TopLeft(), CSize(rectControl.Width(), rectControl.Height()));
	m_inputimg.SetBitmap(NULL);

	image.Draw(pDc->m_hDC, rectControl);

	m_inputimg.ReleaseDC(pDc);
}




void CFilteringDlg::OnBnClickedoutput()
{
	if (infilename.IsEmpty()) {
		int result = MessageBox(TEXT("�뵼��ͼƬ"), TEXT("��ʾ"), MB_OK);
		return; // ���m_strTmpFile0Ϊ�գ���ִ���κδ��벢����
	}
	F_Select safAS;
	safAS.DoModal();
	CString Cqtttm_strTmpFile = m_strTmpFile0;
	if (m_strTmpFile0.IsEmpty()) {
		return; // ���m_strTmpFile0Ϊ�գ���ִ���κδ��벢����
	}
	CImage image;
	image.Load(Cqtttm_strTmpFile);
	CRect rectControl;
	m_outimg.GetClientRect(rectControl); // �ؼ����ζ���
	CDC* pDc = m_outimg.GetDC(); // �豸�����Ķ������
	rectControl = CRect(rectControl.TopLeft(), CSize((int)rectControl.Width(), (int)rectControl.Height()));
	m_outimg.SetBitmap(NULL); // ���picture
	image.Draw(pDc->m_hDC, rectControl);
	m_outimg.ReleaseDC(pDc);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
