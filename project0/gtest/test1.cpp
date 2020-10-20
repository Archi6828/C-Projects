// Archita Bathole
// abathole
// 44633605
// 1/11/2020

#include "gtest/gtest.h"
#include "proj0.hpp"
#include <map>
#include <string>

namespace{

TEST(VerifySolution, First){
    std::string s1 = "POT";
    std::string s2 = "PAN";
    std::string s3 = "BIB";

    std::map<char, unsigned> solution = { {'A', 7}, {'B', 5}, 
        {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}

TEST(VerifySolution, Second){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test two

TEST(VerifySolution, Third){

    std::string s1 = "DING";
    std::string s2 = "BIG";
    std::string s3 = "DBNK";

    std::map<char, unsigned> solution = { {'D', 5}, {'I', 0}, {'N', 1}, {'G', 2}, {'B', 3}, {'K', 4}};

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // unequal string lengths (s1.length() != s2.length())

TEST(VerifySolution, ThirdReverse){

    std::string s1 = "BIG";
    std::string s2 = "DING";
    std::string s3 = "DBNK";

    std::map<char, unsigned> solution = { {'D', 5}, {'I', 0}, {'N', 1}, {'G', 2}, {'B', 3}, {'K', 4}};

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // unequal string lengths (s1.length() != s2.length())


TEST(VerifySolution, Fourth){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "GIP";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
} //output false

TEST(VerifySolution, FIFTH){

    std::string s1 = "CAT";
    std::string s2 = "GO";
    std::string s3 = "IG";

    std::map<char, unsigned> solution = { {'A', 3}, {'C', 0}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 2} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // leading zero

TEST(VerifySolution, FIFTHReverse){

    std::string s1 = "GO";
    std::string s2 = "CAT";
    std::string s3 = "IG";

    std::map<char, unsigned> solution = { {'A', 3}, {'C', 0}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 2} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // leading zero


TEST(VerifySolution, SIXTH){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'Z', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
} // letters not present in map

TEST(VerifySolution, SEVENTH){

    std::string s1 = "CAT";
    std::string s2 = "GO";
    std::string s3 = "IPG";

    std::map<char, unsigned> solution = { {'A', 7}, {'C', 0}, {'G', 6}, {'I', 1}, {'O', 4}, {'P', 3}, {'T', 2} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // leading zero (s3.length() == larger string in operands)

TEST(VerifySolution, SEVENTHReverse){

    std::string s1 = "GO";
    std::string s2 = "CAT";
    std::string s3 = "IPG";

    std::map<char, unsigned> solution = { {'A', 7}, {'C', 0}, {'G', 6}, {'I', 1}, {'O', 4}, {'P', 3}, {'T', 2} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // leading zero (s3.length() == larger string in operands)

TEST(VerifySolution, EIGHT){
    std::string s1 = "POT";
    std::string s2 = "HAN";
    std::string s3 = "TITB";

    std::map<char, unsigned> solution = { {'A', 8}, {'B', 7}, {'H', 5},
        {'I', 0}, {'N', 6}, {'O', 3}, {'P', 4}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} //s1 & s2 are length 3 but s3 is length 4

TEST(VerifySolution, NINE){
    std::string s1 = "PPP";
    std::string s2 = "PP";
    std::string s3 = "TIPA";

    std::map<char, unsigned> solution = { {'A', 8}, {'B', 7}, {'H', 5},
        {'I', 0}, {'N', 6}, {'O', 3}, {'P', 9}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} //s3 is longer than s1 and s2

TEST(VerifySolution, TEN){
    std::string s1 = "II";
    std::string s2 = "IIII";
    std::string s3 = "IIIIII";

    std::map<char, unsigned> solution = { {'A', 8}, {'B', 7}, {'H', 5},
        {'I', 0}, {'N', 6}, {'O', 3}, {'P', 4}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 
} // end namespace
