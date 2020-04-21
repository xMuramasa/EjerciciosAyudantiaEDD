#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.1415912

/*
    * Archivos
    * repaso arrays, strings, structs y funciones.
*/

/* Funciones interesantes para manejo de strings
    * int strlen(char* s): retorna el largo del string apuntado por s.
    * int strcmp(char* lhs, char* rhs): que compara dos strings, retornando 0 si es que son iguales.
    * char* strcpy(char* d, char* s): copia el string s en d, reemplazando su contenido.
    * char* strcat(char* d, char* s): concatena el string s en d.
    * char* strchr(char* s, char c)
*/

/* Funciones de interes para el manejo de archivos
    --------------------general
    * fopen(char* nombre, char* modo): abre el archivo en el modo deseado, retorna un tipo FILE*
    * fclose(FILE* nombre): cierra el archivo /// si no se hace hay tabla
    --------------------archivos de texto
    * fprintf(FILE* f, char* formato, [var]): escribe el archivo segun el formato con las variables en [var]
    * fscanf(FILE* f, char* formato, [var]): igual que antes pero en vez de escribir, guarda en las variables
    --------------------archivos binarios
    * fread(void *ptr, size_t size, size_t nmemb, FILE *stream): lee la estructura ptr, de tamaño size, el numero de veces n, desde un archivo stream
    * fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream): igual que antes pero lee en ved de escribir
*/

//------------------------NOTA: CREAR ARCHIVOS

/* Prolblema 1:
        a) Dado un string S compuesto por una sola palabra de largo par, crea una función que pida una palabra por pantalla,
            la escriba en un archivo, para luego leerla, y finalmente obtenga estadisticas de S. 
            Es decir, largo y si es o no, un palíndromo.

        ** opcional:
        b) Crear la funcion char* palindromo(char* s) que convierte el string s en palíndromo, y 
            AGREGUE la palabra nueva al archivo anterior
*/

/* Problema 2:

    refierase a la funcion crearArchivoProblema2().

    Crear la función desvEst, que recibe un array de dobles desde un archivo de texto 
    y computa la desviación estándar de estos.
    
    {
        la forma del archivo es
            Un numero entero N, seguido de n doubles.
    }
    
    ** Puedes usar funcinones auxiliares para esta actividad. (solo sqrt de la libreria math.h)
    ** Standard Deviation: raiz(suma((dato-prom)^2)/(n))
*/

/* Problema 3:
    Como nos gusta jugar y estudiar a la vez, hemos buscado formas de hacer un minijuego. Para ello,
    descubrimos los maravillosos structs, que nos permiten emular la creación de personajes. Entonces, decidimos
    crear el struct personaje, que será plantilla para personajes de nuestro nuevo juego, esta plantilla
    tiene como características básicas un nombre (string < 60 caracteres), HP (int), MP(int) y Stamina(int).
    
    ** tarea: Finalmente, no queremos perder tiempo y nos proponemos guardar algunos personajes en algun archivo

*/

// ---------------------------------------------------------> Tutorial Manejo de archivos
/* cualquier tipo de struct */
typedef struct rec
{
    int x;
    char string[160];
}recR;

int archivos();
int crearArchivoProblema2(int x);


int main(int argc, char const *argv[])
{
    int x = crearArchivoProblema2(17);
    return x;
}

// Funcion que crea x numeros random y los pega en un archivo
int crearArchivoProblema2(int x)
{

    FILE *p2;
    double n;

    if (!(p2 = fopen("problema2.txt", "w")))
        return 1;

    fprintf(p2, "%d\n", x);

    for (int i = 0; i < x; i++)
    {
        n = (rand() % 11 + 20) * PI; // random double ste está entreo 20 y 30
        fprintf(p2, "%f\n", n);
    }
    fclose(p2);
    return 0;
}

// llamar a la funcion archivos para ver que pasa
int archivos()
{
    // counters
    int i;

    // file
    FILE *f;

    // data struct for info saving
    recR *r;
    //check memeory, Arroyuelo da puntos :)
    if ( !( r = (recR *)malloc(sizeof(recR)) ) ) 
        return 1;

    // create the file of 10 records    
    // always test if file open
    if (!(f = fopen("junk", "wb")))
        return 1;

    for (i = 1; i <= 10; i++)
    {
        //this is where magic happens 
        // en r->string, guardamos __este string__ e i
        snprintf(r->string, 40, "holy shit this is a string %d", i);

        //guardamos el indice en x
        r->x = 2*i+5;
        
        // se escribe:
        // [estructura a escribir], [tamaño a escribir], [veces que se escribe], [puntero al archivo]
        fwrite(r, sizeof(recR), 1, f);
        printf("%d %s\t---------This is a line\n", r->x, r->string);
    }
    //always close whe you are done
    fclose(f);


    // read the 10 records, also memcheck
    if ( !(f = fopen("junk", "rb")) )
        return 1;


    for (i = 1; i <= 10; i++)
    {
    // se lee:
        // [estructura que se lee], [tamaño que se lee], [veces que se lee], [puntero al archivo]
        fread(r, sizeof(recR), 1, f);
        printf("%d %s\n", r->x, r->string);

    }
    //always free memory
    free(r);

    //always close whe you are done
    fclose(f);
    return 0;
}


