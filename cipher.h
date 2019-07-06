#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void cipher()
 {
    Label:
    cout << "" << endl;
    cout << "   =============== CIPHER ===============" << endl;
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
        char data[100], cipher[100], hasilen;
        int key;
        cout<<"   Masukkan Pesan (tanpa spasi): ";
        gets(data);
        cout<<"   Masukkan Key [1-25]: ";
        cin>>key;
        cout << "   Hasil Enkripsi : ";
        for(int i=0;data[i]!='\0';i++)
                data[i] = toupper(data[i]); 
        for(int x=0;data[x]!='\0';x++)
        {
                if(data[x]==' ')
                              cipher[x] = data[x];
                else
                              cipher[x] = ((int(data[x]+key)%65)%26) + 65; 
                              cipher[x+1] = '\0'; 
        }
        for(int y=0;cipher[y]!='\0';y++)
            cout<< "   " << cipher[y];
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
        string encpMsg;
            cout << "   Masukkan Pesan (tanpa spasi): ";
            getline(cin, encpMsg);

            int dcyptKey;
            cout << "   Masukkan Kunci [0-25]: ";
            cin >> dcyptKey;
            cin.ignore();

            string decryptedText = encpMsg;

            for (int i = 0; i < encpMsg.size(); i++){
                if(encpMsg[i]==32){
                    continue; 
                } else {
                    if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    } else if((encpMsg[i] - dcyptKey) < 65){
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    } else {
                        decryptedText[i] = encpMsg[i] - dcyptKey;
                    }
                }
            }

            cout << "   Hasil Dekripsi Pesan : " << decryptedText << endl;
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