#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform basic arithmetic operations
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero!");
            return a / b;
    }
    return 0;
}

// Function that evaluates a mathematical expression string
double evaluate(string tokens) {
    stack<double> values;
    stack<char> ops;

    for (size_t i = 0; i < tokens.length(); i++) {
        // Skip whitespace
        if (tokens[i] == ' ') continue;

        // If current token is an opening brace, push it to 'ops'
        if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        // If current token is a number, parse the whole number
        else if (isdigit(tokens[i])) {
            double val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            // Check for decimal point
            if (i < tokens.length() && tokens[i] == '.') {
                i++;
                double fraction = 0.1;
                while (i < tokens.length() && isdigit(tokens[i])) {
                    val += (tokens[i] - '0') * fraction;
                    fraction /= 10;
                    i++;
                }
            }
            values.push(val);
            i--; // Adjust loop counter
        }
        // Closing brace encountered, solve entire brace
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty()) ops.pop(); // Remove '('
        }
        // Current token is an operator
        else if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed, apply remaining ops
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    cout << "====================================" << endl;
    cout << "      Smart C++ Calculator v1.0     " << endl;
    cout << "====================================" << endl;
    cout << "Enter your expression (or type 'exit' to quit)." << endl;
    cout << "Example: (12 + 3) * 4 / 2" << endl;
    cout << "------------------------------------" << endl;

    string input;
    while (true) {
        cout << "\ncalc > ";
        getline(cin, input);

        if (input == "exit" || input == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }

        try {
            double result = evaluate(input);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}