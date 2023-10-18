//Reverse of a string using stack
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::stack<char> charStack;

    // Push each character onto the stack
    for (size_t i = 0; i < input.length(); ++i) {
        charStack.push(input[i]);
    }

    // Pop characters and append them to a new string to reverse the order
    std::string reversedString;
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    // Print the reversed string
    std::cout << "Reversed string: " << reversedString << std::endl;

    return 0;
}