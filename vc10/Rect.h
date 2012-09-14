/*
 * @file Rect.h
*
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


/**
// our Rectangle class
*/

class Rect{
public:		

	///Constructors

	Rect ();	// no argument constructor
	Rect (int position, int startX, int startY, int width, int height);  // argument constructor

	///Methods

	/**
	drawRect
	@param: int position
	@param: int startX
	@param: int startY
	@param: int width
	@param: int height
	*/
	void drawRect(int position, int startX, int startY, int width, int height);


};     // end declarations and Rect.h file