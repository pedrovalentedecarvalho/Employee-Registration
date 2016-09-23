#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Empregado {
	int id;
	char nome[40];
	char funcao[40];
	struct Empregado *anterior;
	struct Empregado *proximo;
}EMPREGADO;

int idEmpregado = 0;

EMPREGADO *INICIO = NULL;
EMPREGADO *FIM = NULL;

void criarEmpregado(){
	EMPREGADO *empregado = (EMPREGADO *)malloc(sizeof(EMPREGADO));
	if (empregado != NULL){
		idEmpregado++;
		empregado->id = idEmpregado;
		puts("Nome:");
		fflush(stdin);
		gets(empregado->nome);
		puts("Função:");
		fflush(stdin);
		gets(empregado->funcao);

		if (FIM != NULL){ 
			FIM->proximo=empregado; 
			empregado->anterior=FIM; 
			FIM=empregado; 
			empregado->proximo=NULL; 
		}else{ 
			empregado->proximo=NULL; 
			empregado->anterior=NULL; 
			INICIO=empregado; 
			FIM=empregado; 
		}
		puts("Empregado registado!");

		fflush(stdin);
		getchar();
	}
	else{
		puts("Memória insuficiente!");
	}
}
	
EMPREGADO * buscar(int id){
	EMPREGADO *empregado;

	if (FIM){
		for (empregado = INICIO; empregado != NULL; empregado = empregado->proximo){
			if (empregado->id == id){
				return empregado;
			}
		}
		return NULL;
	}
	return NULL;

}

void verEmpregado(){
	int id;
	puts("ID do empregado: ");

	scanf("%d", &id);

	EMPREGADO *empregado = buscar(id);
	if (empregado == NULL){
		puts("O empregado inserido não existe!");
	}
	else{
		printf("\nID: %d   |   Nome: %s   |   Função: %s\n", empregado->id, empregado->nome, empregado->funcao);
	}
}

void eliminar(EMPREGADO *empregado){

	if (INICIO == empregado){ 
		INICIO = empregado->proximo; 
	} 
	
	if (empregado->proximo){ 
		empregado->proximo->anterior = empregado->anterior; }
	else{ 
		FIM = empregado->anterior;
	} 
	
	if (empregado->anterior){ 
		empregado->anterior->proximo = empregado->proximo; 
	} 
	
	free(empregado);
	puts("O empregado foi eliminado!");

	fflush(stdin);
	getchar();
}


void eliminarEmpregado(){
	int id;
	puts("ID empregado: ");

	scanf("%d", &id);

	EMPREGADO *empregado = buscar(id);
	if (empregado == NULL){
		puts("Empregado não existe!");
	}
	else{
		eliminar(empregado);
	}
}

void listarEmpregados(){
	EMPREGADO *ptr;

	if (FIM != NULL){ 
		for (ptr = INICIO; ptr != NULL; ptr = ptr->proximo){ 
			printf("\nId: %d   |   Nome: %s   |   Função: %s\n", ptr->id, ptr->nome, ptr->funcao); } }
	else{ 
		printf("\n Não existem empregados!\n"); 
	}

}

void menu(){
	int opcao;

	while (1){
		puts("1... Criar empregado");
		puts("2... Visualizar empregado");
		puts("3... Eliminar empregado");
		puts("4... Listar empregados");
		puts("5... Sair");

		scanf("%d", &opcao);

		switch (opcao){
		case 1:
			criarEmpregado();
			break;
		case 2:
			verEmpregado();
			break;
		case 3:
			eliminarEmpregado();
			break;
		case 4:
			listarEmpregados();
			break;
		case 5:
			exit(0);

		}
	}
}

int main(){
    setlocale(LC_ALL, "Portuguese");  
	menu();
}
