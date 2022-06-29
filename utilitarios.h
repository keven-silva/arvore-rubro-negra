#include "utilitarios.c"
#include "struct.h"



void RotacaoD(No *z, No **ptRaiz, No *externo);
void RotacaoE(No *z, No **ptRaiz, No *externo);
void Moverpai(No **u, No **v, No **ptRaiz);
void imprimiArvores(No *pt, No *externo); 
void outputOrd(No *pt, No *externo);
int contaNos(No *pt, No *externo); 
No *noExterno();
No *criarNo(int key, No *externo);