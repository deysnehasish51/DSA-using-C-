#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    public:
    unordered_map<int,list<int> > adjList;
    void addEdge(int u,int v,int direction)
    {
        if(direction==1)
        {
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printList()
    {
        for(auto i: adjList)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    void bfs(int src,unordered_map<int,bool>& visited)
    {
        queue<int> data;
            data.push(src);
            visited[src]=true;
            while(!data.empty())
            {
                int node=data.front();
                cout<<node<<" ";
                data.pop();
                for(auto ngh: adjList[node])
                {
                    if(!visited[ngh])
                    {
                        data.push(ngh);
                        visited[ngh]=true;
                    }
                }
            }
    }
    void dfs(int src,unordered_map<int,bool> &vis)
    {
        vis[src]=true;
        cout<<src<<" ";
        for(auto ngh: adjList[src])
        {
            if(!vis[ngh])
            {
                dfs(ngh,vis);
            }
        }

    }
};
int main()
{
    Graph g;
    cout<<"Enetr the number of nodes in the graph";
    int n;
    cin>>n;
    cout<<"\n Enetr the number of edges in the graph";
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printList();
    cout<<"BFS Printing the result";
    unordered_map<int,bool> visited;
    g.bfs(0,visited);
     cout<<"\nDFS Printing the result";
    unordered_map<int,bool> vis;
    g.dfs(0,vis);
}