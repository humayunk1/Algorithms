/* This file contains an implementation of Depth First Search traversal of an undirected graph
 * Code by: Humayun Kabir, humayun.k1@gmail.com */

#include<iostream>
#include "Graph.cpp"

using namespace std;

class DFS {
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
	DFS(Graph & g, int s) : n(g.N()), s(s) {
		//allocate space for marked array
		marked = new bool[n];

		//initialize the vertices as not visited 
		for(int v = 0; v < n; v++)
			marked[v] = false;

		//allocate space for edgeTo array
		edgeTo = new int[n];

		//do a depth first search from the source vertex s
		dfs(g, s);
	}

	void dfs(Graph & g, int v) {
		//mark v as visited
		marked[v] = true;

		//visit the neighbors of v
		for(LinkedList<int>::iterator it = g.adjList(v).begin(); it != g.adjList(v).end(); it ++) {

			int w = *it;
			//if w is not visited - do dfs from w
			if( !marked[w] ) {
				dfs(g, w);
			
				//update edgeTo array -- this store the parent of w
				edgeTo[w] = v;				
			}
		}
	}


	//returns if there is a path from s to v or not
	bool hasPathTo(int v) {
		return marked[v];
	}

	//if there is a path from s to v the path is contained in path
	void pathTo(int v, LinkedList<int> & path) {

		if( !marked[v] ) {
			return;
		}

		for(int x = v; x != s; x = edgeTo[x] )
			path.add(x);
		path.add(s);
	}
};


//Test the dfs search implementation of a graph
int main() {

        Graph g("graph2.txt");


        int source = 5;
        DFS dfs(g, source);

        cout<<"Number of vertices in g: "<<g.N()<<endl;
        int v = 1;

        if( dfs.hasPathTo(v) ) {
                cout<<"There is path from: "<< source<<" to: "<< v<<endl;
                cout<<"The path is: "<<endl;

                LinkedList<int> path;
                dfs.pathTo(v, path);
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
