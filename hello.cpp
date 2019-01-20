/**
 *  "Hello, World" application.
 */

// This header file gives us access to the cout functions.
#include <iostream>

// std::cout means that we are calling the function cout in the `std`
// namespace. A namespace is a C++ concept that lets us create
// collections of functions. You access something in a namespace by
// using namespace::function(...)

// Because the `cout` function is in the `std` namespace, we have to
// use std::cout, which calls the `cout` function through the `std`
// namespace. Instead, we could "open" the namespace by doing this:
using namespace std;

// Let's create our own namespace named `mynamespace`. Remember, a
// namespace is like a folder: all of the declarations for variables,
// functions, classes, structs, etc.. get put under that
// namespace. They are later accessed like mynamespace::x.
namespace mynamespace 
{
    int x = 23;
}

// Let's write ourselves a function!
// A function needs:
//
// - A return type (void in this case)
//   (void means "nothing" i.e., no return value)
// 
// - A name (in this case `helloWorld`)
//
// - A set of formal arguments (i.e., types and names of arguments) We
//   call these "formals" or "formal arguments" or sometimes "named
//   arguments."
// 
// - A definition (function body) with { and }
void helloWorld() 
{
    cout << "Hello again!" << endl;
    
    // A void function has an implicit return at the end of the
    // function definition. But we can insert one anyway.
    return;
}

// Declaring that we have one parameter, n, whose type is int
// (integer).
void printNumber(int n)
{
    cout << "I got the number " << n << "... Great!" << endl;

    // A void function has an implicit return at the end of the
    // function definition. But we can insert one anyway.
    return;
}

// Of course, we can also define functions that return values!
int addOne(int x) 
{
    return x + 1;
}

void printLastElem(int x[], int size) 
{
    cout << "The last element of the array is " << x[size-1] << endl;
    return;
}

// Precondition: 
//  - size is the size of array arr.
//  - size > 0.
// 
// Postcondition: the return value x is the maximum value in array
// arr.
int printAndFindMax(int arr[], unsigned size)
{
    if (size == 0) {
	// Eventually: really want to throw an exception!
	// We'll see how to do this later.
	return -1;
    }
    int max = arr[0];
    
    // While loops work like so...
    // We will *start* by just printing out each element
    int index = 0;
    while (index < size) {
	cout << "The element at array position " << index << " is ";
        cout << arr[index] << endl;
	if (arr[index] > max) {
	    max = arr[index];
	}
	++index; // Increment index by 1
    }

    // Returns *wrong* value!
    return max;
}

// The `main` function takes two arguments:
//  - argc -- declared as an integer, number of arguments to program
// 
//  - argv -- declared as a pointer to a pointer to char, basically an
//  array of strings (we'll see more of this later).
int main(int argc, char **argv) 
{
    // Let's print a message to the user's screen
    std::cout << "Hello, World!\n";

    // Note that if I leave off \n I don't get a newline
    cout << "I don't need to use std::cout here, cout is fine!";

    // There is a variable `endl` in the std namespace that stands in
    // for "\n" (since that can change across systems)
    cout << std::endl;

    // Print out how many arguments were given (the program always has
    // at least one argument: it's name! In this case that's `a.out`)
    cout << "The program was given " << argc << " arguments." << endl;

    // Correctly accessing x in the namespace `mynamespace`
    cout << "The value of x is " << mynamespace::x << endl;

    // This won't work, the definition of x is not visible.  The
    // compiler gives us a "note" to help us find the error.
    // Uncomment this line to see how it works!
    //   cout << "This doesn't work! " << x << endl;

    // To *call* a function we name it and provide its arguments
    // between parentheses
    helloWorld();
    printNumber(23);
    cout << "One plus 5 is " << addOne(5) << endl;

    // We can also define arrays
    int x[5] = {0,1,2,3,4};
    unsigned size = 5; // unsigned means a non-negative integer

    // Arrays are indexed by var[index], with indices starting at 0.
    cout << "The third element of the array x is " << x[3] << endl;

    // Print the last element of the array x
    //cout << "The last element of x is " << x[4] << endl;
    printLastElem(x, 5);

    // We can assign to arrays
    x[4] = x[0];

    // Print the last element of the array x again
    //cout << "The last element of x is " << x[4] << endl;

    // Let's abstract this as a function!
    printLastElem(x, size);

    // Let's write a loop over the array to find the maximum element.
    int max = printAndFindMax(x, size);
    cout << "The maximum number in the array x is " << max << endl;

    // Good luck on lab0!!!
    
    // A return code of 0 indicates "normal" application exit
    // (returning 1 indicates a failure)
    return 0;
}
