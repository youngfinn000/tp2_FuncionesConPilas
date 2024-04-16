#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//

//1. Hacer una funci�n que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargarPilaxReferencia (Pila *pilita);
Pila cargarPilaCopia (Pila pilita);

//2. Hacer una funci�n que pase todos los elementos de una pila a otra.
void pasarPila (Pila *A, Pila *B);

//3. Hacer una funci�n que pase todos los elementos de una pila a otra, pero conservando el orden.
void pasarPilaIgualOrden (Pila *A, Pila *B);

//4. Hacer una funci�n que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.
int eliminarMenor (Pila *A);

//5. Hacer una funci�n que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funci�n del ejercicio 4. (Ordenamiento por selecci�n)
void ordenXseleccion (Pila* A,Pila* B);

//6Hacer una funci�n que inserta en una pila ordenada un nuevo elemento, conservando el orden de �sta.
void insertarEnPilaOrdenada (Pila* A,int dato);

//7. Hacer una funci�n que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funci�n del ejercicio 6.  (Ordenamiento por inserci�n)
void nuevaOrdenada (Pila* A);

//8. Hacer una funci�n que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.
int sumaTopePostope (Pila A);


//9. Hacer una funci�n que calcule el promedio de los elementos de una pila,
// para ello hacer tambi�n una funci�n que calcule la suma, otra para la cuenta y otra que divida.
// En total son cuatro funciones, y la funci�n que calcula el promedio invoca a las otras 3.
int elementosPila(Pila A);
int sumaElementosPila(Pila A);
float divicion(int A, int B);

float promedioPila(Pila A);

//10. Hacer una funci�n que reciba una pila con n�meros de un solo d�gito (es responsabilidad de quien usa el programa) y que transforme esos d�gitos en un n�mero decimal. Por ejemplo, la pila: Debe retornar el n�mero: 14675
int pilaADecimal (Pila* A);







//Ejercicios extra: Con el fin de generar una experiencia de usuario diferente a la que otorga la librer�a se requiere desarrollar las siguientes funciones:

//Realizar una funci�n que cargue la pila sin utilizar la funci�n leer.
//Realizar una funci�n que muestre la pila sin utilizar la funci�n mostrar.




int main()
{
    char seguir ='s';
    int caso,numMenor,numerito,i;
    float PromedioDeLaPila;

    Pila a;
    Pila b;
    Pila aux;
    Pila menor;
    Pila ordenada;
    Pila ordenadaNueva;

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);
    inicpila(&ordenadaNueva);
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
            printf("funci�n que pase todos los elementos de una pila a otra. \n");

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

            printf("funci�n que pase todos los elementos de una pila a otra, pero conservando el orden.\n");

            printf("datos de la pila 1\n");

            mostrar(&a);

            pasarPilaIgualOrden(&a,&b);

            printf("pila 2 con los datos de la pila 1\n");

            mostrar(&b);
            break;
        case 4:
            printf(" funci�n que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila\n");

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

            printf(" funci�n que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.\n");



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

            printf("Hacer una funci�n que inserta en una pila ordenada de menor a mayor un nuevo elemento, conservando el orden de �sta.\n");

            numerito=5;

            apilar(&a,1);

            apilar(&a,2);

            apilar(&a,3);

            apilar(&a,4);

            apilar(&a,6);

            apilar(&a,7);





            insertarEnPilaOrdenada(&a,numerito);

            mostrar(&a);



            break;

        case 7:

            printf("Hacer una funci�n que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.\n");

            apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,4);
            apilar(&a,5);
            apilar(&a,6);
            apilar(&a,7);

            mostrar(&a);

            nuevaOrdenada(&a);

            mostrar(&a);
            break;
        case 8:
            printf("funci�n que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila");
            apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,4);
            apilar(&a,5);
            apilar(&a,6);
            apilar(&a,7);

            mostrar(&a);
            numerito=sumaTopePostope(a);
            mostrar(&a);
            printf("la suma de los dos ultimos numeros de la pila ingresada es:%d\n",numerito);

            break;
        case 9:
            printf("calculo promedio pila\n");

            apilar(&a,7);
            apilar(&a,7);
            apilar(&a,9);

            PromedioDeLaPila = promedioPila(a);
            mostrar(&a);
            printf("el promedio de la pila es :%.2f\n",PromedioDeLaPila);
            break;
        case 10:
            printf("pila a numero decimal.\n");
            apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,4);
                apilar(&a,1);
            apilar(&a,2);
            apilar(&a,3);
            apilar(&a,4);

            // pasarPila(&a,&b);

            // mostrar(&b);
            numerito= pilaADecimal(&a);
            printf("la pila pasada a numero decimal es: %i.",numerito);

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
//7
void nuevaOrdenada (Pila* A)
{
    Pila nuevapilaordenada;
    inicpila(&nuevapilaordenada);

    while(!pilavacia(A))
    {
        insertarEnPilaOrdenada(&nuevapilaordenada,desapilar (A));
    }
    while(!pilavacia(&nuevapilaordenada))
    {
        apilar(A,desapilar(&nuevapilaordenada));
    }
}
//8
int sumaTopePostope (Pila A)
{
    int topedepila=desapilar(&A);
    int postopeDePila = desapilar(&A);

    int ressultado=topedepila+postopeDePila;
    return ressultado;
}
//9
int elementosPila(Pila A)
{
    int i=0;

    while(!pilavacia(&A))
    {
        i++;
        desapilar(&A);
    }

    return i;
}

int sumaElementosPila(Pila A)
{
    int total =0;
    while(!pilavacia(&A))
    {
        total+=desapilar(&A);
    }

    return total;
}
float divicion(int A, int B)
{
    float resultadoDiv;

    resultadoDiv= (float)A/B;

    return resultadoDiv;

}

float promedioPila(Pila A)
{
    float total;

    total= divicion(sumaElementosPila( A),elementosPila(A));



    return total;
}
//10
int pilaADecimal (Pila* A)
{
    int numDecimal;
    int exponencial=1;
    int i=0;


    numDecimal=desapilar(A);

    while(!pilavacia(A))
    {
        exponencial*=10;
        numDecimal+=desapilar(A)*exponencial;
    }

    return numDecimal;
}
