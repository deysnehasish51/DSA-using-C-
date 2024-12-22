#include<iostream>
using namespace std;

int main()
{
    int size1,size2,size3;
    cout<<"Enter the size of the first array : ";
    cin>>size1;
    int arr1[size1];
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of the Second array : ";
    cin>>size2;
    int arr2[size2];
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }
    int arr3[size3];
    for(int i=0;i<size1;i++)
    {
        arr3[i]=arr1[i];
    }
    for(int i=0;i<size3;i++)
    {
        arr3[i+size1]=arr2[i];
    }
    for(int i=0;i<size3;i++)
    {    
        cout<<arr3[i]<<" ";
    }
    return 0;
}