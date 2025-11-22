# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Queue<br/>
Queue merupakan salah satu fitur manajemen bandwidth pada router Mikrotik yang berfungsi untuk mengatur dan membatasi distribusi bandwidth upload dan download pada jaringan komputer. Terdapat dua jenis metode queue yang umum digunakan, yaitu Simple Queue dan Queue Tree. Simple Queue merupakan metode termudah dengan konfigurasi sederhana yang menggunakan parameter dasar berupa target (IP address, network address, atau interface) dan max-limit untuk memberikan batas maksimal bandwidth[1]. Sementara Queue Tree merupakan konfigurasi yang lebih kompleks karena dapat disesuaikan berdasarkan protokol, nomor port, atau pengelompokan alamat IP dengan menggunakan marking packet melalui fitur mangle. Kedua metode ini bertujuan untuk mengoptimalkan kinerja jaringan internet dengan mendistribusikan bandwidth secara merata sehingga akses menjadi lebih stabil dan cepat, terutama untuk mencegah penggunaan bandwidth berlebihan oleh satu pengguna yang dapat mengganggu stabilitas koneksi pengguna lainnya.

### B. Komponen-komponen Queue<br/>
Komponen queue terdiri dari beberapa bagian penting yang bekerja saling terkait agar proses antrian data dapat dilakukan dengan benar sesuai prinsip FIFO (First In First Out)[2]. Komponen-komponen yang membentuk queue antara lain sebagai berikut:
1. Head / Front adalah penunjuk indeks yang menunjukkan posisi elemen pertama di dalam antrian. Nilai head berubah setiap kali dilakukan operasi dequeue karena elemen paling depan selalu dikeluarkan terlebih dahulu.
2. Tail / Rear adalah penunjuk indeks posisi elemen terakhir dalam antrian. Nilai tail akan bertambah setiap kali dilakukan operasi enqueue untuk menambah data ke bagian belakang queue.
3. Elemen atau Data (info) merupakan data yang disimpan dalam antrian. Dalam implementasi praktikum ini berupa tipe integer, namun dalam konteks jaringan seperti pada metode PCQ dapat berupa paket data atau traffic pengguna.
4. Storage atau Media Penyimpanan adalah wadah untuk menyimpan seluruh elemen queue, yang pada implementasi kode menggunakan array berukuran tetap (static array).
5. Ukuran Maksimum (MAX) adalah batas kapasitas queue yang menentukan jumlah elemen terbanyak yang dapat ditampung, misalnya maksimum 5 elemen pada implementasi program. Komponen ini penting untuk mencegah overflow ketika queue penuh.
6. Operasi Dasar Queue terdiri dari enqueue untuk menambahkan data, dequeue untuk menghapus data, isEmpty untuk mengecek apakah queue kosong, isFull untuk mengecek apakah queue penuh, dan printInfo untuk menampilkan isi queue serta posisi head dan tail.

### C. Operasi-operasi dalam Queue<br/>
Operasi-operasi pada queue merupakan serangkaian tindakan untuk mengelola data dalam struktur antrian yang mengikuti prinsip FIFO (First In First Out), di mana elemen pertama yang masuk adalah elemen pertama yang keluar[3]. Berikut beberapa operasi dasar yang terdapat dalam queue[3]:
1. CreateQueue(Q) berfungsi untuk menginisialisasi queue agar kembali pada kondisi awal, yaitu penunjuk head dan tail diisi nilai -1 sebagai tanda bahwa queue masih kosong dan siap digunakan.
2. Enqueue(Q, x) digunakan untuk menambahkan elemen baru x ke posisi belakang (tail). Jika queue awalnya kosong maka head dan tail diatur ke 0. Jika queue belum penuh, tail akan bergeser satu indeks sebelum data dimasukkan.
3. Dequeue(Q) merupakan operasi penghapusan elemen paling depan dari queue (posisi head). Setelah elemen dikeluarkan, head akan bergeser satu langkah. Jika setelah penghapusan hanya tersisa satu elemen, maka head dan tail akan kembali menjadi -1 menandakan queue kosong.
4. IsEmpty(Q) merupakan fungsi untuk memeriksa apakah queue dalam keadaan kosong atau tidak. Queue dianggap kosong jika nilai head dan tail sama-sama bernilai -1.
5. IsFull(Q) merupakan fungsi untuk mengecek apakah queue sudah berada pada kapasitas maksimum sehingga tidak bisa lagi menambah data baru. Pada queue dengan array berukuran tetap, kondisi penuh terjadi ketika tail berada pada indeks maksimum dan tidak ada ruang kosong tersisa.
6. PrintInfo(Q) digunakan untuk menampilkan kondisi queue saat ini berupa posisi head, tail, dan seluruh elemen yang sedang berada di dalam antrian sesuai urutan FIFO.


## Guided 

### guided1

#### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;  
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
Program ini merupakan implementasi struktur data Queue berbasis Linked List di C++, yang mendukung operasi dasar seperti membuat antrian, mengecek kondisi kosong, menambah elemen (enqueue), menghapus elemen (dequeue), memperbarui, mencari, dan menampilkan data dalam antrian sesuai konsep FIFO.

#### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;        // ← DIBENARKAN (yang kurang)
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        if(Q.head == Nil){
            Q.tail = Nil;
        }

        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;

        nodeHapus->next = Nil;
        dealokasi(nodeHapus);   // ← dipindah agar tidak akses data setelah delete
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
Kode ini mengimplementasikan struktur data Queue menggunakan Linked List dengan prinsip FIFO. Program menyediakan operasi dasar seperti membuat queue, mengecek kondisi kosong, menambah elemen (enqueue), menghapus elemen (dequeue), memperbarui data, mencari data, dan menampilkan isi queue.

#### main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah dequeue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
Program ini membuat sebuah queue, lalu menambahkan lima data ke dalam antrian menggunakan operasi enQueue. Setelah itu, program menghapus dua elemen terdepan menggunakan deQueue, melakukan update nilai pada beberapa posisi dalam queue, menampilkan isi queue di setiap tahap, dan melakukan pencarian data untuk memastikan fungsi searchData berjalan dengan baik.

### guided2

#### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
Program ini mendefinisikan struktur data Queue berbasis array dengan ukuran maksimum tertentu (MAX_QUEUE = 5). Fungsi-fungsi yang disediakan meliputi inisialisasi queue, pengecekan kondisi kosong dan penuh, menambah data ke antrian (enqueue), menghapus data dari antrian (dequeue), dan menampilkan isi antrian.

#### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
Kode ini mengimplementasikan operasi dasar struktur data Queue menggunakan array dengan teknik circular queue. Fungsi yang tersedia meliputi membuat antrian, mengecek kondisi kosong atau penuh, menambah data (enqueue), menghapus data (dequeue), dan menampilkan isi antrian.

#### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

//Fungsi utama program
int main(){
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 Elemen " << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << " Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen " << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << " Elemen keluar: " << dequeue(Q) << endl;
    cout << " Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini mendemonstrasikan penggunaan queue berbasis array dengan melakukan beberapa operasi, yaitu menambahkan elemen (enqueue), menghapus elemen (dequeue), dan menampilkan isi queue setelah setiap perubahan. Program ini menunjukkan cara kerja antrian dengan konsep FIFO pada struktur data circular queue.

## Unguided 

### 1. unguided1
Buat ADT Queue menggunakan array dengan mekanisme head diam dan tail bergerak.
Implementasi dalam queue.h dan queue.cpp, lalu uji dengan main yang diberikan.

#### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
Header file ini mendefinisikan struktur data Queue menggunakan array dengan kapasitas maksimum (MAX = 5). Disediakan fungsi‐fungsi untuk menginisialisasi queue, mengecek apakah queue kosong atau penuh, menambah elemen (enqueue), menghapus elemen (dequeue), serta menampilkan isi queue (printInfo) sesuai prinsip FIFO.

#### queue.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue FULL" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue EMPTY" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```
Kode ini mengimplementasikan operasi dasar struktur data Queue menggunakan array dengan pendekatan linear queue. Fungsi yang tersedia meliputi membuat queue, mengecek kondisi kosong atau penuh, menambahkan elemen ke bagian belakang (enqueue), menghapus elemen dari bagian depan (dequeue) dengan proses shifting, serta menampilkan isi queue.

#### main.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T    | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
Program ini melakukan demonstrasi penggunaan queue berbasis array dengan melakukan serangkaian operasi seperti enqueue, dequeue, dan menampilkan isi antrian menggunakan printInfo. Setiap perubahan pada queue akan langsung ditampilkan sehingga memperlihatkan cara kerja antrian FIFO secara bertahap selama program dijalankan.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan8_Modul8/Output/Output-Unguided1-Modul8.png)

### 2. unguided2

Implementasikan ADT Queue dengan mekanisme head bergerak dan tail bergerak (masih menggunakan array).

#### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
Header file ini berisi definisi struktur Queue berbasis array dengan ukuran maksimum tetap (MAX = 5), serta deklarasi fungsi untuk operasi queue seperti membuat antrian, pengecekan kosong/penuh, enqueue, dequeue, dan mencetak isi antrian sesuai konsep FIFO.

#### queue.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue FULL" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue EMPTY" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```
Kode ini mengimplementasikan struktur data Queue berbasis array dengan metode linear queue. Operasi yang tersedia yaitu membuat antrian, memeriksa kondisi kosong atau penuh, menambahkan elemen ke belakang antrian (enqueue), menghapus elemen dari depan antrian (dequeue), serta menampilkan isi antrian (printInfo) sesuai konsep FIFO.

#### main.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T    | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
Program ini menjalankan demonstrasi operasi queue menggunakan array. Program menambahkan (enqueue) dan menghapus (dequeue) elemen secara bertahap sambil menampilkan kondisi queue setelah setiap operasi untuk menunjukkan cara kerja antrian dengan prinsip FIFO.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan8_Modul8/Output/Output-Unguided2-Modul8.png)


### 3. unguided3

Implementasikan ADT Queue dengan mekanisme circular queue, yaitu head dan tail berputar menggunakan operasi modulo.

#### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX 5
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
Header file ini berisi deklarasi struktur Queue berbasis array dengan ukuran maksimum 5, serta fungsi‐fungsi dasar untuk operasi antrian seperti inisialisasi, pengecekan kosong/penuh, enqueue, dequeue, dan menampilkan isi antrian sesuai prinsip FIFO.

#### queue.cpp

```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Queue penuh" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype temp = -1;
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        temp = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
    return temp;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "   | ";
    if (isEmpty(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX;
        }
    }
    cout << endl;
}
```
Kode ini mengimplementasikan operasi queue berbasis array dengan teknik circular queue. Fungsi yang tersedia mencakup membuat queue, mengecek kondisi kosong atau penuh, menambahkan elemen ke belakang (enqueue), menghapus elemen dari depan (dequeue), dan menampilkan seluruh isi queue (printInfo) sesuai konsep FIFO.

#### main.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
Program ini menjalankan operasi‐operasi queue berbasis circular array secara berurutan seperti enqueue dan dequeue. Setiap perubahan antrian langsung ditampilkan melalui fungsi printInfo sehingga pengguna dapat melihat pergerakan data dalam queue sesuai prinsip FIFO.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan8_Modul8/Output/Output-Unguided3-Modul8.png)


## Kesimpulan
Ketiga implementasi queue menggunakan array memiliki mekanisme berbeda dalam mengelola posisi head dan tail. Pada alternatif pertama, head tetap di posisi awal dan hanya tail yang bergerak sehingga membutuhkan shifting saat dequeue dan kurang efisien dalam pemanfaatan ruang. Alternatif kedua memperbaiki hal tersebut dengan menggerakkan head dan tail, tetapi tetap memiliki keterbatasan karena ruang kosong di awal array tidak dapat digunakan kembali ketika tail mencapai batas akhir. Alternatif ketiga merupakan solusi paling optimal dengan menerapkan circular queue, di mana head dan tail berputar secara melingkar menggunakan operasi modulo sehingga seluruh kapasitas array dapat dimanfaatkan secara efisien tanpa shifting.

## Referensi
[1]Santoso, J. D. (2020). Analisis Perbandingan Metode Queue Pada Mikrotik. Jurnal Pseudocode, 1.<br>[2]Kosasih, S. (2014). Pengalokasian Bandwith Secara Otomatis Menggunakan Metode Per Connection Queue. SNIJA, 29, 30.<br>[3]Nurhayati, S. (2013). Queue.