#include<iostream>
//Insert Node At Beggining
using namespace std;
struct Node{
  int data;
  Node* next;
};
void print(Node* &head)
{
   Node* temp = head;
   while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
   }
}
int main(){
    Node* head = nullptr;
    Node* temp = nullptr;
    int choice = 1;
    while(choice == 1){
      temp = new Node;
      cout<<"Enter the data: ";
      cin>>temp->data;
      temp->next = head;
      head = temp;
      cout<<"Choice 1 or 0";
      cin>>choice;
    }
    print(head);
    
return 0;
}