#include "student.h"
#include "dealWithFile.h"

using namespace std;

int main()
{
	char ch;
	
	while(1){
		char ch;
		int num;
		cout<<"\n\t\tMENU";
		cout<<"\n\t1.Create student record";
		cout<<"\n\t2.Search student record";
		cout<<"\n\t3.Display all students records";
		cout<<"\n\t4.Delete student record";
		cout<<"\n\t5.Modify student record";
		cout<<"\n\t6.Exit";
		cout<<"\n\t\tWhat is your Choice (1/2/3/4/5/6):";
		cin>>ch;

		switch(ch)
		{
			case '1': 
			 create_student(); 
			 break;

			case '2': 
			 cout<<"\n\tEnter The roll number "; 
			 cin>>num;
			 display_sp(num); 
			 break;

			case '3': 
			 display_all(); 
			 break;

			case '4': 
			 cout<<"\n\tEnter The roll number: "; 
			 cin>>num;
			 delete_student(num);
			 break;

			case '5': 
			 cout<<"\n\tEnter The roll number "; 
			 cin>>num;
			 change_student(num);
			 break;

			case '6': 
			 cout<<"Exiting, Thank you!";
			 exit(0);
		}

	}
	return 0;
}