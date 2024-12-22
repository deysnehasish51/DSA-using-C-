#include <iostream>
#include <stack>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list using a stack
Node* reverseLinkedList(Node* head) {
    stack<Node*> st;
    Node* current = head;
    
    // Push nodes onto the stack
    while (current != nullptr) {
        st.push(current);
        current = current->next;
    }
    
    // Create a new linked list by popping nodes from the stack
    Node* newHead = nullptr;
    Node* newCurrent = nullptr;
    
    while (!st.empty()) {
        if (newHead == nullptr) {
            newHead = st.top();
            newCurrent = newHead;
            st.pop();
        } else {
            newCurrent->next = st.top();
            newCurrent = newCurrent->next;
            st.pop();
        }
    }
    
    if (newCurrent != nullptr) {
        newCurrent->next = nullptr;
    }
    
    return newHead;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original linked list: ";
    printLinkedList(head);
    
    // Reverse the linked list
    Node* newHead = reverseLinkedList(head);
    
    cout << "Reversed linked list: ";
    printLinkedList(newHead);
    
    return 0;
}