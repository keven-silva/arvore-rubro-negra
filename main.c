#include "testes.h"


int main(){
    No *externo = noExterno();

    printf("\nTeste base de insercao\n");
    testeBaseInserir(externo);
    imprimiArvores(externo);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\nTeste base de remocao\n");
    testeBaseRemover(externo);
    imprimiArvores(externo);

    
    // printf("\nTeste de insercao\n");
    // testeDeInsercao(externo);
    // imprimiArvores(externo);
    // printf("---------------------------------------------------------------");
    // printf("\nTeste de remocao\n");
    // testeDeRemocao(externo);
    // imprimiArvores(externo);

    return 0;
}
