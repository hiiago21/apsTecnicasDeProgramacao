#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

//função apenas para facilitar a limpeza das telas
void limpaTela() {
    system("CLS");
}

typedef struct faceis{char a[200], r[2],p[2];}facil;
typedef struct medias{char a[200], r[2],p[2];}media;
typedef struct dificeis{char a[200], r[2],p[2];}dificil;
typedef struct{char questao[200],resposta[2],tipo[2];} pergunta;

facil pfacil[20];
media pmedia[20];
dificil pdifi[20];

//aqui são as 3 funções destinadas para abertura leitura das perguntas
//estas função são usada na função jogo pois conforme o jogo anda muda o nivel das perguntas
void PerguntasFaceis(){
    FILE *fp;
    fp = fopen("PerguntasFaceis.txt","rt");
    if(fp==NULL){
        printf("erro em executar arquivo");
    }

    for(int i = 0; i<21; i++){
        fgets(pfacil[i].p,2,fp);
        fgets(pfacil[i].a,200,fp);
    }
    fclose(fp);
    };
void PerguntasMedias(){
    FILE *fp;
    fp = fopen("PerguntasMedias.txt","rt");
    if(fp==NULL){
        printf("erro em executar arquivo");
    }

    for(int i = 0; i<21; i++){
        fgets(pmedia[i].p,2,fp);
        fgets(pmedia[i].a,200,fp);
    }
    fclose(fp);
    };
void PerguntasDificeis(){
    FILE *fp;
    fp = fopen("PerguntasDificeis.txt","rt");
    if(fp==NULL){
        printf("erro em executar arquivo");
    }

    for(int i = 0; i<21; i++){
        fgets(pdifi[i].p,2,fp);
        fgets(pdifi[i].a,200,fp);
    }
    fclose(fp);
    };

//esta é a função da opção 3 do menu ela passa as informações pro usuario inserir uma nova pergunta
//ele solicita o nivel que ele quer para poder escolher qual arquivo deseja abrir
// após isto solicita a pergunta e sua resposta as gravas em um struct
// abre o arquivo as inseri e o fecha

void gravaPerguntas(){
    pergunta p[1];
    char escolha;
    printf("Qual nivel de pergunta gostaria de inserir?\n");
    printf("F - Fácil\nM - Médio\nD - Difícil");
    fflush(stdin);
    printf("\nInsira o nivel aqui: ");
    scanf_s("%s", &p->tipo );

    fflush(stdin);
    printf("Insira a pergunta aqui: ");
    fgets(&p -> questao, 200, stdin);

    fflush(stdin);
    printf("Insira a resposta aqui: ");
    fgets(&p -> resposta,2,stdin);

    if(p[0].tipo[0] == 'f' || p[0].tipo[0] == 'F'){
        FILE *fp;
        fp = fopen("./PerguntasFaceis.txt","a");
        if(fp==NULL){
            printf("erro em executar arquivo");
        }
        printf("%s%s", &p->resposta , &p->questao);
       fprintf(fp,"%s%s", &p->resposta , &p->questao);

       fclose(fp);

    }else if(p[0].tipo[0]== 'm' || p[0].tipo[0] == 'M'){
        FILE *fp;
        fp = fopen("./PerguntasMedias.txt","a");
        if(fp==NULL){
            printf("erro em executar arquivo");
        }

       fprintf(fp,"%s%s", p->resposta,p->questao);
       fclose(fp);

        }else if(p[0].tipo[0] == 'd' || p[0].tipo[0] == 'D'){
            FILE *fp;
            fp = fopen("./PerguntasDificeis.txt","a");
            if(fp==NULL){
                printf("erro em executar arquivo");
            }

            fprintf(fp,"%s%s", p->resposta,p->questao);
            fclose(fp);

            }


    printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Inserir outra pergunta \n 3 - Sair \n Escolha e aperte Enter: ");
    int opcao;
    scanf("%d", &opcao);
    if(opcao ==1){
        limpaTela();
        menuJogo();
    }else if(opcao ==2){
        limpaTela();
        gravaPerguntas();
      }else{
            return 0;
        }
}

// esta função é usada ao final do jogo para inserir o ganhador da partida no ranking
void insereRanking(char nome[15], int pontuacao) {
    FILE *fp;

    fp = fopen("RankingTeste.txt", "a");

    if (fp == NULL) {
        printf("Erro em abrir o arquivo");
    }

    else{
        fprintf(fp,"%d%s", pontuacao, nome);
    }
    fclose(fp);
    printf("Foi inserido %d e %s", pontuacao, nome);
}



//algoritmo de sort, perceba que aqui eu ordeno os dois vetores (nome e pontuação)

void bubbleSort(int* pontuacao, char nomes[10][15], int tamanho)
{
    int i;
    int trocou;
    do
    {
        trocou = 0;
    for (i=tamanho-1; i > 0; i--)
    {
        if (pontuacao[i] > pontuacao[i-1])
        {
            int pAux;
            char nAux[255];
            pAux = pontuacao[i];
            strcpy(nAux, nomes[i]);
            pontuacao[i] = pontuacao[i-1];
            strcpy(nomes[i], nomes[i-1]);
            pontuacao[i-1] = pAux;
            strcpy(nomes[i-1], nAux);
            trocou = 1;
        }
    }

    }while (trocou);
}



void ranking(){

    //system("clear");
    printf("\n ######- Ranking de Jogadores -######\n");
    printf("  \n");
    printf(" NOME - PONTOS \n");
    printf("  \n");

    // cria ponteiro de arquivo
    FILE * pont_arq;
    //abrindo o arquivo_frase em modo "somente leitura"
    pont_arq = fopen("RankingTeste.txt", "r");
    // cria matriz para 10 nomes (poderia ser dinamico) e array de pontuações
    char nomes[10][15];
    int pontuacoes[10];
    //variaveis que irá receber o nome ea pontuação do arquivo
    char nome[15];
    int pontuacao;
    //quantidade de jogadores
    int tamanho = 0;

    //lê do arquivo
    while(fscanf(pont_arq, "%d   %s\n",  &pontuacao, nome) != EOF)
    {
        strcpy(nomes[tamanho],nome);
        pontuacoes[tamanho] = pontuacao;
        tamanho++;
    }

    //Ordena
    bubbleSort(pontuacoes, nomes, tamanho);

    //Imprime
    int i;
    for (i=0; i<tamanho; i++)
    {
        printf("%s %d\n", nomes[i], pontuacoes[i]);
    }

    fclose(pont_arq);
    printf("\n");
}
