#include "list_parent.h"

int randomInt(int ID)
{
    int random = rand() % ID;
    return random;
}

void printDate(Date x){
    cout<<x.tanggal<<"/"<<x.bulan<<"/"<<x.tahun<<endl;
    cout<<x.jam<<":"<<x.menit<<endl;
}

void createListParent(List_parent &L) {
    first(L) = NULL;
    last(L)=NULL;
}

address_parent alokasiParent(infotype_parent x) {
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasiParent(address_parent &P){
    delete P;
}

void insertFirstParent(List_parent &L, address_parent P) {
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
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLastParent(List_parent &L, address_parent P){
    next(last(L)) = P;
    last(L) = P;
}

void deleteFirstParent(List_parent &L, address_parent &P){
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
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

int CountParent(List_parent L)
{
    address_parent P = first(L);
    int i = 0;
    if (P != NULL )
    {
        while (P != NULL)
        {
            i++;
            P = next(P);
        }
    }
    return i;
}

void printInfoParent(List_parent L) {
    address_parent P = first(L);
    if(first(L)!=NULL) {
        while (P != NULL)
        {
            cout<<info(P).ID<<endl;
            cout<<info(P).namaPeminjam<<endl;
            cout<<info(P).nomorIdentitas<<endl;
            cout<<info(P).harga<<endl;
            printDate(info(P).waktucheckIn);
            printDate(info(P).waktucheckOut);
            printDate(info(P).waktuPeminjaman);
            P = next(P);
        }
    }else{
        cout<<"Tidak ada data peminjaman"<<endl;
    }
}

address_parent findElmParent(List_parent L, int ID) {
    
    address_parent P = first(L);
    while (P != NULL)
    {
        if(info(P).ID == ID) {
            return P;
        }
        P = next(P);
    }
    cout<<"masuk";
    return NULL;
}

void deleteByIDparent(List_parent &L, int ID){
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

void insertAndsortParent(List_parent &L, address_parent P){
    if (first(L) == NULL || info(P).ID <= info(first(L)).ID)
    {
        insertFirstParent(L, P);
    }
    else if (info(P).ID > info(last(L)).ID)
    {
        insertLastParent(L, P);
    }
    else
    {
        address_parent Q = first(L);
        while (info(next(Q)).ID < info(P).ID)
        {
            Q = next(Q);
        }
        insertAfterParent(L, Q, P);
    }
}


