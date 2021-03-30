//Check node wheather a in the sub tree of b


#include<bits/stdc++.h>
using namespace std;    
int timer=1;
class Graph
{
    map<int,list<int>>adj;
    map<int,bool>visited;
    map<int,int>In;
    map<int,int>Out;
    public:
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int node)
    {
        visited[node]=1;
        In[node]=timer++;
        for(auto i=adj[node].begin();i!=adj[node].end();i++)
        {
            if(!visited[*i])
            {
                DFS(*i);
            }
        }
        Out[node]=timer++;
    }
    bool check_a_in_subtree_of_b(int a, int b)
    {
        // for(auto i=Out.begin();i!=Out.end();i++)
        // { 
        //     cout<<(i->first)<<" "<<(i->second);
        // }
        if(In[a]>In[b]&&Out[a]<Out[b])
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    Graph g;
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(4,5);
    g.DFS(1);
    cout<<g.check_a_in_subtree_of_b(4,3);
}