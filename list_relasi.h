#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED


#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

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
void insertLastRelasi(List_relasi &L, address_relasi P);
void deleteFirstRelasi(List_relasi &L, address_relasi &P);
void deleteLastRelasi(List_relasi &L, address_relasi &P);
void deleteAfterRelasi(List_relasi &L, address_relasi Prec, address_relasi &P);

void connect(List_relasi &LR, List_parent LP, List_child LC, infotype_parent Datapeminjam, infotype_child datachild);
void disconnected(List_relasi &L, int ID);
address_relasi alokasiRelasi( address_parent P, address_child C);
void dealokasiRelasi(address_relasi &P);
address_relasi findElmRelasiByParent(List_relasi L, int ID);
address_relasi findElmRelasiByChild(List_relasi L,  int ID);
int CountRelasi(List_relasi L);
void printInfoRelasi(List_relasi L);
void printInfoTerbaru(List_relasi L);

void checkin(List_relasi LR, infotype_parent &x, infotype_child &y);
void insertAndsort(List_relasi L, address_relasi x);
void CheckInputanCheckin(List_relasi LR, DataPeminjam datapeminjam, bool &mark);
void dataIdentitas(List_parent L,infotype_parent &x);
void inputDataPeminjam(List_relasi LR, infotype_parent &x);

#endif // LIST_RELASI_H_INCLUDED
