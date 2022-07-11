#ifndef ARVORE_RN_H
#define ARVORE_RN_H


#define QTD_ARVORES 1000 // Quantidade de arvores
#define QTD_NOS 27// Quantiadde de nos em cada arvore
#define QTD_REMOCOES  10// Quantidade de remocoes
#define RAND_LIMITE 100000// Valor para limitar o rand()


typedef struct no{
    int chave;
    char cor;
    struct no *pai;
    struct no *esq;
    struct no *dir;
}No;

No **ptRaiz; 

#endif