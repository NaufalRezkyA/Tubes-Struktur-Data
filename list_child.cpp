#include "list_child.h"

void inputDataMotor(infotype_child &x){
    cout<<"Nama Motor: ";
    cin>>x.NamaMotor;
    cout<<"Tahun Motor: ";
    cin>>x.tahunMotor;
    cout<<"ID: ";
    cin>>x.ID;
}

void DataM(List_child &LC){
    infotype_child x;
    x.ID = "BT20";
    x.NamaMotor = "BEAT F1";
    x.tahunMotor = 2020;
    insertLastChild(LC, alokasiChild(x));
    x.ID = "BT12";
    x.NamaMotor = "BEAT A1";
    x.tahunMotor = 2012;
    insertLastChild(LC, alokasiChild(x));
    x.ID = "BT10";
    x.NamaMotor = "BEAT A0";
    x.tahunMotor = 2010;
    insertLastChild(LC, alokasiChild(x));
}

void createListChild(List_child &L) {
    first(L) = NULL;
}

address_child alokasiChild(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasiChild(address_child &P){
    delete P;
}

void insertFirstChild(List_child &L, address_child P) {
    if (first(L) != NULL)
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
    else
    {
        first(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;
    }
}

void insertLastChild(List_child &L, address_child P){
    if (first(L) != NULL)
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
    else
    {
        first(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;
    }
}

void insertAfterChild(List_child &L, address_child &Prec, address_child P)
{
    if (first(L) == NULL)
    {
        insertFirstChild(L, P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirstChild(List_child &L, address_child &P){
    P = first(L);
    if (next(first(L)) != P)
    {
        first(L) = next(P);
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
}

void deleteLastChild(List_child &L, address_child &P){
    P = prev(first(L));
    next(prev(P)) = first(L);
    prev(first(L)) = prev(prev(P));
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteAfterChild(List_child &L, address_child Prec, address_child &P){
    P = next(Prec);
    if (next(Prec) != first(L))
    {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        next(P) = NULL;
        prev(P) = NULL;
        P = NULL;
    }
}
void deleteByID(List_child &L, int ID){
    address_child P,R;
    P = L.first;

    if (L.first == NULL){
        deleteFirstChild(L,R);
        dealokasiChild(R);
    }else{
        if(P->info.ID == id_x){
            deleteFirstChild(L, R);
            dealokasiChild(R);
        }else{
            while(P != NULL && P->info.ID != ID){
                P = P->next;
            }
            P = P->prev;
            deleteAfterChild(L,P,R);
            dealokasiChild(R);
        }
    }
}
void printInfoChild(List_child L) {
    address_child P = first(L);
    do{
        cout<<"->"<<info(P).ID<<endl;
        cout<<"->"<<info(P).NamaMotor<<endl;
        cout<<"->"<<info(P).tahunMotor<<endl;
        P = next(P);
    }while (P != first(L));
}


address_child findElmChild(List_child L, string x) {
    address_child P = first(L);
    do{
        if(info(P).ID==x) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}

void DataM()
{
    List_child LC;
    infotype_child x;
    x.ID = "BT20";
    x.NamaMotor = "BEAT F1";
    x.tahunMotor = 2020;
    insertLastChild(LC, alokasiChild(x));
    x.ID = "BT12";
    x.NamaMotor = "BEAT A1";
    x.tahunMotor = 2012;
    insertLastChild(LC, alokasiChild(x));
    x.ID = "BT10";
    x.NamaMotor = "BEAT A0";
    x.tahunMotor = 2010;
    insertLastChild(LC, alokasiChild(x));
}
