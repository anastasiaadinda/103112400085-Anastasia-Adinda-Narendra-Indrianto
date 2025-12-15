#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    string makanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);  // typo: sebelumnya "creteListAnak"

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

///alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan); // konsisten huruf besar
void dealokasiNodeChild(NodeChild &nodeAnak);

// opearsi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak); // typo sebelumnya "vooid"
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//opeari pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild); // typo sebelumnya "LAnaka"
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari); // typo sebelumnya "listINduk &LINduk"

//opearasi print
void printStrukturMLL(listInduk &LInduk);

#endif
