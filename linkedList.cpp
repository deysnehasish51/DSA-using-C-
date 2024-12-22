#include<iostream>
using namespace std;
struct Node {  
public:  
  int data;  
  Node *next;  
  
  Node(int data) {  
    this->data = data;  
    this->next = nullptr;  
  }  
}; 
class LinkedList {  
private:  
  Node *head;  
public:  
  LinkedList() {  
    this->head = nullptr;  
  }  
  void Beginning(int data) {  
    Node *newNode = new Node(data);  
    newNode->next = head;  
    head = newNode;  
  } 
  void printList() {  
  Node *temp = head;  
  while (temp != nullptr) {  
    cout << temp->data << " ";  
    temp = temp->next;  
  }  
  cout << endl;  
} 
void deleteNode(int a)
{
    Node* current=head;
    Node* previous=nullptr;
    if(head!=nullptr&&head->data==a)
    {
        head=head->next;
        delete current;
        return;
    }
    while(current!=nullptr&&current->data!=a)
    {
        previous=current;
        current=current->next;
    }
    if(current==nullptr)
    {
        return;
    }
    previous->next=current->next;
    delete current;
} 
};
int main() {  

LinkedList list;   
list.Beginning(3);  
list.Beginning(2);  
list.Beginning(1);
list.printList();
list.deleteNode(2);
list.printList();
return 0; 
}