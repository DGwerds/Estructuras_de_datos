#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
#define V 4

bool bfs(int rGraph[V][V], int s, int t, int parent[]){
	bool visited[V];
	memset(visited, 0, sizeof(visited));		// 1
    
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

    while (q.empty() == false){			
		int u = q.front();
	    q.pop(); 
	    for (int v=0; v<V; v++){
			if (visited[v]==false && rGraph[u][v] > 0){
			    q.push(v);
			    parent[v] = u;
			    visited[v] = true;
		    }
	    }
	}
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t){
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];
		int parent[V];
		int max_flow = 0;
		while (bfs(rGraph, s, t, parent)){
	    	int path_flow = INT_MAX;
	    	for (v=t; v!=s; v=parent[v]){
		    	u = parent[v];
		    	path_flow = min(path_flow, rGraph[u][v]);
	    	}
	    	for (v=t; v != s; v=parent[v]){
		    	u = parent[v];
		    	rGraph[u][v] -= path_flow;
		    	rGraph[v][u] += path_flow;
	    	}
	    max_flow += path_flow;
	}
    return max_flow;
}

int main(){
	int graph[V][V] = {	{0,	4,	2,	0},
						{0,	0,	3,	1},
						{0,	0,	0,	6},
						{0,	0,	0,	0}};
	
	cout << "El flujo máximo posible es: " << fordFulkerson(graph, 0, V-1)<<"\n";
    return 0;
}
