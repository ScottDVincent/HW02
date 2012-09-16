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
#include "Rect.h"

using namespace ci;
using namespace ci::app;
using namespace std;		// standard library



///construct a Node  object

class Node {

public: 


// STEP 1

	/**
	? Have to create a list with one empty node in it.
	something like...
	LinkedList::LinkedList (Node* sentinal)

	*/

	//constructor
	Node() {

		sentinal_ = NULL;
	};

	
	//Member Variables
	


	
}
/**
//Diamond::Diamond(int depth, Vec2f position, float radius){
	//This is a circular list, so a list of length 1 has
	// next and prev pointing to itself
	next_ = prev_ = this;
	children_ = NULL;
	
	position_ = position_;
	radius_ = radius;
	velocity_ = randVec2f();
	
	if(depth > 0){
		addRandomChild(depth-1);
		addRandomChild(depth-1);
		addRandomChild(depth-1);
	}
	*/




////if this is our data structure object implementation then maybe don't need a struct?
// 
void insertAfter (Rect new_rect, Node* where) {

	/**
	* in this example "where" is the node we are placing a new node after
	*/
	Node* tmpPrev_;						// ? should this be a Node* type ?
	Node* theNode_p = new Node;			// allocating space for a new Node pointer


	// DO THE NODE SWITCHING
	newNode_p -> new_rect =  new Rect;	// 1: the data will be a new rectangle object

	tmpPrev_ = &where -> prev_;			// 2: tmpPrev holds the addy of "where"'s next_'s prev_ : 
										// ? did I place the & properly ?
										// pointer var tmpPrev_ now holds the memory address of where -> prev_
										// see #3

		// #3: I want the value of tmpPrev to be changed to the location of theNode	
		// ? how to code... (see c++ in 15; p433-35 for concept)
		// ? where's next_'s prev_ = theNode_p   // 6: problem is that "where"'s next_'s "previous_" is still poiningt at "where" and NOT theNode
	 *tmpPrev_ = &theNode_p;   //  the dereferenced value of tmpPrev_ = the address of theNode_p
				
			// bounds checking:	// ?? will I run into a situation where I will ever dereference a NULL next pointer? 	
								// == I don't think so. All nodes should always have a valid pointer				
	
	newNode_p -> next_ = where -> next_;// 4: points the new Node to what it's previous node was pointing to
	where -> next_ = newNode_p;			// 5: where's next_ now points to the newNode
	newNode_p -> prev_= where;			// 6: theNode's prev_ now points behind it to where	
							  

	nodeCount_ += nodeCount_ ;			// increase nodeCount
}





// argument is a int, Node object for project
void Node::addNode (Rect new_rect, Node* next_Node){

	/// you would need to dereference the arguments to use the value
	// *new_Node = something

	// ? do I need to pass in the Node* next_Node ?
	
	/**
	/// in simple terms
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;        //(2) change x pointer to t node
	*/

	 {
	   link* newlink = new link;          // make a new link
	   newlink->Node = new_Node;          // give it data
	   newlink->next = first;             // it points to next link
	   first = newlink;                   // now first points to this
	   }
	
	

}


// argument is a int, Node object for project
void Node::deleteNode (Node* the_node){
	t = x->next;		 //(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to
	delete t;			 //(3) the memory space for t is deleted 

	nodeCount_ -= nodeCount_;		// decement count of items in list
}

// argument is a int, Node object for project
void LinkedList::reverseList (Node* new_Node, Node* next_Node){
	
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
	
	(1) get to end of list 
			end_ = sentinel -> prev_
			current_ = end_ (4 node)

	(2) and go backwards

		do {

	(3) 
	Before  Node		After	Node			What got changed				Temp Node for transition
	4 prev_ = 3			4 prev_ = 1				4,3 & 1 are same addy,						
	4 next_ = 1         4 next_ = 3				only the prev_ & next_ changed
	
	tmpNext_ = current_ -> next_;				// set tmpNext to the current_ node's next pointer
	current_ -> next_ = current -> prev_;		// set current node's next_ pointer to 
										        //  the current_'s previous pointer
	current_ -> prev_ = current_ -> tmpNext_;   // set current node's previous pointer to 
										        //  the current_'s next pointer (stored in tmpNext_)

	(4)	//move current back one
	current_ = current -> prev_;

	// we want the changes to go back through the sentinel and stop at the end / begin node
	while (current_ != end);

	}
	*/

}

// argument is a int, Node object for project
void Node::reorderList (Node* new_Node, Node* next_Node){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, Node object for project
void Node::traverseList (Node* new_Node, Node* next_Node){
		
	for (link t = x; t != 0; t = t->next) 
			displayNode(t->item);			// 
}


// argument is a int, Node object for project
void Node::displayList (int num, node* t){
			// put the display here ? cout<<


}
