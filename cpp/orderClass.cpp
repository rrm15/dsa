#include <iostream>
#include <vector>
using namespace std;

struct LineItem {
  int id;
  int qty;
};

class Order {
  vector<LineItem> items;

public:
  void addLineItem(int id, int qty) {
    // check if item already exists, update qty
    for (int i = 0; i < items.size(); i++) {
      if (items[i].id == id) {
        items[i].qty += qty;
        cout << "  Updated item " << id << ", new qty: " << items[i].qty
             << endl;
        return;
      }
    }
    items.push_back({id, qty});
    cout << "  Added item " << id << " (qty: " << qty << ")" << endl;
  }

  int totalItems() {
    int total = 0;
    for (int i = 0; i < items.size(); i++)
      total += items[i].qty;
    return total;
  }

  void printSummary() {
    cout << "\n===== Order Summary =====" << endl;
    cout << "Line items: " << items.size() << endl;
    for (int i = 0; i < items.size(); i++)
      cout << "  ID: " << items[i].id << " | Qty: " << items[i].qty << endl;
    cout << "Total items: " << totalItems() << endl;
  }
};

int main() {
  Order order;

  // object creation
  cout << "--- Adding items ---" << endl;
  order.addLineItem(101, 3);
  order.addLineItem(102, 1);
  order.addLineItem(103, 5);

  // modification
  cout << "\n--- Modifying items ---" << endl;
  order.addLineItem(101, 2); // update existing

  // summary
  order.printSummary();

  return 0;
}
