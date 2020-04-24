#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
    address_relasi last;
};


void createListRelasi(List_relasi &L);
void insertFirstRelasi(List_relasi &L, address_relasi P);
void insertLastRelasi(List_relasi &L, address_relasi P);
void insertAfterRelasi(address_relasi Prec, address_relasi P);
void deleteFirstRelasi(List_relasi &L, address_relasi &P);
void deleteLastRelasi(List_relasi &L, address_relasi &P);
void deleteAfterRelasi(address_relasi Prec, address_relasi &P);

void disconnected(List_relasi L, int ID);
address_relasi alokasiRelasi( address_parent P, address_child C);
void dealokasiRelasi(address_relasi &P);
address_relasi findElmRelasiByParent(List_relasi L, int ID);
address_relasi findElmRelasiByChild(List_relasi L,  string ID);
void printInfoRelasi(List_relasi L);
void printInfoTerbaru(List_relasi L);

void insertAndsort(List_relasi L, address_relasi x);
void MotorYangTersedia(List_relasi LR, List_child LC);
void CheckInputanCheckin(List_relasi LR, DataPeminjam datapeminjam);
void dataIdentitas(infotype_parent &x);
void inputDataPeminjam(List_relasi LR, infotype_parent &x);
#endif // LIST_RELASI_H_INCLUDED
