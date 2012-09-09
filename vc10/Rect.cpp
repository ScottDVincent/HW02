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
Rect::rect(int position, int startX, int startY, int width, int height) {  // argument constructor

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
}



// argument is a int, Rect object for project
void Rect::addNode (int num, node* t){
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;        //(2) change x pointer to t node
}


// argument is a int, Rect object for project
void Rect::deleteNode (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to
	delete t;			//(3) the memory space for t is deleted 
}

// argument is a int, Rect object for project
void Rect::reverseList (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, Rect object for project
void Rect::reorderList (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, Rect object for project
void Rect::traverseList (int num, node*){
			for (link t = x; t != 0; t = t->next) 
				displayNode(t->item);
}


// argument is a int, Rect object for project
void Rect::displayNode (int num, node*){
			// put the display here ? cout<<
}
