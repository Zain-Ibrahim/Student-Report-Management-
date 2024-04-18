#ifndef DEALWITHFILE_H
#define DEALWITHFILE_H

//inclusions of header files
#include <iostream>
#include <string>
#include <fstream>
#include "student.h"

//function declaration
void create_student();
void display_sp(int);//display particular record
void display_all(); // display all records
void delete_student(int);//delete particular record
void change_student(int);//edit particular record

#endif