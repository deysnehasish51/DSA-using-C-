#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int pass,i,min,loc;
    min=sizeof(arr)/sizeof(arr[0]);
    for(pass=0;pass<min-1;pass++)
    {   
        
        for(i=pass+1;i<min;i++)
        {
            if(min>arr[i])
            {
                min=arr[i];
                loc=i;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}