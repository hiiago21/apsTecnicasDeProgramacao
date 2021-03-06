#include "lib/utilidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void menuJogo(){
    setlocale(LC_ALL, "Portuguese");
    char jogA[15], jogB[15];
    int ptA=0, ptB=0;
    int opcaoEscolhida = 0;
    while(opcaoEscolhida > 1 || opcaoEscolhida < 5){
    void limpaTela();

    printf("Bem-Vindo ao Quiz\n\n\n");
    printf("Escolha uma da op��es a baixo");
    printf("\n1- Jogar");
    printf("\n2- Inserir Pergunta");
    printf("\n3- Ranking");
    printf("\n4- Sobre");
    printf("\n5- Sair");
    printf("\nDigite da op��o e aperte Enter:");
    scanf("%d", &opcaoEscolhida);

    //Abertura do jogo aqui aonde escolhemos o que desejamos fazer no jogo
     switch(opcaoEscolhida){
        //nesta op��o definimos os nomes dos dois jogadores e passamos o nome do jogador
        //e a pontua��o inicial
        case 1:
            printf("Digite o nome dos jogadores\n");
            printf("Jogador 1: ");
            setbuf(stdin,0);
            fgets(jogA, 15, stdin);

            printf("Jogador 2: ");
            setbuf(stdin,0);
            fgets(jogB, 15, stdin);

       Jogo(jogA, ptA, jogB, ptB);

        break;

        case 2:
            //chamamos a fun��o que ira� gravar as perguntas
            gravaPerguntas();
            break;
        case 3:
            ranking();
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

        case 4:
            limpaTela();
            printf("\n\nJogo desenvolvido por:\nHiago Silva da Silva\nLeonardo Oliveira de Farias\nGabriel Luis Mendes\n");
            printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Sair \n Escolha e aperte Enter: ");
            scanf("%d", &opcao);
            if(opcao ==1){
                limpaTela();
                menuJogo();
            }else{
                break;
            }
        break;

        case 5:
            printf("\n\nAt� mais!\n\n");
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

//no jogo fazemos a abertura do arquivo com o carregamento das perguntas
//geramos um randomico para as perguntas nao serem repetidas
// e guardamos as mesma em uma struct
//jogador acertando ganha pontua��o errando perde a pontua��o
//ao final verificamos o vencedor pela pontua��o e chamamos
//as fun��es inserir no ranking com o nome e apontua��o
// ap�s passamos op��o de jogar novamente com os mesmos participantes ou reiniciar todo jogo

void Jogo(char jogA[20], int ptA, char jogB[20], int ptB ){
        system("cls");
        int cont = 0;
        srand(time(NULL));

  //perguntas f�ceis
        for(int j = 0; j<4; j++){
        PerguntasFaceis();
        printf("Perguntas f�ceis\n");

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
        limpaTela();
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
        limpaTela();
        cont--;
        }
        }

     //perguntas medias

        for(int j = 0; j<4; j++){
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
        limpaTela();
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
        limpaTela();
        cont--;
        }
        }



          //perguntas dificeis

        for(int j = 0; j<6; j++){
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
        limpaTela();
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
            ptB = ptB+4;
        }else{
            printf("Errou!!\n");
            ptB = ptB-4;
        }
        fflush(stdin);
        system("pause");
        limpaTela();
        cont--;
        }

        }

        if(ptA > ptB){
            printf("\n----------- Ganhou com pontua��o de %d foi %s", ptA,jogA);
            insereRanking(jogA,ptA);
        }else if(ptB > ptA){
            printf("\n----------- Ganhou com pontua��o de %d foi %s", ptB,jogB);
            insereRanking(jogB,ptB);
        }else{
            printf("*************** Empate sem pontua��o *************\n");
        }

        printf(" O que deseja fazer:\n(1)- Menu principal \n(2) - Jogar novamente \n(3) - Sair?\n");
        int opc;
        scanf("%d", &opc);
        if(opc == 1){
            menuJogo();
        }else if(opc == 2){
            Jogo(jogA,ptA,jogB,ptB);
        }else{
            return;
        }

};










