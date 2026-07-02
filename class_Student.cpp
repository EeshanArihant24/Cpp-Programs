//Create class DacStudent which inherits from class Student has additional new data members projectgrade of char type. It may have values as a b c d. Provide constructor destructor and provide again isPassed() logic checks grades also.

#include<iostream>
using namespace std;

namespace MET
{
class Student{
	protected:
		int rollno;
		int age;
		string name;
		string coursename;
		float marks;
		double fees;
		static int count;
	public:
	     Student(int r,int a,string n,string cn,float m,double f){
		     rollno = ++count;
		     age = a;
		     name = n;
		     coursename = cn;
		     marks = m;
		     fees = f;
		     cout<<"Parameterized ctor called: "<<endl;
	     }	
	     Student(){
		     rollno = ++count;
		     age = 21;
		     name = "kobe";
		     coursename = "AC";
		     marks = 88;
		     fees = 90000;
		     cout<<"Default ctor called"<<endl;
	     }

	     //Run-Time Polymorphism via :- virtual
	     virtual bool isPassed(){ const
		     return marks >= 40;
	     }

	     virtual void Display(){
		     cout<<"RollNo: "<< rollno
			 <<"Age: "<< age
		         <<"Name: "<< name
		         <<"CourseName: "<< coursename
		         <<"Marks: "<< marks
		         <<"Fees: "<< fees
			 <<"Status"<< isPassed()<<endl;	 
	     }

	     ~Student(){
		     --count;
		     cout<<"Student Dtor called"<<endl;
	     }
	     // Derived Class
	     //class DacStudent: public Student(){

	     }
};
}

using namespace MET;

int Student count = 0;
int main(){
	cout<<"Creating Objects: "<<endl;
	Student s1(23,"James","AC",33,90000);
	Student s;
	return 0;

}
