#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tela.h"
#include "desenharLinha.h"
#include "viewPort.h"
#include "poligono.h"

void preenchendoInfoPoligono(poligono *p, char *nome){
    FILE *arq = fopen(nome, "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fscanf(arq, "%d", &p->nVertices);

    //matriz -> int **arestas
    //alocando o espaço da matriz
    p->arestas = (float **) malloc(p->nVertices * sizeof(float *));

    int colunas = 2;
    for(int i=0;i<p->nVertices;i++){
        p->arestas[i] = (float *) malloc(colunas * sizeof(float)); //alocando espaço para 2 colunas por linha
    }

    //preenchendo a matriz
    for(int i=0;i<p->nVertices;i++){
        for(int j=0;j<colunas;j++){
            fscanf(arq, "%f", &p->arestas[i][j]);
        }
    }

    //localizando o maior y e o menor y
    p->yMax = 0;
    p->yMin = 0;
    for(int i=0;i<p->nVertices;i++){
        int j = 1; //referente ao y
        if(p->arestas[i][j] > p->yMax){
            p->yMax = p->arestas[i][j];
        }
        else{
            if(p->arestas[i][j] < p->yMin){
                p->yMin = p->arestas[i][j];
            }
        }
    }

    //localizando o maior x e o menor x
    p->xMax = 0;
    p->xMin = 0;
    for(int i=0;i<p->nVertices;i++){
        int j = 0; //referente ao x
        if(p->arestas[i][j] > p->xMax){
            p->xMax = p->arestas[i][j];
        }
        else{
            if(p->arestas[i][j] < p->xMin){
                p->xMin = p->arestas[i][j];
            }
        }
    }

    fclose(arq);
}



void desenharPoligono(int **tela, poligono *p, float xtranslacao, float ytranslacao, float xescala, float yescala, float angulo){
    //existe uma ordem certa para fazer translação, escala ou rotação?
    //ponto inicial
    float xesIni;
    float xrotIni;
    float xtraIni;
    float yesIni;
    float yrotIni;
    float ytraIni;
    float xIni;
    float yIni;

    //ponto final
    float xesFin;
    float xrotFin;
    float xtraFin;
    float yesFin;
    float yrotFin;
    float ytraFin;
    float xFin;
    float yFin;

    float centrox = (p->xMax + p->xMin)/2;
    float centroy = (p->yMax + p->yMin)/2;

    float translaxIni;
    float translayIni;
    float translaxFin;
    float translayFin;

    int i=0;

    for(i=0;i<p->nVertices-1;i++){
        //translacao para posicionar o objeto no centro (0,0)
        translaxIni = p->arestas[i][0] - centrox;
        translayIni = p->arestas[i][1] - centroy;

        translaxFin = p->arestas[i+1][0] - centrox;
        translayFin = p->arestas[i+1][1] - centroy;

        //escala
        xesIni = translaxIni * xescala;
        yesIni = translayIni * yescala;

        xesFin = translaxFin * xescala;
        yesFin = translayFin * yescala;

        //rotacao
        xrotIni = xesIni * cos(angulo) - yesIni * sin(angulo);
        yrotIni = yesIni * cos(angulo) + xesIni * sin(angulo);

        xrotFin = xesFin * cos(angulo) - yesFin * sin(angulo);
        yrotFin = yesFin * cos(angulo) + xesFin * sin(angulo);

        //translacao
        xtraIni = xrotIni + xtranslacao + centrox;
        ytraIni = yrotIni + ytranslacao + centroy;

        xtraFin = xrotFin + xtranslacao + centrox;
        ytraFin = yrotFin + ytranslacao + centroy;

        xIni = xtraIni;
        yIni = ytraIni;

        xFin = xtraFin;
        yFin = ytraFin;

        //converte de float para int (correspondente a tela)
        ndcToViewport(tela, xIni, yIni, xFin, yFin);
    }

        //translacao para posicionar o objeto no centro (0,0)
        translaxIni = p->arestas[i][0] - centrox;
        translayIni = p->arestas[i][1] - centroy;

        translaxFin = p->arestas[0][0] - centrox;
        translayFin = p->arestas[0][1] - centroy;

        //escala
        xesIni = translaxIni * xescala;
        yesIni = translayIni * yescala;

        xesFin = translaxFin * xescala;
        yesFin = translayFin * yescala;

        //rotacao
        xrotIni = xesIni * cos(angulo) - yesIni * sin(angulo);
        yrotIni = yesIni * cos(angulo) + xesIni * sin(angulo);

        xrotFin = xesFin * cos(angulo) - yesFin * sin(angulo);
        yrotFin = yesFin * cos(angulo) + xesFin * sin(angulo);

        //translacao
        xtraIni = xrotIni + xtranslacao + centrox;
        ytraIni = yrotIni + ytranslacao + centroy;

        xtraFin = xrotFin + xtranslacao + centrox;
        ytraFin = yrotFin + ytranslacao + centroy;

        xIni = xtraIni;
        yIni = ytraIni;

        xFin = xtraFin;
        yFin = ytraFin;

        //converte de float para int (correspondente a tela)
        ndcToViewport(tela, xIni, yIni, xFin, yFin);
}








