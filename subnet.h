#include <stdlib.h>
#include <math.h>
#include <iostream>
 
using namespace std;
void subnet()
{
    Subnet :
    int prefix, subnet, mask, broad, pangkat;
    unsigned int range,host;
    short int akhir;
    short int x=0;
 
    cout << "   Input Prefix (0-32) : "; cin >> prefix;
  
    if (prefix==31 || prefix==32 || prefix==0)
    {
        cout << "   Maaf, prefix "<< prefix <<" yang anda masukkan tidak bisa dikategorikan sebagai jaringan." << endl;
        goto Subnet;
    }
    else if (prefix <=30 && prefix>=24) 
    {
        pangkat = 32 - prefix;
        subnet = pow (2, pangkat);
        mask = 256 - subnet;
  
        cout << endl << "   Maka subnet mask dari prefix /" << prefix <<" adalah 255.255.255." << mask << endl;
        cout << "   Range networknya adalah " << subnet << " IP" << endl;
        host = subnet - 2;
        cout << "   Jumlah host yang bisa digunakan adalah " << host << " IP" << endl << endl;
        cout << "   Range networknya adalah : " << endl;
        do 
        {
            cout << "   192.168.1." << x << "/" << prefix;
            x = x + subnet;
            broad = x - 1;
            cout << " - 192.168.1." << broad << endl;
        }
        while (x<=255);
        cout << endl << "   IP yang bisa dipakai adalah : " << endl;
        short int y=1;
        do 
        {
            cout << "   192.168.1." << y;
            y = y + subnet;
            akhir = y - 3;
            cout << " - 192.168.1." << akhir << endl;
        } 
        while (y<255);
    }
    else if (prefix <24 && prefix >=16)
    {
        pangkat = 24 - prefix;
        subnet = pow (2, pangkat);
        mask = 256 - subnet;
  
        cout << "\n   Maka subnet mask dari prefix /" << prefix << " adalah 255.255." << mask << ".0" << endl;
        range = pow (2, (32 - prefix));
        cout << "   Range networknya adalah " << range << " IP" << endl;
        host = (pow (2, (32 - prefix))) - 2;
        cout << "   Jumlah host yang bisa digunakan adalah " << host << " IP" << endl << endl;
        cout << "   Range networknya adalah : " << endl;
 
        do 
        {
            cout << "   172.16." << x << ".0/" << prefix;
            x = x + subnet;
            broad = x - 1;
            cout << " - 172.16." << broad << ".255" << endl;
        } 
        while (x<=255);
        cout << endl << "   IP yang bisa dipakai adalah : " << endl;
        short int y=0;
        do
        {
            cout << "   172.16." << y << ".1";
            y = y + subnet;
            akhir = y - 1;
            cout << " - 172.16." << akhir << ".254" << endl;
        }
        while (y<255);
    }
    else if (prefix <16 && prefix >=8) 
    {
        pangkat = 16 - prefix;
        subnet = pow (2, pangkat);
        mask = 256 - subnet;

        cout << "\n   Maka subnet mask dari prefix /" << prefix << " adalah 255." << mask << ".0.0" << endl;
        range = pow (2, (32 - prefix));
        cout << "   Range networknya adalah " << range << " IP" << endl;
        host = (pow (2, (32 - prefix))) - 2;
        cout << "   Jumlah host yang bisa digunakan adalah " << host << " IP" << endl << endl;
 
        cout << "   Range networknya adalah : " << endl;
        do 
        {
            cout << "10." << x << ".0.0/" << prefix;
            x = x + subnet;
            broad = x - 1;
            cout << " - 10." << broad << ".255.255" << endl;
        }
        while (x<=255);
  
        cout << endl << "   IP yang bisa dipakai adalah : " << endl;
        short int y=0;
        do 
        {
            cout << "   10." << y << ".0.1";
            y = y + subnet;
            akhir = y - 1;
            cout << " - 10." << akhir << ".255.254" << endl;
        }
        while (y<255);
    }
    else if (prefix <8 && prefix >=0)
    {
        pangkat = 8 - prefix;
        subnet = pow (2, pangkat);
        mask = 256 - subnet;
  
        cout << "\n   Maka subnet mask dari prefix /" << prefix << " adalah " << mask << ".0.0.0" << endl;
        range = pow (2, (32 - prefix));
        cout << "   Range networknya adalah " << range << " IP" << endl;
        host = (pow (2, (32 - prefix))) - 2;
        cout << "   Jumlah host yang bisa digunakan adalah " << host << " IP" << endl << endl;
 
        cout << "   Range networknya adalah : " << endl;
        do
        {
            cout << "   " << x << ".0.0.0/" << prefix;
            x = x + subnet;
            broad = x - 1;
            cout << " - " << broad << ".255.255.255" << endl;
        }
        while (x<=255);
 
        cout << endl << "   IP yang bisa dipakai adalah : " << endl;
        short int y=0;
        do
        {
            cout << "   " << y << ".0.0.1";
            y = y + subnet;
            akhir = y - 1;
            cout << " - " << akhir << ".255.255.254" << endl;
        }
        while (y<255);
    }
    else
    {
        cout << endl << "   Maaf, kode yang anda masukkan salah. Harus angka antara 0-32." << endl;
    }
    char lagi;
    cout << "" << endl;
    cout << "   Apakah anda ingin mengulang kembali (Y/N) ? "; cin >> lagi;
    if (lagi == 'Y' || lagi == 'y')
    {
        goto Subnet;
    } else {
        goto Finish;
    }
    Finish :
    exit;
}