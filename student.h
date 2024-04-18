#ifndef STUDENT_H
#define STUDENT_H

//inclusions of header files
#include <iostream>
#include <string>

class student
{
private:
	int rollno;
	char name[50];
	int PL1, Electronics, OS, Logic, DS;
	double average;
	char grade;

public:
	//read from user data of record
	void getdata();
	//printf data of record
	void showdata() const;
	//calculate average of subjects, grade
	void calculate();
	//return id of student
	int retrollno() const;
}; //ends student calss

#endif
