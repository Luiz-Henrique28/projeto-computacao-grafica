#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //*************************************************************************
    // Chame aqui as funções do mygl.h
    //*************************************************************************
    
    int width = IMAGE_WIDTH;
    int height = IMAGE_HEIGHT;
    
    DrawLine(0, height / 2, width, height / 2, 255, 0, 0, 255); // Vermelho
    
    DrawLine(width / 2, 0, width / 2, height, 0, 255, 0, 255); // Verde
    
    DrawLine(0, 0, width, height, 0, 0, 255, 255); // Azul
    
    DrawLine(width, 0, 0, height, 255, 255, 0, 255); // Amarelo

    DrawLine(0, height, width, 0, 255, 0, 255, 255); // Magenta

    DrawLine(width, height, 0, 0, 0, 255, 255, 255); // Ciano

    DrawLine(0, height / 4, width, (3 * height) / 4, 255, 128, 0, 255); // Laranja

    DrawLine(width, height / 4, 0, (3 * height) / 4, 128, 0, 255, 255); // Roxo

    DrawLine((3 * width) / 4, 0, width / 4, height, 0, 255, 128, 255); // Verde-claro

    DrawLine(width / 4, 0, (3 * width) / 4, height, 255, 0, 255, 255); // Rosa

    // (x0, y0), (x1, y1), (x2, y2), r, g, b, a
    DrawTriangle(100, 100, 200, 150, 150, 250, 255, 0, 0, 255); 

    // (x0, y0), (x1, y1), (x2, y2), r, g, b, a
    DrawTriangle(300, 300, 400, 350, 350, 450, 0, 255, 0, 255);  

    // (x0, y0), (x1, y1), (x2, y2), r, g, b, a
    DrawTriangle(50, 400, 120, 450, 80, 500, 0, 0, 255, 255);    

    // (x0, y0), (x1, y1), (x2, y2), r, g, b, a
    DrawTriangle(200, 50, 250, 100, 150, 120, 255, 255, 0, 255);
}


void PutPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    int index = (x + y * IMAGE_WIDTH) * 4;
    FBptr[index] = r;   // Componente vermelha
    FBptr[index + 1] = g; // Componente verde
    FBptr[index + 2] = b; // Componente azul
    FBptr[index + 3] = a; // Componente alpha
}

void DrawLine(int x0, int y0, int x1, int y1, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {

    // Algoritmo de Bresenham
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        // Desenha o pixel na posição atual
        PutPixel(x0, y0, r, g, b, a);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    
    // Desenha 3 linhas que se interligam
    DrawLine(x0, y0, x1, y1, r, g, b, a); // Linha do ponto (x0, y0) para (x1, y1)
    DrawLine(x1, y1, x2, y2, r, g, b, a); // Linha do ponto (x1, y1) para (x2, y2)
    DrawLine(x2, y2, x0, y0, r, g, b, a); // Linha do ponto (x2, y2) para (x0, y0)
}
