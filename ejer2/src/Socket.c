#include "Socket.h"
#include <stdio.h>
#include <string.h>

const int BuffSize = 1024;
const int Ok = 0;
const int Error = -1;

int RequestTime(int handle, int option_name, int maxTimeout);

int socketCreate() {
	int handle;
	handle = socket(AF_INET, SOCK_STREAM, 0);
	return handle;
}

int socketConnect(int handle, const char *ip, unsigned short port) {
	struct sockaddr_in addrclient = {0};
	addrclient.sin_addr.s_addr 	= inet_addr(ip);
	addrclient.sin_family 		= AF_INET;
	addrclient.sin_port 		= htons(port);
	int ret = connect(handle,(struct sockaddr *)&addrclient, sizeof(struct sockaddr_in));
	return ret;
}

int socketBind(int handle, unsigned short port) {
	struct sockaddr_in addrserver = {0};
	addrserver.sin_addr.s_addr 	= htonl(INADDR_ANY);
	addrserver.sin_family 		= AF_INET;
	addrserver.sin_port 		= htons(port);
	int ret = bind(handle,(struct sockaddr *)&addrserver, sizeof(struct sockaddr_in));
	return ret;
}

int socketAccept(int handle) {
	struct sockaddr_in client;
	int len = sizeof(struct sockaddr_in);
	int ret = accept(handle,(struct sockaddr *)&client,(socklen_t*)&len);
	return ret;
}

int socketRead(int handle, unsigned char *data, int maxTimeout) {
	if (RequestTime(handle, SO_RCVTIMEO, maxTimeout) == Ok) {
		int ret = recv(handle, data, BuffSize, 0);
		return ret;
	} 
	return Error;
}

int socketWrite(int handle, const unsigned char *data) {
	if (RequestTime(handle, SO_SNDTIMEO, 20 /*secs*/) == Ok) {
		int ret = send(handle, data, strlen(data), 0);
		return ret;
	}
	return Error;
}

int socketClose(int handle) {
	close(handle);
}

int RequestTime(int handle, int option_name, int maxTimeout) {
	struct timeval s_timeval;
	s_timeval.tv_sec = maxTimeout;
	s_timeval.tv_usec = 0;
	
	if (setsockopt(handle, SOL_SOCKET, option_name, 
				(char *)&s_timeval, sizeof(s_timeval)) == Error ) {
		fprintf(stderr, "Time out.\n");
		return Error;
	}
	return Ok;
}
