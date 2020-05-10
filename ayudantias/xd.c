#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define PI 3.1415926
// Funcion que crea x numeros random y los pega en un archivo
int crearArchivo(int x)
{
    srand(time(NULL));

    FILE *p2;
    int n;

    if (!(p2 = fopen("datos.txt", "w")))
        return 1;

    fprintf(p2, "%d\n", x);

    for (int i = 0; i < x; i++)
    {
        n = (rand() % 399 + 1); // random double ste está entreo 20 y 30
        fprintf(p2, "%d\n", n);
    }
    fclose(p2);
    return 0;
}

int main(int argc, char const *argv[])
{
    crearArchivo(400);

    FILE *file;

    if (!(file = fopen("datos.txt", "r")))
    {
        puts("No se pudo abrir el archivo");
        return 1;
    }

    int cantLineas;
    fscanf(file, "%d", &cantLineas);

    int tabla[cantLineas];

    // nos aseguramos que el arreglo sea correctamente inicializado
    for (int i = 0; i < cantLineas; i++) tabla[i] = 0;
    
    // leemos datos y los almacenamos en la tabla
    for (int i = 0; i < cantLineas; i++)
    {
        int dato;
        fscanf(file, "%d", &dato);
        tabla[dato]++;
    }

    // mostramos la tabla
    puts("La tabla de frecuencias es:");
    for (int i = 0; i < cantLineas; i++) printf("\t%d:\t%d\n", i, tabla[i]);

    fclose(file);
    return 0;
}
