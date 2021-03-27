#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,bool>visited;
    map<int,list<int>>adj;
    public:
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
    void  count()
    {
        int count =0;
        for(auto i=adj.begin();i!=adj.end();i++)
        {
            if(!visited[i->first])
            {
                DFS(i->first);
                count++;
            }
        }
        cout<<endl<<count;
    }
};
int main()
{
    Graph G;
    G.add_edge(1,5);
    G.add_edge(5,6);
    G.add_edge(5,2);
    G.add_edge(2,8);
    G.add_edge(8,6);
    G.add_edge(6,4);
    G.add_edge(3,7);
    G.count();
}