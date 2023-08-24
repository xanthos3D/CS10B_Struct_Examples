//xander maniaci
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;
//list of prototypes that do not include a struct
double getValidInput(/*in*/string);

//structure variable willed with doubles.
struct MonthlyBudget
{
    double Housing;
    double Utilities;
    double HouseholdExpenses;
    double Transportation;
    double Food;
    double Medical;
    double Insurance;
    double Entertainment;
    double Clothing;
    double Miscellaneous;

    //default constructor
    MonthlyBudget()
    {
    Housing = 580.00;
    Utilities= 150.00;
    HouseholdExpenses = 65.00;
    Transportation = 50.00;
    Food = 250.00;
    Medical = 30.00;
    Insurance = 100.00;
    Entertainment = 150.00;
    Clothing = 75.00;
    Miscellaneous = 50.00;

    }
    //function build into the struct data type to get the value of expenses.
    void getExpenses()
    {
        //pre:obtains a struct variable from main.
        //post:calls a another function to get the correct input from user for each double within the struct.
        int total;
        cout<<"Enter actual monthly expenditures for each budget category"<<endl<<endl;
        //lot of function calls to getValidInput
        Housing = getValidInput("Housing        $  ");
        Utilities = getValidInput("Utilities      $  ");
        HouseholdExpenses = getValidInput("Household      $  ");
        Transportation = getValidInput("Transportation $  ");
        Food = getValidInput("Food           $  ");
        Medical = getValidInput("Medical        $  ");
        Insurance = getValidInput("Insurance      $  ");
        Entertainment = getValidInput("Entertainment  $  ");
        Clothing = getValidInput("Clothing       $  ");
        Miscellaneous = getValidInput("Miscellaneous  $  ");

    }
};
//list of function prototypes including the struct data type.
void display(/*inout*/MonthlyBudget *,/*inout*/double&);
void compareExpenses(/*inout*/MonthlyBudget *,/*inout*/MonthlyBudget *,/*in*/double,/*in*/string);

int main()
{
    string month = " ";
    double total1 = 0;
   //struct variable declarations
    MonthlyBudget Budget, spent;
    //function call to display the default variable.
    display(&Budget,total1);
    //simple prompt for the month.
    cout<<"Enter month of expenditure: ";
    cin>>month;
    //calls built in function to fell the second variable with user input
    spent.getExpenses();
    compareExpenses(&Budget,&spent,total1,month);//calls the compare expenses function to display data.



    return 0;
}
//void function to display default struct variable.
void display(/*inout*/MonthlyBudget *Budget,/*inout*/double& total)
{
    //pre: obtains a struct variable from main that is default.
    //post: displays the default constructer while also tallying up the total budget allowed and sends it back to main.
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Here is your monthly budget for YEAR 2020:"<<endl<<endl;
    cout<<"Housing        $  "<<Budget->Housing<<endl;
    total+=Budget->Housing;
    cout<<"Utilities      $  "<<Budget->Utilities<<endl;
    total+=Budget->Utilities;
    cout<<"Household      $  "<<Budget->HouseholdExpenses<<endl;
    total+=Budget->HouseholdExpenses;
    cout<<"Transportation $  "<<Budget->Transportation<<endl;
    total+=Budget->Transportation;
    cout<<"Food           $  "<<Budget->Food<<endl;
    total+=Budget->Food;
    cout<<"Medical        $  "<<Budget->Medical<<endl;
    total+=Budget->Medical;
    cout<<"Insurance      $  "<<Budget->Insurance<<endl;
    total+=Budget->Insurance;
    cout<<"Entertainment  $  "<<Budget->Entertainment<<endl;
    total+=Budget->Entertainment;
    cout<<"Clothing       $  "<<Budget->Clothing<<endl;
    total+=Budget->Clothing;
    cout<<"Miscellaneous  $  "<<Budget->Miscellaneous<<endl;
    total+=Budget->Miscellaneous;
    cout<<"================================================="<<endl;
    cout<<"Total Budgeted $ "<<total<<endl;
    cout<<"================================================="<<endl<<endl;


}
//void function to compare and display the budget ,how much was spent, and what the difference is.
void compareExpenses(/*inout*/MonthlyBudget * budg,/*inout*/MonthlyBudget * spent,/*in*/double total1,/*in*/string month)
{
    //pre:obtains two struct variables from main as well as the total for the budget and the month.
    //post: displays the difference of spent and budget in a table. also tallys up the total spent so that it can be displayed at the below in the total row.
    double saved = 0;
    double total2 = 0;
    cout<<fixed<< showpoint<<right<<setprecision(2)<<setw(7);
    cout<<"                 Budgeted     Spent      Difference"<<endl;
    cout<<"================================================="<<endl;
    cout<<"Housing           "<<budg->Housing<<"     "<<right<<setw(7)<<spent->Housing<<"     "<<right<<setw(7)<<(spent->Housing)-(budg->Housing)<<endl;
    saved += (spent->Housing)-(budg->Housing);
    total2 += spent->Housing;
    cout<<"Utilities         "<<budg->Utilities<<"     "<<right<<setw(7)<<spent->Utilities<<"     "<<right<<setw(7)<<(spent->Utilities)-(budg->Utilities)<<endl;
    saved += (spent->Utilities)-(budg->Utilities);
    total2 += spent->Utilities;
    cout<<"Household          "<<budg->HouseholdExpenses<<"     "<<right<<setw(7)<<spent->HouseholdExpenses<<"     "<<right<<setw(7)<<(spent->HouseholdExpenses)-(budg->HouseholdExpenses)<<endl;
    saved += (spent->HouseholdExpenses)-(budg->HouseholdExpenses);
    total2 += spent->HouseholdExpenses;
    cout<<"Transportation     "<<budg->Transportation<<"     "<<right<<setw(7)<<spent->Transportation<<"     "<<right<<setw(7)<<(spent->Transportation)-(budg->Transportation)<<endl;
    saved += (spent->Transportation)-(budg->Transportation);
    total2 += spent->Transportation;
    cout<<"Food              "<<budg->Food<<"     "<<right<<setw(7)<<spent->Food<<"     "<<right<<setw(7)<<(spent->Food)-(budg->Food)<<endl;
    saved += (spent->Food)-(budg->Food);
    total2 += spent->Food;
    cout<<"Medical            "<<budg->Medical<<"     "<<right<<setw(7)<<spent->Medical<<"     "<<right<<setw(7)<<(spent->Medical)-(budg->Medical)<<endl;
    saved += (spent->Medical)-(budg->Medical);
    total2+= spent->Medical;
    cout<<"Insurance         "<<budg->Insurance<<"     "<<right<<setw(7)<<spent->Insurance<<"     "<<right<<setw(7)<<(spent->Insurance)-(budg->Insurance)<<endl;
    saved += (spent->Insurance)-(budg->Insurance);
    total2 += spent->Insurance;
    cout<<"Entertainment     "<<budg->Entertainment<<"     "<<right<<setw(7)<<spent->Entertainment<<"     "<<right<<setw(7)<<(spent->Entertainment)-(budg->Entertainment)<<endl;
    saved += (spent->Entertainment)-(budg->Entertainment);
    total2 += spent->Entertainment;
    cout<<"Clothing           "<<budg->Clothing<<"     "<<right<<setw(7)<<spent->Clothing<<"     "<<right<<setw(7)<<(spent->Clothing)-(budg->Clothing)<<endl;
    saved += (spent->Clothing)-(budg->Clothing);
    total2 += spent->Clothing;
    cout<<"Miscellaneous      "<<budg->Miscellaneous<<"     "<<right<<setw(7)<<spent->Miscellaneous<<"     "<<right<<setw(7)<<(spent->Miscellaneous)-(budg->Miscellaneous)<<endl;
    saved += (spent->Miscellaneous)-(budg->Miscellaneous);
    total2+= spent->Miscellaneous;
    cout<<"================================================="<<endl;
    cout<<"Total            "<<right<<setw(7)<<total1<<"     "<<right<<setw(7)<<total2<<"     "<<right<<setw(7)<<saved<<endl;
    cout<<"================================================="<<endl<<endl;
    cout<<"Congratulations! You were $"<<abs(saved)<<" under budget in "<<month<<" 2020."<<endl;


}
//value returning function to get a valid input.
double getValidInput(/*in*/string holder)
{
    //pre:obtains a double from a struct from the built in function from the struct data type.
    //post:returns a variable that is above zero and returns it to the build in function. also displays the correct string for input displays from function.
    double input;
    cout<<holder;
    cin>> input;
    while(!cin || input < 0)
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"ERROR: You must enter a positive number."<<endl;
        cout<<holder;
        cin>>input;
    }
    return input;
}

/*
Here is your monthly budget for YEAR 2020:

Housing        $  580.00
Utilities      $  150.00
Household      $  65.00
Transportation $  50.00
Food           $  250.00
Medical        $  30.00
Insurance      $  100.00
Entertainment  $  150.00
Clothing       $  75.00
Miscellaneous  $  50.00
=================================================
Total Budgeted $ 1500.00
=================================================

Enter month of expenditure: may
Enter actual monthly expenditures for each budget category

Housing        $  580
Utilities      $  125
Household      $  60
Transportation $  50
Food           $  130
Medical        $  30
Insurance      $  100
Entertainment  $  70
Clothing       $  25
Miscellaneous  $  10
                 Budgeted     Spent      Difference
=================================================
Housing           580.00      580.00        0.00
Utilities         150.00      125.00      -25.00
Household          65.00       60.00       -5.00
Transportation     50.00       50.00        0.00
Food              250.00      130.00     -120.00
Medical            30.00       30.00        0.00
Insurance         100.00      100.00        0.00
Entertainment     150.00       70.00      -80.00
Clothing           75.00       25.00      -50.00
Miscellaneous      50.00       10.00      -40.00
=================================================
Total            1500.00     1180.00     -320.00
=================================================

Congratulations! You were $320.00 under budget in may 2020.

Process returned 0 (0x0)   execution time : 63.300 s
Press any key to continue.

extra credit #1
if i was to rewrite my program to use a enumerated data timew to reprosent months i would create the data type like this
enum Month{JANUARY,FEBRUARY,MARCH,APRIL...} with all the months in side it. then the user would be prompted for a month string that would be tested in a switch statement that set a int value to its proper month.
then I would use that the int with the enum value to be the starting place in a for loop to print out the expenses. if the value was 12 the next value it would output for a month would be 0 or january. so all the months would be out put with the starting one displayed being the one given.
the function could also pass the current totals of each month to the next function call to get a total saved for the whole year.
*/

