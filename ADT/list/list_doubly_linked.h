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

       // Remove at position: pos
       void Remove(const unsigned int pos) {
           if (pos >= cur_size) throw out_of_range("Position out of range");
           if (pos == 0) { // List will be empty after this operation
               if (cur_size == 1) {
                   head = move(nullptr);
                   tail = nullptr;
               } else {
                   head = move(head->right);
               } 
            } else if (pos == cur_size - 1) { // Remove at the tail
                Node* n = tail->left;
                n->right = move(nullptr);
                tail = n;
            } else {
                Node* n = GetNode(pos);
                Node* p = n->left;
                p->right = move(n->right);
                //n->left->right->left = n->left; // This is incorrect
                p->right->left = p;
                
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
               n->right = move(p->right);
               n->right->left = n.get();
               n->left->right = move(n);
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