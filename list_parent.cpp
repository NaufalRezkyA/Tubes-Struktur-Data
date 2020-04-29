/*Nama  : Naufal Rezky Ananda
  Nim   : 1301190478
  Nama  : Hassan Rizky Putra
  Nim   : 1301190328*/
#include "list_parent.h"
int randomIntParent(){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    int random = rand() % 90000 + 10000;
    return random;
}
void printDate(Date x,int i, int j){
    /*Nama  : Naufal Rezky Ananda
      Nim   : 1301190478
      Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    gotoxy(38+j,i);cout<<"Tanggal   : "<<x.tanggal<<"/"<<x.bulan<<"/"<<x.tahun<<endl;
    gotoxy(38+j,i+1);cout<<"Jam       : "<<x.jam<<":"<<x.menit<<endl;
    cout<<endl;
}
void createListParent(List_parent &L) {
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    first(L) = NULL;
    last(L)=NULL;
}
address_parent alokasiParent(infotype_parent x) {
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void dealokasiParent(address_parent &P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    delete P;
}
void insertFirstParent(List_parent &L, address_parent P) {
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    if (Prec == NULL)
    {
        insertFirstParent(L, P);
    }
    else
    {
        P->next = Prec->next;
        Prec->next = P;
    }
}
void insertLastParent(List_parent &L, address_parent P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    next(last(L)) = P;
    last(L) = P;
}
void deleteFirstParent(List_parent &L, address_parent &P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    P = first(L);
    if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLastParent(List_parent &L, address_parent &P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    P = last(L);
    address_parent Q = first(L);
    while (next(Q) != last(L))
    {
        Q = next(Q);
    }
    last(L) = Q;
    next(Q) = NULL;
}
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}
int CountParent(List_parent L){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    address_parent P = first(L);
    int i = 0;
    while (P != NULL)
    {
        i++;
        P = next(P);
    }
    return i;
}
void printInfoParent(List_parent L) {
    /*Nama  : Naufal Rezky Ananda
      Nim   : 1301190478
      Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    address_parent P = first(L);
    int i,j;
    i = 9;
    j = 0;
    if(first(L)!=NULL) {
        while (P != NULL)
        {
            if(i+6 >= 30){
                i = 9;
                j = 29;
            }
            gotoxy(55,7);cout<<"DATA DIRI PEMINJAM";
            gotoxy(38+j,i);cout<<"ID Peminjam: "<<info(P).ID<<endl;
            gotoxy(38+j,i+1);cout<<"Nama: "<<info(P).namaPeminjam<<endl;
            gotoxy(38+j,i+2);cout<<"No. Identitas: "<<info(P).nomorIdentitas<<endl;
            gotoxy(38+j,i+3);cout<<"Harga Sewa: "<<info(P).harga<<endl;
            if (info(P).waktucheckIn.tanggal<=31){
                gotoxy(38+j,i+4);cout << "Waktu Checkin: " << endl;
                printDate(info(P).waktucheckIn, i+5, j);
                gotoxy(38+j,i+7);cout<<"Waktu Checkout: "<<endl;
                printDate(info(P).waktucheckOut, i+8, j);
                gotoxy(38+j,i+10);cout<<"Waktu transaksi:"<<endl;
                printDate(info(P).waktuPeminjaman, i+11, j);
                i=i+14;
            }else {
                i= i +5;
            }
            cout<<endl;
            P = next(P);
        }
    }else{
         gotoxy(38+j,20);cout<<"Tidak ada data peminjaman"<<endl;
    }
}
address_parent findElmParent(List_parent L, int ID) {
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    address_parent P = first(L);
    while (P != NULL)
    {
        if(info(P).ID == ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
void deleteByIDparent(List_parent &L, int ID){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    address_parent P, R,Q;
    P = L.first;

    if (L.first == NULL)
    {
        deleteFirstParent(L, R);
        dealokasiParent(R);
    }
    else
    {
        if (P->info.ID == ID)
        {
            deleteFirstParent(L, R);
            dealokasiParent(R);
        }
        else if (info(last(L)).ID == ID)
        {
            deleteLastParent(L, R);
            dealokasiParent(R);
        }
        else
        {
            while (P != NULL && P->info.ID < ID)
            {
                Q = P;
                P = P->next;
            }
            deleteAfterParent(L, Q, R);
            dealokasiParent(R);
        }
    }
}
void insertAndsortParent(List_parent &L, address_parent R){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    if (L.first != NULL)
    {
        if (findElmParent(L,info(R).ID) == NULL)
        {
            if (info(R).ID < info(first(L)).ID)
            {
                insertFirstParent(L, R);
            }
            else if (info(R).ID > info(last(L)).ID)
            {
                insertLastParent(L, R);
            }
            else
            {
                address_parent P;
                P = first(L);
                while (P != NULL && R->info.ID > info(next(P)).ID)
                {
                    P = P->next;
                }
                insertAfterParent(L, P, R);
            }
        }
        else
        {
            gotoxy(55,20);cout << "peminjaman sudah terdaftar" << endl;
        }
    }
    else
    {
        insertFirstParent(L, R);
    }
}
bool checkDuplicateIDParent(List_parent L, int ID){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    if (findElmParent(L, ID) == NULL)
    {
        return false;
    }
    return true;
}
void SetColor(unsigned short color) {
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}
void gotoxy(int x, int y){
    /*Nama  : Hassan Rizky Putra
      Nim   : 1301190328*/
    COORD k = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
