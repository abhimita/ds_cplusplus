#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

string convert_infix_to_postfix(string& infix_str) {
    stack<char> s;
    string postfix_str;

    // '(' has least priority
    map<char,int> m = {
        {'*', 3}, 
        {'/', 3}, 
        {'^', 4}, 
        {'/', 3},
        {'(', -1}, 
        {')', -1}, 
        {'+', 2}, 
        {'-', 2}};

    for (string::iterator it = infix_str.begin(); it != infix_str.end(); ++it) {
        // verify whether the incoming character is an operator
        if (m.find(*it) != m.end()) {
            if (*it == '(') {
                s.push(*it) ;
            } else {
                char c;
                while(!s.empty()) {
                    c = s.top();
                    if (*it == ')') { // for closing parenthesis pop everything till open paren is found
                        s.pop();
                        if (c == '(') {
                            break;
                        } else {
                            postfix_str.append(1, c);
                        }
                    } else { // otherwise pop operators having larger precedence than incoming operator
                        // maintain left associativity except for exponents
                        if (c == '^' && *it == '^') break;
                        else if (m[c] >= m[*it]) s.pop();
                        else break;
                        if (c != '(') postfix_str.append(1, c);
                    }
                }
                if (*it != ')') s.push(*it);
            }
        } else { // Output if it is an operand
            postfix_str.append(1, *it);
        }
    }
    // Empty stack if there is any remaining operators
    while (!s.empty()) {
        char c = s.top();
        if (c != '(') postfix_str.append(1, c);
        s.pop();
    }
    return postfix_str;    
}
int main() {
    vector<string> input = {"(a+b)*(c*(d+e))",
                            "x^y/(5*z)+2",
                            "(2-3+4)*(5+6*7)",
                            "a+b*(c^d-e)^(f+g*h)-i"};
    for (auto in: input) {
        cout << "Infix: " << in << " Postfix: " << convert_infix_to_postfix(in) << endl;
    }
}