/*Nama  : Naufal Rezky Ananda
  Nim   : 1301190478
  Nama  : Hassan Rizky Putra
  Nim   : 1301190328*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void bg();
void bg(){
    gotoxy(1,1);SetColor(17);cout << "                                                                                                      " << endl;
    gotoxy(1,2);SetColor(17);cout << "                                 ";SetColor(112);cout << "   Selamat Datang di Tel-U  Rent   ";SetColor(17);cout << "                                  " << endl;
    gotoxy(1,3);SetColor(17);cout << "                                 ";SetColor(112);cout << "    Jasa Penyewaan Sepeda Motor    ";SetColor(17);cout << "                                  " << endl;
    gotoxy(1,4);SetColor(17);cout << "                                 ";SetColor(112);cout << " Kawasan Sekitar Telkom University ";SetColor(17);cout << "                                  " << endl;
    gotoxy(1,5);SetColor(17);cout << "                                                                                                      " << endl;
    gotoxy(1,6);SetColor(17);cout << " ";SetColor(119);cout << "                                   ";gotoxy(36,6);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,7);SetColor(17);cout << " ";SetColor(119);cout << "                                   ";gotoxy(36,7);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,8);SetColor(17);cout << " ";SetColor(119);cout << "                                   ";gotoxy(36,8);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,9);SetColor(17);cout << " ";SetColor(119);cout << "                                   ";gotoxy(36,9);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,10);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,10);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,11);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,11);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,12);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,12);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,13);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,13);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,14);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,14);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,15);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,15);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,16);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,16);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,17);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,17);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,18);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,18);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,19);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,19);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,20);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,20);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,21);SetColor(17);cout << " ";SetColor(119);cout << "                                  ";gotoxy(36,21);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,22);SetColor(17);cout << " ";SetColor(17);cout << "                                  ";gotoxy(36,22);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,23);SetColor(17);cout << "        ";SetColor(119);cout << "                   ";gotoxy(28,23);SetColor(17);cout << "         ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,24);SetColor(17);cout << " ";SetColor(17);cout << "                                  ";gotoxy(36,24);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,25);SetColor(17);cout << " ";SetColor(112);cout << "                                  ";gotoxy(36,25);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,26);SetColor(17);cout << " ";SetColor(112);cout << "        Telkom University         ";gotoxy(36,26);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,27);SetColor(17);cout << " ";SetColor(112);cout << "             Bandung              ";gotoxy(36,27);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,28);SetColor(17);cout << " ";SetColor(112);cout << " Author by:                       ";gotoxy(36,28);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,29);SetColor(17);cout << " ";SetColor(112);cout << "    > Hassan Rizky P (1301190328) ";gotoxy(36,29);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,30);SetColor(17);cout << " ";SetColor(112);cout << "    > Naufal Rezky A (1301190478) ";gotoxy(36,30);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,31);SetColor(17);cout << " ";SetColor(112);cout << "             IF-43-05             ";gotoxy(36,31);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,32);SetColor(17);cout << " ";SetColor(112);cout << "            INFORMATIKA           ";gotoxy(36,32);SetColor(17);cout << " ";SetColor(119);cout << "                                                                 ";SetColor(17);cout << " " << endl;
    gotoxy(1,33);SetColor(17);cout << "                                                                                                      " << endl;
}

void mainMenu();
void currentTime();

void currentTime(){
    time_t now = time(0);
    char *dt = ctime(&now);
    gotoxy(3,3);cout << "The local date and time is: ";
    gotoxy(5,4);cout << dt <<endl;
}
void mainMenu(){
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
    int i,j;
    i = 7;
    infotype_parent x;
    infotype_child y;
    do
    {
        bg();
        SetColor(112);
        currentTime();
        gotoxy(3,6);cout << "Menu Peminjaman Motor" << endl;
        gotoxy(4,7);cout << "1. Masukkan Data Member" << endl;
        gotoxy(4,8);cout << "2. Menampilkan Biodata Peminjam" << endl;
        gotoxy(4,9);cout << "3. Masukkan Data Motor"<<endl;
        gotoxy(4,10);cout << "4. Menampilkan Data Motor" << endl;
        gotoxy(4,11);cout << "5. Penyewaan Motor" << endl;
        gotoxy(4,12);cout << "6. Cek Penyewaan Motor" << endl;
        gotoxy(4,13);cout << "7. Menghapus Data Penyewaan" << endl;
        gotoxy(4,14);cout << "8. Menampilkan Data Penyewaan" << endl;
        gotoxy(4,15);cout << "9. Menampilkan Motor yang disewa" << endl;
        gotoxy(4,16);cout << "10. Menghapus Data Motor" << endl;
        gotoxy(4,17);cout << "11. Menghapus Data Member" << endl;
        gotoxy(4,18);cout << "12. 3 Data Transaksi Terbaru" << endl;
        gotoxy(4,19);cout << "13. Reset Semua Data" << endl;
        gotoxy(4,20);cout << "14. Total Pendapatan" << endl;
        gotoxy(4,21);cout << "00. QUIT"<< endl;
        gotoxy(10,23);cout << "Masukan angka:";
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
            gotoxy(55,7); cout << "Proses Peminjaman Motor";
            gotoxy(38,9); cout << "ID peminjam:";
            cin >> x.ID;
            P = findElmParent(LP, x.ID);
            if(P!=NULL){
                checkin(LR,LC, info(P), y);
                connect(LR, LP, LC, x, y);
            }else{
                gotoxy(54, 15);
                cout << "Data tidak tidak ada..." << endl;
            }
            break;
        case 6:
            gotoxy(38,7);cout<<"Masukkan ID peminjam: ";
            cin>>x.ID;
            gotoxy(38,8);cout<<"Masukkan ID motor: ";
            cin>>y.ID;
            P = findElmParent(LP, x.ID);
            Q = findElmChild(LC, y.ID);
            if(P!=NULL & Q!=NULL){
                R = findElmRelasiByParent(LR, info(P).ID);
                S = findElmRelasiByChild(LR, info(Q).ID);
                if(R!=NULL & S!=NULL){
                    gotoxy(38,10);cout<<"Data telah terhubung"<<endl;
                } else{
                    gotoxy(38,10);cout<<"Data belum terhubung"<<endl;
                }
            }else{
                gotoxy(38,10);cout<<"Data yang anda cari tidak ada..."<<endl;
            }
            break;
        case 7:
            gotoxy(38,7);cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            P = findElmParent(LP, id);
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    disconnected(LR, info(P).ID);
                    gotoxy(38,9);cout << "Penghapusan Data berhasil...";
                }
            }
            else
            {
                gotoxy(38,9);cout << "Data Tidak ada..." << endl;
            }
            break;
        case 8:
            printInfoRelasi(LR);
            break;

        case 9:
            gotoxy(38,7);cout << "Masukkan ID peminjam:";
            cin >> x.ID;
            i= 9;
            j = 0;
            bool found;
            found = false;
            R = first(LR);
            if(R!=NULL){
                while (R != NULL)
                {
                    if(i+6 >= 30){
                        i = 9;
                        j = 29;
                    }
                    if(info(parent(R)).ID == x.ID){
                        gotoxy(38,i);cout << "Nama Peminjam       : "<<info(parent(R)).namaPeminjam << endl;
                        gotoxy(38,i+1);cout << "ID Peminjam         : "<<info(parent(R)).ID << endl;
                        gotoxy(38,i+2);cout << "Motor yang dipinjam : "<<info(child(R)).NamaMotor << endl;
                        gotoxy(38,i+3);cout << "Waktu checkin:" << endl;
                        printDate(info(parent(R)).waktucheckIn, i+4, j);
                        gotoxy(38,i+6);cout << "Waktu checkout:" << endl;
                        printDate(info(parent(R)).waktucheckOut, i+7, j);
                        found = true;
                    }
                    R=next(R);
                    i= i +10;
                }
            }if(found == false) {
                gotoxy(55,15);cout << "ID peminjam tidak ditemukan";
            }
            break;
        case 10:
            gotoxy(38,7);cout << "Masukkan ID motor yang ingin di hapus : ";
            cin >> id;
            j = 0;
            Q = findElmChild(LC, id);
            if (Q != NULL)
            {
                R = findElmRelasiByChild(LR, info(Q).ID);
                if (R != NULL)
                {
                    gotoxy(38,8);cout << "ID akan menggunakan Motor pada :" << endl;
                    printDate(info(parent(R)).waktucheckIn, 9, j);
                    gotoxy(38,11);cout << "Dengan menghapus data motor maka akan menghapus data peminjaman" << endl;
                    gotoxy(38,12);cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(parent(R)).ID);
                        deleteByIDChild(LC, id);
                        gotoxy(38,14);cout << "Penghapusan Data Berhasil..." << endl;
                    }else {
                        gotoxy(38,14);cout << "Data Batal Dihapus..." << endl;
                    }
                }else {
                    deleteByIDChild(LC, id);
                    gotoxy(38,9);cout << "Penghapusan Data Berhasil..." << endl;
                }
            }
            else
            {
                gotoxy(55,15);cout << "Data Tidak ada.." << endl;
            }
            break;
        case 11:
            gotoxy(38,7);cout << "Masukkan ID member yang ingin di hapus: ";
            cin >> id;
            j = 0;
            P = findElmParent(LP, id);
            if (P != NULL)
            {
                R = findElmRelasiByParent(LR, info(P).ID);
                if (R != NULL)
                {
                    gotoxy(38,8);cout << "ID akan menggunakan Motor pada:" << endl;
                    printDate(info(P).waktucheckIn, 9, j);
                    gotoxy(38,11);cout << "Dengan menghapus data peminjam maka akan menghapus data peminjaman motor" << endl;
                    gotoxy(38,12);cout << "Apakah anda ingin menghapusnya(Y/N)?";
                    char penentuDelete;
                    cin >> penentuDelete;
                    if (penentuDelete == 'Y')
                    {
                        disconnected(LR, info(P).ID);
                        deleteByIDparent(LP, id);
                        gotoxy(38,14);cout << "Penghapusan Data Berhasil..." << endl;
                    }else {
                        gotoxy(38,14);cout << "Data Batal Dihapus..." << endl;
                    }
                }else {
                    deleteByIDparent(LP, id);
                    gotoxy(38,9);cout << "Penghapusan Data Berhasil..." << endl;
                }
            }
            else
            {
                gotoxy(55,15);cout << "Data Tidak ada.." << endl;
            }
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
            gotoxy(54,15);cout<<"Reset Data Berhasil..."<<endl;
            break;
        case 14:
            gotoxy(38,7);cout << "Total Pendapatan Tel-U Rent : Rp.";
            cout << totalIncome(LR)<<endl;
            break;
        }
        gotoxy(54,32);system("pause");
        if (choice == 00)
        {
            break;
        }
    } while (true);

}

int main(){
    mainMenu();

    return 0;
}
