#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>

using namespace std;

template <typename T>
class BinarySearchTree {
    public:
       struct Node {
           T item;
           unique_ptr<Node> left;
           unique_ptr<Node> right;
           Node(const T& value): item(value), left(nullptr), right(nullptr) {};
       };
       unique_ptr<Node> root;

       // This is a helper function as this calls another method with same name
       // adds root pointer as first parameter
       bool Contains(const T& key) {
           return Contains(root, key);
       }

       // Example of search BST iteratively
       // Instead of recursive call, tree is traversed iteratively
       bool Contains(unique_ptr<Node>& r, const T& key) {
           Node* n = r.get();
           while (n) {
               if (n->item == key) return true;
               if (n->item > key) {
                   n = n->left.get();
               } else if (n->item < key) {
                   n = n->right.get();
               }
           }
           return false;
  
       }

       const Node* Max() {
           Node *n = root.get();
           while (n->right) {
               n = n->right.get();
           } 
           return n;
       }

       Node* Min() {
           return Min(root);
       }
       Node* Min(unique_ptr<Node>& r) {
           Node* n = r.get();
           while (n->left) {
               n = move(n->left.get());
           } 
           return n;
       }

       void Insert(const T &key) {
           Insert(root, key);
       }
       void Insert(unique_ptr<Node> &n, const T& key) {
           if (!n) {
               n = unique_ptr<Node>(new Node(key));
           } else if (key < n->item) {
               Insert(n->left, key);
           } else if (key > n->item) {
               Insert(n->right, key);
           } else {
               cerr << "Key: " << key << " already present" << endl;
           }

       }
       void InOrderPrint() {
           InOrderPrint(root);
           cout << endl;
       }
       void InOrderPrint(unique_ptr<Node>& n) {
           if (!n) return;
           InOrderPrint(n->left);
           cout << n->item << ' ';
           InOrderPrint(n->right);
       }
       void Remove(const T& key) {
           Remove(root, key);
       }
       // Recursive removal of node
       void Remove(unique_ptr<Node>& n, const T& key) {
           if (!n) return;
           if (key < n->item) {
               Remove(n->left, key);
           } else if (key > n->item) {
               Remove(n->right, key);
           } else {
               if (n->left && n->right) {
                   n->item = Min(n->right)->item;
                   Remove(n->right, n->item);
               } else {
                   n = std::move((n->left) ? n->left : n->right);
               }
           }
       }
       /*
       void RemoveIterative(const T& key) {
           Node* n = root.get();
           Node* p = nullptr;
           while (n) {
               if (n->item == key) { 
                   if ((!n->left) && (!n->right)) {
                       if (p->left->item == key) {
                           p->left = nullptr;
                       } else {
                           p->right = nullptr;
                       }
                   } else if ((n->left) && (!n->right)) {
                       p->left = move(n->left);
                   } else if ((!n->left) && (n->right)) {
                       p->right = move(n->right);
                   } else { // Node to be deleted has left & right child
                       //p->left = move(Min(n->right));
                   }
                   return;
               }
               if (n->item > key) {
                   p = n;
                   n = n->left.get();
               } else if (n->item < key) {
                   p = n;
                   n = n->right.get();
               }
           }
           return; // key not found
       }
       */
};

int main() {
    vector<int> v = {7, 5, 20, 4, 6, 19, 25, 30, 15, 3};
    BinarySearchTree<int> bst;
    for (auto i: v) {
        bst.Insert(i);
    }
    bst.InOrderPrint();
    cout << bst.Contains(20) << ',' << bst.Contains(100) << endl;
    cout << bst.Max()->item << ',' << bst.Min()->item << endl;
    bst.Remove(5);
    bst.InOrderPrint();
}
