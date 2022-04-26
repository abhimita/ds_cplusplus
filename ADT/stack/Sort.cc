#include <iostream>
#include <stack>
#include <vector>

using namespace std;


template <typename T>
stack<T> Sort(stack<T> &s) {
    stack<T> temp_stack;
    
    while (!s.empty()) {
        T& x = s.top();
        cout << "Popped " << x << " from stack" << endl;
        s.pop();
        while (!temp_stack.empty() && temp_stack.top() < x) {
            T& y = temp_stack.top();
            cout << "L:Popped " << y << " from temp_stack" << endl;
            temp_stack.pop();
            s.push(y);
            cout << "L:Pushed " << y << " into stack" << endl;
        }
        cout << "Pushed " << x << " into temp_stack" << endl;
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