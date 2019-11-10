/**
Algorithm:
1) Create a set sptSet(shortest path tree set) that keeps track of vertices included in the shortest path tree, i.e 
whose minimum distnace from source is calculated and finalized. Initially this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign
distance 0 to the source vertex as it is picked first.
3) While sptSet doesn't include all vertices
  ...a) Pick a vertex u which is not there in sptSet and has a minimum distance value.
  ...b) Include u to sptSet.
  ...c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all the 
  adjacent vertices. For every adjacent vertex v, if the sum of distance value of u( from source), and weight of
  edge u-v, is less than the distance value of v, then update the distance value of v.
  */
  #include<limits.h>
  #include<stdio.h>
  #define V 9
  int minDistance(int dist[], bool sptSet[])
  {
    int min = INT_MAX,min_index;
    for(int v = 0;v < V ; v++)
      if(sptSet[v] == false && dist[v]<= min)
        min = dist[v], min_index = v;
    
    return min_index;
  }
  
  int printSolution(int dist[])
  {
    printf("Vertex \t\t Distance from Source\n");
    for(int i = 0;i< V; i++)
      printf("%d \t\t %d\n",i,dist[i]);
  }
  
  void dijkstra(int graph[V][V], int src)
  {
    int dist[V];
    bool sptSet[V];
    for(int i = 0;i<V; i++)
      dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for(int count = 0;count < V-1;count++)
    {
      int u = minDistance(dist,sptSet);
      sptSet[u] = true;
      for(int v = 0;v < V; v++)
        if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v])
          dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
 }
 
 int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 
