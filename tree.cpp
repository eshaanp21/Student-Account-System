#include "tree.h"
#include <algorithm>
#include <bits/stdc++.h>

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::BinaryTree(int root_data) {
  root = new Nodet;
  root->data = root_data;
  root->left = nullptr;
  root->right = nullptr;
}

BinaryTree::BinaryTree(int root_data, BinaryTree left, BinaryTree right) {
  root = new Nodet;
  root->data = root_data;
  root->left = left.root;
  root->right = right.root;
}

int BinaryTree::height(const Nodet *n) const {
  if (n == nullptr) {
    return 0;
  } else {
    return 1 + std::max(height(n->left), height(n->right));
  }
}

int BinaryTree::height() const { return height(root); }

bool BinaryTree::empty() const { return root == nullptr; }

int BinaryTree::data() const { return root->data; }

BinaryTree BinaryTree::left() const {
  BinaryTree result;
  result.root = root->left;
  return result;
}

BinaryTree BinaryTree::right() const {
  BinaryTree result;
  result.root = root->right;
  return result;
}


void make_quiz() {
  std::ofstream Aoutfile("A.txt");
  std::ofstream Qoutfile("Q.txt");
  std::ofstream sizeout("size.txt");
	int max_size = 10;
  std::cout << "You will have to enter 2 times the amount of questions the student has to answer minus one question.\n";
  std::cout << "Enter the number of questions you want the student to answer(only up to " << max_size << "): ";
  int size; 
	std::cin >> size;
  int numquest = (size*2)-1;
	while (size <= 0 || size > max_size || std::cin.fail()){
	  std::cout << "Error! Please enter an integer no greater than " << max_size << " and no less than 1: ";
    std::cin.clear(); 
    std::cin.ignore();
  	std::cin >> size;
	}
  std::cin.ignore(); 
  std::string question[size];
  std::string answer[size];
	for (int i = 0; i < size; i++) {
		std::string q;
    if(i%2==0 && i!=0)
    {std::cout<<"Please enter a more challenging question for this one. ";}
		std::cout << "\nQuestion " << i + 1 << ":\n";
		std::getline(std::cin, q);
		 while(q.empty()){ //to make sure an answer for each option is entered
			 std::cout << "Please enter a question: ";
				std::getline(std::cin, q);
			}
		q = q + "\n";
		std::string o;
		for (int i = 0; i < 4; i++) {
			std::string l;
			if (i + 1 == 1) { l = "A"; }
			if (i + 1 == 2) { l = "B"; }
			if (i + 1 == 3) { l = "C"; }
			if (i + 1 == 4) { l = "D"; }
			std::cout << "option " << l << ": ";
			std::getline(std::cin, o);
			while(o.empty()){ //to make sure an answer for each option is entered
				std::cout << "Error: This option cannot be blank.\nPlease enter an option: ";
				std::getline(std::cin, o);
			}
			o = l + ") " + o;
			q = q + o + "\n";
		}
			std::cout << "Which option is the answer for Question " << i + 1 << "? Enter A, B, C, or D: ";
			std::string a;
			std::cin >> a;
		  transform(a.begin(), a.end(), a.begin(), ::toupper);
			while(a != "A" && a != "B" && a != "C" && a != "D"){
				std::cout << "Please enter a valid option (A, B, C, or D): ";
				std::cin >> a;
			}
			answer[i] = a;
			std::cout << std::endl;
			question[i] = q;
		}
  std::string q, a;
  for (int i = 0; i < size; i++) {
    q = q + question[i] + ",";
    a = a + answer[i] + ",";
  }
  Qoutfile << q;
  Aoutfile << a;
  sizeout << size;
}


double take_quiz() {
  
  BinaryTree tree(0, BinaryTree(1, BinaryTree(3, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))))), BinaryTree(4, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))))),   BinaryTree(2, BinaryTree(3, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))))), BinaryTree(4, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))))));   

  
  std::ifstream Sizein, Qinfile, Ainfile;
  Sizein.open("size.txt");
  int size = 0;
  Sizein >> size;
  //std::ifstream Qinfile;
  Qinfile.open("Q.txt");
  std::string question[size];
  for (int i = 0; i < size; i++) {
    std::string q;
    getline(Qinfile, q, ',');
    question[i] = q;
  }
  //std::ifstream Ainfile;
  Ainfile.open("A.txt");
  std::string answer[size];
  for (int i = 0; i < size; i++) {
    std::string a;
    getline(Ainfile, a, ',');
    answer[i] = a;
  }
  std::map<int, std::string> map;
  for (int i = 0; i < size; i++) {
    map[i] = question[i];
  }
  std::cout << std::endl;
  size = size - 1;
  size = size / 2;
  size = size + 1;
  double score = 0.0;
  int count = 0;
  bool done = false;
  while (!done) {
    BinaryTree left = tree.left();
    BinaryTree right = tree.right();
    if (left.empty() && right.empty()) {
      std::cout << tree.data() << std::endl;
      done = true;
    } else {
      std::string response;
      do {
        std::cout << map[tree.data()] << std::endl;
        std::cout<<"Note: please enter a valid input (A,B,C,or D):\n";
        std::cin >> response;
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        if(response != "A" && response != "B" && response != "C" && response != "D") { 
          std::cout << "INVALID INPUT!\n\n";
          continue;
        }
        if (response == answer[tree.data()]) { score++; }
        count++;
        if (count == size) {
          done = true;
          break;
        }
				//data validation  for lowercase
      } while (response != "A" && response != "B" && response != "C" &&
               response != "D" && response != "a" && response != "b" && response != "c" &&
               response != "d");
      if (response == answer[tree.data()]) {
        tree = right;
      } else if (response != answer[tree.data()]) {
        tree = left;
      }
    }
  }
  score=score/size;
  score=score*100;
  return score;
}
