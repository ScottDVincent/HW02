/*
 * @file Rect.cpp
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

//#include "cinder/gl/gl.h"
#include "math.h"
#include "Rect.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;		// standard library


	
	/** 
	Default Rect constructor
	*/  
	Rect::Rect(){
	}

	/**
	*
	*/
	Rect::Rect (float x1, float y1, float x2, float y2, Color8u inColor, int shake ) {	
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;

		inColor_ = inColor;
		shakeFactor_ = shake;
		
}


	/**
void randomColor(){
     int rand_red_ =   rand()%256;		//use modulus to get a random color
     int rand_green_ = rand()%256;
     int rand_blue_ =  rand()%256;
}
*/


void Rect::shakeMore(){ 
	// would this update the shakeFactor_ for each object?
	//shakeFactor_ += shakeFactor_;
	// or would I need to do this with a loop?
	
	/**
	 for (Node* cur_ = sentinel->next_; cur_ != sentinel; cur_ = cur_->next_)
		{
		       cur_-> data_ -> shakeFactor_ += shakeFactor_;		//for each data_ member of each node call the drawRect method
		}
	 */
}

void Rect::shakeLess(){
	shakeFactor_ -= shakeFactor_;
}

	
void Rect::drawRect(){

//using cinder: http://libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html

	int shadowOffset = 3;
	int shake = rand()%shakeFactor_;
	shadowOffset += shake;

	// Create a Drop Shadow for each rectangle giing depth to an object [Goal H]
		// turn on alpha blending
		gl::enableAlphaBlending();
		//activate the alpha channel
		gl::color(ColorA(0.0f,0.0f,0.0f,0.25f));
		// draw a rectangle offset from the primary rect
		gl::drawSolidRect(Rectf (x1_+shadowOffset, y1_+shadowOffset, x2_+shadowOffset, y2_+shadowOffset),  6.0f);
		//turn off alpha
		gl::disableAlphaBlending();	

		// set the color of the list rectangle		
		gl::color(inColor_);	
		// draw list rectangle
		gl::drawSolidRect(Rectf (x1_+ shake, y1_+ shake, x2_+shake, y2_+shake) );
		
}

/**

// original rect code from HW01

	void Rect::drawRect(uint8_t* pixels, int x_width, int y_height, int x_origin, int y_origin, Color8u cn) {

		if ( (x_width < AppWidth) && (y_height < AppHeight) ){
		
		// start at y_origin
		for ( int y = y_origin; y <= (y_height); y++ ){
			for ( int  x = x_origin; x <= (x_origin + x_width); x++ ) {
				pixels [3* (x + y*(TextureSize))  ] = c.r;
				pixels [3* (x + y*(TextureSize))+1] = c.g;
				pixels [3* (x + y*(TextureSize))+2] = c.b;
				//rect_width-1
				}
			}
		} //end if

	} // end drawRect
*/



