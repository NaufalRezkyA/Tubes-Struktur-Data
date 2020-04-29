#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void mainMenu();
void currentTime();

void currentTime(){
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;
}

void mainMenu()
{
    int choice;
    List_parent LP;
    List_child LC;
    List_relasi LR;
    DataPeminjam Datapeminjam;
    DataMotor DataMtr;
    address_parent P,T;
    address_child Q,U;
    address_relasi R,S;
    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);
    DataM(LC);
    int id;
    int idmotor;
    infotype_parent x;
    infotype_child y;
    do
    {
        currentTime();
        cout << "Menu Penyewaan Motor" << endl;
        cout << "1. Masukkan data Member" << endl;
        cout << "2. Menampilkan data member" << endl;
        cout << "3. Masukkan data Motor"<<endl;
        cout << "4. Menampilkan data motor" << endl;
        cout << "5. Penyewaan Motor" << endl;
        cout << "6. Cek Penyewaan Motor" << endl;
        cout << "7. Hapus Data Penyewaan Motor" << endl;
        cout << "8. Menampilkan Data Penyewaan" << endl;
        cout << "9. Menampilkan motor yang disewa" << endl;
        cout << "10. Menghapus Data Motor" << endl;
        cout << "11. Menghapus Data Member" << endl;
        cout << "12. Menampilkan 3 Data Transaksi Terbaru" << endl;
        cout << "13. Reset Semua Data" << endl;
        cout << "14. Total Pendapatan" << endl;
        cout << "0. Quit" << endl;
        cout << "Masukan angka:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            dataIdentitas(LP,Datapeminjam);
            inputDataPeminjam(LR,Datapeminjam);
            P = alokasiParent(Datapeminjam);
            insertAndsortParent(LP, P);
            break;
        case 2:
            printInfoParent(LP);
            break;
        case 3:
            inputDataMotor(LC, DataMtr);
            insertAndsortChild(LC, alokasiChild(DataMtr));
            break;
        case 4:
            printInfoChild(LC);
            break;
        case 5:
            cout << "ID peminjam:";
            cin >> x.ID;
            P = findElmParent(LP, x.ID);
            if(P!=NULL){
                checkin(LR,LC, info(P), y);
                connect(LR, LP, LC, x, y);
            }else{
                cout<<"Data tidak tidak ada..."<<endl;
            }
            break;
        case 6:
            cout<<"Masukkan ID peminjam: ";
            cin>>x.ID;
            cout<<"Masukkan ID motor: ";
            cin>>y.ID;
            P = findElmParent(LP, x.ID);
            Q = findElmChild(LC, y.ID);
            if(P!=NULL & Q!=NULL){
                R = findElmRelasiByParent(LR, info(P).ID);
                S = findElmRelasiByChild(LR, info(Q).ID);
                if(R!=NULL & S!=NULL){
                    cout<<"Data telah terhubung"<<endl;
                } else{
                    cout<<"Data belum terhubung"<<endl;
                }
            }else{
                cout<<"Data yang anda cari tidak ada..."<<endl;
            }
            break;
        case 7:
            cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    disconnected(LR, info(P).ID);
                    cout << "Penghapusan Data berhasil...";
                }
            }
            else
            {
                cout << "Data peminjam Tidak ada..." << endl;
            }
            cout << endl;
            break;
        case 8:
            if (first(LR) != NULL)
            {
                printInfoRelasi(LR);
            }
            else
            {
                cout << "kosong" << endl;
            }
            break;

        case 9:
            cout << "Masukkan ID peminjam:";
            cin >> x.ID;
            R = first(LR);
            if(R!=NULL){
                while (R != NULL)
                {
                    if(info(parent(R)).ID==x.ID){
                        cout << info(parent(R)).namaPeminjam << endl;
                        cout << info(parent(R)).ID << endl;
                        cout << info(child(R)).NamaMotor << endl;
                        cout << "Waktu checkin:" << endl;
                        printDate(info(parent(R)).waktucheckIn);
                        cout << "Waktu checkout:" << endl;
                        printDate(info(parent(R)).waktucheckOut);
                    }
                    R=next(R);
                }
            }else{
                cout<<"ID peminjam tidak ditemukan..."<<endl;
            }
            break;
        case 10:
            cout << "Masukkan ID motor yang ingin di hapus: ";
            cin >> id;
            Q = findElmChild(LC, id);
            if (Q != NULL)
            {
                R = findElmRelasiByChild(LR, info(Q).ID);
                if (R != NULL)
                {
                    cout << "ID akan menggunakan Motor pada:" << endl;
                    printDate(info(parent(R)).waktucheckIn);
                    cout << "Dengan menghapus data motor maka akan menghapus data Penyewaan motor" << endl;
                    cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(parent(R)).ID);
                        deleteByIDChild(LC, id);
                        cout << "Penghapusan Data Berhasil..." << endl;
                    }
                }
            }
            else
            {
                cout << "Data Tidak ada.." << endl;
            }
            cout << endl;
            break;
        case 11:
            cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    cout << "ID akan menggunakan Motor pada:" << endl;
                    printDate(info(P).waktucheckIn);
                    cout << "Dengan menghapus data peminjam maka akan menghapus data Penyewaan motor" << endl;
                    cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(P).ID);
                        deleteByIDparent(LP, id);
                        cout << "Penghapusan Data Berhasil..." << endl;
                    }
                }
            }
            else
            {
                cout << "Data Tidak ada.." << endl;
            }
            cout << endl;
            break;

        case 12:
            printInfoTerbaru(LR);
            break;
        case 13:
            int i;
            R = first(LR);
            if (R != NULL)
            {
                i = CountRelasi(LR);
                while (i > 0)
                {
                    deleteFirstRelasi(LR, S);
                    dealokasiRelasi(S);
                    i--;
                }
            }
            P = first(LP);
            if (P != NULL)
            {
                i = CountParent(LP);
                while (i > 0)
                {
                    deleteFirstParent(LP, T);
                    dealokasiParent(T);
                    i--;
                }
            }
            Q = prev(first(LC));
            if (Q != NULL)
            {
                i = CountChild(LC);
                while (i > 0)
                {
                    deleteFirstChild(LC, U);
                    dealokasiChild(U);
                    i--;
                }
            }
            cout<<"Reset Data Berhasil..."<<endl;
            break;
        case 14:
            cout<<"Total Pendapatan: ";
            cout<<totalIncome(LR)<<endl;
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
