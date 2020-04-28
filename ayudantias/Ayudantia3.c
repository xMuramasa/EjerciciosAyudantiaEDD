
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Funciones interesantes para manejo de strings
    * int strlen(char* s): retorna el largo del string apuntado por s.
    * int strcmp(char* lhs, char* rhs): que compara dos strings, retornando 0 si es que son iguales.
    * char* strcpy(char* d, char* s): copia el string s en d, reemplazando su contenido.
    * char* strcat(char* d, char* s): concatena el string s en d. -> d + s = ds -> "abba" + "popo" = "abbapopo"
    * char* strchr(char* s, char c)
*/

/* Prolblema 1:
        a) Dado un string S compuesto por una sola palabra de largo par, 
			crea una función que pida una palabra por pantalla,
            la escriba en un archivo, 
			para luego leerla, y finalmente obtenga estadisticas de S. 
            Es decir, {largo} y si es o no, un palíndromo.

        ** opcional:
        b) Crear la funcion char* palindromo(char* s) que convierte el 
		   string s en palíndromo, y 
           AGREGUE la palabra nueva al archivo anterior
*/


// problema propuesto
/*
	[...Imagine que ocurrió algo que involucra a un personaje llamado Jacinto], por lo tanto, usted debe desarrollar el siguiente programa:
	Al ejecutarlo, reciba un número n, seguido de una palabra S
	Luego,recibirá n líneas distintas con 1 número x y una palabra y, donde x es el largo de la palabra y, 
	su programa debe almacenar en 1 arreglo las palabras mayores que la palabra S, en otro las palabras menores y en otro más las palabras iguales.
	Finalmente, debe escribir en un archivo las palabras mayores y en otro archivo las menores, y mostrar en pantalla el total de palabras iguales

		***	Nota: Recuerde liberar toda la memoria.

		Ejemplo:

			3 ola

			6 olaolaola
			3 asd
			3 ola

			Palabras mayores: olaolaola
			Palabras menores: asd
			Palabras iguales: 1
*/


// func stats, dice si un palabra es pal, y muestra por pantalla el len de la palabra
// recibe: arrat de caracteres
// prints: largo de la palabra
// returns : 0 si es palindromo
//			 1 si no es

// s = ab | ba  DONE
// x = ab		DONE
// y = ba -> flip(ab) DONE
// strcmp(x, y)

int  stats(char * A){

	char *x;
	char *y;

	int len = strlen(A);
	int half = len/2;
	printf("El largo de la palabra es: %d", len);


	x = (char *)malloc(sizeof(char) * (half) + 1);

	y = (char *)malloc(sizeof(char) * (half) + 1);

	// recorrer ->
	for (int i = 0; i < half; i++)
		x[i] = A[i];

	// recorrer <-
	for (int i = len, j = 0; i > half; i--, j++)
		y[j] = A[j];
	int palindromo = strcmp(x, y);
	
	free(x);
	free(y);

	return palindromo;

}

int main(int argc, char const *argv[])
{
	char *A;
	
	A = (char *)malloc(2 * 5 * sizeof(char));

	printf("Ingrese palabra: ");
	scanf("%s", A);

	printf("\nBeep boop calculando...\nStats:\n\t");
	printf("\n\tPalindromo: %d\n", stats(A));

	free(A);
	return 0;
}


/*
	int main() {
		int n, x, iguales = 0, res, sizeMay = 0, sizeMen = 0;
		char s[1000];

		// Arreglos de strings lmao
		char** mayores = (char**)malloc(sizeof(char*));
		char** menores = (char**)malloc(sizeof(char*));
		// palabra y de largo x
		char* y;

		FILE* fileMayores = fopen("mayores.txt", "w");
		FILE* fileMenores = fopen("menores.txt", "w");

		scanf("%d %s", &n, s);
		printf("%d %s\n", n, s);

		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			y = (char*) malloc(sizeof(char) * (x + 1));
			scanf("%s", y);
			
			res = strcmp(y, s);

			if(res < 0) {
				menores = (char**) realloc(menores, sizeof(char*) * (sizeMen + 1));
				menores[sizeMen] = y;
				sizeMen += 1;
			} else if(res > 0) {
				mayores = (char**) realloc(mayores, sizeof(char*) * (sizeMay + 1));
				mayores[sizeMay] = y;
				sizeMay += 1;
			} else {
				iguales ++;
				free(y);
			}
		}

		for (int i = 0; i < sizeMay; ++i) {
			fprintf(fileMayores, "%s\n", mayores[i]);
		}

		for (int i = 0; i < sizeMen; ++i) {
			fprintf(fileMenores, "%s\n", menores[i]);
		}

		printf("Palabras iguales: %d\n", iguales);

		fclose(fileMayores);
		fclose(fileMenores);

		for (int i = 0; i < sizeMay; ++i) {
			free(mayores[i]);
		}

		for (int i = 0; i < sizeMen; ++i) {
			free(menores[i]);
		}

		free((void*) menores);
		free((void*) mayores);

		return 0;
	}
*/