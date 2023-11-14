#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "student.h"
#include <iostream>

#include <vector>

/** 
  greeting funciton to get name of user and introduce program.
	@param none
  no return value
*/
void greeting();


/** 
  use_program funciton to ask user if they want to run the program
	@param none
	return value --> boolean check
*/
bool use_program();


/** 
  read_file function that reads in the data from a given file and stores each character in a queue
	@param none
	no return value
*/
void read_file(); //might need to make  this  of type  queue so I can return a queue


/** 
  repeat_program funciton to ask user if they want to repeat the program
	@param none
	retun value --> boolean check
*/
bool repeat_program();


bool confirm(const std::string &prompt);

std::string student_or_teacher();

bool student_login(std::string&);

bool teacher_login(std::string&);

void read_student_names(bool reversed);
void read_student_grades(bool reversed);
void see_data();
int teacher_options(std::string name);
void view_grades(bool reversed);
void view_names(bool reversed);
void modify_option();
void give_rewards();
void addoredit();
void remove_student();
void assign_score(std::string, double);
void assign_studytime(std::string, double);


#endif