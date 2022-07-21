#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BuffSize = 1024;
const int CantidadIngreso = 2;
const int MaxLength =11;

int IngresarNumero();
char* NombreArchivo();
void Serializar(FILE* archivo, int* valor);
int ErrorAlAbrirArchivo();

int IngresosDeDatos() {
	int num[CantidadIngreso];
	int c = 0;
	printf("Ingrese %d numero(s) y luego el cero para salir.\n",
			CantidadIngreso);
 	while ((num[c++] = IngresarNumero())) 
		if (c == (CantidadIngreso + 1)) {
			fprintf(stderr, "Solo se debe ingresar %d numero(s), ingrese 0 (cero) para finalizar ingreso.\n",
					CantidadIngreso);
			c--;
		}
	char* nombre = NombreArchivo();
	FILE* archivo = fopen(nombre,"w");
	--c; // @c actual ubicación donde se guardó el cero en num[c]
	if (archivo) {
		while (--c) 
			Serializar(archivo, &num[c]);
		Serializar(archivo, &num[c]);
	} else {
		return ErrorAlAbrirArchivo();
	} 
	fclose(archivo);
	free(nombre);
	return EXIT_SUCCESS;
}

int main() {
	return IngresosDeDatos();
}

int IngresarNumero() {
	int a;
	printf("Ingrese un numero: ");
	scanf("%d", &a);
//	printf("numero: %d\n", a);
	return a;
}

char* NombreArchivo() {
	char * nombre = (char*)malloc(BuffSize);
	printf("Ingrese un nombre para el archivo: ");
	scanf("%s",nombre);
//	printf("nombre: %s\n", nombre);
	return nombre;
}

char* AString(int* valor) {
	char* valor_str = (char*)malloc(sizeof(char) * MaxLength);
	snprintf(valor_str,MaxLength, "%010d", (*valor));
//	printf("numero: %s\n", valor_str);
	return valor_str;
}

void Serializar(FILE* archivo, int* valor) {
//	printf("numero: %d\n", *valor);
	char databuffer[10] = {0};
	char* numero_str = AString(valor);
	memcpy(databuffer, numero_str,strlen(numero_str));
	fprintf(archivo,"%s\r\n",databuffer);
	free(numero_str);
}


int ErrorAlAbrirArchivo() {
	fprintf(stderr, "No fue posible crear/abrir el archivo.\n");
	return -1;
}

