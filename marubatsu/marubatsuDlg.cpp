
// marubatsuDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "marubatsu.h"
#include "marubatsuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CmarubatsuDlg ダイアログ



CmarubatsuDlg::CmarubatsuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MARUBATSU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmarubatsuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BUTTON1, m_waku01);
	DDX_Text(pDX, IDC_BUTTON2, m_waku02);
	DDX_Text(pDX, IDC_BUTTON3, m_waku03);
	DDX_Text(pDX, IDC_BUTTON4, m_waku04);
	DDX_Text(pDX, IDC_BUTTON5, m_waku05);
	DDX_Text(pDX, IDC_BUTTON6, m_waku06);
	DDX_Text(pDX, IDC_BUTTON7, m_waku07);
	DDX_Text(pDX, IDC_BUTTON8, m_waku08);
	DDX_Text(pDX, IDC_BUTTON9, m_waku09);

	DDX_Text(pDX, IDC_MSG, m_msg);
}

BEGIN_MESSAGE_MAP(CmarubatsuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CmarubatsuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CmarubatsuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmarubatsuDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CmarubatsuDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CmarubatsuDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CmarubatsuDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CmarubatsuDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CmarubatsuDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CmarubatsuDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CmarubatsuDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CmarubatsuDlg メッセージ ハンドラー

BOOL CmarubatsuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// 初期化処理.
	AllClear();
	DisableField();

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// フィールド表示.
void CmarubatsuDlg::DisplayField()
{
	// フィールドの値に従って画面表示.
	for (int i=0;i<9;i++)
	{
		if (m_field[i] == 1)
		{
			switch (i)
			{
			case 0:
				m_waku01 = "○";
				break;
			case 1:
				m_waku02 = "○";
				break;
			case 2:
				m_waku03 = "○";
				break;
			case 3:
				m_waku04 = "○";
				break;
			case 4:
				m_waku05 = "○";
				break;
			case 5:
				m_waku06 = "○";
				break;
			case 6:
				m_waku07 = "○";
				break;
			case 7:
				m_waku08 = "○";
				break;
			case 8:
				m_waku09 = "○";
				break;
			default:
				break;
			}
		}
		else if (m_field[i] == 2)
		{
			switch (i)
			{
			case 0:
				m_waku01 = "×";
				break;
			case 1:
				m_waku02 = "×";
				break;
			case 2:
				m_waku03 = "×";
				break;
			case 3:
				m_waku04 = "×";
				break;
			case 4:
				m_waku05 = "×";
				break;
			case 5:
				m_waku06 = "×";
				break;
			case 6:
				m_waku07 = "×";
				break;
			case 7:
				m_waku08 = "×";
				break;
			case 8:
				m_waku09 = "×";
				break;
			default:
				break;
			}
		}
	}
	UpdateData(FALSE);	// 画面更新
}

// 先攻後攻判定.
void CmarubatsuDlg::judgeSenko()
{
	int num = rand() % 2;
	if (num == 1)
	{
		senkoFlg = true;	// 先攻.
	}
	else
	{
		senkoFlg = false;	// 後攻.
	}
}

// CPUターン処理.
void CmarubatsuDlg::CPUturn()
{
	// 終了判定.
	judgeResult();
	if (rsltFlg != 0)
	{
		gameEnd();
		return;
	}
	m_msg = DISP_MSG_CPUTURN;
	UpdateData(FALSE);	// 画面更新

	// CPUターン時の処理.
	turn_num++;
	Sleep(1000);

	CPUputon();
	DisplayField();

	// 終了判定.
	judgeResult();
	if (rsltFlg != 0)
	{
		gameEnd();
		return;
	}

	// プレイヤーのターン準備.
	EmptyOnlyEnebleField();
	m_msg = DISP_MSG_YOURTURN;
	UpdateData(FALSE);	// 画面更新
	turn_num++;
}

void CmarubatsuDlg::gameEnd()
{
	// ゲーム終了.
	DisableField();
	if (rsltFlg == 1)
	{
		m_msg = "プレイヤーの勝利！！";
	}
	else if (rsltFlg == 2)
	{
		m_msg = "CPUの勝利！！";
	}
	else
	{
		m_msg = "引き分け！！";
	}
	// ゲーム開始ボタン無効化（連続クリック防止）.
	(CButton*)GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);

	UpdateData(FALSE);	// 画面更新
}

// CPU置き場判定.
void CmarubatsuDlg::CPUputon()
{
	if (diffLevel == 3)
	{
		actDiff3();
		return;
	}
	else if (diffLevel == 2)
	{
		actDiff2();
		return;
	}
	else
	{
		while (1)
		{
			int num = rand() % 9;
			if (m_field[num] == 0)
			{
				m_field[num] = 2;
				break;
			}
		}
	}
}

// 勝敗判定.
void CmarubatsuDlg::judgeResult()
{
	if (turn_num == 9)
	{
		rsltFlg = -1;
	}
	// 横判定.
	if ((m_field[0] == m_field[1]) && (m_field[0] == m_field[2]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[3] == m_field[4]) && (m_field[3] == m_field[5]))
	{
		if (m_field[3] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[3] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[6] == m_field[7]) && (m_field[6] == m_field[8]))
	{
		if (m_field[6] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[6] == 2)
		{
			rsltFlg = 2;
		}
	}

	// 縦判定.
	if ((m_field[0] == m_field[3]) && (m_field[0] == m_field[6]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[1] == m_field[4]) && (m_field[1] == m_field[7]))
	{
		if (m_field[1] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[1] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[2] == m_field[5]) && (m_field[2] == m_field[8]))
	{
		if (m_field[2] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[2] == 2)
		{
			rsltFlg = 2;
		}
	}

	// 斜め判定.
	if ((m_field[0] == m_field[4]) && (m_field[0] == m_field[8]))
	{
		if (m_field[0] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[0] == 2)
		{
			rsltFlg = 2;
		}
	}
	if ((m_field[2] == m_field[4]) && (m_field[2] == m_field[6]))
	{
		if (m_field[2] == 1)
		{
			rsltFlg = 1;
		}
		else if (m_field[2] == 2)
		{
			rsltFlg = 2;
		}
	}
}


// フィールド無効化.
void CmarubatsuDlg::DisableField()
{
	(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
}
// フィールド有効化.
void CmarubatsuDlg::EnebleField()
{
	(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
}
// フィールド有効化.
void CmarubatsuDlg::EmptyOnlyEnebleField()
{
	if (m_field[0] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}
	if (m_field[1] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	}
	if (m_field[2] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	}
	if (m_field[3] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	}
	if (m_field[4] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	}
	if (m_field[5] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	}
	if (m_field[6] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	}
	if (m_field[7] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	}
	if (m_field[8] != 0)
	{
		(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	}
	else
	{
		(CButton*)GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	}
}


void CmarubatsuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CmarubatsuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CmarubatsuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmarubatsuDlg::OnBnClickedButton1()
{
	m_field[0] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton2()
{
	m_field[1] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton3()
{
	m_field[2] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton4()
{
	m_field[3] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton5()
{
	m_field[4] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton6()
{
	m_field[5] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton7()
{
	m_field[6] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton8()
{
	m_field[7] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}


void CmarubatsuDlg::OnBnClickedButton9()
{
	m_field[8] = 1;
	DisplayField();
	DisableField();
	CPUturn();
}

void CmarubatsuDlg::AllClear()
{
	rsltFlg = 0;

	turn_num = 0;
	for(int i=0;i<9;i++)
	{
		m_field[i] = 0;
	}

	m_waku01 = "";
	m_waku02 = "";
	m_waku03 = "";
	m_waku04 = "";
	m_waku05 = "";
	m_waku06 = "";
	m_waku07 = "";
	m_waku08 = "";
	m_waku09 = "";
	UpdateData(FALSE);	// 画面更新
}

void CmarubatsuDlg::OnBnClickedButton10()
{
	AllClear();
	CButton* myRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* myRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton* myRadio3 = (CButton*)GetDlgItem(IDC_RADIO3);

	if (myRadio1->GetCheck() == BST_CHECKED)
	{
		// 初級.
		diffLevel = 1;
	}
	else if(myRadio2->GetCheck() == BST_CHECKED)
	{
		// 中級.
		diffLevel = 2;
	}
	else
	{
		// 上級.
		diffLevel = 3;
	}

	// 後攻ならCPU処理、先攻ならメッセージ表示.
	judgeSenko();
	if (senkoFlg == true)
	{
		EmptyOnlyEnebleField();
		m_msg = DISP_MSG_YOURTURN;
		turn_num++;
	}
	else
	{
		// CPU処理実行.
		m_msg = DISP_MSG_CPUTURN;
		CPUturn();
	}
	UpdateData(FALSE);	// 画面更新

	// ゲーム開始ボタン無効化（連続クリック防止）.
	(CButton*)GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);

}

// 中級処理.
void CmarubatsuDlg::actDiff2()
{
	bool doneFlg = false;
	for (int num = 0; num < 9; num++)
	{
		// 空きブロックのみ評価.
		if (m_field[num] == 0)
		{
			// ----------------------------.
			// CPUリーチ判定
			// ----------------------------.
			switch (num)
			{
				// 一段目.
			case 0:
				// 左上.
				if (((m_field[1] == m_field[2]) && (m_field[1] == 2))
					|| ((m_field[4] == m_field[8]) && (m_field[4] == 2))
					|| ((m_field[3] == m_field[6]) && (m_field[3] == 2))
					)
				{
					if (m_field[0] == 0)
					{
						m_field[0] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[1] == m_field[2]) && (m_field[1] == 1))
					|| ((m_field[4] == m_field[8]) && (m_field[4] == 1))
					|| ((m_field[3] == m_field[6]) && (m_field[3] == 1))
					)
				{
					if (m_field[0] == 0)
					{
						m_field[0] = 2;
						doneFlg = true;
					}
				}
				break;
			case 1:
				// 中上.
				if (((m_field[0] == m_field[2]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[7]) && (m_field[4] == 2))
					)
				{
					if (m_field[1] == 0)
					{
						m_field[1] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[0] == m_field[2]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[7]) && (m_field[4] == 1))
					)
				{
					if (m_field[1] == 0)
					{
						m_field[1] = 2;
						doneFlg = true;
					}
				}
				break;
			case 2:
				// 右上.
				if (((m_field[0] == m_field[1]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[6]) && (m_field[4] == 2))
					|| ((m_field[5] == m_field[8]) && (m_field[5] == 2))
					)
				{
					if (m_field[2] == 0)
					{
						m_field[2] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[0] == m_field[1]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[6]) && (m_field[4] == 1))
					|| ((m_field[5] == m_field[8]) && (m_field[5] == 1))
					)
				{
					if (m_field[2] == 0)
					{
						m_field[2] = 2;
						doneFlg = true;
					}
				}
				break;
				// 二段目.
			case 3:
				// 左中.
				if (((m_field[0] == m_field[6]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[5]) && (m_field[4] == 2))
					)
				{
					if (m_field[3] == 0)
					{
						m_field[3] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[0] == m_field[6]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[5]) && (m_field[4] == 1))
					)
				{
					if (m_field[3] == 0)
					{
						m_field[3] = 2;
						doneFlg = true;
					}
				}
				break;
			case 4:
				// 中中.
				if (((m_field[0] == m_field[8]) && (m_field[0] == 2))
					|| ((m_field[1] == m_field[7]) && (m_field[1] == 2))
					|| ((m_field[3] == m_field[5]) && (m_field[3] == 2))
					|| ((m_field[2] == m_field[6]) && (m_field[2] == 2))
					)
				{
					if (m_field[4] == 0)
					{
						m_field[4] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[0] == m_field[8]) && (m_field[0] == 1))
					|| ((m_field[1] == m_field[7]) && (m_field[1] == 1))
					|| ((m_field[3] == m_field[5]) && (m_field[3] == 1))
					|| ((m_field[2] == m_field[6]) && (m_field[2] == 1))
					)
				{
					if (m_field[4] == 0)
					{
						m_field[4] = 2;
						doneFlg = true;
					}
				}
				break;
			case 5:
				// 右中.
				if (((m_field[3] == m_field[4]) && (m_field[3] == 2))
					|| ((m_field[2] == m_field[8]) && (m_field[2] == 2))
					)
				{
					if (m_field[5] == 0)
					{
						m_field[5] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[3] == m_field[4]) && (m_field[3] == 1))
					|| ((m_field[2] == m_field[8]) && (m_field[2] == 1))
					)
				{
					if (m_field[5] == 0)
					{
						m_field[5] = 2;
						doneFlg = true;
					}
				}
				break;
				// 三段目.
			case 6:
				// 左下.
				if (((m_field[0] == m_field[3]) && (m_field[0] == 2))
					|| ((m_field[2] == m_field[4]) && (m_field[2] == 2))
					|| ((m_field[7] == m_field[8]) && (m_field[7] == 2))
					)
				{
					if (m_field[6] == 0)
					{
						m_field[6] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[0] == m_field[3]) && (m_field[0] == 1))
					|| ((m_field[2] == m_field[4]) && (m_field[2] == 1))
					|| ((m_field[7] == m_field[8]) && (m_field[7] == 1))
					)
				{
					if (m_field[6] == 0)
					{
						m_field[6] = 2;
						doneFlg = true;
					}
				}
				break;
			case 7:
				// 中下.
				if (((m_field[1] == m_field[4]) && (m_field[1] == 2))
					|| ((m_field[6] == m_field[8]) && (m_field[6] == 2))
					)
				{
					if (m_field[7] == 0)
					{
						m_field[7] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[1] == m_field[4]) && (m_field[1] == 1))
					|| ((m_field[6] == m_field[8]) && (m_field[6] == 1))
					)
				{
					if (m_field[7] == 0)
					{
						m_field[7] = 2;
						doneFlg = true;
					}
				}
				break;
			case 8:
				// 右下.
				if (((m_field[2] == m_field[5]) && (m_field[2] == 2))
					|| ((m_field[0] == m_field[4]) && (m_field[0] == 2))
					|| ((m_field[6] == m_field[7]) && (m_field[6] == 2))
					)
				{
					if (m_field[8] == 0)
					{
						m_field[8] = 2;
						doneFlg = true;
					}
				}
				if (((m_field[2] == m_field[5]) && (m_field[2] == 1))
					|| ((m_field[0] == m_field[4]) && (m_field[0] == 1))
					|| ((m_field[6] == m_field[7]) && (m_field[6] == 1))
					)
				{
					if (m_field[8] == 0)
					{
						m_field[8] = 2;
						doneFlg = true;
					}
				}
				break;
			default:
				break;
			}
		}
		if (doneFlg == true)
		{
			break;
		}
	}
	if (doneFlg == false)
	{
		while (1)
		{
			int n = rand() % 9;
			if (m_field[n] == 0)
			{
				m_field[n] = 2;
				break;
			}
		}
	}
}

// 上級処理.
void CmarubatsuDlg::actDiff3()
{
	// 真ん中を最優先.
	if (m_field[4] == 0)
	{
		m_field[4] = 2;
		return;
	}
	// 設置位置の評価.
	int fieldScore[9];
	for (int num = 0; num < 9; num++)
	{
		fieldScore[num] = 0;
	}
	for (int num = 0; num < 9; num++)
	{
		// 空きブロックのみ評価.
		if (m_field[num] == 0)
		{
			// ----------------------------.
			// CPUリーチ判定
			// ----------------------------.
			switch (num)
			{
			// 一段目.
			case 0:
				// 左上.
				if (((m_field[1] == m_field[2]) && (m_field[1] == 2))
					|| ((m_field[4] == m_field[8]) && (m_field[4] == 2))
					|| ((m_field[3] == m_field[6]) && (m_field[3] == 2))
					)
				{
					fieldScore[0] = 1000;
				}
				if (((m_field[1] == m_field[2]) && (m_field[1] == 1))
					|| ((m_field[4] == m_field[8]) && (m_field[4] == 1))
					|| ((m_field[3] == m_field[6]) && (m_field[3] == 1))
					)
				{
					fieldScore[0] = 900;
					break;
				}
				break;
			case 1:
				// 中上.
				if (((m_field[0] == m_field[2]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[7]) && (m_field[4] == 2))
					)
				{
					fieldScore[1] = 1000;
				}
				if (((m_field[0] == m_field[2]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[7]) && (m_field[4] == 1))
					)
				{
					fieldScore[1] = 900;
				}
				break;
			case 2:
				// 右上.
				if (((m_field[0] == m_field[1]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[6]) && (m_field[4] == 2))
					|| ((m_field[5] == m_field[8]) && (m_field[5] == 2))
					)
				{
					fieldScore[2] = 1000;
				}
				if (((m_field[0] == m_field[1]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[6]) && (m_field[4] == 1))
					|| ((m_field[5] == m_field[8]) && (m_field[5] == 1))
					)
				{
					fieldScore[2] = 900;
				}
				break;
			// 二段目.
			case 3:
				// 左中.
				if (((m_field[0] == m_field[6]) && (m_field[0] == 2))
					|| ((m_field[4] == m_field[5]) && (m_field[4] == 2))
					)
				{
					fieldScore[3] = 1000;
				}
				if (((m_field[0] == m_field[6]) && (m_field[0] == 1))
					|| ((m_field[4] == m_field[5]) && (m_field[4] == 1))
					)
				{
					fieldScore[3] = 900;
				}
				break;
			case 4:
				// 中中.
				if (((m_field[0] == m_field[8]) && (m_field[0] == 2))
					|| ((m_field[1] == m_field[7]) && (m_field[1] == 2))
					|| ((m_field[3] == m_field[5]) && (m_field[3] == 2))
					|| ((m_field[2] == m_field[6]) && (m_field[2] == 2))
					)
				{
					fieldScore[4] = 1000;
				}
				if (((m_field[0] == m_field[8]) && (m_field[0] == 1))
					|| ((m_field[1] == m_field[7]) && (m_field[1] == 1))
					|| ((m_field[3] == m_field[5]) && (m_field[3] == 1))
					|| ((m_field[2] == m_field[6]) && (m_field[2] == 1))
					)
				{
					fieldScore[4] = 900;
				}
				break;
			case 5:
				// 右中.
				if (((m_field[3] == m_field[4]) && (m_field[3] == 2))
					|| ((m_field[2] == m_field[8]) && (m_field[2] == 2))
					)
				{
					fieldScore[5] = 1000;
				}
				if (((m_field[3] == m_field[4]) && (m_field[3] == 1))
					|| ((m_field[2] == m_field[8]) && (m_field[2] == 1))
					)
				{
					fieldScore[5] = 900;
				}
				break;
			// 三段目.
			case 6:
				// 左下.
				if (((m_field[0] == m_field[3]) && (m_field[0] == 2))
					|| ((m_field[2] == m_field[4]) && (m_field[2] == 2))
					|| ((m_field[7] == m_field[8]) && (m_field[7] == 2))
					)
				{
					fieldScore[6] = 1000;
				}
				if (((m_field[0] == m_field[3]) && (m_field[0] == 1))
					|| ((m_field[2] == m_field[4]) && (m_field[2] == 1))
					|| ((m_field[7] == m_field[8]) && (m_field[7] == 1))
					)
				{
					fieldScore[6] = 900;
				}
				break;
			case 7:
				// 中下.
				if (((m_field[1] == m_field[4]) && (m_field[1] == 2))
					|| ((m_field[6] == m_field[8]) && (m_field[6] == 2))
					)
				{
					fieldScore[7] = 1000;
				}
				if (((m_field[1] == m_field[4]) && (m_field[1] == 1))
					|| ((m_field[6] == m_field[8]) && (m_field[6] == 1))
					)
				{
					fieldScore[7] = 900;
				}
				break;
			case 8:
				// 右下.
				if (((m_field[2] == m_field[5]) && (m_field[2] == 2))
					|| ((m_field[0] == m_field[4]) && (m_field[0] == 2))
					|| ((m_field[6] == m_field[7]) && (m_field[6] == 2))
					)
				{
					fieldScore[8] = 1000;
				}
				if (((m_field[2] == m_field[5]) && (m_field[2] == 1))
					|| ((m_field[0] == m_field[4]) && (m_field[0] == 1))
					|| ((m_field[6] == m_field[7]) && (m_field[6] == 1))
					)
				{
					fieldScore[8] = 900;
				}
				break;
			default:
				break;
			}
		}
		// ----------------------------.
		// CPU置き場相対評価
		// ----------------------------.
		else if (m_field[num] == 2)
		{
			switch (num)
			{
			case 0:
				fieldScore[1] = fieldScore[1] + 10;
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[3] = fieldScore[3] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 1:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[7] = fieldScore[7] + 10;
				break;
			case 2:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[1] = fieldScore[1] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[5] = fieldScore[5] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 3:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[5] = fieldScore[5] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				break;
			case 4:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[1] = fieldScore[1] + 10;
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[3] = fieldScore[3] + 10;
				fieldScore[5] = fieldScore[5] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				fieldScore[7] = fieldScore[7] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 5:
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[3] = fieldScore[3] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 6:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[3] = fieldScore[3] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[7] = fieldScore[7] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 7:
				fieldScore[1] = fieldScore[1] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				fieldScore[8] = fieldScore[8] + 10;
				break;
			case 8:
				fieldScore[0] = fieldScore[0] + 10;
				fieldScore[2] = fieldScore[2] + 10;
				fieldScore[4] = fieldScore[4] + 10;
				fieldScore[5] = fieldScore[5] + 10;
				fieldScore[6] = fieldScore[6] + 10;
				fieldScore[7] = fieldScore[7] + 10;
				break;
			default:
				break;
			}
		}
		// ----------------------------.
		// プレイヤー置き場相対評価
		// ----------------------------.
		else if (m_field[num] == 1)
		{
			switch (num)
			{
			case 0:
				fieldScore[1] = fieldScore[1] - 10;
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[3] = fieldScore[3] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 1:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[7] = fieldScore[7] - 10;
				break;
			case 2:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[1] = fieldScore[1] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[5] = fieldScore[5] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 3:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[5] = fieldScore[5] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				break;
			case 4:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[1] = fieldScore[1] - 10;
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[3] = fieldScore[3] - 10;
				fieldScore[5] = fieldScore[5] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				fieldScore[7] = fieldScore[7] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 5:
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[3] = fieldScore[3] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 6:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[3] = fieldScore[3] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[7] = fieldScore[7] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 7:
				fieldScore[1] = fieldScore[1] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				fieldScore[8] = fieldScore[8] - 10;
				break;
			case 8:
				fieldScore[0] = fieldScore[0] - 10;
				fieldScore[2] = fieldScore[2] - 10;
				fieldScore[4] = fieldScore[4] - 10;
				fieldScore[5] = fieldScore[5] - 10;
				fieldScore[6] = fieldScore[6] - 10;
				fieldScore[7] = fieldScore[7] - 10;
				break;
			default:
				break;
			}
		}
		else
		{
			fieldScore[num] = -1000;
		}
	}
	// 評価値の一番高い場所に置く.
	int putPoint = 0;
	int m_score = -1000;
	for (int num = 0; num<9; num++)
	{
		if (m_field[num] != 0)
		{
			continue;
		}
		if (-1000 < fieldScore[num])
		{
			if (m_score < fieldScore[num])
			{
				m_score = fieldScore[num];
				putPoint = num;
			}
		}
		TRACE("[NAK]num=%d,putPoint=%d,fieldScore=%d\n", num, putPoint, fieldScore[num]);
	}
	m_field[putPoint] = 2;
}
