#include <iostream>
#include <string>
using namespace std;

class Book {
  string isbn;
  string title;
  string author;

public:
  Book() : isbn(""), title(""), author("") {}

  // setters (public methods)
  void setIsbn(const string &i) { isbn = i; }
  void setTitle(const string &t) { title = t; }
  void setAuthor(const string &a) { author = a; }

  // getters
  string getIsbn() { return isbn; }
  string getTitle() { return title; }
  string getAuthor() { return author; }

  void print() {
    cout << "ISBN:   " << isbn << endl;
    cout << "Title:  " << title << endl;
    cout << "Author: " << author << endl;
  }

  void updateTitle(const string &newTitle) {
    title = newTitle;
    cout << "  [Title updated to: \"" << title << "\"]" << endl;
  }
};

int main() {
  // creating object via default constructor, setting through setters
  Book b1;
  b1.setIsbn("978-0-13-468599-1");
  b1.setTitle("The C++ Programming Language");
  b1.setAuthor("Bjarne Stroustrup");

  cout << "--- Book Details ---" << endl;
  b1.print();

  cout << "\n--- Updating Title ---" << endl;
  b1.updateTitle("The C++ Programming Language (4th Edition)");

  cout << "\n--- Updated Book ---" << endl;
  b1.print();

  return 0;
}
