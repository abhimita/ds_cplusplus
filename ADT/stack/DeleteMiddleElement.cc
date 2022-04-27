#include <iostream>
#include <stack>

using namespace std;


template <typename T>
unsigned int DeleteMiddleElementNonRecursive(stack<T>& s) {
    stack<T> temp;
    int depth = 0; // counts number of elements in stack
    if (s.empty()) {
        cerr << "Stack is empty" << endl;
        exit(1);
    }
    while (!s.empty()) {
        T x = s.top();
        s.pop();
        depth++;
        temp.push(x);
    }
    int n = 0;
    int mid_element;
    while (!temp.empty()) {
        T x = temp.top();
        if (n == depth / 2) {
            n++;
            mid_element = x;
            continue;
        }
        n++;
        temp.pop();
        s.push(x);

    }
    return mid_element;
}

template <typename T>
unsigned int DeleteMiddleElementRecursive(stack<T>& s, int depth, int* n) {
    if (s.empty()) { // we have popped everything
        *n = depth; 
        return 0;
    }
    T v = s.top();
    s.pop();
    int ret = DeleteMiddleElementRecursive(s, depth + 1, n);
    if (depth == *n / 2) {
        return v;
    } 
    return ret;
}

template <int> unsigned int DeleteMiddleElementNonRecursive(stack<int>&);
template <int> unsigned int DeleteMiddleElementRecursive(stack<int>&, int, int*);

template <typename T>
unsigned int DeleteMiddleElement(stack<T>& s) {
    if (s.empty()) {
        cerr << "Stack is empty" << endl;
        exit(1);        
    }
    int depth = 0;
    int n = 0;
    return DeleteMiddleElementRecursive(s, depth, &n);
}

template <int> unsigned int DeleteMiddleElement(stack<int>&);

void TestDeleteMiddleElementNonRecursive() {
    stack<int> s;
    int arr[] = {34, 3, 31, 98, 92, 23, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    int x = DeleteMiddleElementNonRecursive(s);
    cout << x << endl;     
}
void TestDeleteMiddleElement() {
    stack<int> s;
    int arr[] = {34, 3, 31, 98, 92, 23, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }
    int x = DeleteMiddleElement(s);
    cout << x << endl;     
}

int main() {
    TestDeleteMiddleElementNonRecursive();
    TestDeleteMiddleElement();
}