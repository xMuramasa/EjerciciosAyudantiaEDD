
#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"
#include <math.h>

int main() {
	nroComplejo* nro = crearComplejo(4, 4);
	toString(nro);
	printf("%d %d %f", parteReal(nro), parteIm(nro), valorAbsoluto(nro));

	nroComplejo* nro2 = crearComplejo(4, 4);
	nroComplejo* nro3 = suma(nro, nro2);
	nroComplejo* nro4 = conjugado(nro3);

	toString(nro);
	toString(nro2);
	toString(nro3);
	toString(nro4);

	borrarComplejo(nro);
	borrarComplejo(nro2);
	borrarComplejo(nro3);
	borrarComplejo(nro4);

	return 0;
}



nroComplejo* crearComplejo(int im, int real) {
	nroComplejo* nro = (nroComplejo*) malloc(sizeof(nroComplejo));
	nro->im = im;
	nro->real = real;
	return nro;
}

int parteReal(nroComplejo* nro) {
	return nro->real;
}

int parteIm(nroComplejo* nro) {
	return nro->im;
}

double valorAbsoluto(nroComplejo* nro) {
	return sqrt(pow(nro->real, 2) + pow(nro->im, 2));
}

nroComplejo* conjugado(nroComplejo* nro) {
	nroComplejo* res = crearComplejo(nro->real, nro->im * -1);
	return res;
}

nroComplejo* suma(nroComplejo* nro1, nroComplejo* nro2) {
	nroComplejo* res = crearComplejo(nro1->real + nro2->real, nro1->im + nro2->im);
	return res;
}

void toString(nroComplejo* nro) {
	printf("%d + %di", nro->real, nro->im);
}

void borrarComplejo(nroComplejo* nro) {
	free(nro);
}