// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/12/2020

#include "gtest/gtest.h"
#include "Wordset.hpp"
#include "proj3.hpp"
#include <string>
#include <fstream>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.


TEST(HashFunctionTest, Hf1)
{
	int hv = hashFunction("dbc", 37, 100000);
	int shouldBe = 3*37*37 + 1*37 + 2;
	EXPECT_TRUE(hv == shouldBe);
}

TEST(HashFunctionTest, RevHf1)
{
    int hv = strtonum("dbc", 37, 100000);
    int  str = numtohash(hv,37,100000);
    EXPECT_TRUE(str == hashFunction("dbc", 37, 100000));
}

TEST(HashFunctionTest, Hf2)
{
    int hv = hashFunction("dbc", 26, 100000);
    int shouldBe = 3*26*26 + 1*26 + 2;
    EXPECT_TRUE(hv == shouldBe);
}


TEST(TableTest, Tab1)
{
	WordSet ws;
	ws.insert("dbc");
	EXPECT_TRUE(ws.contains("dbc"));
}

TEST(TableTest, FALSETab1)
{
    WordSet ws;
    EXPECT_FALSE(ws.contains("dbc"));
}

TEST(TableTest, CONTAINSTab131)
{
    WordSet ws;
     ws.insert("sleepy");
    ws.insert("happy");
    ws.insert("dopey");
     ws.insert("ey");
      ws.insert("dope");
       ws.insert("pey");
        ws.insert("doy");
         ws.insert("yay");
          ws.insert("wday");
           ws.insert("poy");
            ws.insert("wesgw");
             ws.insert("dywef");
              ws.insert("dwewgwvvf");
EXPECT_TRUE(ws.contains("dwewgwvvf"));
EXPECT_TRUE(ws.contains("ey"));
EXPECT_TRUE(ws.contains("dope"));
EXPECT_TRUE(ws.contains("pey"));
EXPECT_TRUE(ws.contains("doy"));
EXPECT_TRUE(ws.contains("yay"));
EXPECT_TRUE(ws.contains("wday"));
EXPECT_TRUE(ws.contains("poy"));
EXPECT_TRUE(ws.contains("wesgw"));
EXPECT_TRUE(ws.contains("dywef"));


}

TEST(ResizeTest, Tab2)
{
	WordSet ws;
	ws.insert("sleepy");
	ws.insert("happy");
	EXPECT_TRUE(ws.getCapacity() == 11);
	ws.insert("dopey");
	EXPECT_TRUE(ws.getCapacity() == 23);
	ws.insert("sneezy");
	ws.insert("datalink");
	ws.insert("australia");
	ws.insert("guacamole");
	ws.insert("phylum");
	EXPECT_TRUE(ws.getCount() == 8);
    EXPECT_TRUE(ws.contains("happy"));
	EXPECT_TRUE(ws.contains("dopey"));
	// 23
}


TEST(ResizeTest, Tab3)
{
	WordSet ws;
	ws.insert("sleepy");
	ws.insert("happy");
	EXPECT_TRUE(ws.getCapacity() == 11);
	ws.insert("dopey");
	ws.insert("sneezy");
	EXPECT_TRUE(ws.getCapacity() == 23);
	ws.insert("datalink");
	ws.insert("australia");
	ws.insert("guacamole");
	ws.insert("phylum");
	EXPECT_TRUE(ws.contains("happy"));
	EXPECT_TRUE(ws.contains("sleepy"));
    EXPECT_TRUE(ws.contains("dopey"));
	ws.insert("one");
	ws.insert("two");
	ws.insert("three");
	ws.insert("four");
	ws.insert("five");
	EXPECT_TRUE(ws.getCapacity() == 83);
}

TEST(SampleTest, Abandoning)
{
	WordSet words;
	words.insert("abandoning");
	EXPECT_TRUE(words.contains("abandoning"));
}


TEST(TableTest, CONTAINS)
{
    WordSet words;
    std::ifstream in("words.txt");
    loadWordsIntoTable(words, in);
    
    EXPECT_FALSE(words.contains("unt"));
}

TEST(ConvertWords, AntToArt)
{
	WordSet words;
	std::ifstream in("words.txt");
  	loadWordsIntoTable(words, in);
    //words.insert("tealL");
    //words.insert("heal");
 	std::string r = convert("ant", "art", words);
 	 std::cout << "PATH: " << r << std::endl;

    EXPECT_TRUE(r == "ant --> art");
}

TEST(ConvertWords, batTosit)
{
    WordSet words;
    std::ifstream in("words.txt");
    loadWordsIntoTable(words, in);
    //words.insert("tealL");
    //words.insert("heal");
    std::string r = convert("bat", "sit", words);
     std::cout << "PATH: " << r << std::endl;

    EXPECT_TRUE(r == "bat --> bit --> sit");
}


TEST(ConvertWords, MantoApe)
{
    WordSet words;
    std::ifstream in("words.txt");
    loadWordsIntoTable(words, in);
    //words.insert("tealL");
    //words.insert("heal");
    std::string r = convert("man", "ape", words);
    std::cout << "PATH: " << r << std::endl;
    std::cout << words.contains("mat") << std::endl;
    std::cout << words.contains("oat") << std::endl;
    std::cout << words.contains("opt") << std::endl;
    std::cout << words.contains("apt") << std::endl;
    
    EXPECT_TRUE(r == "man --> mat --> oat --> opt --> apt --> ape");
}

TEST(ConvertWords, headTotail)
{
    WordSet words;
    std::ifstream in("words.txt");
    loadWordsIntoTable(words, in);
    //words.insert("tealL");
    //words.insert("heal");
    std::string r = convert("head", "tail", words);
     std::cout << "PATH: " << r << std::endl;
    EXPECT_TRUE(r == "head --> heal --> teal --> tell --> tall --> tail");
}

TEST(ConvertWords, AntToEat)
{
	WordSet words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);

 	std::string r = convert("ant", "eat", words);
 	 std::cout << "PATH: " << r << std::endl;
    EXPECT_TRUE(r == "ant --> aft --> oft --> oat --> eat");
 	// of course, if yours outputs a way to do this with exactly 5 words, it is also correct.
 	// So maybe confirm if yours is right or not if this test appears to be failing.
 	// I will be verifying it differently when I grade this assignment.
}
}
