// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/19/2020

#include "gtest/gtest.h"
#include "MyAVLTree.hpp"
#include "proj4.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// The four tests marked "CheckPoint" are going to be run
// on your submission for the checkpoint code.
// This is worth one-sixth of your grade on the assignment
// and is due at the time marked "checkpoint"


// None of the "checkpoint" tests require you to have
// AVL functionality OR the counting of words.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement AVL functionality
// for the full project.

// BE SURE TO FULLY TEST YOUR CODE.
// This means making sure your templating is not hard-coding for 
// a specific type, that every function is called somewhere in 
// your test cases, etc. 
// There will NOT be a project 2 style redo for this;  if your 
//  code does not compile, your score will be a zero. 


TEST(CheckPoint, CheckPoint_FindTheRoot)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) );
}

TEST(CheckPoint, CheckPoint_FindOneHop)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) );
}
/*
TEST(CheckPoint, FINDCheckPoint_FindOneHop)
{
    MyAVLTree<int, std::string> tree;
     EXPECT_TRUE( tree.isEmpty());
    tree.insert(5, "foo");
    tree.insert(10, "bar");
    
    EXPECT_FALSE( tree.isEmpty());

    EXPECT_TRUE( tree.find(5) == "foo");
    EXPECT_TRUE( tree.find(10) == "bar");

    EXPECT_THROW({ 
        try
        {
            tree.find(123);
        }
        catch(const ElementNotFoundException& e)
        {
            EXPECT_TRUE("NOT IN TREE!" == e.getMessage());
            throw;
        }
        }, ElementNotFoundException
        );
}
*/
TEST(CheckPoint, CheckPoint_FindTwoHops)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) );
}


TEST(CheckPoint, CheckPoint_Add5)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_TRUE( tree.size() == 5 );
}


TEST(CheckPoint, LEFTSIDE_AddTONS)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(20, "twenty");
     tree.postOrder();
    tree.insert(19, "nineteem");
     tree.postOrder();
    tree.insert(18, "eighteen");
     tree.postOrder();
    tree.insert(17, "seventeen");
     tree.postOrder();
    tree.insert(16, "sixteen");
     tree.postOrder();
    tree.insert(15, "fifteen");
    tree.postOrder();
    tree.insert(14, "fourteen");
    tree.postOrder();
    tree.insert(13, "thirteen");
    tree.postOrder();
    tree.insert(12, "twelve");
    tree.postOrder();
    tree.insert(11, "eleven");

    EXPECT_TRUE( tree.size() == 10 );
    tree.postOrder(); 
    std::vector<int> trav = tree.postOrder();
    std::vector<int> expected = {11,12,14,16,15,13,18,20,19,17};
    EXPECT_TRUE( trav == expected );

}


TEST(CheckPoint, ROTATION3_AddTONS)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
     tree.preOrder();
   // tree.insert(3, "sna");
     //tree.preOrder();
    tree.insert(10, "bar");
     tree.preOrder();
   // tree.insert(2, "two");
     //tree.preOrder();
    tree.insert(6, "six");
     tree.preOrder();
    tree.insert(16, "sixteen");
    tree.preOrder();
    tree.insert(13, "13teen");
    tree.preOrder();
    tree.insert(12, "twelve");
    tree.preOrder();
    tree.insert(19, "nineteen");
    tree.preOrder();
    tree.insert(20, "twenty");

    EXPECT_TRUE( tree.size() == 8 );
    tree.preOrder();
    std::vector<int> trav = tree.preOrder();
    std::vector<int> expected = {10,6,5,13,12,19,16,20};
    EXPECT_TRUE( trav == expected );

}


TEST(CheckPoint, R4_AddTONS)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(15, "fifteen");
     tree.preOrder();
    tree.insert(9, "nine");
     tree.preOrder();
    tree.insert(11, "eleven");
     tree.preOrder();
    tree.insert(14, "fourteen");
     tree.preOrder();
    tree.insert(12, "twelve");
     tree.preOrder();
    tree.insert(1, "one");
    tree.preOrder();
    tree.insert(3, "five");
    tree.preOrder();
    tree.insert(8, "eight");
    tree.preOrder();
    tree.insert(7, "seven");
    tree.preOrder();  
    tree.insert(13, "thriteen");
    tree.preOrder();
    tree.insert(20, "twenty");
    
    EXPECT_TRUE( tree.size() == 11);
    tree.preOrder();
    std::vector<int> trav = tree.preOrder();
    std::vector<int> expected = {11,3,1,8,7,9,14,12,13,15,20};
    EXPECT_TRUE( trav == expected );

}


TEST(CheckPoint, REPEAT_AddTONS)
{
    MyAVLTree<std::string, int > tree;
   // tree.insert("ten", 10);
     //tree.preOrder();
    tree.insert("5", 5);
     tree.preOrder();
    tree.insert("6", 6);
     tree.preOrder();
    tree.insert("9", 9);
     tree.preOrder();
    tree.insert("7", 7);
     tree.preOrder();
//    tree.insert("5", 5);
    tree.preOrder();
    tree.insert("3", 3);
    tree.preOrder();
//    tree.insert("5", 5);
    tree.preOrder();
    tree.insert("8", 8);
    tree.preOrder();
//    tree.insert("twenty", 20);
    
    EXPECT_TRUE( tree.size() == 6 );
  //  tree.preOrder();
    std::vector<std::string> trav = tree.preOrder();
    std::vector<std::string> expected = {"6", "5" , "3", "8", "7", "9"};
    EXPECT_TRUE( trav == expected );

}

TEST(CheckPoint, RIGHTSIDE_AddTONS)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
     //tree.preOrder();
    tree.insert(3, "sna");
     //tree.preOrder();
    tree.insert(10, "bar");
     //tree.preOrder();
    tree.insert(12, "twelve");
     //tree.preOrder();
    tree.insert(15, "fifteen");
    tree.preOrder();
    tree.insert(16, "sixteen");
    tree.preOrder();
    tree.insert(17, "seventeen");
    tree.preOrder();
    tree.insert(18, "eighteen");
    tree.preOrder();
    tree.insert(19, "nineteen");
    tree.preOrder();
    tree.insert(20, "twenty");
    
    EXPECT_TRUE( tree.size() == 10 );
    tree.preOrder();
   std::vector<int> trav = tree.preOrder();
   std::vector<int> expected = {12, 5, 3, 10, 18, 16, 15, 17 ,19, 20};
    EXPECT_TRUE( trav == expected );

}


TEST(PostCheckPoint, InOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PreOrderTraversal)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "sna");
    tree.insert(10, "bar");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");

    std::vector<int> trav = tree.preOrder();
    std::vector<int> expected = {5, 3 ,12, 10, 15};
    EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PostOrderTraversal)
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "sna");
    tree.insert(10, "bar");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");

    std::vector<int> trav = tree.postOrder();
    std::vector<int> expected = {3, 10, 15, 12, 5};
    EXPECT_TRUE( trav == expected );
}


TEST(PostCheckPoint, JackSparrow)
{
	std::string quote = "I'm dishonest, and a dishonest man you can "; 
	quote += "always trust to be dishonest. Honestly. It's the honest ";
    quote += "ones you want to watch out for, because you can never ";
	quote += "predict when they're going to do something incredibly... stupid.";


	std::istringstream stream( quote );

	MyAVLTree<std::string, unsigned> tree;

	countWords(stream, tree);
   
	EXPECT_TRUE(tree.find("dishonest") == 3);
}

}
