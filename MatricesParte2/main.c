#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int const colm = 4;
int const colmP = 20;
void cargarMatriz(int matriz[][colm], int dimF);
void mostrarMatriz(int matriz[][colm],  int dimF);
int sumarMatriz(int matriz[][colm],  int dimF);
float promediarMatriz(int matriz[][colm],  int dimF, int suma);
int buscarDato(int matriz[][colm], int dimF);
int cargarArregloPalabras(char arreglo[][colmP], int dimF);
int buscarString(char arreglo[][colmP], int f, char buscar[]);
int buscarStringOrdenado(char arreglo[][colmP], int f, char buscar[]);

int main()
{
    int matriz[4][colm];
    cargarMatrizRandoms(matriz, 4);
    mostrarMatriz(matriz, 4);

    int suma = sumarMatriz(matriz, 4);
    printf("\nEl resultado de la suma es: %i", suma);

    float promedio = promediarMatriz(matriz, 4, suma);
    printf("\nEl promedio de la matriz es: %.1f", promedio);

    int flag = buscarDato(matriz, 4);

    if(flag)
    {
        printf("El dato si se encuentra en la matriz");
    }
    else
    {
        printf("El dato no se encuentra en la matriz");
    }

    char arregloPalabras[100];
    int f;
    f = cargarArregloPalabras(arregloPalabras, 100);
    mostrarArregloPalabras(arregloPalabras, f);

    char palabra[]= {"mateo"};

    int res = buscarStringOrdenado(arregloPalabras, f, palabra);
    if(res != -1){
        printf("La palabra se encuentra en el arreglo \n");
    }
    else{
        printf("La palabra no se encuentra en el arreglo. \n");
    }
    return 0;
}

void cargarMatriz(int matriz[][colm], int dimF)
{
    int i, j;
    for(i = 0; i<dimF; i++)
    {
        for(j = 0; j<colm; j++)
        {
            printf("Que dato desea apilar en la posicion Fila %i, Columna %i ? \n", i+1, j+1);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[][colm], int dimF)
{

    int i, j;
    for(i = 0; i<dimF; i++)
    {
        printf("\n");
        for(j = 0; j<colm; j++)
        {
            printf("| %i |", matriz[i][j]);
        }
    }
}

void cargarMatrizRandoms(int matriz[][colm], int dimF)
{
    int i, j, valorRandom;
    srand(time(NULL));
    for(i = 0; i<dimF; i++)
    {
        for(j = 0; j<colm; j++)
        {
            valorRandom = rand()%10;
            matriz[i][j] = valorRandom;
        }
    }
}

int sumarMatriz(int matriz[][colm], int dimF)
{
    int i, j, dato, suma = 0;
    for(i = 0; i<dimF; i++)
    {
        for(j = 0; j<colm; j++)
        {
            dato = matriz[i][j];
            suma = suma + dato;
        }
    }
    return suma;
}

float promediarMatriz(int matriz[][colm], int dimF, int suma)
{
    float promedio = suma/(colm*dimF);
    return promedio;
}

int buscarDato(int matriz[][colm], int dimF)
{
    int i, j, dato = 0;
    int flag = 0;

    printf("\nIngrese el dato a buscar");
    scanf("%i", &dato);
    for(i = 0; i<dimF && flag == 0; i++)
    {
        for(j = 0; j<colm && flag == 0; j++)
        {
            if(dato == matriz[i][j])
            {
                flag = 1;
            }
        }
    }

    return flag;
}

int cargarArregloPalabras(char arreglo[][colmP], int dimF)
{
    int f = 0;
    char control = 's';
    while((f<dimF) && (control == 's'))
    {
        printf("\n Ingrese una palabra para ser cargada en la matriz \n");
        fflush(stdin);
        gets(arreglo[f]);

        printf("Desea seguir cargando palabras? \n");
        fflush(stdin);
        scanf("%c", &control);
        f++;
    }
    return f;
}
void mostrarArregloPalabras(char arreglo[][colmP], int f)
{
    for(int i=0; i<f; i++)
    {
        puts(arreglo[i]);
    }
}
int buscarString(char arreglo[][colmP], int f, char buscar[])
{
    int res = -1;
    for(int i=0; i<f && res == -1; i++)
    {
        if(strcmp(arreglo[i], buscar)==0){
            res = i;
        }
    }
    return res;
}

int buscarStringOrdenado(char arreglo[][colmP], int f, char buscar[])
{
    int res = -1;
    for(int i=0; i<f && res == -1 && arreglo[i] > buscar[i]; i++)
    {
        if(strcmp(arreglo[i], buscar) == 0){
            res = i;
        }
    }
    return res;
}
