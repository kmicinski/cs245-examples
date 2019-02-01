// Classes, Scopes, Stacks, and Argument passing..
#include <iostream>

using namespace std;

// Let's start by just writing out the most basic structural type: a
// struct!

// A struct in C++ is a collection of member variables, plus
// methods. This is different than in the C langauge.  In C++, structs
// are more like classes.
// 
// The main difference between a struct and a class is that by default
// everything is public. Stylistically, structs are used for data
// rather than computation.
struct SquareStruct {
    int x;
    int y;
    int sideLen;
    
    // One method on a struct. Note that sideLen implicitly talks
    // about `this` (i.e., the struct on which it is called)
    int getArea() { return sideLen * sideLen; }

    // Let's also add a constructor
    // Note use of initialization list syntax
    SquareStruct(int x, int y, int sideLen)
	: x(x), y(y), sideLen(sideLen) { 
	cout << "SquareStruct" << endl;
    }
    
    // Now let's add a *destructor*. The destructor is called whenever
    // the object is destroyed.  The destructor takes care of
    // "cleaning up" data held by the struct / class. In this case
    // there's nothing to clean up, but we'll do something to
    // understand when it's called.
    ~SquareStruct() { cout << "~SquareStruct" << endl; }
};

// A class is like a struct, except by default data is private. 
class Square {
    // We can put the specifier here, but if we didn't it would be
    // private anyway.
    private:
    int x; // member variable x
    int y;
    int sideLen;
    // Private constructor means object can't be created!
    // Square(int x, int y, int side)
    // 	: x(x), y(y), sideLen(side) { }
    public:
    Square(int x, int y, int side)
	: x(x), y(y), sideLen(side) { }

    // Accessor methods ("getters")
    int getX() { return x; }
    int getY() { return y; }
    int getArea() { return sideLen * sideLen; }
};

// A struct for points.
struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) { 
	cout << "Point created" << endl;
    }

    Point(const Point &other) {
	cout << "copy constructor called!" << endl;
	x = other.x;
	y = other.y;
    }

    ~Point() {
	cout << "Point deleted" << endl;
    }
};

// For the next example, we're going to need a math utility
// function. It's nice style to put it in a namespace. (I normally
// wouldn't do this for a small program but useful in big programs.)
namespace Utils {
    double abs(double v) {
	if (v < 0) { return -v; }
	return v;
    }
};

// A triangle class
class Triangle {
    private:
    Point p1;
    Point p2;
    Point p3;

    public:
    // Note that the constructor passes by *const reference*.
    // Let's add some code to Point to see what happens.
    // Triangle(const Point& p1,const Point& p2,const Point& p3)
    // 	: p1(p1), p2(p2), p3(p3) { 
    // 	// Note that to construct p1, p2, and p3, the *copy*
    // 	// constructor is called (a default one is created if none is
    // 	// specified).  And specifically: note that the copy
    // 	// constructor is called *before* "Triangle created!" is
    // 	// printed. This is because the init list runs before the
    // 	// function!
    // 	cout << "Triangle created!" << endl;
    // }

    // Now: what happens if we pass by value instead?
    Triangle(Point p1,Point p2,Point p3)
	: p1(p1), p2(p2), p3(p3) { 
	cout << "Triangle created!" << endl;
    }

    ~Triangle() {
	cout << "Triangle deleted!" << endl;
    }

    // Area formula for a triangle. I looked this up.
    double getArea() {
	return .5 * Utils::abs(p1.x*p2.y + p2.x * p3.y + p3.x*p1.y
			       - p1.x*p3.y - p3.x*p2.y - p2.x*p1.y);
    }
};

int main() {
    cout << "begin of main()" << endl;
    Point p0(0,0);
    Point p1(0,1);
    Point p2(1,0);
    // When calling functions by value, C++ creates a *copy* of the
    // object to pass on to the function being called (in this case
    // the constructor). This is slower than passing by
    // reference. Note that this causes six rather than three copies.
    Triangle(p0,p1,p2);
    // SquareStruct sstruct(1,2,3);
    // cout << sstruct.getArea() << endl;
    // // Creating new scopes happens with { }. Local variables that
    // // appear inside of new scopes are allocated on the stack.
    // {
    // 	cout << "creating ss2 now" << endl;
    // 	{
    // 	    cout << "creating ss3 now" << endl;
    // 	    SquareStruct ss3(0,0,1);
    // 	    cout << "leaving subscope" << endl;
    // 	}
    // 	SquareStruct ss2(2,4,8);
    // 	cout << "leaving subscope" << endl;
    // }
    cout << "end of main()" << endl;
    // Note that the object "dies" at the end of the scope
}

// Thanks for watching! Your assignment is to send me an example of a
// small class or struct you created and illustrate one use of scopes
// that shows you understand a bit about how scopes and constructors
// work. Additionally: your assignment is also to send me an example
// that uses `new` and `delete` and shows me what happens when you do
// that! `kris@cs.haverford.edu`. Good luck!
