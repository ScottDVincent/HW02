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

#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h";
#include "Rect.h"
#include "list.h"

using namespace ci;
using namespace ci::app;
using namespace std;		// standard library

class Rect {

public:

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

private:

}  // end definitions and 
