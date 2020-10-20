// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/12/2020

#ifndef ___PROJECT_3_HPP
#define ___PROJECT_3_HPP

#include <string>
#include "Wordset.hpp"
#include <map>
#include <queue>
#include <set>
#include <stack>
void loadWordsIntoTable(WordSet & words, std::istream & in);


std::string convert(std::string s1, std::string s2, const WordSet & words);
void findcombo(int index, std::string& s1, std::string& s2,
const WordSet & words, std::map<std::string,std::set<std::string>>& wordmap);
std::stack<std::string> BFS(std::map<std::string,std::set<std::string>>&                   
wordmap, std::string& s1, std::string& s2);

void print(std::map<std::string,std::set<std::string>>& wordmap);
char numtochar(int n);


#endif
