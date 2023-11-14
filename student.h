#ifndef STUDENT_H
#define STUDENT_H
#include <iostream> //for strings
#include "helper_functions.h"
#include <fstream>
#include <vector>

class Student {
public:
  void set_name(std::string); //mutator
  std::string get_name() const; //acessor
  void set_quizscore(int); //mutator
  int get_quizscore() const; //acessor
  void set_reward(bool); //mutator
  bool get_reward() const; //acessor
  void set_studytime(int); //mutator
  int get_studytime(); //acessor

  void move_data(std::vector<Student>& temp);
  void new_student(std::vector<Student>& temp, std::string studentname);
  void edit_student(std::vector<Student>& temp, int i);
/*
	Takes teacher input for menu options & calls appropriate functions.
	@param user's name
	retun value --> integer input, the user's chosen option
*/
  int student_options(std::string);

/*
	uses user's name to find thier data from studentEX text file
	@param user's name
*/
  void findStudent(std::string);

/*
	reads in student data and uses setters to assign data
	@param none 
*/
  std::vector<Student> getdata();

/*
	prints data of student and mentions reward
	@param none
*/
  void print();

private:
  std::string name;
  int rec_quizscore; //recent quiz score
  bool reward; //reward to claim or not
  int studytime;   //in minutes
};

#endif