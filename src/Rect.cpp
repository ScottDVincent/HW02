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
	*Default Rect constructor
	*/  
	Rect::Rect(){
	}

	/**
	*Rect constructor
	*/
	Rect::Rect (float x1, float y1, float x2, float y2, Color8u inColor, int shake ) {	
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;

		inColor_ = inColor;
		shakeFactor_ = shake;
}


void Rect::shakeMore(){ 

	if (shakeFactor_ < 10) 
	++shakeFactor_; 
}

void Rect::shakeLess(){

	if (shakeFactor_ > 0) 
	--shakeFactor_; 
}

	
void Rect::drawRect(){

//using cinder: http://libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html

	int shadowOffset = 3;
	int shake = rand()%shakeFactor_;
	shadowOffset += shake;

	// Create a Drop Shadow for each rectangle giing depth to an object [Goal H]
		// turn on alpha blending
		//http://libcinder.org/docs/v0.8.2/namespacecinder_1_1gl.html#a2cb8982a5a007376031745ac074bed4c
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






