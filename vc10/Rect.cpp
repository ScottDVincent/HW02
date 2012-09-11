/*
 * @file Rect.cpp
 *  This is really a
 * linked data structure as well.
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
#include "Rect.h"
#include "cinder/Rand.h";

using namespace ci;
using namespace ci::app;
using namespace std;



//construct a Rectangle object
Rect::Rect(int position, int startX, int startY, int width, int height);  // argument constructor

	/**
//Rect::Rect(int depth, Vec2f position, float radius){
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




// argument is a int, Rect object for project
void Rect::addNode (Rect* new_rect, Rect* next_rect){

	/// you would need to dereference the arguments to use the value
	// *new_rect = something

	// ? do I need to pass in the Rect* next_rect ?
	
	/**
	/// in simple terms
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;        //(2) change x pointer to t node
	*/

	 {
	   link* newlink = new link;          // make a new link
	   newlink->rect = new_rect;          // give it data
	   newlink->next = first;             // it points to next link
	   first = newlink;                   // now first points to this
	   }
	
	

}


// argument is a int, Rect object for project
void Rect::deleteNode (Rect* new_rect, Rect* next_rect){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to
	delete t;			//(3) the memory space for t is deleted 
}

// argument is a int, Rect object for project
void Rect::reverseList (Rect* new_rect, Rect* next_rect){
	
	/*** FROM BOOK
	link reverse(link x)
  { link t, y = x, r = 0;
    while (y != 0)
      { t = y->next; y->next = r; r = y; y = t; }
    return r;
  }
  */

}

// argument is a int, Rect object for project
void Rect::reorderList (Rect* new_rect, Rect* next_rect){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, Rect object for project
void Rect::traverseList (Rect* new_rect, Rect* next_rect){
		
	for (link t = x; t != 0; t = t->next) 
			displayNode(t->item);			// 
}


// argument is a int, Rect object for project
void Rect::displayList (int num, node* t){
			// put the display here ? cout<<


}
