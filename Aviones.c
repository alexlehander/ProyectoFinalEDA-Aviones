#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

typedef struct Aviones{
    char matricula[7];
    int prioridad;
    char tipo[3];
    int combustible;
    int tiempo;
    char estado[10];
};

typedef struct Nodo{
    struct Aviones datos;
    struct Nodo *siguiente;
}Nodo;

void eliminar (Nodo** cabeza, int entrada);
Nodo* crearNodo(struct Aviones x);
void insertarPrimero(Nodo** cabeza, struct Aviones dato);
int checarCombustible(int *combustible[], char matricula[]);

int main()
{

    return 0;
}

Nodo* crearNodo(struct Aviones x){
    Nodo *p;
    p = (Nodo*)malloc(sizeof(Nodo));
    p-> datos = x;
    p->siguiente=NULL;
    return p;
}

void insertarPrimero(Nodo** cabeza, struct Aviones dato){
    Nodo *nuevo;
    nuevo = crearNodo(dato);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

int checarCombustible(int *combustible[], char matricula[])
{

    return;
}

int generarMatricula(Nodo** cabeza)
{
    Nodo* actual;
    actual = *cabeza;
    srand(time(NULL));
    //actual->datos.matricula = rand() % 90000 + 10001;

    return;
}

void eliminar (Nodo** cabeza, int entrada){
	Nodo* actual, *anterior;
	int encontrado=0;

	//printf("Entre!!\n");

	actual = *cabeza; anterior = NULL;
	while((actual != NULL) && (encontrado==0)){
		if(actual->datos.matricula == entrada){
            encontrado=1;
		}
		if(encontrado==0){
			anterior = actual;
			actual = actual-> siguiente;
		}
		/*printf("%d\t", actual->dato);
		printf("%d\n", anterior->dato);*/
	}
	if(actual == NULL){
        printf("NO SE ENCONTRO EL ID\n");
	}
	if(actual != NULL){
		if(actual == *cabeza){
			*cabeza  = actual ->siguiente;
		}
		else{
			anterior-> siguiente =actual ->siguiente;
			printf("OBJETIVO ELIMINADO\n");
		}
	}

	free(actual);
	getch();
}
