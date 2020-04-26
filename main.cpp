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
        cout << "Menu Peminjaman Motor" << endl;
        cout << "1. Menginput Peminjam Motor" << endl;
        cout << "2. Menginput Data Motor" << endl;
        cout << "3. Menginput transaksi penyewaan"<<endl;
        cout << "4. Data peminjam" << endl;
        cout << "5. Daftar motor yang ada" << endl;
        cout << "6. Catatan peminjaman motor" << endl;
        cout << "7. Lihat data motor yang di sewa peminjam" << endl;
        cout << "8. Edit data peminjaman motor" << endl;
        cout << "9. Batalkan peminjaman motor by ID" << endl;
        cout << "10. Delete Data si peminjam" << endl;
        cout << "11. Delete Data Motor" << endl;
        cout << "12. 3 Data Transaksi terbaru" << endl;
        cout << "13. Reset Data" << endl;
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
            inputDataMotor(LC, DataMtr);
            insertAndsortChild(LC, alokasiChild(DataMtr));
            break;
        case 3:
            cout << "ID peminjam:";
            cin >> x.ID;
            P = findElmParent(LP, x.ID);
            checkin(LR, info(P), y);
            connect(LR, LP, LC, x, y);
            break;
        case 4:
            printInfoParent(LP);
            break;
        case 5:
            printInfoChild(LC);
            break;
        case 6:
            if (first(LR) != NULL)
            {
                printInfoRelasi(LR);
            }
            else
            {
                cout << "kosong" << endl;
            }
            break;
        case 7:
            cout << "Masukkan ID peminjam:";
            cin >> x.ID;
            R = findElmRelasiByParent(LR, x.ID);
            while (R != NULL)
            {
                cout << info(parent(R)).namaPeminjam << endl;
                cout << info(parent(R)).ID << endl;
                cout << info(child(R)).NamaMotor << endl;
                cout << "Waktu checkin:" << endl;
                printDate(info(parent(R)).waktucheckIn);
                cout << "Waktu checkout:" << endl;
                printDate(info(parent(R)).waktucheckOut);
            }
            break;
        case 8:
            int Id;
            cout << "Masukkan ID peminjaman yang ingin dirubah datanya:";
            cin >> Id;
            R = findElmRelasiByParent(LR, Id);
            if (R == NULL)
            {
                cout << "Data tidak ditemukan" << endl;
            }
            else
            {
                inputDataPeminjam(LR, info(parent(R)));
            }
            break;
        case 9:
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
                cout << "Data Tidak ada..." << endl;
            }
            cout << endl;
            break;
        case 10:
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
                    cout << "Dengan menghapus data peminjam maka akan menghapus data peminjaman motor" << endl;
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
        case 11:
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
                    cout << "Dengan menghapus data motor maka akan menghapus data peminjaman motor" << endl;
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
