/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "menu.h"


#define BTC 4606954.55

int main(void) {
	setbuf(stdout, NULL);

  int opcion;
  int flagKm = 0;
  int flagPrecioAero = 0;
  int flagPrecioLatam =0;
  int flagCostos =0;


  float kilometros;
  float precioAero;
  float precioLatam;
  float debitoAero;
  float debitoLatam;
  float creditoAero;
  float creditoLatam;
  float btcAero;
  float btcLatam;
  float precioXKmAero;
  float precioXKmLatam;
  float diferenciaPrecio;


  do
  {
	 opcion = menuPrincipal(opcion);

	switch(opcion)
	{
		case 1:  // funciona
			kilometros = getFloat(&kilometros, "Ingrese la cantidad de kilometros:", "Ingrese un valor correcto", 1, 600000000, 3);
			flagKm =1;

			break;
	    case 2: // funiona

			precioAero = getFloat(&precioAero,"\nIngrese el precio de Aerolíneas Argentinas: ", "Ingrese un valor correcto: ", 1,12000000,3);
			flagPrecioAero =1;

			precioLatam = getFloat(&precioLatam, "\nIngrese el precio de la Aerolinea Latam: ", "Ingrese un valor correcto: ",1,12000000,3);

			flagPrecioLatam =1;

			break;
	    case 3: // funciona
	    	if(flagKm == 1 && flagPrecioAero ==1 && flagPrecioLatam ==1)
	    	{
	    		debitoAero = calcularDescuento(precioAero);
	    		debitoLatam = calcularDescuento(precioLatam);

	    		creditoAero = calcularInteres(precioAero);
	    		creditoLatam =calcularInteres(precioLatam);

	    		btcAero = calcularPrecioBit(precioAero, BTC);
				btcLatam =calcularPrecioBit(precioLatam, BTC);


				precioXKmLatam = precioPorKm(precioLatam, kilometros);
				precioXKmAero =precioPorKm(precioAero, kilometros);

				diferenciaPrecio = calcularDiferencia(precioLatam,precioAero);
				flagCostos =1;

	    	}
	    	else
	    	{
	    		printf("\nDebe ingresar los valores para poder calcular los costos\n");
	    	}


				break;
	    case 4: // funciona

	    	if(flagCostos ==1){
	    	 printf("\n********LATAM*******\n"
	    			"\n1. Precio con tarjeta de Debito es:$ %.2f"
	    			"\n2. Precio con tarjeta de Credito es:$ %.2f"
	    			"\n3. Precio pagando con Bitcoin es:$ %.4f BTC"
	    			"\n4. Precio unitario es:$ %.2f\n"

	    			"\n*******Aerolineas Argentinas********\n"
	    			"\n1. Precio con tarjeta de Debito es:$ %.2f"
					"\n2. Precio con tarjeta de Credito es:$ %.2f"
					"\n3. Precio pagando con Bitcoin es:$ %.4f BTC"
	    			"\n4. Precio unitario es:$ %.2f"
					"\n\nLa diferencia de precio es:$ %2.f\n"
	    			,debitoLatam,creditoLatam,btcLatam,precioXKmLatam,debitoAero,creditoAero,btcAero,precioXKmAero,diferenciaPrecio);
	    	}else{
	    		printf("Aun no se calcularon los costos");
	    	}
	    	break;
	    case 5:

	    	kilometros = 7090;
	    	precioAero = 1335000.66;
	    	precioLatam = 1350000.76;

	    	debitoAero =calcularDescuento(precioAero);
			debitoLatam = calcularDescuento(precioLatam);

			creditoAero = calcularInteres(precioAero);
			creditoLatam = calcularInteres(precioLatam);

			btcAero = calcularPrecioBit(precioAero, BTC);
			btcLatam = calcularPrecioBit(precioLatam, BTC);

			precioXKmAero = precioPorKm(precioAero, kilometros);
			precioXKmLatam = precioPorKm(precioLatam, kilometros);

			diferenciaPrecio =calcularDiferencia(precioLatam,precioAero);

	    	printf("\n********LATAM*******\n"
	    			"\n1. Precio con tarjeta de Debito es:$ %.2f"
	    			"\n2. Precio con tarjeta de Credito es:$ %.2f"
	    			"\n3. Precio pagando con Bitcoin es:$ %.4f BTC"
	    			"\n4. Precio unitario es:$ %.2f\n"

	    			"\n*******Aerolineas Argentinas********\n"
	    			"\n1. Precio con tarjeta de Debito es:$ %.2f"
					"\n2. Precio con tarjeta de Credito es:$ %.2f"
					"\n3. Precio pagando con Bitcoin es:$ %.4f BTC"
	    			"\n4. Precio unitario es:$ %.2f"
					"\n\nLa diferencia de precio es:$ %2.f\n"
					,debitoLatam,creditoLatam,btcLatam,precioXKmLatam,debitoAero,creditoAero,btcAero,precioXKmAero,diferenciaPrecio);
           break;
	    case 6:
	    	printf("\nGracias por utilizar nuestros servicios !!!");
	    break;
	    default: printf("\nLa opcion no es valida\n");

	}

  }while(opcion!=6);

	return EXIT_SUCCESS;
}
