#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
  string name;
  double salary;

public:
  Employee(string n, double s) : name(n), salary(s) {}

  void displayDetails() {
    cout << "Name:   " << name << endl;
    cout << "Salary: " << salary << endl;
  }
};

class Manager : public Employee {
  string department;

public:
  Manager(string n, double s, string dept) : Employee(n, s), department(dept) {}

  void displayDetails() {
    Employee::displayDetails();
    cout << "Dept:   " << department << endl;
  }
};

int main() {
  cout << "--- Employee ---" << endl;
  Employee emp("Alice", 50000);
  emp.displayDetails();

  cout << "\n--- Manager ---" << endl;
  Manager mgr("Bob", 85000, "Engineering");
  mgr.displayDetails();

  return 0;
}
