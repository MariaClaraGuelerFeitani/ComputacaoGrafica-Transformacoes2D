#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tela.h"
#include "desenharLinha.h"
#include "viewPort.h"
#include "poligono.h"

//Converte coordenadas do sistema NDC (−1 a 1) para coordenadas da tela (viewport), permitindo que os pontos sejam posicionados corretamente no dispositivo
void ndcToViewport(int **tela, float x1, float y1, float x2, float y2){
    int xa, xb, ya, yb;
    //printf("Valores unificado: x1: %f, y1: %f, x2: %f, y2: %f\n", x1, y1, x2, y2);
    xa = WIDTH * ((x1 + 1)/2);
    xb = WIDTH * ((x2 + 1)/2);
    ya = HEIGHT * ((-y1 + 1)/2);
    yb = HEIGHT * ((-y2 + 1)/2);
    //printf("Valores dispositivo: xa: %d, ya: %d, xb: %d, yb: %d\n", xa, ya, xb, yb);

    //desenha as linhas
    plotLine(tela, xa, ya, xb, yb);
}
