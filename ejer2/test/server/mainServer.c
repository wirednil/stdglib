#include <Socket.h>
#include <Tarjeta.h>
#include <stdio.h>
#include <string.h>

typedef int sock;

#define LenTipoMensaje 5
#define LenNumTarjeta  17
#define LenMonto       13


int main() {
	sock sockfd = socketCreate();
	
	if (sockfd == -1) {
		printf("No se pudo crear el socket.\n");
		return -1;
	}
	printf("Socket creado.\n");

	if (socketBind(sockfd, 9000) == -1) {
		printf("Falló la conexión.\n");
		return -1;
	}
	printf("Bind creado.\n");

	listen(sockfd, 3);
	printf("listen.\n");

	while (1) {
		sock acceptfd = socketAccept(sockfd);
		if (acceptfd == -1) {
			printf("Falló socketAccept.\n");
			return -1;
		}

		unsigned char buffer[1024] = {0}; 
		sock recvfd = recv(acceptfd, (void*)buffer, 1024,0);
		if (recvfd == -1) {
			printf("Falló recv.\n");
			break;
		}

		printf("%s\n",buffer);

		CheckRequestMessage(buffer);

		sock sendfd = send(acceptfd, "Ok", strlen("OK"), 0);
		if (sendfd = -1) {
			printf("Falló send.\n");
			return -1;
		}

		socketClose(acceptfd);
		sleep(1);
	}
	return 0;
}
