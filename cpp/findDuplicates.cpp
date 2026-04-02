#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[100];
  cout << "Enter " << n << " integers: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Duplicate elements: ";
  bool found = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        // check if we already printed this duplicate
        bool alreadyPrinted = false;
        for (int k = 0; k < i; k++) {
          if (arr[k] == arr[i]) {
            alreadyPrinted = true;
            break;
          }
        }
        if (!alreadyPrinted) {
          cout << arr[i] << " ";
          found = true;
        }
        break;
      }
    }
  }

  if (!found)
    cout << "None";
  cout << endl;

  return 0;
}
