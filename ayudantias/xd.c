#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415926
#define MAX_CURSOS 10

typedef struct {
    char ROL[11];
    char cursos[MAX_CURSOS][8];
    int notas[MAX_CURSOS];
    long double prioridad;
}estudiante;

void writeAlumno(estudiante *e, FILE *fp){
    fwrite(e->ROL, sizeof(char), 11, fp);
    for (int i = 0; i < MAX_CURSOS; i++)
    {
        fwrite(e->cursos[i], sizeof(char), 8, fp);
    }
    for (int i = 0; i < MAX_CURSOS; i++)
    {
        fwrite(&e->notas[i], sizeof(int), 1, fp);
    }
    fwrite(&e->prioridad, sizeof(long double), 1, fp);
    
}


// Funcion que crea x numeros random y los pega en un archivo
int crearArchivo(int x)
{
    srand(time(NULL));

    FILE *p2;

    if (!(p2 = fopen("siga.dat", "wb")))
        return 1;

    estudiante *alumno = (estudiante *)malloc(sizeof(estudiante));
    
    fwrite(&x, sizeof(int), 1, p2);

    for (int i = 0; i < x; i++)
    {
        
        strcpy(alumno->cursos[0], "INF-285");
        strcpy(alumno->cursos[1], "INF-136");
        strcpy(alumno->cursos[2], "INF-134");
        strcpy(alumno->cursos[3], "INF-293");
        strcpy(alumno->cursos[4], "INF-134");
        strcpy(alumno->cursos[5], "INF-202");
        strcpy(alumno->cursos[6], "INF-278");
        strcpy(alumno->cursos[7], "INF-216");
        strcpy(alumno->cursos[8], "INF-275");
        strcpy(alumno->cursos[9], "INF-269");

        strcpy(alumno->ROL, "201773557-0");

        for (int j = 0; j < MAX_CURSOS; j++)
        {
            alumno->notas[j] = (rand() % 101 + 1);
        }

        alumno->prioridad = (rand() % 7000 + 1);

        writeAlumno(alumno, p2);
    }

    free(alumno);

    fclose(p2);
    return 0;
}

int main(int argc, char const *argv[])
{

    crearArchivo(100);

    long double cursaronEDD = 0.0;
    long double notaCien = 0.0;
    FILE *file;

    if (!(file = fopen("siga.dat", "rb")))
    {
        puts("No se pudo abrir el archivo");
        return 1;
    }

    int cantStructs;
    fread(&cantStructs, sizeof(int), 1, file);

    // definimos un placeholder para un estudinate
    estudiante *al = (estudiante*)malloc(sizeof(estudiante));

    
    // leemos datos y los almacenamos en la tabla
    for (int i = 0; i < cantStructs; i++)
    {
        fread(al->ROL, sizeof(char), 11, file);

        for (int j = 0; j < MAX_CURSOS; j++)
        {
            fread(al->cursos[j], sizeof(char), 8, file);
        }
        for (int j = 0; j < MAX_CURSOS; j++)
        {
            fread(&al->notas[j], sizeof(int), 1, file);
        }
        fread(&al->prioridad, sizeof(long double), 1, file);

        for (int j = 0; j < MAX_CURSOS; j++)
        {
            
            if (strcmp("INF-134", al->cursos[j]))
            {
                cursaronEDD++;
                
                if(al->notas[j] == 100){
                    notaCien++;
                }
                break;
            }
        
        }
    }

    //bonus: calculamos la probabilidad    
    long double prob = notaCien/cursaronEDD;
    printf("La probabilidad de aprobar el ramo es de:\t%d\n", (int)prob*100);

    free(al);
    fclose(file);
    
    return 0;
    }
