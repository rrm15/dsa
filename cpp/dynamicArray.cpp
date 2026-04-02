#include <iostream>
using namespace std;

int main() {
  int capacity = 2;
  int size = 0;
  int *arr = new int[capacity];

  cout << "Dynamic array (doubles when capacity exceeded)" << endl;
  cout << "Enter integers (-1 to stop):" << endl;

  int val;
  while (true) {
    cout << "> ";
    cin >> val;
    if (val == -1)
      break;

    // double capacity if full
    if (size == capacity) {
      int newCapacity = capacity * 2;
      int *newArr = new int[newCapacity];
      for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
      delete[] arr;
      arr = newArr;
      cout << "  [Capacity doubled: " << capacity << " -> " << newCapacity
           << "]" << endl;
      capacity = newCapacity;
    }

    arr[size] = val;
    size++;
  }

  cout << "\nArray contents (size=" << size << ", capacity=" << capacity
       << "):" << endl;
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;

  delete[] arr;
  return 0;
}
