#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tElem{
    int val;
    char name[50];
}tElemList;

typedef struct tNode{
    tElemList data;
    tNode* next;
}tNode;

typedef struct tList{
    unsigned int maxSize;  // tamaño máximo de la lista
    unsigned int listSize; // tamaño actual de la lista
    unsigned int curr;     // posición actual de la lista
    tNode *List; // arreglo con los elementos de la lista
}tList;

// Tarea pa la casa
tList *builder()
{
    tList *list;
    return list;
}

// Tarea pa la casa
void destroyer(tList* l)
{
    free(l);
}

// Tarea pa la casa
int append(tElemList data, tList *l)
{
    return 0;
}

// Start Pregunta 2
void update(tList *L, int pos, tElemList value)
{
    moveToStart(L);
    for (int i = 0; i < pos; i++)
        next(L);
    L->List->data = value;
}

void swap(tList *L, int i, int j)
{
    tElemList tmp_i;
    tElemList tmp_j;

    // buscamos los datos para pos i
    moveToStart(L);
    for (int pos = 0; pos < i; pos++)
        next(L);
    tmp_i = L->List->data;

    // para j
    moveToStart(L);
    for (int pos = 0; pos < j; pos++)
        next(L);
    tmp_j = L->List->data;

    // update list
    update(L, i, tmp_j);
    update(L, j, tmp_i);
}
// End Pregunta 2


// Tarea pa la casa
int getVal(tList* L)
{
    return 1;
}

// Start Pregunta 3
char* getRol(tList* L)
{
    return "xd";
}


char* findMax(tList *L)
{
    char *rol = (char*)malloc(sizeof(char)*20);
    int maxi = -150;
    int size = getSize(L);

    moveToStart(L);
    for (int i = 0; i < size; i++)
    {
        if(maxi < getVal(L)){
            strcpy(rol, getRol(L));
            maxi = getVal(L);
        }
        next(L);
    }
    return rol;
}
// End Pregunta 3

int main(int argc, char const *argv[])
{
    /* code */
    // Start Ejercicio 1
    tList *MetroSA = builder();

    if (!MetroSA)
        exit(-1);

    tElemList dat;

    strcpy(dat.name, "Vickunia Mackena");
    if(append(dat, MetroSA))
        printf("Added something to List\n");

    strcpy(dat.name, "Santa Julia");
    if (append(dat, MetroSA))
        printf("Added something to List\n");

    destroyer(MetroSA);
    // END Ejercicio 1
    
    return 0;
}
