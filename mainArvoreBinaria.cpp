#include <iostream>

using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;

    NoArvore(int valor) : dado(valor), esquerda(NULL), direita(NULL) {}
};

bool ArvoreCompleta(NoArvore* raiz) {

    if (raiz == NULL)
        return true;

    NoArvore* fila[1000];
    int inicio = -1, fim = -1;
    bool encontrouNoNaoCheio = false;

    fila[++fim] = raiz;

    while (inicio != fim) {
        NoArvore* atual = fila[++inicio];

        if ((atual->esquerda == NULL && atual->direita != NULL) ||
            (atual->esquerda != NULL && atual->direita == NULL)) {
            return false; 
        }

        if (atual->esquerda == NULL || atual->direita == NULL) {
            encontrouNoNaoCheio = true;
        }

        if (encontrouNoNaoCheio && (atual->esquerda != NULL || atual->direita != NULL)) {
            return false; 
        }

        if (atual->esquerda != NULL)
            fila[++fim] = atual->esquerda;
        if (atual->direita != NULL)
            fila[++fim] = atual->direita;
    }

    return true;
}

bool ArvoreCheia(NoArvore* raiz) {
    
	if (raiz == NULL)
        return true;

    NoArvore* fila[1000];
    int inicio = -1, fim = -1;

    fila[++fim] = raiz;

    while (inicio != fim) {
        NoArvore* atual = fila[++inicio];

        if ((atual->esquerda == NULL && atual->direita != NULL) ||
            (atual->esquerda != NULL && atual->direita == NULL)) {
            return false; 
        }

        if (atual->esquerda != NULL)
            fila[++fim] = atual->esquerda;
        if (atual->direita != NULL)
            fila[++fim] = atual->direita;
    }

    return true;
}

int AlturaArvore(NoArvore* raiz) {
    if (raiz == NULL)
        return 0;

    int alturaEsquerda = AlturaArvore(raiz->esquerda);
    int alturaDireita = AlturaArvore(raiz->direita);

    return 1 + max(alturaEsquerda, alturaDireita);
}

bool ArvorePerfeita(NoArvore* raiz) {

    if (raiz == NULL)
        return true;

    int alturaEsquerda = AlturaArvore(raiz->esquerda);
    int alturaDireita = AlturaArvore(raiz->direita);

    if (alturaEsquerda == alturaDireita) {

        return ArvorePerfeita(raiz->esquerda) && ArvorePerfeita(raiz->direita);
    }

    return false;
}

bool ArvoreBalanceada(NoArvore* raiz) {

    if (raiz == NULL)
        return true;

    int alturaEsquerda = AlturaArvore(raiz->esquerda);
    int alturaDireita = AlturaArvore(raiz->direita);

    if ((alturaEsquerda - alturaDireita) <= 1) {
        
		return ArvoreBalanceada(raiz->esquerda) && ArvoreBalanceada(raiz->direita);
    }

    return false;
}

bool ArvoreDegenerada(NoArvore* raiz) {

    if (raiz == NULL || (raiz->esquerda == NULL && raiz->direita == NULL))
        return true;

    if (raiz->esquerda != NULL && raiz->direita != NULL)
        return false;

    return ArvoreDegenerada(raiz->esquerda) && ArvoreDegenerada(raiz->direita);
}

bool ArvoreDistorcida(NoArvore* raiz) {
    
	if (raiz == NULL || (raiz->esquerda == NULL && raiz->direita == NULL))
        return true;

    if ((raiz->esquerda != NULL && raiz->direita != NULL) ||
        (raiz->esquerda != NULL && raiz->esquerda->direita != NULL) ||
        (raiz->direita != NULL && raiz->direita->esquerda != NULL))
        return false;

    return ArvoreDistorcida(raiz->esquerda) && ArvoreDistorcida(raiz->direita);
}

int main() {

    NoArvore* raizCompleta = new NoArvore(1);
    raizCompleta->esquerda = new NoArvore(2);
    raizCompleta->direita = new NoArvore(3);
    raizCompleta->esquerda->esquerda = new NoArvore(4);
    raizCompleta->esquerda->direita = new NoArvore(5);
    raizCompleta->direita->esquerda = new NoArvore(6);
    raizCompleta->direita->direita = new NoArvore(7);
    raizCompleta->esquerda->esquerda->esquerda = new NoArvore(8);
    raizCompleta->esquerda->esquerda->direita = new NoArvore(9);
    raizCompleta->esquerda->direita->esquerda = new NoArvore(10);

    cout << "A arvore e uma arvore binaria completa? "
         << (ArvoreCompleta(raizCompleta) ? "Sim" : "Nao") << endl;

    cout << "A arvore e uma arvore binaria cheia? "
         << (ArvoreCheia(raizCompleta) ? "Sim" : "Nao") << endl;

    cout << "A arvore e uma arvore binaria perfeita? "
         << (ArvorePerfeita(raizCompleta) ? "Sim" : "Nao") << endl;

    cout << "A arvore e uma arvore binaria balanceada? "
         << (ArvoreBalanceada(raizCompleta) ? "Sim" : "Nao") << endl;

    cout << "A arvore e uma arvore binaria degenerada? "
         << (ArvoreDegenerada(raizCompleta) ? "Sim" : "Nao") << endl;

    cout << "A arvore e uma arvore binaria distorcida? "
         << (ArvoreDistorcida(raizCompleta) ? "Sim" : "Nao") << endl;

    delete raizCompleta;

    return 0;
}
