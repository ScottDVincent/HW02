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
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "Rect.h"   //class


using namespace ci;
using namespace ci::app;
using namespace std;

// this HW02App should go in a header file
class HW02App : public AppBasic {

  public:
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );

	
	void setup();
	void update();
	void draw();

	void prepareSettings(Settings* settings);

  private:

		//Width and height of the screen
		static const int AppWidth=800;
		static const int AppHeight=600;
		static const int TextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
	
		int frame_number_;		
};




void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(AppWidth,AppHeight);
	settings->setResizable(false);
}

void HW02App::setup()
{

	/**

	First:
	?construct an empty List first?
	or create it with one Rect object? 
	LinkList List 
	*
	Second:
	/// make node call 4x for rectangles
	List.
	Rect(int position, int startX, int startY, int width, int height);

	Third:
	?? how do we add this rect node to the link list
	?  addNode();
	*/
	

}


void HW02App::mouseDown( MouseEvent event ) {
	
	/// if doing something with coordinates:
	//int x = event.getX();
	//int y = event.getY();
	
	 if( event.isRight() ) {
		 // call reorder list
    }

	  if( event.isLeft() ) {
		 // call something list
    }
}





/**
libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html
*/
void  HW02App::keyDown( KeyEvent event ) {
    if( event.getChar() == 'q' ){
        // call delete first node
    } else if( event.getChar() == 'w' ){
        //call add rect node
    } else if( event.getChar() == 'e' ){
        // call reverse node
    } else if( event.getChar() == 'r' ){
        //call move rect node
    } else if( event.getChar() == '?' ){
        //call hideConsole method
    }
}


void HW02App::update()
{
	// show console with controls q, w, e, r, t,


	// call addNode for 3 rects


	// keep the instructions in the console screen
	 console() << "Press Q for something. \n Press W for something else. \n Press E for something else. \n Press T for something else. \n Press ? to toggle the display. \n "  << std::endl;

}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 



}

CINDER_APP_BASIC( HW02App, RendererGl )
