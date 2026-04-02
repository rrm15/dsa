#include <iostream>
#include <string>
using namespace std;

class CryptoBox {
  string privateKey;
  string owner;
  double balance;

  // friend function can access private members
  friend void dumpForAudit(const CryptoBox &box);

public:
  CryptoBox(string key, string own, double bal)
      : privateKey(key), owner(own), balance(bal) {}
};

// friend function definition
void dumpForAudit(const CryptoBox &box) {
  cout << "===== AUDIT REPORT =====" << endl;
  cout << "Owner:       " << box.owner << endl;
  cout << "Private Key: " << box.privateKey << endl;
  cout << "Balance:     " << box.balance << endl;
}

// regular function - cannot access private members
void tryAccess(const CryptoBox &box) {
  cout << "\n[Regular function] Cannot access private members." << endl;
  // The following lines would cause compile errors:
  // cout << box.privateKey;   // ERROR: 'privateKey' is private
  // cout << box.owner;        // ERROR: 'owner' is private
  // cout << box.balance;      // ERROR: 'balance' is private
  cout << "(Commented out lines would cause compile errors)" << endl;
}

int main() {
  CryptoBox wallet("0xABCDEF1234567890", "Alice", 15.75);

  // friend function can inspect private fields
  dumpForAudit(wallet);

  // regular function cannot
  tryAccess(wallet);

  return 0;
}
