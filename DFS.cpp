#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int size;
    list<int>*adj;
    bool *visited;
    public:
    Graph(int V)
    {
        size=V;
        adj=new list<int>[V];
        visited=new bool[V];
    }
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int root)
    {
        visited[root]=1;
        cout<<root<<"->";
        for(auto &n:adj[root])
        {
            if(!visited[n])
            {
                DFS(n);
            }
        }
    }
};
int main()
{
    Graph G(7);
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(2,4);
    G.add_edge(4,6);
    G.add_edge(4,5);
    G.DFS(1);
}