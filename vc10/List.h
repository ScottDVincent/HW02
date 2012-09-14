/* * @file Node.h
 *  
 * @author Scott Vincent
 * @date 09-09-2012
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 *

 * this is an example INTERFACE from the text:

	
		// other ideas
		http://www.martinbroadhurst.com/articles/circular-linked-list.html


 */ 

	// our linked list data structure
		struct node {
			//Item item; 	   		// place for the data
			Node rect;				// Rect object
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


class Node{
public:		

	//LinkedList ();	// no argument constructor

	Node() {

		root = NULL;
	}
		
	/**
	Member Variables

	/// TYPES: from books
		typedef int Item;
		struct node { Item item; node *next; };
		typedef node *link;
		typedef link Node;
	*/


	Node* next_;
	Node* previous_;
	Node* child_;

	Rect data_;

	


	/**
	Member Methods
	
		/// METHODS: from books
		void construct(int);
		Node newNode(int);
		void deleteNode(Node);
		void insert(Node, Node);
		Node remove(Node);
		Node next(Node);
		Item item(Node);

	*/


	/**
	 @name: _insert_after
	 @param: Node*
	 @param: Rect 
	*/
	void _insert_after (Node* where, Rect new_rect);


	
	/**
	* @param Rect new_rect: The addy of addRect object
		
	? do I need to pass in the Rect* next_rect ?

	 ? should I take a the pointer in by reference (&) or by value (*)?
	 == by (*) for pointers
	*/
	void addNode (Node* new_Node, Node* next_Node);
	

	/**
	* @param Rect new_rect: The addy of addRect object
		
	? do I need to pass in the Rect* next_rect ?

	 ? should I take a the pointer in by reference (&) or by value (*)?
	 == by (*) for pointers
	*/
	void insert_after (Node* where, Rect new_rect){


	}

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void deleteNode (Node* new_rect, Node* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reverseList (Node* new_rect, Node* next_rect);


	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void reorderList (Node* new_rect, Node* next_rect);

	/**
	* @param Rect* new_rect: Pointer to addy of new_rect object
	* @param Rect* next_rect: Pointer to addy of the link next_rect
	*/
	void traverseList (Node* new_rect, Node* next_rect);
	

	/**
	* @param int num: 
	* @param node* t: 
	*/
	void displayList (int num, node* t);


	/**
	* @param int num: 
	* @param node* t: 
	*/
	int CountItems ();

private:
	


};     // end declarations and Node.h file