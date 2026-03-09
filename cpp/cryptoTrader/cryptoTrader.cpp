#include <fstream>
#include <iomanip>
#include <iostream>

#include <string>
using namespace std;

struct Coin {
  string name;
  float price;
  int available;
};

struct Holding {
  string name;
  int quantity;
  float boughtAt;
};

Coin shop[20];
int shopSize = 6;

Holding *portfolio = NULL;
int portfolioSize = 0;
int portfolioCapacity = 0;

float balance = 1000.0;

#define CART_MAX 5

void initShop() {
  shop[0] = {"TrumpCoin", 150.0, 10};
  shop[1] = {"DogeFather", 50.0, 20};
  shop[2] = {"ElonBucks", 300.0, 5};
  shop[3] = {"SilverSurfer", 80.0, 15};
  shop[4] = {"GoldDigger", 200.0, 8};
  shop[5] = {"ChaiPeCoin", 10.0, 50};
}

void savePortfolio() {
  ofstream outFile("portfolio.txt");
  outFile << balance << endl;
  outFile << portfolioSize << endl;
  for (int i = 0; i < portfolioSize; i++) {
    outFile << portfolio[i].name << endl;
    outFile << portfolio[i].quantity << endl;
    outFile << portfolio[i].boughtAt << endl;
  }
  outFile.close();
}

void loadPortfolio() {
  ifstream inFile("portfolio.txt");
  if (!inFile) {
    cout << "  No save found. Starting fresh.\n\n";
    return;
  }

  inFile >> balance;
  int savedSize;
  inFile >> savedSize;

  if (savedSize > 0) {
    portfolioCapacity = savedSize;
    portfolio = new Holding[portfolioCapacity];

    for (int i = 0; i < savedSize; i++) {
      inFile >> portfolio[i].name;
      inFile >> portfolio[i].quantity;
      inFile >> portfolio[i].boughtAt;
    }
    portfolioSize = savedSize;
    cout << "  Loaded " << portfolioSize << " coins from save. Balance: $"
         << fixed << setprecision(0) << balance << "\n\n";
  }
  inFile.close();
}

void showStatus() {
  cout << "\n  Balance: $" << fixed << setprecision(0) << balance;
  cout << "  |  Portfolio: " << portfolioSize << " coins";
  cout << "  |  Heap: " << portfolioCapacity << " slots\n";
}

void showShop() {
  cout << "\n  +------ CRYPTO SHOP ------+\n";
  for (int i = 0; i < shopSize; i++) {
    cout << "  | " << i + 1 << ". " << left << setw(14) << shop[i].name;
    cout << "$" << right << setw(4) << fixed << setprecision(0)
         << shop[i].price;
    cout << "  x" << shop[i].available << "\n";
  }
  cout << "  +-------------------------+\n";
}

void addToPortfolio(string coinName, float coinPrice) {
  for (int i = 0; i < portfolioSize; i++) {
    if (portfolio[i].name == coinName) {
      portfolio[i].quantity++;
      return;
    }
  }

  if (portfolioSize == portfolioCapacity) {
    int newCap = (portfolioCapacity == 0) ? 2 : portfolioCapacity * 2;
    Holding *newPortfolio = new Holding[newCap];
    cout << "  HEAP >> Resized: " << portfolioCapacity << " -> " << newCap
         << " slots\n";
    for (int i = 0; i < portfolioSize; i++) {
      newPortfolio[i] = portfolio[i];
    }
    if (portfolio != NULL)
      delete[] portfolio;
    portfolio = newPortfolio;
    portfolioCapacity = newCap;
  }

  portfolio[portfolioSize].name = coinName;
  portfolio[portfolioSize].quantity = 1;
  portfolio[portfolioSize].boughtAt = coinPrice;
  portfolioSize++;
}

void buyCoins() {
  string cart[CART_MAX];
  int cartIndex[CART_MAX];
  int cartTop = -1;
  float cartTotal = 0;

  cout << "\n  === BUY MODE (Cart is on STACK) ===\n";
  showShop();

  int choice;
  while (true) {
    cout << "\n  Cart [" << cartTop + 1 << "/" << CART_MAX << "]  Total: $"
         << fixed << setprecision(0) << cartTotal << "\n";
    cout << "  Coin # to add | 0 = buy | -1 = cancel: ";
    cin >> choice;

    if (choice == 0) {
      if (cartTop == -1) {
        cout << "  Cart empty. Nothing to buy.\n";
        return;
      }
      if (cartTotal > balance) {
        cout << "  Not enough balance! Need $" << cartTotal << "\n";
        continue;
      }

      balance -= cartTotal;
      cout << "\n  STACK >> Popping cart (LIFO):\n";
      while (cartTop >= 0) {
        cout << "    pop -> " << cart[cartTop] << "\n";
        addToPortfolio(cart[cartTop], shop[cartIndex[cartTop]].price);
        shop[cartIndex[cartTop]].available--;
        cartTop--;
      }
      cout << "  STACK >> Cart destroyed automatically.\n";
      cout << "  HEAP  >> Coins stored in portfolio.\n";
      savePortfolio();
      showStatus();
      return;
    } else if (choice == -1) {
      cout << "  Cancelled. Cart discarded.\n";
      return;
    } else if (choice >= 1 && choice <= shopSize) {
      if (cartTop == CART_MAX - 1) {
        cout << "  STACK OVERFLOW! Cart full. Buy or cancel first.\n";
      } else if (shop[choice - 1].available <= 0) {
        cout << "  Sold out!\n";
      } else {
        cartTop++;
        cart[cartTop] = shop[choice - 1].name;
        cartIndex[cartTop] = choice - 1;
        cartTotal += shop[choice - 1].price;
        cout << "  STACK >> push: " << shop[choice - 1].name << "\n";
      }
    } else {
      cout << "  Invalid.\n";
    }
  }
}

void showPortfolio() {
  if (portfolioSize == 0) {
    cout << "\n  Portfolio empty.\n";
    return;
  }

  float totalValue = 0;
  cout << "\n  +---- PORTFOLIO (on HEAP) ----+\n";
  for (int i = 0; i < portfolioSize; i++) {
    float val = portfolio[i].quantity * portfolio[i].boughtAt;
    cout << "  | " << i + 1 << ". " << left << setw(14) << portfolio[i].name;
    cout << "x" << portfolio[i].quantity;
    cout << "  $" << fixed << setprecision(0) << val << "\n";
    totalValue += val;
  }
  cout << "  +-----------------------------+\n";
  cout << "  Value: $" << totalValue;
  cout << "  |  Heap: " << portfolioSize << "/" << portfolioCapacity
       << " slots used\n";
}

void sellCoin() {
  if (portfolioSize == 0) {
    cout << "\n  Nothing to sell.\n";
    return;
  }

  showPortfolio();
  cout << "\n  Coin # to sell (0 = cancel): ";
  int choice;
  cin >> choice;

  if (choice == 0)
    return;
  if (choice < 1 || choice > portfolioSize) {
    cout << "  Invalid.\n";
    return;
  }

  int idx = choice - 1;
  float refund = portfolio[idx].boughtAt * portfolio[idx].quantity;
  cout << "  Sold " << portfolio[idx].name << " for $" << fixed
       << setprecision(0) << refund << "\n";
  balance += refund;

  for (int i = idx; i < portfolioSize - 1; i++) {
    portfolio[i] = portfolio[i + 1];
  }
  portfolioSize--;

  if (portfolioSize == 0) {
    delete[] portfolio;
    portfolio = NULL;
    portfolioCapacity = 0;
    cout << "  HEAP >> All freed. Portfolio memory released.\n";
  } else {
    cout << "  HEAP >> Slot freed.\n";
  }

  savePortfolio();
  showStatus();
}

void devMode() {
  int devChoice;
  while (true) {
    cout << "\n  +--- DEV MODE ---+\n";
    cout << "  | 1. Add coin    |\n";
    cout << "  | 2. Add balance |\n";
    cout << "  | 3. Back        |\n";
    cout << "  +----------------+\n";
    cout << "  dev> ";
    cin >> devChoice;

    if (devChoice == 1) {
      if (shopSize >= 20) {
        cout << "  Shop full.\n";
        continue;
      }
      string coinName;
      float coinPrice;
      int coinQty;
      cout << "  Name: ";
      cin >> coinName;
      cout << "  Price: $";
      cin >> coinPrice;
      cout << "  Qty: ";
      cin >> coinQty;
      shop[shopSize] = {coinName, coinPrice, coinQty};
      shopSize++;
      cout << "  Added " << coinName << "!\n";
    } else if (devChoice == 2) {
      float addAmount;
      cout << "  Amount: $";
      cin >> addAmount;
      balance += addAmount;
      cout << "  Balance: $" << fixed << setprecision(0) << balance << "\n";
    } else if (devChoice == 3) {
      return;
    }
  }
}

int main() {
  cout << "\n  ========================================\n";
  cout << "     CRYPTO TRADER : Stack vs Heap Demo\n";
  cout << "  ========================================\n\n";

  initShop();
  loadPortfolio();
  showStatus();

  int menuChoice;
  while (true) {
    cout << "\n  +-------- MENU --------+\n";
    cout << "  | 1. Shop              |\n";
    cout << "  | 2. Buy       [STACK] |\n";
    cout << "  | 3. Portfolio  [HEAP] |\n";
    cout << "  | 4. Sell       [HEAP] |\n";
    cout << "  | 5. Balance           |\n";
    cout << "  | 6. Dev Mode          |\n";
    cout << "  | 7. Exit              |\n";
    cout << "  +----------------------+\n";
    cout << "  > ";
    cin >> menuChoice;

    if (menuChoice == 1)
      showShop();
    else if (menuChoice == 2)
      buyCoins();
    else if (menuChoice == 3)
      showPortfolio();
    else if (menuChoice == 4)
      sellCoin();
    else if (menuChoice == 5)
      showStatus();
    else if (menuChoice == 6)
      devMode();
    else if (menuChoice == 7) {
      cout << "\n  Saving & exiting...\n";
      savePortfolio();

      if (portfolio != NULL) {
        cout << "  HEAP >> " << portfolioSize
             << " coins still allocated. Freeing...\n";
        delete[] portfolio;
        portfolio = NULL;
      } else {
        cout << "  HEAP >> Clean. Nothing to free.\n";
      }

      cout << "  STACK >> Auto-cleaned on exit.\n";
      cout << "  FILE  >> Portfolio saved. Will reload next run.\n";
      cout << "\n  ========================================\n";
      break;
    } else
      cout << "  Invalid.\n";
  }

  return 0;
}