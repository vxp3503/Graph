#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,bool>visited;
    map<int,int>distance;
    map<int,list<int>>adj;
    public:
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void shortest_distance(int source,int dist)
    {
        visited[source]=1;
        distance[source]=dist;
        for(auto i=adj[source].begin();i!=adj[source].end();i++)
        {
            if(!visited[*i])
            {
                shortest_distance(*i,dist+1);
            }
        }
    }
    void print_distance(int source)
    {
        cout<<"distance from all nodes of given source"<<source;
        shortest_distance(source,0);
        for(auto i=distance.begin();i!=distance.end();i++)
        {
            cout<<"distance of "<<i->first<<"from source is:->"<<i->second<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(4,5);
    g.add_edge(4,6);
    g.print_distance(1);
}