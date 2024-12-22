#include<iostream>
using namespace std;

int main()
{
  int i,j,pos;
  cout<<"Enter the position : "<<endl;
  cin>>pos;
  int num;
  cout<<"Enter the Number you want to insert"<<endl;
  cin>>num;
  int n;
  cout<<"Enter the size of the Array "<<endl;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(i=pos;i>=n;i--)
  {
    arr[i]=arr[i-1];
  }
  arr[i+1]=num;
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}