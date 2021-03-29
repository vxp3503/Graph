#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>>adj;
    map<int,bool>visited;
    public:
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool is_cycle(int node,int parent)
    {
            visited[node]=1;
            for(auto i=adj[node].begin();i!=adj[node].end();i++)
            {
                if(!visited[*i])
                {
                    if(is_cycle(*i,node))
                    {
                        return true;
                    }
                }
                else if(parent!=*i)
                {
                    return true;
                }
            }
        return false;
    }
    bool detectcycle()
    {
        for(auto i=adj.begin();i!=adj.end();i++)
        {
            if(!visited[i->first])
            {
                if(is_cycle(i->first,-1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph g1;
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 1);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    g1.detectcycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    Graph g2;
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.detectcycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";

    Graph g3;
    g3.add_edge(1,2);
    g3.add_edge(2,3);
    g3.add_edge(3,4);
    g3.add_edge(2,4);
    g3.add_edge(4,5);
    g3.detectcycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
}