#include "Doublylist.h"

// Membuat list kosong
void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Mengalokasi elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menampilkan semua data di list (dari belakang ke depan)
void printInfo(List L) {
    cout << "\nDATA LIST 1\n\n";
    address P = L.Last;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == nullptr) { // Jika list kosong
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Mengecek apakah nopol sudah ada
bool isExist(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol)
            return true;
        P = P->next;
    }
    return false;
}

// Tambahan implementasi fungsi
// Mencari elemen berdasarkan nomor polisi
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

