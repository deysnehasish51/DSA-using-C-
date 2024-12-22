#include<iostream>
#include<stack>
using namespace std;
int adjMatrix[4][4];
int numVertices = 4; // Predefined number of vertices

// Add edges
void addEdge(int i, int j) {
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}
// DFS traversal
void DFS(int start) {
    bool visited[numVertices] = {false};
    stack<int> stack;

    stack.push(start);
    visited[start] = true;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        cout << current << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[current][i] && !visited[i]) { // if (adjMatrix[current][i]==1&& visited[i]==false) 
                stack.push(i);
                visited[i] = true;
            }
        }
    }
}
   int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);

    cout << "DFS traversal starting from node 0: ";
    DFS(0);
    cout << endl;
    cout << "DFS traversal starting from node 3: ";
    DFS(3);
    return 0;
}