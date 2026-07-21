#include <iostream>

using namespace std;

class Employee
{
    private: 
        int eid;
        int hours;
        float rate;
        int age;
		static int count;
    public:

       Employee()
       {
          eid = 1000;
          hours = 180;
          rate = 200.04;
          age = 24;
       }
       
	  //        Employee* this
       Employee(int eid, int h, float r, int y)
       {
          this->eid = eid;
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
       double AnnualIncome()
       {  
            return (hours * rate) * 12 * 1.2;

       }
};


double GetTax(Employee* emp)
{
    double income = emp->AnnualIncome();
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
  Employee e1(2000, 250, 300, 30);
                                                                      //Employee::AnnualIncome(&e)               
  cout << "Employee id :" << e.GetEid() << " and Annual Income : " << e.AnnualIncome() << endl;
  cout << "And Tax is : " << GetTax(&e) << endl;
  cout << "Employee id :" << e1.GetEid() << " and Annual Income : " << e1.AnnualIncome() << endl;
  cout << "And Tax is : " << GetTax(&e1) << endl;
  return 0;
}
