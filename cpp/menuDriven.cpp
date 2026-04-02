#include <iostream>
using namespace std;

int main() {
  int choice;

  do {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Add two numbers" << endl;
    cout << "2. Subtract two numbers" << endl;
    cout << "3. Multiply two numbers" << endl;
    cout << "4. Divide two numbers" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    double a, b;
    if (choice >= 1 && choice <= 4) {
      cout << "Enter two numbers: ";
      cin >> a >> b;
    }

    switch (choice) {
    case 1:
      cout << "Result: " << a + b << endl;
      break;
    case 2:
      cout << "Result: " << a - b << endl;
      break;
    case 3:
      cout << "Result: " << a * b << endl;
      break;
    case 4:
      if (b != 0)
        cout << "Result: " << a / b << endl;
      else
        cout << "Error: Division by zero!" << endl;
      break;
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice!" << endl;
    }
  } while (choice != 5);

  return 0;
}
