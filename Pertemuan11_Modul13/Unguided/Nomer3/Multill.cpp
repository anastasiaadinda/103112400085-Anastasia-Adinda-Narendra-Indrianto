#include <iostream>
#include "MultiLL.h"
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
        }
        delete C;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        deleteListChild(P->L_Child);
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
        }
        delete P;
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    NodeParent P = NPrev->next;
    if (P != NULL) {
        deleteListChild(P->L_Child);
        NPrev->next = P->next;
        if (P->next != NULL) {
            P->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        delete P;
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int i = 1;

    while (P != NULL) {
        cout << "== Parent " << i++ << " ==" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int j = 1;
            while (C != NULL) {
                cout << "  Child " << j++ << " :" << endl;
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "  Habitat : " << C->isidata.habitat << endl;
                cout << "  Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "  Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "-------------------------" << endl;
        P = P->next;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        while (C != NULL) {
            if (C->isidata.ekor == tail) {
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "Golongan : " << P->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}
