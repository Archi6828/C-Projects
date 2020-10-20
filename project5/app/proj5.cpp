// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 3/7/2020

#include "proj5.hpp"
#include <iostream>

// As a reminder, for this project, edges have positive cost, g[i][j] = 0 means no edge.
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
    std::vector<bool>intree(graph.size(), false);//tracks if element is visited
    std::vector<unsigned>parent(graph.size(), -1); //tracks the parent nodes
    //keeps track of the shortest distances
    std::vector<unsigned> dist(graph.size(), std::numeric_limits<int>::max());
    dist[0] = 0;
    int u = 0;
    while(std::count(intree.begin(), intree.end(), false))
    {
        //int u;

        MyPriorityQueue<unsigned> mindist;
        for(int s = 0; s < dist.size(); s++)
        {
            if(intree[s] == false)
            {
                mindist.insert(dist[s]);
            }
        }
        int smallest;
        int MINindex = 0;
        smallest = mindist.min(); //smallest distance 
        for(int i = 0; i < dist.size(); i++)
        {
            if(dist[i] == smallest && intree[i] == false)
            {
                MINindex = i; //corresponding index of smallest distance
                break;
            }
        }
       
        u = MINindex;
        intree[u] = true;
        for(int v = 0; v < graph[u].size(); v++) // all adj vertices to u
        {
            if(dist[v] >  graph[u][v] && v != u && intree[v] == false)
            {
                dist[v] = graph[u][v]; 
                parent[v] = u;
            }
        }
    }

    std::vector<Edge> mst;
    //update mst
    for(int w = 0; w < parent.size(); w++)
    {
        if(w != 0)
        {
            Edge e(parent[w], w, dist[w]);    
            mst.push_back(e);
        }
    }
	return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.  
unsigned mstCost(const std::vector<Edge> & vE) 
{
	unsigned sum =0;
	for(auto e: vE)
	{
		sum += e.weight;
	}
	return sum;
}
