/*
Given a graph and a source vertex src in graph, find shortest paths from src to all the vertices in the given graph.
Dijkstra algorithm is a greedy algorithm and time complexxity is O(VlogV)(with the use of Fibonacci Heap). Dijkstra 
doesn't work for graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also much
more simpler than Dijkstra and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE),
which is more than Dijkstra.
Algorithm
Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, 
negative cycle is reported.
Algorithm
1) This step initializes distances from source to all vertices as infinte and distance to itself is zero. Create an array dist[] 
of size |V| with all values as infinite except dist[src] where src is the source vertex.
2) This step calculates shortest distances. Do following |V| - 1 times where |V| is the number of vertices in the graph.
	...a) Do following for each edge u-v
		...If dist[v] > dist[u] + weight of edge uv, then update dist[v]
		... dist[v] = dist[u] + weight of edge uv.
3) This step reports if there is a negative weight cycle in a graph.Do following for each edge u-v 
... If dist[v] > dist[u] + weight of edge uv, then "Graph contains negative cycle."
The idea of step 3 is, step 2 guarantees shortest distances if graph doesn’t contain negative weight cycle. 
If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
*/

// A C++ program for Bellman Ford single source shortest path algorithm.
#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest, weight;
};

struct Graph{
	int V,E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
};

void printArr(int dist[],int n)
{
	printf("Vertex Distance From Source\n");
	for(int i = 0; i < n; ++i)
		printf("%d \t\t %d",i,dist[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	
	// Step 1: Initialize all the distances from src to all vertices as Infinite
	for(int i = 0;i< V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V|-1 times. A simple shortest path from src to any other vertex can 
	// have at most |V| - 1 edges.
	for(int i = 1; i<= V-1; i++)
		for(int j = 0;j<E;j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dist[u]!=INT_MAX && dist[u] + weight < dist[v] )
				dist[v] = dist[u] + weight;
		}
	
	for(int i = 0;i<E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if(dist[u]!=INT_MAX && dist[v]> dist[u] + weight)
		{
			printf("Graph contains negative weight cycle\n");
			return;
		}
	}
	printArr(dist,V);
	return;
}

int main()
{
	int V = 5;
	int E = 8;
	struct Graph* graph = createGraph(V,E);
	
	// Edge 1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;
	
	// Edge 2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;
	
	// Edge 3
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;
	
	// Edge 4
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;
	
	// Edge 5
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;
	
	// Edge 6
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;
	
	// Edge 7
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;
	
	// Edge 8
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;
	
	BellmanFord(graph,0);
	
	return 0;
}
