#include <iostream>
#include <stack>
#include <vector>

using namespace std;


template <typename T>
stack<T> Sort(stack<T> &s) {
    stack<T> temp_stack;
    
    while (!s.empty()) {
        T x = s.top();
        s.pop();
        // check if temp stack is empty
        // elements in temp_stacj should not be lesser than the incoming element
        // This is required as we need the temp_stack to be sorted with smallest element on the top
        while (!temp_stack.empty() && temp_stack.top() < x) {
            // Pop elements from temp_stack which are less than incoming element and
            // move them back to original stack
            T y = temp_stack.top();
            temp_stack.pop();
            s.push(y);
        }
        // Now push the incoming element to temp stack 
        // At this time all elements in temp stack are in ascending order 
        // reading from top of stack towards the bottom
        temp_stack.push(x);
    } 
    return temp_stack;
}

int main() {
    stack<int> s;
    int arr[] = {34, 3, 31, 98, 92, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    stack<int> t = Sort(s);
    while (!t.empty()) {
        cout << t.top() << ' ';
        t.pop();
    }
    cout << endl;

}