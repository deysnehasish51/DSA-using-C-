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
void insertAtPosition(Node* &head,int position){
  int data;
  cout<<"Enter the data(Middle): ";
  cin>>data;
  Node* newNode = new Node(data);
  Node* temp=head;
  int count = 1;
  while(count!=position-1){
     temp=temp->next;
     count++;
  }
  temp->next->prev = newNode;
  newNode->next = temp->next;
  newNode->prev =temp;
  temp->next = newNode;  
}
void deleteAtPosition(Node* &head,int p){
   Node* temp= head;
   int count = 1;
   while(count!=p){
    temp=temp->next;
    count++;

   }
   temp->next->prev = temp->prev;
   temp->prev->next = temp->next;
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
     int position;
    cout<<"Enter the position number: ";
    cin>>position;
    insertAtPosition(head,position);//Inserting the node at a specific position
    printForward(head);
    printBackward(tail);
    deleteAtPosition(head,position);
    printForward(head);
return 0;
}