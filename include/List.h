/* 
 * @file List.h
 *  
 * @author Scott Vincent
 * @date 09-09-2012
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, mashup and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */



#pragma once
#include "Rect.h"

class Node{
public:		

//constructors
	Node();
	Node(Rect* data, Node* node);

			
	// External node pointers to the list
	Node* next_;
	Node* prev_;
	Node* children_;

	// a Rect object to hold data	
	Rect* data_;		

	int nodeCount_;
		
};   // end member declarations



	/**
	 @name: insertAfter
	 @param: Rect  : the rectangle object 
	 @param: Node* : a node pointer to where the item is being placed in the list

	 This is my "add a new" node and it creates a new node, with rect object and next_ and prev_ pointers
	 ? should I take a the pointer in by reference (&) or by value (*)?  == by (*) for pointers

	*/
	void insertAfter (Rect* new_rect, Node* current);

	/**
	 @name: addChild
	 @param: Rect  : the rectangle object 
	 @param: Node* : a node pointer to where the item is being placed in the list
	*/
	void addChild (Rect* childRect, Node* parentNode);
	

	/**
	* void deleteNode
	* @param Node* delNode: Pointer to addy of the node to be deleted
	*/
	void deleteNode (Node* delNode);


	/**
	* void reverseList
	* reverses the list items from the end
	* 	*/
	void reverseList (Node* sentinal);


	/**
	* void reorderList
	* @param Node* fromNode: 
	* @param Node* toNode:
	* Moves the fromNode to after the toNode
	*/
	void reorderList (Node* fromNode, Node* toNode);
		


	/**
	* void traverseList
	* traverses the list starting from the sentinel node
	* send to display
	*/
	void traverseList (Node* sentinel);
	

	/**
	* void diplayList
	* @param node* inNode 
	* calls the drawRect function 
	*/
	void displayNode (Node* inNode);
	

	/**
	* void diplayList
	* @param node* inNode 
	* adds a child node at the node passed in
	*/
	void addChild(int inNode);


	/**
	* int nodeCount
	* return an int with the number of nodes, including the sentinel 
	*/
	int nodeCount ();


	/**
	* bool isEmpty();
	* returns true if at end of list
	*/
	bool atEnd();


	/**
	* bool isEmpty();
	* returns true if list is empty. 
	* really shouldn't need this as I'm planning to go with a never-empty list
	*/
	bool isEmpty();


   