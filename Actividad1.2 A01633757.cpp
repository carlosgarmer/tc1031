#include <iostream>
#include <vector>
#include<math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Imprime el vector en una linea
void imprimir(vector<int> vectorcito){

    for (int i = 0; i < vectorcito.size(); i++){
        cout << vectorcito[i] << " ";
    }
    cout << endl;
}

// Ordena un vector de tamaño n, con el método de Inserción, su complejidad optima: 0(n), media y peor: O(n2)
void ordenaIntercambio(vector<int> &ordenar){

    for(int i = 1; i<ordenar.size(); i++){
        int indiceVal= i;
        int indiceMod= i -1;
        while(indiceMod > -1 && ordenar.at(indiceMod) > ordenar.at(indiceVal) && ordenar.at(indiceMod) != ordenar.at(indiceVal) ){
            swap(ordenar[indiceMod], ordenar[indiceVal]);
            indiceVal = indiceVal - 1;
            indiceMod= indiceMod-1; 
        }
    }

}

// Ordena un vector de tamaño n, con el método de Burbuja, su complejidad optima: 0(n), media y peor: O(n2)
void ordenaBurbuja(vector<int> &ordenar){
    int cambios = 1; 
    while (cambios != 0){
        cambios = 0;
        for(int i = 0; i<ordenar.size()-1; i++){
            int indiceVal= i;
            int indiceMod= i + 1;
            if(ordenar.at(indiceMod) < ordenar.at(indiceVal)){
                swap(ordenar[indiceMod], ordenar[indiceVal]);
                cambios += 1;
            }
        }
    }   
}

// Funcion secundaria que organiza los valores por seccion
void merge(vector<int> &ordenar,int izq, int mitad,int der){
    int tamano1 = mitad - izq +1;
    int tamano2 = der - mitad;
    vector<int> Izqu;
    vector<int> Dere;
    for(int i=0; i < tamano1; i++){
        Izqu.push_back(ordenar[izq + i]);
    }
    for(int j=0; j < tamano2; j++){
        Dere.push_back(ordenar[mitad +1 + j]);
    }
    int i = 0;
    int j = 0;
    int k = izq;
    while (i < tamano1 && j < tamano2){
        if (Izqu[i] <= Dere[j]){
            ordenar[k]= Izqu[i];
            i += 1;
        } else {
            ordenar[k] = Dere[j];
            j += 1;
        }
        k += 1;
    }
    while ( i < tamano1 ){
        ordenar[k] = Izqu[i];
        i += 1;
        k += 1;
    }
    while ( j < tamano2){
        ordenar[k] = Dere[j];
        j += 1;
        k += 1;
    }
}

// Funcion principal que divide seciones del arreglo en dos
void mergeSort(vector<int> &ordenar,int izq,int der){
    if (izq < der)  {
    int mitad = floor((izq + der)/ 2) ;
    mergeSort(ordenar, izq, mitad);
    mergeSort(ordenar,mitad+1, der);
    merge(ordenar,izq, mitad, der);
    }
}

// En esta función  se llama a mergeSort() para hacer un arreglo de fusión, la complejidad es de log2(n)
void ordenaMerge(vector<int> &ordenar){
    int izq = 0;
    int der = ordenar.size() - 1;
    mergeSort(ordenar, izq, der);
}

int busqSecuencial(vector<int> &arreglo, int dato){
    int i = 0;
    while (i < arreglo.size()){
        if (arreglo.at(i) == dato){
            return i;
        }
        i ++;
    }
    return -1;
}

int busqBinaria(vector<int> &arreglo, int dato){
    ordenaMerge(arreglo);
    int start = 0;
    int last = arreglo.size() -1;
    while (start <= last ){
        int m = (start+last)/2 ;
        if (arreglo.at(m) == dato){
            return m;
        } else if (arreglo.at(m) < dato){
           start = m + 1;
        } else {
            last = m -1;
        }
    }
    return -1;
}

int main(){
    vector<int> vectorPrueba;
    int respuesta = 0;
    srand(time(NULL));   // Inicialización
    int n = 4;
    for (int i = 0; i < n; i++){
        vectorPrueba.push_back(rand()%100 +1);      // Regresa un numero aleatorio
    }

    cout << "Seleccione una de las siguentes funciones a realizarle al vector: "<<endl;
    imprimir(vectorPrueba);
    cout<< "1 Ordena Intercambio" <<endl;
    cout<< "2 Ordena Burbuja" <<endl;
    cout<< "3 Ordena Merge" <<endl;
    cout<< "4 Busca secuencial" <<endl;
    cout<< "5 Búsqueda binaria" <<endl;
    cout<< ">>";
    cin >> respuesta;

    switch (respuesta)
    {
    case 1:
        ordenaIntercambio(vectorPrueba);
        break;
    case 2:
        ordenaBurbuja(vectorPrueba);
        break;
    case 3:
        ordenaMerge(vectorPrueba);
        break;
    case 4:
        cout<< "Ingresa el número que quieres buscar >>";
        cin >> respuesta;
        cout << "Se encuentra en el índice: " << busqSecuencial(vectorPrueba, respuesta) << endl;
        break;
    case 5:
        cout<< "Ingresa el número que quieres buscar >>";
        cin >> respuesta;
        cout << "Se encuentra en el índice: " << busqBinaria(vectorPrueba, respuesta) << endl;
        break;
    default:
        break;
    }
    imprimir(vectorPrueba);
}