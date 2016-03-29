/* This file contains an implementation of breadth first search of an undirected graph 
 * Code by: Humayun Kabir, humayun.k1@gmail.com */

#include <iostream>
#include "Graph.cpp"
#include "queue.cpp"

using namespace std;

class BFS {
private:
	//number of vertices
	int n;

	//the source vertex
	int s;

	//an array to keep track of visited vertices
	bool *marked;

	//gives parent vertex of vistied vertices
	int *edgeTo;

public:
	//Constructor 
	BFS(Graph & g, int s) : n(g.N()), s(s) {
		marked = new bool[n];

		//Initially all the vertices are unmakred or not visited
		for(int v = 0; v < n; v++)
			marked[v] = false;
	
		edgeTo = new int[n];

		//does a bfs from the source vertex s		
		bfs(g, s);
	}


	//bfs on a graph g from source vertex s
	void bfs(Graph & g, int t) {

		//Declare a queue of integers	
		Queue<int> que;	

		//insert the source t into the queue
		que.Enqueue(t);

		//mark t as visited
		marked[t] = true;

		//continue until the queue is empty
		while( !que.isEmpty() ) {

			//dequeue an element from the queue
			int v = que.Dequeue();

			//check all the neighbors of v
			for(LinkedList<int>::iterator it = g.adjList(v).begin(); it != g.adjList(v).end(); it ++) {
				//neighbor of v
				int w = *it;

				//if w is not visited
				if( !marked[w] ) {
					//insert w into the queue
					que.Enqueue( w );

					//mark w as visited
					marked[w] = true;

					//update edgeTo array 
					//w is reached from v --in other words edgeTo array gives parent of a vertex
					edgeTo[w] = v;
				}
			}
		}
	}

		
	//tests where there is a path to v from the source vertex s
	bool hasPathTo(int v) {
		return marked[v];
	}	

	//Returns a path from s to v
	//If there is no path - an empty linkedList is returned
	void pathTo(int v, LinkedList<int> & path) {

		if( !hasPathTo(v) )
			return;

		for(int x = v; x != s; x = edgeTo[x]) 
			path.add(x);
		path.add(s);

		return;
	}	

	//Destructor 
	~BFS() {
		delete [] marked;
		delete [] edgeTo;
	}	
};

//Test the bfs search implementation of a graph
int main() {

	Graph g("graph2.txt");

	
	int source = 5;
	BFS bfs(g, source);

	cout<<"Number of vertices in g: "<<g.N()<<endl;
 	int v = 1;	

	if(bfs.hasPathTo(v) ) {
		cout<<"There is path from: "<< source<<" to: "<< v<<endl;
		cout<<"The path is: "<<endl;

		LinkedList<int> path;
		bfs.pathTo(v, path);
		for( LinkedList<int>::iterator it = path.begin(); it != path.end(); it ++) {
			if( *it == source )
				cout<<*it;
			else
				cout<<"->"<<*it;
		}
		cout<<endl;
	}
	else
		cout<<"There is no path from: "<< source<<" to: "<< v<<endl;
	
	return 0;
}
