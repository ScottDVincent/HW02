/**
 * @file HW02App.cpp
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 * @author Scott Vincent
 * @date 09-09-2012
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 *
 * This program satisfies requirements:
 (A) Draw a linked-list data structure
 (B) App displays a menu at beginning
 (D) Items on the screen move of their own accord
 (E) Have a reverse procredure for the list
 (H) Creates a drop shadow for each of the rectangles showing depth
 (I) Add child node: It maybe, kinda, works. 
 */


//cinder includes
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/Texture.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "cinder/Text.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/Text.h"
//my includes
#include "List.h"				// class header


using namespace ci;
using namespace ci::app;
using namespace std;



// this HW02App should go in a header file
class HW02App : public AppBasic {

  public:

	// Cinder specific methods
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );
	void prepareSettings(Settings* settings);
	void setup();
	void update();
	void draw();
	void randomColor();
	

private:
	  
	  // define sentinel
	  Node* sentinel_;
	  Node* cur_;
	  Node* firstChild_;

		//Width and height of the screen
		static const int AppWidth=800;
		static const int AppHeight=600;
		static const int TextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
		
		
		// declare the menu parameters
		bool hideMenu;  //When true, removes the instructions
		Font* font;		//Part of the cinder drawString method 
	
};  // the above should really go in a .h file



void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(AppWidth,AppHeight);
	settings->setResizable(false);
}


void HW02App::setup(){

	//	Setup the text menu 
	font = new Font("Arial",28);
	hideMenu = false;


	/**
	First:	construct the sentinel node
	//Establishes the inital sentinal node for our circular list. 
	*/
	sentinel_ = new Node;

    //http://libcinder.org/docs/v0.8.4/classcinder_1_1_rect_t.html#adf917a76e5a25087be8094989d4e352d
	
	/**
	Second:	
	// create an initial list of rectangles
	*/
	int offset = 0;

	for (int i=1; i<=6; i++){ 
		Rect* new_rect = new Rect (10.0+offset, 10.0+offset, 50.0+offset, 50.0+offset,  Color8u(rand()%256,rand()%256,rand()%256), 3); 
		insertAfter(new_rect, sentinel_ -> next_);

		offset +=20;
	}


	/**
	Third:	
	// add three children to the first node and see if they follow it. use the reorder function to test
	*/
	firstChild_ = new Node();
	firstChild_ = sentinel_-> next_ ;				// ? this will create the head child node
	//firstChild_ = sentinel_-> next_ -> children_; // ! this causes a crash

}


void HW02App::mouseDown( MouseEvent event ) {
	
	//reverses list
	 if( event.isRight() ) {
		reverseList(sentinel_);
    }
	// creates a new node
	 if( event.isLeft() ) {
		 Rect* new_rect = new Rect (event.getX(), event.getY(), event.getX()+rand()%50, event.getY()+rand()%50,  Color8u(rand()%256, rand()%256, rand()%256), 3 ) ;
		 insertAfter(new_rect, sentinel_);
    }
}



/**
libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html
*/

void  HW02App::keyDown( KeyEvent event ) {
	
    if( event.getChar() == 'q' ){
		 //call reverse node
		reverseList(sentinel_);	
    
	} else if( event.getChar() == 'w' ){
       // call reorder list
        reorderList (sentinel_ -> next_ , sentinel_ -> next_ -> next_);
	 
	} else if( event.getChar() == 'a' ){

		Rect* new_rect =  new Rect (400, 400, 500, 500, Color8u(100,200,50), 1 );
		addChild(new_rect, firstChild_);
		Rect* new_rect2 =  new Rect (450, 450, 520, 520, Color8u(50,35,50), 1 );
		addChild(new_rect2, firstChild_);
		Rect* new_rect3 =  new Rect (500, 500, 540, 540, Color8u(10,250,150), 1 );
		addChild(new_rect3, firstChild_);

	} else if(  event.getCode() == KeyEvent::KEY_RIGHT ){
		for (Node* cur_ = sentinel_->next_; cur_ != sentinel_; cur_ = cur_->next_)
		{
		       cur_-> data_ -> shakeMore();		//for each data_ member of each node call the drawRect method
		}
	
	} else if( event.getCode() == KeyEvent::KEY_LEFT ){
		for (Node* cur_ = sentinel_->next_; cur_ != sentinel_; cur_ = cur_->next_)
		{
		       cur_-> data_ -> shakeLess();		//for each data_ member of each node call the drawRect method
		} 
	
	} else if ((event.getChar() == '/') && hideMenu == false) {
			hideMenu = true;
	
	} else if ((event.getChar() == '/') && hideMenu == true) {
			hideMenu = false;
    }

} // end keyDown




void HW02App::update()
{
	// show console with controls q, w, e, r, t,
	// console() << "Press Q for something. \n Press W for something else. \n Press E for something else. \n Press T for something else. \n Press ? to toggle the display. \n "  << std::endl;

}

void HW02App::draw(){

	if(!hideMenu)                         // draw menu initially
	{	
		// libcinder.org/docs/v0.8.2/namespacecinder_1_1gl.html#a8715d619df092110ac326e7a4ab08098
		gl::drawString("Menu Operations: q = reverse list, w = reorder list, a = add child.", Vec2f(50.0f,200.0f),Color(0.0f,0.5f,0.0f), *font);	
		gl::drawString("Menu Operations: Left click adds a node, right click reverses list.", Vec2f(50.0f,250.0f),Color(0.0f,0.5f,0.0f), *font);	
		gl::drawString("Menu Operations: Left arrow: slow jitter, Right arrow: increase jitter.", Vec2f(50.0f,300.0f),Color(0.0f,0.5f,0.0f), *font);	
		gl::drawString("Press ? to toggle menu.", Vec2f(50.0f,350.0f),Color(0.0f,0.5f,0.0f),*font);	
	    } else	{	
		gl::clear(Color( 255, 255, 255 )); //Clear out text and makes screen white 
	}
		

		//Go through linked list draw every node. 
	    for (Node* cur_ = sentinel_->next_; cur_ != sentinel_; cur_ = cur_->next_)
		{
		       cur_-> data_ -> drawRect();		//for each data_ member of each node call the drawRect method

		//child node doesn't draw when I call it so I have no idea if the method is actually creating a child node
			   if (cur_ -> children_ != NULL)
				   // loop thru the child nodes somehow
				   for (Node* curChild_ = cur_ -> children_; curChild_ -> children_ != NULL; curChild_ = curChild_-> next_)
					   //or
					   // for (Node* curChild_ = cur_ -> children_; curChild_ -> children_ != firstChild_; curChild_ = curChild_-> next_)  
				   curChild_-> data_ -> drawRect();
		}	
}




CINDER_APP_BASIC( HW02App, RendererGl )
