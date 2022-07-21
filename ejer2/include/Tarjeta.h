#ifndef __TARJETA_H__
#define __TARJETA_H__

#include <stdbool.h>

#define LEN_RANGE       9
#define LEN_LABEL_CARD  13

typedef struct {
	char rangeLow[LEN_RANGE];
	char rangeHigh[LEN_RANGE];
	unsigned char len;
	int id;
} range_t;

typedef struct {
	char label[LEN_LABEL_CARD];
	int id;
} card_t;

/** 
 * Chequea el buffer de Request Message enviado desde client.
 * 
 * @param buffer set de datos del request message.
 *
 * @return devuelve @true si se encontró el número de la tarjeta del request message.
 *         de lo contrario devuelve @false.
 */
bool CheckRequestMessage(char* buffer); 


#endif /*__TARJETA_H__*/
