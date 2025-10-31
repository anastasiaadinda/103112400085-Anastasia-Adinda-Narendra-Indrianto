# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Doubly Linked List<br/>
Doubly Linked List adalah jenis struktur data yang setiap simpulnya memiliki dua pointer: satu menunjuk ke node berikutnya (next) dan satu lagi menunjuk ke node sebelumnya (prev), sehingga memungkinkan penelusuran dua arah. Konsep ini merupakan bagian dari fondasi ilmu komputer yang berkembang, dan meskipun tidak memiliki satu penemu tunggal, implementasinya dalam bahasa pemrograman seperti Java disediakan oleh kelas LinkedList dari James Gosling dan tim pengembang Java di Sun Microsystems[1].
Doubly Linked List adalah struktur data linear yang terdiri dari serangkaian simpul (node) yang saling terhubung, di mana setiap simpul memiliki tiga komponen utama:
1. Data - untuk menyimpan nilai
2. Pointer next - menunjuk ke simpul berikutnya
3. Pointer prev - menunjuk ke simpul sebelumnya
Struktur ini memungkinkan traversal (penelusuran) dalam dua arah - maju dari head ke tail menggunakan pointer next, dan mundur dari tail ke head menggunakan pointer prev. Keunggulan utamanya adalah efisiensi dalam operasi penyisipan dan penghapusan simpul karena dapat mengakses simpul sebelumnya secara langsung tanpa harus menelusuri dari awal list[3].
Doubly Linked List biasanya memiliki dua pointer utama: HEAD yang menunjuk ke simpul pertama dan TAIL yang menunjuk ke simpul terakhir, dengan pointer prev HEAD dan pointer next TAIL bernilai NULL sebagai penanda awal dan akhir list.

### B. Struktur Doubly Linked List<br/>
Struktur Doubly Linked List merupakan pengembangan dari linked list sederhana, di mana setiap node tidak hanya terhubung ke node berikutnya, tetapi juga ke node sebelumnya. Setiap node dalam struktur ini memiliki tiga komponen utama:
1. Data → Bagian ini menyimpan nilai atau informasi aktual yang ingin disimpan. Dalam konteks pengolahan data mahasiswa, data dapat berisi NIM, nama, atau informasi lainnya(M.T. Mbejo).
2. Pointer prev (previous) → Pointer ini menunjuk ke node sebelumnya dalam urutan. Jika node tersebut adalah elemen pertama, maka pointer prev akan bernilai null.
3. Pointer next → Pointer ini menunjuk ke node berikutnya dalam urutan. Jika node tersebut adalah elemen terakhir, maka pointer next akan bernilai null.
Struktur ini memungkinkan operasi traversal dua arah - baik maju (forward) maupun mundur (backward) - yang memberikan fleksibilitas lebih dibandingkan dengan Singly Linked List[2]. Keunggulan ini terutama terasa dalam operasi seperti:
1. Penghapusan node yang lebih efisien ketika posisi node sudah diketahui
2. Penelusuran data dari kedua ujung
3. Implementasi fitur undo/redo dalam aplikasi

### C. Operasi Doubly Linked List<br/>
Berikut versi singkat tetap menyertakan nama-nama sumber:
1. Insert First: Menambahkan simpul baru di awal list dengan mengatur pointer next simpul baru ke kepala lama dan pointer prev kepala lama ke simpul baru, lalu memperbarui kepala (H.A Sofianti).
2. Insert After: Menyisipkan simpul baru setelah simpul tertentu dengan mengatur pointer next dan prev simpul baru serta memperbarui simpul sebelum dan sesudahnya (Y.V Manullang).
3. Delete: Menghapus simpul berdasarkan nilai/kunci dengan menyambungkan ulang pointer simpul sebelum dan sesudah simpul yang dihapus (N.A Tampubolon).
4. Delete First: Menghapus simpul pertama dengan memindahkan kepala ke simpul kedua dan mengatur prev kepala baru menjadi null (L.H Naibaho).
5. Delete Last: Menghapus simpul terakhir dengan memindahkan tail ke simpul sebelumnya dan mengatur next tail baru menjadi null (I. Gunawan; H.A Sofianti).
Operasi pada Doubly Linked List memungkinkan penambahan, penyisipan, dan penghapusan simpul secara efisien dengan pengaturan pointer next dan prev, sehingga struktur list tetap terhubung dengan baik[4].


## Guided 

### Guided-1

#### listMakanan.h

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```
File header listMakanan.h mengimplementasikan Doubly Linked List untuk mengelola data makanan. Struktur data ini menyimpan informasi nama, jenis, harga, dan rating setiap makanan. Dilengkapi dengan fungsi dasar seperti inisialisasi list, alokasi/dealokasi memori, operasi insert (first, last, after, before), update data, dan traversal list. Struktur ini ideal untuk sistem manajemen menu yang membutuhkan manipulasi data dinamis.

#### listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```
File ini mengimplementasikan operasi lengkap Doubly Linked List untuk mengelola data makanan, mencakup fungsi inisialisasi list, pengecekan kekosongan, alokasi dan dealokasi memori node, serta empat variasi operasi penyisipan node (insertFirst, insertLast, insertAfter, insertBefore) dan empat operasi pembaruan data (updateFirst, updateLast, updateAfter, updateBefore) yang disertai validasi pointer dan penanganan kasus khusus, dilengkapi dengan fungsi printList untuk menampilkan seluruh data makanan beserta informasi nama, jenis, harga, dan rating secara terstruktur.

#### main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Mengelola data makanan dengan membuat lima node berisi berbagai menu seperti Nasi Rames, Ayam Geprek, Risol Mayo, Mie Ayam, dan Donat yang kemudian disusun secara berurutan menggunakan operasi insertFirst, insertLast, insertAfter, dan insertBefore sehingga membentuk urutan D - A - C - E - B, lalu melakukan pembaruan data pada node pertama, terakhir, sebelum dan setelah node tertentu menggunakan fungsi update, sebelum akhirnya menampilkan seluruh isi list sebelum dan setelah proses update untuk memperlihatkan perubahan data yang terjadi.


### Guided-2

#### Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
File header doublylist.h mendefinisikan struktur data Doubly Linked List untuk mengelola data kendaraan, yang terdiri dari struktur kendaraan berisi informasi nomor polisi, warna, dan tahun pembuatan, serta fungsi-fungsi dasar seperti pembuatan list, alokasi/dealokasi node, penyisipan di akhir list, pencarian berdasarkan nomor polisi, penghapusan data, dan penampilan seluruh informasi kendaraan dalam list.

#### Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
File ini mengimplementasikan fungsi-fungsi untuk mengelola Doubly Linked List kendaraan, dimulai dari inisialisasi list kosong, alokasi node baru berisi data kendaraan, penyisipan node di akhir list, pencarian berdasarkan nomor polisi, penghapusan node dengan empat kasus berbeda (satu-satunya elemen, elemen pertama, elemen terakhir, atau elemen tengah), serta penampilan seluruh data kendaraan dalam list secara berurutan.

#### main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
Program utama ini mendemonstrasikan penggunaan Doubly Linked List untuk mengelola data kendaraan dengan membuat list kosong, menambahkan tiga data kendaraan (D001, D003, D004) menggunakan insertLast, menampilkan data awal, melakukan pencarian kendaraan bernomor polisi D001, menghapus kendaraan D003 menggunakan deleteByNopol, menampilkan data setelah penghapusan, serta menghapus elemen pertama dari list dan menampilkan hasil akhirnya.


## Unguided 

### 1. Unguided-1

Program ADT Doubly Linked List untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan, lalu tampilkan hasilnya melalui file main.cpp.

#### Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// ====== TYPE DEFINITION ======
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== FUNGSI & PROSEDUR ======
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isExist(List L, string nopol);

address findElm(List L, infotype x);

#endif
```
File Doublylist.h berisi deklarasi tipe data dan fungsi untuk mengelola Doubly Linked List yang menyimpan data kendaraan berupa nomor polisi, warna, dan tahun pembuatan.

#### Doublylist.cpp

```C++
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
```
File Doublylist.cpp berisi implementasi fungsi dan prosedur untuk membuat, menambah, menampilkan, serta menghapus data pada Doubly Linked List yang menyimpan informasi kendaraan.

#### main.cpp

```C++
#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    infotype x;
    int n = 4; // contoh input 4 kendaraan

    for (int i = 0; i < n; i++) {
        cout << "\nmasukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek duplikasi nopol
        if (isExist(L, x.nopol)) {
            cout << "\nnomor polisi sudah terdaftar\n";
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    // Tampilkan hasil akhir
    printInfo(L);

    return 0;
}
```
File main.cpp berisi program utama untuk menginput data kendaraan, memeriksa duplikasi nomor polisi, menyimpan data ke dalam Doubly Linked List, dan menampilkan seluruh data kendaraan yang telah dimasukkan.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan6_Modul6/Output/Output-Unguided1-Modul6.png)


### 2. Unguided-2

Buatlah fungsi findElm untuk mencari dan menampilkan data kendaraan dengan nomor polisi D001 pada Doubly Linked List.

#### Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// ====== TYPE DEFINITION ======
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== FUNGSI & PROSEDUR ======
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isExist(List L, string nopol);

//Tambahan deklarasi fungsi
address findElm(List L, infotype x);

#endif
```
File Doublylist.h berisi deklarasi tipe data dan fungsi yang digunakan untuk mengelola Doubly Linked List, termasuk proses pencarian data kendaraan berdasarkan nomor polisi menggunakan fungsi findElm().

#### Doublylist.cpp

```C++
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
```
File Doublylist.cpp berisi implementasi fungsi-fungsi untuk mengelola Doubly Linked List yang menyimpan data kendaraan. Di dalamnya terdapat proses pembuatan list, alokasi dan dealokasi elemen, penambahan data di akhir list, penampilan seluruh data dari belakang ke depan, pengecekan keberadaan nomor polisi, serta pencarian data kendaraan menggunakan fungsi findElm().

#### main.cpp

```C++
#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    infotype x;
    int n = 4; // contoh input 4 kendaraan

    for (int i = 0; i < n; i++) {
        cout << "\nmasukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek duplikasi nopol
        if (isExist(L, x.nopol)) {
            cout << "\nnomor polisi sudah terdaftar\n";
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    // Tampilkan hasil akhir
    printInfo(L);

     // Tambahan supaya daftar kendaraan ditampilkan
     // Cari elemen berdasarkan nomor polisi
    infotype cari;
    cout << "\n\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != nullptr) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cari.nopol << " tidak ditemukan.\n";
    }

    return 0;
}
```
Program ini mengelola data kendaraan dengan Doubly Linked List untuk menambah, menampilkan, dan mencari kendaraan berdasarkan nomor polisi.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan6_Modul6/Output/Output-Unguided2-1-Modul6.png)

##### Output 2
![Screenshot Output Unguided 2-2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan6_Modul6/Output/Output-Unguided2-2-Modul6.png)


### 3. Unguided-3

Hapus elemen dengan nomor polisi tertentu dari list menggunakan prosedur delete yang sesuai.

#### Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// ====== TYPE DEFINITION ======
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== FUNGSI & PROSEDUR ======
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isExist(List L, string nopol);

//Tambahan deklarasi fungsi
address findElm(List L, infotype x);

//Tambahan untuk prosedur delete
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
Deklarasi struktur data dan fungsi untuk mengelola double linked list berisi data kendaraan, seperti nomor polisi, warna, dan tahun pembuatan. Di dalamnya terdapat definisi tipe data, serta deklarasi fungsi dasar seperti pembuatan list, alokasi, pencarian, pengecekan duplikasi, penambahan, dan penghapusan elemen.

#### Doublylist.cpp

```C++
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
```
Implementasi fungsi-fungsi untuk mengelola Doubly Linked List kendaraan, termasuk pembuatan list kosong, alokasi dan dealokasi elemen, penambahan di akhir list, pengecekan duplikasi nomor polisi, pencarian elemen berdasarkan nomor polisi, serta prosedur penghapusan elemen baik di awal, akhir, maupun setelah elemen tertentu.

#### main.cpp

```C++
#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    infotype x;
    int n = 4; // contoh input 4 kendaraan

    for (int i = 0; i < n; i++) {
        cout << "\nmasukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek duplikasi nopol
        if (isExist(L, x.nopol)) {
            cout << "\nnomor polisi sudah terdaftar\n";
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    // Tampilkan hasil akhir
    printInfo(L);

    // Tambahan supaya daftar kendaraan ditampilkan
    // Cari elemen berdasarkan nomor polisi
    infotype cari;
    cout << "\n\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != nullptr) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cari.nopol << " tidak ditemukan.\n";
    }

    // ================================
    // Tambahan: Hapus data kendaraan
    // ================================
    string hapusNopol;
    cout << "\n\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address P = L.First;

    while (P != nullptr && P->info.nopol != hapusNopol) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Data dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n";
    }

    // Tampilkan list setelah penghapusan
    printInfo(L);

    return 0;
}
```
Program utama untuk mengelola data kendaraan menggunakan Doubly Linked List. Program ini memungkinkan pengguna untuk memasukkan data kendaraan, memeriksa duplikasi nomor polisi, menampilkan seluruh data, mencari kendaraan berdasarkan nomor polisi, serta menghapus kendaraan tertentu dari list dan menampilkan daftar yang tersisa setelah penghapusan.

##### Output 1
![Screenshot Output Unguided 2-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan6_Modul6/Output/Output-Unguided3-1-Modul6.png)

##### Output 2
![Screenshot Output Unguided 2-2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan6_Modul6/Output/Output-Unguided3-2-Modul6.png)


## Kesimpulan
Pembuatan dan pengelolaan Doubly Linked List memungkinkan penyimpanan data kendaraan secara terstruktur. Program dapat menambah data baru di akhir list, menampilkan seluruh isi list, memeriksa nomor polisi untuk mencegah duplikasi, serta mencari dan menghapus elemen tertentu dari list. Implementasi fungsi-fungsi ini menunjukkan bahwa operasi pada Doubly Linked List dapat dilakukan secara efisien dan sistematis.


## Referensi
[1]Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. INFOKOM (Informatika & Komputer), 7(2), 15-24<br>[2]Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444.<br>[3]Khoerul, A. (2023). Pengantar Struktur Data Full.<br>[4]Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877