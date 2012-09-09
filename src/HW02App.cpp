#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

//#include "cinder/app/App.h"
// #include Rectangle.h class
// #include HW02App.h 

using namespace ci;
using namespace ci::app;
using namespace std;

// this HW02App should go in a header file
class HW02App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	
	private:

		//Width and height of the screen
		static const int AppWidth=800;
		static const int AppHeight=600;
		static const int TextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
	

		
		//construct a Rectangle object
		// Rectangle rect();	// no argument constructor
		// Rectangle rect(int startX, int startY, int width, int height);  // argument constructor


	
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
		link t = new node(x, t)


		//Methods
		/**
		* int: takes an int for data
		* 
		*/
		void addNode (int num, node* t);

		/**
		*/
		void deleteNode (int num, node* t);

		/**
		* int: takes an int for data
		* 
		*/
		void reverseList (int num, node* t);


		/**
		* int: takes an int for data
		* 
		*/
		void reorderNode (int num, node* t){

};


// argument is a int, Rect object for project
void addNode (int num, node* t){
	t->next = x->next;	//(1) sets t pointer to value that x pointer has
	x->next = t;       //(2) change x pointer to t node
}


// argument is a int, Rect object for project
void deleteNode (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to
	delete t;			//(3) the memory space for t is deleted 
}

// argument is a int, Rect object for project
void reverseList (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}

// argument is a int, Rect object for project
void reorderNode (int num, node* t){
	t = x->next;		//(1) sets t up as the link from x
	x->next = t->next;   //(2) x link points to whatever t link points to

}



void HW02App::setup()
{

	/**create Head node
	*
	*/
	// make node call
	// addNode();

}

/**
void HW02App::mouseDown( MouseEvent event )
{
	//int x = event.getX();
	//int y = event.getY();
	
}
*/
/**
libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html
*/
void  HW02App::keyDown( KeyEvent event ) {
    if( event.getChar() == 'q' ){
        // call delete first node
    } else if( event.getChar() == 'e' ){
        //call add rect node
    } else if( event.getChar() == 't' ){
        // call reverse node
    } else if( event.getChar() == 'r' ){
        //call move rect node
    }
}


void HW02App::update()
{
	// call add to link list for 3 three

}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW02App, RendererGl )
