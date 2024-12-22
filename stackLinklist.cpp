#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        next = NULL;
    }
};
Node* top = NULL;
void push(int value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}
void pop(){
    if(top==NULL){
        cout<<"Underflow";
    }else{
        cout<<"The poped element is: "<<top->data;
        Node* temp = top;
        top = temp->next;
        delete temp;
    }
}
void display(){
    if(top==NULL){
        cout<<"The stack is empty.";
    }else{
        Node* temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}
int main(){
    cout<<"Enter 1 for pushing the element.";
    cout<<"Enter 2 for poping the element.";
    cout<<"Enter 3 for displaying the element.";
    cout<<"Enter 4 for exit";
    int choice;
    do{
        cout<<"\nEnter the choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            int value;
            cout<<"\nEnter the value: ";
            cin>>value;
            push(value);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            default:
            cout<<"\nInvalid choice";
            break;
        }
    }while(choice!=4);
    return 0;
}