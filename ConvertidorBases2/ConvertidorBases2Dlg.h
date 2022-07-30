
// ConvertidorBases2Dlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CConvertidorBases2Dlg
class CConvertidorBases2Dlg : public CDialogEx
{
	// Construcción
public:
	CConvertidorBases2Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONVERTIDORBASES2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdtNum();
private:
	CString m_cad;
	long m_num;
	char m_aux[30];
public:
	afx_msg void OnBnClickedRadDecimal();
	afx_msg void OnBnClickedRadOctal();
	afx_msg void OnBnClickedRadHexa();
	afx_msg void OnBnClickedRadBin();
private:
	//BOOL m_decimal;
	CButton m_ctrlDecimal;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnArchivoSalir();
	afx_msg void OnAyudaAcercade();
};
