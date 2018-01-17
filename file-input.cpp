#include <iostream>
#include <fstream>

#define FILENAME "testdata.txt"

struct student {
  std::string name;
  float gpa;
};

int main(int argc, char const *argv[]) {

  std::ifstream infile;
  infile.open(FILENAME);
  if (infile.fail()) {
    std::cerr << "Error opening file: " << FILENAME << std::endl;
    return 1;
  }

  // if (!infile.is_open()) {
  //   std::cerr << "Error opening file: " << FILENAME << std::endl;
  //   return 1;
  // }

  char c;
  infile.get(c);
  std::cout << "c: " << c << std::endl;

  // int n;
  // infile >> n;
  // if (infile.fail()) {
  //   std::cerr << "Failed to read n" << std::endl;
  // } else {
  //   std::cout << "n: " << n << std::endl;
  // }



  infile.close();

  return 0;
}
