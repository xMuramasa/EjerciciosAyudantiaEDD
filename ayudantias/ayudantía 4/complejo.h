
typedef struct {
	int real;
	int im;
} nroComplejo;

int parteReal(nroComplejo* nro);
int parteIm(nroComplejo* nro);
double valorAbsoluto(nroComplejo* nro);
void toString(nroComplejo* nro);
nroComplejo* conjugado(nroComplejo* nro);
nroComplejo* suma(nroComplejo* nro1, nroComplejo* nro2);
nroComplejo* crearComplejo(int im, int real);
void borrarComplejo(nroComplejo* nro);