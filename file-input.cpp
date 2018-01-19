#include <iostream>
#include <fstream>
#include <string>

struct student {
  std::string first_name;
  std::string last_name;
  float gpa;
};

int main(int argc, char const *argv[]) {

  std::ifstream infile;
  infile.open("testdata.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: " << "testdata.txt" << std::endl;
    return 1;
  }

  // if (!infile.is_open()) {
  //   std::cerr << "Error opening file: " << "testdata.txt" << std::endl;
  //   return 1;
  // }

  int n;
  infile >> n;
  if (infile.fail()) {
    std::cerr << "Failed to read n" << std::endl;
  } else {
    std::cout << "n: " << n << std::endl;
  }

  std::string str;
  infile >> str;
  if (infile.fail()) {
    std::cerr << "Failed to read str" << std::endl;
  } else {
    std::cout << "str: " << str << std::endl;
  }

  char c;
  infile.get(c);
  if (c != ' ') {
    std::cout << "c: " << c << std::endl;
  }
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;

  std::string line;
  std::getline(infile, line);
  std::cout << "line: " << line << std::endl;

  infile.close();


  infile.open("people-to-read.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: " << "people-to-read.txt" << std::endl;
    return 1;
  }

  struct student s;
  while (infile.good()) {
    infile >> s.first_name >> s.last_name >> s.gpa;
    if (!infile.fail()) {
      std::cout << "Student: " << s.first_name << "\t" << s.last_name << "\t"
        << s.gpa << std::endl;
    }
  }

  infile.close();



  infile.open("people-to-read-2.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: " << "people-to-read-2.txt" << std::endl;
    return 1;
  }

  int num_students;
  infile >> num_students;
  std::cout << "Reading this many students: " << num_students << std::endl;

  struct student* students = new struct student[num_students];
  for (int i = 0; i < num_students; i++) {
    infile >> students[i].first_name >> students[i].last_name >> students[i].gpa;
    if (infile.fail()) {
      std::cerr << "Failed to read student #" << i << std::endl;
      break;
    }
  }

  for (int i = 0; i < num_students; i++) {
    std::cout << "students[" << i << "]: " << students[i].first_name << "\t"
      << students[i].last_name << "\t" << students[i].gpa << std::endl;
  }


  infile.close();

  return 0;
}
