
#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"
#include <math.h>





int main() {

	complex* c1 = buildComplex(3,5);
	complex* c2 = buildComplex(9,-1);
	complex* s = sumaComp(c1, c2);

	complex* c1_Conj = conjugado(c1);

	printComplex(c1);
	printComplex(c2);
	printComplex(s);
	printComplex(c1_Conj
	);

	destroyer(c1);
	destroyer(c2);
	destroyer(s);
	return 0;
}

complex* buildComplex(int re, int im)
{

	complex *c = (complex *)malloc(sizeof(complex));

	c->real = re;
	c->imaginario = im;
	return c;
}

int re(complex *c)
{
	return c->real;
}

int im(complex *c)
{
	return c->imaginario;
}

double absol(complex *c)
{
	return sqrt(pow(re(c), 2) + pow(im(c), 2));
}

void destroyer(complex *c)
{
	free(c);
}

void printComplex(complex *c)
{
	printf("%d+%di\n", re(c), im(c));
}

complex *conjugado(complex *c){
	complex* conj = buildComplex(re(c), (-1)*im(c));
	return conj;
}

complex* sumaComp(complex* a, complex* b){
	complex *s = buildComplex(re(a) + re(b), im(a) + im(b));
	return s;
}

/*
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

*/
