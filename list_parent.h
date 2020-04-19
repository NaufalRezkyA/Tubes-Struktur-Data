#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <ctime>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct Date{
    int tanggal;
    int bulan;
    int tahun;
    int jam;
    int menit;
};

struct DataPeminjam
{
    int ID, IDmotor;
    int nomorIdentitas, durasiPeminjaman;
    string namaPeminjam;
    Date waktuPeminjaman;
    Date waktucheckIn;
    Date waktucheckOut;
};

typedef DataPeminjam infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
};


void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
void PrintDate(Date x);

void inputDataPeminjam(infotype_parent &x);

int randomInt(int ID);
address_parent alokasiParent(infotype_parent x);
void dealokasiParent(address_parent &P);
address_parent findElmParent(List_parent L, infotype_parent x);
void printInfoParent(List_parent L);

#endif // LIST_PARENT_H_INCLUDED
