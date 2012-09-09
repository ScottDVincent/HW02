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
 */ 

class Rect{
public:		

	
	Rect rect();	// no argument constructor
	Rect rect(int position, int startX, int startY, int width, int height);  // argument constructor
	//Rect(int depth, ci::Vec2f position, float radius);

	// our linked list data structure
		struct node {
			//Item item; 	   		// place for the data
			int item;				// place for the data
			node* next;			    // a pointer named next of type 'node'
			
			node(int x, node* t)	
			{
			 item = x; next = t;};
		};

		// link is a node type
		typedef node* link;

		// initalize each new node when we construct it.
		// have to give the pointer a valid addy before using it
		link t = new node(x, t);


		//Methods
		/**
		* int: takes an int for data
		* node: should I take a the pointer in by reference (&) or by value (*)?
		*/
		void addNode (int num, node*);

		/**
		*/
		void deleteNode (int num, node*);

		/**
		* int: takes an int for data
		* 
		*/
		void reverseList (int num, node*);


		/**
		* int: takes an int for data
		* 
		*/
		void reorderNode (int num, node*);

		/**
		* int: takes an int for data
		* 
		*/
		void traverseList (int num, node*);
	


		/**
		* int: takes an int for data
		* 
		*/
		void displayNode (int num, node*);


};     // end declarations and Rect.h file