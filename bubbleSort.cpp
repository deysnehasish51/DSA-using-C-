#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Array size "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Array before sorting"<<endl;
    for(int i=0;i<n;i++)
    {   
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"Array after Sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}