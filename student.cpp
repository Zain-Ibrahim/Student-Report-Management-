#include "student.h"

using namespace std;

void student::calculate()
{
	average=(PL1+Electronics+OS+Logic+DS)/5.0;
	if(average>=90)
		grade='A';
	else if(average>=75)
		grade='B';
	else if(average>=50)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter student's roll number: ";
	cin>>rollno;
	cout<<"\n\nEnter student name: ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nAll marks should be out of 100";
	cout<<"\nEnter marks in Programming 1: ";
	cin>>PL1;
	cout<<"\nEnter marks in Electronics:  ";
	cin>>Electronics;
	cout<<"\nEnter marks in Operating Systems:  ";
	cin>>OS;
	cout<<"\nEnter marks in Logic Design:  ";
	cin>>Logic;
	cout<<"\nEnter marks in Data Structers:  ";
	cin>>DS;
	calculate();
}
void student::showdata() const

{	
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nProgramming 1 : "<<PL1;
	cout<<"\nElectronicss : "<<Electronics;
	cout<<"\nOperating Systems : "<<OS;
	cout<<"\nLanguage2 : "<<Logic;
	cout<<"\nData Structers :"<<DS;
	cout<<"\nAverage Marks :"<<average;
	cout<<"\nGrade of student is :"<<grade;
}
int  student::retrollno() const
{
	
	return rollno;
}