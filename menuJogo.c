#include "lib/utilidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void menuJogo(){
    setlocale(LC_ALL, "Portuguese");
    char jogA[20], jogB[20];
    int ptA=0, ptB=0;
    int opcaoEscolhida = 0;
    while(opcaoEscolhida < 1 || opcaoEscolhida > 3){
    void limpaTela();

    printf("Bem-Vindo ao Quiz\n\n\n");
    printf("Escolha uma da opções a baixo");
    printf("\n1- Jogar");
    printf("\n2- Inserir Pergunta");
    printf("\n3- Ranking");
    printf("\n4- Sobre");
    printf("\n5- Sair");
    printf("\nDigite da opção e aperte Enter:");
    scanf("%d", &opcaoEscolhida);

     switch(opcaoEscolhida){
        case 1:
            printf("Digite o nome dos jogadores\n");
            printf("Jogador 1: ");
            setbuf(stdin,0);
            fgets(jogA, 20, stdin);

            printf("Jogador 2: ");
            setbuf(stdin,0);
            fgets(jogB, 20, stdin);

       Jogo(jogA, &ptA, jogB, &ptB);

        break;

        case 2:
            gravaPerguntas();
            printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Sair \n Escolha e aperte Enter: ");
            int opcao;
            scanf("%d", &opcao);
            if(opcao ==1){
                limpaTela();
                menuJogo();
                }else{
                   break;
                }
            break;

        case 3:
            //ranking
            break;

        case 4:
            printf("\n\nJogo desenvolvido por:\nHiago Silva da Silva\nLeonardo Oliveira de Farias\nGabriel Luis Mendes\n");
                   printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Sair \n Escolha e aperte Enter: ");
                    opcao;
                   scanf("%d", &opcao);
                   if(opcao ==1){
                       limpaTela();
                        menuJogo();
                   }else{
                   break;
                   }
        break;

        case 5:
            printf("\n\nAté mais!\n\n");
        break;
    }
 }
}

typedef struct faceis{char a[200], r[2],p[2];}facil;
typedef struct medias{char a[200], r[2],p[2];}media;
typedef struct dificeis{char a[200], r[2],p[2];}dificil;


facil pfacil[20];
media pmedia[20];
dificil pdifi[20];

void Jogo(char jogA[20], int *ptA, char jogB[20], int *ptB ){
        system("cls");
        int cont = 0;


  //perguntas fáceis
        for(int j = 0; j<2; j++){
        PerguntasFaceis();
        printf("Perguntas fáceis\n");

        if(cont == 0){

        printf("Turno do jogador: %s", jogA);
        int h = rand()%20;
        printf("%s", pfacil[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pfacil[h].r);
        int x = strcmp(pfacil[h].p,pfacil[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptA = ptA+1;
        }else{
            printf("Errou!!\n");
             ptA = ptA-1;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont++;
       }

        else if(cont == 1){

        printf("Turno do jogador: %s", jogB);
        int h = rand()%20;
        printf("%s", pfacil[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pfacil[h].r);
        int x = strcmp(pfacil[h].p,pfacil[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptB = ptB+1;
        }else{
            printf("Errou!!\n");
            ptB = ptB-1;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont--;
        }
        }

     //perguntas medias

        for(int j = 0; j<2; j++){
        PerguntasMedias();
        printf("Perguntas Medias\n");

        if(cont == 0){
        printf("Turno do jogador: %s", jogA);
        int h = rand()%20;
        printf("%s", pmedia[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pmedia[h].r);
        int x = strcmp(pmedia[h].p,pmedia[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptA = ptA+2;
        }else{
            printf("Errou!!\n");
            ptA = ptA-2;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont++;
        }

        else if(cont == 1){
        printf("Turno do jogador: %s", jogB);
        int h = rand()%20;
        printf("%s", pmedia[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pmedia[h].r);
        int x = strcmp(pmedia[h].p,pmedia[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptB = ptB+2;
        }else{
            printf("Errou!!\n");
            ptB = ptB-2;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont--;
        }
        }



          //perguntas dificeis

        for(int j = 0; j<2; j++){
        PerguntasDificeis();
        printf("Perguntas Medias\n");

        if(cont == 0){
        printf("Turno do jogador: %s", jogA);
        int h = rand()%20;
        printf("%s", pdifi[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pdifi[h].r);
        int x = strcmp(pdifi[h].p,pdifi[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptA = ptA+4;
        }else{
            printf("Errou!!\n");
            ptA = ptA-4;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont++;
        }

        else if(cont == 1){
        printf("Turno do jogador: %s", jogB);
        int h = rand()%20;
        printf("%s", pdifi[h].a);
        printf("v - Verdadeiro\nf - Falso\n");
        scanf ("%s", pdifi[h].r);
        int x = strcmp(pdifi[h].p,pdifi[h].r);
        if(x == 0){
            printf("Resposta certa\n");
            ptA = ptA+4;
        }else{
            printf("Errou!!\n");
            ptA = ptA-4;
        }
        fflush(stdin);
        system("pause");
        system("cls");
        cont--;
        }

        }

        if(ptA > ptB){
            printf("A ganhou");
        }else if(ptB>ptA){
            printf("B ganhou");
        }else{
            printf("Empate");
        }
//    insereRanking()
};










