/* This program rect_struct.cpp uses a structure to hold data about a rectangle
   Fill in the code as indicated by the comments.
   Add code to the program above so that the modified program will determine
   whether or not the rectangle entered by the user is a square.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats
struct Rectangle
{
    float length;
    float width;
    float area;
    float perimeter;
} box;

int main()
{
	// Fill in code to define a rectangle variable named box



	// Fill in code to read in the length member of box
	cout << "Enter the length of a rectangle: ";
	cin>> box.length;


        // Fill in code to read in the width member of box
	cout << "Enter the width of a rectangle: ";
	cin>> box.width;



	cout << endl << endl;

	// Fill in code to compute the area member of box

	box.area = box.length * box.width;
	// Fill in code to compute the perimeter member of box
	box.perimeter = 2*(box.length + box.width);

	cout << fixed << showpoint << setprecision(2);

	// Fill in code to output the area with an appropriate message
    cout<<"The are of a Rectangle is "<<box.area<<endl;

	// Fill in code to output the perimeter with an appropriate message
    cout<<"the perimeter of the rectangle is "<<box.perimeter<<endl;
    if(box.length == box.width)
    {
        cout<<"the Rectangle is a square"<<endl;
    }else
    {
        cout<<"the Rectangle is not a square"<<endl;
    }
	return 0;
}

/*A sample compile/run of the above program

Enter the length of a rectangle: 7
Enter the width of a rectangle: 7


The area of the rectangle is 49.00
The perimeter of the rectangle is 28.00
The rectangle is a square

Process returned 0 (0x0)   execution time : 10.907 s
Press any key to continue.
*/

