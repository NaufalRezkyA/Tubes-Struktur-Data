#include "list_relasi.h"

void createListRelasi(List_relasi &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_relasi alokasiRelasi(address_parent P, address_child C)
{
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

void dealokasiRelasi(address_relasi &P)
{
    delete P;
}

void insertLastRelasi(List_relasi &L, address_relasi P)
{
    if (L.first == NULL)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        L.last->next = P;
        prev(P)=last(L);
        L.last = P;
    }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &P)
{
    P = first(L);
    parent(P)=NULL;
    child(P)=NULL;
    if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLastRelasi(List_relasi &L, address_relasi &P)
{
    P = last(L);
    parent(P) = NULL;
    child(P) = NULL;
    if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        last(L)=prev(P);
        next(last(L))=NULL;
        prev(P) = NULL;
    }
}

void deleteAfterRelasi(List_relasi &L, address_relasi Prec, address_relasi &P)
{
    if (L.first == L.last && Prec != NULL)
    {
        deleteFirstRelasi(L, P);
    }
    else if (Prec->next != L.last && Prec != NULL)
    {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
    else if (Prec != NULL)
    {
        deleteLastRelasi(L, P);
    }
}

int CountRelasi(List_relasi L)
{
    address_relasi P = first(L);
    int i = 0;
    while (P != NULL)
    {
        i++;
        P = next(P);
    }
    return i;
}

void printInfoRelasi(List_relasi L)
{
    address_relasi P = first(L);
    int i,j;
    i = 7;
    j = 0;
    if(P!=NULL){
        while (P != NULL)
        {
            if(parent(P)!=NULL && child(P)!=NULL){
                if(i+6 >= 30){
                    i = 9;
                    j = 29;
                }
                gotoxy(38,i);cout << "Nama Peminjam   : "<<info(parent(P)).namaPeminjam << endl;
                gotoxy(38,i+1);cout << "ID Peminjam     : "<<info(parent(P)).ID << endl;
                gotoxy(38,i+2);cout << "Nama Motor      :"<<info(child(P)).NamaMotor << endl;
                gotoxy(38,i+3);cout << "Waktu checkin   : "<<endl;
                printDate(info(parent(P)).waktucheckIn, i+4, j);
                gotoxy(38,i+6);cout << "Waktu checkout  : " << endl;
                printDate(info(parent(P)).waktucheckOut, i+7, j);
            }
            i=i+10;
            P = next(P);
        }
    }else{
        gotoxy(45,20);cout<< "Tidak ada data peminjaman..."<<endl;
    }
}

void printInfoTerbaru(List_relasi L)
{
    address_relasi P = last(L);
    int k = 1;
    int i = 9;
    int j = 0;
    if (P != NULL)
    {
        while (P != NULL || k <= CountRelasi(L))
        {
            if(i+6 >= 30){
                i = 9;
                j = 29;
            }
            gotoxy(38,i);cout << "Nama Peminjam   : "<<info(parent(P)).namaPeminjam << endl;
            gotoxy(38,i+1);cout << "ID Peminjam     : "<<info(parent(P)).ID << endl;
            gotoxy(38,i+2);cout << "Nama Motor      :"<<info(child(P)).NamaMotor << endl;
            gotoxy(38,i+3);cout << "Waktu checkin   : "<<endl;
            printDate(info(parent(P)).waktucheckIn, i+4, j);
            gotoxy(38,i+6);cout << "Waktu checkout  : " << endl;
            printDate(info(parent(P)).waktucheckOut, i+7, j);
            P = prev(P);
            k++;
        }
    }
    else
    {
        gotoxy(55,15);cout << "Tidak ada data peminjaman motor" << endl;
    }
}

address_relasi findElmRelasiByParent(List_relasi L, int ID)
{
    address_relasi Q = first(L);
    while (Q != NULL)
    {
        if (info(parent(Q)).ID == ID)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

address_relasi findElmRelasiByChild(List_relasi L, int ID)
{
    address_relasi Q = first(L);
    while (Q != NULL)
    {
        if (info(child(Q)).ID == ID)
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}


void CheckInputanCheckin(List_relasi LR, DataPeminjam datapeminjam, bool &mark)
{
    address_relasi P = findElmRelasiByChild(LR, datapeminjam.IDMotor);
    mark = false;
    if (P != NULL)
    {
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
            gotoxy(45,15);cout << "Motor telah di pesan pengguna yang lain" << endl;
        }
        else
        {
            mark = true;
        }
    }
    else
    {
        mark = true;
    }
}
void dataIdentitas(List_parent L, infotype_parent &x)
{
    gotoxy(55,7);cout << "Formulir Data Diri Peminjam ";
    gotoxy(38,9);cout << "Masukkan Nomor identitas          : ";
    cin >> x.nomorIdentitas;
    bool mark = true;
    while (mark != false)
    {
        x.ID = randomIntParent();
        mark = checkDuplicateIDParent(L, x.ID);
    }
    gotoxy(38,10);cout << "Masukkan Nama                     : ";
    cin>>x.namaPeminjam;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    x.waktuPeminjaman.tanggal = ltm->tm_mday;
    x.waktuPeminjaman.bulan = 1 + ltm->tm_mon;
    x.waktuPeminjaman.tahun = 1900 + ltm->tm_year;
    x.waktuPeminjaman.jam = ltm->tm_hour;
    x.waktuPeminjaman.menit = 1 + ltm->tm_min;
}

void checkin(List_relasi LR,List_child LC, infotype_parent &x, infotype_child &y)
{
    int i, j;
    bool mark = false;
    while (mark != true)
    {
        gotoxy(38, 10);
        cout << "Masukan ID motor yang akan dipinjam: " << endl;
        cin >> x.IDMotor;
        address_child R = findElmChild(LC, x.IDMotor);
        if(R!=NULL){
            address_relasi P = (findElmRelasiByChild(LR, x.IDMotor));
            if (P != NULL)
            {
                cout<<"Motor dipakai orang lain pada :"<<endl;
            }
            else
            {
                mark = true;
            }
        }else{
            cout<<"Data motor tidak ada..."<<endl;
        }
        
    }

    mark = false;
    while (mark != true)
    {
        while (mark != true)
        {
            gotoxy(38,11);cout << "Waktu checkin: " << endl;
            gotoxy(40,12);cout << "Format pengisian tanggal bulan tahun jam menit" << endl;
            gotoxy(40,13);cout << "Yang dipisahkan dengan 1 space.." << endl;
            gotoxy(40,14);cout << "Ex: 23 9 2000 10 30" << endl;
            gotoxy(38,15);cout << "Silahkan input waktu : ";
            cin >> x.waktucheckIn.tanggal >> x.waktucheckIn.bulan >> x.waktucheckIn.tahun >> x.waktucheckIn.jam >> x.waktucheckIn.menit;
            gotoxy(38,16);cout << "Waktu Sekarang : ";
            i = 17;
            j = 0;
            printDate(x.waktuPeminjaman, i, j);
            if (x.waktucheckIn.tahun < x.waktuPeminjaman.tahun)
            {
                gotoxy(38,19);cout << "Inputan tidak valid" << endl;
            }
            else if (x.waktucheckIn.tahun > x.waktuPeminjaman.tahun)
            {
                mark = true;
            }
            else
            {
                if (x.waktucheckIn.bulan < x.waktuPeminjaman.bulan)
                {
                    gotoxy(38,19);cout << "Inputan tidak valid" << endl;
                }
                else if (x.waktucheckIn.bulan > x.waktuPeminjaman.bulan)
                {
                    mark = true;
                }
                else
                {
                    if (x.waktucheckIn.tanggal < x.waktuPeminjaman.tanggal)
                    {
                        gotoxy(38,19);cout << "Inputan tidak valid" << endl;
                    }
                    else if (x.waktucheckIn.tanggal > x.waktuPeminjaman.tanggal)
                    {
                        mark = true;
                    }
                    else
                    {
                        if (x.waktucheckIn.jam < x.waktuPeminjaman.jam)
                        {
                            gotoxy(38,19);cout << "Inputan tidak valid" << endl;
                        }
                        else if (x.waktucheckIn.jam > x.waktuPeminjaman.jam)
                        {
                            mark = true;
                        }
                        else
                        {
                            if (x.waktucheckIn.menit < x.waktuPeminjaman.menit)
                            {
                                gotoxy(38,19);cout << "Inputan tidak valid" << endl;
                            }
                            else
                            {
                                mark = true;
                            }
                        }
                    }
                }
            }
        }
        CheckInputanCheckin(LR, x, mark);
    }
    i = 21;
    gotoxy(38,20);cout << "Waktu checkin:" << endl;
    printDate(x.waktucheckIn, i, j);

    gotoxy(38,24);cout << "Waktu checkout:" << endl;
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
    i =25;
    printDate(x.waktucheckOut, i, j);
    y.ID = x.IDMotor;
}

void inputDataPeminjam(List_relasi LR, infotype_parent &x)
{
    int i;
    int j = 0;
    string waktu;
    gotoxy(38,11);cout << "durasi peminjaman(ex: 8 jam/hari) : ";
    cin >> x.durasiPeminjaman >> waktu;
    if (waktu == "hari")
    {
        x.durasiPeminjaman = x.durasiPeminjaman * 24;
    }
    gotoxy(45,15);cout <<"RESULT"<< endl;
    gotoxy(38,16);cout <<"Durasi Peminjaman : "<< x.durasiPeminjaman << " jam"<< endl;
    i = 17;
    printDate(x.waktuPeminjaman, i, j);

    int harga;
    x.harga = 0;
}

void connect(List_relasi &LR, List_parent LP, List_child LC, infotype_parent Datapeminjam, infotype_child datachild){
    address_parent P = findElmParent(LP, Datapeminjam.ID);
    address_child Q = findElmChild(LC, datachild.ID);
    insertLastRelasi(LR, alokasiRelasi(P, Q));
    address_relasi R = findElmRelasiByParent(LR, Datapeminjam.ID);
    info(parent(R)).harga = info(parent(R)).durasiPeminjaman * info(child(R)).Harga;
}

void disconnected(List_relasi &L, int ID)
{
    address_relasi P, R;
    P = L.first;

    if (info(parent(P)).ID == ID || L.first == NULL)
    {
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
        deleteAfterRelasi(L, P, R);
        dealokasiRelasi(R);
    }

}


