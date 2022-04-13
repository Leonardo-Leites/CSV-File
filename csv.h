#ifndef CSV_H
#define CSV_H

#define TAMANHO 30
#define NATLETAS 3

typedef struct
{
    char *nomes[NATLETAS][TAMANHO];
    int idade[NATLETAS];
    int altura[NATLETAS];
}t_csv;

#endif