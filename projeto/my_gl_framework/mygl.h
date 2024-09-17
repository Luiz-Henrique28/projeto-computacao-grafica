#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void PutPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, unsigned char a);