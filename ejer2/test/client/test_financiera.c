#include <t_financiera.h>
#include <Socket.h>
#include <stdio.h>
#include <string.h>

#define LenTipoMensaje 4
#define LenNumTarjeta  16
#define LenMonto       13

#define LOGERR(fmt,...) { fprintf(stderr,fmt "\n",##__VA_ARGS__);}

typedef int sock;

int EnviarAHost(unsigned char* data);

int main() {
	Transaccion* t = CreaTransaccion(25.25, "1243098732458765", "223");

	Mostrar(ValidarDatos(t)); 
	
	char auxMonto[LenMonto];
	snprintf(auxMonto, LenMonto, "%012.0f", t->monto*100);

	char* buffer = CrearRequestMessage(t);
	return EnviarAHost((unsigned char*)buffer);
}

int EnviarAHost(unsigned char* data) {
	sock sockfd = socketCreate();
	if (sockfd == -1) {
		LOGERR("No se pudo crear el socket");
		return -1;
	}

	sock connfd = socketConnect(sockfd, "127.0.0.1", 9000);
	if (connfd == -1) {
		LOGERR("Fallo en la conexión");
		return -1;
	}

	printf("Se pudo conectar con el servidor\n");

	sock ret = socketWrite(sockfd, data);

	socketClose(sockfd);
	return 0;
}

		


