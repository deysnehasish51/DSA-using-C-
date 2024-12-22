#include <iostream>
//insert Node At End
using namespace std;
struct Node{
    int data;
    Node* next;
};
void print(Node* &head){
   Node* temp = head;
   while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
   }
}
int main(){
Node* temp = NULL;
Node* head = NULL;
int choice = 1;
while(choice == 1){
   Node* newNode = new Node();
   cout<<"Enter the data: ";
   cin>>newNode->data;
   newNode->next=nullptr;
   if(head == nullptr)
   head = temp = newNode;
   else{
    temp->next = newNode;
    temp=newNode;
   }
   cout<<"Continue 1 or 0: ";
   cin>>choice;
}
print(head);
}//