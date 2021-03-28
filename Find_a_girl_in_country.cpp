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
	int find_girl(set<int> s,int Q)
	{
		shortest_distance(1,0);
		auto j=s.begin();
		int min=*j;
		for(auto i=s.begin();i!=s.end();i++)
		{
			if(distance[*i]<distance[*j])
			{
				min=*i;
			}
		}
		return min;
	}
};
int main()
{
	Graph g;
	int N;
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		cin>>u;
		cin>>v;
		g.add_edge(u,v);
	}
	int Q;
	cin>>Q;
	set<int>s;
	for(int i=0;i<Q;i++)
	{
		int v;
		cin>>v;
		s.insert(v);
	}
	cout<<g.find_girl(s,Q);
}