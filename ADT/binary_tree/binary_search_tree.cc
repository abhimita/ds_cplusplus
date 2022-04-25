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

       const T& Max() {
           Node *n = root.get();
           while (n->right) {
               n = n->right.get();
           } 
           return n->item;
       }

       const T& Min() {
           Node *n = root.get();
           while (n->left) {
               n = n->left.get();
           } 
           return n->item;
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
       void Remove(const T& key);
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
};

int main() {
    vector<int> v = {7, 5, 20, 4, 6, 19, 25, 30, 15, 3};
    BinarySearchTree<int> bst;
    for (auto i: v) {
        bst.Insert(i);
    }
    bst.InOrderPrint();
    cout << bst.root->item << endl;
    cout << bst.Contains(20) << ',' << bst.Contains(100) << endl;
    cout << bst.root->item << endl;
    cout << bst.Max() << ',' << bst.Min() << endl;
    cout << bst.root->item << endl;
}
