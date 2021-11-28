// Carlos Garcia Mercado A01633757
// 22 de noviembre del 2021

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable{
    public:
        vector< vector<string> > hash;
        int tamano;

        // Esta incializacion considera el valor ingreado por el usuario para determinar el numero de nodos que hay O(n)
        HashTable(int n){
            tamano =  n;
            vector<string> temporal;
            for (int i = 0; i< n; i++){
                hash.push_back(temporal);
            }
        }

        // Esta funcion regresa el valor ASCII de un string, la complejidad es de O(n)
        int convertToASCII(string letter){
            for (int i = 0; i < letter.length(); i++){
                char x = letter.at(i);
                return int(x);
            }
            return 255;
        }

        // Esta funcion obtine el indice donde guardar el valor apartir de los valores ASCII de las prinmeras palabras O(1)
        int hashFunction(string nombre){
            int indice = 0;
            string a = "", b = "", c = "";
            a = nombre[0];
            b = nombre[1];
            c = nombre[2];
            indice += convertToASCII(a) + convertToASCII(b) + convertToASCII(c); // Sumamos los valores ASCII
            return indice;
        }

        // Esta funcion inserta el valor, resolviendo colisiones con cadenas O(1)
        void insertarChain(string palabra){
            int indice = hashFunction(palabra);
            hash[indice].push_back(palabra);
        }


        // Esta funcion verifica si la palabra se encuentra dentro de la tabla O(n)
        bool existChain(string palabra){
            int indice = hashFunction(palabra);
            for (int i= 0; i < hash[indice].size(); i++){
                if(palabra == hash[indice][i]){
                return true;
                }
            }
            return false;
        }

        // Esta funcion inserta el valor, resolviendo colisiones con cuadraticamente O(n)
        void insertarQuadratic(string palabra){
            vector<string> vacio;
            int indice = hashFunction(palabra);
            if (hash[indice] == vacio){
                hash[indice].push_back(palabra);
            } else {
                for(int i =  0; i <tamano; i++){
                    int indiceTemporal = indice + i*i;
                    if (indiceTemporal > tamano){
                        cout << "El valor no pudo ser guardado" <<endl;
                        break;
                    }
                    if (hash[indiceTemporal] == vacio){
                        hash[indiceTemporal].push_back(palabra);
                        break;
                    }
                }
            }
        }

        // Esta funcion verifica si la palabra se encuentra dentro de la tabla O(n)
        bool existQuadratic(string palabra){
            vector<string> word;
            word.push_back(palabra);
            int indice = hashFunction(palabra);
            if (hash[indice] == word){
                return true;
            } else {
                for(int i =  0; i <tamano; i++){
                    int indiceTemporal = indice + i*i;
                    if (indiceTemporal > tamano){
                        return false;
                    }
                    if (hash[indiceTemporal] == word){
                        return true;
                    }
                }
                return false;
            }    
        }
};

int main() {
    HashTable chain(1000);
    HashTable quadratic(1000);
    chain.insertarChain("Carlos");
    chain.insertarChain("Alexa");
    chain.insertarChain("Juan");
    chain.insertarChain("Manuel");
    chain.insertarChain("Alejandro");
    chain.insertarChain("Alex");
    chain.insertarChain("Alexis");
    cout<< "HashTable con coliciones en cadena" <<endl;
    cout<< "Existe Alexis : "<< chain.existChain("Alexis") <<endl;
    cout<< "Existe Alex : "<< chain.existChain("Alex") <<endl;
    cout<< "Existe Sofia : "<< chain.existChain("Sofia") <<endl;
    quadratic.insertarQuadratic("Carlos");
    quadratic.insertarQuadratic("Alexa");
    quadratic.insertarQuadratic("Juan");
    quadratic.insertarQuadratic("Manuel");
    quadratic.insertarQuadratic("Alejandro");
    quadratic.insertarQuadratic("Alex");
    quadratic.insertarQuadratic("Alexis");
    cout<< "HashTable con coliciones cuadraticas" <<endl;
    cout<< "Existe Alexis : "<< quadratic.existQuadratic("Alexis") <<endl;
    cout<< "Existe Alex : "<< quadratic.existQuadratic("Alex") <<endl;
    cout<< "Existe Sofia : "<< quadratic.existQuadratic("Sofia") <<endl;
    return 0;
}  