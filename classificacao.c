#include <stdio.h>
#include <stdlib.h>
#include "classificacao.h"

struct aluno{
    int Ra, Nota;
};

struct aluno v[6];

void verificarAberturaArquivos(){
    fr = fopen("arquivos\\respostas.txt", "r");
    if(fr == NULL){
        printf("Impossivel abrir arquivo\n");
        exit(1);
    }
    fclose(fr);
    fg = fopen("arquivos\\gabarito.txt", "r");
    if(fg == NULL){
        printf("Impossivel abrir arquivo\n");
        exit(1);
    }
    fclose(fg);
}

void ler_respostas(char *p){
    int i=0, k=0;
    int nota=0;
    float ra=0;
    char res[T];
    while(!feof(fr)){
        fscanf(fr, "%f    %s", &ra, res);
        for(i=0; i<T; i++){
            if(res[i] == p[i]){
                nota++;
            }
        }
        v[k].Ra = ra;
        v[k].Nota = nota;
        nota=0;
        k++;
    }
}

void atribuirVetorValoresPorRa(){
    int i, j;
    int aux1, aux2;
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
            if(v[i].Ra>v[j].Ra){
                aux1 = v[i].Ra;
                v[i].Ra = v[j].Ra;
                v[j].Ra = aux1;
                aux2 = v[i].Nota;
                v[i].Nota = v[j].Nota;
                v[j].Nota = aux2;
            }
        }
    }
}

void atribuirVetorValoresPorNota(){
    int i, j;
    int aux1, aux2;
    for(i=0; i<6; i++){
        for(j=i+1; j<6; j++){
            if(v[i].Nota<v[j].Nota){
                aux1=v[i].Nota;
                v[i].Nota=v[j].Nota;
                v[j].Nota=aux1;
                aux2=v[i].Ra;
                v[i].Ra=v[j].Ra;
                v[j].Ra=aux2;
            }
        }
    }
}

void imprimirResultadoPorRa(){
    int i;
    printf("\nCLASSIFICACAO POR NUMERO DO RA\n");
    printf("\nRA       Pontos\n");
    for(i=0; i<5; i++)
        printf("%d      %d\n", v[i].Ra,v[i].Nota);
}

void imprimirResultadoPorNota(){
    int i;
    printf("\nCLASSIFICACAO POR NOTA\n");
    printf("\nRA       Pontos\n");
    for(i=0; i<5; i++)
        printf("%d      %d\n", v[i].Ra,v[i].Nota);
}

void registrarResultadoPorRa_noArquivo(){
    int i;
    fprintf(fout,"\nCLASSIFICACAO POR NUMERO DO RA\n");
    fprintf(fout,"\nRA       Pontos\n");
    for(i=0; i<5; i++)
        fprintf(fout,"%d       %d\n", v[i].Ra,v[i].Nota);
}

void registrarResultadoPorNota_noArquivo(){
    int i;
    fprintf(fout,"\nCLASSIFICACAO POR NOTA\n");
    fprintf(fout,"\nRA       Pontos\n");
    for(i=0; i<5; i++)
        fprintf(fout,"%d       %d\n", v[i].Ra,v[i].Nota);
}
