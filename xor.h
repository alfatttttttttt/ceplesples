#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Menu
void enxor()
{
    Label:
    cout << "" << endl;
    cout << "   ============= CIPHER XOR =============" << endl;
    cout << "   [                                    ]" << endl;
    cout << "   [  MENU :                            ]" << endl;
    cout << "   [  1. Enkripsi Pesan                 ]" << endl;
    cout << "   [  2. Dekripsi Pesan                 ]" << endl;
    cout << "   [                                    ]" << endl;
    cout << "   ======================================" << endl;
    cout << "   Silahkan Masukkan Pilihan Anda : ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "   ---Enkripsi---" << endl;
        string msg;
        cout << "   Masukkan Pesan Anda : ";
        getline(cin, msg);

        string key;
        cout << "   Masukkan Key Anda : ";
        getline(cin, key);

        string encrypHexa = "";
        int keyItr = 0;
        stringstream res;
        for (int i = 0; i < msg.length(); i++){
            int temp = msg[i] ^ key[keyItr];

            res << hex << setfill('0') << std::setw(2) << (int)temp;
            keyItr++;
            if (keyItr >= key.length()){
                keyItr = 0;
            }
        }

        res >> encrypHexa;
        cout << "   Selamat ! Text Anda Telah Terenkripsi! : " << encrypHexa;
        cout << "\n";
        char lagi;
        cout << "" << endl;
        cout << "   Apakah anda ingin mengulang kembali (Y/N) ? "; cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
        {
            goto Label;
        } else {
            goto Finish;
        }
    } else if (choice == 2){
        cout << endl << "   ---Dekripsi---" << endl;
        string msg;
        cout << "   Masukkan Pesan Anda : ";
        getline(cin, msg);

        string key;
        cout << "   Masukkan Key Anda : ";
        getline(cin, key);

        string hexToUni = "";
        for (int i = 0; i < msg.length()-1; i+=2){
            string output = msg.substr(i, 2);
            int decimal = strtol(output.c_str(), NULL, 16);
            hexToUni += (char)decimal;
        }

        string decrypText = "";
        int keyItr = 0;
        for (int i = 0; i < hexToUni.length(); i++){
            int temp = hexToUni[i] ^ key[keyItr];

            decrypText += (char)temp;
            keyItr++;
            if (keyItr >= key.length()){
                keyItr = 0;
            }
        }

        cout << "   Selamat ! Teks Anda Telah Di Dekripsi!(String): " << decrypText;
        cout << "\n";
        char lagi;
        cout << "" << endl;
        cout << "   Apakah anda ingin mengulang kembali (Y/N) ? "; cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
        {
            goto Label;
        } else {
            goto Finish;
        }
    } else {
        cout << endl << "   Pilihan Salah ! Masukkan Dengan Benar !" << endl;
    }
    Finish :
    exit;
}
