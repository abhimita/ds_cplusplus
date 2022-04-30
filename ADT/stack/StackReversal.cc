#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Reverse a stack using queue
template <typename T>
class StackReversal {
    public:
        stack<T> s;
        void ReverseUsingQueue() {
            while (!s.empty()) {
                T x = s.top();
                q.push(x);
                s.pop();
            }
            while (!q.empty()) {
                T x = q.front();
                s.push(x);
                q.pop();
            }
        }
        void ReverseUsingRecursion() {
            if (s.empty()) return; // base case - nothing to do
            T x = s.top();
            s.pop();
            ReverseUsingRecursion();
            InsertAtBottom(x);
        }

    private:
        queue<T> q;
        void InsertAtBottom(T x) {
            if (s.empty()) {
                s.push(x);
            } else {
                T y = s.top();
                s.pop();
                InsertAtBottom(x);
                s.push(y);
            }
        }
};


int main() {

    StackReversal<int> rsq;

    // Initialize the stack for testing purpose
    for (int i = 10; i < 100; i += 10) {
        rsq.s.push(i);
    };

    rsq.ReverseUsingQueue();

    // Printing the stack elements
    while (!rsq.s.empty()) {
        cout << rsq.s.top() << ' ';
        rsq.s.pop();
    }
    cout << endl;

    // Initialize again to test reversal of stack using recursion
    for (int i = 10; i < 100; i += 10) {
        rsq.s.push(i);
    };

    rsq.ReverseUsingRecursion();

    while (!rsq.s.empty()) {
        cout << rsq.s.top() << ' ';
        rsq.s.pop();
    }
    cout << endl;
}