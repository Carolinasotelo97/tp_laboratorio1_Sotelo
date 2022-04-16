/*
 * funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: caroo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * \brief Aplica al primer parametro el interes porcentual del segundo parametro y lo retorna
 * \param precio Variable sobre la que se calcula el interes
 * \param interes Variable que establece el interes
 * \return El primer parametro con interes
 */
float calcularInteres(float precio);
/**
 * \brief Aplica al primer parametro el descuento porcentual del segundo parametro y lo retorna
 * \param precio Variable sobre la que se calcula el descuento
 * \param aumento Variable que establece el descuento
 * \return El primer parametro descontado
 */
float calcularDescuento(float precio);

/**
 * \brief Calcula el precio en BTC y lo retorna
 * \param precio Variable que define el total
 * \param valorBTC Variable que divide el total
 * \return El valor traducido a BTC del primer parametro
 */
float calcularPrecioBit(float precio, float Bit);
/**
 * \brief Calcula el precio por cada kilometro y lo retorna
 * \param precio Variable que define el total
 * \param kilometros variable que divide al primer parametro
 * \return El valor del primer parametro dividido por el segundo
 */
float precioPorKm(float precio, float km);

/**
 * \brief Calcula el diferencial de los dos parametros y lo retorna
 * \param latam, aerolineas Variables a calcular su diferencia
 * \return El diferencial de ambos parametros, siempre como valor positivo (mayor a 0)
 */
float calcularDiferencia(float latam, float aerolineas);
/**
 * \brief Solicita un INT al usuario, lo valida en un rango y lo retorna por referencia
 * \param pNumeroIngresado Puntero donde se almacena el valor del INT solicitado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje mostrado al ingresar un INT fuera de rango
 * \param min, max Valores que establecen el rango
 * \param reintentos Cantidad de veces que el usuario puede ingresar el dato fuera de rango
 * \return -1 si el usuario no ingreso un INT validado. 0 si se realizo la carga satisfactoriamente
 */
int getInt(int * pNumeroIngresado, char * mensaje, char* mensajeError, int min, int max, int reintentos);

/**
 * \brief Solicita un FLOAT al usuario, lo valida en un rango y lo retorna por referencia
 * \param pNumeroIngresado Puntero donde se almacena el valor del FLOAT solicitado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje mostrado al ingresar un INT fuera de rango
 * \param min, max Valores que establecen el rango
 * \param reintentos Cantidad de veces que el usuario puede ingresar el dato fuera de rango
 * \return -1 si el usuario no ingreso un FLOAT validado. 0 si se realizo la carga satisfactoriamente
 */
int getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, int min, int max, int reintentos);

#endif /* FUNCIONES_H_ */
