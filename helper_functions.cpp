#include "helper_functions.h"
#include "quick_sort.h"
#include "stack.h"
#include <fstream>
#include <vector>


//greeting function to take in user's name and provide program description.
void greeting()
{
	std::cout << "Welcome!"; //no need for name input with login system
	std::cout << "\nThis program will help you take practice quizzes and work on your study habits as a student. As a teacher, it will help you track your student's progress as well as give rewards when appropriate. " << std::endl;
}


//function to ask user if they want to run program. Includes data validation. 
bool use_program()
{
	bool continues = false; //boolean for the while loop
	bool check = false;//boolean for the return 
	
	while (!continues)
	{
		std:: cout<< "\nWould you like to run the program? (y/n) ";
		std:: string use;
		std:: cin>> use;
		
		if (use == "y"|| use== "Y")
		{
			continues = true;
			check = true; 
		}
		else if(use == "n"|| use=="N" )
		{
			continues = true;
			check = false; 
			std:: cout<< "Goodbye, have a nice day!"<< std:: endl;
			return check;
		}
		else
		{
			std::cout<<"Please enter yes or no "<<std::endl;
		}
	}
	return check;
}

//read_file function to read the file from the text file and it calls the preprocessing function then returns the vecotr that is ready to sort.
void read_file(){
	std::ifstream in_file;

	std::string file_name;
	std::string data;//data to read from file
	std::cout << "\nEnter file name below, don't worry about the .txt part! \n";
	std::cout << "File name: ";
	std::cin >> file_name;

	in_file.open(file_name + ".txt");

	if(in_file.is_open()){
		//do stuff
	}
	else{
		std::cout << "Error opening file";
		exit(0);
	}
}


//function to ask user if they want to repeat program. Includes data validation. 
bool repeat_program()
{
	bool continues = false; //boolean for the while loop
	bool check = false;//boolean for the return 
	
	while (!continues){
		std:: cout<< "\n\nWould you like to repeat the program? (y/n) ";
		std:: string repeat;
		std:: cin>> repeat;
		
		if (repeat == "y"|| repeat== "Y"){
			continues = true;
			check = true; 
		}
		else if(repeat == "n"|| repeat=="N" ){
			continues = true;
			check = false; 
			std:: cout<< "Goodbye, have a nice day!"<< std:: endl;
			return check;
		}
		else{
			std::cout<<"Please enter yes or no "<<std::endl;
		}
	}
	return check;
}



bool confirm(const std::string &prompt) {
  while (true) {
    // Receive raw input from user
    std::string input;
    std::cout << prompt << ": ";
    std::cin >> input;

    if (!std::cin.fail() && !input.empty()) {
      // Check if the first character
      // is either y/n and serialize
      // to a boolean
      char c = tolower(input[0]);
      switch (c) {
      case 'y':
        return true;
      case 'n':
        return false;
      }
    }
    std::cout << "Invalid input (only enter y/n).\n";
    std::cin.clear();
    std::cin.ignore();
  }
}

std::string student_or_teacher()
{
  std::string input = "";
  std::cout << "\nHello user! Are you a student or a teacher using our program today?: ";
  std::cin >> input;
  while(input != "student" && input != "teacher"){
    std::cout << "Please enter either student or teacher: ";
    std::cin >> input;
  }
  return input;
}

bool student_login(std::string& name)
{
  std::cout << "\nPlease enter a username: ";
  std::cin >> name;
  std::cout << "\nPlease enter a password: ";
  
  //name = "username";
  
  return true;    //filler for now does nothing
  
}

bool teacher_login(std::string& name)
{
  std::cout << "\nPlease enter a username: ";
  std::cout << "\nPlease enter a password: ";
  
  name = "username";
  
  return true;    //filler for now does nothing
}



//funtion to read student names from file and call quick sort.
void read_student_names(bool reversed){ //Sanaa
  Student temps;
  std::vector<Student> temp = temps.getdata();

	quick_sortnames(temp, 0, temp.size()-1);  
  
	Stack stack; 
	if (reversed) 
	{
		for(int i = 0; i < temp.size(); i++)	{ //add ordered data to stack
			stack.push(temp[i]);
		}
		while(stack.size() > 0)	{ //print stack to reverse data
			std::cout << stack.top().get_name() << ": " <<  stack.top().get_quizscore() << "\n";
			stack.pop();
		}
	}
	else{
		//prints the names that were sorted using the quick_sort call
		for(int i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i].get_name() << ": " << temp[i].get_quizscore() << "\n";
		}
	}
}

//funtion to read student names from file and call quick sort.
void read_student_grades(bool reversed){ //Sanaa
	Student temps;
  std::vector<Student> temp = temps.getdata();
	
	quick_sortscore(temp, 0, temp.size()-1);  

	IntStack intstack; 
	if (reversed) 
	{
		for(int i = 0; i < temp.size(); i++)	{ //add ordered data to stack
			intstack.push(temp[i]);
		}
		while(intstack.size() > 0)	{ //print stack to reverse data
			std::cout << intstack.top().get_name() << ": " << intstack.top().get_quizscore() << "\n";
			intstack.pop();
		}
	}
	else{
		//prints the names that were sorted using the quick_sort call
		for(int i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i].get_name() << ": " << temp[i].get_quizscore() << "\n";
		}
	}
}


void assign_score(std::string username, double score) {
  Student temps;
  std::vector<Student> temp = temps.getdata();
  bool unregistered = true;
  int i;
  for(i = 0; i < temp.size(); i++) {
    if(username == temp[i].get_name()) { unregistered = false;  break; }
  }

  if(unregistered) {
    std::cout << "You are an unregistered student and the score will not be recorded.\n";
    return;
  } else {
    std::cout << "Your score has been recorded and you eligible to get a reward.\n";
    temp[i].set_quizscore(score);
    temp[i].set_reward(false);
  }

  temps.move_data(temp);
}


void assign_studytime(std::string username, double studytime) {
  Student temps;
  std::vector<Student> temp = temps.getdata();
  bool unregistered = true;
  int i;
  for(i = 0; i < temp.size(); i++) {
    if(username == temp[i].get_name()) { unregistered = false;  break; }
  }

  if(unregistered) {
    std::cout << "You are an unregistered student and the study time will not be recorded.\n";
    return;
  } else {
    std::cout << "Your studytime has been recorded.\n";
    int newstudytime = temp[i].get_studytime() + studytime;
    temp[i].set_studytime(newstudytime);
  }

  temps.move_data(temp);
}