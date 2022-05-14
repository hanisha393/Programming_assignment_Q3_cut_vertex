// C++ program to find cutvertex in an undirected graph
#include <bits/stdc++.h>
using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points
void find_cutvertex(vector<int> adj[], int u, bool visited[],
			int discovery[], int low[], int& count, int parent,
			bool isCV[])
{
	int v;
	int children = 0;

	// Mark the vertex as visited
	visited[u] = true;

	// Initialize discovery time and low value
	discovery[u] = low[u] = ++count;

	// Go through all vertices adjacent to this
	for (int i=0;i<adj[u].size();i++) 
	{
		v = adj[u][i];

		if (!visited[v]) 
		{
			children++;
			find_cutvertex(adj, v, visited, discovery, low, count, u, isCV);
			low[u] = min(low[u], low[v]);
			if (parent != -1 && low[v] >= discovery[u])
				isCV[u] = true;
		}

		else if (v != parent)
			low[u] = min(low[u], discovery[v]);
	}

	if (parent == -1 && children > 1)
		isCV[u] = true;
}

void cutvertex(vector<int> adj[], int V)
{
	int discovery[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool iscutvertex[V] = { false };
	int time = 0, par = -1;

	for (int u = 0; u < V; u++)
		if (!visited[u])
			find_cutvertex(adj, u, visited, discovery, low,
				time, par, iscutvertex);

	// Printing the cut vertices
	for (int u = 0; u < V; u++)
		if (iscutvertex[u] == true)
			cout << u << " ";
}
int main()
{
	cout << "\nCut Vertices in given graph \n";
	int V = 9;
	vector<int> adj[V];
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[0].push_back(2);
	adj[2].push_back(0);
	adj[3].push_back(1);
	adj[1].push_back(3);
	adj[4].push_back(1);
	adj[1].push_back(4);
	adj[6].push_back(1);
	adj[1].push_back(6);
	adj[3].push_back(5);
	adj[5].push_back(3);
	adj[4].push_back(5);
	adj[5].push_back(4);
	adj[6].push_back(7);
	adj[7].push_back(6);
	adj[7].push_back(8);
	adj[8].push_back(7);
	adj[6].push_back(8);
	adj[8].push_back(6);
	cutvertex(adj, V);

}

