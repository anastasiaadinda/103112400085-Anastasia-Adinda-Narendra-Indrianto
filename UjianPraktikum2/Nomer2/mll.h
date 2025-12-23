#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct NodeChild {
    string IDFilm, judulFilm;
    int durasiFilm, tahunTayang;
    float ratingFilm;
    NodeChild *next, *prev;
};

struct ListChild {
    NodeChild *first, *last;
};

struct NodeParent {
    string IDGenre, namaGenre;
    ListChild childs;
    NodeParent *next, *prev;
};

struct ListParent {
    NodeParent *first, *last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void insertFirstParent(ListParent &L, NodeParent* P);
void insertLastChild(ListChild &L, NodeChild* P);
void hapusListChild(ListChild &L);
void deleteAfterParent(ListParent &L, NodeParent* prec, NodeParent* &P);
void printStrukturMLL(ListParent L);
void searchFilmByRatingRange(ListParent L, float min, float max);

#endif