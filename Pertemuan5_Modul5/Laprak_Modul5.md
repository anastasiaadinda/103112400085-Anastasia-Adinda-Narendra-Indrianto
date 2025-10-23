# <h1 align="center">Laporan Praktikum Modul 5 -  SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Searching Singly Linked List<br/>
Searching pada singly linked list dalam bahasa C++ adalah proses pencarian data dengan menelusuri setiap node secara berurutan mulai dari node pertama (head) hingga node terakhir yang menunjuk ke NULL. Struktur data ini terdiri atas sejumlah simpul (node) yang masing-masing memiliki dua bagian, yaitu bagian data untuk menyimpan nilai dan bagian pointer yang menunjuk ke node berikutnya[1]. Pencarian dilakukan menggunakan metode linear search, yaitu membandingkan nilai yang dicari dengan data di setiap node secara berurutan hingga ditemukan kecocokan atau mencapai akhir list. Konsep linked list pertama kali dikemukakan oleh Allen Newell, Cliff Shaw, dan Herbert A. Simon pada tahun 1956 dalam proyek Logic Theorist, sedangkan metode linear search merupakan algoritma dasar pencarian yang telah digunakan sejak awal perkembangan komputer(H. Soetanto(2020)).

### B. Tujuan Searching Singly Linked List<br/>
Tujuan searching pada singly linked list adalah untuk menemukan dan mengidentifikasi data tertentu yang tersimpan dalam setiap node dengan cara menelusuri list secara berurutan mulai dari node pertama (head) hingga node terakhir yang menunjuk ke NULL(H. A. Sofianti dkk. (2025)). Pencarian ini bertujuan agar program dapat mengetahui apakah data yang dicari ada di dalam list, serta memperoleh posisi atau alamat node yang berisi data tersebut jika ditemukan[2]. Proses searching juga berperan penting dalam operasi lain seperti penghapusan (deletion) dan pembaruan (update), karena kedua operasi tersebut memerlukan lokasi data yang tepat dalam list.

### C. Operasi-operasi Dasar Singly Linked List<br/>
Operasi dasar pada singly linked list dalam bentuk poin:
1. Create (Membuat List)
Operasi ini digunakan untuk membuat list baru dan menginisialisasi pointer head menjadi NULL sebagai tanda bahwa list masih kosong sebelum digunakan.
2. Insert (Menambah Node)
Operasi ini berfungsi untuk menambahkan node baru ke dalam list. Penambahan dapat dilakukan di awal (insert first), di tengah (insert after), atau di akhir list (insert last).
3. Delete (Menghapus Node)
Operasi ini digunakan untuk menghapus node dari list, baik berdasarkan data maupun posisi node. Setelah penghapusan, pointer dari node sebelumnya akan disesuaikan agar list tetap terhubung.
4. Searching (Mencari Data)
Operasi ini berfungsi untuk mencari data tertentu dalam list dengan cara menelusuri setiap node dari head hingga NULL sampai data yang dicari ditemukan.
5. Traversal (Menampilkan Data)
Operasi ini digunakan untuk menampilkan seluruh isi list dengan menelusuri node satu per satu dari head hingga node terakhir[3].
Kesimpulannya, singly linked list memiliki lima operasi dasar utama yaitu create, insert, delete, searching, dan traversal yang masing-masing berfungsi untuk membuat, menambah, menghapus, mencari, dan menampilkan data dalam list. Operasi-operasi ini memungkinkan pengelolaan data secara dinamis dan efisien karena ukuran list dapat berubah sesuai kebutuhan(M. Bachtiar, A. (2010).).


## Guided 

### 1. List Buah

#### listBuah.h

```C++
#ifndef LIST_BUAH
#define LIST_BUAH
#define Nil NULL 

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah
typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct

struct node{ //node untuk isi dari linked listnya. isi setiap node adalah data & pointer
    dataBuah isidata;
    address next; 
};

struct linkedlist{
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &list);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
Berisi deklarasi struktur data dan fungsi untuk mengelola singly linked list data buah, seperti deklarasi struct, tipe data pointer, serta daftar fungsi (insert, delete, update, print, dll) tanpa implementasi.

#### listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
Berisi implementasi lengkap dari fungsi-fungsi yang dideklarasikan di listBuah.h, mencakup logika untuk menambah, menghapus, memperbarui, menampilkan, dan menghitung data buah dalam list secara dinamis.

#### main.cpp

```C++
#include "listBuah.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 74, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << " --- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini merupakan program utama (main) yang menggunakan fungsi-fungsi dari file listBuah.h dan listBuah.cpp. Program ini membuat linked list berisi data buah seperti Jeruk, Apel, Pir, Semangka, dan Durian, kemudian melakukan operasi penambahan (insert) dan pembaruan data (update). Setelah itu, program menampilkan isi list beserta jumlah node yang ada di dalamnya.


### 2. Binary

#### binary.cpp

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node *next; //pointer ke node berikutnya
};

void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr}; //newNode adalah pointer yang menunjuk ke node baru yang akan dibuat.
    //value == null karena node baru berada di paling akhir
    if(!head) head = newNode; // jika head null, head diisi node baru
    else{
        Node * temp = head; // mulai dari head
        while (temp -> next) temp = temp -> next; // pindah ke node berikutnya sampai ketemu node terakhir
        temp -> next = newNode; // node terakhir dihubungkan ke node baru
    }
}

Node * binarySearch(Node * head, int key){ //Node* ini pointer (kembalian) //head ini pointer ke node pertama // key ini data yang idcari
    int size = 0; //var disi 0
    for (Node *current = head; current; current = current -> next) size++; //current adalah pointer yang digunakan untuk menyusuri linked list

    Node* start = head; // start adlh pointer yang menunjuk ke node pertama
    Node* end = nullptr; // end adalah pointer yang menunjuk ke node terakhir(null karena linked list tidak emiliki node terakhir yang pasti)

    while(start != end){
        int mid = size / 2;
        Node* midNode = start;
        for(int i = 0; i < mid; i++) midNode = midNode -> next;

        if(midNode -> data == key) return midNode;
        if(midNode -> data < key){
            start = midNode -> next;
            size = size - mid - 1;
        }
        else{
            size = mid;
        }
    }
    
    if(start && start->data == key) return start;
    return nullptr; //Jika key tidak ditemukan
}

int main(){
    Node *head = nullptr;
    append(head, 10); append(head,20); append(head,30);
    append(head, 40); append(head,50);

    Node * result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program ini merupakan implementasi binary search pada singly linked list menggunakan bahasa C++. Program membuat daftar berantai berisi data integer (10, 20, 30, 40, 50) menggunakan fungsi append(), kemudian melakukan pencarian elemen tertentu (misalnya angka 40) menggunakan fungsi binarySearch().


### 3. Linear

#### linear.cpp

```C++
#include<iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data; 
    Node *next; //Pointer ke node berikutnya
};

//FUngsi untuk pencarian
Node *linearSearch(Node *head, int key){
    Node *current = head;
    while (current != nullptr){
        if (current -> data == key) return current;
        current = current -> next; //Pindah ke node berikutnya
    }

    return nullptr; //Tidak ditemukan
}

//Prosedur untuk menambah node
void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr};

    if(!head) head = newNode;
    
    else{
        Node* temp = head; //mulai dari head
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

int main(){
    Node * head = nullptr; //inisialisasi head
    append(head, 10); append(head, 20); append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result ? "Found" : "Not Found") << endl; //condition? value_if_true : value_if_false;
    return 0;
}
```
Program ini merupakan implementasi linear search pada singly linked list menggunakan bahasa C++. Program membuat daftar berantai berisi data 10, 20, dan 30 dengan fungsi append(), kemudian melakukan pencarian data tertentu menggunakan fungsi linearSearch(). Proses pencarian dilakukan secara berurutan dari node pertama hingga terakhir, dan hasilnya akan menampilkan “Found” jika data ditemukan atau “Not Found” jika tidak ada.


## Unguided 

### 1. Binary Modifikasi

Buatlah program C++ yang mengimplementasikan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus dapat menambahkan node di akhir list, melakukan pencarian dengan menampilkan proses dan hasilnya, serta menggunakan data yang terurut secara ascending agar binary search berjalan dengan benar.

#### binarymodif.cpp

```C++
#include <iostream>
#include <iomanip>  // untuk std::hex dan std::showbase
using namespace std;

// Struktur node: menyimpan data dan pointer ke node berikutnya
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // buat node baru
    if (!head) head = newNode;                // jika list kosong, node baru jadi head
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari node terakhir
        temp->next = newNode;                 // hubungkan node terakhir ke node baru
    }
}

// Fungsi untuk menghitung panjang linked list
int getSize(Node* head) {
    int size = 0;
    for (Node* curr = head; curr; curr = curr->next) size++;
    return size;
}

// Fungsi untuk mengambil node di posisi ke-n (0-based)
Node* getNodeAt(Node* head, int index) {
    Node* curr = head;
    for (int i = 0; i < index && curr; i++)
        curr = curr->next;
    return curr;
}

// Fungsi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    int size = getSize(head);
    int left = 0;
    int right = size - 1;
    int iteration = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iteration++ << ": Mid = "
             << midNode->data << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan\n";
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    return nullptr; // jika tidak ditemukan
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";

    // Membuat linked list dengan data terurut
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        append(head, arr[i]);
        cout << arr[i];
        if (i != n - 1) cout << " -> ";
    }
    cout << " -> NULL\n";

    // Cari nilai yang ada
    int cari = 40;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    // Cari nilai yang tidak ada
    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
```
Program ini merupakan implementasi algoritma Binary Search pada Linked List menggunakan bahasa C++. Program membuat linked list berisi data terurut (10, 20, 30, 40, 50, 60), lalu melakukan pencarian elemen tertentu — misalnya 40 dan 25 — menggunakan fungsi binarySearch().

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan5_Modul5/Output/Output-binarymodif-Modul5.png)


### 2. Linear Modifikasi

Buatlah program C++ yang mengimplementasikan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus dapat menambahkan node di akhir list, melakukan pencarian dengan menampilkan proses dan hasilnya, serta menggunakan minimal 3 elemen dalam linked list.

#### linearmodif.cpp

```C++
#include <iostream>
#include <iomanip> // untuk format alamat memori (hex)
using namespace std;

// Struktur node: menyimpan data dan pointer ke node berikutnya
struct Node {
    int data;
    Node* next;
};

// Tambah node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;            // jika kosong, node baru jadi head
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari node terakhir
        temp->next = newNode;                 // hubungkan node terakhir ke node baru
    }
}

// Fungsi Linear Search
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* current = head;
    int index = 1;

    // Telusuri satu per satu node
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr; // jika tidak ditemukan
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";

    // Buat linked list
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        append(head, arr[i]);
        cout << arr[i];
        if (i != n - 1) cout << " -> ";
    }
    cout << " -> NULL\n";

    // Cari nilai yang ada
    int cari = 30;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = linearSearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    // Cari nilai yang tidak ada
    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = linearSearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
```
Program ini merupakan implementasi algoritma Linear Search pada Linked List menggunakan bahasa C++. Program membuat linked list berisi data 10, 20, 30, 40, dan 50, lalu melakukan pencarian nilai tertentu dengan menelusuri setiap node satu per satu. Selama proses pencarian, program menampilkan langkah-langkah pemeriksaan tiap node dan hasil akhir apakah data ditemukan atau tidak, beserta alamat dan isi node jika ditemukan.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan5_Modul5/Output/Output-linearmodif-Modul5.png)


## Kesimpulan
Kesimpulannya, kedua program unguided tersebut menunjukkan implementasi algoritma pencarian pada struktur data Linked List menggunakan C++, yaitu Binary Search dan Linear Search. Pada program Binary Search, data dalam linked list harus terurut agar pencarian dapat dilakukan secara efisien dengan membagi ruang pencarian menjadi dua setiap iterasi. Sedangkan pada Linear Search, pencarian dilakukan secara berurutan dari node pertama hingga node terakhir tanpa memerlukan data yang terurut. Keduanya menampilkan proses pencarian secara detail dan hasil akhir apakah elemen yang dicari ditemukan atau tidak, sehingga memperlihatkan perbedaan efisiensi dan cara kerja masing-masing algoritma dalam konteks linked list.


## Referensi
[1]Soetanto, H. (2022). Struktur Data.<br>[2]Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877.<br>[3]Mukharil Bachtiar, A. (2010). Bab Viii-Stack.