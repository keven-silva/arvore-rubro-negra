#ifndef ARVORE_RN_H
#define ARVORE_RN_H

typedef struct no{
    int chave;
    char cor;
    struct no *pai;
    struct no *esq;
    struct no *dir;
}No;

No **ptRaiz; 

#endif