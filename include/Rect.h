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

#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"

using namespace ci;


class Rect{
public:		

	///Constructors

	Rect ();																  // no argument constructor
	Rect (float x1, float y1, float x2, float y2, Color8u color, int shake);  //cinder construct
	
	// old code: Rect (uint8_t* pixels, int x_width, int y_height, int x_origin, int y_origin, Color8u c);  // argument constructor


	/// Member Variables
	// pointers to nodes, perhaps use here or else have these pointers in the Node class
	// ? I'm not sure I need Rect next & prev pointers ? as I will handle this in the node class
	Rect* rectNext_;
	Rect* rectPrev_;


	//uint8_t* pixels; int x_width; int y_height;	int x_origin; int y_origin;	Color8u c;

	// for rect shape
	float x1_, y1_, x2_, y2_;
	Color8u inColor_;
	uint8_t* newColor; 
	
	//Color8u colorRect;
    int shakeFactor_ ;

	
	/// Member Methods
	void randomColor();
	void shake(int shakeFactor);

	void shakeMore();
	void shakeLess();
	
	/**
	drawRect
	@param: int x1
	@param: int y1
	@param: int x2
	@param: int y2
	@param: Color8u (c.red, c.blue, c.green)
	@param: int shake
	*/
	void drawRect();

};     // end declarations and Rect.h file	


