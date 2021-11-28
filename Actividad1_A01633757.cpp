// Carlos Garcia Mercado A01633757
// 19 de agosto del 2021

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// En esta función se itera con for para poder sumar los valores de 1 a n
// en la variable suma, se recibe n en la funcion, y regresa la suma , la complejidad es de O(n)
int sumaIterativa(int n){
    int suma = 0;
    for(int i = 1; i< n+1; i++){
        suma += i;
    }
    return suma;
}

// En esta función se utiliza a la recursividad para llamar a la misma función para
// suma n-1 hasta llegar a 1, se recibe n, y regresa la suma, la complejidad es de O(n) <- siguendo el Teorema maestro
int sumaRecurisva(int n){
    if (n == 1){
        return 1;
    }
    return n + sumaRecurisva(n-1);
}
// En esta funcion al usar una formula, se recibe n, y regresa la suma,la complejidad es de O(1)
int sumaDirecta(int n){
    int suma = n  * (n + 1) / 2;
    return suma;
}

int main(){
    srand(time(NULL));   // Inicialización
    int n = 4;
    int num = 0;
    for (int i = 0; i < n; i++){
        num = rand()%100 +1;      // Regresa un numero aleatorio
        cout<< "Suma de 1 a "<< num << endl;
        cout<< "Suma Iterativa = "<< sumaIterativa(num) <<endl;
        cout<< "Suma Recursiva = "<< sumaRecurisva(num) <<endl;
        cout<< "Suma Directa = "<< sumaDirecta(num) <<endl;
    }
}
