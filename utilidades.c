#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void limpaTela() {
    system("CLS");
}

typedef struct faceis{char a[200], r[2],p[2];}facil;
typedef struct medias{char a[200], r[2],p[2];}media;
typedef struct dificeis{char a[200], r[2],p[2];}dificil;


facil pfacil[20];
media pmedia[20];
dificil pdifi[20];


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

void gravaPerguntas(){
    char escolha;
    printf("Qual nivel de pergunta gostaria de inserir?\n");
    printf("F - Fácil\nM - Médio\nD - Difícil");
    scanf("%c", &escolha);
    printf("\nInsira o nivel aqui: "); scanf("%c", &escolha);


    printf("%c", escolha);

    char pergunta[200];
    setbuf(stdin,0);
    printf("\nInsira a pergunta aqui: ");
    fgets(pergunta, 200, stdin);

    printf("Insira a resposta aqui: ");
    char resposta;
    scanf("%c", &resposta);

    if(escolha == 'f' || escolha == 'F'){
        FILE *fp;
        fp = fopen("PerguntasFaceis.txt","a");
        if(fp==NULL){
            printf("erro em executar arquivo");
        }

       fprintf(fp,"%c%s", resposta,pergunta);

       fclose(fp);

    }else if(escolha == 'm' || escolha == 'M'){
        FILE *fp;
        fp = fopen("PerguntasMedias.txt","a");
        if(fp==NULL){
            printf("erro em executar arquivo");
        }

       fprintf(fp,"%c%s", resposta,pergunta);
       fclose(fp);

        }else if(escolha == 'd' || escolha == 'D'){
            FILE *fp;
            fp = fopen("PerguntasDificeis.txt","a");
            if(fp==NULL){
                printf("erro em executar arquivo");
            }

            fprintf(fp,"%c%s", resposta,pergunta);
            fclose(fp);

            }
    return 0;
}
