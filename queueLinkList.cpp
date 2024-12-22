#include <iostream>
using namespace std;
class Queue{
  public:
    int data;
    Queue* next;
    Queue(int data){
        this->data = data;
        next = NULL;
    }
};
Queue* front = NULL;
Queue* rear = NULL;
void enque(int value){
    Queue* temp = new Queue(value);
    if(front == NULL && rear == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}
void deque(){
    if(front == NULL){
        cout<<"Underflow";
    }else{
        cout<<"Deleted element is: "<<front->data;
        front=front->next;
    }
}
void display(){
    Queue* temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    cout<<"Enter 1 for inserting the element.";
    cout<<"\nEnter 2 for deleting the element.";
    cout<<"\nEnter 3 for displaying the element";
    cout<<"\nEnter 4 for exit.";
    int choice;
    do{
        cout<<"Enter the choice: ";
        cin>>choice;
        switch(choice){
            case(1):
            int value;
            cout<<"Enter the value:";
            cin>>value;
            enque(value);
            break;
            case(2):
            deque();
            break;
            case(3):
            display();
            break;
            case(4):
            cout<<"Exit";
            break;
            default:
            cout<<"Invalid Input.";
        }
    }while(choice!=4);
    return 0;
}