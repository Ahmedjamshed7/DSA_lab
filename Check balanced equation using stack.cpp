//Check balanced equation using stack
#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& equation) {
    std::stack<char> charStack;
    
    for (size_t i = 0; i < equation.length(); ++i) {
        char c = equation[i];
        if (c == '(' || c == '[' || c == '{') {
            charStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (charStack.empty()) {
                return false; // Unmatched closing bracket
            }
            char top = charStack.top();
            charStack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // Mismatched closing bracket
            }
        }
    }
    
    return charStack.empty(); // The stack should be empty if all brackets are matched
}

int main() {
    std::string equation;
    std::cout << "Enter an equation with parentheses, brackets, and curly braces: ";
    std::cin >> equation;

    if (isBalanced(equation)) {
        std::cout << "The equation is balanced." << std::endl;
    } else {
        std::cout << "The equation is not balanced." << std::endl;
    }

    return 0;
}