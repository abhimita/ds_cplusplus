#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <list>

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

       bool FindPath(unique_ptr<Node> &r, T& v, list<T>& p) {
           if (!r) return false;
           else if (r->item == v) return true;
           else {
               p.push_back(r->item);
               if (FindPath(r->left, v, p) || FindPath(r->right, v, p)) return true;
               p.pop_back();
           }
           return false;
       }

       list<T> FindPath(T& v) {
           list<T> path;
           if (FindPath(root, v, path)) {
               path.push_back(v);
               cout << "Path from root to " << v << ": ";
               for (auto it=path.begin(); it != path.end(); it++) {
                   cout << *it << ' ';
               }
               cout << endl;
           }
           return path;
       }
       
       T LowestCommonAncestor(T x, T y) {
           list<T> path_x = FindPath(x);
           list<T> path_y = FindPath(y);
           list<T> common;

           auto it1 = path_x.begin();
           auto it2 = path_y.begin();
           int n = min(path_x.size(), path_y.size());
           while (n > 0) {
               if (*it1 == *it2) {
                   common.push_back(*it1);
                   it1++;
                   it2++;
               } else {
                   break;
               }
               n--;
           }
           return common.back();
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

    int x = 21;
    int y = 24;
    int result = bst.LowestCommonAncestor(x, y);
    cout << "Lowest common ancestor: " << result << endl;

/*
    vector<int> v1 = {5, 7, 9, 8, 12, 15, 18, 22, 25};
    BinarySearchTree<int> bst1;
    for (auto i: v1) {
        bst1.Insert(i);
    }
    //cout << bst1.root->item << ',' << bst1.root->right->item << endl;
    bst1.InOrderPrint();  
*/
}
