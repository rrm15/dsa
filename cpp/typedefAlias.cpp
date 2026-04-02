#include <iostream>
#include <string>
using namespace std;

// using typedef
typedef struct {
  string name;
  int age;
  double gpa;
} Student;

// using 'using' keyword (C++11 alias)
using Marks = int;
using Name = string;

int main() {
  // typedef usage
  Student s1;
  s1.name = "Alice";
  s1.age = 20;
  s1.gpa = 3.85;

  cout << "--- typedef usage ---" << endl;
  cout << "Name: " << s1.name << endl;
  cout << "Age:  " << s1.age << endl;
  cout << "GPA:  " << s1.gpa << endl;

  // using alias usage
  Name studentName = "Bob";
  Marks math = 95;
  Marks science = 88;

  cout << "\n--- using alias usage ---" << endl;
  cout << "Student: " << studentName << endl;
  cout << "Math:    " << math << endl;
  cout << "Science: " << science << endl;

  return 0;
}
