#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
  string name;
  string subject;

  Teacher(string n, string s) : name(n), subject(s) {}

  virtual void showRole() { cout << "  Role: Teacher" << endl; }

  void showTeacher() {
    cout << "  Name:    " << name << endl;
    cout << "  Subject: " << subject << endl;
  }
};

class Researcher {
public:
  string researchArea;

  Researcher(string area) : researchArea(area) {}

  virtual void showRole() { cout << "  Role: Researcher" << endl; }

  void showResearch() {
    cout << "  Research: " << researchArea << endl;
  }
};

class Professor : public Teacher, public Researcher {
  string university;

public:
  Professor(string n, string s, string area, string uni)
      : Teacher(n, s), Researcher(area), university(uni) {}

  // method overriding
  void showRole() override {
    cout << "  Role: Professor (Teacher + Researcher)" << endl;
  }

  void showAll() {
    showRole();
    showTeacher();
    showResearch();
    cout << "  University: " << university << endl;
  }
};

int main() {
  cout << "--- Teacher ---" << endl;
  Teacher t("Alice", "Physics");
  t.showRole();
  t.showTeacher();

  cout << "\n--- Researcher ---" << endl;
  Researcher r("Quantum Computing");
  r.showRole();
  r.showResearch();

  cout << "\n--- Professor (multiple inheritance) ---" << endl;
  Professor p("Dr. Bob", "Computer Science", "Machine Learning", "MIT");
  p.showAll();

  return 0;
}
