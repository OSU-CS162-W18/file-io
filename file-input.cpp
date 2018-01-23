/*
 * In this file, we'll demonstrate how to read data from a file.
 */

#include <iostream>

/*
 * To be able to use std::ifstream, which is the C++ class for reading files,
 * we need to include fstream.
 */
#include <fstream>

/*
 * To be able to use std::getline(), we need to include string.
 */
#include <string>

/*
 * This is a little struct we'll use to store data we read from files.
 */
struct student {
  std::string first_name;
  std::string last_name;
  float gpa;
};


int main(int argc, char const *argv[]) {

  std::cout << "===========================================" << std::endl;
  std::cout << "== Reading from testdata.txt" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << std::endl;

  /*
   * This is how we can open a file for reading.  We first declare a variable
   * of type std::ifstream and then call the open() method on that variable.
   * The argument to infile.open() is the path (relative to the directory in
   * which the program is being run) to the file we want to open.  Before
   * actually reading from the file, we need to make sure it was successfully
   * opened.  We can do this with the infile.fail() method, like we do below.
   */
  std::ifstream infile;
  infile.open("testdata.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: testdata.txt" << std::endl;
    return 1;
  }

  /*
   * The infile.is_open() method is an alternative way to make sure the file
   * was successfully opened.
   */
  if (!infile.is_open()) {
    std::cerr << "Error opening file: testdata.txt" << std::endl;
    return 1;
  }

  /*
   * We can see that the first thing in testdata.txt is an integer (-2048).
   * We can read this value using std::cin-style syntax, like below.  Note
   * that we need to check for errors after reading!
   */
  int n;
  infile >> n;
  if (infile.fail()) {
    std::cerr << "Failed to read n" << std::endl;
  } else {
    std::cout << "n: " << n << std::endl;
  }

  /*
   * The read above actually parsed part of the file as an int.  We can also
   * simply read into a string, like below.  Each time a read is made, a cursor
   * pointing to the current location in the file is moved up past the part of
   * the file that was just read.  Thus, the code below will read the next
   * space-separated token in the file after the int we read initially (using
   * std::cin-style reads like this skips over whitespace).
   */
  std::string str;
  infile >> str;
  if (infile.fail()) {
    std::cerr << "Failed to read str" << std::endl;
  } else {
    std::cout << "str: " << str << std::endl;
  }

  /*
   * We can read a single character from a file using the infile.get() method,
   * like below.  Each call to infile.get() moves the cursor forward by one
   * character.  Note that calls to ,get() do not skip whitespace characters.
   */
  char c;
  infile.get(c);
  if (c != ' ') {
    std::cout << "c: " << c << std::endl;
  }
  infile.get(c);
  std::cout << "c: " << c << std::endl;
  infile.get(c);
  std::cout << "c: " << c << std::endl;

  /*
   * A final way to read data from a file is to read std::getline(), like
   * below.  This reads everything from the current position of the cursor to
   * the end of the current line (i.e. the next \n character) and stores it
   * all in an std::string.
   */
  std::string line;
  std::getline(infile, line);
  std::cout << "line: " << line << std::endl;

  /*
   * Once we're done reading from a file, we need to close it using the
   * infile.close() method.  This makes sure all of the resources being used
   * for reading the file are released.
   */
  infile.close();

  std::cout << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << "== Reading from people-to-read.txt" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << std::endl;

  /*
   * Now, we're going to read people-to-read.txt, which is slightly more
   * structured than testfile.txt.  The initial opening of the file works the
   * same way.  Note that we're reusing the variable infile here.
   */
  infile.open("people-to-read.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: people-to-read.txt" << std::endl;
    return 1;
  }

  /*
   * We know each line in people-to-read.txt corresponds to data for one
   * student and contains two strings (first and last name) and a float (gpa).
   * Thus, we can write a loop like below to read those values one student at
   * a time.  The loop will terminate when infile.good() returns false, which
   * will happen either when reading reaches the end of the file or when an
   * error occurs.  Note that it's still a good idea to check for errors
   * within the loop using infile.fail().
   */
  struct student s;
  while (infile.good()) {
    infile >> s.first_name >> s.last_name >> s.gpa;
    if (!infile.fail()) {
      std::cout << "Student: " << s.first_name << "\t" << s.last_name << "\t"
        << s.gpa << std::endl;
    }
  }

  /*
   * Again, we need to close the file when we're done reading from it.
   */
  infile.close();

  std::cout << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << "== Reading from people-to-read-2.txt" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << std::endl;

  /*
   * We can finish up by reading people-to-read-2.txt, which is even more
   * structured than people-to-read.txt.  Opening the file works the same,
   * and we're reusing the variable infile again.
   */
  infile.open("people-to-read-2.txt");
  if (infile.fail()) {
    std::cerr << "Error opening file: " << "people-to-read-2.txt" << std::endl;
    return 1;
  }

  /*
   * The first value in people-to-read-2.txt is an integer that indicates the
   * number of people specified in the file.  We can read this integer in first
   * to help us figure out how much space to allocate to an array to store all
   * of the students as well as how many loop iterations we need to perform to
   * read all of the students.
   */
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
