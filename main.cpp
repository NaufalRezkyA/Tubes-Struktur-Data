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
    address_relasi R;
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
        cout << "4. Catatan peminjaman motor" << endl;
        cout << "5. Edit data peminjaman motor" << endl;
        cout << "6. Delete Data Peminjaman" << endl;
        cout << "7. Delete Data Motor" << endl;
        cout << "8. Reset Data" << endl;
        cout << "9. 3 Data terbaru" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            dataIdentitas(Datapeminjam);
            inputDataPeminjam(LR,Datapeminjam);
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
            printInfoRelasi(LR);
            break;
        case 5:
            int Id;
            cout<<"Masukkan ID peminjaman yang ingin dirubah datanya:";
            cin>>Id;
            R = findElmRelasiByParent(LR, Id);
            if (R == NULL)
            {
                cout<<"Data tidak ditemukan"<<endl;
            }
            else
            {
                inputDataPeminjam(LR, info(parent(R)));
            }
            break;
        case 6:
            cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            cout << info(P).ID << endl;
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    cout << "ID akan menggunakan Motor pada:" << endl;
                    printDate(info(P).waktucheckIn);
                    cout << "Dengan menghapus data peminjam maka akan menghapus data peminjaman motor" << endl;
                    cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(P).ID);
                    }
                    cout << "dc sukses";
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
            cout<<"Masukkan ID motor yang ingin dihapus: ";
            cin>>idmotor;
            if (findElmChild(LC, idmotor)!=NULL){
                deleteByIDChild(LC, idmotor);
                cout<<"delete berhasil";
            }
            break;
        case 8:
            R = first(LR);
            while(R!=NULL){
                disconnected(LR, info(parent(R)).ID);
                R=next(R);
            }
            P = first(LP);
            while (P!=NULL)
            {
                deleteByIDparent(LP, info(P).ID);
                P=next(P);
            }
            Q = first(LC);
            while(Q!=NULL){
                deleteByIDChild(LC, info(Q).ID);
                Q=next(Q);
            }
            break;
        case 9:
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
