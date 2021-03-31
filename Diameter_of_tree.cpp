#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>>adj;
    public:
    map<int,bool>visited;
    int maxnode, max=-1;
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void diameter(int root,int d)
    {
        visited[root]=1;
        if(d>max)
        {
            max=d;
            maxnode=root;
        }
        for(auto i=adj[root].begin();i!=adj[root].end();i++)
        {
            if(!visited[*i])
            {
                diameter(*i,d+1);
            }
        }
    }
    int maximum(int x)
    {
        diameter(x,0);
        max=-1;
    for(auto i=visited.begin();i!=visited.end();i++)
    {
        i->second=0;
    }
    diameter(maxnode,0);
    return max;
    }
};
int main()
{
    Graph g,g2;
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(3,7);
    g.add_edge(4,5);
    g.add_edge(4,6);
    cout<<g.maximum(1);

    g2.add_edge(0,1);
    g2.add_edge(1,2);
    cout<<g2.maximum(0);
}