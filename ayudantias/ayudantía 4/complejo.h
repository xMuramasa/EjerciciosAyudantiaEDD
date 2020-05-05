
typedef struct {
	int real;
	int im;
} nroComplejo;

typedef struct
{
	int real;
	int imaginario;

} complex;

complex *buildComplex(int re, int im);
int re(complex* c);
int im(complex *c);
double absol(complex* c);
void destroyer(complex* c);
void printComplex(complex* c);
complex* sumaComp(complex* a, complex* b);
complex* conjugado(complex *c);

/*
	int parteReal(nroComplejo* nro);
	int parteIm(nroComplejo* nro);
	double valorAbsoluto(nroComplejo* nro);
	void toString(nroComplejo* nro);
	nroComplejo* conjugado(nroComplejo* nro);
	nroComplejo* suma(nroComplejo* nro1, nroComplejo* nro2);
	nroComplejo* crearComplejo(int im, int real);
	void borrarComplejo(nroComplejo* nro);
*/