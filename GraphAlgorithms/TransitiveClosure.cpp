/**
Given a directed graph, find out a vertex j is reachable from vertex i for all vertex pairs(i,j) in the given graph. Here reachable means
that there is a path between vertex i and vertex j. Floyd Warshall algorithm is used, we can calculate the distance matrix
dist[V][V] using Floyd Warshall, if dist[i][j] is infinite, then j is not reachable from i, otherwise j is reachable and value of 
dist[j] will be less than V.
1) Instead of integer resultant matrix, we can create a boolean reachability matrix reach[V][V]( we save space). The value of reach[i][j]
will be 1 if j is reachable from i, otherwise 0.
2) Instead of using arithmetic operations, we can use logical operations. For arithmetic operation '+', logical and '&&' is used,and for
min, logical or '||' is used.
*/
#include<bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int reach[][V]);

// Print transitive closure of graph[][] using Floyd Warshall algorithm.
void transitiveClosure(int graph[][V])
{
	int reach[V][V], i, j, k;
	for(i = 0;i < V; i++)
		for(j = 0;j < V; j++)
			reach[i][j] = graph[i][j];
	
	for(k = 0;k< V; k++)
		for(i = 0;i< V; i++)
			for(j = 0;j < V; j++)
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
	
	printSolution(reach);
}

void printSolution(int reach[][V])
{
	printf("Following matrix is transitive closure of the given graph\n");
	for(int i = 0;i < V; i++)
	{
		for(int j = 0;j < V; j++)
			printf("%d ",reach[i][j]);
		printf("\n");
	}
}

int main()
{
	int graph[V][V] = { {	1,	1,	0,	1},
						{	0,	1,	1,	0},
						{	0,	0,	1,	1},
						{	0,	0,	0,	1}};
	transitiveClosure(graph);
	return 0;
}

	
	
