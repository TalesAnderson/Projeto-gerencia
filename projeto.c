#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int true=1;
const int false=0;

struct nodo{
	char nome[50];
	int numero;
	char marca[50];
	int prioridade;
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

int adiciona_prioridade(){
    int prio;
    printf("O voo possui prioridade?\n");
    printf("1 = sim\n0 = nao\n");
    scanf("%d",&prio);
    return prio;
}
void adiciona_fila(Fila *fila){


	char nom[50];
	int n;
	char marc[50];
	int x=1;
    int prio;

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
	novo->prioridade=prio;
	aux2->proximo=novo;

    }

}
void imprime (Fila *fila){
	if (fila->inicio==NULL){
		printf("A fila de avioes esta vazia!\n\n");
	}
	else{
		Nodo *aux=fila->inicio;

		while (aux!=NULL){
			printf("\nNome: %s",aux->nome);
			printf("\nNome: %d",aux->numero);
			printf("\nMarca: %s",aux->marca);

			printf("\n\n");

			aux=aux->proximo;
		}
	}
}
void numero_espera(Fila *fila){

	int contador=0;
	Nodo *cont=fila->inicio;

	if(fila->inicio==NULL){
		printf("A fila de avioes esta vazia!\n\n");
	}

	else{

		while(cont!=NULL){
			contador++;
			cont=cont->proximo;
		}
		printf("\nExistem %d avioes na Fila de Espera\n",contador);
	}
}
void autorizar_primeiro(Fila *fila){
	
	if(fila->inicio==NULL){
		printf("A fila de avioes esta vazia!\n\n");
	}
	
	else{
		Nodo *aux=fila->inicio;
		Nodo *p=aux->proximo;
		fila->inicio=p;
		free(aux);
	}
}
main(){
	Fila *fila=criafila();
	Fila *fila2=criafila();
	Fila *fila3=criafila();
	Fila *fila4=criafila();

	int x,p;

		do{
			printf("--------------------------------------Menu--------------------------------------\n\n");
			printf("----------Decolagens----------\n\n");
			printf("   ---Selecione uma opcao---\n\n");
			printf("1 - Adiciona aviao a lista de espera.\n");
			printf("2 - Mostrar todos os avioes da fila de espera.\n");
			printf("3 - Mostrar todos os avioes da fila de prioridade.\n");
			printf("4 - Informar o numero de avioes na lista de espera.\n");
			printf("5 - Informar o numero de avioes na lista de prioridade.\n");
			printf("6 - Autorizar a decolagem da lista de prioridade.\n");
			printf("7 - Autorizar a decolagem na lista de espera.\n\n");
			printf("-----------Chegadas-----------\n\n");
			printf("   ---Selecione uma opcao---\n\n");
			printf("8 - Adiciona aviao a lista de espera.\n");
			printf("9 - Mostrar todos os avioes da fila de espera.\n");
			printf("10 - Mostrar todos os avioes da fila de prioridade.\n");
			printf("11 - Informar o numero de avioes na lista de espera.\n");
			printf("12 - Informar o numero de avioes na lista de prioridade.\n");
			printf("13 - Autorizar o pouso da lista de prioridade.\n");
			printf("14- Autorizar o pouso na lista de espera.\n\n");
			
			printf("9 - para sair do programa.\n\n");
			scanf("%d",&x);
			switch(x){

				case 1:
				    while(x!=0){
				    p=adiciona_prioridade();
				    if(p==true){
                        adiciona_fila(fila3);
                        system("pause   ");
                        printf("\n\n");
				    }
				    else{
                        adiciona_fila(fila);
                        system("pause   ");
                        printf("\n\n");
				    }
				    printf("Se deseja informar outro aviao digite 1, se nao digite 0: ");
                    scanf("%d", &x);
				    }
					break;
				case 2:
					imprime(fila);
					system("pause   ");
					printf("\n\n");
					break;
				case 3:
					imprime(fila3);
					system("pause   ");
					printf("\n\n");
					break;
				case 4:
					numero_espera(fila);
					system("pause   ");
					printf("\n\n");
					break;
                case 5:
               		 numero_espera(fila3);
                	 system("pause   ");
                	 printf("\n\n");
               		 break;
                case 6:
                	 autorizar_primeiro(fila3);
                	 system("pause   ");
                	 printf("\n\n");
                	 break;
                case 7:
               		 autorizar_primeiro(fila);
                	 system("pause   ");
                	 printf("\n\n");
                	 break;
				case 8:
				    while(x!=0){
                    p=adiciona_prioridade();
				    if(p==true){
                    adiciona_fila(fila4);
					system("pause   ");
					printf("\n\n");
                    }
                    else{
					adiciona_fila(fila2);
					system("pause   ");
					printf("\n\n");
                    }
                    printf("Se deseja informar outro aviao digite 1, se nao digite 0: ");
                    scanf("%d", &x);
				    }
					break;
				case 9:
					imprime(fila2);
					system("pause   ");
					printf("\n\n");
					break;
				case 10:
					imprime(fila4);
					system("pause   ");
					printf("\n\n");
					break;
				case 11:
					numero_espera(fila2);
					system("pause   ");
					printf("\n\n");
					break;
                case 12:
					numero_espera(fila4);
					system("pause   ");
					printf("\n\n");
					break;
				case 13:
                	 autorizar_primeiro(fila4);
                	 system("pause   ");
                	 printf("\n\n");
                	 break;
                case 14:
               		 autorizar_primeiro(fila2);
                	 system("pause   ");
                	 printf("\n\n");
                	 break;
					
			}

		}while(x!=15);
}

