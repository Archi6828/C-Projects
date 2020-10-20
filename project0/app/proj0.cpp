// Archita Bathole
// abathole
// 44633605
// 1/11/2020

#include <map>
#include <string>
#include <sstream>
#include "proj0.hpp"

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{
    //This function checks whether the letters in s3 are the sum of the 
    //letters in strings s1 and s2.
    
    //put all 3 strings into sstream
    std::stringstream sstr;
    sstr << s1 + " ";
    sstr << s2 + " ";
    sstr << s3;
    unsigned int curStrNum = 1;

    std::stringstream strNum; //stores the chars' corresponding int values
    std::string curStr;
    unsigned int curStrLen;

    //repeat for loop until all three strings are verified
    while(curStrNum <= 3)
    {
        sstr >> curStr;
        curStrLen = curStr.length();

        for(int index = 0; index < curStrLen; index++)
        {
            //check if char is in map
            if(mapping.find( curStr[index] ) != mapping.end())
            {
                strNum <<  mapping.at(curStr[index]);
            }
            else //char not in map
            {
                return false;
            }
        }
        //update to next string
        strNum << " ";
        curStrNum++;
        curStrLen = 0;
        curStr = "";
    }

    //store int values separately
    unsigned int s1n, s2n, s3n;

    strNum >> s1n;
    strNum >> s2n;
    strNum >> s3n;

    //verify sum
    if( (s1n + s2n) == s3n )
    {
        return true;
    }

    return false;
}





