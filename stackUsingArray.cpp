#include <iostream>
using namespace std;
int stack[10], n=10, top=-1;
void push(int val) {
   if(top>=n-1)
   cout<<"Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int peek()
{
    if(top==-1)
    {
        cout<<"Stack is Empty";
        return -1;
    }
    else
    {
        return stack[top];
    }
}
int max()
{
   int max=stack[0];
   for(int i=0;i<n;i++)
   {
   if(stack[i]>max)
   {
      max=stack[i];
   }
   }
   return max;
}
int min()
{
   int min=stack[0];
   for(int i=0;i<n;i++)
   {
      if(min>stack[i])
      {
         min=stack[i];
      }
   }
   return min;
}
int main() {
   int choice, val,n;
   n=sizeof(stack)/sizeof(stack[0]);
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Peek"<<endl;
   cout<<"5) Max Element"<<endl;
   cout<<"6) Min Element"<<endl;
   cout<<"7) Exit"<<endl;
   
   do {
      cout<<"Enter choice: "<<endl;
      cin>>choice;
      switch(choice) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
           cout<<"Peek is :"<< peek()<<endl;
            
            break;
         }
         
         case 5:{
            cout<<"The max Value in Array is : "<<max()<<endl;
            break;
         }
         case 6:{
            cout<<"The min Value in Array is : "<<min()<<endl;
            break;
         }
         case 7: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(choice!=6);
   return 0;
}