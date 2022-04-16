/*
 * funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "menu.h"



float calcularInteres(float precio){
	float resultado;

	resultado = precio + (precio*0.25);

	return resultado;
}

float calcularDescuento(float precio){
	float resultado;

	resultado= precio - (precio * 0.1);

	return resultado;
}


float calcularPrecioBit(float precio, float Bit){
	float resultado;

	resultado = precio / Bit;

	return resultado;
}

float precioPorKm(float precio, float km){
	float resultado;

	resultado = precio / km;

	return resultado;

}


float calcularDiferencia(float latam, float aerolineas){
	float resultado;
	if(latam<aerolineas){
		resultado= aerolineas - latam;
	}else{
		resultado = latam - aerolineas;
	}

	return resultado;
}


int getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int min, int max, int reintentos){

	int auxNumeroIngresado;
	int retorno =-1;


	if(pNumeroIngresado != NULL&& mensaje != NULL && mensajeError != NULL && min <= max && reintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);

			if(auxNumeroIngresado >= min && auxNumeroIngresado <= max){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >> 0);
	}

	return retorno;
}

int getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, int min, int max, int reintentos){

	float auxNumeroIngresado;
	int retorno=-1;

	if(pNumeroIngresado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);

			if(auxNumeroIngresado >= min && auxNumeroIngresado <= max){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}



