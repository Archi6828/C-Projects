// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/12/2020

#include "proj3.hpp"
#include "Wordset.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

// You should not need to change this function.
void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}


// You probably want to change this function.
std::string convert(std::string s1, std::string s2, const WordSet & words)
{

    std::map<std::string, std::set<std::string>> wordmap;
    findcombo(-1, s1,s2,words,wordmap);         //find combinations
      
    std::stack<std::string> path;
    path = BFS(wordmap,s1,s2);                  //find shortest path

    //reverse path into a string
    std::string strpath = "";
    std::stack<std::string> order;
    
    while(!path.empty())
    {
        order.push(path.top());
        path.pop();
    }

    while(!order.empty())         //reverse order
    {
        strpath += order.top();
        if(order.size() != 1)
            strpath += " --> ";
       order.pop();
    }
  
    return strpath; 
}

void findcombo(int index, std::string& s1, std::string& s2,
const WordSet & words, std::map<std::string,std::set<std::string>>& wordmap)
{
    std::string str;
    for(unsigned i = 0; i < s1.length(); i++)
    {
        if(i != index) //skip index just changed
        {
            for(unsigned l = 0; l < 26; l++)
            {       
                if(numtochar(l) != s1[i])  //not the same word
                {
                    str = s1.substr(0,i) + numtochar(l) + s1.substr(i + 1);
                   
                    //if check if word in words
                    if(words.contains(str))
                    {
                        bool first = false;
                        if(wordmap.count(s1) == 0)
                        {
                            first = true;
                            std::set<std::string> list;
                            wordmap.insert(std::make_pair(s1, list));
                        }
                      
                        bool loopFlag = false;
                        if(wordmap[s1].count(str) == 1)  //avoid word loops
                        {
                            loopFlag = true;
                        }
                        //add to set
                        std::set<std::string>& listref = wordmap[s1];
                        listref.insert(str);
                            
                        if(loopFlag != true)         //not in s1 set
                        {
                            findcombo(i, str,s2,words,wordmap);          
                        }
                   }
                }     
            }
        }    
    }
}

std::stack<std::string> BFS(std::map<std::string,std::set<std::string>>& 
wordmap, std::string& s1, std::string& s2)
{
    std::string s = s1;
    std::queue<std::stack<std::string>> list;
    std::stack<std::string> word;
    word.push(s1);
    list.push(word);

    std::set<std::string> discovered;
    discovered.insert(s1);

    while(!list.empty())
    {
        std::stack<std::string> path;
  
        //look through queue inside map        
        std::set<std::string> maplist;
        maplist = wordmap[ list.front().top()];            
        path = list.front();
        list.pop();
    
        for(std::string s: maplist)  //edges
        {
            std::stack<std::string> temp;
            temp = path;
               
            if(s == s2)
            {
                temp.push(s);        
                discovered.insert(s);       
                return temp;
            }
            //trak visitt         
            if(discovered.count(s) == 0)
            {
               discovered.insert(s); //mark visited    
               temp.push(s);
               list.push(temp);
            }   
       }
           
    }
    std::stack<std::string> ES;
    return ES;
}

void print(std::map<std::string,std::set<std::string>>& wordmap)
{
    for (auto const& pair: wordmap)
    {
        std::cout << pair.first << " : ";
        for(auto const& s: pair.second)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

}

char numtochar(int n)
{
    return "abcdefghijklmnopqrstuvwxyz"[n];
}
