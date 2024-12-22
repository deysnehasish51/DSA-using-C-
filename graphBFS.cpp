#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr[5][5];
int numVertices=5;

addEdge(int i,int j)
{
    arr[i][j]=1;
    arr[j][i]=1;
}

void breadthFirstSearch(int startVertex)
{
    bool visited[numVertices]={false};
    queue <int> bfsQueue;

    visited[startVertex]=true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty())
    {
        int currentVertex=bfsQueue.front();
        cout<<currentVertex<<"  ";
        bfsQueue.pop();
        for(int i=0;i<numVertices;i++)
        {
            if(arr[currentVertex][i]==1&&visited[i]==false)
            {
                visited[i]=true;
                bfsQueue.push(i);
            }
        }
    }   
}
int main()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,4);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    
    breadthFirstSearch(1);
    cout<<endl;
    breadthFirstSearch(4);
    return 0;
}