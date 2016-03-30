
#include <iostream>
#include "Graph.cpp"

using namespace std;

//A class to find out if an undirected graph has a cycle or not
class Cycle {
private:
	//An array to keep track of visited vertices
	bool *visited;

	//A flag to mark if there is a cycle in a graph or not
	bool hasCycle;

	//Number of vertices
	int n;

	//Keep track of parent of a vertex in DFS traversal
	int *edgeTo;

	//last edge in the cycle
	int i;
	int j;

public:
	Cycle(Graph & g) : n( g.N() ) {
		//Allocate space for the visited array
		visited = new bool[n];

		//Iniialize the vertices as not visited
		for(int v = 0; v < n; v++) {
			visited[v] = false;
		}

		//Initialize the flag as false
		hasCycle = false;

		//Allocate space for edgeTo array
		edgeTo = new int[n];

		//Visit all the unvisited vertices	
		for(int s = 0; s < n; s++ ) {
			//Do a DFS from an unvisited vertex
			if( !visited[s] )
				dfs(g, s, s);	
		}
	}

	//DFS is called with v and u (which is parent of v)
	void dfs(Graph & g, int v, int u) {
		//Mark v as visited
		visited[v] = true;

		//Visit the neighbors of v
		for(LinkedList<int>::iterator it = g.adjList(v).begin(); it != g.adjList(v).end(); it ++) {

			//Neighbor of v
			int w = *it;
			
			//if w is not visited -- start a DFS from w
			if( !visited[w] ) {

				//Call DFS with w and it's parent
				dfs(g, w, v);
				edgeTo[w] = v;
			}
			//if w is visited and w is not v's parent
			//Since the graph is undirected v's parent is also on v's adjacency list
			else if( w != u ) { 
				hasCycle = true;
				j = w;
				i = v;
			}	

		}
	}

	//Returns if the graph has a cycle or not
	bool HasCycle() {
		return hasCycle;
	}

	//If there is a cycle -- this returns the cycle
	void getCycle(LinkedList<int> & cycle) {

		if( hasCycle )	{
			cycle.add( i );
		
			for(int x = j; x != i; x = edgeTo[x]) {
				cycle.add(x);
			}
			cycle.add( i );
		}

	}

	//The destructor
	~Cycle() {
		delete [] visited;
		delete [] edgeTo;
	}	
};

//Test if an undirected graph has a cycle or not
int main() {
	Graph g("graph3.txt");

	Cycle cycle(g);

	if( cycle.HasCycle() ) {
		cout<<"The graph has a cycle.\n";
	
		LinkedList<int> lList;
		cycle.getCycle(lList);	
		cout<<"The cycle is: \n";
		for(LinkedList<int>::iterator it = lList.begin(); it != lList.end(); it ++) {
			
			cout<<*it<<" ";
		}	
		cout<<endl;
	}
	else {
		cout<<"The graph has no cycle.\n";
	}
	return 0;
}
