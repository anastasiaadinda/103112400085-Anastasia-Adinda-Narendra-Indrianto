# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Multi Linked List<br/>
A. Pengertian Multi Linked List (MLL)
Struktur data Multi Linked List (MLL) adalah variasi kompleks dari Linked List yang digunakan untuk merepresentasikan hubungan hirarkis atau one-to-many antara dua atau lebih entitas. MLL terdiri dari minimal dua tingkat Linked List yang saling terhubung: satu tingkat sebagai List Induk (Parent List) dan satu atau lebih tingkat sebagai List Anak (Child List)[1].
Dalam konteks tugas ini, MLL memodelkan hubungan antara Golongan Hewan (Parent) dan Hewan (Child).
- List Induk (Parent List): Berisi data entitas tingkat tinggi (misalnya, Golongan Hewan seperti Aves, Mamalia, dll.). List ini diimplementasikan sebagai Doubly Linked List.
- List Anak (Child List): Setiap node pada Parent List terhubung ke List Anak tersendiri. List Anak ini berisi data entitas tingkat rendah (misalnya, Data Hewan spesifik). List Anak juga diimplementasikan sebagai Doubly Linked List.
Intinya, setiap node Parent tidak hanya menyimpan data Golongan Hewan, tetapi juga menyimpan pointer yang menunjuk ke daftar lengkap (List Child) dari semua Hewan yang termasuk dalam golongan tersebut.

### B. Kelebihan & Kekurangan Multi Linked List<br/>
Kelebihan Multi Linked List (MLL)Pemodelan Hierarkis[2]: 
1. Sangat ideal untuk merepresentasikan hubungan 1:N (satu Parent ke banyak Child), seperti Golongan Hewan ke daftar Hewan spesifik.
2. Modifikasi Cepat: Operasi INSERT dan DELETE cepat (O(1)) karena mudah memanipulasi pointer, didukung oleh struktur Doubly Linked List.
3. Dinamis dan Fleksibel: Struktur dapat tumbuh dan menyusut tanpa batas, serta mendukung navigasi maju dan mundur (bi-direksional).
Kekurangan Multi Linked List (MLL)
1. Overhead Memori Tinggi: Membutuhkan banyak memori tambahan untuk menyimpan pointer (next, prev) pada Parent dan Child, yang memakan lebih banyak ruang daripada data itu sendiri.
2. Kompleksitas Implementasi: Jauh lebih rumit untuk diimplementasikan dan rawan kesalahan (bug) karena banyaknya pointer yang harus dikelola.
3. Akses Sekuensial: Pencarian data membutuhkan waktu yang lambat (O(n)) karena harus melintasi list dari awal secara berurutan.

### C. Operasi-operasi dalam Multi Linked List<br/>
Operasi-operasi dalam Multi Linked List[3]
1. Pembuatan (Creation) & Penyisipan (Insertion)
Proses inisialisasi list induk (LParent) dan list anak (LChild) menjadi kosong, diikuti dengan penambahan node baru (Parent atau Child) ke dalam struktur MLL. Operasi penyisipan dapat dilakukan di awal (First), di akhir (Last), atau setelah node tertentu (After).
2. Pencarian (Search) & Penelusuran (Traversal)
Proses menemukan node Parent atau Child yang memenuhi kriteria tertentu (misalnya, ekor = FALSE) atau mengunjungi seluruh node dalam struktur secara sistematis untuk menampilkan datanya (penelusuran dari Parent kemudian ke Child).
3. Penghapusan (Deletion)
Proses menghilangkan Node Parent atau Node Child. Penghapusan Node Parent adalah operasi yang kompleks karena wajib diikuti dengan penghapusan dan didealokasi seluruh List Child yang terikat padanya untuk menghindari memory leak.

## Guided 

### Guided1

#### multilist.h

```C++
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
```
File ini berisi implementasi fungsi Multi Linked List, meliputi pembuatan list, alokasi dan dealokasi node parent–child, operasi insert, delete, search, serta pencetakan struktur data secara hierarkis.

#### multilist.cpp

```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->makanan = idMakanan;   // sebelumnya typo "idMakanan" di struct nodeChild
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                nodeHapus->next->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                nodeHapus->next->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        bool ketemu = false;   // sebelumnya int ketemu
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->makanan == IDCari) {  // sebelumnya idMakanan
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->makanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->makanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
File ini berisi implementasi fungsi Multi Linked List, meliputi pembuatan list, alokasi dan dealokasi node parent–child, operasi insert, delete, search, serta pencetakan struktur data secara hierarkis.

#### main.cpp

```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    //Inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);

    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);

    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //Memasukan Data Child (Menu Makanan) ke kategori tertentu

    //-> Isi Kategori Makanan Berat
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);

    // -> Isi Kategori Minuman
    NodeChild D02 = alokasiNodeChild("N02", "Just Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01); 

    cout << endl;

    // -> Print MLL setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    // -> Searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    // -> Delete node child
    deleteAfterChild(K01 -> L_Anak, M01);
    cout << endl;

    // -> Delete node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;

    // -> print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Program utama ini digunakan untuk menguji ADT Multi Linked List dengan melakukan inisialisasi list, penambahan data parent dan child, pencarian data child berdasarkan ID, penghapusan node child dan parent, serta menampilkan struktur data sebelum dan sesudah operasi.


## Unguided 

### 1. Nomer1
Buatlah ADT Multi Linked List untuk menyimpan data golongan hewan dan data hewan beserta implementasinya.

#### MultiLL.h

```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

#endif
```
Header ini mendefinisikan struktur data Multi Linked List yang terdiri dari list parent dan list child beserta deklarasi fungsi dan prosedur untuk pengelolaan data golongan hewan dan hewan.

#### MultiLL.cpp

```C++
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
```
Program ini mengimplementasikan ADT Multi Linked List yang mencakup operasi alokasi node, insert data parent dan child, serta pencetakan struktur data secara hierarkis.

#### main.cpp

```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {

    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    printMLLStructure(LParent);

    return 0;
}
```
Program ini menggunakan ADT Multi Linked List untuk memasukkan data golongan hewan dan data hewan sesuai soal, kemudian menampilkan struktur data menggunakan prosedur printMLLStructure().

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal1-1-Modul13.png)

##### Output 2
![Screenshot Output Unguided 1-2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal1-2-Modul13.png)

##### Output 3
![Screenshot Output Unguided 1-3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal1-3-Modul13.png)

### 2. Nomer2
Tambahkan prosedur searchHewanByEkor untuk melakukan operasi SEARCHING terhadap hewan yang memiliki ekor = FALSE dengan cara menelusuri seluruh list child pada setiap node parent, kemudian panggil prosedur tersebut pada main.cpp.

#### Multill.h

```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
Header ini mendefinisikan struktur data Multi Linked List serta deklarasi prosedur tambahan searchHewanByEkor yang digunakan untuk melakukan pencarian hewan berdasarkan atribut ekor.

#### Multill.cpp

```C++
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
```
Program ini mengimplementasikan prosedur pencarian hewan berdasarkan atribut ekor dengan menelusuri seluruh node child pada setiap node parent di dalam Multi Linked List.

#### main.cpp

```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {

    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    printMLLStructure(LParent);

    cout << endl;
    cout << "Hasil pencarian hewan dengan ekor = FALSE" << endl;
    searchHewanByEkor(LParent, false);

    return 0;
}
```
Program ini melakukan pencarian hewan yang tidak memiliki ekor dengan memanggil prosedur searchHewanByEkor, kemudian menampilkan data hewan yang memenuhi kriteria tersebut.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal2-1-Modul13.png)

##### Output 2
![Screenshot Output Unguided 1-2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal2-2-Modul13.png)

##### Output 3
![Screenshot Output Unguided 1-3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal2-3-Modul13.png)

### 3. Nomer3
Lakukan operasi DELETE dengan menghapus node G004 (Amfibi) pada list parent, di mana list child dari node tersebut juga ikut terhapus, kemudian lakukan kembali operasi PRINT dengan memanggil prosedur printMLLStructure() sehingga struktur Multi Linked List berubah.

#### Multill.h

```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
Header ini mendefinisikan struktur data Multi Linked List beserta deklarasi prosedur untuk melakukan penghapusan node parent dan seluruh node child yang terhubung.

#### Multill.cpp

```C++
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
```
Program ini menghapus node parent G004 beserta seluruh node child yang terhubung, kemudian menampilkan kembali struktur Multi Linked List setelah penghapusan.

#### main.cpp

```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {

    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    NodeParent P = LParent.first;
    while (P != NULL && P->isidata.idGolongan != "G004") {
        P = P->next;
    }

    if (P != NULL) {
        if (P == LParent.first) {
            deleteFirstParent(LParent);
        } else {
            deleteAfterParent(LParent, P->prev);
        }
    }

    printMLLStructure(LParent);

    return 0;
}
```
Program ini menghapus golongan Amfibi (G004) beserta data hewan di dalamnya, kemudian menampilkan struktur Multi Linked List yang telah diperbarui.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal3-1-Modul13.png)

##### Output 2
![Screenshot Output Unguided 1-2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan11_Modul13/Output/Output-Soal3-2-Modul13.png)

## Kesimpulan
Dari ketiga soal, dapat disimpulkan bahwa Multi Linked List dapat digunakan untuk menyimpan data yang memiliki hubungan hierarkis antara list parent dan list child. Melalui penerapan ADT, struktur data ini memungkinkan pengelolaan data golongan hewan dan data hewan secara terorganisir. Operasi insert, search, dan delete dapat dilakukan dengan menelusuri pointer pada setiap node, sehingga proses pencarian data, penghapusan node beserta relasinya, serta pencetakan struktur data dapat dilakukan secara sistematis dan efisien.

## Referensi
[1]Purwanto, A. D., & Badrul, M. (2016). Implementasi Access List Sebagai Filter Traffic Jaringan (Study Kasus PT. Usaha Entertainment Indonesia). Jurnal Teknik Komputer, 2(1), 78-88.<br>[2]CAHYATI, D. (2016). APLIKASI PENGOLAHAN DATA SAMBUNGAN BARU PADA PERUSAHAAN DAERAH AIR MINUM (PDAM) KABUPATEN OGAN KOMERING ULU BATURAJA (Doctoral dissertation, POLITEKNIK NEGERI SRIWIJAYA).<br>[3]Ambarsari, I. F. (2023). BAB 4 KOMPLEKSITAS ALGORITMA. MATEMATIKA DISKRIT, 55.