#include "testes.h"


int main(){
    testeBaseInserir();

    return 0;
}


void testeBaseInserir()
{
    int i;
    int list[] = { 11, 2, 14, 1, 7, 15, 5, 8, 4};
    
    No *externo = noExterno();

    ptRaiz = (No**)malloc(sizeof(No*) * sizeof(list));    
    ptRaiz[0] = externo;    


    for ( i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
    {
        No *z = criarNo(list[i], externo);
        InserirRN(externo, z, &(ptRaiz[0]));

    }

    int count = contaNos(ptRaiz[0], externo);
    printf("\nQTD: %d\n", count);
    
    // imprimirOrdem(ptRaiz[0], externo);
}


void testeBaseRemover()
{
    int i;
    int list[] = {11, 4};
    
    No *externo = noExterno();    

    for ( i = 0; i < (sizeof(list) / sizeof(list[0])); i++)
    {
        No *z = criarNo(list[i], externo);
        RemoverRN(externo, z, &(ptRaiz[0]));

    }

    int count = contaNos(ptRaiz[0], externo);
    printf("QTD: %d\n", count);
    
    imprimirOrdem(ptRaiz[0], externo);
}


// // Prepara as arvores a serem criadas
// void testeDeInsercao() {
//     int i;
//     No *externo = noExterno();   

//     // alocando memória para as raizes
//     ptRaiz = (No**)malloc(sizeof(No*) * QTD_ARVORES);
//     // Inicializando cada raiz para apontar para NULL
//     for (i = 0; i < QTD_ARVORES; i++) {
//         ptRaiz[i] = NULL;
//     }
    
//     // Inserindo a quantidade definida de nós em cada árvore
//     for(i = 0; i < QTD_ARVORES; i++) {
//         int nos = 0;

//         // Enquanto nao ocorrerem as N insercoes, o laco continua
//         while (nos < QTD_NOS) {
//             int key = rand() % RAND_LIMITE;
//             inserir(key, &(ptRaiz[i]), &alturaTotal);
//             nos = contaNos(ptRaiz[i]);
//         }
//         // Atualizando a altura da arvore apos as inserções
//         atualizaAltura(ptRaiz[i]);
//     }

// }


// Procedimento que realiza as remocoes exigidas
// void testeDeExclusao() {
//     int i;
//     int nos; // contador
//     for(i = 0; i < QTD_ARVORES; i++) {
//     No *externo = noExterno();   
//      // Variavel para o resultado de alteracao de altura
//         nos = QTD_NOS; // contador

//         // Enquanto nao ocorrerem as N remocoes, o laco continua
//         while (nos > (QTD_NOS - QTD_REMOCOES)) {
//             int key = rand() % RAND_LIMITE;
//             deletaNo(&(ptRaiz[i]), key, &alturaTotal, &(ptRaiz[i]));
//             nos = contaNos(ptRaiz[i]);
//         }
//         // Atualizando a altura da arvore apos as remocoes
//         atualizaAltura(ptRaiz[i]);
//     }
// }