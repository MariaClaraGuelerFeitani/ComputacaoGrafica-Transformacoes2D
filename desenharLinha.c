#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tela.h"
#include "desenharLinha.h"
#include "viewPort.h"
#include "poligono.h"

void plotLineHorizontal(int ** tela, int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int D = 2*abs(dy) - dx;
    int y = y0;
    int x;

    int dir = 1; //octante 7

    if(dy < 0){ //octante 0
        dir = -1;
    }

    for(x=x0; x<=x1; x++){
        if(x<0 || x>HEIGHT-1 || y<0 || y>WIDTH-1){

        }
        else{
            tela[y][x] = 1;
        }
        if(D>0){
            y = y + dir;
            D = D + 2*(abs(dy) - dx);
        }
        else{
            D = D + 2*abs(dy);
        }
    }
}

void plotLineVertical(int **tela, int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int D = 2*abs(dx) - dy;
    int x = x0;
    int y;

    int dir = 1;

    if(dx < 0){
        dir = -1;
    }

    for(y=y0; y<=y1;y++){
        if(x<0 || x>HEIGHT-1 || y<0 || y>WIDTH-1){

        }
        else{
            tela[y][x] = 1;
        }
        if(D>0){
            x = x + dir;
            D = D + 2*(abs(dx) - dy);
        }
        else{
            D = D + 2*abs(dx);
        }
    }
}

void plotLine(int **tela, int x0, int y0, int x1, int y1){
    if(abs(x1 - x0) > abs(y1 - y0)){
        if(x0>x1){
            plotLineHorizontal(tela, x1, y1, x0, y0); //octante 3 e 4
        }
        else{
            plotLineHorizontal(tela, x0, y0, x1, y1); //octante 0 e 7
        }
    }
    else{
        if(y0>y1){
            plotLineVertical(tela, x1, y1, x0, y0); //octante 2 e 5
        }
        else{
            plotLineVertical(tela, x0, y0, x1, y1); //octante 1 e 6
        }
    }
}
