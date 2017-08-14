#include "234.h"
#include <stdio.h>
#include <stdlib.h>

tno* cria234(){
	int i;
	tno *p = (tno *)malloc(sizeof(tno));
	p->n = 0;
	p->folha = 1;
	for(i = 0; i < 4; i++)
		p->filho[i] = NULL;
	return p;
}

void divideFilho(tno *pai, int i, tno *filhoVelho){
	int j;
	tno *filhoNovo = cria234();
	filhoNovo->folha = filhoVelho->folha;
	filhoNovo->n = 1;
	for(j = 0; j < 1; j++)
		filhoNovo->ch[j] = filhoVelho->ch[2+j];
	if(!filhoVelho->folha){
		//Se filho velho não é folha, deve copiar os filhos
		for(j = 0; j < 2; j++){
			filhoNovo->filho[j] = filhoVelho->filho[j+2];
			filhoVelho->filho[j+2] = NULL;
		}
	}
	filhoVelho->n = 1;
	for(j = pai->n; j >= i; j--)
		pai->filho[j+1] = pai->filho[j];
	pai->filho[i+1] = filhoNovo;
	for(j = pai->n-1; j >=i; j--)
		pai->ch[j+1] = pai->ch[j];
	pai->ch[i] = filhoVelho->ch[1]; //A posição i recebe o valor central
	pai->n += 1;
}

void insereFolha(tno *x, int num){
	int i;
	i = x->n;
	//Verifica se x é folha
	if(x->folha){
		//Busca local correto para inserção
		while((i >= 1) && (num < x->ch[i-1])){
			x->ch[i] = x->ch[i-1];
			i--;
		}
		//Inserir nova chave
		x->ch[i] = num;
		//Ajusta contador de chaves
		x->n++;
	}
	//Se x não é folha
	else{
		while((i >=1) && (num < x->ch[i-1]))
			i--;
		i++;
		//Verifica se inserção dará overflow
		if(x->filho[i-1]->n == 3){
			divideFilho(x, i-1,x->filho[i-1]);
			if(num > x->ch[i-1])
				i++;
		}
        insereFolha(x->filho[i-1],num);
	}
}

void insere234(tno **raiz, int num){
    tno *novo, *p;
	p = *raiz;

	if(p->n == 3){
		novo = cria234();
		*raiz = novo;
		novo->folha = 0;
		novo->n = 0;
		novo->filho[0] = p;
		divideFilho(novo, 0, p);
		insereFolha(novo, num);
	} else insereFolha(p, num);
}

void imprime234(tno *x, int n){
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
