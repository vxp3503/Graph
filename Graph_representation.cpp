#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int size;
    list<int>*adj;
    public:
    Graph(int V)
    {
        size=V;
        adj=new list<int>[size];
    }
    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<i<<"->";
            for(auto j= adj[i].begin();j!=adj[i].end();j++)
            {
                cout<<*j<<"->";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(7);
    g.add_edge(1,2);
    g.add_edge(2,4);
    g.add_edge(4,6);
    g.add_edge(4,5);
    g.add_edge(2,3);
    g.add_edge(3,5);
    g.print();
}