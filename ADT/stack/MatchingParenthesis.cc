#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {

    const int count = 2;
    string expressions[count] = {
        "(((2+3)*5)/6)", // balanced parentheis
        "(((2+3)*5)/6)))" // unbalanced parenthesis
    };
    vector<bool> balanced(count);

    for (int i = 0; i < count; i++) {
        string expr = expressions[i];
        stack<char> s;
        balanced[i] = true;
        for (int j = 0; j < expr.length(); j++) {
            if (expr[j] == '(') {
                s.push(expr[j]);
            } else if (expr[j] == ')') {
                if (!s.empty()) {
                    s.pop();
                } else {
                    balanced[i] = false;
                    break;
                }
            }
        }
        if (!s.empty()) {
            balanced[i] = false;
        } 
    }
    for (int i = 0; i < count; i++) {
        cout << expressions[i] << ' ' << boolalpha << balanced[i] << endl;
    }
}