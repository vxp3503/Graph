#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,bool>visited;
    map<int,list<int>>adj;
    map<int,bool>color;
    public:
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string bipertite(int node,int c)
    {
        visited[node]=1;
        color[node]=c;
        for(auto i=adj[node].begin();i!=adj[node].end();i++)
        {
            if(!visited[*i])
            {
                if(bipertite(*i,c^1)=="false")
                return "false";
            }
            else if(color[node]==color[*i])
            {
                return "false";
            }
        }
        return "true";
    }
};
int main()
{
    Graph g1,g2,g3;
    g1.add_edge(1,2);
    g1.add_edge(1,6);
    g1.add_edge(6,5);
    g1.add_edge(5,4);
    g1.add_edge(3,4);
    g1.add_edge(2,3);
    cout<<g1.bipertite(1,0);

    g2.add_edge(1,2);
    g2.add_edge(2,3);
    g2.add_edge(3,4);
    g2.add_edge(2,4);
    g2.add_edge(4,5);
    cout<<endl<<g2.bipertite(1,0);

    g3.add_edge(0,3);
    g3.add_edge(2,3);
    cout<<g3.bipertite(0,0);
}