//leetcode problem
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(const std::string &str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (s.empty()) return false; 
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }
    return s.empty(); 
}
