/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include "arrayPassenger.h"

#define MAX 2000

int main(void) {
	setbuf(stdout, NULL);

	Pasajero pasajeros[MAX];
	int id = 100;
	char nombreIngresado[50];
	char apellidoIngresado[50];
	float precioIngresado;
	int tipoPasajerpIngresado;
	char codigoIngresado[10];

	int auxiliarBusquedaID;

	int menu;
	int menuModificar;
	int menuInformes;



	if(inicializarPasajero(pasajeros, MAX)==0){

		do{
			printf("*****MENU PRINCIPAL*****\n");
			printf("1.- ALTAS\n");
			printf("2.- MODIFICAR\n");
			printf("3.- BAJA\n");
			printf("4.- INFORMAR\n");
			printf("5.- SALIR\n");

			if(getInt(&menu, "Por favor, ingrese una opcion:", "La opcion Ingresada no es valida, intente nuevamente\n", 1, 5, 3)==0){
				switch(menu){
				case 1:
					if(getString("Por favor, ingrese el nombre del pasajero: \n", "Ha habido un error, intente nuevamente\n", nombreIngresado, 50, 3) == 0 &&
							getString("Por favor, ingrese el apellido del pasajero: \n", "Ha habido un error, intente nuevamente\n", apellidoIngresado, 50, 3) == 0 &&
							getFloat(&precioIngresado, "Por favor, ingrese un precio\n", "Precio fuera de parametros, intente nuevamente \n", 10000, 500000, 3) == 0 &&
							getInt(&tipoPasajerpIngresado, "Ingrese el tipo: 1- Activo | 2- Cancelado  | 3- Demorado\n", "Tipo fuera de parametros, intente nuevamente \n", 1, 3, 3) == 0 &&
							getString("Por favor, ingrese el codigo del vuelo: \n", "Ha habido un error, intente nuevamente\n", codigoIngresado, 50, 3) == 0){

						altaPasajero(pasajeros, MAX, id, nombreIngresado, apellidoIngresado, precioIngresado, tipoPasajerpIngresado, codigoIngresado);
						id++;
					}
					break;
				case 2:
					if(hayPasajeros(pasajeros, MAX, "No hay pasajeros ingresados\n") == 0 && mostrarPasajero(pasajeros, MAX) == 0 &&
							getInt(&auxiliarBusquedaID, "Por favor, ingrese el ID del pasajero que desea modificar\n", "No existe ese pasajero\n", 0, 1000000, 3) == 0){
						do{
							printf("*****MODIFICACIONES*****\n");
							printf("Ingrese la opcion que desea modificar:\n");
							printf("1.- NOMBRE\n");
							printf("2.- APELLIDO\n");
							printf("3.- PRECIO DEL VUELO\n");
							printf("4.- TIPO\n");
							printf("5.- CODIGO DE VUELO\n");
							printf("6.- VOLVER AL MENU ANTERIOR\n");

							if(getInt(&menuModificar, "Por favor, ingrese una opcion\n", "La opcion Ingresada no es valida, intente nuevamente\n", 1, 6, 3)==0){
								switch(menuModificar){
								case 1:
									if(modificarNombre(pasajeros, MAX, auxiliarBusquedaID, "Por favor, ingrese el nuevo nombre.\n", "Ha habido un error, intente nuevamente.\n") == 0){
										printf("El nombre ha sido modificado exitosamente.\n");
									}
									else{
										printf("Ha habido un error. Intente nuevamente.\n");
									}
									break;
								case 2:
									if(modificarApellido(pasajeros, MAX, auxiliarBusquedaID, "Por favor, ingrese el nuevo apellido.\n", "Ha habido un error, intente nuevamente.\n") == 0){
										printf("El apellido ha sido modificado exitosamente.\n");
									}
									else{
										printf("Ha habido un error. Intente nuevamente.\n");
									}
									break;
								case 3:
									if(modificarPrecio(pasajeros, MAX, auxiliarBusquedaID, "Por favor, ingrese el nuevo precio", "Precio fuera de parametros, intente nuevamente\n") == 0){
										printf("El precio ha sido modificado exitosamente.\n");
									}
									else{
										printf("Ha habido un error. Intente nuevamente.\n");
									}
									break;
								case 4:
									if(modificarTipo(pasajeros, MAX, auxiliarBusquedaID, "Por favor, ingrese el nuevo tipo\n", "Tipo incorrecto, intente nuevamente\n") == 0){
										printf("El tipo de vuelo ha sido modificado exitosamente.\n");
									}
									else{
										printf("Ha habido un error. Intente nuevamente.\n");
									}
									break;
								case 5:
									if(modificarCodigo(pasajeros, MAX, auxiliarBusquedaID, "Por favor, ingrese el nuevo codigo de vuelo\n", "Ha habido un error, intente nuevamente") == 0){
										printf("El tipo de vuelo ha sido modificado exitosamente.\n");
									}
									else{
										printf("Ha habido un error. Intente nuevamente.\n");
									}
									break;
								case 6:
									break;
								}
							}

						}while(menuModificar != 6);


					}
					break;
				case 3:
					if(hayPasajeros(pasajeros, MAX, "No hay pasajeros ingresados\n") == 0 && mostrarPasajero(pasajeros, MAX) == 0 &&
							getInt(&auxiliarBusquedaID, "Por favor, ingrese el ID del pasajero que desea remover\n", "No existe ese pasajero\n", 0, 1000000, 3) == 0 &&
							bajaPasajero(pasajeros, MAX, auxiliarBusquedaID, "Desea eliminar este pasajero?(S/N)\n") == 0){
						printf("Se ha eliminado al pasajero exitosamente.\n");
					}
					else{
						printf("Ha habido un error. Por favor, reintente nuevamente\n");
					}
					break;
				case 4:
					if(hayPasajeros(pasajeros, MAX, "No hay pasajeros ingresados.\n") == 0){
						do{
							printf("*****INFORMES*****\n");
							printf("Seleccione una opcion:\n");
							printf("1.- Pasajeros ordenados por nombre y tipo\n");
							printf("2.- Total y promedio de pasajes. Numero de pasajeros que superan el precio promedio\n");
							printf("3.- Listado de pasajeros por codigo de vuelo y estado de vuelo ACTIVO\n");
							printf("4.- Volver al menu anterior\n");

							if(getInt(&menuInformes, "Por favor, ingrese una opcion\n", "La opcion Ingresada no es valida, intente nuevamente\n", 1, 4, 3)==0){
								switch(menuInformes){
								case 1:
									if(ordenarPasajeros(pasajeros, MAX, 1)==0 && ordenarPasajeroXTipo(pasajeros, MAX, 1) == 0 &&
											mostrarPasajero(pasajeros, MAX) == 0){

										printf("Listado de pasajeros mostrado\n\n");
									}
									else{
										printf("Ha habido un error, por favor, intente nuevamente\n");
									}
									break;
								case 2:
									if(informarTotalPromedio(pasajeros, MAX) == 0){
										printf("Informes mostrados\n\n");
									}
									else{
										printf("Ha habido un error, por favor, intente nuevamente\n");
									}
									break;
								case 3:
									if(ordenarPasajeroXCodigo(pasajeros, MAX, 1) == 0 && mostrarPasajeroActivo(pasajeros, MAX) == 0){
										printf("Listado de pasajeros mostrado\n\n");
									}
									else{
										printf("Ha habido un error, por favor, intente nuevamente\n");
									}
									break;
								case 4:
									break;
								}
							}

						}while(menuInformes != 4);
					}
					break;
				case 5:
					break;
				}
			}
		}while(menu != 5);
	}

	return EXIT_SUCCESS;
}
