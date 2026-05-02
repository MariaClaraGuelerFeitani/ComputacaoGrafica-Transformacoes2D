#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

typedef struct Poligono{
    int nVertices;
    float **arestas;
    float yMin;
    float yMax;
    float xMin;
    float xMax;
    int **escanearIntersecoes;
} poligono;

void preenchendoInfoPoligono(poligono *p, char *nome);
void desenharPoligono(int **tela, poligono *p, float xtranslacao, float ytranslacao, float xescala, float yescala, float angulo);



#endif // POLIGONO_H_INCLUDED
