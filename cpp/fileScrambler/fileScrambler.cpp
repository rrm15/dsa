#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream inf("message.txt");
  ofstream outf("secret.txt");
  char ch;

  if (!inf) {
    cout << "file not found" << endl;
    return 1;
  }

  cout << "scrambling the file..." << endl;

  while (inf.get(ch)) {
    if (ch != '\n')
      ch = ch + 3;
    outf.put(ch);
  }

  inf.close();
  outf.close();

  cout << "file has been scrambled.." << endl;

  return 0;
}
