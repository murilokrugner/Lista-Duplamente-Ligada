/*
	Name: Lista Duplamente Ligada;
	Course: Ciência da computação; 
	Author: Murilo Augusto Krugner Almeida Leite;
	Description: Quiz Aula 14 - Estrutura de dados;
	Creation date: 27/06/2020;
	Copyright: Licence MIT;
	
	Repository: https://github.com/murilokrugner/Lista-Duplamente-Ligada
*/


#include <stdio.h>
#include <stdlib.h>

struct noListaDL {
	int valor;
	struct noListaDL *ant, *prox;
};

typedef struct noListaDL NOLISTADL;
typedef NOLISTADL *NOLISTAPTR;

void insereInicio(NOLISTAPTR *inic, int valor) {
	NOLISTAPTR novo;
	novo = (NOLISTAPTR) malloc(sizeof(NOLISTADL));
	
	if (novo == NULL) {
		return;
	}
	
	if (*inic == NULL) {
		novo->valor = valor;
		novo->prox = novo->ant = NULL;
		*inic = novo;
	} else {
		novo->valor = valor;
		novo->ant = NULL;
		novo->prox = *inic;
		(*inic)->ant = novo;
		*inic = novo;
	}
	
	printf("\nInserindo o valor %i no comeco da lista\n", valor);	
}

void insereFinal(NOLISTAPTR *inic, int valor) {
	NOLISTAPTR novo, current;
	novo = malloc(sizeof(NOLISTADL));
	
	if(novo == NULL) {
		return;
	}
	
	if(*inic == NULL) {
		novo->valor = valor;
		novo->prox = novo->ant = NULL;
		*inic = novo;
	} else {
		current = *inic;
		
		while (current->prox != NULL) {
			current = current->prox;
		}
		
		novo->valor = valor;
		novo->ant = current;
		novo->prox = NULL;
		current->prox = novo;
	}
	
	printf("\n\nInserindo o valor %i no final da lista\n", valor);
}

int remover(NOLISTAPTR *inic, int valor) {
	NOLISTAPTR temp, current;
	
	if(*inic == NULL) {
		return 0;		
	}
	
	current = *inic;
	
	if((*inic)->valor == valor) {
		*inic = (*inic)->prox;
	}
	
	while(current != NULL && current->valor != valor) {
		current = current->prox;
	}
	
	if(current == NULL) {
		return 0;
	} else {
		temp = current;
		
		if(current->ant != NULL) {
			current->ant->prox = current->prox;
		}
		
		if(current->prox != NULL) {
			current->prox->ant = current->ant;
		}
		
		free(temp);
	}
	
	printf("\n\nRemovido o valor: %i\n", valor);
	return 1;
}

int removerNo(NOLISTAPTR *inic) {
	NOLISTAPTR temp;
	int c;
	temp = *inic;
	c = (*inic)->valor;
	*inic = (*inic)->prox;
	free(temp);
	
	return c;
}

int verificarVazia(NOLISTAPTR lista) {
	return lista == NULL;
}

void imprimeOrdemDireta(NOLISTAPTR lista) {
	if(verificarVazia(lista)) {
		printf("\n\nA lista esta vazia. \n");
	} else {
		printf("\n\nA lista em ordem direta e:\n");
		
		while(lista != NULL) {
			printf(" %i", lista->valor);
			lista = lista->prox;
		}
	}
}

void imprimeOrdemInversa(NOLISTAPTR lista) {
	if(verificarVazia(lista)) {
		printf("\n\nA lista esta vazia. \n");
	} else {
		while(lista->prox != NULL) {
			lista = lista->prox;												
		}
		
		printf("\n\nA lista em ordem inversa e:\n");
		while(lista != NULL) {
			printf(" %i", lista->valor);
			lista = lista->ant;
		}
	}
}

int main() {
	NOLISTAPTR lista = NULL;
		
	imprimeOrdemDireta(lista);
	
	insereInicio(&lista, 1);
	insereInicio(&lista, 2);
	insereInicio(&lista, 3);
	insereInicio(&lista, 4);
	insereInicio(&lista, 5);
	
	imprimeOrdemDireta(lista);
	
	imprimeOrdemInversa(lista);
		
	insereFinal(&lista, 10);
	
	imprimeOrdemDireta(lista);
	
	remover(&lista, 2);
		
	verificarVazia(lista);
	
	removerNo(&lista);
		
	return 0;
}


