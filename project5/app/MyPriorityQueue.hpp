// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 3/7/2020

#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <vector>
#include <iostream>

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename Object>
class MyPriorityQueue
{
private:
	// fill in private member data here
    std::vector<Object> things;

public:

	// You also need a constructor and a destructor.
    MyPriorityQueue();
    ~MyPriorityQueue();

 	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	void insert(const Object & elem);


	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 

	void extractMin(); 
    
    void bubbleUp();  //swap up
    void bubbleDown(); //swap down
    std::vector<Object> MinHeap(); // for checking the configured heap
};

//member functions
template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue()
{}

template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue()
{}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return things.size();
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
    if(things.size() == 0)
	    return true;
    return false;
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	//go to rightmost leaf (end of vector)   
    things.push_back(elem);
    bubbleUp(); //swap up elements, if needed.
}

template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	if(isEmpty() == true)
        throw PriorityQueueEmptyException("Min Heap is Empty!!");
    return things[0]; 
}

template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
    if(isEmpty() == true)
        throw PriorityQueueEmptyException("Min Heap is Empty!!");
    //swap
    things[0] = things[things.size() - 1];
    things.pop_back();
    bubbleDown(); //swap down elements, if needed.
}

template<typename Object>
void MyPriorityQueue<Object>::bubbleUp()
{
    int index = things.size() - 1;
    //swap if inserted elem is smaller than its parent
    while(((index - 1) / 2) >= 0 && things[index] < things[(index - 1 )/ 2])
    {
        std::swap(things[ (index - 1)/ 2], things[index]);
        index = (index - 1) / 2;   
    }
}

template<typename Object>
void MyPriorityQueue<Object>::bubbleDown()
{
    int index = 0;
    //swap if either of the child nodes are smaller
    while(((index * 2) + 1) <= things.size() && 
          ((index * 2) + 2) <= things.size() 
          && (things[index] > things[(index * 2) + 1] ||
          things[index] > things[(index * 2) + 2]))
    {
        //find the smaller child
        int Lchild = (index * 2) + 1;
        int Rchild = (index * 2) + 2;
        if(std::min(things[Lchild], things[Rchild]) == things[Lchild])
        {
            if(things[index] > things[(index * 2) + 1])
            {
            
                std::swap(things[(index * 2) + 1],things[index]);
                index = (index * 2) + 1;
            }
        }
        else 
        {
            if(things[index] > things[(index * 2) + 2])
            {
                std::swap(things[(index * 2) + 2],things[index]);
                index = (index * 2) + 2;
            }
        }
    }
}

template<typename Object>
std::vector<Object> MyPriorityQueue<Object>:: MinHeap()
{
    std::vector<Object> copyThings;
    for(Object o: things)
    {
        copyThings.push_back(o);
    }
    return copyThings;
}
#endif

