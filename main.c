#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


//
//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.

void cargarPilaxReferencia (Pila *pilita);
Pila cargarPilaCopia (Pila pilita);
//2. Hacer una función que pase todos los elementos de una pila a otra.
void pasarPila (Pila *A, Pila *B);

//3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void pasarPilaIgualOrden (Pila *A, Pila *B);
//4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.
int eliminarMenor (Pila *A);
//5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void ordenXseleccion (Pila* A,Pila* B);
//6Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.
void insertarEnPilaOrdenada (Pila* A,int dato);
//7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)

//8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.

//9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.

//10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila: Debe retornar el número: 14675




//Ejercicios extra: Con el fin de generar una experiencia de usuario diferente a la que otorga la librería se requiere desarrollar las siguientes funciones:
//Realizar una función que cargue la pila sin utilizar la función leer.
//Realizar una función que muestre la pila sin utilizar la función mostrar.



int main()
{
    char seguir ='s';
    int caso,numMenor,numerito;

    Pila a, b, aux,menor,ordenada;

    inicpila (&a);
    inicpila(&b);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);



// inicio de bucle do

    do
    {


        printf("ingrese un numero entero del 1 al 10 para ver los distintos ejercicios\n");
        scanf("%d", &caso);
        switch(caso)
        {
        case 1:
            printf("funcion para cargar una pila por consola, tanto como el usuario desee\n");
            cargarPilaxReferencia( &a);
            mostrar (&a);
            break;

        case 2:
            printf("función que pase todos los elementos de una pila a otra. \n");
            apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);

            printf("pila 1 antes de vaciar\n");
            mostrar(&a);
            pasarPila(&a,&b);
            printf("pila 1 despues de vaciar\n");
            mostrar(&a);
            printf("pila 2 con los datos de la pila 1\n");
            mostrar(&b);


            break;
        case 3:

            apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);

            printf("función que pase todos los elementos de una pila a otra, pero conservando el orden.\n");
            printf("datos de la pila 1\n");
            mostrar(&a);
            pasarPilaIgualOrden(&a,&b);
            printf("pila 2 con los datos de la pila 1\n");
            mostrar(&b);


            break;
        case 4:
            printf(" función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila\n");

            apilar(&a,4);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,1);
            apilar(&a,5);
            apilar(&a,6);

            printf("esta es la pila 1");
            mostrar(&a);

            numMenor=eliminarMenor (&a);

            printf("numero eliminado:%d\n",numMenor);
            printf("pila 1 con el menor dato eliminado");
            mostrar(&a);



            break;
        case 5:
            printf(" función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.\n");

            apilar(&a,4);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,1);
            apilar(&a,5);
            apilar(&a,6);

            printf("pila desordenada\n");
            mostrar(&a);

            printf("nueva pila ordenada");
            ordenXseleccion(&a,&ordenada);
            mostrar(&ordenada);

            break;
        case 6:
            printf("Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.\n");
            numerito=5;
            apilar(&a,7);
            apilar(&a,6);
            apilar(&a,4);
            apilar(&a,3);
            apilar(&a,2);
            apilar(&a,1);


            insertarEnPilaOrdenada(&a,numerito);
            mostrar(&a);

            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;

        default:
            printf("error, caso inexistente\n ingrese un numero del 1 al 10:");
            scanf("%d",&caso);
        }

        printf("si desea ver otro ejercicio presione s, si quiere finalizar presione algo distinto de s:\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');

    return 0;
}


//1
void cargarPilaxReferencia (Pila *pilita)
{
    char continuar ='s';
    do
    {
        //sin & ya que trabaja la pila por puntero
        leer(pilita);
        printf("para cargar otro numero presione s \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while(continuar == 's');
}

Pila cargarPilaCopia (Pila pilita)
{
    char continuar='s';
    do
    {
        //con & porque no se trabaja con direcciones de memoria y luego retorna la pila
        leer(&pilita);
        printf("desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar=='s');

    return pilita;
}


//2
void pasarPila (Pila *A, Pila *B)
{
    //mientras pila A no este vacia se apilaran los datos en B y se desapilaran de A
    while(!pilavacia(A))
    {
        apilar(B, desapilar(A));
    }
}

//3
void pasarPilaIgualOrden (Pila *A, Pila *B)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(A))
    {
        apilar(&aux,desapilar(A));

    }
    while(!pilavacia(&aux))
    {
        apilar(B,desapilar(&aux));
    }
}

//4
int eliminarMenor(Pila *A)
{
    int menor;
    Pila aux;

    inicpila(&aux);

    menor=(desapilar(A));

    while(!pilavacia(A))
    {
        if(tope(A)< menor)
        {
            //no usar & dentro de funciones de no ser que sea una pila creada dentro de la funcion
            apilar(&aux,menor);
            menor=(desapilar(A));
        }
        else
        {
            apilar(&aux,desapilar(A));
        }

    }

    while(!pilavacia(&aux))
    {
        apilar(A,desapilar(&aux));
    }
    return menor;
}

//5
void ordenXseleccion (Pila* A,Pila* B)
{
    while(!pilavacia(A))
    {
        //no usar & adentro de las funciones
        apilar(B,eliminarMenor(A));

    }
}

//6
void insertarEnPilaOrdenada (Pila* A,int dato)
{
    Pila aux;
    inicpila(&aux);


    if(tope(A)<dato)
    {
        while((!pilavacia(A))&&(tope(A)<dato))
        {
            apilar(&aux,desapilar(A));
        }
        apilar(A,dato);
        while(!pilavacia(&aux))
        {
            apilar(A,desapilar(&aux));
        }

    }
    else
    {
        while((!pilavacia(A))&&(tope(A)>dato))
        {
            apilar(&aux,desapilar(A));
        }
        apilar(A,dato);
        while(!pilavacia(&aux))
        {
            apilar(A,desapilar(&aux));
        }

    }

}

