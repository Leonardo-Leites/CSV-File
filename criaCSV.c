#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "csv.h"

#define MAX 8
#define MIN 3

t_csv csv[NATLETAS] = {0};

static char consoante(void){
    char consoantes[] = {"bcdfghjklmnpqrstvwx"};
    int nc = strlen (consoantes);
    return consoantes[rand()%nc];
}

static char vogal(void){
    char vogais[] = {"aeiou"};
    int nv = strlen(vogais);
    return vogais[rand()%nv];
}

void gera_nome_aleatorio(char *str, int tamanho_maximo){
    int tamanho_aleatorio = MIN+(rand()%(MAX-MIN));
    for(int i = 0; i < tamanho_maximo && i < tamanho_aleatorio; i++){
        *str++ = consoante();
        *str++ = vogal();
    }
    *str = '\0';
}
void preenche(){

    csv->idade[0] = 20;
    csv->idade[1] = 50;
    csv->idade[2] = 58;
    csv->altura[0] = 179;
    csv->altura[1] = 192;
    csv->altura[2] = 157;

}
int main(){

    FILE *arq = fopen ("arquivo.csv", "w"); // abrindo o arquivo em 
                        //  formato escrita com exclusão do arq antigo
    if (arq == NULL){
        printf("Não consegui abrir o arquivo.");
        return 0;
    }
    preenche();
    fputs("Nome,Idade,Altura\n", arq);
    for (int i =0; i < NATLETAS; i++){
        gera_nome_aleatorio(csv->nomes[i], TAMANHO);
        fprintf(arq, "%s,%d,%d\n", csv->nomes[i], csv->idade[i], csv->altura[i]);
    }

    fclose(arq);

    return 0;
}