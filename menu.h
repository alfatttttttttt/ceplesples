#include <iostream>
#include <windows.h>
#include "cout.h"
#include "subnet.h"
#include "cipher.h"
#include "xor.h"

using namespace std;

void menu()
{
  int choice, kripto, jaringan;
  cout1();
  cout << "   Masukkan pilihan : "; cin >> choice;
  switch(choice)
  {
    case 1:
    cout2();
    cout << "   Masukkan pilihan : "; cin >> kripto;
    switch(kripto)
    {
      case 1:
      system("cls");
      cipher();
      char ask1;
      cout << "   Apakah anda ingin kembali ke menu utama (Y/N)? "; cin >> ask1;
      cout << "   "; system("PAUSE");
      if (ask1 == 'Y' || ask1 == 'y')
      {
        system("cls");
        menu();
      } else {
        exit;
      }
      break;

      case 2:
      system("cls");
      enxor();
      char ask2;
      cout << "   Apakah anda ingin kembali ke menu utama (Y/N)? "; cin >> ask2;
      cout << "   "; system("PAUSE");
      if (ask2 == 'Y' || ask2 == 'y')
      {
        system("cls");
        menu();
      } else {
        exit;
      }
      break;
    }
    break;

    case 2:
    cout3();
    cout << "   Masukkan pilihan : "; cin >> jaringan;
    switch(jaringan)
    {
      case 1:
      subnet();
      char ask4;
      cout << "   Apakah anda ingin kembali ke menu utama (Y/N) ? "; cin >> ask4;
      cout << "   "; system("PAUSE");
      if (ask4 == 'Y' || ask4 == 'y')
      {
        system("cls");
        menu();
      } else {
        exit;
      }
      break;
    }
    case 3:
    system("cls");
    char keluar;
    cout << "  " << endl;
    cout << "   Apakah anda yakin ingin keluar (Y/N)? "; cin >> keluar;
    if (keluar == 'Y' || keluar == 'y')
      {
        MessageBox(0,"Berhasil Keluar!","KELUAR",0);
        system("cls");
        system("main");
      } else {
        menu();
      }
    break;
  }
}