#ifndef arvores
    #define arvores

struct no{
    // Ambas
	int ch[3]; // Chaves dentro de um n�
    struct no *filho[4]; // Apenas [0] e [1] s�o utilizados pela Red/Black, simbolizando esquerda e direita, respectivamente
    // Red/Black Tree
    char color; //b ou r
    // B-Tree
	int n; // Quantidade de elementos na p�gina
	int folha; // Indica se o n� � folha ou n�o
}; typedef struct no tno;

void converteArvore(tno *x, tno *arv);
#endif

