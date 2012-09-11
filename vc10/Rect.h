/*
 * @file Rect.h
 *  This is really a
 * linked data structure as well.
 *
 * @author Scott Vincent
 * @date 09-09-2012
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 *

 * this is an example INTERFACE from the text:

		/// TYPES
		typedef int Item;
		struct node { Item item; node *next; };
		typedef node *link;
		typedef link Node;

		/// METHODS
		void construct(int);
		Node newNode(int);
		void deleteNode(Node);
		void insert(Node, Node);
		Node remove(Node);
		Node next(Node);
		Item item(Node);

 */ 

	// our linked list data structure
		struct node {
			//Item item; 	   		// place for the data
			Rect rect;				// Rect object
			//int item;				// place for the data
			node* next;			    // a pointer named next of type 'node'
		
		    /// from book -- declares what a node is
			node(Rect x, node* t)	
			{
			   rect = x; next = t; // rect is x and next node pointer is t
			};
		
	};  // end struct


		// link is a pointer node type
		typedef node* link;


		// initalize each new node when we construct it.
		// have to give the pointer a valid addy before using it
		link t = new node(x, t);


/**
// our Rectangle class
*/

class Rect{
public:		

	Rect ();	// no argument constructor
	Rect (int position, int startX, int startY, int width, int height);  // argument constructor
	
	/// Bo's constructor
	//Diamond(int depth, ci::Vec2f position, float radius); 


	//Methods
	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	
	? do I need to pass in the Rect* next_rect ?

	 ? should I take a the pointer in by reference (&) or by value (*)?
	 == by (*) for pointers
	*/
	void addNode (Rect* new_rect, Rect* next_rect);
	


	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void deleteNode (Rect* new_rect, Rect* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reverseList (Rect* new_rect, Rect* next_rect);


	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reorderList (Rect* new_rect, Rect* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void traverseList (Rect* new_rect, Rect* next_rect);
	

	/**
	* @param int num: 
	* @param node* t: 
	*/
	void displayNode (int num, node* t);


};     // end declarations and Rect.h file