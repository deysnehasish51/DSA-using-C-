#include<iostream>
using namespace std;
class Node{
  public:
     int data;
     Node* next;
     Node* prev;
     Node(){}
     Node(int d){
         this->data = d;
         next = NULL;
         prev = NULL;
     }   
};
void insertAtTail(Node* &tail){
  int data;
  cout<<"Enter the data(tail)";
  cin>>data;
  Node* temp = new Node(data);
  tail->next = temp;
  temp->prev = tail;
  tail = temp;
}
void deleteAtTail(Node* &tail){
  Node* temp = tail;
  temp->prev->next = NULL;
  tail = temp->prev;
  delete temp;
}
void printForward(Node* &head){
    Node* temp = head;
    cout<<"Node in forward direction: ";
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<endl;
}
void printBackward(Node* &tail){
  Node* temp = tail;
  cout<<"Node in backward direction: ";
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->prev;
  }
  cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail = NULL;
    Node* temp =NULL;
    int choice = 1;
    while(choice == 1){
      int data;
      cout<<"Enter the data: ";
      cin>>data;
      Node* newNode = new Node(data);
      if(head==NULL)
      {
        head = temp = newNode;
      }
      else
      {
          temp->next = newNode;
          newNode->prev=temp;
          temp=newNode;
      }
      tail = temp;
      cout<<"Enter the choice 1 or 0: ";
      cin>>choice;
    }
    insertAtTail(tail);//Inserting the data at head
    printForward(head);
    printBackward(tail);
    deleteAtTail(tail);
    printForward(head);
return 0;
}