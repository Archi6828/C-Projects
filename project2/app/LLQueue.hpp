// Archita Bathole
// abathole
// 44633605
// 1/31/2020

#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};


template<typename Object>
class LLQueue
{
private:
    
    struct Node
    {
        Object value;
        Node* next;
    };

    Node* head;
    Node* tail;
    unsigned tailIndex;

public:
	LLQueue();

//	In principle, you should have copy constructors and 
// assignment operators implemented.
// I am not going to require it for this assignment.
//	LLQueue(const LLQueue & st);
//	LLQueue & operator=(const LLQueue & st);
	~LLQueue()
	{
		while(tailIndex != 0)
        {
            dequeue(); //delete nodes
        }
	}

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two front() for the same reason the Stack in lecture week 2 had two top() functions.
	// If you do not know why there are two, your FIRST step needs to be to review your notes from that lecture.

	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

// does not return anything.  Just removes. 
	void dequeue();
};

//constructor
template <typename Object>
LLQueue<Object>::LLQueue()
{
    head = tail = nullptr;
    tailIndex = 0;
}
  
template <typename Object>
size_t LLQueue<Object>::size() const noexcept
{
    return tailIndex;
}
    
template <typename Object>
bool LLQueue<Object>::isEmpty() const noexcept
{
    return (tailIndex == 0);
}

template <typename Object>
Object & LLQueue<Object>::front()
{   
    if(isEmpty())
    {
        throw QueueEmptyException("Access to empty queue.");
    }
    return head->value;
}

template <typename Object>
const Object & LLQueue<Object>::front() const
{
    if(isEmpty())
    {
        throw QueueEmptyException("Access to empty queue.");
    }
    return head->value;
}

template <typename Object>
void LLQueue<Object>::enqueue(const Object & elem)
{
    //create Node
    Node* temp = new Node;
    temp->value = elem;
    //front
    if(head == nullptr)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;  //add node to back
        tail = temp;
    }
    tail->next = NULL;
    tailIndex++;
}

// does not return anything.  Just removes.
template <typename Object> 
void LLQueue<Object>::dequeue()
{
    if(isEmpty())
    {
        throw QueueEmptyException("Empty queue.");
    }
      
    Node* delNode = head;
    head = head->next;  //remove front node
    delete delNode;
    tailIndex--;
}

#endif 
