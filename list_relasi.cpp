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
    if (L.first != L.last)
    {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
    else
    {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}

void deleteLastRelasi(List_relasi &L, address_relasi &P){
    address_relasi Q = L.first;
    while (Q->next->next != NULL)
    {
        Q = Q->next;
    }
    P = Q->next;
    Q->next = NULL;
}

void deleteAfterRelasi(address_relasi Prec, address_relasi &P){
    P->next = Prec->next;
    Prec->next = P->next;
}

int CountRelasi(List_relasi L){
    address_relasi P = first(L);
    int i = 0;
    if(parent(P)!=NULL || child(P)!=NULL){
        while(P!=NULL){
            i++;
            P=next(P);
        }
    }
    return i;
}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
    if (P==NULL || parent(P)==NULL || child(P)==NULL){
        cout<<"Kosong"<<endl;
    }else{
        cout<<"list";
        while(P !=NULL) {
            cout<<info(parent(P)).namaPeminjam<<endl;
            cout<<info(parent(P)).ID<<endl;
            cout<<info(parent(P)).durasiPeminjaman<<endl;
            cout<<info(child(P)).NamaMotor<<endl;
            P = next(P);
        }
    }
}

void printInfoTerbaru(List_relasi L){
    address_relasi P = last(L);
    int i = 0;
    if(P!=NULL){
        while (P != NULL || i<=3)
        {
            cout << info(parent(P)).namaPeminjam;
            cout << info(parent(P)).durasiPeminjaman;
            cout << info(child(P)).ID;
            P = prev(P);
            i++;
        }
    }else{
        cout<<"Tidak ada data peminjaman motor"<<endl;
    }
}

address_relasi findElmRelasiByParent(List_relasi L, int ID) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(info(parent(Q)).ID==ID) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_relasi findElmRelasiByChild(List_relasi L,int ID) {
    address_relasi Q = first(L);
    cout<<"findelm";
    while(Q != NULL) {
        cout<<"masuk";
        if(info(child(Q)).ID == ID) {
            cout<<"masuk1";
            return Q;
        }
        Q = next(Q);
    }
    cout<<"child";
    return NULL;
}

void MotorYangTersedia(List_relasi LR, List_child LC){
    address_child R = first(LC);
    do
    {
        if (findElmRelasiByChild(LR, info(R).ID) == NULL)
        {
            cout << "->" << info(R).NamaMotor << endl;
        }
        R = next(R);
    } while (R != first(LC));
}

void CheckInputanCheckin(List_relasi LR, DataPeminjam datapeminjam, bool &mark){
    cout<<"error";
    address_relasi P = findElmRelasiByChild(LR, datapeminjam.IDMotor);
    mark = false;
    cout<<"inputancheckin";
    if(P!=NULL){
        cout<<"temu";
        if (info(parent(P)).waktucheckIn.tahun <= datapeminjam.waktucheckIn.tahun &&
            datapeminjam.waktucheckIn.tahun <= info(parent(P)).waktucheckOut.tahun &&
            info(parent(P)).waktucheckIn.bulan <= datapeminjam.waktucheckIn.bulan &&
            datapeminjam.waktucheckIn.bulan <= info(parent(P)).waktucheckOut.bulan &&
            info(parent(P)).waktucheckIn.tanggal <= datapeminjam.waktucheckIn.tanggal &&
            datapeminjam.waktucheckIn.tanggal <= info(parent(P)).waktucheckOut.tanggal &&
            info(parent(P)).waktucheckIn.jam <= datapeminjam.waktucheckIn.jam &&
            datapeminjam.waktucheckIn.jam <= info(parent(P)).waktucheckOut.jam &&
            info(parent(P)).waktucheckIn.menit <= datapeminjam.waktucheckIn.menit &&
            datapeminjam.waktucheckIn.menit <= info(parent(P)).waktucheckOut.menit)
        {
            cout << "Motor telah di pesan pengguna yang lain" << endl;
        }else{
            mark=true;
        }
    }else{
        mark=true;
    }
    cout<<mark;
}
void dataIdentitas(List_parent L, infotype_parent &x){
    cout << "Masukkan Nomor identitas anda: ";
    x.nomorIdentitas = 1301190478;
    cout << endl;
    bool mark=true;
    while(mark!=false){
        x.ID = randomIntParent();
        mark=checkDuplicateIDParent(L, x.ID);
        cout<<"duplikat";
    }
    cout << "Masukkan Nama: ";
    x.namaPeminjam = "Naufal";
    cout << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    x.waktuPeminjaman.tanggal = ltm->tm_mday;
    x.waktuPeminjaman.bulan = 1 + ltm->tm_mon;
    x.waktuPeminjaman.tahun = 1900 + ltm->tm_year;
    x.waktuPeminjaman.jam = ltm->tm_hour;
    x.waktuPeminjaman.menit = 1 + ltm->tm_min;
}

void inputDataPeminjam(List_relasi LR, infotype_parent &x)
{
    string waktu;
    cout << "durasi peminjaman(jam/hari):" << endl;
    x.durasiPeminjaman = 8;
    waktu = "hari";
    if (waktu == "hari")
    {
        x.durasiPeminjaman = x.durasiPeminjaman * 24;
    }
    cout << x.durasiPeminjaman << endl;
    printDate(x.waktuPeminjaman);

    int harga;
    x.harga = x.durasiPeminjaman * 10000;
    cout << "Harga: " << x.harga << endl;

    cout << "masukan id motor yang akan dipinjam:" << endl;
    x.IDMotor = 19320;

    bool mark = false;
    while(mark!=true){
        while (mark != true)
        {
            cout << "waktu checin:" << endl;
            cin >> x.waktucheckIn.tanggal >> x.waktucheckIn.bulan >> x.waktucheckIn.tahun >> x.waktucheckIn.jam >> x.waktucheckIn.menit;
            if (x.waktucheckIn.tahun < x.waktuPeminjaman.tahun)
            {
                cout << "Inputan tidak valid" << endl;
            }else if(x.waktucheckIn.tahun > x.waktuPeminjaman.tahun){
                mark = true;
            }
            else
            {
                if (x.waktucheckIn.bulan < x.waktuPeminjaman.bulan)
                {
                    cout << "Inputan tidak valid" << endl;
                }else if(x.waktucheckIn.bulan > x.waktuPeminjaman.bulan){
                    mark = true;
                }
                else
                {
                    if (x.waktucheckIn.tanggal < x.waktuPeminjaman.tanggal)
                    {
                        cout << "Inputan tidak valid" << endl;
                    }else if(x.waktucheckIn.tanggal > x.waktuPeminjaman.tanggal){
                        mark = true;
                    }
                    else
                    {
                        if (x.waktucheckIn.jam < x.waktuPeminjaman.jam)
                        {
                            cout << "Inputan tidak valid" << endl;
                        }else if(x.waktucheckIn.jam > x.waktuPeminjaman.jam){
                            mark = true;
                        }
                        else
                        {
                            if (x.waktucheckIn.menit < x.waktuPeminjaman.menit)
                            {
                                cout << "Inputan tidak valid" << endl;
                            }else{
                                mark = true;
                            }
                        }
                    }
                }
            }
        }
        CheckInputanCheckin(LR, x, mark);
    }
    printDate(x.waktucheckIn);

    cout << "waktu checkout" << endl;
    x.waktucheckOut.tanggal = x.waktucheckIn.tanggal;
    x.waktucheckOut.bulan = x.waktucheckIn.bulan;
    x.waktucheckOut.tahun = x.waktucheckIn.tahun;
    x.waktucheckOut.jam = x.waktucheckIn.jam + x.durasiPeminjaman;
    if (x.waktucheckOut.jam >= 24)
    {
        int hari = x.waktucheckOut.jam / 24;
        x.waktucheckOut.tanggal = x.waktucheckIn.tanggal + hari;
        x.waktucheckOut.jam = x.waktucheckOut.jam - (24 * hari);
        if (x.waktucheckOut.tanggal > 31)
        {
            int bulan = x.waktucheckOut.tanggal / 31;
            x.waktucheckOut.bulan = x.waktucheckIn.bulan + bulan;
            x.waktucheckOut.tanggal = x.waktucheckOut.tanggal - (31 * bulan);
            if (x.waktucheckOut.bulan > 12)
            {
                int tahun = x.waktucheckOut.bulan / 12;
                x.waktucheckOut.bulan = x.waktucheckOut.bulan - (tahun * 12);
                x.waktucheckOut.tahun = x.waktucheckIn.tahun + tahun;
            }
        }
    }
    x.waktucheckOut.menit = x.waktucheckIn.menit;
    printDate(x.waktucheckOut);
}

void disconnected(List_relasi L, int ID)
{
    address_relasi P, R;
    P = L.first;

    if (L.first == NULL)
    {
        deleteFirstRelasi(L, R);
        dealokasiRelasi(R);
    }
    else
    {
        if (info(parent(P)).ID == ID)
        {
            cout<<"delete first";
            deleteFirstRelasi(L, R);
            //dealokasiRelasi(R);
        }
        else if (info(parent(last(L))).ID == ID)
        {
            cout<<"deletelast";
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
            cout<<"deleteafter";
            deleteAfterRelasi(P, R);
            dealokasiRelasi(R);
        }
    }
}
