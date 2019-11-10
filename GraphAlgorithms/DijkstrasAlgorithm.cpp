/* Given a graph and a source vertex in graph,find shortest paths from source to all vertices in the given graph.
Below is the algorithm based on set data structure.
1) Initialize distances of all vertices as infinite.
2) Create an empty set. Every item of the set is a pair(weight,vertex). Weight(or distance) is used as first 
item of pair to compare two items.
3) Insert source vertex into the set and make its distance as 0.
4) While set doesn't become empty, do following
	a) Extract minimum distance vertex set from the set . Let the extracted vertex be u.
	b) Loop through all adjacent of u and do following for every vertex v
		// If there is a shorter path to v through u.
		If dist[v] > dist[u] + weight(u,v)
		i) update distance of v ,i.e, distance of v is dist[v] = dist[u] + weight(u,v)
		ii) If v is in set, update its distance in set by removing it first, then inserting the new distance.
		iii) If v is not in set, then insert it in set with new distance.
5) Print distance array dist[] to print all the shortest paths.
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph
{
	int V; // number of Vertices
	list<pair<int,int> > *adj;
public:
	Graph(int V); //constructor
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<pair<int,int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src)
{
	set<pair<int,int> > setd;
	vector<int> dist(V,INF);
	setd.insert(make_pair(0,src));
	dist[src] = 0;
	while(!setd.empty())
	{
		pair<int,int> temp = *(setd.begin());
		setd.erase(setd.begin());
		int u = temp.second;
		list<pair<int, int> >::iterator itr;
		for(itr = adj[u].begin();itr!=adj[u].end();itr++)
		{
			int v = (*itr)->first;
			int weight = (*itr)->second;
			if(dist[v] > dist[u] + weight)
			{
				if(dist[v]!=INF)
					setd.erase(setd.find(make_pair(dist[v],v)));
				dist[v] = dist[u] + weight;
				setd.insert(make_pair(dist[v],v));
			}
		}
	}
	
	// Print shortest distances stored in dist[]
	printf("Vertex Distances from Source\n");
	for(int i=0;i<V;i++)
		printf("%d \t\t %d\n",i,dist[i]);
}

int main()
{
	int V  = 9;
	Graph g(V);
	
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	
	g.shortestPath(0);
	return 0;
}

					
