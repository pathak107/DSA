#include<iostream>
#include<queue>
using namespace std;

void BFS(int start, int adj[][50],int v) 
{ 
    // Visited vector to so that 
    // a vertex is not visited more than once 
    // Initializing the vector to false as no 
    // vertex is visited at the beginning 
    bool visited[50]={false}; 
    queue<int> q;
    q.push(start); 
  
    // Set source as visited 
    visited[start] = true; 
  
    int vis; 
    while (!q.empty()) { 
        vis = q.front(); 
  
        // Print the current node 
        cout << vis << " "; 
        q.pop(); 
  
        // For every adjacent vertex to the current vertex 
        for (int i = 0; i < v; i++) { 
            if (adj[vis][i] == 1 && (!visited[i])) { 
  
                // Push the adjacent node to the queue 
                q.push(i); 
  
                // Set 
                visited[i] = true; 
            } 
        } 
    } 
} 
  
int main()
{
    int adj[50][50],v;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>v;
    cout<<"\n Enter the adjacency matrix : "<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>adj[i][j];
        }
        
    }
    cout<<"Enter the starting vertex: ";
    int start;
    cin>>start;
    BFS(start,adj,v);
    return 0;

}