//xander maniaci
#include <iostream>
#include <iomanip>

using namespace std;
//constant global variable
const int NUM_TESTS = 4;  //a global constant
//struct declaration
struct StudentData
{
    string name;
    int id;
    int scores[NUM_TESTS];
    double average;
    char grade;

    //default constructor.
    StudentData()
    {
        int id = 0;
        int scores[NUM_TESTS];
        double average = 0;
        char grade = ' ';

    }
    //build in struct function. for getting input.
    void getData()
    {
        //pre: obtains a struct variable from main.
        //post:fills the struct variable
        cout<<"Student name: ";
        cin.clear();
        cin.ignore(1,'/n');
        getline(cin, name);
        cout<<"ID Number: ";
        cin>>id;
        average = 0;//encountered a strange bug where if there where three students the average would display improperly on the third student. this fixes it.
        for(int counter = 0;counter < NUM_TESTS;counter++)//for loop to get test scores for array variable in
        {
            cout<<"\tTest # "<<counter+1<<": ";
            cin>>scores[counter];
            average+=scores[counter];
        }
        average /= 4;//caclulates average and sets char grade to proper grade letter.
        if(average>=91)
        {
            grade = 'A';
        }else if(average >= 81 && average < 91)
        {
            grade = 'B';
        }else if(average >= 71 && average < 81)
        {
            grade = 'C';
        }else if(average >= 61 && average < 71)
        {
            grade = 'D';
        }else if( average < 61)
        {
            grade = 'F';
        }


    }
    //build in void function for displaying data.
    void displayData()
    {
        //pre:gets struct variable
        //post:gets input for struct variable
        cout<<"student name: "<<name<<endl;
        cout<<"ID number: "<<id<<endl;
        cout<<"Average test score: "<<fixed<<setprecision(1)<<average<<endl;
        cout<<"Grade: "<<grade<<endl;
    }

};


int main()
{
    StudentData *student = nullptr;
    int Size;

    cout<<"How many students? ";
    cin>> Size;
    while(!cin || Size < 1)//input validation
    {
     cin.clear();
     cin.ignore(200,'/n');
     cout<<"bad data please retype.";
     cout<<"How many students? ";
     cin>> Size;
    }
    student = new StudentData [Size];//created a dynamic struct array

    for(int counter = 0; counter < Size;counter++)//for loops call built in function to get data for each index of struct array.
    {
        student[counter].getData();
    }
    cout<<endl;
    cout<<"===========================\nCourse Grade Report\n==========================="<<endl;
    for(int counter = 0; counter < Size;counter++)// calls the build in display function for each struct variable in the array.
    {
        student[counter].displayData();
        cout<<endl;
    }

    delete [] student;//garbage collects dynamic struct array once program is done.
    student = nullptr;
    return 0;
}
/*
How many students? 4
Student name: Joe Blow
ID Number: 3478
        Test # 1: 65
        Test # 2: 57
        Test # 3: 68
        Test # 4: 72
Student name: Jon Tron
ID Number: 3276
        Test # 1: 89
        Test # 2: 87
        Test # 3: 79
        Test # 4: 84
Student name: Jack Black
ID Number: 7256
        Test # 1: 83
        Test # 2: 7
        Test # 3: 43
        Test # 4: 21
Student name: Dave Wave
ID Number: 2397
        Test # 1: 97
        Test # 2: 89
        Test # 3: 92
        Test # 4: 78

===========================
Course Grade Report
===========================
student name: Joe Blow
ID number: 3478
Average test score: 65.5
Grade: D

student name: Jon Tron
ID number: 3276
Average test score: 84.8
Grade: B

student name: Jack Black
ID number: 7256
Average test score: 38.5
Grade: F

student name: Dave Wave
ID number: 2397
Average test score: 89.0
Grade: B


Process returned 0 (0x0)   execution time : 158.840 s
Press any key to continue.*/



