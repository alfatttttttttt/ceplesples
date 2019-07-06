#include <iostream>
#include "menu.h"

using namespace std;
bool IsLoggedIn()
{
  string username, password, un, pw;
  cout << "   ================================== LOGIN ==================================" << endl;
  cout << "   Username : "; cin >> username;
  cout << "   Password : "; cin >> password;

  ifstream read("E:\\FP\\USER\\" + username + ".txt");
  getline(read, un);
  getline(read, pw);

  if (un == username && pw == password)
  {
    return true;
  } else {
    return false;
  }
}


