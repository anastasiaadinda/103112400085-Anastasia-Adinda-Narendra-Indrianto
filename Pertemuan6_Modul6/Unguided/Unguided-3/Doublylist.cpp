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

// =============================
// Tambahan: Prosedur DELETE
// =============================

// Hapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        dealokasi(P);
    }
}

// Hapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        dealokasi(P);
    }
}

// Hapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        dealokasi(P);
    }
}
