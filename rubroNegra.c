#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include "arvores.h"

tno* createTreeRB(){

    tno *sentinela;

    //Allocating sentinel
    sentinela = (tno*)malloc(sizeof(tno));

    if(!sentinela){
        printf("\t\tSentinel Unallocated!!!\n");
        return NULL;
    }

    sentinela->color = 'p';
    sentinela->filho[0] = NULL;
    sentinela->filho[1] = NULL;
    sentinela->ch[0] = -10000;

    return sentinela;

}

tno *insertNodeRB(tno *sentinela, int dado){

    //Auxiliary Variables
    tno *auxNo, *novoNo, *auxPai, *auxAvo, *auxTio;

    //Allocating novoNo
    novoNo = (tno*)malloc(sizeof(tno));
    if(novoNo == NULL){
        printf("\t\tnovoNo Unallocated!!!\n\n");
        return;
    }
    novoNo->color = 'v';
    novoNo->ch[0] = dado;
    novoNo->filho[0] = NULL;//PAI
    novoNo->filho[1] = NULL;//FILHO ESQ
    novoNo->filho[2] = NULL;//FILHO DIR

    //Empty Tree
    if(sentinela->filho[2] == NULL){

        sentinela->filho[2] = novoNo;
        novoNo->filho[0] = sentinela;

        //Root is black
        novoNo->color = 'p';

        return;

    }

    //Find the place of node
    auxNo = sentinela->filho[2];

    while(auxNo != NULL){

        auxPai = auxNo;

        if(dado > auxNo->ch[0])
            auxNo = auxNo->filho[2];
        else
            auxNo = auxNo->filho[1];

    }

    //Insert the node
    if (dado < auxPai->ch[0])
        auxPai->filho[1] = novoNo;
    else
        auxPai->filho[2] = novoNo;

    novoNo->filho[0] = auxPai;

    insertionRBbalancingTree(sentinela, novoNo);

    return novoNo;
}

tno *insertNodeRBConvert(tno *sentinela, int dado){

    //Auxiliary Variables
    tno *auxNo, *novoNo, *auxPai, *auxAvo, *auxTio;

    //Allocating novoNo
    novoNo = (tno*)malloc(sizeof(tno));
    if(novoNo == NULL){
        printf("\t\tnovoNo Unallocated!!!\n\n");
        return;
    }
    novoNo->color = 'v';
    novoNo->ch[0] = dado;
    novoNo->filho[0] = NULL;//PAI
    novoNo->filho[1] = NULL;//FILHO ESQ
    novoNo->filho[2] = NULL;//FILHO DIR

    //Empty Tree
    if(sentinela->filho[2] == NULL){

        sentinela->filho[2] = novoNo;
        novoNo->filho[0] = sentinela;

        //Root is black
        novoNo->color = 'p';

        return;

    }

    //Find the place of node
    auxNo = sentinela->filho[2];

    while(auxNo != NULL){

        auxPai = auxNo;

        if(dado > auxNo->ch[0])
            auxNo = auxNo->filho[2];
        else
            auxNo = auxNo->filho[1];

    }

    //Insert the node
    if (dado < auxPai->ch[0])
        auxPai->filho[1] = novoNo;
    else
        auxPai->filho[2] = novoNo;

    novoNo->filho[0] = auxPai;

    return novoNo;
}

void insertionRBbalancingTree(tno *sentinela, tno *no){

    //Auxiliary Variables
    tno *auxPai, *auxAvo, *auxTio;

    //Assigning values of auxiliary variables
    auxPai = no->filho[0];

    while(auxPai->color == 'v'){

        auxAvo = auxPai->filho[0];

        //Node left of the auxAvo
        if(no->ch[0] < auxAvo->ch[0]){

            //[1 CASO]: Uncle right:
            if(auxAvo->filho[2] != NULL)
                auxTio = auxAvo->filho[2];

            if(auxAvo->filho[2] != NULL && auxTio->color == 'v'){

                auxPai->color = 'p';
                auxTio->color = 'p';
                auxAvo->color = 'v';

                no = auxAvo;
                auxPai = no->filho[0];

            }//Fim Caso 1.

            //[2 CASO]:
            else{
                if(no == auxPai->filho[2]){
                    rotationLeft(auxPai);
                    no = auxPai;
                    auxPai = no->filho[0];
                }//Fim Caso 2.

                //[3 CASO]:
                auxPai->color = 'p';
                auxAvo->color = 'v';
                rotationRight(auxAvo);
            }//Fim Caso 3.
        }
        //Node Right of the auxAvo
        else{

            //[1 CASO]: Uncle Left
            if(auxAvo->filho[1] != NULL)
                auxTio = auxAvo->filho[1];

            if(auxAvo->filho[1] != NULL && auxTio->color == 'v'){
                auxPai->color = 'p';
                auxTio->color = 'p';
                auxAvo->color = 'v';
                no = auxAvo;
                auxPai = no->filho[0];
            }//FIM CASO 1.

            //[2 CASO]:
            else{

                if(no == auxPai->filho[1]){

                    rotationRight(auxPai);
                    no = auxPai;
                    auxPai = no->filho[0];
                }//Fim Caso 2.

                //[3 CASO]:
                auxPai->color = 'p';
                auxAvo->color = 'v';
                rotationLeft(auxAvo);
            }//Fim Caso 3.

        }
    }

    //Root is Black
    sentinela->filho[2]->color = 'p';

}

void consultRB(tno *sentinela){

    //Empty Tree
    if(sentinela->filho[2] == NULL){
        printf("\n\t\tEmpty Tree!!!\n\n");
        return;
    }

    //Prints in Order
    printf("\n\tData: \n\t");
    inOrderRB(sentinela->filho[2]);
    printf("\n\n");

    return;

}

void preOrderRB(tno *no){

    if(no == NULL)
        return;

    printf(" %d (%c)", no->ch[0], no->color);
    preOrderRB(no->filho[1]);
    preOrderRB(no->filho[2]);

    return;

}

void inOrderRB(tno *no){

    if(no == NULL)
        return;

    inOrderRB(no->filho[1]);
    printf(" %d (%c)", no->ch[0], no->color);
    inOrderRB(no->filho[2]);

    return;

}

void postOrderRB(tno *no){

    if(no == NULL)
        return;

    postOrderRB(no->filho[1]);
    postOrderRB(no->filho[0]);
    printf(" %d (%c)", no->ch[0], no->color);

    return;

}

void rotationRight(tno *x){

     tno *w, *y, *z;

     y = x->filho[1];
     z = y->filho[2];
     y->filho[2] = x;
     y->filho[0] = x->filho[0];
     x->filho[0] = y;

     if(z!=NULL)
     {
         x->filho[1]=z;
         z->filho[0]=x;
     }else{
     	x->filho[1] = NULL;
     }
     if(y->filho[0]->ch[0] <= y->ch[0])
        y->filho[0]->filho[2] = y;
     else
        y->filho[0]->filho[1] = y;

}

void rotationLeft(tno *x){

     tno *w, *y, *z;

     y = x->filho[2];
     z = y->filho[1];
     y->filho[1] = x;
     y->filho[0] = x->filho[0];
     x->filho[0] = y;
     if(z != NULL)
     {

         x->filho[2] = z;
         z->filho[0] = x;

     }else{

     	x->filho[2] = NULL;

     }
     if(y->filho[0]->ch[0] <= y->ch[0])
         y->filho[0]->filho[2] = y;
     else
        y->filho[0]->filho[1] = y;
}


void imprimeRB(tno *x, int n){
	int i;
	if(x){
		for(i = x->n; i > (x->n)/2; --i)
			imprime234(x->filho[i],n+1);
		for(i = 0; i < n; i++)
			printf ("\t");
		printf("(");
		for(i = 0; i < x->n; ++i){
            if(i==0) printf("%d,", x->ch[i]);
            else if(i!=x->n-1) printf(" %d,", x->ch[i]);
            else    printf(" %d", x->ch[i]);
		}
		printf(")\n");
		for(i = (x->n)/2; i >= 0; --i)
			imprime234(x->filho[i],n+1);
 	}
}
