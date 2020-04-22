#include "list_relasi.h"

void createListRelasi(List_relasi &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_relasi alokasiRelasi(address_parent P, address_child C) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

void dealokasiRelasi(address_relasi &P){
    delete P;
}

void insertFirstRelasi(List_relasi &L, address_relasi P) {
    if (L.first != NULL)
    {
        P->next = L.first;
        prev(L.first) = P;
        L.first = P;
    }
    else
    {
        L.first = P;
        L.last = P;
    }
}

void insertAfterRelasi(address_relasi Prec, address_relasi P)
{
    P->next = Prec->next;
    P->prev = Prec;
    prev(next(Prec)) = P;
    Prec->next = P;
}

void insertLastRelasi(List_relasi &L, address_relasi P){
    if (L.first != NULL)
    {
        P->prev = L.last;
        next(L.last) = P;
        L.last = P;
    }
    else
    {
        L.last = P;
        L.first = P;
    }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &P){
    if (L.first->next == NULL)
    {
        cout<<"delete";
        P = L.first;
        parent(P) = NULL;
        child(P) = NULL;
        P = NULL;
        L.last = NULL;
        
    }
    else
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
        L.first->prev = NULL;
    }
}

void deleteLastRelasi(List_relasi &L, address_relasi &P){
    P = L.last;
    if (L.last != first(L))
    {
        L.last = prev(P);
        prev(P) = NULL;
        next(L.last) = NULL;
    }
    else
    {
        L.first = NULL;
        L.last = NULL;
    }
}

void deleteAfterRelasi(address_relasi Prec, address_relasi &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
    if (parent(P)==NULL || child(P)==NULL){
        cout<<"Kosong"<<endl;
    }else{
        cout<<"list";
        while(P !=NULL) {
            cout<<info(parent(P)).namaPeminjam<<endl;
            cout<<info(parent(P)).ID<<endl;
            cout<<info(parent(P)).durasiPeminjaman<<endl;
            cout<<info(child(P)).ID<<endl;
            P = next(P);
        }
    }
}

void printInfoTerbaru(List_relasi L){
    address_relasi P = last(L);
    int i = 0;
    while (P != NULL && i<=3)
    {
        cout << info(parent(P)).namaPeminjam;
        cout << info(parent(P)).durasiPeminjaman;
        cout << info(child(P)).ID;
        P = prev(P);
        i++;
    }
}

void penentuWaktu();

void insertAndsort(List_relasi L, address_relasi x){
    address_relasi P, Q;
    P = L.first;

    if (P == NULL || info(parent(P)).waktucheckOut.tahun >=
        info(parent(x)).waktucheckOut.tahun)
    {
        insertFirstRelasi(L, x);
    }
    else if (info(parent(last(L))).waktucheckOut.tahun <=
        info(parent(x)).waktucheckOut.tahun)
    {
        insertLastRelasi(L, x);
    }
    else
    {
        while (P != NULL && info(parent(P)).waktucheckOut.tahun <
            info(parent(x)).waktucheckOut.tahun)
        {
            P = P->next;
        }
        P = prev(P);
        insertAfterRelasi(P, x);
    }
}

address_relasi findElmRelasiByParent(List_relasi L, address_parent P) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_relasi findElmRelasiByChild(List_relasi L,address_child C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void disconnected(List_relasi L, int ID)
{
    address_relasi P, R;
    P = L.first;

    if (L.first == NULL)
    {
        cout<<"masuk";
        deleteFirstRelasi(L, R);
        dealokasiRelasi(R);
    }
    else
    {
        
        if (info(parent(P)).ID == ID)
        {
            cout<<"masuk2";
            deleteFirstRelasi(L, R);
            dealokasiRelasi(R);
        }
        else if (info(parent(last(L))).ID == ID)
        {
            deleteLastRelasi(L, R);
            dealokasiRelasi(R);
        }
        else
        {
            while (P != NULL && info(parent(P)).ID != ID)
            {
                P = P->next;
            }
            P = prev(P);
            deleteAfterRelasi(P, R);
            dealokasiRelasi(R);
        }
    }
}
