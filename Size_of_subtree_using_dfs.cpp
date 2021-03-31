#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> adj;
    map<int, bool> visited;
    map<int, int> size;

public:
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs(int root)
    {
        visited[root] = 1;
        int curr = 1;
        for (auto i = adj[root].begin(); i != adj[root].end(); i++)
        {
            if (!visited[*i])
            {
                curr += dfs(*i);
            }
        }
        size[root] = curr;
        return curr;
    }
    void print()
    {
        for (auto i = size.begin(); i != size.end(); i++)
        {
            cout << "Size of Node" << i->first << "is-->" << i->second << endl;
        }
    }
};
int main()
{
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 7);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.dfs(1);
    g.print();
}