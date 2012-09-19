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

#include "Rect.h";

class Node{
public:		

	// constructor
	Node();
	//Node(Node* sentinal);
	Node(Rect* rect, Node* node);

			
	/**
	Member Variables

	/// TYPES: from book
		typedef int Item;
		struct node { Item item; node *next; };
		typedef node *link;
		typedef link Node;
	*/

	// list specific
	int length();
	bool empty(); 
	bool atEnd();
	bool isEmpty;


	// External node pointers to the list
	
	Node* sentinel_;
	Node* cur_;
	Node* next_;
	Node* prev_;
	Node* children_;

	Rect* rect_;		// a Rect object to hold data	
		


	/**
	Member Methods
	
		/// METHODS: from book
		void construct(int);
		Node newNode(int);
		void deleteNode(Node);
		void insert(Node, Node);
		Node remove(Node);
		Node next(Node);
		Item item(Node);

	*/


	/**
	 @name: insertAfter
	 @param: Rect  : the rectangle object 
	 @param: Node* : a node pointer to where the item is being placed in the list

	 This is my "add a new" node and it creates a new node, with rect object and next_ and prev_ pointers

		 ? should I take a the pointer in by reference (&) or by value (*)?  == by (*) for pointers

	*/
	void insertAfter (Rect new_rect, Node* current);


	
	/**
	* void deleteNode
	* @param Node* delNode: Pointer to addy of the node to be deleted
	*/
	void deleteNode (Node* delNode);


	/**
	* void reverseList
	* reverses the list items
	* 	*/
	void reverseList ();

	/**
	* void reorderList
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Node* 

	? reordering based on what parameter?
	*/
	void reorderList (Node* new_rect, Node* next_rect);



	/**
	* void traverseList
	* traverses the list starting from the beginning
	* send to display
	*/
	void traverseList ();
	

	/**
	* void diplayList
	* @param node* t: 
	* diplays the list starting from the node argument
	*/
	void displayNode (Node* t);
	

	/**
	* int CountItems
	* returns an int of number of nodes 
	*/
	int CountItems ();


	


};     // end declarations and Node.h file