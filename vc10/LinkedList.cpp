/*
 * @file LinkedList.cpp
 *
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 * @author Scott Vincent
 * @date 09/09/2012
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */ 

#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h";
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;		// standard library



//construct a LinkedList  object
//LinkedList::LinkedList(int position, int startX, int startY, int width, int height);  // argument constructor

	/**
//LinkedList::LinkedList(int depth, Vec2f position, float radius){
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




// argument is a int, LinkedList object for project
void LinkedList::addNode (LinkedList* new_LinkedList, LinkedList* next_LinkedList){

	/// you would need to dereference the arguments to use the value
	// *new_LinkedList = something

	// ? do I need to pass in the LinkedList* next_LinkedList ?
	
	/**
	/// in simple terms
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;        //(2) change x pointer to t node
	*/

	 {
	   link* newlink = new link;          // make a new link
	   newlink->LinkedList = new_LinkedList;          // give it data
	   newlink->next = first;             // it points to next link
	   first = newlink;                   // now first points to this
	   }
	
	

}


// argument is a int, LinkedList object for project
void LinkedList::deleteNode (LinkedList* new_LinkedList, LinkedList* next_LinkedList){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to
	delete t;			//(3) the memory space for t is deleted 
}

// argument is a int, LinkedList object for project
void LinkedList::reverseList (LinkedList* new_LinkedList, LinkedList* next_LinkedList){
	
	/*** FROM BOOK
	link reverse(link x)
  { link t, y = x, r = 0;
    while (y != 0)
      { t = y->next; y->next = r; r = y; y = t; }
    return r;
  }
  */

}

// argument is a int, LinkedList object for project
void LinkedList::reorderList (LinkedList* new_LinkedList, LinkedList* next_LinkedList){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, LinkedList object for project
void LinkedList::traverseList (LinkedList* new_LinkedList, LinkedList* next_LinkedList){
		
	for (link t = x; t != 0; t = t->next) 
			displayNode(t->item);			// 
}


// argument is a int, LinkedList object for project
void LinkedList::displayList (int num, node* t){
			// put the display here ? cout<<


}
