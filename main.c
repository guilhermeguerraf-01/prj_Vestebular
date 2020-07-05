#include <stdio.h>
#include <stdlib.h>
#include "classificacao.h"

int main(void)
{
    char gab[T];
    verificarAberturaArquivos();
    fout = fopen("arquivos\\resultado.txt", "a");
    fr = fopen("arquivos\\respostas.txt", "r");
    fg = fopen("arquivos\\gabarito.txt", "r");
    while(fscanf(fg, "%s", gab) != EOF){
        ler_respostas(gab);

        atribuirVetorValoresPorRa();
        imprimirResultadoPorRa();
        registrarResultadoPorRa_noArquivo();

        atribuirVetorValoresPorNota();
        imprimirResultadoPorNota();
        registrarResultadoPorNota_noArquivo();
    }
    fclose(fout);
    fclose(fr);
    fclose(fg);
    return 0;
}
