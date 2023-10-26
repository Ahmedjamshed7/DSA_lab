#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    // Create a custom stack using a singly linked list
    Node* stackTop = nullptr;

    Node* slow = head;
    Node* fast = head;

    // Push the first half of the linked list onto the custom stack
    while (fast != nullptr && fast->next != nullptr) {
        Node* newNode = createNode(slow->data);
        newNode->next = stackTop;
        stackTop = newNode;

        slow = slow->next;
        fast = fast->next->next;
    }

    // If the list has an odd number of elements, skip the middle one
    if (fast != nullptr)
        slow = slow->next;

    // Compare the second half of the list with the custom stack
    while (slow != nullptr) {
        if (slow->data != stackTop->data)
            return false;

        // Pop the top element from the custom stack
        Node* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;

        slow = slow->next;
    }

    // Clean up the custom stack
    while (stackTop != nullptr) {
        Node* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }

    return true;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    cout << "Linked List: ";
    displayList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
