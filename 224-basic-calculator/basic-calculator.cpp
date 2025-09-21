#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeWhitespaces(const string& str) {
        string result;
        for (char c : str) {
            if (c != ' ') result += c;
        }
        return result;
    }

    int calculate(string s) {
        // Remove whitespaces
        s = removeWhitespaces(s);

        stack<int> values;
        stack<char> ops;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;  // Adjust index
                values.push(num);
            } 
            else if (c == '(') {
                ops.push(c);
            } 
            else if (c == ')') {
                // Process inside parentheses
                while (!ops.empty() && ops.top() != '(') {
                    compute(values, ops);
                }
                ops.pop(); // Remove '('
            } 
            else if (c == '+' || c == '-') {
                // Handle unary minus
                if (c == '-' && (i == 0 || s[i - 1] == '(')) {
                    values.push(0);  // Unary minus becomes "0 - num"
                }
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    compute(values, ops);
                }
                ops.push(c);
            }
        }

        // Final computation
        while (!ops.empty()) {
            compute(values, ops);
        }

        return values.top();
    }

private:
    int precedence(char op) {
        return (op == '+' || op == '-') ? 1 : 0;
    }

    void compute(stack<int>& values, stack<char>& ops) {
        if (values.size() < 2 || ops.empty()) return;

        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') values.push(a + b);
        if (op == '-') values.push(a - b);
    }
};
