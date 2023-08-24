// This program demonstrates various ways to setup structs for data collection.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
   string name;			  // Student's name
   int idNum;             // Student ID number
   int creditHours;       // Credit hours enrolled
   double gpa;			  // Current GPA
};

void getData(Student *);  // Function prototype
void showData(Student *);  // Function prototype

int main()
{
   Student freshman; //memory allocated in stack
   int numstds = 0;

   Student *stdPtr = nullptr;
   stdPtr = &freshman;

   cout << "Enter the following student data:\n";
   cout << "Student name: ";
 //  getline(cin, freshman.name);
   getline(cin, stdPtr->name);

   cout << "Student ID Number: ";
  // cin >> freshman.idNum;
   cin >> stdPtr->idNum;

   cout << "Credit Hours Enrolled: ";
 //  cin >> freshman.creditHours;
   cin >> stdPtr->creditHours;

   cout << "Current GPA: ";
  // cin >> freshman.gpa;
   cin >> stdPtr->gpa;
   //getData(&freshman);    // Pass the address of freshman.
   //  getData(stdPtr);
   cout << "\nHere is the student data you entered:\n";
   showData(stdPtr);

   cout<<"Member addresses: " <<int(&freshman) << " " <<int(&freshman.name) << " " << int(&freshman.idNum)
        << " " << int(&freshman.creditHours) << " " <<int(&freshman.gpa) <<endl;
   cout <<"Bytes utilized for struct variable: "<<sizeof(Student)<<endl;
   cout <<"Beginning and end of struct variable addresses: "<<int(stdPtr) << " "<< int(stdPtr+1)<<endl;
   cout <<"Memory utilized for variable: " << int(stdPtr+1) - int(stdPtr) <<endl<<endl;

   // Now display the data stored in freshman
/*   cout << setprecision(3);
   cout << "Name: " << freshman.name << endl;
   cout << "ID Number: " << freshman.idNum << endl;
   cout << "Credit Hours: " << freshman.creditHours << endl;
   cout << "GPA: " << freshman.gpa << endl;*/

   Student *stdPtr2 = nullptr;
   stdPtr2 = new Student; //memory block in heap
   //assignment to struct members using member assignment operator
   stdPtr2->name = "Shane Sarkar";
   stdPtr2->idNum = 2345;
   stdPtr2->creditHours = 21.0;
   stdPtr2->gpa = 3.59;

   showData(stdPtr2);

   cout <<"Bytes utilized for struct variable: "<<sizeof(Student)<<endl;
   cout <<"Beginning and end of struct variable addresses: "<<int(stdPtr2) << " "<< int(stdPtr2+1)<<endl;
   cout <<"Memory utilized for variable: " << int(stdPtr2+1) - int(stdPtr2) <<endl;

    delete stdPtr2;
    stdPtr2 = nullptr;

    cout<<stdPtr2 <<endl;

    cout<< "How many students enrolled in Virtual.edu: ";
    cin  >> numstds;
    cin.ignore();

    stdPtr2 = new Student[numstds]; //memory block in heap

//    for(stdPtr2 = Student; stdPtr2 < &Student[numstds]; stdPtr++)
    for(int i = 0; i < numstds; i++)
    {
        getData(stdPtr2);
    }

    showData(stdPtr2);

   cout <<"Bytes utilized for struct array: "<<sizeof(Student[numstds])<<endl;

   return 0;
}

//*******************************************************
// Definition of function getData. Uses a pointer to a  *
// Student structure variable. The user enters student  *
// information, which is stored in the variable.        *
//*******************************************************

void getData(Student *s)
{
   cout << "Student name: ";
   getline(cin, s->name);

   cout << "Student ID Number: ";
   cin >> s->idNum;

   cout << "Credit Hours Enrolled: ";
   cin >> s->creditHours;

   cout << "Current GPA: ";
   cin >> s->gpa;
   cin.ignore();
   cout<<endl<<endl;
}


void showData(Student *s)
{
   cout << "Student name: " << s->name <<endl;
   cout << "Student ID Number: " << s->idNum <<endl;
   cout << "Credit Hours Enrolled: " << s->creditHours <<endl;
   cout << "Current GPA: " << s->gpa <<endl;
}
