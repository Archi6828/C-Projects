// Archita Bathole
// abathole
// 44633605
// 1/31/2020

#include "gtest/gtest.h"
#include "LLQueue.hpp"
#include "proj2.hpp"


namespace{


// NOTE:  these are not intended as exhaustive tests.
	// This should get you started testing.
	// You should make your own additional tests for both queue
	// and for the social network question.
	// VERY IMPORTANT:  if your LLQueue is not templated, or if 
	//		it is not linked-list based, your score for this project
	//		will be zero.  Be sure your LLQueue compiles and runs 
	// 		with non-numeric data types. 

TEST(QueueTest, QueueTest1)
{
	LLQueue<int> a;
	a.enqueue(5);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, QueueTest2)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	EXPECT_TRUE( a.front() == 5 );
}


TEST(QueueTest, QueueTest3)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.front() == 3 );
}

TEST(QueueTest, QueueSIZE)
{
    LLQueue<int> a;
    EXPECT_TRUE( a.size() == 0 );
    a.enqueue(5);
    a.enqueue(3);
    EXPECT_TRUE( a.size() == 2 );
    a.dequeue();
    EXPECT_TRUE( a.size() == 1 );
}//SIZE

//STRINGS
TEST(QueueTest, STRQueueTest1)
{
    LLQueue<std::string> a;
    a.enqueue("FIVE");
    EXPECT_TRUE( a.front() == "FIVE" );
}

TEST(QueueTest, STRQueueTest2)
{
    LLQueue<std::string> a;
    a.enqueue("WEEEEE");
    a.enqueue("KOALA");
    EXPECT_TRUE( a.front() == "WEEEEE" );
}


TEST(QueueTest, STRQueueTest3)
{
    LLQueue<std::string> a;
    a.enqueue("A");
    a.enqueue("BEE");
    a.dequeue();
    a.enqueue("MANGO");
    a.dequeue();
    EXPECT_TRUE( a.front() == "MANGO" );
}

TEST(QueueTest, STRemptyQueueTest2)
{
    LLQueue<std::string> a;
    a.enqueue("WEEEEE");
    a.dequeue();
    try
    {
        a.dequeue();
    }
    catch(const QueueEmptyException& e)
    {
        EXPECT_TRUE(e.getMessage() == "Empty queue.");
    }
}

TEST(QueueTest, STRemptyFRONTQueueTest2)
{
    LLQueue<std::string> a;
    a.enqueue("WEEEEE");
    a.dequeue();
    try
    {
        a.front();
    }
    catch(const QueueEmptyException& e)
    {
        EXPECT_TRUE(e.getMessage() == "Access to empty queue.");
    }
}



TEST(GraphTest, GraphTest1)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2}, {0,3}, {0,3}, {1,2}
	};
		std::vector<unsigned> pathLengths(4);
	std::vector<unsigned> numShortestPaths(4);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}

TEST(GraphTest, STARTGraphTest1)
{
    std::vector< std::vector<unsigned> > g1 = {
        {1,2}, {0,3}, {0,3}, {1,2}
    };
        std::vector<unsigned> pathLengths(4);
    std::vector<unsigned> numShortestPaths(4);

    countPaths(g1, 3, pathLengths, numShortestPaths);

    std::vector<unsigned> expPathLengths = {2, 1, 1, 0};
    std::vector<unsigned> expNumSP = {2, 1, 1, 1};

    EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}


TEST(GraphTest, GraphTest2)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5}, {0, 5}, {3, 4}
	};
	
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1};

    EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

TEST(GraphTest, STARTGraphTest2)
{
    std::vector< std::vector<unsigned> > g1 = {
        {1, 2, 4}, {0,3}, {0,3}, {1,2,5}, {0, 5}, {3, 4}
    };

    std::vector<unsigned> pathLengths(6);
    std::vector<unsigned> numShortestPaths(6);

    countPaths(g1, 4, pathLengths, numShortestPaths);

    std::vector<unsigned> expPathLengths = {1, 2, 2, 2, 0, 1};
    std::vector<unsigned> expNumSP = {1, 1, 1, 1, 1, 1};

    EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

TEST(GraphTest, GraphTest3)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
	};
	
	std::vector<unsigned> pathLengths(8);
	std::vector<unsigned> numShortestPaths(8);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2, 2, 3};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1, 1, 3};

    EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}

TEST(GraphTest, STARTGraphTest3)
{
    std::vector< std::vector<unsigned> > g1 = {
        {1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
    };

    std::vector<unsigned> pathLengths(8);
    std::vector<unsigned> numShortestPaths(8);

    countPaths(g1, 5, pathLengths, numShortestPaths);

    std::vector<unsigned> expPathLengths = {2, 2, 2, 1, 1, 0, 2, 2};
    std::vector<unsigned> expNumSP = {1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}


}
