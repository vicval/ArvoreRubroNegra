#include "arvores.h"

void converteArvore(tno *x, tno *arv){
    int i;
    tno *aux;
    if(!x)
        return;

    if(x->n == 1){
        aux = insertNodeRBConvert(arv, x->ch[0]);
        aux->color = 'p';
    }
    else if(x->n == 2){
        aux = insertNodeRBConvert(arv, x->ch[1]);
        aux->color = 'p';
        aux = insertNodeRBConvert(arv, x->ch[0]);
        aux->color = 'v';
    }
    else if(x->n == 3){
        aux = insertNodeRBConvert(arv, x->ch[1]);
        aux->color = 'p';
        aux = insertNodeRBConvert(arv, x->ch[0]);
        aux->color = 'v';
        aux = insertNodeRBConvert(arv, x->ch[2]);
        aux->color = 'v';
    }

    for(i=0; i<=x->n; i++)
        converteArvore(x->filho[i], arv);
}
