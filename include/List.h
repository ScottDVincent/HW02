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
 *

 */
/**
// other ideas
http://www.martinbroadhurst.com/articles/circular-linked-list.html


 */ 

/**
	// our linked list data structure, but really we are using a class so we shouldn't need this
		struct node {
			//Item item; 	   		// place for the data
			Rect rect;				// Rect object
			//int item;				// place for the data
			node* nextNode;			// a pointer named next of type 'node'
		

		    /// from book -- declares what a node is
			node(LinkedList x, node* t)	
			{
			   rect = x; next = t; // rect is x and next node pointer is t
			};
			
		
	}  *root ;  // end struct


		// link is a pointer node type
		typedef node* link;


		// initalize each new node when we construct it.
		// have to give the pointer a valid addy before using it
		link t = new node(x, t);

*/

////////////////////////////////////////

#include "Rect.h"

class Node{
public:		

	// constructor
	Node();
	Node(Rect* data, Node* node);

			
	/**
	Member Variables
    */


	// External node pointers to the list
	//Node* cur_;
	Node* next_;
	Node* prev_;
	//Node* children_;

	// a Rect object to hold data	
	Rect* data_;		
		
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
	int nodeCount (Node* sentinel);


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


   