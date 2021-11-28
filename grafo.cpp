// Carlos Garcia Mercado A01633757
// 19 de noviembre del 2021

#include <vector>
#include <iostream>

using namespace std;

// Esta clase describe un grafo como una lista de adyadencia donde cada indice
// del vector principal indica el nodo y el vector interior indica los nodos con los
// que tiene conexión
class Grafo{
    public:
        vector< vector<int> > listaAdyacencia;
        int tamano;
        
        // Esta incializacion considera el valor ingreado por el usuario para determinar el numero de nodos que hay O(n)
        Grafo(int n){
            tamano =  n;
            vector<int> temporal;
            for (int i = 0; i< n; i++){
                listaAdyacencia.push_back(temporal);
            }
        }
        // Se inserta una adyacencia en el vector corresponciente al nodo O(1)
        void insertarAdyacencia(int n, int nodo){
            if (n > -1 && n < listaAdyacencia.size())
                listaAdyacencia[n].push_back(nodo);
        }

        // Imprime la lista de adyacencia O(n)
        void print(){
            for (int i = 0; i < listaAdyacencia.size();i++){
                cout << i << " :";
                if (listaAdyacencia[i].size() > 0){
                    for(int j = 0; j < listaAdyacencia[i].size();j++){
                        cout << listaAdyacencia[i][j] << ",";
                    }
                }
                cout<<endl;
            }
        }

        // Funcion auxiliar para determinar si la funcion es un arbol, determina atraves de un recurrido si hay un ciclo O(n)
        bool hayCiclo(int j, vector< bool > visitados, vector < bool > recursivo){
            if (visitados[j] ==false){
                visitados[j] = true;
                recursivo[j] = true;
                
                if (listaAdyacencia[j].size()> 0){
                    for (int nodo =  *listaAdyacencia[j].begin(); nodo == *listaAdyacencia[j].end(); ++nodo){
                        if (!visitados[nodo] && hayCiclo(nodo,visitados, recursivo)){
                            return true;
                        } else if(recursivo[nodo]){
                            return true;
                        }
                    }
                } else {
                    return true;
                }
            }

            recursivo[j] = false;
            return false;
        }

        // Determina si un grafo como lista de Adyacencia es un arbol, ya que se llama la funcion axiliar hayCiclo() la complejidad es de O(n^2)
        bool isTree(){
            vector <bool> visitados(tamano,false);
            vector <bool> recursivo(tamano,false);

            for(int i = 0;i < tamano; i++){
                if (hayCiclo(i, visitados, recursivo)){
                    return true;
                }
            }

            return false;
        }
};

int main(){
    Grafo arbol(2);
    Grafo tree(5);
    Grafo cycle(2);
    Grafo ciclo(5);
    arbol.insertarAdyacencia(1,0);
    arbol.print();
    cout << "Es un arbol : " << arbol.isTree()<< endl;
    tree.insertarAdyacencia(0,2);
    tree.insertarAdyacencia(1,2);
    tree.insertarAdyacencia(3,1);
    tree.insertarAdyacencia(4,0);
    tree.print();
    cout << "Es un arbol : " << tree.isTree()<< endl;
    cycle.insertarAdyacencia(1,0);
    cycle.insertarAdyacencia(0,1);
    cycle.print();
    cout << "Es un arbol : " << cycle.isTree()<< endl;
    ciclo.insertarAdyacencia(0,1);
    ciclo.insertarAdyacencia(0,2);
    ciclo.insertarAdyacencia(1,2);
    ciclo.insertarAdyacencia(1,0);
    ciclo.insertarAdyacencia(2,3);
    ciclo.insertarAdyacencia(3,4);
    ciclo.insertarAdyacencia(4,0);
    ciclo.print();
    cout << "Es un arbol : " << ciclo.isTree()<< endl;
    return 0;
}