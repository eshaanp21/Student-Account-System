#include "helper_functions.h"
#include "tree.h"
#include <iostream>

//Option 1 Make a Quiz    Option 2 View Student Data     Option 3 Logout
int teacher_options(std::string name) //By Sanaa using Eshaan's starter code
{
  std::cout << "\nHello " << name << ", welcome to the portal. What would you like to do today?\n";
  std::cout << "Option 1: Make a Practice Quiz\nOption 2: View Student Data\n";
  std::cout << "Option 3: Give Rewards\n" << "Option 4: Logout\n";
  int input = 0;
  bool corr = false;
  std::string temp;
  while(!corr) //while option is not chosen correctly
  {
    input = 0;
    std::cout << "Enter the number of the option(1, 2, 3, 4): ";
    std::cin >> input;
    while((input <= 0 || input > 4 || std::cin.fail())) //input validation loop
    {
      std::cout << "That was not a valid option. Please enter a valid option: ";
      std::cin.clear(); 
      std::cin.ignore();
      std::cin >> input; //user is prompted to enter an option # again
    }
    temp = "Would you like to continue with option " + std::to_string(input) + "?";
    corr = confirm(temp);
  }
  if(input == 1) { //if teacher wants to make a practice quiz
    make_quiz();
  }
	if(input == 2){ //if teacher wants to see student data
		see_data();
	}
	if(input ==  3){ //if teacher wants to give rewards
		give_rewards();
	}
  return input;
}


void see_data(){ //Sanaa
	bool reversed = false;
	std::string topic;
	std::cout << "\nWould you like to see student grades or names? ";
	std::cin >> topic;

	//data validation
	while (topic != "grades" && topic != "names"){
		std::cout << "Please enter either grades or names: ";
		std::cin >> topic;
	}

	if (topic == "grades"){
		view_grades(reversed);
	}
	else if(topic == "names"){
		view_names(reversed);
	}

	modify_option(); //allow teacher to modify any data after viewing the data
}


void modify_option(){
	std::string modify = "";
	std::cout << "\nWould you like to modify the data? (y/n): ";
	std::cin >> modify;

	//data validation
	while (modify != "y" && modify != "n"){
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> modify;
	}
	
	if(modify == "y"){
    std::string edit = "";
    std::cout << "\nWill you be changing a student's data or removing a student? (edit/remove): ";
    std::cin >> edit;
    while (edit != "edit" && edit != "remove"){
	    std::cout << "Please enter either edit or remove: ";
    	std::cin >> edit;
	  }
    if(edit == "edit") {
      addoredit();
    } else {
      remove_student();
    }
	}
	else{
		std::cout << "Okay, you chose not modify any student data. ";
		return; 
	}
}


void give_rewards(){
	
	std::cout << "\nOkay! you can give rewards based on students' grades";
	std::cout << "\nThe students with grades 90 and above will recieve rewards.\n";

	Student temps;
	std::vector<Student> data = temps.getdata();
  
	std::cout << "\nBelow are the names of the students who just received rewards!\n";
  
	for(int i = 0; i < data.size(); i++){
		if(data[i].get_quizscore() >= 90){
			data[i].set_reward(true);
			std::cout << data[i].get_name() << "\n";
		}
	}
	temps.move_data(data);
}


void view_names(bool reversed){
	std::string option;
	std::cout << "would you like to see the students' names from A-Z (a) or Z-A (z) order? enter a or z: ";
	std::cin >> option;
	
	//data validation
	while (option != "a" && option != "z"){
	  std::cout << "Please enter either a for A-Z or z for Z-A order: ";
  	std::cin >> option;
	}
	
	if (option == "a"){
		reversed = false;
		read_student_names(reversed); //student names is printed from A-Z
	}
	else if (option == "z"){
		reversed = true;
		read_student_names(reversed);  //student names is printed from Z-A
	}
}


void  view_grades(bool reversed){
	std::string option;
	std::cout << "Would you like to see your grades in ascending or descending order? (a/d): ";
	std::cin >> option;
	
	//data validation
	while (option != "a" && option != "d"){
	  std::cout << "Please enter either a for ascending or d for descending: ";
  	std::cin >> option;
	}
	
	if (option == "a"){
		reversed = false;
		read_student_grades(reversed);
	}
	else if (option == "d"){
		reversed = true;
		read_student_grades(reversed);
	}
}


void addoredit()
{
  std::cout << "Please give the name of the student that you would like to edit.\n";
  std::cout << "If the student does not exist, then a new student will be made and added\n";
  bool goodname = true;
  std::string studentname;
  while(goodname) {
    goodname = false;
    std::cout << "What is the name?: ";
    std::cin >> studentname;
    for(int i = 0; i < studentname.size(); i++)
    {
      if(isdigit(studentname[i])) { 
        goodname = true;
        std::cout << "Please enter a name with no numbers involved: ";
        break;
      }
    }
  }
  Student temps;
  std::vector<Student> temp = temps.getdata();
  bool neworedit = true;
  for(int i = 0; i < temp.size(); i++){
    if(studentname == temp[i].get_name()) {
      neworedit = false;
      temps.edit_student(temp, i);
      break;
    }
  }

  if(neworedit) {
    temps.new_student(temp, studentname);
  }
  temps.move_data(temp);
}

void Student::edit_student(std::vector<Student>& temp, int i)
{
  Student editable = temp[i];
  std::string name = editable.get_name();
  std::cout << "\nWhat part of " << name << "'s data would you like to edit?\n";
  std::cout << "Would you like to edit there score or manually give them a reward?(score/reward): ";
  std::string input;
  std::cin >> input;
  while(input != "score" && input != "reward")
  {
    std::cout << "Please enter either reward or score!: ";
    std::cin >> input;
  }
  if(input == "reward")
  {
    if(editable.get_reward())
    {
      std::cout << "This student has just been made eligible for another reward.\nThey will be told that there is no reward waiting for them.\n";
      editable.set_reward(false);
    } else {
      std::cout << "This student has just been made ineligible for another reward.\nThey will be told that there is a reward waiting for them.\n";
      editable.set_reward(true);
    }
  } else if(input == "score") {
    std::cout << name << "'s current score is " << editable.get_quizscore() << ".\n";
    std::cout << "What would you like to change the score to: ";
    int newscore;
    std::cin >> newscore;
    while(std::cin.fail() || (newscore < 0)) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Please enter a valid score greater than 0: ";
      std::cin >> newscore;
    }
    editable.set_quizscore(newscore);
    std::cout << "The score has been changed to " << newscore << ".\n";
  }
  
  temp[i] = editable;
}


void Student::new_student(std::vector<Student>& temp, std::string studentname) {
  std::cout << "That student name is not present in the class. Would you like to add this student? (y/n): ";
  std::string cont;
  std::cin >> cont;
  while (cont != "y" && cont != "n"){
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> cont;
	}
  if(cont == "n") { return; }

  Student newstudent;
  newstudent.set_name(studentname);
  
  std::cout << "What would you like to make this students quiz score: ";
  int newscore;
  std::cin >> newscore;
  while(std::cin.fail() || (newscore < 0)) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Please enter a valid score greater than 0: ";
    std::cin >> newscore;
  }
  newstudent.set_quizscore(newscore);
  newstudent.set_studytime(0);
  std::cout << "The score has been made " << newscore << ".\n";
  std::cout << "Student " << studentname << "has been created.\n";

  temp.push_back(newstudent);
}

void Student::move_data(std::vector<Student>& temp) {
  std::ofstream out;
  out.open("studentEX.txt");
  for(int i = 0; i < temp.size() ; i++){
		out << temp[i].get_name() << " ";
		out << temp[i].get_quizscore() << " ";
		out << temp[i].get_studytime() << " ";

		if(temp[i].get_reward()==true){
			out << "true" << std::endl;
		}
		else{
			out << "false" << std::endl;
		}		
	} 
}

void remove_student() {
  std::cout << "What is the name of the student that you would like to remove.\n";
  std::string name;
  Student temps;
  std::vector<Student> temp = temps.getdata();
  bool invalid = true;
  int posremove = 0;
  while(invalid) {
    std::cout << "To cancel enter 100.\n";
    std::cout << "Enter name here: ";
    std::cin >> name;
    for(int i = 0; i < temp.size(); i++) {
      if(temp[i].get_name() == name) {
        invalid = false;
        posremove = i;
        break;
      }
    }
    if(name == "100") { return; }
    if(invalid) { std::cout << "Please enter a valid name.\n"; }
  }
  std::cout << "You have chosen to remove " << name << ". Would you like to continue?(y/n): ";
  std::string cont;
  std::cin >> cont;
  while (cont != "y" && cont != "n"){
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> cont;
	}
  if(cont == "n") { return; }
  
  Student temp2;
	temp2 = temp[posremove]; //temp holds x
	temp[posremove] = temp[temp.size()-1]; //x holds y
	temp[temp.size()-1] = temp2;
  temp.pop_back();
  temps.move_data(temp);
}