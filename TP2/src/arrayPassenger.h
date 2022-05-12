/*
 * arrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: caroo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;
}typedef Pasajero;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int inicializarPasajero(Pasajero* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int altaPasajero(Pasajero* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int buscarPasajeroId(Pasajero* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int bajaPasajero(Pasajero* list, int len, int id, char mensaje[]);

/** \brief Corrobora si hay pasajeros cargados en el array
*
* \param list Passenger*
* \param length int
* \return int. 0 Si hay al menos un pasajero cargado. -1 en caso contrario
*
*/
int hayPasajeros(Pasajero* list, int len, char * mensajeError);

/** \brief Busca el primer index libre y lo retorna por referencia
*
* \param list Passenger*
* \param len int
* \param index posicion en el array que es retornada por referencia
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int buscarIndexLibre(Pasajero* list, int len, int * index);


//------------------------------ORDENAMIENTO------------------------------

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int ordenarPasajeros(Pasajero* list, int len, int order);

/** \brief Sort the elements in the array of passengers ordering by type, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int ordenarPasajeroXTipo(Pasajero* list, int len, int order);

/** \brief Sort the elements in the array of passengers ordering by code, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int ordenarPasajeroXCodigo(Pasajero* list, int len, int order);



//----------------------------------PRINT----------------------------------


/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int. 0 Si los parametros son validos y se pudo mostrar el listado. -1 en caso contrario
*
*/
int mostrarPasajero(Pasajero* list, int length);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int ordenarPasajeroXCodigo(Pasajero* list, int len, int order);

/** \brief muestra el pasajero que se pasa por parametro
*
* \param list Passenger*
* \return int. 0 Si los parametros son validos y se pudo mostrar el listado. -1 en caso contrario
*
*/
int mostrarUnPasajero(Pasajero pasajero);

/** \brief print the content of passengers array with list[i].statusFlight == ACTIVO
*
* \param list Passenger*
* \param length int
* \return int. 0 Si los parametros son validos y se pudo mostrar el listado. -1 en caso contrario
*
*/
int mostrarPasajeroActivo(Pasajero* list, int length);



//---------------MODIFICACIONES---------------

/** \brief Recibe la lista de pasajeros, busca el pasajero por su ID y cambia el campo del nombre
*
* \param list Passenger*
* \param len int
* \param int id id con el que busca al pasajero seleccionado
* \param mensaje Mensaje con el que se le solicita al usuario un nuevo nombre
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modificarNombre(Pasajero* list, int len, int id, char * mensaje, char * mensajeError);

/** \brief Recibe la lista de pasajeros, busca el pasajero por su ID y cambia el campo del apellido
*
* \param list Passenger*
* \param len int
* \param int id id con el que busca al pasajero seleccionado
* \param mensaje Mensaje con el que se le solicita al usuario un nuevo apellido
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modificarApellido(Pasajero* list, int len, int id, char * mensaje, char * mensajeError);

/** \brief Recibe la lista de pasajeros, busca el pasajero por su ID y cambia el campo del precio
*
* \param list Passenger*
* \param len int
* \param int id id con el que busca al pasajero seleccionado
* \param mensaje Mensaje con el que se le solicita al usuario un nuevo precio
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modificarPrecio(Pasajero* list, int len, int id, char * mensaje, char * mensajeError);

/** \brief Recibe la lista de pasajeros, busca el pasajero por su ID y cambia el campo del codigo
*
* \param list Passenger*
* \param len int
* \param int id id con el que busca al pasajero seleccionado
* \param mensaje Mensaje con el que se le solicita al usuario un nuevo codigo
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modificarCodigo(Pasajero* list, int len, int id, char * mensaje, char * mensajeError);

/** \brief Recibe la lista de pasajeros, busca el pasajero por su ID y cambia el campo del tipo
*
* \param list Passenger*
* \param len int
* \param int id id con el que busca al pasajero seleccionado
* \param mensaje Mensaje con el que se le solicita al usuario un nuevo tipo
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modificarTipo(Pasajero* list, int len, int id, char * mensaje, char * mensajeError);


//--------------------INFORMES--------------------

/** \brief Recibe la lista de pasajeros. Imprime por pantalla el costo total de los precios, su promedio y cuantos pasajeros superan el promedio.
*
* \param list Passenger*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int informarTotalPromedio(Pasajero* list, int len);

#endif /* ARRAYPASSENGER_H_ */
