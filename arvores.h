#ifndef arvores
    #define arvores

struct no{
    // Ambas
	int ch[3]; // Chaves dentro de um nó
    struct no *filho[4]; // Apenas [0] e [1] são utilizados pela Red/Black, simbolizando esquerda e direita, respectivamente
    // Red/Black Tree
    char color; //b ou r
    // B-Tree
	int n; // Quantidade de elementos na página
	int folha; // Indica se o nó é folha ou não
}; typedef struct no tno;

void converteArvore(tno *x, tno *arv);
#endif

