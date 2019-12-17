#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct nodo{
	char nome[50];
	int numero;
	char marca[50];
	struct nodo *proximo;
};
typedef struct nodo Nodo;


struct fila{
	Nodo *inicio;
};
typedef struct fila Fila;


Fila *criafila(){
	Fila *fila=(Fila*) malloc(sizeof(Fila));
	fila->inicio=NULL;
	return fila;
}

void adiciona_fila(Fila *fila){


	char nom[50];
	int n;
	char marc[50];
	int x=1;

	while(x!=0){

   	if(fila->inicio==NULL){

   	Nodo *aux=(Nodo*) malloc(sizeof(Nodo));

   	printf("Informe o nome do aviao: ");
	scanf("%s", &nom);
	fflush(stdin);
	printf("Informe o numero do aviao: ");
	scanf("%d", &n);
	fflush(stdin);
	printf("Informe a marca do aviao: ");
	scanf("%s", &marc);

	strcpy(aux->nome, nom);
	aux->numero=n;
	strcpy(aux->marca, marc);
	fila->inicio=aux;
	aux->proximo=NULL;

 }

 else{

 	Nodo *novo=(Nodo*) malloc(sizeof(Nodo));
 	Nodo *aux2=fila->inicio;

 	printf("Informe o nome do aviao: ");
	scanf("%s", &nom);
	fflush(stdin);
	printf("Informe o numero do aviao: ");
	scanf("%d", &n);
	fflush(stdin);
	printf("Informe a marca do aviao: ");
	scanf("%s", &marc);

 	while(aux2->proximo!=NULL){
 		aux2=aux2->proximo;
	 }


	strcpy(novo->nome, nom);
	novo->numero=n;
	strcpy(novo->marca, marc);
	novo->proximo=NULL;
	aux2->proximo=novo;

 }



	printf("Se deseja informar outro aviao digite 1, se nao digite 0: ");
	scanf("%d", &x);
  }

}
void imprime (Fila *fila){
	if (fila->inicio==NULL){
		printf("A fila de avioes está vazia!\n\n");
	}
	else{
		Nodo *aux=fila->inicio;
		
		while (aux!==NULL){
			printf("\nNome: %s",aux->nome);
			printf("\nNome: %d",aux->numero);
			printf("\nMarca: %s",aux->marca);
			
			printf("\n\n");
			
			aux=aux->proximo;
		}
	}
}

