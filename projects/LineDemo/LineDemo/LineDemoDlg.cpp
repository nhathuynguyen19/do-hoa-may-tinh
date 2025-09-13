
// LineDemoDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "LineDemo.h"
#include "LineDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CLineDemoDlg dialog



CLineDemoDlg::CLineDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINEDEMO_DIALOG, pParent)
	, xa(0)
	, ya(0)
	, xb(0)
	, yb(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLineDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, xa);
	DDX_Text(pDX, IDC_EDIT2, ya);
	DDX_Text(pDX, IDC_EDIT3, xb);
	DDX_Text(pDX, IDC_EDIT4, yb);
}

BEGIN_MESSAGE_MAP(CLineDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CLineDemoDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLineDemoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLineDemoDlg message handlers

BOOL CLineDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLineDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLineDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLineDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLineDemoDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CLineDemoDlg::BresLine(int xa, int ya, int xb, int yb)
{
	// TODO: Add your implementation code here.
	CDC* p_DC = this->GetDC();
	COLORREF Color = RGB(0, 0, 0);

	int Dx = xb - xa;
	int Dy = yb - ya;
	double a;
	if (Dx != 0 && Dy != 0) a = (double)Dy / Dx;
	else if (Dx == 0) a = 2;
	else if (Dy == 0) a = 0;

	if (a >= 0 && a <= 1) {
		if (xa > xb) {
			int t;
			t = xa; xa = xb; xb = t;
			t = ya; ya = yb; yb = t;
			Dx = xb - xa;
			Dy = yb - ya;
		}
		int P = 2 * Dy - Dx;
		int Const1 = 2 * Dy;
		int Const2 = 2 * Dy - 2 * Dx;
		int x = xa, y = ya;

		p_DC->SetPixel(x, y, Color);

		while (x < xb) {
			x++;
			if (P < 0) {
				P += Const1;
			}
			else {
				y++;
				P += Const2;
			}
			p_DC->SetPixel(x, y, Color);
		}
	}
	else if (-1 <= a && a <= 0) {
		ya = -ya;
		yb = -yb;
		if (xa > xb) {
			int t;
			t = xa; xa = xb; xb = t;
			t = ya; ya = yb; yb = t;
		}
		Dx = xb - xa;
		Dy = yb - ya;
		int P = 2 * Dy - Dx;
		int Const1 = 2 * Dy;
		int Const2 = 2 * Dy - 2 * Dx;
		int x = xa, y = ya;

		p_DC->SetPixel(x, -y, Color);

		while (x < xb) {
			x++;
			if (P < 0) {
				P += Const1;
			}
			else {
				y++;
				P += Const2;
			}
			p_DC->SetPixel(x, -y, Color);
		}
	} else if (a > 1) {
		int t;
		t = xa; xa = ya; ya = t;
		t = xb; xb = yb; yb = t;
		if (xa > xb) {
			int t;
			t = xa; xa = xb; xb = t;
			t = ya; ya = yb; yb = t;
		}
		Dx = xb - xa;
		Dy = yb - ya;
		int P = 2 * Dy - Dx;
		int Const1 = 2 * Dy;
		int Const2 = 2 * Dy - 2 * Dx;
		int x = xa, y = ya;

		p_DC->SetPixel(y, x, Color);

		while (x < xb) {
			x++;
			if (P < 0) {
				P += Const1;
			}
			else {
				y++;
				P += Const2;
			}
			p_DC->SetPixel(y, x, Color);
		}
	} else if (a < -1) {
		int t;
		t = xa; xa = ya; ya = t;
		t = xb; xb = yb; yb = t;
		ya = -ya;
		yb = -yb;
		if (xa > xb) {
			int t;
			t = xa; xa = xb; xb = t;
			t = ya; ya = yb; yb = t;
		}
		Dx = xb - xa;
		Dy = yb - ya;
		int P = 2 * Dy - Dx;
		int Const1 = 2 * Dy;
		int Const2 = 2 * Dy - 2 * Dx;
		int x = xa, y = ya;

		p_DC->SetPixel(-y, x, Color);

		while (x < xb) {
			x++;
			if (P < 0) {
				P += Const1;
			}
			else {
				y++;
				P += Const2;
			}
			p_DC->SetPixel(-y, x, Color);
		}
	}
}

void CLineDemoDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	BresLine(xa, ya, xb, yb);
}
