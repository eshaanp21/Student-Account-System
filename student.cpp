#include "student.h"
//setter for the name variable of student class
void Student::set_name(std::string nname) //Eshaan
{
  name = nname;
}
//getter for the name variable of student class
std::string Student::get_name() const //Eshaan
{
  return name;
}

//setter for the quizscore variable of the student class
void Student::set_quizscore(int quizscore) //Eshaan
{
  rec_quizscore = quizscore;
}
int Student::get_quizscore() const //Eshaan
{
  return rec_quizscore;
}


void Student::set_reward(bool nreward) //Eshaan
{
  reward = nreward;
}
bool Student::get_reward() const  //Eshaan
{
  return reward;
}


void Student::set_studytime(int nstudytime) //Eshaan
{
  studytime = nstudytime;
}
int Student::get_studytime() //Eshaan
{
  return studytime;
}



//Option 1 Practice Quiz    Option 2 View Data    Option 3 Study    Option 4 Logout
int Student::student_options(std::string name) //Eshaan
{
  std::cout << "\nWhat would you like to do today?\n";
  std::cout << "\nOption 1: Take a Practice Quiz\nOption 2: See Grades and Check Rewards\n";
  std::cout << "Option 3: Study\nOption 4: Logout\n";
  int input = 0;
  bool corr = false;
  std::string temp;
  while(!corr)
  {
    input = 0;
    std::cout << "Enter the number of the option(1, 2, 3, 4): ";
    std::cin >> input;
    while((input <= 0 || input > 4 || std::cin.fail())) //input validation loop
    {
      std::cout << "That was not a valid option. Please enter a valid option: ";
      std::cin.clear(); 
      std::cin.ignore();
      std::cin >> input;
    }
    temp = "Would you like to continue with option " + std::to_string(input) + "?";
    corr = confirm(temp);
  }
  return input;
}


std::vector<Student> Student::getdata()
{
  std::ifstream in;
  in.open("studentEX.txt");
  std::string temp;
  
  std::vector<Student> finalvector;
  while(getline(in, temp))
  {
    std::string::size_type i = 0;
    std::string::size_type j = temp.find(" ");
    std::vector<std::string> v;
    while (j != std::string::npos) {
      v.push_back(temp.substr(i, j-i));
      i = ++j;
      j = temp.find(" ", j);

      if (j == std::string::npos)
         v.push_back(temp.substr(i, temp.length()));
    }
    Student newStudent;
    newStudent.set_name(v[0]);
    newStudent.set_quizscore(stoi(v[1]));
    newStudent.set_studytime(stoi(v[2]));
    if(v[3] == "true") { newStudent.set_reward(true); }
    else if(v[3] == "false") { newStudent.set_reward(false); }
    else { std::cout << "ERROR"; }
    finalvector.push_back(newStudent);
  }
  return finalvector;
}



void Student::findStudent(std::string name) 
{
  std::ifstream in_file;
	in_file.open("studentEX.txt");
	std::string student_name;

	std::string line; //line read in from file is "Eshaan 89 180 true"
	std::string delimiter = " ";
  bool registered = false;
	if(in_file.is_open())
  {
		while(std::getline(in_file, line))
		{
			student_name = line.substr(0, line.find(delimiter)); // student_grade is "89"
      if(name == student_name) { 
        registered = true;
        break; 
      }
		}
	}
	else{
		std::cout << "Error reading in student names from file.";
		exit(0);
	}

  if(!registered) {
    std::cout << "You are an unregistered student with no file. Please speak to your teacher about fixing this issue.\n";
    return;
  }
  std::string::size_type i = 0;
  std::string::size_type j = line.find(" ");
  std::vector<std::string> v;
  while (j != std::string::npos) {
    v.push_back(line.substr(i, j-i));
    i = ++j;
    j = line.find(" ", j);
    if (j == std::string::npos)
       v.push_back(line.substr(i, line.length()));
  }
  this->name = v[0];
  this->rec_quizscore = stoi(v[1]);
  this->studytime = (stoi(v[2]));
  if(v[3] == "true") { this->reward = true; }
  else if(v[3] == "false") { this->reward = false; }
  else { std::cout << "ERROR"; }
}


void Student::print() 
{
  std::cout << "\nName: " + this->name;
  std::cout << "\nQuiz Score: " << this->rec_quizscore;
  std::cout << "\nStudy Time: " << this->studytime << "\n";
  if(this->reward)
  {
    //might try GUI later here - Eshaan
    std::cout << "Congratulations! There is a reward waiting for you!\n";  
    std::cout << "Please talk to your teacher about receiving your reward.\n";
  } else {
    std::cout << "There is no reward to be claimed now.\n";
    std::cout << "Keep pushing forward and trying to get that reward.\n";
    std::cout << "You can do it!\n";
  }
}