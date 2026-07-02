/*Write a claiiss Student with following data members. Rollno age subject1 subject2 subject3 (marks for 3 subjects) coursename and finally fees. Use appropriate data types. Provide constructor and also provide method isPassed() which returns true if passed in all subjects.  Also Provide PrintStudent() which prints details of all students.  Write main programs and test class. Create students and show output.         Try these show it to me tomorrow*/


#include <iostream>
#include<string>
using namespace std;

class Student{
	private:
		int rollno;
		int age;
		float sub1,sub2,sub3;
		string coursename;
		int fees;
        public:
Student(int r,int a,float s1,float s2,float s3,string c,int f){
	rollno = r;
	age = a;
	sub1 = s1;
	sub2 = s2;
	sub3 = s3;
	coursename = c;
	fees = f;
}
bool isPassed(){
	return(sub1 >= 35 && sub2 >= 35 && sub3 >= 35);
}
void PrintStudent(){
	cout<<"rollno:"<<rollno<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"coursename:"<<coursename<<endl;
	cout<<"fees:"<<fees<<endl;
	cout<<"Marks:"<<sub1<<sub2<<sub3<<endl;
	if(isPassed())
		cout<<"Result:Passed"<<endl;
	else

                cout<<"Result:Failed"<<endl;
}
};
int main(){
	Student s1(10,21,81,63,78,"CS-AI",95000);
        Student s2(20,20,75,66,85,"CS-IOT",95000);
        Student s3(30,23,52,30,60,"CS-IT",90000);

	s1.PrintStudent();
        s2.PrintStudent();
        s3.PrintStudent();
return 0;	
}
