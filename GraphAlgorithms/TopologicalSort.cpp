/*
TOPOLOGICAL SORT
Topological sorting for Directed Acyclic graph(DAG) is a linear ordering of vertices such that for every directed edge uv,
vertex u comes before vertex v in the ordering. Topological sorting for a graph is not possible if graph is not DAG.
TOPOLOGICAL SORTING VS. DEPTH FIRST SEARCH(DFS)
In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting, we need to print
a vertex before its adjacent vertices. For example, in the given graph, the vertex '5' should be printed before vertex '0',
but unlike DFS, the vertex '4' should also be printed before vertex '0'.So topological sorting is different from DFS. 
Algorithm to find topological sort:
We can modify DFS to find Topological sorting of a graph. In DFS, we start from a vertex, we first print it, and then 
recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack.We don't print the vertex 
immediately, we first recursively call topological sorting for all adjacent vertices, then push it to a stack.Finally,
print contents of the stack.Note that a vertex is pushed to the stack only when all of its adjacent vertices(and their 
adjacent vertices and so on) are already on stack.
*/
#include<iostream>
#include<list>
#include<stack>
using namespace std;

// Class to represent graph
class Graph
{
	int V; // number of vertices
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V); // constructor
	void addEdge(int u, int v);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	
	list<int>::iterator itr;
	for(itr = adj[v].begin(); itr!=adj[v].end();itr++)
		if(!visited[*itr])
			topologicalSortUtil(*itr,visited,Stack);
	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i = 0;i < V; i++)
		visited[i] = false;
	for(int i = 0;i < V; i++)
		if(visited[i] == false)
			topologicalSortUtil(i,visited,Stack);
	while(Stack.empty()==false)
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

// Driver program
int main()
{
	Graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	cout<<" Following is the topological sort of the given graph \n";
	g.topologicalSort();
	return 0;
}

/*
Time Complexity of the algorithm is O(V+E).

*/
