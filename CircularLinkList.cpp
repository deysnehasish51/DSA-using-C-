#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        head = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        head = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty.";
        return;
    }
    else
    {

        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    Node *head = NULL;
    int choice = 1;
    while (choice == 1)
    {
        int data;
        cout << "Enter the data: ";
        cin >> data;
        int position;
        cout << "Enter the position: ";
        cin >> position;
        switch (position)
        {
        case 1:
            insertAtHead(head, data);
            break;
        case 0:
            insertAtTail(head, data);
            break;
        }
        cout << "Enter the choice: ";
        cin >> choice;
    }
    print(head);
}