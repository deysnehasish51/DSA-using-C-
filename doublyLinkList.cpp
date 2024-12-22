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
void insertAthead(Node* &head){
  int data;
  cout<<"Enter the data(head)";
  cin>>data;
  Node* temp = new Node(data);
  temp->next = head;
  head->prev = temp;
  head = temp;
}
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
void deleteAtHead(Node* &head){
  Node* temp = head;
  head = temp->next;
  head->prev=NULL;
  delete temp;  
}
void deleteAtTail(Node* &tail){
  Node* temp = tail;
  temp->prev->next = NULL;
  tail = temp->prev;
  delete temp;
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
void accessData(Node* &head,int position){
  Node* temp= head;
   int count = 1;
   while(count!=position){
    temp=temp->next;
    count++;
   }
   cout<<"The data is: "<<temp->data<<"\n";
}
void findData(Node* &head,int data){
  int count = 1;
  Node* temp = head;
  while(temp->data != data){
    temp=temp->next;
    count++;
  }
  cout<<"\nThe node number is : "<<count;
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
    printForward(head);
    printBackward(tail);
    insertAthead(head);//Inserting the data at head
    printForward(head);
    printBackward(tail);
    insertAtTail(tail);//Inserting the data at tail
    printForward(head);
    printBackward(tail);
    int position;
    cout<<"Enter the position number: ";
    cin>>position;
    insertAtPosition(head,position);//Inserting the node at a specific position
    printForward(head);
    printBackward(tail);
    deleteAtHead(head);//Deleting the node from head
    cout<<"After the head is being deletd: "<<"\n";
    printForward(head);
    printBackward(tail);
    deleteAtTail(tail);//Deleting the node from tail
    cout<<"After the tail is being deletd: "<<"\n";
    printForward(head);
    printBackward(tail);
    int p;
    cout<<"Enter the position number, that is to be delted: ";
    cin>>p;
    deleteAtPosition(head,p);//Deleting the node from the middle
    printForward(head);
    printBackward(tail);
    int pos;
    cout<<"Enter the node number: ";
    cin>>position;
    accessData(head,position);//Accessing the data by the node position
    cout<<"Enter the data, to find the node number: ";
    int da;
    cin>>da;
    findData(head,da);
return 0;
}