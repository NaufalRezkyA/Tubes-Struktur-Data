#include "list_parent.h"

int randomInt(int ID)
{
    int random = rand() % ID;
    return random;
}

<<<<<<< Updated upstream
void printDate(Date x){
    cout<<x.tanggal<<"/"<<x.bulan<<"/"<<x.tahun<<endl;
    cout<<x.jam<<":"<<x.menit<<endl;
}

=======
>>>>>>> Stashed changes
void createListParent(List_parent &L) {
    first(L) = NULL;
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

    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfterParent(List_parent &L, address_parent Prec, address_parent P){
    if (first(L) == NULL)
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
    address_parent Q;
    Q = L.first;
    if(first(L)==NULL){
        first(L) = P;
    }else{
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
        
    }
}

void deleteFirstParent(List_parent &L, address_parent &P){
    if (L.first != NULL)
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastParent(List_parent &L, address_parent &P){
    address_parent Q;
    Q = L.first;
    if (Q->next == NULL)
    {
        deleteFirstParent(L, Q);
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

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
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
        while ((P) != first(L))
        {
<<<<<<< Updated upstream
            cout<<info(P).ID<<endl;
            cout<<info(P).namaPeminjam<<endl;
            cout<<info(P).nomorIdentitas<<endl;
            cout<<info(P).harga<<endl;
            printDate(info(P).waktucheckIn);
            printDate(info(P).waktucheckOut);
            printDate(info(P).waktuPeminjaman);
=======
            cout<<"ID Peminjam: "<<info(P).ID<<endl;
            cout<<"Nama: "<<info(P).namaPeminjam<<endl;
            cout<<"No. Identitas: "<<info(P).nomorIdentitas<<endl;
            cout<<"ID Motor: "<<info(P).IDMotor<<endl;
            cout<<"Harga Sewa: "<<info(P).harga<<endl;
            cout<<endl;
>>>>>>> Stashed changes
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
    return NULL;
}

address_parent findElmParentbyIdentitas(List_parent L, string ID) {
    address_parent P = first(L);
    while (P != NULL)
    {
        if(info(P).nomorIdentitas == ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteByIDparent(List_parent &L, int ID){
    address_parent P, R;
    P = L.first;

    address_parent Q,last;
    Q = first(L);
    while (Q->next != NULL)
    {
        Q = Q->next;
    }
    last = Q;

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
        else if (info(last).ID == ID)
        {
            deleteLastParent(L, R);
            dealokasiParent(R);
        }
        else
        {
            while (P != NULL && P->info.ID != ID)
            {
                P = P->next;
            }
            P = prev(P);
            deleteAfterParent(L, P, R);
            dealokasiParent(R);
        }
    }
}

void insertAndsortParent(List_parent L, address_parent x){
    address_parent P, Q;
    P = L.first;

    address_parent R, last;
    R = first(L);
    while (R->next != NULL)
    {
        R = R->next;
    }
    last = R;

    if (P == NULL || P->info.ID >= info(x).ID)
    {
        insertFirstParent(L, x);
    }
    else if (info(R).ID <= info(x).ID)
    {
        insertLastParent(L, x);
    }
    else
    {
        while (P != NULL && P->info.ID < info(x).ID)
        {
            P = P->next;
        }
        P = prev(P);
        insertAfterParent(L, P, x);
    }
}


