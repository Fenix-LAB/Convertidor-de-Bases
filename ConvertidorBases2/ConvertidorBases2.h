
// ConvertidorBases2.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CConvertidorBases2App:
// Consulte ConvertidorBases2.cpp para obtener información sobre la implementación de esta clase
//

class CConvertidorBases2App : public CWinApp
{
public:
	CConvertidorBases2App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CConvertidorBases2App theApp;
