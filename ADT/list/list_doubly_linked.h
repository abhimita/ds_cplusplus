#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class ListDoublyLinked {
    private:
       struct Node {
           T item;
           Node* left; // we can't have both unique pointers
           unique_ptr<Node> right; // extra data member - bothway pointers
       };
       size_t cur_size = 0;
       unique_ptr<Node> head;
       Node* tail= nullptr; // rear pointer to facilitate back insertion/deletion
       Node* GetNode(size_t pos) {
           assert(pos < cur_size);
           Node* n = head.get(); // get the raw pointer
           while (pos > 0) {
               pos--;
               n = n->right.get();
           }
           return n;
       }
    public:
       ListDoublyLinked() = default;
       ~ListDoublyLinked() = default;
       unsigned int Size() {
           return cur_size;
       }
       const T& Get(const unsigned int pos) {
           if (pos >= cur_size) {
               throw out_of_range("Position out of range");
           }
           return GetNode(pos)->item;
       }
       int Find(const T& item) {
           Node* n = head.get();
           int i = 0;
           while (n) {
               if (n->item == item) return i;
               i++;
               n = n->right.get();
           }
           return -1;
       }
       void Remove(const unsigned int pos) {
           if (pos > cur_size) throw out_of_range("Position out of range");
           if (pos == 0) {
               if (cur_size == 1) {
                   head = move(nullptr);
                   tail = nullptr;
               } else {
                   head = move(head->right);
               } 
            } else if (pos == cur_size) {
                Node* n = tail->left;
                n->right = move(nullptr);
                tail = n;
            } else {
                cout << "here" << endl;
                Node* n = GetNode(pos);
                n->right = move(n->right->right);
                n->right->left = n;
            }
            cur_size--;
       }
       void Insert(const T& item, const unsigned int pos) {
           if (pos > cur_size) throw out_of_range("Position out of range");
           auto n = unique_ptr<Node>(new Node);
           n->item = item;
           if (pos == 0) {
               if (head) {
                   n->right = move(head);
                   n->right->left = n.get();
                   head = move(n);
               } else {
                   head = move(n);
                   tail = head.get();
                   head->left = nullptr;
               }
           } else if (pos == cur_size) {
               n->left = tail;
               n->left->right = move(n);
               tail = tail->right.get();
           } else {
               auto p = GetNode(pos);
               n->left = p;
               p->right = move(n);
               n->right = move(p->right);
           }
           cur_size++;
           if (cur_size == 1) tail = head.get();
       }
};

/*
int main() {
    ListDoublyLinked<int> l;
    for (int i = 10; i < 50; i += 10) {
        cout << "Insert " << i << " at position: " << (i / 10 - 1) << endl;
        l.Insert(i, i / 10 - 1);
    }
}*/