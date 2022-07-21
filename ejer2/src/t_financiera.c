#include "t_financiera.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

Transaccion* 
CreaTransaccion(double monto, const char* numeroTarjeta, const char* codigoSeguridad) {
	Transaccion *transaccion = malloc(sizeof(Transaccion));
	transaccion->monto = monto;
	strncpy(transaccion->numeroTarjeta, numeroTarjeta, strlen(numeroTarjeta));
	strncpy(transaccion->codigoSeguridad, codigoSeguridad, LengthCode);
	return transaccion;
}

bool ValidarDatos(Transaccion* transaccion) {
	if (!transaccion) return false;
	return (transaccion->monto >= 0.0 &&
			strlen(transaccion->numeroTarjeta) >= MinCardLength &&
			strlen(transaccion->codigoSeguridad) == (LengthCode-1));
}

int Mostrar(bool status) {
	if (!status) {
		fprintf(stderr,
				"Los datos ingresados son incorrectos:\n"
				"\tVerifique Número de Tarjeta o Código de Seguridad.\n");
	}
	return (status?0:-1);
}

char* CrearRequestMessage(Transaccion* transaccion) {
	char* buffer = malloc(1024);
	char* buffaux = buffer;
	char  tipoMsg[] = "0200";
	char  c_lenNumTarjeta[3];
	int   i_lenNumTarjeta = strlen(transaccion->numeroTarjeta);
	char  monto[13];

	snprintf(c_lenNumTarjeta, 3, "%d", i_lenNumTarjeta);
	snprintf(monto, 13, "%012.0f", transaccion->monto*100);

	memcpy(buffaux, tipoMsg, 4);
	memcpy(buffaux+=4, c_lenNumTarjeta, 2);
	memcpy(buffaux+=2, transaccion->numeroTarjeta, i_lenNumTarjeta);
	memcpy(buffaux+=i_lenNumTarjeta,monto, 12);
	memcpy(buffaux+=12, transaccion->codigoSeguridad, LengthCode);

	return buffer;
}

void Destruir(Transaccion* transaccion) {
	free(transaccion);
}


