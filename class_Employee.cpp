#include<iostream>
using namespace std;

class Employee{
	private:
		int eid;
		//int hours;
		//float rate;
		int age;
		static int count; // static-member -> shared by all members
        public:
		int hours;
		float rate;

         Employee(){
		 eid = ++count+100;
		 hours = 180;
		 rate = 200.08;
		 age = 24;
	 }		

	 Employee(int h, float r, int y){
		 //this -> eid = eid;
		 eid = ++count+100;
		 hours = h;
		 rate = r;
		 age = y;
		 cout<<"Employee Instance create through Parameterised Ctor"<<endl;
	 }

	 int GetEid(){
		 return eid;	 
	 }

	 void SetEid(int i){
		 eid = i;
	 }

	 double AnnualIncome() const{
		 return (hours*rate)*12*1.2;
	 }

	 int static GetCount(){
		 return count;
	 }
};

// Calling Static Method 

int Employee::count = 0;

// Global Method

double GetTax(const Employee* emp){
	double income = emp->AnnualIncome();
	//emp->rate =400;      //read-only
	if(income > 550000)
		return (income-550000)*0.1;
	return 0.0;
}

// Entry Point


int main(){
	int x;
	x = 100;
	cout<<"Direct Access of x"<<x<<endl;
	int* p = &x;
	cout<<"Indirect Access of x through pointer p"<<*p<<endl;
	Employee e;
	Employee e1(150,400,23);
	cout<<"Employee ID: " << e.GetEid()<< " and Annual Income: "<< e.AnnualIncome()<<endl;
	cout<<"Tax is: "<<GetTax(&e)<<endl;
	cout<<"Employee ID: " <<e1.GetEid()<<" and Annual Income: "<<e1.AnnualIncome()<<endl;
	cout<<"Tax is : "<<GetTax(&e1)<<endl;
	cout<<"Total Employees: "<< Employee::GetCount() <<endl;
	return 0;
}





































