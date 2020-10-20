// Archita Bathole
// abathole
// 44633605
// 1/20/2020

#include "gtest/gtest.h"
#include "proj1.hpp"
#include "ver.hpp" 
#include <map>
#include <string>


/*
 
Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.

 */


namespace{

TEST(SimpleCases, PotPanBib){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "PAN", "BIB", puzzle) ) ;
}

TEST(SimpleCases, NeatFind){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle) );
} // end test two, "NeatFind"


TEST(SimpleCases, FirstNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, Solution){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("GO", "CAT", "IG", puzzle);
     EXPECT_TRUE( p1 &&  gradeYesAnswer("GO", "CAT", "IG", puzzle) );
}

TEST(SimpleCases, LeadingZero){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("CAT", "GO", "IPG", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("CAT", "GO", "IPG", puzzle) );
}

TEST(SimpleCases, s3LengthisMore){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "HAN", "TITB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "HAN", "TITB", puzzle) );
}

TEST(SimpleCases, longer){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("L", "LLLL", "LLLLLL", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("L", "LLLL", "LLLLLL", puzzle) );
}

TEST(SimpleCases, tendigits){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("ABCDEF", "GHI", "KITE", puzzle);
    EXPECT_FALSE( p1 );
}


} // end namespace
