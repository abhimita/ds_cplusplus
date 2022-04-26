#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template <typename T>
class QueueUsingTwoStacks {
    private:
       stack<T> enque_stack; // stack used for enque
       stack<T> deque_stack; // stacj used for deque
    public:
       // Put the element in enque_stack
       // Complexity = O(1)
       void Push(const T& v) {
           enque_stack.push(v);
       }
       // Remove element from front of queue
       // Stacj will contain elements in reverse order
       void Pop() {
           // If both stacks are empty then queue is empty
           if (enque_stack.empty() && deque_stack.empty()) {
               cerr << "Queue is empty" << endl;
               exit(1);
           }
           // If deque_stack is empty then pop elements from enque_stack
           // Put them in deque_stack. This reverses the stack order
           if (deque_stack.empty()) {
               while (!enque_stack.empty()) {
                   T& x = enque_stack.top();
                   enque_stack.pop();
                   deque_stack.push(x);
               }
           }
           // Pop the top most element from deque stack. This is the front of the queue
           deque_stack.pop();
       }
       // Logic similar to Pop operation
       const T& Front() {
           if (enque_stack.empty() && deque_stack.empty()) {
               cerr << "Queue is empty" << endl;
               exit(1);
           }   
           if (deque_stack.empty()) {
               while (!enque_stack.empty()) {
                   T& x = enque_stack.top();
                   enque_stack.pop();
                   deque_stack.push(x);
               }
           }
           return deque_stack.top();        
       }
       // Logic similar to reverse of pop operation
       const T& Back() {
           if (enque_stack.empty() && deque_stack.empty()) {
               cerr << "Queue is empty" << endl;
               exit(1);
           } 
           if (!enque_stack.empty()) {
               return enque_stack.top();
           }  else {
               while (!deque_stack.empty()) {
                   T& x = deque_stack.top();
                   deque_stack.pop();
                   enque_stack.push(x);
               }               
           }         
       }
};


int main() {
    QueueUsingTwoStacks<int> q;
    for (int i = 1; i <= 4; i++) {
        q.Push(i);
    }
    q.Pop();
    q.Pop();
    assert(q.Front() == 3);
    q.Pop();
    assert(q.Front() == 4);
}
