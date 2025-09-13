
// LineDemoDlg.h : header file
//

#pragma once


// CLineDemoDlg dialog
class CLineDemoDlg : public CDialogEx
{
// Construction
public:
	CLineDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int xa;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	int ya;
	int xb;
	int yb;
	void BresLine(int xa, int ya, int xb, int yb);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
