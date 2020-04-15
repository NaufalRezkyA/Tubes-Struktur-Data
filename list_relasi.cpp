#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_parent P, address_child C) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void dealokasi(address_relasi &P){
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfter(address_relasi &Prec, address_relasi P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLast(List_relasi &L, address_relasi P){
    address_relasi Q;
    Q = L.first;
    while (Q->next != NULL)
    {
        Q = Q->next;
    }
    Q->next = P;
}

void deleteFirst(List_relasi &L, address_relasi &P){
    if (L.first != NULL)
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(List_relasi &L, address_relasi &P){
    address_relasi Q;
    Q = L.first;
    if (Q->next == NULL)
    {
        deleteFirst(L, Q);
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

void deleteAfter(address_relasi Prec, address_relasi &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(parent(P)).ID<<"->"<<info(child(P))<<endl;
        cout<<info(parent(P)).IDmotor<<"->"<<info(child(P))<<endl;
        cout<<info(parent(P)).namaPeminjam<<"->"<<info(child(P))<<endl;
        cout<<info(parent(P)).nomorIdentitas<<"->"<<info(child(P))<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_parent P, address_child C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}


