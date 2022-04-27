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

       // checks for a valid BST
       // wrapper function
       bool CheckBST() {
           return CheckBST(root);
       }


       bool CheckBST(unique_ptr<Node> &n) {
           // If the starting node is null then it is a degenerate BST
           if (!n) return true;
           // If left tree node value is bigger than root node value or right tree node value is less than 
           // root node value  then it is not BST
           else if ((n->right && n->right->item < n->item) || (n->left && n->left->item > n->item)) return false;
           else {
               // Repeat the above checks for left & right tree
               bool is_right_bst = true;
               bool is_left_bst = true;
               if (n->right) {
                   is_right_bst = CheckBST(n->right);
               }
               if (n->left) {
                   is_left_bst = CheckBST(n->left);
               }
               return is_right_bst && is_left_bst;
           }
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
           InOrderPrint(root.get());
           cout << endl;
       }
       void InOrderPrint(Node* n) {
           if (!n) return;
           InOrderPrint(n->left.get());
           cout << n->item << ' ';
           InOrderPrint(n->right.get());
       }

};

int main() {

    vector<int> v = {18, 12, 22, 8, 15, 21, 24};
    BinarySearchTree<int> bst;
    for (auto i: v) {
        bst.Insert(i);
    }
    bst.InOrderPrint();  

    cout << boolalpha << bst.CheckBST() << endl;

    vector<int> v1 = {5, 7, 9, 8, 12, 15, 18, 22, 25};
    BinarySearchTree<int> bst1;
    for (auto i: v1) {
        bst1.Insert(i);
    }
    //cout << bst1.root->item << ',' << bst1.root->right->item << endl;
    bst1.InOrderPrint();  
    //cout << bst1.root->item << ',' << bst1.root->right->item << endl;
    cout << boolalpha << bst1.CheckBST() << endl;

}
