// LEARN GITHUB

#include <stdio.h>
//#include <math.h>

// Notas rapidas

// Descomentar las secciones que se quiera probar

// Para compilar un programa en C:
/*
    gcc -o nombreArchivoSalida nombrePrograma.c
*/

// Para ejecutar en linux
/*
    ./nombreArchivoSalida
*/


// Main function such wao
int main(int argc, char const *argv[])
{
    /* Your c code goes here */

// *-----------------------------------------> Calentamiento previo
// Problema 0.1
    /*
        Realice un programa que reciba por pantalla el año de nacimiento 
        de alguien y muestre en pantalla su edad.

        int fecha;
        int fechaActual = 2020;

        printf("Ingrese fecha de nacimiento: ");
        scanf("%d", &fecha);

        int edad = fechaActual - fecha;
        printf("La fecha es %d\n", edad);
    */

// Problema 0.2
    /*
        Realice un programa que reciba 3 años de nacimiento y muestre en pantalla:
        - Las 3 edades
        - La suma de las 3 edades
        - El promedio de los 3 años de nacimiento

        // fechas de nacimiento
        int fecha1;
        int fecha2;
        int fecha3;

        int fechaActual = 2020;    

        printf("ingrese las fechas de nacimiento: ");
        scanf("%d %d %d", &fecha1, &fecha2, &fecha3);

        int edad1 =  fechaActual - fecha1;
        int edad2 =  fechaActual - fecha2;
        int edad3 =  fechaActual - fecha3;
        int sumaEdades = edad1 + edad2 + edad3;

        int promedio = sumaEdades/3;

        printf("Las edades: \n\t(1)%d, \n\t(2)%d, \n\t(3)%d\n", edad1, edad2, edad3);
        printf("La suma de las edades es: %d\n", sumaEdades);
        printf("El promedio de las edades es: %d\n", promedio);
    */

// *-----------------------------------------> Fin Calentamiento previo

//  Problema 1
    /* 
        Dado que nos gusta la geometría... 
        Escribir un programa que reciba dos catetos de un tríangulo (floats) 
        y calcule el valor de la hipotenusa. 
        Nota: no se aceptan largos inválidos y su programa debe avisar.

            Ingrese catetos: 0.0 20.0 
            Hipotenusa: Imposible de calcular.

            Ingrese catetos: 10.3 203.0
            Hipotenusa: 203.261137456

            Ingrese catetos: 10.3 203.0
            Hipotenusa: Imposible de calcular.

        
        // descomentar la linea con el math.h
        // PD: no digan que yo les enseñe esto

        float cateto1, cateto2;
        float hipotenusa;

        printf("Ingrese catetos:\n\tIngrese cateto 1: ");
        scanf("%f", &cateto1);

        printf("\n\tIngrese cateto 2: ");
        scanf("%f", &cateto2);


        int flag = 1;

        if (cateto1 <= 0 || cateto2 <= 0){
            flag = 0;
        }

        if(flag){

            float p1 = pow(cateto1, 2.0);
            float p2 = pow(cateto2, 2.0);
            float suma = p1 + p2;

            // sqrt(pow(cateto1,2) + pow(cateto2,2));
            printf("hipotenusa: %f\n", sqrt(suma));
        }

        else    
            printf("Hipotenusa: No es posible de calcular\n");
    */

// Problema 2
    /*   
        Leer 3 números de punto flotante. Luego, imprimir las raíces usando 
        la formula para ecuaciones cuadráticas(Bhaskara) ax^2 + bx + c.
        Nota: Si es imposible calcular las raíces, imprimir “Imposible de calcular”.

            Ingrese a: 0.0 \\
            Hipotenusa: Imposible de calcular.
            \vspace{5}

            Ingrese b: 10.3 \\
            Hipotenusa: 203.261137456

            Ingrese c: 10.3 \\
            Hipotenusa: Imposible de calcular.
    
            
        float a, b, c;

        printf("Ingrese a, b, c: ");
        scanf("%f %f %f", &a, &b, &c);

        float discriminante = pow(b,2) - 4*a*c;
                            // condicion and
        if(discriminante >= 0 && a != 0){
            
            float root1 = (-b + sqrt(discriminante)) / (2 * a);
            float root2 = (-b - sqrt(discriminante)) / (2 * a);

            printf("\nLas raices del polinomio son:\n\t%f\n\t%f\n", root1, root2);
        }
        else
            puts("No es posible calcular");

            //printf("No es posible calcular\n");

    */

// Problema 3
    /*
        Realice un programa que reciba coordenadas X e Y y determina en que cuadrante pertenece el punto (X,Y).
        Si el punto está en algún eje, escribir Eje Y/Eje X. Si el punto está en el origen, imprimir “Origen".

        Input: 4.5 -2.2
        Output: Cuadrante 4
        
        Input: 0.0 1.5
        Output: Eje Y
    */

    return 0;
}


// Learn GITHUB
