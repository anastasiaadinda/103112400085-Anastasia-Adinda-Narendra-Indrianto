# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Linked List<br/>
Linked list merupakan salah satu bentuk struktur data dinamis yang terdiri atas sekumpulan elemen data bertipe sama, di mana setiap elemen saling terhubung melalui pointer. Pointer berfungsi untuk menunjukkan alamat dari elemen berikutnya di memori, sehingga hubungan antar elemen bersifat logis, meskipun secara fisik tidak bersebelahan di memori komputer[1]. Setiap elemen dalam linked list disebut sebagai node (simpul), yang umumnya terdiri dari dua bagian, yaitu field data untuk menyimpan nilai dan field pointer (link) untuk menunjuk ke node berikutnya(J. Sihombing, Politeknik Piksi Ganesha). Jenis-jenis linked list antara lain singly linked list, doubly linked list, singly circular linked list, dan doubly circular linked list, yang masing-masing memiliki karakteristik dan cara kerja berbeda.

### B. Komponen Linked List<br/>
Komponen utama dalam struktur data Linked List terdiri dari node, pointer, head, dan tail. Setiap node berfungsi sebagai wadah yang menyimpan data serta penunjuk atau pointer ke simpul berikutnya. Pointer berperan penting untuk menghubungkan antar simpul sehingga membentuk rantai data yang saling terhubung. Bagian head merupakan simpul pertama yang menjadi titik awal untuk mengakses seluruh isi daftar, sedangkan tail adalah simpul terakhir yang menunjuk ke nilai null sebagai tanda akhir dari rangkaian data menurut Muhammad Rizki Andrian Fitra dkk(2025)[2].
1. Node (Simpul) → menyimpan data dan pointer ke node berikutnya.
Fungsi: menjadi elemen utama penyusun linked list.
2. Pointer (Link) → alamat memori yang menunjuk ke node lain.
Fungsi: menghubungkan antar node agar membentuk rantai data.
4. Head → node pertama dalam linked list.
Fungsi: sebagai titik awal untuk menelusuri seluruh data.
5. Tail → node terakhir yang menunjuk ke null.
Fungsi: menandai akhir dari linked list.

### C. Pengertian Insert Pada C++<br/>
Insert pada Linked List adalah proses menyisipkan elemen baru ke dalam daftar, baik di awal (push_front), di akhir (push_back), maupun di posisi tertentu sebelum elemen yang ditunjuk (insert(p, x)). Operasi ini menautkan node baru ke node lain melalui pointer tanpa harus memindahkan seluruh elemen seperti pada array.
Fungsi utama dari insert adalah menambahkan data baru secara dinamis di mana saja dalam struktur data tanpa perlu realokasi memori(Lucky E. Santoso (2004)). Hal ini membuat pengelolaan data lebih fleksibel dan efisien, terutama saat sering dilakukan penambahan atau penghapusan data[3].


## Guided 

### 1. Guided_1

#### list.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Kode di atas adalah header file untuk Linked List data mahasiswa. Berisi struktur mahasiswa, node, dan linkedlist, serta fungsi untuk membuat, menambah, menampilkan, dan menghapus data. Header guard digunakan agar file tidak di-include dua kali.


#### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Kode ini mengelola Linked List mahasiswa dengan fungsi untuk membuat list, menambah node di awal/tengah/akhir, menghapus node, dan menampilkan seluruh data secara dinamis.


#### main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas adalah program utama untuk menguji fungsi-fungsi pada Linked List mahasiswa. Program membuat list kosong, lalu menambahkan lima data mahasiswa menggunakan fungsi insertFirst, insertAfter, dan insertLast. Setelah semua data dimasukkan, program menampilkan seluruh isi list dengan memanggil printList().


### 2. Guided_2

#### list.h

```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
Kode di atas adalah header file untuk program Linked List mahasiswa.
File ini mendefinisikan struktur data (mahasiswa, node, dan linkedlist) serta deklarasi fungsi untuk operasi dasar seperti membuat list, menambah node, menghapus node, menghitung jumlah elemen, dan menghapus seluruh list.


#### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
Kode di atas merupakan implementasi lengkap Linked List untuk data mahasiswa.
Program ini mencakup fungsi membuat list, menambah node (awal, tengah, akhir), menghapus node (awal, tengah, akhir), menghitung jumlah node, menampilkan isi list, dan menghapus seluruh list.


#### main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
}
```
Kode di atas adalah program utama untuk menguji semua operasi pada Linked List mahasiswa.
Program membuat list kosong, menambah lima data mahasiswa dengan berbagai posisi (awal, tengah, akhir), lalu menampilkan hasilnya. Setelah itu dilakukan penghapusan node di awal, akhir, dan tengah, kemudian ditampilkan kembali hasilnya. Terakhir, seluruh list dihapus menggunakan deleteList().


## Unguided 

### 1. Soal Unguided_1

Buatlah ADT Singly Linked List dengan tipe data int, yang memiliki operasi:
CreateList, alokasi, dealokasi, printInfo, dan insertFirst.
Kemudian buat program utama untuk menambahkan data 9, 12, 8, 0, 2 sehingga membentuk linked list:


#### Singlylist.h

```C++
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
```
File ini berisi deklarasi ADT Singly Linked List dasar, mencakup struktur ElmList untuk menyimpan data dan pointer next, serta struktur List untuk menyimpan alamat node pertama. Selain itu, terdapat deklarasi fungsi untuk membuat list, mengalokasikan dan menghapus node, menampilkan isi list, serta menambah elemen di awal list.


#### Singlylist.cpp

```C++
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
```
File ini berisi implementasi dasar Singly Linked List, meliputi pembuatan list kosong, alokasi dan dealokasi node, penambahan node di awal list, serta menampilkan seluruh data yang tersimpan di dalam list.


#### main.cpp

```C++
#include "Singlylist.h"
#include <iostream>
#include <chrono> // for measuring execution time
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now(); // start time measurement

    List L;
    CreateList(L); // create empty list

    // insert data into list
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // display list data
    printInfo(L);

    // add blank line for spacing
    cout << endl;

    auto end = chrono::high_resolution_clock::now(); // end time measurement
    chrono::duration<double> duration = end - start; // calculate execution time

    // display output similar to IDE format
    cout << "Process returned 0 (0x0) execution time : " 
         << duration.count() << " s" << endl;
    cout << "Press any key to continue." << endl;

    return 0;
}
```
Program ini membuat dan menampilkan Singly Linked List berisi data 9, 12, 8, 0, 2.
Node ditambahkan menggunakan insertFirst, sehingga urutan data terbentuk sesuai hasil yang diinginkan.
Selain itu, program juga menampilkan waktu eksekusi dan format output seperti di IDE, menunjukkan bahwa proses pembuatan dan penampilan list berjalan sukses.


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan4_Modul4/Output/Output-Unguided1-Modul4.png)

Program ini membuat Singly Linked List bertipe data int dan menambahkan elemen 9, 12, 8, 0, dan 2 menggunakan fungsi insertFirst. Setiap data disimpan dalam node yang saling terhubung satu arah melalui pointer next. Hasil akhirnya menampilkan urutan data 9 12 8 0 2, yang menunjukkan bahwa linked list berhasil terbentuk dan berjalan sesuai fungsi yang dibuat


### 2. Soal Unguided 2

Lakukan penghapusan node 9 dengan delFirst(), node 2 dengan delLast(), dan node 8 dengan delAfter().
Tampilkan jumlah node dengan nbList() dan hapus seluruh node menggunakan deleteList().


#### Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Deklarasi fungsi dan prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void delFirst(List &L);
void delLast(List &L);
void delAfter(List &L, address P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```
File ini mendefinisikan struktur dan fungsi dasar Singly Linked List, seperti membuat list, menambah, menghapus, menampilkan, menghitung, dan menghapus seluruh node.


#### Singlylist.cpp

```C++
#include "Singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Cetak isi list
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

// Insert di awal
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// Delete node pertama
void delFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}

// Delete node terakhir
void delLast(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        address Prec = Nil;
        while (P->next != Nil) {
            Prec = P;
            P = P->next;
        }
        if (Prec == Nil)
            L.First = Nil;
        else
            Prec->next = Nil;
        dealokasi(P);
    }
}

// Delete node setelah node tertentu
void delAfter(List &L, address P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// Hitung jumlah node
int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

// Hapus seluruh list
void deleteList(List &L) {
    address P = L.First;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.First = Nil;
}
```
File ini berisi implementasi fungsi Singly Linked List, meliputi pembuatan list, alokasi dan dealokasi node, menambah dan menghapus elemen, menampilkan isi list, menghitung jumlah node, serta menghapus seluruh isi list.


#### main.cpp

```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    // Membuat linked list: 9 -> 12 -> 8 -> 0 -> 2
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // Hapus node 9 (awal)
    delFirst(L);

    // Hapus node 2 (akhir)
    delLast(L);

    // Hapus node 8 (setelah 12)
    address P = L.First;
    delAfter(L, P->next, P);

    // Cetak hasil akhir
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << " \n" << endl;

    // Hapus seluruh list
    deleteList(L);

    cout << "- List Berhasil Terhapus - " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
Program utama ini menjalankan operasi pada Singly Linked List, mulai dari membuat list berisi data 9, 12, 8, 0, 2, kemudian menghapus node 9 (awal), 2 (akhir), dan 8 (tengah). Setelah itu, program menampilkan isi list (12 0), jumlah node yang tersisa, lalu menghapus seluruh list hingga kosong.


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan4_Modul4/Output/Output-Unguided2-Modul4.png)


## Kesimpulan
Dari kedua soal, dapat disimpulkan bahwa Singly Linked List memungkinkan pengelolaan data secara dinamis menggunakan pointer. Pada soal pertama, list berhasil dibentuk dan menampilkan urutan data sesuai urutan penyisipan. Pada soal kedua, berbagai operasi penghapusan node (delFirst, delLast, delAfter) dan penghapusan seluruh list (deleteList) berjalan dengan baik, menunjukkan bahwa struktur dan fungsi Linked List berfungsi sesuai tujuan untuk menambah, menampilkan, dan menghapus data secara efisien.


## Referensi
[1]Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. INFOKOM (Informatika & Komputer), 7(2), 15-24<br>[2]Fitra, M. R. A., Effendi, A. A. S., & Ramadhani, F. (2025). Implementasi Python Dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 Pada Universitas Negeri Medan Menggunakan Struktur Data Linked List. JATI (Jurnal Mahasiswa Teknik Informatika), 9(1), 51-58<br>[3]Santoso, L. E. (2004). STANDARD TEMPLATE LIBRARY C++ UNTUK MENGAJARKAN STRUKTUR DATA. Jurnal FASILKOM Vol, 2(2).