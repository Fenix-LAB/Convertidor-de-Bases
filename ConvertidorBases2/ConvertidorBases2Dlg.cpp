
// ConvertidorBases2Dlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "ConvertidorBases2.h"
#include "ConvertidorBases2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CConvertidorBases2Dlg



CConvertidorBases2Dlg::CConvertidorBases2Dlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CONVERTIDORBASES2_DIALOG, pParent)
	, m_cad(_T(""))
	, m_num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertidorBases2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Radio(pDX, IDC_RAD_DECIMAL, m_decimal);
	DDX_Control(pDX, IDC_RAD_DECIMAL, m_ctrlDecimal);
}

BEGIN_MESSAGE_MAP(CConvertidorBases2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDT_NUM, &CConvertidorBases2Dlg::OnEnChangeEdtNum)
	ON_BN_CLICKED(IDC_RAD_DECIMAL, &CConvertidorBases2Dlg::OnBnClickedRadDecimal)
	ON_BN_CLICKED(IDC_RAD_OCTAL, &CConvertidorBases2Dlg::OnBnClickedRadOctal)
	ON_BN_CLICKED(IDC_RAD_HEXA, &CConvertidorBases2Dlg::OnBnClickedRadHexa)
	ON_BN_CLICKED(IDC_RAD_BIN, &CConvertidorBases2Dlg::OnBnClickedRadBin)
	ON_BN_CLICKED(IDOK, &CConvertidorBases2Dlg::OnBnClickedOk)
	ON_COMMAND(ID_ARCHIVO_SALIR, &CConvertidorBases2Dlg::OnArchivoSalir)
	ON_COMMAND(ID_AYUDA_ACERCADE, &CConvertidorBases2Dlg::OnAyudaAcercade)
END_MESSAGE_MAP()


// Controladores de mensajes de CConvertidorBases2Dlg

BOOL CConvertidorBases2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	//CButton* pBoton;
	//pBoton = (CButton*)GetDlgItem(IDC_RAD_DECIMAL);
	//pBoton->SetCheck(1);
	//UpdateData(false);
	m_ctrlDecimal.SetCheck(1);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CConvertidorBases2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CConvertidorBases2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CConvertidorBases2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CConvertidorBases2Dlg::OnEnChangeEdtNum()
{
	int seleccion;
	GetDlgItemText(IDC_EDT_NUM, m_cad);

	seleccion = GetCheckedRadioButton(IDC_RAD_DECIMAL, IDC_RAD_BIN);

	switch (seleccion) {
	case IDC_RAD_DECIMAL: m_num = wcstol(m_cad, NULL, 10);
		break;
	case IDC_RAD_OCTAL: m_num = wcstol(m_cad, NULL, 8);
		break;
	case IDC_RAD_HEXA: m_num = wcstol(m_cad, NULL, 16);
		break;
	case IDC_RAD_BIN: m_num = wcstol(m_cad, NULL, 2);
		break;
	}

}

void CConvertidorBases2Dlg::OnBnClickedRadDecimal()
{
	_itoa_s(m_num, m_aux, 10);
	m_cad = m_aux;
	SetDlgItemText(IDC_EDT_NUM, m_cad);
}

void CConvertidorBases2Dlg::OnBnClickedRadOctal()
{
	sprintf_s(m_aux, "%o", m_num);  //forma alternativa
	m_cad = m_aux;
	SetDlgItemText(IDC_EDT_NUM, m_cad);
}


void CConvertidorBases2Dlg::OnBnClickedRadHexa()
{
	_itoa_s(m_num, m_aux, 16);
	m_cad = m_aux;
	SetDlgItemText(IDC_EDT_NUM, m_cad);
}


void CConvertidorBases2Dlg::OnBnClickedRadBin()
{
	_itoa_s(m_num, m_aux, 2);
	m_cad = m_aux;
	SetDlgItemText(IDC_EDT_NUM, m_cad);
}


void CConvertidorBases2Dlg::OnBnClickedOk()
{
	int seleccion;
	seleccion = AfxMessageBox(_T("Estas seguro de que deaseas salir?"), MB_YESNO | MB_ICONQUESTION);

	if (seleccion == IDYES) {
		CDialogEx::OnOK();
	}
}


void CConvertidorBases2Dlg::OnArchivoSalir()
{
	OnBnClickedOk();
}


void CConvertidorBases2Dlg::OnAyudaAcercade()
{
	CAboutDlg dlg;
	dlg.DoModal();
}
