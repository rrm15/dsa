#include <iostream>
#include <string>
using namespace std;

struct Customer {
  string name;
  string phone;
  string address;
};

struct Order {
  int orderId;
  string product;
  int quantity;
  double price;
  Customer customer;
};

int main() {
  Order order;

  cout << "--- Enter Order Details ---" << endl;
  cout << "Order ID: ";
  cin >> order.orderId;
  cin.ignore();
  cout << "Product: ";
  getline(cin, order.product);
  cout << "Quantity: ";
  cin >> order.quantity;
  cout << "Price per unit: ";
  cin >> order.price;
  cin.ignore();

  cout << "\n--- Enter Customer Details ---" << endl;
  cout << "Name: ";
  getline(cin, order.customer.name);
  cout << "Phone: ";
  getline(cin, order.customer.phone);
  cout << "Address: ";
  getline(cin, order.customer.address);

  cout << "\n===== Complete Order Details =====" << endl;
  cout << "Order ID  : " << order.orderId << endl;
  cout << "Product   : " << order.product << endl;
  cout << "Quantity  : " << order.quantity << endl;
  cout << "Unit Price: " << order.price << endl;
  cout << "Total     : " << order.quantity * order.price << endl;
  cout << "Customer  : " << order.customer.name << endl;
  cout << "Phone     : " << order.customer.phone << endl;
  cout << "Address   : " << order.customer.address << endl;

  return 0;
}
