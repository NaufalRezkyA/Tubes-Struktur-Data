#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info

struct Date{
    int tanggal,bulan,tahun,jam,menit;
};

struct DataPeminjam
{
    int ID, harga,nomorIdentitas, durasiPeminjaman;
    string namaPeminjam, IDMotor;
    Date waktuPeminjaman;
    Date waktucheckIn,waktucheckOut;
};

typedef DataPeminjam infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
void printDate(Date x);

int CountParent(List_parent L);
void deleteByIDparent(List_parent &L, int ID);

int randomInt(int ID);
address_parent alokasiParent(infotype_parent x);
void dealokasiParent(address_parent &P);
address_parent findElmParent(List_parent L, int ID);
void printInfoParent(List_parent L);

void insertAndsortParent(List_parent &L, address_parent R);

#endif // LIST_PARENT_H_INCLUDED
