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
	void prepareSettings(Settings* settings);
	void setup();
	void update();
	void draw();


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

	/**create Head node
	*
	*/
	// make node call
	// addNode();

}


void HW02App::mouseDown( MouseEvent event )
{
	//int x = event.getX();
	//int y = event.getY();
	
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

}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW02App, RendererGl )
