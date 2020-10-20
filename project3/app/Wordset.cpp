// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/12/2020

#include "Wordset.hpp"
#include <string>
#include <iostream>

const int BASE_TO_USE = 37; 
const double LOAD_LIMIT = 0.25;

WordSet::WordSet()
{
    wordsSize = SIZES[0];
    words = new unsigned[wordsSize];
    std::fill_n(words, wordsSize, -1);
    filledSpots = 0;
    resize = 0;
}

// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
    unsigned key = 0;
    unsigned counter;
    unsigned charNum = 0;
    counter = s.length() - 1;
    for(int i = 0; i < s.length(); i++)
    {
        unsigned innerbase = 1;
        for(int k = 0; k < counter; k++)
        {
            innerbase *= base;
        }
        counter--;
        charNum = (s[i] - ('a'));    //zero-based counting
        key += (charNum * innerbase);
    }
    
    key = key % mod;
 
	return key;
}

unsigned strtonum(std::string s, int base, int mod)
{
    unsigned key = 0;
    unsigned counter;
    unsigned charNum = 0;
    counter = s.length() - 1;
    for(int i = 0; i < s.length(); i++)
    {
        unsigned innerbase = 1;
        for(int k = 0; k < counter; k++)
        {
            innerbase *= base;
        }
        counter--;
        charNum = (s[i] - ('a' - 1));  //counting starts from 1        
        key += (charNum * innerbase);
    }
    return key;
}

char getchar(int n)
{
    return "abcdefghijklmnopqrstuvwxyz"[n]; //char of corresponding int
}

unsigned numtohash(unsigned num, int base, int mod)
{
    //converts the interger of the value stored in words into 
    //its corresponding hashkey.

    unsigned high = 26;   
    unsigned counter = -1;
    while (num > high)
    {
        unsigned innerbase = 1;
        counter++;
        for(int k = 0; k < counter; k++)
        {
            innerbase *= base;
        }
        high += 26 * innerbase;
    }
    unsigned strlen = counter + 1;
  
    for(int i = 0; i < strlen; i++)
    {
        unsigned innerb = 1;
        for(int k = 0; k < (counter); k++)
        {
            innerb *= base;
        }
        counter--;        
        num -=  innerb;
    }
    num = num % mod;
    return num;
}

WordSet::~WordSet()
{
    delete[] words;
}

void WordSet::insert(std::string s)
{
    filledSpots++;
    double loadFactor = ((1.0) * filledSpots/wordsSize);
    
    if( loadFactor  >= LOAD_LIMIT) //resize
    {
        resize++;
        rehash(resize);
    }

    unsigned hashkey = hashFunction(s, BASE_TO_USE, wordsSize); //get s in digit
    unsigned incbase = 0;

    hashkey = hashkey % wordsSize;
 
    while(words[hashkey]  != -1)      //check for collision
    {
        incbase++;
        hashkey = ((hashkey % wordsSize) +
                  ((incbase * incbase) % wordsSize)) % wordsSize; 
    }
    
    unsigned key = strtonum(s,BASE_TO_USE, wordsSize);
    words[hashkey] = key;
}

//helper functions for resize words
void  WordSet::rehash(int resize)
{
    //store old numbers
    unsigned* oldWords = words;
    unsigned oldWordsSize = wordsSize;

    wordsSize =  SIZES[resize];
    
    words = new unsigned[wordsSize]; //up the size
    std::fill_n(words, wordsSize, -1); 
    
    //rehash nums in oldwords to new spots in cur words
    for(int i = 0; i < oldWordsSize; i++)
    {
        if(oldWords[i] != -1)
        {
            unsigned incbase = 0;
            unsigned hashkey = numtohash(oldWords[i], 
                                BASE_TO_USE, wordsSize) % wordsSize;
            
            while(words[hashkey]  != -1)      //check for collision
            {   
                incbase++;
                hashkey = ((hashkey % wordsSize) + 
                          ((incbase * incbase) % wordsSize)) % wordsSize; 
            }
            words[hashkey] = oldWords[i];            
        }
    }

    //delete old items
    delete[] oldWords;
}

bool WordSet::contains(std::string s) const
{
    unsigned key = strtonum(s, BASE_TO_USE, wordsSize);
    unsigned hashkey = hashFunction(s,BASE_TO_USE, wordsSize);
    hashkey = hashkey % wordsSize; 
   
    if(words[hashkey] == key)
    {
        return true;
    }
    else //if collision
    {
        unsigned incbase = 0;
  
        while(words[hashkey]  != -1)  //check for collision
        {
            incbase++;
            hashkey = ((hashkey % wordsSize) + 
                      ((incbase * incbase) % wordsSize)) % wordsSize;
   
            if(words[hashkey] == key)
                return true;
        }
    }
	return false;
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return filledSpots; 
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return wordsSize; 
}
