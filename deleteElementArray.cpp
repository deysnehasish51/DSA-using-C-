#include<iostream>
using namespace std;

int main()
{
    int i,n;
    cout<<"Enter the Size of array"<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pos;
    cout<<"Enter the Position you want the delete the element"<<endl;
    cin>>pos;
    for(i=pos;i<=n;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}