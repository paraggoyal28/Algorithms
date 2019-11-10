/*
Given an undirected graph, print all connected components line by line. Finding connected components of an undirected graph is an 
easy task. We simply need to do either BFS or DFS starting from every unvisited vertex, and we get all the stringly connected 
components. Below are the steps to follow:
1) Initialize all vertices as not visited.
2) Do following for every vertex 'v'
	(a) If 'v' is not visited before, call DFSUtil(v)
	(b) Print new line character
DFSUtil(v)
1) Mark 'v' as visited
2) Print 'v'
3) Do following for every adjacent vertex 'u' of 'v':
	If 'u' is not visited before, then recursively call DFSUtil(u)
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // number of vertices
	list<int> *adj; // pointer to array containing adjacency list
	void DFSUtil(int v, bool visited[]) //  A function used by DFS
public:
	Graph(int V); //constructor
	void addEdge(int u, int v); 
	void connectedComponents();
};

// Method to print connected components of the graph
void Graph::connectedComponents()
{
	// Mark all vertices as not visited
	bool *visited = new bool[V];
	for(int v = 0; v < V ; v++)
		visited[v] = false;
	for(int v = 0; v < V ; v++)
	{
		if(!visited[v])
		{
			DFSUtil(v,visited);
			cout<<"\n";
		}
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout<< v << " ";
	
	// Recur for all vertices adjacent to this vertex.
	list<int> :: iterator itr;
	for(itr = adj[v].begin(); itr!=adj[v].end(); ++itr)
		if(!visited[*itr])
			DFSUtil(*itr,visited);

}
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver program to test above
int main()
{
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(2,3);
	g.addEdge(3,4);
	cout<< "Following are the connected components\n";
	g.connectedComponents();
	
	return 0;
}
