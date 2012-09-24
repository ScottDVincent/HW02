/*
 * @file Node.cpp
 *
 * @author Scott Vincent
 * @date 09/09/2012
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */ 

#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "List.h"


using namespace ci;
using namespace ci::app;
using namespace std;		// standard library


	/** 
	 * Constructs Node object which points to itself and has a data_ member and a child hook
	*/  
	Node::Node(){
		next_ = prev_ = this;		// create self-referential node; the assignments go in reverse order
		data_ = new Rect();			// data item will be a Rect object
		children_ = NULL;			// child hook into the node, each node has no children initially
	}



	/** 
	 * insertAfter method but perhaps it should be insertBefore since we want to insert at the end 
	 * @param new_Rect: creates a new Rect object pointer
	 * @param cur: is the current node we are inserting after, in this case the sentinal node 
	*/ 
	void insertAfter (Rect* new_rect, Node* cur) {
	
		
	// actually creates the new node	
	Node* newNode_p = new Node;			// allocating space for a new Node pointer
	newNode_p -> data_ =  new_rect;	    // 1: the data will be the rectangle info we are sending in
	
	// DO THE NODE SWITCHING
	//take care if newNode_p pointers first
	newNode_p -> prev_ = cur;					// set the newNode's prev to point to current, the one before it
	newNode_p -> next_ = cur -> next_;			// 4: points the new Node to what it's previous node was pointing to
	
	cur -> next_ = newNode_p;					// alter current node pointer
	newNode_p -> next_ -> prev_ = newNode_p;	// dereference newNode_p's pointers twice
												// set newNode_p's next_'s "previous" pointer to newNode_p			
		
	// where to declare nodeCount_ so that it's available to all List methods?
	// would it go in the constructor?
	//nodeCount_ += nodeCount_ ;			// increase nodeCount

	}


/** Adds a child to a node
	* @param Rect* childRect
	* @param Node* parentNode
	*/
void addChild (Rect* childRect, Node* parentNode){

		if(parentNode -> children_ == NULL){				// if this node doesn't have any children
			parentNode -> children_ = new Node();			// turn children into a Node
			parentNode -> children_ -> data_ =  childRect;	//put data into this new child
		} else {	
			insertAfter(childRect, parentNode);				// adds a another node onto the child list
		}
}



/**
* deleteNode
*@param delNode argument is a Node object you want to delete
*/
void deleteNode (Node* delNode){

	 delNode-> next_-> prev_ = delNode-> prev_; //(1) sets t up as the link from x
	 delNode-> prev_-> next_ = delNode-> next_; //(2) x link points to whatever t link points to
	 delete delNode;							//(3) the memory space for t is deleted
	 //--nodeCount_;

	//nodeCount_ -= nodeCount_;		// decement count of items in list
}


/**
* reverseList: reverses the list order 
* @param sentinel , we will start at the sentinel node
*/
void reverseList (Node* sentinel){
	
		
	//(1) get to end of list 
			Node* end;
			Node* tmpNext;
			Node* cur;

			end = sentinel -> prev_;
			cur = end ;

	//(2) and go backwards

		do {

			tmpNext = cur -> next_;				// set tmpNext to the current_ node's next pointer
			cur -> next_ = cur -> prev_;		// set current node's next_ pointer to 
												//  the current_'s previous pointer
			cur -> prev_ = tmpNext;				// set current node's previous pointer to 
												//  the current_'s next pointer (stored in tmpNext_)
			//(4)	move current back one
			cur = cur -> next_;					// next_ is now pointing to the current's previous, we just switched it above, so we have to use next_

			// we want the changes to go back through the sentinel and stop at the end (now beginning)  node
			}
		while (cur != end);
		

}


/**
* reorderList
*@param fromNode node you want to move
*@param toNode where you want to move this node
*/
void reorderList (Node* fromNode, Node* toNode){

	fromNode->next_->prev_ = fromNode->prev_;		// set cur next 's prev to the one before cur
	fromNode->prev_->next_ = fromNode->next_;		// set cur prev to cur's next
														// fromNode is now "free"	
	fromNode->next_ = toNode->next_;				// set cur's next to toNode's next
	fromNode->prev_ = toNode;						// set cur prev_ to the toNode (behind it)
	toNode->next_ = fromNode;						// set toNode next to cur
	fromNode->next_->prev_ = fromNode;				// set new cur's next's prev back to cur
}


/**
* traverseList
*@param sentinel 
* start at the first item and iterate thru list
*/
void traverseList (Node* sentinel){
	
	Node* cur;
	cur = sentinel -> next_;	// set cur to first item, which is after the sentinel

	while (cur != sentinel){	// move forward through the list

			displayNode (cur);	
	}
		cur = cur -> next_ ;	// update the cur to the next node
}



/**
* displayNode
*@param inNode 
*argument is a a single Node object, passed in from traverseList,  to be printed
*/
void displayNode (Node* inNode){		
	  
	// draw this single node being passed in
}

 

/**
* nodeCount
@param sentinel start counting from the sentinel
*return an int with the number of nodes, including the sentinel
*/ 
int nodeCount (Node* sentinel){

		Node* cur = sentinel -> next_;
		int theCount = 1;				// includes the sentinel

		while(cur != sentinel) {
			theCount++;
			cur = cur->next_;
			}
		return theCount;

}