#include "list_child.h"
int randomIntChild()
{
    int random = rand() % 90000 + 10000;
    return random;
}

void inputDataMotor(List_child L,infotype_child &x){
    gotoxy(55,7);cout << "Formulir Data Motor Baru ";
    gotoxy(40,9);cout<<"Nama Motor           : ";
    cin>>x.NamaMotor;
    gotoxy(40,10);cout<<"Tahun Motor          : ";
    cin>>x.tahunMotor;
    gotoxy(40,11);cout<<"Tipe (Matic/Manual)  : ";
    cin>>x.Tipe;
    gotoxy(40,12);cout<<"Harga Sewa motor     : ";
    cin>>x.Harga;

    bool mark = true;
    while(mark!=false){
        x.ID = randomIntChild();
        mark = checkDuplicateIDChild(L, x.ID);
    }
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

void insertAfterChild(List_child &L, address_child Prec, address_child P)
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
    P=first(L);
    if(next(first(L)!=P)){
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(prev(P));
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }

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
void deleteByIDChild(List_child &L, int ID){
    address_child P, R;
    P = L.first;
    if (L.first == NULL)
    {
        deleteFirstChild(L, R);
        dealokasiChild(R);
    }
    else
    {

        if (info(first(L)).ID == ID)
        {
            deleteFirstChild(L, R);
            dealokasiChild(R);
        }
        else if (info(prev(P)).ID == ID)
        {
            deleteLastChild(L, R);
            dealokasiChild(R);
        }
        else
        {
            do{
                P = P->next;
            }while (P != first(L) && info(prev(P)).ID != ID);
            P=prev(prev(P));
            deleteAfterChild(L, P, R);
            dealokasiChild(R);
        }
    }
}

int CountChild(List_child L){
    address_child P = first(L);
    int i=0;
    do
    {
        i++;
        P = next(P);
    } while (P != first(L));
    return i;
}

void printInfoChild(List_child L) {
    address_child P = first(L);
    int i,j;
    i = 9;
    j = 0;
    if(P!=NULL){
        do{
            if(i+6 >= 30){
                i = 9;
                j = 29;

            }
            gotoxy(45,7);cout<<"DAFTAR MOTOR";
            gotoxy(38+j,i);cout << "Nama Motor      : " << info(P).NamaMotor << endl;
            gotoxy(38+j,i+1);cout << "ID Motor        : " << info(P).ID << endl;
            gotoxy(38+j,i+2);cout << "Tahun Motor     : " << info(P).tahunMotor << endl;
            gotoxy(38+j,i+3);cout << "Tipe Motor      : " << info(P).Tipe << endl;
            gotoxy(38+j,i+4);cout << "Harga sewa(jam) : " << info(P).Harga << endl;
            cout<<endl;
            i=i+6;
            P = next(P);
        }while (P != first(L));
    }else{
        gotoxy(45,7);cout<<"Data motor Tidak Ada..."<<endl;
    }
}


address_child findElmChild(List_child L, int ID) {
    address_child P = first(L);
    do{
        if(info(P).ID==ID) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}

void insertAndsortChild(List_child &L, address_child R)
{
    if (L.first != NULL)
    {
        if (findElmChild(L, info(R).ID) == NULL)
        {
            if (info(R).ID < L.first->info.ID)
            {
                insertFirstChild(L, R);
            }
            else if (info(R).ID > info(prev(first(L))).ID)
            {
                insertLastChild(L, R);
            }
            else
            {
                address_child P;
                P = first(L);

                do{
                    P = P->next;
                }
                while (P != first(L) && R->info.ID > info(next(P)).ID);
                insertAfterChild(L, P, R);
            }
        }
        else
        {
            cout << "Peminjam telah meminjam motor..." << endl;
        }
    }
    else
    {
        insertFirstChild(L, R);
    }
}

bool checkDuplicateIDChild(List_child L, int ID){
    if (findElmChild(L, ID) == NULL)
    {
        return false;
    }
    return true;
}

void DataM(List_child &LC)
{
    infotype_child x;
    x.ID = 19231;
    x.NamaMotor = "BEAT F1";
    x.tahunMotor = 2012;
    x.Tipe = "Manual";
    x.Harga = 12000;
    insertAndsortChild(LC, alokasiChild(x));

    x.ID = 92132;
    x.NamaMotor = "BEAT A1";
    x.tahunMotor = 2010;
    x.Tipe = "Automatic";
    x.Harga = 10000;
    insertAndsortChild(LC, alokasiChild(x));

    x.ID = 12345;
    x.NamaMotor = "BEAT A0";
    x.tahunMotor = 2020;
    x.Tipe = "Manual";
    x.Harga = 11000;
    insertAndsortChild(LC, alokasiChild(x));
}

