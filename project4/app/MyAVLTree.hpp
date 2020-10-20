// Archita Bathole (abathole) 44633605
// Partner: Mandy Woo (woom3) 89385270 
// 2/19/2020

#ifndef __PROJ_THREE_AVL_HPP
#define __PROJ_THREE_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>
#include <stack>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


template<typename Key, typename Value>
class MyAVLTree
{
private:
    struct Node
    {
        Key nodeKey;
        Value nodeValue;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
        int height = 1;
    };

    Node* root;
    int treeSize;

public:
	MyAVLTree();

	// The destructor is, however, required. 
	~MyAVLTree()
	{
        deleteNodes(root);
	}

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;
    
    //Added functions
    void rebalance(Node* n);
    void BalancedSubtree(Node* x, Node* y, Node* z);
    void updateChildNodes(Node* n); //update child nodes' heights
    void updateParentHeight(Node* n);
    void inOrderRecur(Node* n, std::vector<Key>& ordered) const;
    void preOrderRecur(Node* n, std::vector<Key>& ordered) const;
    void postOrderRecur(Node* n, std::vector<Key>& ordered) const;
    void deleteNodes(Node* n);
};


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree()
{
     root = nullptr;
     treeSize = 0;
}

template<typename Key, typename Value>
void MyAVLTree<Key,Value>::deleteNodes(Node* n)
{
     if(n == nullptr)
        return;
     else
     {
       deleteNodes(n->left);
        deleteNodes(n->right);
        delete n;
     }
}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return treeSize;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
	return treeSize == 0;
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const
{
    Node*tempPtr = root;
    while(tempPtr != nullptr)
    {
        if(tempPtr->nodeKey == k)
        {
            return true;
        }
        //smaller than root
        else if(k < tempPtr->nodeKey )
        {
            tempPtr = tempPtr->left;
        }
        //bigger than root
        else 
        {
            tempPtr = tempPtr->right;
        }
    }  
	return false;
}

template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
    static Value v;
	if(!contains(k))
        throw ElementNotFoundException("NOT IN TREE!");
    else
    {
         Node*tempPtr = root;
        while(tempPtr != nullptr)
        {
            if(tempPtr->nodeKey == k)
            {
                v = tempPtr->nodeValue;
                return v;
            }
            //smaller than root
            if(k < tempPtr->nodeKey)
            {
               tempPtr = tempPtr->left;
            }
            //bigger than root
            if(k > tempPtr->nodeKey)
            {
               tempPtr = tempPtr->right;
            }
        }
    }
    return v;
}

template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
    static Value v;
    if(!contains(k))
        throw ElementNotFoundException("NOT IN TREE!");
    else
    {
        Node*tempPtr = root;
        while(tempPtr != nullptr)
        {
            if(tempPtr->nodeKey == k)
            {
                v = tempPtr->nodeValue;
                return v;
            }
            //smaller than root
            if(k < tempPtr->nodeKey)
            {
               tempPtr = tempPtr->left;
            }
            //bigger than root
            if(k > tempPtr->nodeKey)
            {
               tempPtr = tempPtr->right;
            }
        }
    }
    return v;
}

// Inserts the given key-value pair into
// the tree and performs the AVL re-balance
// operation, as described in lecture.
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
    Node* x = nullptr;
    Node* y = nullptr;
    Node* z = nullptr;

    Node* tempPtr = root;
    
    bool exists = contains(k);

    //bool root height checker
    bool rootIncHeight = false;
    if(root != nullptr && !contains(k))
    {
        //update root's height only when it had no or two childs
        if((root->left == nullptr && root->right == nullptr) ||
           (root->left != nullptr && root->right != nullptr))
        {
            root->height += 1;
            rootIncHeight = true;
        }
    }
    if(!exists)
        treeSize++;
    while(tempPtr != nullptr)
    {
        if(tempPtr != root && !exists) //update heights of all nodes
            tempPtr->height += 1;
        if(k == tempPtr->nodeKey)
        {
            tempPtr->nodeValue += 1;
            return;
        }
        //smaller than root
        else if(k < tempPtr->nodeKey)
        {
            if(tempPtr->left == nullptr) //add new node 
            {
                //create new node
                Node* node = new Node;
                node->nodeKey = k;
                node->nodeValue = v;

                tempPtr->left = node;
                tempPtr->left->parent = tempPtr;
                tempPtr = tempPtr->left;
                break;
            }
            tempPtr = tempPtr->left;
        }
        //bigger than root
        else
        {
            if(tempPtr->right == nullptr) //add new node
            {
                Node* node = new Node;
                node->nodeKey = k;
                node->nodeValue = v;

                tempPtr->right = node;
                tempPtr->right->parent = tempPtr;
                tempPtr = tempPtr->right;
                break;
            }
            tempPtr = tempPtr->right;      
        }
    }
    //add root
    if(tempPtr == nullptr)
    {
        Node* node = new Node;
        node->nodeKey = k;
        node->nodeValue = v;

        root = node;
        tempPtr = root;
    }   
    //check for balance
    if(treeSize > 2)
    {
       x = tempPtr;    
       BalancedSubtree(x,y,z);   //check balance of each level (leaf to root)
       updateParentHeight(tempPtr); 
    }
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	std::vector<Key> ordered;
    Node* tempPtr = root;
    inOrderRecur(tempPtr, ordered); //call recursive
	return ordered; 
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::inOrderRecur(Node* n, std::vector<Key>& ordered) const
{
    if(n == nullptr)
        return;
    else
    {
        inOrderRecur(n->left, ordered);
        ordered.push_back(n->nodeKey);
        inOrderRecur(n->right, ordered);
    }
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const
{
	std::vector<Key> ordered;
    Node* tempPtr = root;
    preOrderRecur(tempPtr, ordered);
    return ordered;
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::preOrderRecur(Node* n, std::vector<Key>& ordered) const
{
    if(n == nullptr)
        return;
    else
    {
        ordered.push_back(n->nodeKey);
        preOrderRecur(n->left, ordered);
        preOrderRecur(n->right, ordered);
    }
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const
{
	std::vector<Key> ordered;
    Node* tempPtr = root;
    postOrderRecur(tempPtr, ordered); //call recursive function
    return ordered;

}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::postOrderRecur(Node* n, std::vector<Key>& ordered) const
{
     if(n == nullptr)
        return;
    else
    {
        postOrderRecur(n->left, ordered);
        postOrderRecur(n->right, ordered);
        ordered.push_back(n->nodeKey);
    }
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::rebalance(Node* n)
{
    Node* tempPtr = n;
    Node* y = tempPtr->parent;
    Node* z = y->parent;
    Node* oldParent;
   
    Node* a = nullptr;
    Node* b = nullptr;
    Node* c = nullptr;
    
    //type of rotation
    if(z->nodeKey < y->nodeKey && y->nodeKey < tempPtr->nodeKey)
    { //Rotation 1
        a = z;
        b = y;
        c = tempPtr;
        oldParent = a->parent;                
    }
    else if(z->nodeKey > y->nodeKey && y->nodeKey > tempPtr->nodeKey)
    { //Rotation 2
        a = tempPtr;
        b = y;
        c = z;
        oldParent = c->parent;                
    }
    else if(y->nodeKey < tempPtr->nodeKey && tempPtr->nodeKey < z->nodeKey)
    { //Rotation 4
        a = y;
        b = tempPtr;
        c = z;
        oldParent = c->parent;                
    }
    else //Rotation 3
    {
        a = z;
        b = tempPtr;
        c = y;
        oldParent = a->parent;                
    }

    //rotate setup substrees (Node* T0 = a->left)
    Node* T1 = nullptr;
    Node* T2 = nullptr;
    Node* T3 = nullptr;

    if(b == y && c == z)
    {
        T1 = a->right;
        T2 = b->right;
        T3 = c->right;
    }
    else if(b == tempPtr && c == y)
    {
        T1 = b->left;
        T2 = b->right;
        T3 = c-> right;
    }
    else if(b == tempPtr && c == z)
    {
        T1 = b->left;
        T2 = b->right;
        T3 = c-> right;
    }
    else
    {
        T1 = b->left;
        T2 = c-> left;
        T3 = c->right;
    }
     
    //rotations           
    if(root->nodeKey == a->nodeKey || root->nodeKey == c->nodeKey)
    {
        root = b;
        b->parent = nullptr;
    }
    else
    {
        b->parent = oldParent;
        if(b->nodeKey > oldParent->nodeKey)
            oldParent->right = b;
        else
            oldParent->left = b;
    }
    b->left = a;
    a->parent = b;
    a-> right = T1;
    if(T1 != nullptr)
    {
        T1->parent = a;
    }
    b->right = c;
    c->parent = b;
    c->left = T2;
    
    if(T2 != nullptr)
    {
        T2->parent = c;
    }
           
    //reset heights
    if(b == y && c == z)
    {
        z->height -= 1; 
    }
    else if(b == tempPtr && c == y)
    {
        z->height -= 2; 
        y->height -= 1;
        tempPtr->height += 1;
    }
    else if(b == tempPtr && c == z)
    {
        tempPtr->height += 1;
        y->height -= 1;
        z->height -= 2; 
    }
    else
    {
        z->height -= 1; 
    }
    
    //update heights of parent node and all child nodes in rotation
    updateParentHeight(b);      
    updateChildNodes(a);
    updateChildNodes(a->right);
    updateChildNodes(c);
    updateChildNodes(c->right);
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::BalancedSubtree(Node* x, Node* y, Node* z)
{
    //check height diference of every level in tree from leaf to root

    if(x == nullptr)
        return;
    
    //set nulptrs to zero
    int xLeftHeight, xRightHeight;
    if(x->left == nullptr)
        xLeftHeight = 0;
    else
        xLeftHeight = x->left->height;
    if(x->right == nullptr)
        xRightHeight = 0;
    else
        xRightHeight = x->right->height;

    int dif = (xLeftHeight - xRightHeight);
    
    if(dif < 0)
        dif *= (-1);

    if( dif > 1)        
        rebalance(z); 

    if(x == root)
        return;
   BalancedSubtree(x->parent, x, y); //switch to pass parent node
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::updateParentHeight(Node* n)
{
    //update node n's parent's height

    if(n->parent == nullptr)
        return;
   
    Node* parent = n->parent;

    bool atRoot = false;
    while(atRoot == false)
    {
        //set nulptrs to zero
        int ParentLeftHeight, ParentRightHeight;
        if(parent->left == nullptr)
            ParentLeftHeight = 0;
        else
            ParentLeftHeight = parent->left->height;
        if(parent->right == nullptr)
            ParentRightHeight = 0;
        else
            ParentRightHeight = parent->right->height;

        int height;
        if(ParentLeftHeight > ParentRightHeight)
            height = ParentLeftHeight;
        else
            height = ParentRightHeight;
 
        parent->height = height + 1;
        if(parent->parent != nullptr)
            parent = parent->parent;
        else
            atRoot = true;
    }
  
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::updateChildNodes(Node* n)
{
    //update heights of all child nodes
    if (n == nullptr)
    {
        return;
    }
    n->height = n->parent->height - 1;
    updateChildNodes(n->left);
    updateChildNodes(n->right);
}

#endif 
