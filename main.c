#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tela.h"
#include "desenharLinha.h"
#include "viewPort.h"
#include "poligono.h"


int main()
{
    int i, j;
    int x0, x1, y0, y1;
    int **tela;

    tela = criaTela(nColuna, nLinha);


    //os angulos precisam ser passados em radianos
    float pi = M_PI; //pi

    //triangulo
    poligono p1;
    preenchendoInfoPoligono(&p1, "trianguloNDC.dcg");
    float triangulotx = 1.5;
    float trianguloty = 0.15;
    float trianguloex = 1;
    float trianguloey = 0.5;
    float trianguloa = 0;
    desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);

    //casa
    poligono p2;
    preenchendoInfoPoligono(&p2, "casaNDC.dcg");
    float casatx = -0.5;
    float casaty = -2.6;
    float casaex = 0.5;
    float casaey = 0.1;
    float casaa = 0;
    desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

    //estrela
    poligono p3;
    preenchendoInfoPoligono(&p3, "estrelaNDC.dcg");
    float estrelatx = -0.5;
    float estrelaty = 0.85;
    float estrelaex = 1.2;
    float estrelaey = 0.5;
    float estrelaa = 0;
    desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

    if(tela != NULL)  imprimeTela(tela);
    else printf("Frame n�o aceito\n");


    int menu=0;

    while(menu!=13){
    printf("Escolha uma opcao do menu: \n");
    printf("\n");
    printf("TRANSLACAO\n");
    printf("1- mover o objeto para a direita\n");
    printf("2- mover o obejto para a esquerda\n");
    printf("3- mover o objeto para cima\n");
    printf("4- mover o objeto para baixo\n");

    printf("\n");
    printf("ESCALA\n");
    printf("5- dobrar o tamanho do objeto\n");
    printf("6- reduzir o tamanho do objeto pela metade\n");
    printf("7- dobrar o tamanho no eixo x\n");
    printf("8- dobrar o tamanho no eixo y\n");

    printf("\n");
    printf("ROTACAO\n");
    printf("9- rodar o objeto 30 graus\n");
    printf("10- rodar o objeto 90 graus\n");
    printf("11- rodar o objeto 180 graus\n");
    printf("12- rodar o objeto 360 graus\n");


    printf("\n");
    printf("13- sair\n");
    printf("\n");

    scanf("%d", &menu);

    while(menu < 1 || menu > 13){
        printf("Valor invalido, digite novamente: ");
        scanf("%d", &menu);
    }

    switch(menu){
        int opcao=0;

        //mover para a direita
        case 1:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casatx = casatx + 0.5;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelatx = estrelatx + 0.5;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                triangulotx = triangulotx + 0.5;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                triangulotx = triangulotx + 0.5;
                casatx = casatx + 0.5;
                estrelatx = estrelatx + 0.5;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }

        break;


        //mover para a esquerda
        case 2:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casatx = casatx - 0.5;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelatx = estrelatx - 0.5;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                triangulotx = triangulotx - 0.5;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                triangulotx = triangulotx - 0.5;
                casatx = casatx - 0.5;
                estrelatx = estrelatx - 0.5;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;


        //mover para cima
        case 3:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaty = casaty + 0.085;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaty = estrelaty + 0.085;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloty = trianguloty + 0.085;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloty = trianguloty + 0.085;
                casaty = casaty + 0.085;
                estrelaty = estrelaty + 0.085;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }

        break;


        //mover para baixo
        case 4:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaty = casaty - 0.085;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaty = estrelaty - 0.085;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloty = trianguloty - 0.085;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloty = trianguloty - 0.085;
                casaty = casaty - 0.085;
                estrelaty = estrelaty - 0.085;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //dobrar o tamanho do objeto
        case 5:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaex = casaex*2;
                casaey = casaey*2;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaex = estrelaex*2;
                estrelaey = estrelaey*2;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloex = trianguloex*2;
                trianguloey = trianguloey*2;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloex = trianguloex*2;
                casaex = casaex*2;
                estrelaex = estrelaex*2;
                trianguloey = trianguloey*2;
                casaey = casaey*2;
                estrelaey = estrelaey*2;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;


        //reduzir o tamanho do objeto
        case 6:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaex = casaex*0.5;
                casaey = casaey*0.5;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaex = estrelaex*0.5;
                estrelaey = estrelaey*0.5;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloex = trianguloex*0.5;
                trianguloey = trianguloey*0.5;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloex = trianguloex*0.5;
                casaex = casaex*0.5;
                estrelaex = estrelaex*0.5;
                trianguloey = trianguloey*0.5;
                casaey = casaey*0.5;
                estrelaey = estrelaey*0.5;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //dobrar o tamanho do objeto no eixo x
        case 7:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaex = casaex*2;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaex = estrelaex*2;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloex = trianguloex*2;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloex = trianguloex*2;
                casaex = casaex*2;
                estrelaex = estrelaex*2;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //dobrar o tamanho do objeto no eixo y
        case 8:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaey = casaey*2;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaey = estrelaey*2;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloey = trianguloey*2;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloey = trianguloey*2;
                casaey = casaey*2;
                estrelaey = estrelaey*2;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //rotacao 30°
        case 9:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaa = (pi/5);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaa = (pi/5);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloa = (pi/5);
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloa = (pi/5);
                casaa = (pi/5);
                estrelaa = (pi/5);

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //rotacao 90°
        case 10:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaa = (pi/2);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaa = (pi/2);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloa = (pi/2);
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloa = (pi/2);
                casaa = (pi/2);
                estrelaa = (pi/2);

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;



        //rotacao 180°
        case 11:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaa = pi;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaa = pi;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloa = pi;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloa = pi;
                casaa = pi;
                estrelaa = pi;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }

        break;



        //rotacao 360°
        case 12:
            printf("Qual objeto voce deseja alterar: \n");
            printf("1- Casa\n");
            printf("2- Estrela\n");
            printf("3- Triangulo\n");
            printf("4- Todos\n");

            scanf("%d", &opcao);

            while(opcao < 1 || opcao > 4){
            printf("Valor invalido, digite novamente: ");
            scanf("%d", &opcao);
            }

            switch(opcao){
            case 1:
                limparTela(tela);
                casaa = 0;
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 2:
                limparTela(tela);
                estrelaa = 0;
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);


                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 3:
                limparTela(tela);
                trianguloa = 0;
                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);


                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;

            case 4:
                limparTela(tela);
                trianguloa = 0;
                casaa = 0;
                estrelaa = 0;

                desenharPoligono(tela, &p1, triangulotx, trianguloty, trianguloex, trianguloey, trianguloa);
                desenharPoligono(tela, &p2, casatx, casaty, casaex, casaey, casaa);
                desenharPoligono(tela, &p3, estrelatx, estrelaty, estrelaex, estrelaey, estrelaa);

                if(tela != NULL)  imprimeTela(tela);
                else printf("Frame n�o aceito\n");

                break;
            }


        break;

    }

    }

    printf("Muitooo legaaal\n");


    //liberando a memória alocada da matriz
    //p1
    for(int i=0;i<p1.nVertices;i++){
        free(p1.arestas[i]);
    }
    free(p1.arestas);

    //p2
    for(int i=0;i<p2.nVertices;i++){
        free(p2.arestas[i]);
    }
    free(p2.arestas);

    //p3
    for(int i=0;i<p3.nVertices;i++){
        free(p3.arestas[i]);
    }
    free(p3.arestas);

    return 0;
}

