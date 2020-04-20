#include "list_relasi.h"

void createListRelasi(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasiRelasi(address_parent P, address_child C) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void dealokasiRelasi(address_relasi &P){
    delete P;
}

void insertFirstRelasi(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfterRelasi(address_relasi &Prec, address_relasi P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLastRelasi(List_relasi &L, address_relasi P){
    address_relasi Q;
    Q = L.first;
    while (Q->next != NULL)
    {
        Q = Q->next;
    }
    Q->next = P;
}

void deleteFirstRelasi(List_relasi &L, address_relasi &P){
    if (L.first != NULL)
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastRelasi(List_relasi &L, address_relasi &P){
    address_relasi Q;
    Q = L.first;
    if (Q->next == NULL)
    {
        deleteFirstRelasi(L, Q);
    }
    else
    {
        while ((Q->next)->next != NULL)
        {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfterRelasi(address_relasi Prec, address_relasi &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(parent(P)).namaPeminjam;
        cout<<info(parent(P)).durasiPeminjaman;
        cout<<info(child(P)).ID;
        P = next(P);
    }
}


address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}


