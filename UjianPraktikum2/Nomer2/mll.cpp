#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(ListChild &L) {
    L.first = NULL;
    L.last = NULL;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent* P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->childs);
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild* P = new NodeChild;
    P->IDFilm = id;
    P->judulFilm = judul;
    P->durasiFilm = durasi;
    P->tahunTayang = tahun;
    P->ratingFilm = rating;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstParent(ListParent &L, NodeParent* P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(ListChild &L, NodeChild* P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void hapusListChild(ListChild &L) {
    NodeChild* P = L.first;
    while (P != NULL) {
        NodeChild* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteAfterParent(ListParent &L, NodeParent* prec, NodeParent* &P) {
    if (prec == NULL || prec->next == NULL) {
        P = NULL;
        return;
    }
    P = prec->next;
    hapusListChild(P->childs);
    prec->next = P->next;
    if (P->next != NULL) {
        P->next->prev = prec;
    } else {
        L.last = prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

void printStrukturMLL(ListParent L) {
    NodeParent* P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        NodeChild* C = P->childs.first;
        int j = 1;
        while (C != NULL) {
            cout << " - Child " << j << " :" << endl;
            cout << "   ID Film : " << C->IDFilm << endl;
            cout << "   Judul Film : " << C->judulFilm << endl;
            cout << "   Durasi Film : " << C->durasiFilm << " menit" << endl;
            cout << "   Tahun Tayang : " << C->tahunTayang << endl;
            cout << "   Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "-----------------------" << endl;
        P = P->next;
        i++;
    }
}

void searchFilmByRatingRange(ListParent L, float min, float max) {
    NodeParent* P = L.first;
    while (P != NULL) {
        NodeChild* C = P->childs.first;
        int posC = 1;
        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "==============================" << endl;
            }
            C = C->next;
            posC++;
        }
        P = P->next;
    }
}