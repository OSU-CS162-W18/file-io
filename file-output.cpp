#include <iostream>
#include <fstream>

struct student {
  std::string first_name;
  std::string last_name;
  float gpa;
};

int main(int argc, char const *argv[]) {

  struct student s1 = {
    .first_name = "Darth",
    .last_name = "Vader",
    .gpa = 2.25
  };

  struct student s2 = {
    .first_name = "Kylo",
    .last_name = "Ren",
    .gpa = 1.67
  };

  std::ofstream outfile;
  outfile.open("people-to-write.txt");
  if (outfile.fail()) {
    std::cerr << "Error: failed to open file: people-to-write.txt" << std::endl;
    return 1;
  }

  outfile << s1.first_name << "\t" << s1.last_name << "\t" << s1.gpa << std::endl;
  outfile << s2.first_name << "\t" << s2.last_name << "\t" << s2.gpa << std::endl;

  outfile.close();

  outfile.open("people-to-write.txt", std::ofstream::app);
  if (outfile.fail()) {
    std::cerr << "Error: failed to open file: people-to-write.txt" << std::endl;
    return 1;
  }

  outfile << s1.first_name << "\t" << s1.last_name << "\t" << s1.gpa << std::endl;
  outfile << s2.first_name << "\t" << s2.last_name << "\t" << s2.gpa << std::endl;

  outfile.close();
  return 0;
}
