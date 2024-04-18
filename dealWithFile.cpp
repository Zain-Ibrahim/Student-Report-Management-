#include "dealWithFile.h"

using namespace std;

//write student details to file
void create_student()
{
	student stud;
	ofstream oFile;
	oFile.open("student.dat",ios::binary|ios::app);
	stud.getdata();
	oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
	oFile.close();
	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

// read file records
void display_all()
{
	student stud;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key to exit";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
	while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
		stud.showdata();
		cout<<"\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

//read specific record based on roll number
void display_sp(int n)
{
	student stud;
	ifstream iFile;
	iFile.open("student.dat",ios::binary);
	if(!iFile)
	{
		cout<<"File could not be opened... Press any Key to exit";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
		if(stud.retrollno()==n)
		{
			stud.showdata();
			flag=true;
		}
	}
	iFile.close();
	if(flag==false)
		cout<<"\n\nrecord does not exist";
	cin.ignore();
	cin.get();
}

// modify record for specified roll number
void change_student(int n)
{
	bool found=false;
	student stud;
	fstream fl;
	fl.open("student.dat",ios::binary|ios::in|ios::out);
	if(!fl)
	{
		cout<<"File could not be opened. Press any Key to exit...";
		cin.ignore();
		cin.get();
		return;
	}
	while(!fl.eof() && found==false)
	{
		fl.read(reinterpret_cast<char *> (&stud), sizeof(student));
		if(stud.retrollno()==n)
		{
			stud.showdata();
			cout<<"\nEnter new student details:"<<endl;
			stud.getdata();
			int pos=(-1)*static_cast<int>(sizeof(stud));
			fl.seekp(pos,ios::cur);
			fl.write(reinterpret_cast<char *> (&stud), sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=true;
		}
	}
    fl.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}

//delete record with particular roll number
void delete_student(int n)
{
	student stud;
	ifstream iFile;
	iFile.open("student.dat",ios::binary);
	if(!iFile)
	{
		cout<<"File could not be opened... Press any Key to exit...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream oFile;
	oFile.open("Temp.dat",ios::out);
	iFile.seekg(0,ios::beg);
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
		if(stud.retrollno()!=n)
		{
			oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
		}
	}
	oFile.close();
	iFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
