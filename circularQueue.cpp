#include <iostream>
using namespace std;
int queue[100],size=100, front=-1,rear = -1;
void enqueue(int value){
    if(rear == -1 && front == -1){
        front = rear = 0;
        queue[front] = value;
    }
    else if((rear+1)%size == front){
        cout<<"Overflow";
    }
    else{
        rear = (rear+1)%size;
        queue[rear] = value;
    }
}
void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Underflow";
    }
    else if(front == rear){
        front=rear=-1;
    }else{
        cout<<"The deleted element is: "<<queue[front];
        front = (front+1)%size;
    }
}
void display(){
    if(front==-1 && rear ==-1){
        cout<<"The queue is empty";
    }else{
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
    }
}
int main(){
   int choice;
   do{
    cout<<"Enter the choice: ";
    cin>>choice;
    switch(choice){
        case(1):
        int value;
        cout<<"Enter the value: ";
        cin>>value;
        enqueue(value);
        break;
        case(2):
        dequeue();
        break;
        case(3):
        display();
        break;
        case(4):
        cout<<"Exiting";
        break;
    }
   }while(choice != 4);
   return 0;
}