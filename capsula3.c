#include <stdio.h>

int arrayMax(int arr[], int n){
    int max = arr[0];

    int i = 0;

    for (i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;

}

int compareStrings(char String1[], char String2[], int len){
    for (int i = 0; i < len; i++)
    {
        if (String1[i] != String2[i])
        {
            return -1;
        }
    }
    return 1;
}

double max(double arr[], int size){
    double max = arr[0];

    int i = 0;

    for (i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

double min(double arr[], int size)
{
    double min = arr[0];

    int i = 0;

    for (i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

double mean(double arr[], int size){
    double suma = 0;

    for (int i = 0; i < size; i++)
    {
        suma += arr[i];
    }
    
    double res = suma/((double)size);

    return res;
}


double mode(double arr[], int size){
    double modaGlobal;
    int cantRepsModa = 0;

    for (int i = 0; i < size; i++)
    {
        int cantRepsIt = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cantRepsIt++;    
            }
            
        }

        if (cantRepsModa < cantRepsIt)
        {
            modaGlobal = arr[i];
            cantRepsModa = cantRepsIt;
        }        
    }
    
    return modaGlobal;
}
int main(int argc, char const *argv[])
{
    /*
        int n;
        printf("Ingrese cantidad de datos del arreglo: ");
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {   
            printf("\nIngrese elemnto %d:", i);
            scanf("%d", &arr[i]);
        }

        printf("\nEl maximo es: %d\n", arrayMax(arr, n));
        
        return 0;
    */
    /*
        char s1[] = {'d', 'a','s','a','\0'};
        char s2[] = "casa";

        printf("Iguales: %d\n", compareStrings(s1,s2,5));
    */

   double arr[] = {0.5,0.5,0.5,1.0,1.0,1.0,1.0,2.0,3.0};

   printf("Analisis:\n\tMAx: %f\n\tMin: %f\n\tMean: %f\n\tmoda: %f\n",
          max(arr, 9), min(arr, 9), mean(arr, 9), mode(arr, 9));
}



/*
    #include <stdio.h>

    double mean(double arr[], int length){
        double result = 0;

        //suma total
        for (int i = 0; i < length; i++)
            result += arr[i];
        
        //pasamos el largo del arreglo de int -> double
        result = result/((double)length);

        //retornamos variable
        return result;
    }

    double min(double arr[], int length){
        //inicializamos minimo con primera pos del arreglo
        double min = arr[0];
        for (int i = 1; i < length; i++)
            //actualizamos min
            if(arr[i] < min)
                min = arr[i];   
        return min;
    }

    double max(double arr[], int length){
        //inicializamos max con primera pos del arreglo
        double max = arr[0];
        for (int i = 1; i < length; i++)
            //actualizamos max
            if(arr[i] > max)
                max = arr[i];
        return max;
    }

    double mode(double arr[], int length){
        //variable generales
        double mode;
        int modeReps;
        // debemos recorrer el arreglo 
        // de esta forma para obtener repeticiones
        for (int i = 0; i < length; i++)
        {
            //repeticiones por vez
            int reps = 0;
            for (int j = 0; j < length; j++){
                if (arr[i]==arr[j]) {
                    reps++;
                }
            }
            //comparamos moda actual con nuevo computo
            if (modeReps < reps){
                //actualizamos datos
                mode = arr[i];
                modeReps = reps;
            }        
        }
        return mode;
    }


    int main(int argc, char const *argv[])
    {
        double arr[] = {3.14, 15.6, 165.9, 2.71, 
                        3.14, 2.71, 3.14};
        printf("Analisis exploratorio del arreglo:\n\tMaximo: %f", max(arr, 7));
        printf("\n\tminimo: %f\n\tmoda: %f\n\tMedia aritmetica: %f\n", 
                    min(arr, 7),mode(arr, 7), mean(arr, 7));
        return 0;
    }
*/