/* tamanho definido para armazenar o RA e as respostas de um aluno */
#define T 52

/* ponteiro para os arquivos, sendo fr para respostas.txt,
   fg para gabarito.txt e fout para resultados.txt*/
FILE *fr, *fg, *fout;

/* verifica se não haverá problemas ao abrir um arquivo, caso o programa
   não consiga abrir algum arquivo, o programa será finalizado com erro. */
void verificarAberturaArquivos();

/* os RAs e as respostas de cada aluno contidas no arquivo "respostas.txt"
   serão lidos (um aluno por vez) e serão armazenados no vetor v onde as
   respostas dos alunos será comparadas com o gabarito e de acordo com os
   acertos será calculado as suas notas. */
void ler_respostas(char *p);

/* organiza o vetor de forma crescente tendo como base o número do RA. */
void atribuirVetorValoresPorRa();

/* imprime todos os dados do vetor - organizado por RA. */
void imprimirResultadoPorRa();

/* registra o resultado organizado por RA no arquivo "resultados.txt". */
void registrarResultadoPorRa_noArquivo();

/* organiza o vetor de forma decrescente tendo como base as notas de cada aluno. */
void atribuirVetorValoresPorNota();

/* imprime todos os dados do vetor - organizado por notas. */
void imprimirResultadoPorNota();

/* registra o resultado organizado por notas no arquivo "resultados.txt". */
void registrarResultadoPorNota_noArquivo();
