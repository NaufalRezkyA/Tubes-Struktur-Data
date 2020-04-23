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
    List_relasi LR;
    DataPeminjam Datapeminjam;
    DataMotor DataMtr;
    address_parent P;
    address_child Q;
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);
    DataM(LC);
    int id;
    string idmotor;
    do
    {
        cout << "Menu Peminjaman Motor" << endl;
        cout << "1. Menginput Peminjaman Motor" << endl;
        cout << "2. Menginput Data Motor" << endl;
        cout << "3. Daftar motor yang ada" << endl;
        cout << "5. Catatan peminjaman motor" << endl;
        cout << "6. Edit data peminjaman motor" << endl;
        cout << "7. Delete Data Peminjaman" << endl;
        cout << "8. Delete Data Motor" << endl;
        cout << "9. Reset Data" << endl;
        cout << "10. 3 Data terbaru" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            inputDataPeminjam(LR,Datapeminjam);
            CheckInputanCheckin(LR, Datapeminjam);
            P = alokasiParent(Datapeminjam); 
            insertAndsortParent(LP, P);
            Q = findElmChild(LC, Datapeminjam.IDMotor);
            insertLastRelasi(LR, alokasiRelasi(P,Q));
            break; 
        case 2:
            inputDataMotor(DataMtr);
            insertLastChild(LC, alokasiChild(DataMtr));
            break;
        case 3:
            printInfoChild(LC);
            break;
        case 4:
            MotorYangTersedia(LR, LC);
            break;
        case 5:
            printInfoRelasi(LR);
            break;
        case 6:
            cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            cout<<info(P).ID<<endl;
            if (P != NULL)
            {
                address_relasi Q = findElmRelasiByParent(LR, P);
                if(Q!=NULL){
                    cout<<"ID akan menggunakan Motor pada:"<<endl;
                    printDate(info(P).waktucheckIn);
                    cout<<"Dengan menghapus data peminjam maka akan menghapus data peminjaman motor"<<endl;
                    cout<<"Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin>> penentuDelete;
                    if (penentuDelete=='Y'){
                        disconnected(LR, info(P).ID);
                    }
                    cout<<"dc sukses";
                    deleteByIDparent(LP, id);
                    cout << "Data berhasil dihapus.." << endl;
                }
            }
            else
            {
                cout << "Data Tidak ada.." << endl;
            }
            cout << endl;
            break;
        case 7:

            break;

        case 8:
            cout<<"Masukkan ID motor yang ingin dihapus: ";
            cin>>idmotor;
            if (findElmChild(LC, idmotor)!=NULL){
                deleteByIDChild(LC, idmotor);
                cout<<"delete berhasil";
            }
            break;
        case 9:
            break;
        case 10:
            printInfoTerbaru(LR);
            break;
        }
        
        if (choice == 0)
        {
            break;
        }
    } while (true);

}




int main()
{
    mainMenu();

    return 0;
}
