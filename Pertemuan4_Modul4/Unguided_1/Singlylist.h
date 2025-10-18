#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// Deklarasi tipe data
typedef int infotype;
typedef struct ElmList *address;

// Struktur node (elemen list)
struct ElmList {
    infotype info;
    address next;
};

// Struktur list
struct List {
    address First;
};

// Deklarasi fungsi dan prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif