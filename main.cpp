#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "login.h"
using namespace std;

int main()
{
  int hello;
  cout << " " << endl;
  cout << "   ===========================================================================" << endl;
  cout << " " << endl;
  cout << "              `    -sNmo.                                             ,---." << endl;
  cout << "           `/dM+.omMMMMMMd+`          ,--.  ,--.       ,--.,--.       |   |" << endl;
  cout << "         :yMdo+hMMMMMd+``+dMy:        |  '--'  | ,---. |  ||  | ,---. |  .'" << endl;
  cout << "      .sNMs.`NMMMMmo.   .hy+omm       |  .--.  || .-. :|  ||  || .-. ||  | " << endl;
  cout << "     /MMMM.  .dNy-     :NMMMNs-       |  |  |  ||   --.|  ||  |' '-' '`--' " << endl;
  cout << "      dMMMh     .oyhyo- /hMMMMMd+`    `--'  `--' `----'`--'`--' `---' .--. " << endl;
  cout << "      -MMMM/   yMMMMMMMy  `+dMMMMMy    versi 1.0 UPDATE               '--' " << endl;
  cout << "     .-sMMMN` /MMMs-oMMM+    -sNMMs   " << endl;
  cout << "     mM-mMMMy -MMMdodMMM: ..   .Mm`   " << endl;
  cout << "     -Md:dyo:  :dMMMMMd: -MMMd`hM:    " << endl;
  cout << "      sM+        `:::`   mMMMh/My     Login sebelum menggunakan aplikasi ini! " << endl;
  cout << "      `mNyyyyyyyyyys    oMMMN.NN`     Pilih salah satu :" << endl;
  cout << "       :MMMMMMMMMMMM`  -MMMM+         1. Login" << endl;   
  cout << "        +sssssssssso   dMMMd          2. Daftar" << endl;
  cout << "               dMMMMMMMMMMN.          >> "; cin >> hello;
  cout << " " << endl;
  cout << "   ===========================================================================" << endl;
  cout << " " << endl;
  if (hello == 2)
  {
    string username, password, email;

    cout << "   ================================== DAFTAR ==================================" << endl;
    cout << "   Username : "; cin >> username;
    cout << "   Password : "; cin >> password;
    cout << "   Email    : "; cin >> email;
    MessageBox(0,"Pendaftaran Berhasil!","DAFTAR",0);
    string encrypHexa = "";
        int keyItr = 0;
        string key = "5";
        stringstream res;
        for (int i = 0; i < password.length(); i++){
            int temp = password[i] ^ key[keyItr];

            res << hex << setfill('0') << std::setw(2) << (int)temp;
            keyItr++;
            if (keyItr >= key.length()){
                keyItr = 0;
            }
        }

        res >> encrypHexa;

    ofstream file;
    file.open("C:\\" + username + ".txt");
    file << username << endl << encrypHexa << endl << email;
    file.close();
    system("cls");
    main();
  }
  else if (hello == 1)
  {
    bool status = IsLoggedIn();

    if (!status)
    {
      MessageBox(0,"Login Gagal!","LOGIN",0);
      cout << "   "; system("PAUSE");
      return 0;
    }
    else
    {
      MessageBox(0,"Login Berhasil!","LOGIN",0);
      system("cls");
      menu();
      return 1;
    }
  }
  else
  {
    cout << "   Pilihan anda salah!" << endl;
    cout << "   "; system("PAUSE");
  }
  cin.get();
  return 0;
}
