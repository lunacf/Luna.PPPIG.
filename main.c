#include <stdio.h>
#include <stdlib.h>
#define TAM 4
#include <string.h>

typedef struct{

    int id;
    char procesador[20];
    char marca[20];
    float precio;

}eNotebook;


    int contarCaracteres(char cad[], char character){

	int counting = 0;

	for( int i = 0; cad[i] != '\0'; i++ ){
		if(cad[i] == character){
			counting++;

		}
	}
        return counting;
}


float aplicarDescuento5(float precioSinDescuento)
{
   float precioDescuento;

   precioDescuento = precioSinDescuento-precioSinDescuento*0.05;

   return precioDescuento;
}

void ordenoNotebook(eNotebook lista[], int tam){
	eNotebook auxNotebook;
	for(int i = 0; i < tam - 1; i++){
		for(int j = i + 1; j < tam; j++){
			// Ordeno por marca
			if(strcmp(lista[i].marca, lista[j].marca) > 0){
				auxNotebook = lista[i];
				lista[i] = lista[j];
				lista[j] = auxNotebook;
			}
			// Ordeno por precio menor a mayor
			else if(strcmp(lista[i].marca, lista[j].marca) == 0 &&
					lista[i].precio > lista[j].precio){
				auxNotebook = lista[i];
				lista[i] = lista[j];
				lista[j] = auxNotebook;
			}
		}
	}
}

int main()

{
    float precio = 30000;
	float precioDescuento;
	char letra = 'C';
	char nombre[20];
	int counting;

	eNotebook lista[TAM] = {
                {1001, "I7 2600k", "Asus", 50000},
                {1002, "Athlon", "Asus", 105000},
                {1003, "Ryzen 9", "Samsung", 28000},
                {1004, "i7 8400H", "Sony", 45000} };

    precioDescuento = aplicarDescuento5(precio);
    counting = contarCaracteres(nombre, letra);
    ordenoNotebook(lista, TAM);

    printf(" 1) El precio de %.2f con descuento de 5 por ciento es %.2f\n\n", precio, precioDescuento);
    printf(" 2) En el indice %s hay letras %c : %d\n\n", nombre, letra, counting);
    printf(" 3)  Criterio por marca y precio\n "
            "    ID        Processor      Brand      Prize\n");
                for(int i = 0; i <TAM; i++){
		printf("    %d    %10s    %10s   $ %.2f\n", lista[i].id, lista[i].procesador, lista[i].marca, lista[i].precio);
	}

	return 0;
}
