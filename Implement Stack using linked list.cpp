//Implement Stack using linked list

#include <iostream>

struct Node {
    char data;
    Node* next;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* top, char data) {
    Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (top == NULL) {
        std::cout << "Stack underflow\n";
        return NULL;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    return top;
}

char peek(Node* top) {
    if (top == NULL) {
        std::cout << "Stack is empty\n";
        return '\0';
    }
    return top->data;
}

bool isEmpty(Node* top) {
    return (top == NULL);
}

int main() {
    Node* top = NULL;
    char input;
    char choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter character to push: ";
                std::cin >> input;
                top = push(top, input);
                break;

            case '2':
                top = pop(top);
                break;

            case '3':
                std::cout << "Top of the stack: " << peek(top) << "\n";
                break;

            case '4':
                
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '4');

    return 0;
}