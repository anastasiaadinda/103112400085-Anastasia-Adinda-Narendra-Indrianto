#include "Singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// Mengalokasikan node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Menghapus node dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menampilkan seluruh isi list
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menyisipkan node di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
