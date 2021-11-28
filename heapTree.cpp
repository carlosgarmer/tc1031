// Carlos García Mercado A01633757
// Viernes 22 de octubre 
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class priority_queue{
    public: 
    
    vector<int> heapTree;

    // Returns the first key on the tree, O(1)
    int top(){
        if(!heapTree.empty()){
            return heapTree[0];
        } else {
        return -1;
        }
    }

    // Returns the size of the tree, 0(1)
    bool empty() {
        return !(heapTree.size() > 0);
    }

    // Returns the size of the tree, 0(1)
    int size(){
        return heapTree.size();
    }

    // Navegates the heap tree to acomodate the condition that is less than it's parent, starts form the inserted node, O(log(n))
    void navegar(vector<int> &heapTree,int data) {
        int index = heapTree.size() - 1;
        bool isMin = false;
        while (index != 0 && isMin == false) {
            if (heapTree[index] < heapTree[int(floor(index / 2))]) {
                isMin = true; //El nuevo nodo insertado es menor al padre
            }
            else { //El padre es menor que el hijo
            //Intercambiamos el padre por el hijo
                swap(heapTree[index], heapTree[int(floor(index / 2))]);
                index = floor(index / 2); //Avanzamos al siguiente nodo padre
            }
        }

    }

    // Navegates the heap tree to acomodate the condition that is less than it's parent, starts form the top, O(log(n))
    void navegarInverso(vector<int> &heapTree) {
        int index = 0;
        bool isMax = false;
        while (index < heapTree.size() && isMax == false) {
            if (heapTree[index] > max(heapTree[2*index],heapTree[2*index+1])) {
                isMax = true; //El hijo más grande es menor que el padre
            }
            else { //El padre es menor que el hijo
            //Intercambiamos el padre por el hijo
                if (heapTree[index] < heapTree[2*index] && heapTree[2*index] > heapTree[2*index+1] ) {
                swap(heapTree[index], heapTree[2*index]);
                index = 2 * index; 
                } else {
                swap(heapTree[index], heapTree[2*index+1]);
                index = 2* index +1;
                }
            }
        }

    }

    // Inserts the node in the heap tree, O(1) (when navegated O(log(N)))
    void insert(int data) {
        if (heapTree.empty()) {
            heapTree.push_back(data);
        }
        else {
            heapTree.push_back(data);
            navegar(heapTree,data);
        }
    }

    // Prints the heap tree O(n)
    void imprimir() {
        for (int i = 0; i < heapTree.size(); i++) {
            cout << heapTree[i] << ',';
        } 
        cout << endl;
    }

    // Deletes and returns the top key, and the navegates the tree to make sure it follows heap guides, O(1) (when navegated O(log(N)))
    int pop(){
        int top;
        top = heapTree[0];
        if (heapTree.size() == 1){
            heapTree.clear();
        } else {
            heapTree[0] = 0;
            heapTree[0] = heapTree[heapTree.size()];
            heapTree.pop_back();
            navegarInverso(heapTree);
        }
        return top;
    }

};

int main() {
    priority_queue arbolito;

    arbolito.insert(20);
    arbolito.insert(43);
    arbolito.insert(112);
    arbolito.insert(76);
    arbolito.insert(84);
    arbolito.insert(7);
    arbolito.imprimir();
    cout << arbolito.pop() <<endl;
    arbolito.imprimir();
    cout << arbolito.top() <<endl;
    arbolito.insert(2);
    arbolito.insert(1);
    arbolito.insert(43);
    arbolito.insert(56);
    arbolito.imprimir();
    cout << arbolito.pop() <<endl;
    arbolito.imprimir();

    return 0;
}