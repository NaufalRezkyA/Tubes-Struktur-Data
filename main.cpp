#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void mainMenu();

void mainMenu()
{
    int choice;
    List_parent LP;
    List_child LC;
    DataPeminjam DataPeminjam;
    DataMotor DataMtr;
    createListParent(LP);
    createListChild(LC);
    DataM(LC);
    do
    {
        cout << "Menu Peminjaman Motor" << endl;
        cout << "1. Menginput Peminjaman Motor" << endl;
        cout << "2. Menginput Data Motor" << endl;
        cout << "3. Daftar motor yang ada" << endl;
        cout << "4. Daftar motor yang tersedia" << endl;
        cout << "5. Catatan peminjaman motor" << endl;
        cout << "6. Edit data peminjama motor" << endl;
        cout << "7. Delete Data Peminjaman" << endl;
        cout << "8. Delete Data Motor" << endl;
        cout << "9. Reset Data" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            inputDataPeminjam(DataPeminjam);
            insertLastParent(LP, alokasiParent(DataPeminjam));
            break;
        case 2:
            inputDataMotor(DataMtr);
            insertLastChild(LC, alokasiChild(DataMtr));
            break;
        case 3:
            printInfoChild(LC);
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
