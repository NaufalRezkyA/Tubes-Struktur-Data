#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void mainMenu();

void mainMenu()
{
    int choice;
    DataPeminjam DataPeminjam;
    do
    {
        cout << "Menu Peminjaman Motor" << endl;
        cout << "1. Menginput Peminjaman Motor" << endl;
        cout << "1. Menginput Data Motor" << endl;
        cout << "2. Daftar motor yang ada" << endl;
        cout << "3. Daftar motor yang tersedia" << endl;
        cout << "4. Catatan peminjaman motor" << endl;
        cout << "5. Edit data peminjama motor" << endl;
        cout << "6. Delete Data Peminjaman" << endl;
        cout << "6. Delete Data Motor" << endl;
        cout << "5. Reset Data" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"hello"<<endl;
            inputDataPeminjam(DataPeminjam);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        }
        if (choice == 0)
        {
            break;
        }
    } while (true);

    //----------------------------------------
}




int main()
{
    mainMenu();

    return 0;
}
