// Archita Bathole
// abathole
// 44633605
// 1/31/2020

#include "proj2.hpp"
#include "LLQueue.hpp"

#include <vector>

void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{  
    numShortestPaths[start] = 1; 

    LLQueue<unsigned>level; 
    level.enqueue(start);
    
    int counter = 0;
    int levelNum = 1; //keeps track of level number
    
    LLQueue<unsigned> vInLevel;
    vInLevel.enqueue(1);
 
    while(!level.isEmpty()) //for each level of vectors
    {            
        if(counter == vInLevel.front())
        {
            levelNum += 1; //update level
            counter = 0;
            vInLevel.dequeue();
        }

        LLQueue<unsigned> nextLevel; //store vertices of next level in new LLQ
        
        for(unsigned v: friends[level.front()]) //for each adjacent vertex
        {
            if(v != start && pathLengths[v] == 0) //not visited
            {
                pathLengths[v] = levelNum; //mark visited with path length
                nextLevel.enqueue(v);
            }
            
            //capture all shortest paths
            if(pathLengths[v] < pathLengths[level.front()])
            {
                numShortestPaths[level.front()] += numShortestPaths[v];
            }
        }
        
        //add next level of vertices
        vInLevel.enqueue(nextLevel.size());
        while(!nextLevel.isEmpty())
        {
            level.enqueue(nextLevel.front());
            nextLevel.dequeue();
        }
        level.dequeue(); //for all vertices in level
    
        counter+= 1;
    }
}
