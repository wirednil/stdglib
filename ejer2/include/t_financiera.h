#ifndef __T_FINANCIERA_H__
#define __T_FINANCIERA_H__

#include <stdbool.h>

#define MinCardLength 13
#define MaxCardLength 17 //16
#define LengthCode    4     //3

typedef struct Transaccion {
	double monto;
	char numeroTarjeta[MaxCardLength];
	char codigoSeguridad[LengthCode];
} Transaccion;

/**
 * Inicializa una nueva transacción.
 *
 * @param monto 
 * @param numeroTarjeta
 * @param codigoSeguridad
 *
 * @return nueva transaccion.
 */
Transaccion* CreaTransaccion(double monto, const char* numeroTarjeta, 
		const char* codigoSeguridad);

/**
 * Valida los datos de la transaccion.
 * 
 * @param transaccion es una instancia válida, creada con una de las funciones creacionales.
 *
 * @return si la transaccion es válida retorna @true, de lo contrario @false.
 */
bool ValidarDatos(Transaccion* transaccion);

int Mostrar(bool status); 

char* CrearRequestMessage(Transaccion* transaccion);

/**
 * Libera la memoría 
 *
 * @param transaccion es una instancia válida, creada con una de las funciones creacionales.
 */
void Destruir(Transaccion* transaccion);

#endif /*__T_FINANCIERA_H__*/
