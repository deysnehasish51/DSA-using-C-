#include<iostream>
using namespace std;
void heapify(int* arr,int size,int i){
    int largest = i;
    int left = i * 2;
    int right = i*2+1;
    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
         swap(arr[largest],arr[i]);
         heapify(arr,size,largest);
    }
}
void heapSort(int* arr,int size){
    int t = size;
    while(t>1){
        //swap 
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}
int main(){
    int size;
    cout<<"Enter the size of the Array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in array : ";
    for(int i = 1 ; i <= size ; i++){
        cin>>arr[i];
    }
    for(int i = size/2 ; i > 0 ; i--){
        heapify(arr,size,i);
    }
    
    heapSort(arr,size);
    for(int i = 1; i<size;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}