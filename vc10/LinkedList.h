/* * @file LinkedList.h
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




/**
// our Rectangle class
*/

class LinkedList{
public:		

	//LinkedList ();	// no argument constructor

	LinkedList() {

		root = NULL;
	}
		
		
	// Rect(int position, int startX, int startY, int width, int height);  // argument constructor
	
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
	void addNode (LinkedList* new_rect, LinkedList* next_rect);
	


	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void deleteNode (LinkedList* new_rect, LinkedList* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reverseList (LinkedList* new_rect, LinkedList* next_rect);


	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reorderList (LinkedList* new_rect, LinkedList* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void traverseList (LinkedList* new_rect, LinkedList* next_rect);
	

	/**
	* @param int num: 
	* @param node* t: 
	*/
	void displayNode (int num, node* t);


	/**
	* @param int num: 
	* @param node* t: 
	*/
	int CountItems ();

private:
		// our linked list data structure
		struct node {
			//Item item; 	   		// place for the data
			LinkedList rect;		// Rect object
			//int item;				// place for the data
			node* nextNode;			// a pointer named next of type 'node'
		
		    /// from book -- declares what a node is
			/**
			node(LinkedList x, node* t)	
			{
			   rect = x; next = t; // rect is x and next node pointer is t
			};
			*/
		
	}  *root ;  // end struct


		// link is a pointer node type
		typedef node* link;


		// initalize each new node when we construct it.
		// have to give the pointer a valid addy before using it
		link t = new node(x, t);


};     // end declarations and Rect.h file