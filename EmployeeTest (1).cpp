#include <iostream>

using namespace std;
/*
  Instance Variable
  Instance Methods
  Writing Class
  Creating object or Instance in main
  What is Constructor
  Overloaded Ctor
  Parameterised NonParemeterised Ctor( Default one)
  If class does not Ctor Compiler provides Empty Parameterless Ctor which is also the default one
  Global method like main (GetTax)
  call by value / call by address
  This pointer which is available to all member functions in a class
  This pointer gets address of the current instance or alternatively
  we can say it get address of instance on which method is invoked
  Member function since they get this pointer they are allowed to access
  instance data through this pointer
  Constructors also get this pointer
  Strategy to generate unique values through static count variable
  Static or shared data also called as Class variables
  Static Methods / functions in a class
  Static Methods are called on class through ::
  Static Methods do not get access to instance field as they do not get this pointer
  Static Methods only access class fields
  Scope of instance field can be private protected public
  Generally instance field are kept private and given access outside class
  through corressponding get and set methods
  Understanding of applying const whenever using pass by address
  Const also sometimes need to be applied on methods like AnnualIncome()
  Binding Mechanisim where when we call a method on an instance actually compiler
  writes a code to call that method on a class with & of that instance is passed 
  as first parameter to that method and get assigned to this pointer 
*/

class Employee
{
    private: 
        int eid;
        int hours;
        //float rate;
        int age;
		static int count;
    public:
       float rate;
       Employee()
       {
          eid = ++count + 1000;
          hours = 180;
          rate = 200.04;
          age = 24;

       }
       
	  //        Employee* this
       Employee(int h, float r, int y)
       {
          //this->eid = eid;
		  
          eid = ++count + 1000;
          hours = h;
          rate = r;
          age = y;
          cout << "Employee Instance create through Parameterised Ctor" << endl;
       }

       int GetEid(){
          return eid;
       }

       void SetEid(int i)
       {
          eid = i;
       }
 //    double AnnualIncome(Employee* this)
       double AnnualIncome() const 
       {  
            return (hours * rate) * 12 * 1.2;
       }

	   int static GetCount()
	   {
			return count;
	   }
};

int Employee::count = 0;


/*
double GetTax(Employee emp)
{

    double income = emp.AnnualIncome();
	if (income > 550000)
	   return (income-550000) * 0.1;
	return 0.0;

}
*/
double GetTax(const Employee* emp)
{                    //Employee::AnnualIncome(emp)
    double income = emp->AnnualIncome();
//    emp->rate = 400;
	if (income > 550000)
	   return (income-550000) * 0.1;
	return 0.0;

}


int main()
{
  int x;
  x = 100;
  cout <<"Direct access of x" << x << endl;
  int* p = &x;
  cout <<"Indirect Direct access of x through p" << *p << endl;
  Employee e;
  Employee e1(250, 300, 30);
                                                                      //Employee::AnnualIncome(&e)               
  cout << "Employee id :" << e.GetEid() << " and Annual Income : " << e.AnnualIncome() << endl;
  cout << "And Tax is : " << GetTax(&e) << endl;
  cout << "Employee id :" << e1.GetEid() << " and Annual Income : " << e1.AnnualIncome() << endl;
  cout << "And Tax is : " << GetTax(&e1) << endl;
  cout << "Total Employees : " << Employee::GetCount() << endl;
  return 0;
}
