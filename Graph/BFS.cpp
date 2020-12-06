#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
	Graph(int V)
	{
		this->V=V;
		adj=new list<int>[V];
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}
	void BFS(int a)
	{
		list<int> queue;
		bool visited[V];
		for(int i=0;i<V;i++)
		visited[i]=false;
		queue.push_back(a);
		visited[a]=true;
		while(!queue.empty())
		{
			int z=queue.front();
			cout<<z<<" ";
			queue.pop_front();
			for(auto it=adj[z].begin();it!=adj[z].end();it++)
			{
				if(visited[*it]==false)
				{
					visited[*it]=true;
					queue.push_back(*it);
				}
			}
		}
	}
};
int main()
{
	int n;		//number of vertices
	cin>>n;
	Graph g(n);
	int v;		//number of edges
	cin>>v;
	int a,b;
	for(int i=0;i<v;i++)
	{
		cin>>a>>b;	// edge a to edge b
		g.addEdge(a,b);	
	}
	cin>>a;			// Starting index for BFS
	g.BFS(a);
}