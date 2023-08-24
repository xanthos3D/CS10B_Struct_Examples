// This program demonstrates a function that uses a
// pointer to a structure variable as a parameter.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
   string name;			// Student's name
   int idNum;             	// Student ID number
   int creditHours;       	// Credit hours enrolled
   double gpa;	            // Current GPA

   Student()//default constructor
   {
        name = "unknown";
        idNum = 0;
        creditHours = 0;
        gpa = 0;

   }

   Student(string n,int i, int ch,double g)//parameterized constructor
   {
        name = n;
        idNum = i;
        creditHours = ch;
        gpa = g;

   }
   void getInput()
   {
       cout << "Student name: ";
   getline(cin, name);

   // Get the student ID number.
   cout << "Student ID Number: ";
   cin >> idNum;

   // Get the credit hours enrolled.
   cout << "Credit Hours Enrolled: ";
   cin >> creditHours;

   // Get the GPA.
   cout << "Current GPA: ";
   cin >> gpa;
   }
};

void getData(Student *);
void showData(Student *);  // Function prototype

int main()
{
   Student freshman, freshman2;

   Student freshman3("xander maniaci",6743,3,3.25);

   // Get the student data.
   showData(&freshman);
   showData(&freshman3);
   freshman2.getInput();
   showData(&freshman2);
   cout << "Enter the following student data:\n";
   getData(&freshman);    // Pass the address of freshman.
   cout << "\nHere is the student data you entered:\n";
   showData(&freshman);

   // Now display the data stored in freshman
   /*cout << setprecision(3);
   cout << "Name: " << freshman.name << endl;
   cout << "ID Number: " << freshman.idNum << endl;
   cout << "Credit Hours: " << freshman.creditHours << endl;
   cout << "GPA: " << freshman.gpa << endl;
   */
   return 0;
}

//*******************************************************
// Definition of function getData. Uses a pointer to a  *
// Student structure variable. The user enters student  *
// information, which is stored in the variable.        *
//*******************************************************

void getData(Student *s)
{
   // Get the student name.
   cout << "Student name: ";
   getline(cin, s->name);

   // Get the student ID number.
   cout << "Student ID Number: ";
   cin >> s->idNum;

   // Get the credit hours enrolled.
   cout << "Credit Hours Enrolled: ";
   cin >> s->creditHours;

   // Get the GPA.
   cout << "Current GPA: ";
   cin >> s->gpa;
}

void showData(Student *s)
{
    cout << "Student name: "<< s->name<<endl;
    cout<<"Student ID Number: "<<s->idNum<<endl;
    cout<<"Credit Hours Enrolled: "<<s->creditHours<<endl;
    cout<<"Current GPA: "<<s->gpa<<endl;

}
