#include "Tarjeta.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_MSG 5
#define LEN_NUM 3
#define LEN_MONTO 13
#define LEN_SEC 4

struct RequestMsg {
	char tipoMensaje[LEN_MSG];
	char  lenNumTarjeta[LEN_NUM];
	char* numeroTarjeta;
	char  monto[LEN_MONTO];
	char  codSeguridad[LEN_SEC];
};	

struct
RequestMsg* CrearRequest(char* buffer);

bool CheckRequestMessage(char* buffer) {
	
	struct RequestMsg* requestMsg = CrearRequest(buffer);
	range_t rt;
	card_t ct;

	strncpy(rt.rangeLow, requestMsg->numeroTarjeta, 8);
	rt.rangeLow[8] = '\0';

	int offset = (atoi(requestMsg->lenNumTarjeta) - LEN_RANGE);
	strncpy(rt.rangeHigh, requestMsg->numeroTarjeta+offset, 8);

}

struct
RequestMsg* CrearRequest(char* buffer) {
	struct RequestMsg *rm = malloc(sizeof(struct RequestMsg));
	
	strncpy(rm->tipoMensaje, buffer, 4);
	printf("tipo: %s\n", rm->tipoMensaje);

	strncpy(rm->lenNumTarjeta, buffer+=4, 2);
	int len = atoi(rm->lenNumTarjeta);
	printf("len:  %s %d\n", rm->lenNumTarjeta, len);

	rm->numeroTarjeta = malloc(len+1);
	strncpy(rm->numeroTarjeta, buffer+=2, len);
	printf("num:  %s\n", rm->numeroTarjeta);

	strncpy(rm->monto, buffer+=atoi(rm->lenNumTarjeta), (LEN_MONTO-1));
	printf("monto: %s\n", rm->monto);

	strncpy(rm->codSeguridad, buffer+=(LEN_MONTO-1), 3);
	printf("sec:  %s\n", rm->codSeguridad);

	return rm;
}




