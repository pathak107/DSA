#include<iostream>
#include<stack>
using namespace std;

void DFS(int start, int adj[][50],int v) 
{ 
   
    bool visited[50]={false}; 
    stack<int> s;
    s.push(start); 
  
  
  
   
    while (!s.empty()) { 
        start= s.top();
        s.pop();

        if(!visited[start])
        {
            cout<<start<<" ";
            visited[start]=true;
        }
        // For every adjacent vertex to the current vertex 
        for (int i = 0; i < v; i++) { 
            if (adj[start][i] == 1 && (!visited[i])) { 
  
                // Push the adjacent node to the queue 
                s.push(i); 
  
                // Set 
                // visited[i] = true; 
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
    DFS(0,adj,v);
    return 0;

}