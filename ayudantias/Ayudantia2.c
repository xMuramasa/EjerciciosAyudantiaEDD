#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
    file open
    * fopen(char* nombre, char* modo): abre el archivo en el modo deseado, retorna un tipo FILE*
    * fclose(FILE* nombre): cierra el archivo /// si no se hace hay tabla
    --------------------archivos de texto
    file print formatted
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
            Un numero entero N en la prinmera linea, seguido de n lineas con un double c/u.

            2
            1.3
            1.4
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

/*  
    // funciones para el problema 2
    double sumaProm(double* arr, int size){
        double ret = 0;

        for (int i = 0; i < size; i++)
        {
            ret = ret + arr[i];
        }
        return ret;
        
    }

    double prom(double suma, int size){
        return suma/(double)size;
    }

    double desvEst(double *arr, int size)
    {
        double ret = 0;
        double p = prom(sumaProm(arr,size), size);

        for (int i = 0; i < size; i++)
        {
            ret += pow(arr[i] - p, 2);
        }

        ret = sqrt(ret/(size-1));

        return ret;
    }
*/

// nombre (string < 60 caracteres), HP (int), MP(int) y Stamina(int).
typedef struct pje{
    char nombre[160];
    int hp;
    int mp;
    int stamina;
}personaje;


int main(int argc, char const *argv[])
{

    /*
        // una de las muchas soluciones al problema 2
        int x = crearArchivoProblema2(17);

        FILE *file;

        if (!(file = fopen("problema2.txt", "r")))
        {
            puts("No se pudo abrir el archivo");
            return 1;
        }
        
        int cantLineas;
        fscanf(file, "%d", &cantLineas);

        double arr[cantLineas];

        for (int i = 0; i < cantLineas; i++)
        {
            fscanf(file, "%lf", &arr[i]);
        }
        
        printf("La desviación es: %f\n", desvEst(arr, cantLineas));

        fclose(file);

    */

   FILE *personajes;

   /* 
        personaje = fopen("personajes.dat", "rb");
        if(!personaje){
            bla;
        // exactamente igual que el codigo de abajo
    }
   */
   if(!(personajes = fopen("personajes.dat", "rb"))){
       puts("No se pudo abrir el archivo");
       return 1;
   }

    personaje *juanito;

    if (!(juanito = (personaje *)malloc(sizeof(personaje))))
        return 1;
    /*
        // creamos un juanito y lo guardamos
        strcpy(juanito->nombre, "juanito");
        juanito->hp = 1;
        juanito->mp = 1;
        juanito->stamina = 1;

        fwrite(juanito, sizeof(personaje), 1, personajes);
    */

    fread(juanito, sizeof(personaje), 1, personajes);

    printf("Juanito's stats:\n\tname: %s\n\thp: %d\n\tmp: %d\n\tstamina: %d\n",
           juanito->nombre, juanito->mp,juanito->hp,juanito->stamina);

    fclose(personajes);
    // #FreeJuanito
    free(juanito);

    
    return 0;
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
    if ( !( r = (recR *)malloc(sizeof(recR)))) 
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
    //siempre
    //always close whe you are done
    fclose(f);


    // read the 10 records, also comprobar si se abre
    if ( !(f = fopen("junk", "rb")))
        return 1;


    for (i = 1; i <= 10; i++)
    {
    // se lee:
        // [estructura que se lee], [tamaño que se lee], [veces que se lee], [puntero al archivo]
        fread(r, sizeof(recR), 1, f);
        printf("%d %s\n", r->x, r->string);

    }
    //siempre
    //always free memory
    free(r);

    //always close whe you are done
    //siempre
    fclose(f);
    return 0;
}


