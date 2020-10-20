// Archita Bathole
// abathole
// 44633605
// 1/20/2020

#include "proj1.hpp"
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>

// recursive helper function to generate different digit sequences 
void findSolution(int lettersSize,bool& found, std::map<char,
unsigned> & mapping, std::stack<int>& order, std::vector<int> & nums,
std::set<char>& letters, std::vector<std::string>& str);

//cheks if the digit sequence is valid
bool testSolution(std::map<char,unsigned> & mapping,
std::vector<std::string>& str);

bool puzzleSolver(std::string s1, std::string s2, std::string s3,
std::map<char, unsigned> & mapping)
{
    //This function identifies the unique characters in strings
    //s1, s2, s3 and calls the recursive function (findSolution).

    std::vector<int> nums = {0,1,2,3,4,5,6,7,8,9};//stores distinct digits (0-9)
   
    std::vector<std::string> str = {s1, s2, s3};
   
    std::set<char> letters; //stores the unique letters from all 3 strings
    for(std::string s : str)
    {   
        for(int index = 0; index < s.length(); index++)
            letters.insert( s[index] );
    }

    //call recursive helper function
    std::stack<int> order; //stores digit sequence
    bool indicator = false; 
   
    findSolution(letters.size(), indicator, mapping, order, nums, letters, str);
  
    if(indicator == true)
    {
       return true; 
    }
    return indicator;
}

void findSolution(int lettersSize, bool& found, std::map<char,
unsigned> & mapping, std::stack<int>& order, std::vector<int> & nums,
std::set<char>& letters, std::vector<std::string>& str){
//This function is similar to the multiple recursion summation puzzles 
//algorithm from textbook(ch.3.5)
    
    for(int i = 0; i < nums.size(); i++) // for every number in nums
    {
        int n = nums[i];
        nums.erase(nums.begin() + i);  //remove number from nums
        order.push(n);      //add number to order
        
        if(lettersSize == 1)
        {
            //add char:int to mapping
            std::stack<int> copyOrder = order;
            for(char c : letters)
            {
                mapping[c] = copyOrder.top();    
                copyOrder.pop();   
            }
 
            found = testSolution(mapping, str);  //check solution
            if(found) 
                return; //solution found
        }
        else
            findSolution(lettersSize - 1, found, mapping, order, nums, letters,
                         str);
        if(found)
            return; //skip loop iterations
        nums.insert(nums.begin() + i, n);   //add number back into nums
        if(!order.empty())
            order.pop();     //remove number from order
    }
}

bool testSolution( std::map<char,unsigned> & mapping,
std::vector<std::string>& str){
//This function checks if the particular digit sequence is a valid solution.
 
    //stores the chars' corresponding int values
    std::stringstream strNum;

    for(std::string s : str)
    {
        for(int index = 0; index < s.length(); index++)
        {
            strNum << mapping.at( s[index] );
        }
        strNum << " ";
    }

    //store int values separately
    unsigned int s1n, s2n, s3n;
    
    strNum >> s1n;
    strNum >> s2n;
    strNum >> s3n;
    
    //verify sum
    if( (s1n + s2n) == s3n )
        return true;
    return false;
}

