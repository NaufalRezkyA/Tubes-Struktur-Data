#include "list_parent.h"

int randomInt(int ID)
{
    int random = rand() % ID;
    return random;
}

void printDate(Date x){
    cout<<x.tanggal<<":"<<x.bulan<<":"<<x.tahun<<endl;
    cout<<x.jam<<":"<<x.menit<<endl;
}

void inputDataPeminjam(infotype_parent &x)
{
    cout<<"Masukkan Nomor identitas anda: ";
    x.nomorIdentitas=1301190478;
    cout<<endl;
    x.ID = randomInt(x.nomorIdentitas);

    cout<<"Masukkan Nama: ";
    x.namaPeminjam = "Naufal";
    cout<<endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    x.waktuPeminjaman.tanggal= ltm->tm_mday;
    x.waktuPeminjaman.bulan= 1+ltm->tm_mon;
    x.waktuPeminjaman.tahun= 1900+ltm->tm_year;
    x.waktuPeminjaman.jam = ltm->tm_hour;
    x.waktuPeminjaman.menit = 1 + ltm->tm_min;

    string waktu;
    cout<<"durasi peminjaman(jam/hari):"<<endl;
    x.durasiPeminjaman = 8; 
    waktu = "hari";
    if (waktu == "hari"){
        x.durasiPeminjaman= x.durasiPeminjaman*24;
    }
    cout<<x.durasiPeminjaman<<endl;
    printDate(x.waktuPeminjaman);

    int harga;
    x.harga = x.durasiPeminjaman * 10000;
    cout<<"Harga: "<<x.harga<<endl;

    cout<<"masukan id motor yang akan dipinjam:"<<endl;
    x.IDMotor="BT20";

    cout<<"waktu checin:"<<endl;
    cin >> x.waktucheckIn.tanggal >> x.waktucheckIn.bulan
        >> x.waktucheckIn.tahun >> x.waktucheckIn.jam
        >> x.waktucheckIn.menit;
    printDate(x.waktucheckIn);

    cout<<"waktu checkout"<<endl;
    x.waktucheckOut.tanggal = x.waktucheckIn.tanggal;
    x.waktucheckOut.bulan = x.waktucheckIn.bulan;
    x.waktucheckOut.tahun = x.waktucheckIn.tahun;
    x.waktucheckOut.jam= x.waktucheckIn.jam+x.durasiPeminjaman;
    if (x.waktucheckOut.jam>=24){
        int hari = x.waktucheckOut.jam / 24;
        x.waktucheckOut.tanggal = x.waktucheckIn.tanggal+hari;
        x.waktucheckOut.jam = x.waktucheckOut.jam-(24*hari);
        if (x.waktucheckOut.tanggal>31){
            int bulan = x.waktucheckOut.tanggal / 31;
            x.waktucheckOut.bulan = x.waktucheckIn.bulan+bulan;
            x.waktucheckOut.tanggal=x.waktucheckOut.tanggal-(31*bulan);
            if (x.waktucheckOut.bulan>12){
                int tahun = x.waktucheckOut.bulan/12;
                x.waktucheckOut.bulan = x.waktucheckOut.bulan-(tahun*12);
                x.waktucheckOut.tahun = x.waktucheckIn.tahun+tahun;
            }
        }
    }
    x.waktucheckOut.menit= x.waktucheckIn.menit;
    printDate(x.waktucheckOut);
}

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

void printInfoParent(List_parent L) {

    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P).ID<<endl;
            cout<<info(P).namaPeminjam<<endl;
            cout<<info(P).nomorIdentitas<<endl;
            cout<<info(P).harga<<endl;
            printDate(info(P).waktucheckIn);
            printDate(info(P).waktucheckOut);
            printDate(info(P).waktuPeminjaman);
            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent findElmParent(List_parent L, infotype_parent x) {

    address_parent P = first(L);
    do {
        if(info(P).ID == x.ID) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void deleteByIDparent(List_parent &L, int ID){
    address_parent P, R;
    P = L.first;

    address_parent Q,last;
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
            while (P != NULL && inf != X)
            {
                P = P->next;
            }
            P = prev(P);
            deleteAfterParent(L, P, R);
            dealokasiParent(R);
        }
    }
}   
