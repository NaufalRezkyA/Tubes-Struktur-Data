#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_child &P){
    delete P;
}

void insertFirst(List_child &L, address_child P) {
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

void insertLast(List_child &L, address_child P){
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

void insertAfter(List_child &L, address_child &Prec, address_child P)
{
    if (first(L) == NULL)
    {
        insertFirst(L, P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirst(List_child &L, address_child &P){
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

void deleteLast(List_child &L, address_child &P){
    P = prev(first(L));
    next(prev(P)) = first(L);
    prev(first(L)) = prev(prev(P));
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteAfter(List_child &L, address_child Prec, address_child &P){
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

void printInfo(List_child L) {
    address_child P = first(L);
    do{
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }while (P != first(L));
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    do{
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}


