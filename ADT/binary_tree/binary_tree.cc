#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
class BinaryTree {
    public:
       struct Node {
           T item;
           unique_ptr<Node> left;
           unique_ptr<Node> right;
           Node(const T& value, unique_ptr<Node> l=nullptr, unique_ptr<Node> r=nullptr): item(value), left(move(l)), right(move(r)) {};
       };
       BinaryTree(unique_ptr<Node> r): root(move(r)) {};
       unique_ptr<Node> root;

       void PreorderTraversalRecursive(Node* n) {
           if (!n) return;
           PreorderTraversalRecursive(n->left.get());
           PreorderTraversalRecursive(n->right.get());
           cout << n->item << ' ';
       }      

       void PostorderTraversalRecursive(Node* n) {
           if (!n) return;
           cout << n->item << ' ';
           PostorderTraversalRecursive(n->left.get());
           PostorderTraversalRecursive(n->right.get());
       }
       void InorderTraversalRecursive(Node* n) {
           if (!n) return;
           InorderTraversalRecursive(n->left.get());
           cout << n->item << ' ';
           InorderTraversalRecursive(n->right.get());
       }

       int GetHeight() {
           return GetHeightRecursive(root.get());
       }
       int GetHeightRecursive(Node* n) {
           if (!n) return 0;
           return 1 + max(GetHeightRecursive(n->left.get()), GetHeightRecursive(n->right.get()));
       }

       // Iterative version of inorder traversal
       void InorderTraversalIterative() {
           stack<Node*> s;
           Node* n = root.get();
           while (true) {
               if (n) {
                   s.push(n);
                   n = n->left.get();
               } else if (s.size() > 0) {
                   n = s.top();
                   s.pop();
                   cout << n->item << ' ';
                   n = n->right.get();
               } else {
                   break;
               }
           }
       }
       // Given a level it will print all siblings at that level
       void LevelRecursive(Node* n, int level) {
           if (level == 1) {
               if (n) cout << n->item << ' ';
           } else {
               LevelRecursive(n->left.get(), level - 1);
               LevelRecursive(n->right.get(), level - 1);
           }
       }
       // Iterate through all levels
       void LevelOrderUsingRecursion(Node* r, int levels) {
           for (int l = 1; l <= levels; l++) {
               LevelRecursive(r, l);
           }
       }
       // This is same as Breadth First Search of the tree
       void LevelOrderUsingQueue(Node* r) {
           queue<Node*> q;
           q.push(r);
           while (q.size() > 0) {
               Node* n = q.front();
               q.pop();
               cout << n->item<< ' ';
               if (n->left.get()) q.push(n->left.get());
               if (n->right.get()) q.push(n->right.get());
           }
           cout << endl;
       }

       void ListLeavesFromLeftToRight(Node* n) {
           if ((!n->left.get()) && (!n->right.get())) {
               cout << n->item << ' ';
           } else {
               if (n->left.get()) ListLeavesFromLeftToRight(n->left.get());
               if (n->right.get()) ListLeavesFromLeftToRight(n->right.get());
           }
       }
       bool FindPathRecursive(Node *r, T value, vector<Node*>& p) {
           if (!r) return false;
           if (r->item == value) {
               return true;
           } 
           p.push_back(r);
           if ((FindPathRecursive(r->left.get(), value, p)) || (FindPathRecursive(r->right.get(), value, p))) {
               return true;
           }
           p.pop_back();
           return false;
       }
       void FindPath(Node* r, T value) {
           vector<Node*> v;
           if (FindPathRecursive(r, value, v)) {
               for (int i = 0; i < v.size(); i++) {
                   cout << v[i]->item << ' ';
               }
               cout << value << endl;
           }
       }
};

using TreeNode = BinaryTree<char>::Node;

int main() {
    auto nj = unique_ptr<TreeNode>(new TreeNode('j'));
    auto ni = unique_ptr<TreeNode>(new TreeNode('i'));
    auto nh = unique_ptr<TreeNode>(new TreeNode('h'));
    auto ng = unique_ptr<TreeNode>(new TreeNode('g')); 
    // move is used because two unique_ptr can't point to same location
    auto nf = unique_ptr<TreeNode>(new TreeNode('f', move(nj)));
    auto ne = unique_ptr<TreeNode>(new TreeNode('e'));
    auto nd = unique_ptr<TreeNode>(new TreeNode('d', move(nh), move(ni)));
    auto nc = unique_ptr<TreeNode>(new TreeNode('c', move(nf), move(ng)));
    auto nb = unique_ptr<TreeNode>(new TreeNode('b', move(nd), move(ne)));
    auto na = unique_ptr<TreeNode>(new TreeNode('a', move(nb), move(nc)));
    BinaryTree<char> binary_tree(move(na));

    cout << "Preorder traversal recursive: ";
    binary_tree.PreorderTraversalRecursive(binary_tree.root.get());
    cout << endl;
    cout << "Postorder traversal recursive: ";
    binary_tree.PostorderTraversalRecursive(binary_tree.root.get());
    cout << endl;
    cout << "Inorder traversal recursive: ";
    binary_tree.InorderTraversalRecursive(binary_tree.root.get());
    cout << endl;
    cout << "Inorder traversal iterative: ";
    binary_tree.InorderTraversalIterative();
    cout << endl;
    cout << "Level order traversal (Recursion): ";
    binary_tree.LevelOrderUsingRecursion(binary_tree.root.get(),4);
    cout << endl;
    cout << "Level order traversal (Queue): ";
    binary_tree.LevelOrderUsingQueue(binary_tree.root.get());
    cout << endl;
    cout << "List leaves from left to right: ";
    binary_tree.ListLeavesFromLeftToRight(binary_tree.root.get());
    cout << endl;

    cout << "Find path from root to the node: ";
    binary_tree.FindPath(binary_tree.root.get(), 'f');
    cout << endl;

    cout << "Get tree height: " << binary_tree.GetHeight() << endl;
}
