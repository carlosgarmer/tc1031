// Carlos García Mercado A01633757
// 25 de octubre 2021

#include <iostream>

template <class T> class Node{ 
  public: 
    T data; 
    Node<T>* left;
    Node<T>* right;
    int height;

    Node(){
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    Node(int key){
        data = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

};

template <class T> class AVLTree { 
  public: 
  Node<T> *root;
      
  AVLTree() {
    root = nullptr;
  }

  ~AVLTree() {
    delete root;
  }

// Returns the height O(1)
  int height(Node<T> *N) {
    if (N == nullptr){
      return 0;
    }
    return N->height;
  }
  
// Return the the maximum value O(1)
  int max(int a, int b) {
    if (a > b){
      return a; 
    } else {
      return b;
    }
  }

  // Balance the tree rotating to the right, O(1)
  Node<T>* rightRotate(Node<T> *y) {
    Node<T> *x = y->left;
    Node<T> *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
  }

  // Balance the tree rotating to the left, O(1)
  Node<T>* leftRotate(Node<T> *x) {
      Node<T> *y = x->right;
      Node<T> *temp = y->left;
      // Perform rotation
      y->left = x;
      x->right = temp;
      // Update heights
      x->height = max(height(x->left), height(x->right)) + 1;
      y->height = max(height(y->left), height(y->right)) + 1;
      // Return new root
      return y;
  }
  
  // Get Balance factor current node O(1)
  int balanceFactor(Node<T> *current) {
      if (current == nullptr)
          return 0;
      return height(current->left) - height(current->right);
  }

  // Inserts a new node and make sures it doesn't unbalance the tree, O(log N)
  Node<T>* insert(Node<T>* current, T key) {
      if (current == NULL)
          return(new Node<T>(key));
  
      if (key < current->data)
          current->left = insert(current->left, key);
      else if (key > current->data)
          current->right = insert(current->right, key);
      else 
          return current;

      current->height = 1 + max(height(current->left),
                          height(current->right));
  
      int balance = balanceFactor(current);

      // LeftLeft
      if (balance > 1 && key < current->left->data)
          return rightRotate(current);
  
      // RightRight
      if (balance < -1 && key > current->right->data)
          return leftRotate(current);
  
      // LeftRight 
      if (balance > 1 && key > current->left->data) {
          current->left = leftRotate(current->left);
          return rightRotate(current);
      }
  
      // RightLeft
      if (balance < -1 && key < current->right->data) {
          current->right = rightRotate(current->right);
          return leftRotate(current);
      }
  
      return current;
  }

  // Calls the insert function
  void insert(T valor) {
    root = insert(root, valor);  
  }

  // Search for the minimum node O(log N)
  Node<T>* minimumNode(Node<T>* current_node){
      while(current_node->left != NULL){
          current_node = current_node->left;
      }

      return current_node;
  }

  // Deletes a node form the tree and make sures it stays balanced O(log N)
  Node<T>* deleteNode(Node<T>* current, int key){
    if (current == NULL)
      return current;
    if (key < current->data)
      current->left = deleteNode(current->left, key);
  
    else if (key > current->data)
      current->right = deleteNode(current->right, key);

    else
    {
      if ((current->left == NULL) ||
        (current->right == NULL))
      {
        Node<T> *temp = current->left ?
          current->left :
          current->right;

        if (temp == NULL)
        {
          temp = current;
          current = NULL;
        }
        else  
          *current = *temp; 
          
        delete temp;
      }
      else
      {  
        Node<T>* temp = minimumNode(current->right);
  
        current->data = temp->data;

        current->right = deleteNode(current->right,
          temp->data);
      }
    }

    if (current == NULL)
      return current;

    current->height = 1 + max(height(current->left),
      height(current->right));
  
    int balance = balanceFactor(current);

    
    if (balance > 1 && balanceFactor(current->left) >= 0)
      return rightRotate(current);

    // LeftRight  
    if (balance > 1 && balanceFactor(current->left) < 0) {
      current->left = leftRotate(current->left);
      return rightRotate(current);
    }

    // RightRight  
    if (balance < -1 &&
      balanceFactor(current->right) <= 0)
      return leftRotate(current);

    // RightLeft  
    if (balance < -1 && balanceFactor(current->right) > 0){
      current->right = rightRotate(current->right);
      return leftRotate(current);
    }

    return current;
  }

  // Calls the delete function
  Node<T>* deleteNode(int key_delete){
    return this->deleteNode(this->root, key_delete);
  }
  
  // Print the tree inorder
  void inorder(Node<T>* nodo) {
      if(nodo != nullptr){
      if (nodo->left != nullptr) inorder(nodo->left);
      std::cout << nodo->data << " ";
      if (nodo->right != nullptr) inorder(nodo->right);
      }
  }
};


int main() {
  AVLTree<int> arbolito;

 arbolito.insert(60);
 arbolito.insert(70);
 arbolito.insert(80);
 arbolito.insert(90);  
 arbolito.insert(100);
 arbolito.insert(65);
 arbolito.insert(34);
 arbolito.inorder(arbolito.root);
 arbolito.deleteNode(90);
 std::cout<<std::endl;
 arbolito.inorder(arbolito.root);
 arbolito.deleteNode(70);
 std::cout<<std::endl;
 arbolito.inorder(arbolito.root);
 arbolito.deleteNode(65);
 std::cout<<std::endl;
 arbolito.inorder(arbolito.root);
 arbolito.deleteNode(34);
 std::cout<<std::endl;
 arbolito.inorder(arbolito.root);
}