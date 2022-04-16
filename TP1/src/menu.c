/*
 * menu.c
 *
 *  Created on: 15 abr. 2022
 *      Author: caroo
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"

int menuPrincipal(int numero){


	printf("***MENU DE OPCIONES***\n\n");
	printf("\n 1. Ingresar Kilometros:");
	printf("\n 2. Ingresar precio de vuelos:");
	printf("\n 3. Calcular costos.");
	printf("\n 4. Informar resultados.");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir\n");
	printf("\n Opcion ingresada: ");
	scanf("%d", &numero);



	return numero;
}

int subMenuPrecios(void){
	int opcion;

	printf("\n 1. Ingresar precio de vuelo Aerolineas: ");
	printf("\n 2. Ingresar precio de vuelo Latam");
	printf("\n 3. Volver al menu principal");
	printf("\n Opcion ingresada: ");
	scanf("%d", &opcion);

	while(opcion < 1 && opcion >3){
		printf("\n Error, ingrese una opcion del 1 al 3");
	}

	return opcion;

}

/*
int subMenuCostos(void){
	int opcion;

	printf("\n 1. Tarjeta de debito (descuento 10%c", 37);
	printf("\n 2. Tarjeta de credito (interes 25%c", 37);
	printf("\n 3. Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	printf("\n 4. Mostrar precio por KM (precio unitario");
	printf("\n 5. Mostrar diferencia de precio ingresada (Latam - Aerolineas");
	printf("\n Opcion ingresada:");
	scanf("%d",&opcion);

	while(opcion < 1 && opcion >5 ){
		printf("Error, ingrese una opcion valida del 1 al 5");
	}

	return opcion;

}
*/

