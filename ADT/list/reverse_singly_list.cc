#include <iostream>
#include <memory>
#include <stack>

// Reverses linked list in iterative and recursive way
// Iterative method uses stack to mimic the program stack
using namespace std;

template <typename T>
class ListLinked {
    private:
       struct Node {
           T item;
           Node* next; 
       };
       Node* head = nullptr;

       Node* ReverseRecursive(Node* n) {
           if (!n || (!n->next)) return n;
           // e.g. A->B->C where head -> A
           // Recursive calls will terminate when n->C
           // At that time !n->next = True so the line above returns h
           // which is pointing to "C"
           Node* h = ReverseRecursive(n->next);
           // Top of the program stack is popped so now n->B
           // Next line makes B<-C
           // This keeps on happening as stack is popped
           // Everytime "h" is returned that way becomes the new head pointer h->C
           n->next->next = n;
           n->next = nullptr;
           return h;
       }
       void ReverseIterative(Node* h) {
           stack<Node*> s;
           Node* n = h;
           if (!n || (!n->next)) return;
           Node* p;
           while (n->next) {
               s.push(n);
               n = n->next;
           }
           head = n;
           while (!s.empty()) {
               p = s.top();
               s.pop();
               n->next = p;
               p->next = nullptr;
               n = p;
           }
       }
    public:
       void InsertAtTail(T x) {
           Node* n = new Node();
           n->item = x;
           if (!head) {
               head = n;
           } else {
               Node* ptr = head;
               while (ptr->next) {
                   ptr = ptr->next;
               }
               ptr->next = n;
           }
       }
       void Print() {
           Node *ptr = head;
           while (ptr) {
               cout << ptr->item << ' ';
               ptr = ptr->next;
           }
           cout << endl;
       }
       void ReverseIterative() {
           ReverseIterative(head);
       }
       void ReverseRecursive() {
           head = ReverseRecursive(head);
       }
};

int main() {
    ListLinked<int> l;
    for (int i = 10; i < 70; i += 10) {
        l.InsertAtTail(i);
    }
    l.Print();
    l.ReverseIterative();
    l.Print();
    l.ReverseIterative();
    l.Print();
}
