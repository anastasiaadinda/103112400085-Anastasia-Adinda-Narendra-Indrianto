#include "Singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Cetak isi list
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

// Insert di awal
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// Delete node pertama
void delFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}

// Delete node terakhir
void delLast(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        address Prec = Nil;
        while (P->next != Nil) {
            Prec = P;
            P = P->next;
        }
        if (Prec == Nil)
            L.First = Nil;
        else
            Prec->next = Nil;
        dealokasi(P);
    }
}

// Delete node setelah node tertentu
void delAfter(List &L, address P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// Hitung jumlah node
int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

// Hapus seluruh list
void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.First = Nil;
}
