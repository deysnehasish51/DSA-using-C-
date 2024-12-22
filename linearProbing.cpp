#include<iostream>
using namespace std;

int size = 10;
int hashing[10];

void insertValue() 
{
    int data;
    cout<<"Enter data :";
    cin>>data;
    
    int index = data % size;
    int start = index;
    while(hashing[index] != -1) {
        index = (index + 1) % size;
    }
    
    hashing[index] = data;
}

void display() {
    for(int i=0;i<size;i++) {
        cout<<hashing[i]<< " ";
    }
}

int main() {
    for(int i=0;i<size;i++) {
        hashing[i] = -1;
    }
    
    int choice = 1;
    while(choice == 1)
    {
        insertValue();  
        cout<<"for again inserting value press 1 :";
        cin>>choice;
    } 
    display();
    return 0;
}