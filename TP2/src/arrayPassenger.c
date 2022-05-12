/*
 * arrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: caroo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "arrayPassenger.h"

#define EMPTY 0
#define FULL 1

#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3


int inicializarPasajero(Pasajero* lista, int len){
	int retorno = -1;
	int i;

	if(lista != NULL && len > 0){
		for (i=0; i<len; i++){
			lista[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}


int altaPasajero(Pasajero* lista, int len, int id, char nombre[], char apellido[], float precio, int tipoPasajero, char codigoV[]){
	int retorno = -1;

	int index = -1;


	if(buscarIndexLibre(lista, len, &index) == 0){
		lista[index].id = id;
		strcpy(lista[index].nombre, nombre);
		strcpy(lista[index].apellido, apellido);
		lista[index].precio = precio;
		lista[index].tipoPasajero = tipoPasajero;
		strcpy(lista[index].codigoVuelo, codigoV);
		lista[index].estadoVuelo = ACTIVO;
		lista[index].isEmpty = FULL;
		retorno = mostrarUnPasajero(lista[index]); //Si se carga exitosamente, en retorno se carga 0.
	}



	return retorno;
}


int buscarPasajeroId(Pasajero* lista, int len, int id){
	int retorno = -1;

	if (lista != NULL && len > 0 && id > -1) {

		for (int i = 0; i < len; i++) {
			if (lista[i].id == id && lista[i].isEmpty == FULL) {
				retorno = i;
				break;
			}
		}

	}

	return retorno;
}


int bajaPasajero(Pasajero* lista, int len, int id, char mensaje[]){
	int retorno = -1;
	int index;
	char respuesta;

	if(lista != NULL && len>0){

		index = buscarPasajeroId(lista, len, id);
		if(index != -1 && mostrarUnPasajero(lista[index]) != -1 && getCharSiNo(mensaje, &respuesta, 1) == 0 && (respuesta == 'S' || respuesta =='s')){
			lista[index].isEmpty = EMPTY;
			retorno = 0;
		}
	}

	return retorno;
}

int hayPasajeros(Pasajero* lista, int len, char * mensajeError){
	int retorno = -1;
	int i;

	for(i = 0;i <len; i++){
		if(lista[i].isEmpty == FULL){
			retorno = 0;
			break;
		}
	}

	if(retorno == -1){
		printf(mensajeError);
	}

	return retorno;
}

int buscarIndexLibre(Pasajero* lista, int len, int * index){
	int retorno = -1;
	int indexLibre;
	int i;

	for (i=0; i<len; i++){
		if(lista[i].isEmpty == 0){
			indexLibre = i;
			*index = indexLibre;
			retorno = 0;
			break;
		}
	}

	return retorno;
}


int ordenarPasajeros(Pasajero* lista, int len, int orden){
	int retorno = -1;
	int ordenado;
	int i;
	Pasajero aux;

	if(lista != NULL && len>0 && (orden == 0 || orden ==1)){

		if(orden == 1){
			do{
				ordenado = 1;
				len--;
				for(i=0; i<len; i++){
					if(stricmp(lista[i].apellido, lista[i+1].apellido) > 0){
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
						ordenado = 0;
					}
				}
			}while(ordenado == 0);
		}
		if(orden == 0){
			do{
				ordenado = 1;
				len--;
				for(i=0; i<len; i++){
					if(stricmp(lista[i].apellido, lista[i+1].apellido) < 0){
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
						ordenado = 0;
					}
				}
			}while(ordenado == 0);
		}

		retorno = 0;
	}


	return retorno;
}

int ordenarPasajeroXTipo(Pasajero* lista, int len, int orden){
	int retorno = -1;
	int ordenado;
	int i;
	Pasajero aux;

	if(lista != NULL && len>0 && (orden == 0 || orden ==1)){

		if(orden == 1){
			do{
				ordenado = 1;
				len--;
				for(i=0; i<len; i++){
					if( (stricmp(lista[i].apellido, lista[i+1].apellido) == 0) && (lista[i].tipoPasajero > lista[i+1].tipoPasajero) ){
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
						ordenado = 0;
					}
				}
			}while(ordenado == 0);
		}
		if(orden == 0){
			do{
				ordenado = 1;
				len--;
				for(i=0; i<len; i++){
					if( (stricmp(lista[i].apellido, lista[i+1].apellido) == 0) && (lista[i].tipoPasajero < lista[i+1].tipoPasajero) ){
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
						ordenado = 0;
					}
				}
			}while(ordenado == 0);
		}

		retorno = 0;
	}


	return retorno;
}

int ordenarPasajeroXCodigo(Pasajero* lista, int len, int orden){
	int retorno = -1;
		int ordenado;
		int i;
		Pasajero Paux;

		if(lista != NULL && len>0 && (orden == 0 || orden ==1)){

			if(orden == 1){
				do{
					ordenado = 1;
					len--;
					for(i=0; i<len; i++){
						if(stricmp(lista[i].codigoVuelo, lista[i+1].codigoVuelo) > 0 ){
							Paux = lista[i];
							lista[i] = lista[i+1];
							lista[i+1] = Paux;
							ordenado = 0;
						}
					}
				}while(ordenado == 0);
			}
			if(orden == 0){
				do{
					ordenado = 1;
					len--;
					for(i=0; i<len; i++){
						if(stricmp(lista[i].codigoVuelo, lista[i+1].codigoVuelo) < 0){
							Paux = lista[i];
							lista[i] = lista[i+1];
							lista[i+1] = Paux;
							ordenado = 0;
						}
					}
				}while(ordenado == 0);
			}

			retorno = 0;
		}


		return retorno;
}


int mostrarPasajero(Pasajero* lista, int len){
	int i;
	int retorno = -1;
	if(lista != NULL && len > 0){
		printf("ID || NOMBRE  || APELLIDO  || PRECIO || CODIGO  ||  TIPO  ||  ESTADO\n\n");
		for(i=0; i<len; i++){
			if(lista[i].isEmpty == 1){
				printf("%d", lista[i].id);
				printf("%20s", lista[i].nombre);
				printf("%20s", lista[i].apellido);
				printf("%20.2f", lista[i].precio);
				printf("%20s", lista[i].codigoVuelo);
				printf("%10d", lista[i].tipoPasajero);
				printf("%10d", lista[i].estadoVuelo);
				printf("\n");
			}
		}
		printf("\n\n");

		retorno = 0;
	}



	return retorno;
}

int mostrarPasajeroActivo(Pasajero* lista, int len){
	int i;
	int retorno = -1;
	if(lista != NULL && len > 0){
		printf("ID            || NOMBRE          || APELLIDO         || PRECIO           || CODIGO   || TIPO  || ESTADO\n");
		for(i=0; i<len; i++){
			if(lista[i].isEmpty == 1 && lista[i].estadoVuelo == ACTIVO){
				printf("%d", lista[i].id);
				printf("%20s", lista[i].nombre);
				printf("%20s", lista[i].apellido);
				printf("%20.2f", lista[i].precio);
				printf("%20s", lista[i].codigoVuelo);
				printf("%10d", lista[i].tipoPasajero);
				printf("%10d", lista[i].estadoVuelo);
				printf("\n");
			}
		}
		printf("\n\n");

		retorno = 0;
	}



	return retorno;
}

int mostrarUnPasajero(Pasajero pasajero){
	int retorno = -1;


	if(pasajero.isEmpty == FULL){
		printf("ID            || NOMBRE          || APELLIDO         || PRECIO           || CODIGO   || TIPO  || ESTADO\n");
		printf("%d", pasajero.id);
		printf("%20s", pasajero.nombre);
		printf("%20s", pasajero.apellido);
		printf("%20.2f", pasajero.precio);
		printf("%20s", pasajero.codigoVuelo);
		printf("%10d", pasajero.tipoPasajero);
		printf("%10d", pasajero.estadoVuelo);
		printf("\n");
		retorno = 0;
	}

	return retorno;
}



int modificarNombre(Pasajero* lista, int len, int id, char * mensaje, char * mensajeError){
	int retorno = -1;
	char datoIngresado[256];
	int index;

	index = buscarPasajeroId(lista, len, id);

	if(index != -1 && getString (mensaje, mensajeError, datoIngresado, 256, 3) == 0){
		strcpy(lista[index].nombre, datoIngresado);
		retorno = 0;
	}

	return retorno;
}

int modificarApellido(Pasajero* lista, int len, int id, char * mensaje, char * mensajeError){
	int retorno = -1;
	char datoIngresado[256];
	int index;

	index = buscarPasajeroId(lista, len, id);

	if(index != -1 && getString (mensaje, mensajeError, datoIngresado, 256, 3) == 0){
		strcpy(lista[index].apellido, datoIngresado);
		retorno = 0;
	}

	return retorno;
}

int modificarPrecio(Pasajero* lista, int len, int id, char * mensaje, char * mensajeError){
	int retorno = -1;
	float datoIngresado;
	int index;

	index = buscarPasajeroId(lista, len, id);

	if (index != -1 && getFloat(&datoIngresado, mensaje, mensajeError, 10000, 1000000, 3) == 0){
		lista[index].precio = datoIngresado;
		retorno = 0;
	}

	return retorno;
}

int modificarTipo(Pasajero* lista, int len, int id, char * mensaje, char * mensajeError){
	int retorno = -1;
	int datoIngresado;
	int index;

	index = buscarPasajeroId(lista, len, id);

	if (index != -1 && getInt(&datoIngresado, mensaje, mensajeError, 1, 3, 3) == 0){
		lista[index].tipoPasajero = datoIngresado;
		retorno = 0;
	}

	return retorno;
}

int modificarCodigo(Pasajero* lista, int len, int id, char * mensaje, char * mensajeError){
	int retorno = -1;
	char datoIngresado[10];
	int index;

	index = buscarPasajeroId(lista, len, id);

	if(index != -1 && getString (mensaje, mensajeError, datoIngresado, 256, 3) == 0){
		strcpy(lista[index].codigoVuelo, datoIngresado);
		retorno = 0;
	}

	return retorno;
}



int informarTotalPromedio(Pasajero* lista, int len){
	int retorno = -1;
	float totalPasajes = 0;
	float promedioPasajes = 0;
	int contadorPasajeros = 0;
	int contadorPrecioAlto = 0;
	int i;

	if (lista != NULL && len > 0){

		for(i=0; i<len; i++){
			if(lista[i].isEmpty == FULL){
				totalPasajes += lista[i].precio;
				contadorPasajeros ++;
			}
		}

		promedioPasajes = totalPasajes / contadorPasajeros;

		for(i=0; i<len; i++){
			if(lista[i].isEmpty == FULL && lista[i].precio > promedioPasajes){
				contadorPrecioAlto ++;
			}
		}

		printf("--INFORME--\n");
		printf("COSTO TOTAL DE PASAJES: $ %.2f\n", totalPasajes);
		printf("PROMEDIO: $ %.2f\n", promedioPasajes);
		printf("PASAJEROS QUE SUPERAN EL PROMEDIO: %d\n", contadorPrecioAlto);
		printf("\n");

		retorno = 0;
	}

	return retorno;
}
