 #include<iostream>
 using namespace std;
 int queue[100];
 int rear=-1;
 int front =-1;
 void enqueue(int data){
     if(rear >=100){
         cout<<"Overflow";
         return;
     }
     if(front == -1 && rear == -1){
         front++;
         rear++;
         queue[front]=data;
     }
     else{
         rear++;
         queue[rear] = data;
     }
 }
 void dequeue(){
     if(front == -1 || front > rear){
         cout<<"Underflow";
         return;
     }
     else{
         cout<<"The deleted element is: "<<queue[front];
         front++;
     }
 }
 void print(){
     for(int i = front;i<=rear;i++){
         cout<<queue[i]<<" ";
     }
 }
 int main(){
     int choice;
     cout<<"1.Enqueue"<<endl;
     cout<<"2.Dequeue"<<endl;
     cout<<"3.Display"<<endl;

     cout<<"Enter the choice: ";
     cin>>choice;
     while(choice!=4){
        switch(choice){
         case 1:
             int data;
             cout<<"Enter the data: ";
             cin>>data;
             enqueue(data);
             break;
         case 2:
        
             dequeue();
             break;
         case 3:
             print();
             break;
         }
         cout<<"Enter the choice: ";
         cin>>choice;
     }
 return 0;
 }
