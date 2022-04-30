#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Reverse a stack using queue
template <typename T>
class QueueReversal {
    public:
        queue<T> q;
        void ReverseUsingRecursion() {
            if (q.empty()) return; // base case - nothing to do
            T x = q.front();
            q.pop();
            ReverseUsingRecursion();
            q.push(x);
        }
};


int main() {

    QueueReversal<int> qr;

    // Initialize the queue for testing purpose
    for (int i = 10; i < 40; i += 10) {
        qr.q.push(i);
    };

    qr.ReverseUsingRecursion();

    // Printing the queue elements
    while (!qr.q.empty()) {
        cout << qr.q.front() << ' ';
        qr.q.pop();
    }
    cout << endl;
}
