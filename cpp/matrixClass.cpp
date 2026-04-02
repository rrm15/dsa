#include <initializer_list>
#include <iostream>
using namespace std;

class Matrix {
  int **data;
  int rows, cols;

  void allocate() {
    data = new int *[rows];
    for (int i = 0; i < rows; i++)
      data[i] = new int[cols]();
  }

  void deallocate() {
    if (data) {
      for (int i = 0; i < rows; i++)
        delete[] data[i];
      delete[] data;
      data = nullptr;
    }
  }

public:
  // default constructor
  Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
    allocate();
    cout << "  [Constructed " << rows << "x" << cols << " matrix]" << endl;
  }

  // initializer_list constructor
  Matrix(int r, int c, initializer_list<initializer_list<int>> init)
      : rows(r), cols(c), data(nullptr) {
    allocate();
    int i = 0;
    for (auto &row : init) {
      int j = 0;
      for (auto &val : row) {
        if (i < rows && j < cols)
          data[i][j] = val;
        j++;
      }
      i++;
    }
    cout << "  [Constructed " << rows << "x" << cols
         << " matrix from initializer list]" << endl;
  }

  // destructor
  ~Matrix() {
    cout << "  [Destructor: freeing " << rows << "x" << cols << " matrix]"
         << endl;
    deallocate();
  }

  void display() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        cout << data[i][j] << "\t";
      cout << endl;
    }
  }
};

int main() {
  cout << "--- Default constructor (2x3 zero matrix) ---" << endl;
  Matrix m1(2, 3);
  m1.display();

  cout << "\n--- Initializer list constructor ---" << endl;
  Matrix m2(2, 3, {{1, 2, 3}, {4, 5, 6}});
  m2.display();

  cout << "\n--- Scope exit (destructors will fire) ---" << endl;
  return 0;
}
