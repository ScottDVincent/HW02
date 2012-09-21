/*
 * @file Node.cpp
 *``
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
#include "cinder/Rand.h";
#include "List.h"


using namespace ci;
using namespace ci::app;
using namespace std;		// standard library




// STEP 1
	/**
	? Have to create a list with one empty node in it.
	--> do that in HW02App setup()
	*/

	//Constructor for Node
	Node::Node(){
		next_ = prev_ = this;		// create self-referential node; the assignments go in reverse order
		data_ = new Rect();			// data item will be a Rect object

		//children_ = NULL;			// no children in this node, yet
	}




// insertAfter method but perhaps it should be insertBefore since we want to insert at the end
void insertAfter (Rect* new_rect, Node* cur) {
	
	/**
	* in this example "cur" is the node we are placing a new node after
	*/
	Node* tmpPrev;						// ? should this be a Node* type ?
	
	// create new node	
	Node* newNode_p = new Node;			// allocating space for a new Node pointer
	newNode_p -> data_ =  new_rect;	    // 1: the data will be the rectangle info we are sending in
	
	
	// DO THE NODE SWITCHING
	//take care if newNode_p pointers first
	newNode_p -> prev_ = cur;					//
	newNode_p -> next_ = cur -> next_;			//
	
	cur -> next_ = newNode_p;					// alter current node pointer
	newNode_p -> next_ -> prev_ = newNode_p;	// dereference newNode_p's pointers twice
												// set newNode_p's next_'s "previous" pointer to newNode_p			


	/**	old code idea

	tmpPrev_ = &current -> prev_;		// 2: tmpPrev holds the addy of "current"'s next_'s prev_ : 
										// ? did I place the & properly ?
										// pointer var tmpPrev_ now holds the memory address of current -> prev_
										// see #3

		// #3: I want the value of tmpPrev to be changed to the location of theNode	
		// ? how to code... (see c++ in 15; p433-35 for concept)
		// ? current's next_'s prev_ = theNode_p   
											// 6: problem is that "current"'s next_'s "previous_" is still poiningt at "current" and NOT theNode
	 *tmpPrev_ = &theNode_p;				//  the dereferenced value of tmpPrev_ = the address of theNode_p
				
	 newNode_p -> -> prev_ = theNode_p;
											// bounds checking:	// ?? will I run into a situation where I will ever dereference a NULL next pointer? 	
											// == I don't think so. All nodes should always have a valid pointer				
	
	newNode_p -> next_ = current -> next_;  // 4: points the new Node to what it's previous node was pointing to
	current -> next_ = newNode_p;			// 5: current's next_ now points to the newNode
	newNode_p -> prev_= current;			// 6: theNode's prev_ now points behind it to where	
	*/						  

	//nodeCount_ += nodeCount_ ;			// increase nodeCount

	}




/**
// argument is a int, Node object for project
void Node::addNode (Rect new_rect, Node* next_Node){

	/// you would need to dereference the arguments to use the value
	// *new_Node = something

	// ? do I need to pass in the Node* next_Node ?
	
	/**
	/// in simple terms
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;        //(2) change x pointer to t node

	 {
	   link* newlink = new link;          // make a new link
	   newlink->Node = new_Node;          // give it data
	   newlink->next = first;             // it points to next link
	   first = newlink;                   // now first points to this
	   }


}
*/



// argument is a Node object 
void deleteNode (Node* delNode){

	 delNode-> next_-> prev_ = delNode-> prev_; //(1) sets t up as the link from x
	 delNode-> prev_-> next_ = delNode-> next_; //(2) x link points to whatever t link points to
	 delete delNode;						    //(3) the memory space for t is deleted	

	//nodeCount_ -= nodeCount_;		// decement count of items in list
}


// argument is a Node pointer for project
void reverseList (Node* sentinel){
	
	/*** FROM BOOK USING STRUCT
	link reverse(link x)
  { link t, y = x, r = 0;
    while (y != 0)
      { t = y->next; y->next = r; r = y; y = t; }
    return r;
  }
  */

	/**
	(1 : seems complicated)
	1-2-3-4 becomes 4-3-2-1
	switch pointers; use a tempNode to hold the value of the one you're switching
	4 -> 1
	3-> 2
	2 -> 3

	or 

	(2 : seems fairly practical)
	Swap pointers of data item
	4 <-> 1
	3 <-> 2

	or

	(3 : seem practical as well and gives me the bonus of using a circular list)

	Use a double linked list with next_ and prev_ so that you switch those values: 	1-2-3-4
	
	vars: node* sentinal, current_, prev_, next_, tmpNext;	// declare these above in class declaration
	*/
	
	//(1) get to end of list 
			Node* end;
			Node* tmpNext;
			Node* cur;

			end = sentinel -> prev_;
			cur = end ;

	//(2) and go backwards

		do {

			//(3) 
			//Before  Node		After	Node			What got changed				Temp Node for transition
			//4 prev_ = 3			4 prev_ = 1				4,3 & 1 are same addy,						
			//4 next_ = 1         4 next_ = 3				only the prev_ & next_ changed
	
			tmpNext = cur -> next_;				// set tmpNext to the current_ node's next pointer
			cur -> next_ = cur -> prev_;		// set current node's next_ pointer to 
														//  the current_'s previous pointer
			cur -> prev_ = tmpNext;   // set current node's previous pointer to 
														//  the current_'s next pointer (stored in tmpNext_)

			//(4)	move current back one
			cur = cur -> next_;				// next_ is now pointing to the current's previous, we just switched it above, so we have to use next_

			// we want the changes to go back through the sentinel and stop at the end (now beginning)  node
			}
		while (cur != end);
		

}



void reorderList (Node* fromNode, Node* toNode){

	fromNode->next_->prev_ = fromNode->prev_;		// set cur next 's prev to the one before cur
	fromNode->prev_->next_ = fromNode->next_;		// set cur prev to cur's next
														// fromNode is now "free"	
	fromNode->next_ = toNode->next_;				// set cur's next to toNode's next
	fromNode->prev_ = toNode;						// set cur prev_ to the toNode (behind it)
	toNode->next_ = fromNode;						// set toNode next to cur
	fromNode->next_->prev_ = fromNode;				// set new cur's next's prev back to cur


}


// start at the first item and iterate thru list
void traverseList (Node* sentinel){
	
	Node* cur;

	// ? can I use the same cur_ I have declared above ?
	cur = sentinel -> next_;	// set cur to first item, which is after the sentinel
	
	while (cur != sentinel){	// move forward through the list

			displayNode (cur);	
	}
		cur = cur -> next_ ;	// update the cur to the next node

}




// argument is a int, Node object for project
void displayNode (Node* inNode){		
	
          // drawRect(inNode->X1, inNode->Y1, inNode->X2, inNode -> Y2, inNode -> color );



		   /**
		   	bool areOverlapping = isInside(mp.x, mp.y);

				if(areOverlapping){
					//change color
				gl::color(Color8u(255,127,00));
				} else {
				gl::color(Color8u(255,0,0));
				}
				*/



     
}


// adds a child node at the node passed in
void addChild(int inNode){

	/** Dr Brinkman's code
		Node* newNode = new Node(depth,position_,Vec2f(0.0,0.0),0.45*radius_);

			if(children_ != NULL){
				insertAfter(newNode, children_);
				} else {
				children_ = newNode;
				}
			}
		*/

}


// return an int with the number of nodes, including the sentinel
int nodeCount (Node* sentinel){

		Node* cur = sentinel -> next_;
		int theCount = 1; // includes the sentinel

		while(cur != sentinel) {
			theCount++;
			cur = cur->next_;
			}
		return theCount;

}