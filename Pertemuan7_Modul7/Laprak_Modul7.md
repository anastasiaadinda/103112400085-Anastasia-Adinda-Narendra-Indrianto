# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Stack<br/>
Stack atau tumpukan adalah salah satu jenis struktur data yang menyimpan sekumpulan elemen dengan aturan LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Pada stack, proses penambahan data disebut push, sedangkan penghapusan data disebut pop, dan keduanya hanya dilakukan pada satu ujung yang disebut top atau puncak tumpukan. Stack dapat dianalogikan seperti tumpukan piring, di mana piring baru selalu diletakkan di atas dan diambil dari atas juga[1].
Struktur data ini sering digunakan dalam pemrograman untuk menyimpan data sementara, mengatur urutan eksekusi perintah, serta membantu proses rekursi dan perhitungan ekspresi aritmatika. Dengan sifatnya yang sederhana namun efisien, stack menjadi salah satu konsep dasar yang penting dalam pembelajaran algoritma dan struktur data.

### B. Komponen-komponen Stack<br/>
Komponen stack terdiri dari beberapa bagian penting yang saling berhubungan agar struktur data ini dapat berfungsi dengan baik[2]. Komponen-komponen yang membentuk stack antara lain sebagai berikut:
1. TOP adalah penunjuk (pointer atau indeks) yang menunjukkan posisi elemen paling atas pada stack. Nilai TOP akan berubah setiap kali dilakukan operasi push untuk menambah data dan pop untuk menghapus data.
2. Elemen atau Item merupakan data-data yang disimpan di dalam stack. Semua elemen disusun secara berurutan dan hanya dapat diakses dari bagian atas melalui TOP.
3. MAXSIZE adalah batas maksimum kapasitas stack, yaitu jumlah elemen terbanyak yang dapat disimpan. Komponen ini digunakan terutama pada stack yang diimplementasikan menggunakan array.
4. Struktur Penyimpanan berfungsi sebagai wadah untuk menampung elemen-elemen stack, yang umumnya berupa array atau linked list tergantung dari metode implementasinya.
5. Operasi Dasar meliputi push untuk menambahkan data, pop untuk menghapus data, isEmpty untuk memeriksa apakah stack kosong, dan isFull untuk memeriksa apakah stack sudah penuh.

### C. Operasi-operasi dalam Stack<br/>
Operasi-operasi pada stack adalah serangkaian tindakan yang dapat dilakukan untuk mengelola data dalam struktur tumpukan. Semua operasi ini mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Berikut beberapa operasi dasar yang terdapat dalam stack[3]:
1. MAKENULL(S) berfungsi untuk mengosongkan seluruh elemen pada stack sehingga stack kembali ke kondisi awal.
2. TOP(S) digunakan untuk mengambil atau melihat elemen paling atas dari stack tanpa menghapusnya.
3. POP(S) berfungsi untuk menghapus elemen yang berada di posisi paling atas stack. Operasi ini mengurangi jumlah elemen di dalam stack.
4. PUSH(x, S) digunakan untuk menambahkan elemen baru x ke bagian atas stack. Setelah operasi ini, nilai TOP akan bertambah satu.
5. EMPTY(S) berfungsi untuk memeriksa apakah stack dalam keadaan kosong atau tidak.
Semua operasi tersebut memastikan bahwa pengelolaan data dalam stack berjalan secara teratur, efisien, dan sesuai dengan konsep dasar tumpukan yang hanya memungkinkan akses pada satu ujung, yaitu bagian atas (top of stack).


## Guided 

### guided1

#### stack.h

```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack &listStack);
void searchData(stack &listStack, int data);

#endif
```
File stack.h berisi deklarasi ADT Stack berbasis linked list yang menyimpan data bertipe integer. Setiap elemen stack direpresentasikan oleh struct node yang berisi data dan pointer next, sedangkan struct stack memiliki pointer top yang menunjuk ke elemen teratas. File ini juga mendefinisikan fungsi-fungsi penting seperti inisialisasi stack, pengecekan kosong, alokasi dan dealokasi node, serta operasi dasar seperti push, pop, update, tampilan isi stack, dan pencarian data.

#### stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack &listStack){ 
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack &listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
File di atas merupakan implementasi ADT Stack menggunakan linked list dalam bahasa C++. Setiap elemen stack direpresentasikan oleh node yang menyimpan data bertipe integer dan pointer ke elemen berikutnya. Program ini menyediakan fungsi untuk membuat stack, menambah (push) dan menghapus (pop) elemen, memperbarui data berdasarkan posisi, menampilkan seluruh isi stack, serta mencari data tertentu. Stack diakses melalui pointer top, di mana elemen terakhir yang dimasukkan menjadi elemen pertama yang dihapus (prinsip LIFO).

#### main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program di atas merupakan implementasi utama untuk menguji ADT Stack berbasis linked list. Program diawali dengan pembuatan stack kosong menggunakan createStack, lalu lima node dengan nilai 1–5 dialokasikan dan dimasukkan ke stack melalui fungsi push. Setelah itu, dua elemen teratas dihapus dengan pop. Fungsi update digunakan untuk mengubah data pada posisi tertentu, sedangkan searchData mencari nilai tertentu dalam stack. Setiap tahapan ditampilkan menggunakan view, sehingga pengguna dapat melihat perubahan isi stack setelah setiap operasi dilakukan.

### guided2

#### stack.h

```C++
#ifndef STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
Header file di atas berisi deklarasi ADT Stack berbasis array statis dengan kapasitas maksimum 20 elemen (MaxEl). Stack menyimpan data bertipe int dalam array info dan menggunakan variabel top untuk menandai posisi elemen teratas. Konstanta Nil bernilai -1 menandakan bahwa stack kosong. Terdapat beberapa deklarasi fungsi penting, yaitu CreateStack untuk inisialisasi, isEmpty dan isFull untuk memeriksa kondisi stack, push dan pop untuk menambah serta menghapus elemen, printInfo untuk menampilkan isi stack, dan balikStack untuk membalik urutan elemen dalam stack.

#### stack.cpp
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
Kode di atas merupakan implementasi ADT Stack berbasis array dalam bahasa C++. Stack memiliki kapasitas maksimal 20 elemen dan menggunakan variabel top untuk menandai posisi elemen teratas. Program menyediakan operasi dasar seperti CreateStack untuk inisialisasi, push untuk menambah elemen, pop untuk menghapus elemen, serta printInfo untuk menampilkan isi stack. Selain itu, terdapat fungsi balikStack yang membalik urutan elemen dalam stack dengan memanfaatkan dua stack sementara.

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Kode di atas merupakan implementasi ADT Stack berbasis array dalam bahasa C++. Stack memiliki kapasitas maksimal 20 elemen dan menggunakan variabel top untuk menandai posisi elemen teratas. Program menyediakan operasi dasar seperti CreateStack untuk inisialisasi, push untuk menambah elemen, pop untuk menghapus elemen, serta printInfo untuk menampilkan isi stack. Selain itu, terdapat fungsi balikStack yang membalik urutan elemen dalam stack dengan memanfaatkan dua stack sementara.


## Unguided 

### 1. unguided1
Membuat ADT Stack menggunakan array dengan tipe data integer. Struktur stack terdiri dari array berukuran 20 elemen dan variabel top sebagai penanda elemen teratas. Program harus menyediakan prosedur CreateStack untuk inisialisasi, push untuk menambah data, pop untuk menghapus data, printInfo untuk menampilkan isi stack, dan balikStack untuk membalik urutan elemen stack.

#### stack.h

```C++
#ifndef STACK_H
#define STACK_H
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
Header file di atas berisi deklarasi ADT Stack berbasis array statis dengan kapasitas maksimum 20 elemen (MAX). Stack menyimpan data bertipe int dalam array info dan menggunakan variabel top untuk menandai posisi elemen teratas. Fungsi-fungsi yang dideklarasikan meliputi createStack untuk inisialisasi stack kosong, push untuk menambah elemen, pop untuk menghapus elemen teratas, printInfo untuk menampilkan isi stack, dan balikStack untuk membalik urutan elemen dalam stack.

#### stack.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top != -1) {
        push(temp, pop(S));
    }
    S = temp;
}
```
Kode di atas merupakan implementasi ADT Stack menggunakan array statis yang dideklarasikan pada file stack.h. Fungsi createStack menginisialisasi stack kosong dengan top = -1. Fungsi push menambahkan elemen baru ke posisi teratas jika stack belum penuh, sedangkan pop menghapus dan mengembalikan elemen teratas jika stack tidak kosong. Fungsi printInfo menampilkan isi stack dari elemen teratas ke terbawah. Terakhir, balikStack digunakan untuk membalik urutan elemen dalam stack dengan bantuan stack sementara (temp).

#### main.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Program ini mengimplementasikan dan menguji ADT Stack berbasis array. Di dalamnya dilakukan proses pembuatan stack kosong, penambahan elemen dengan operasi push, penghapusan elemen dengan operasi pop, serta menampilkan isi stack menggunakan printInfo. Selain itu, program juga membalik urutan elemen dalam stack dengan fungsi balikStack dan menampilkan hasilnya di layar.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan7_Modul7/Output/Output-Unguided1-Modul7.png)

### 2. unguided2

Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

#### stack.h

```C++
//Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
#ifndef STACK_H
#define STACK_H
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x); // tambahan baru

#endif
```
Header file stack.h ini mendefinisikan ADT Stack berbasis array dengan kapasitas 20 elemen. Terdapat prosedur untuk membuat, menambah, menghapus, menampilkan, dan membalik isi stack, serta tambahan prosedur pushAscending untuk menyisipkan elemen secara urut menaik.

#### stack.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top != -1) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    // Pindahkan elemen yang lebih kecil dari x ke stack sementara
    while (S.top != -1 && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari temp ke stack utama
    while (temp.top != -1) {
        push(S, pop(temp));
    }
}
```
Kode di atas merupakan implementasi lengkap ADT Stack berbasis array. Program ini menyediakan operasi dasar seperti membuat stack (createStack), menambah data (push), menghapus data (pop), menampilkan isi stack (printInfo), membalik urutan data (balikStack), serta menambah elemen secara urut menaik melalui prosedur tambahan pushAscending.

#### main.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Program di atas merupakan implementasi utama untuk menguji fungsi ADT Stack. Program membuat stack baru, lalu menambahkan elemen menggunakan prosedur pushAscending agar data tersusun menaik. Setelah semua elemen dimasukkan, isi stack ditampilkan, kemudian dibalik dengan fungsi balikStack, dan hasil akhirnya kembali ditampilkan.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan7_Modul7/Output/Output-Unguided2-Modul7.png)


### 3. unguided3

Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan
menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
tombol enter

#### stack.h

```C++
// Tambahkan prosedur getInputStream( in/out S : Stack )
#ifndef STACK_H
#define STACK_H
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S); // tambahan baru

#endif
```
Header file di atas mendefinisikan ADT Stack berbasis array dengan kapasitas maksimum 20 elemen bertipe integer. Selain operasi dasar seperti createStack, push, pop, dan balikStack, ditambahkan juga prosedur getInputStream(Stack &S) untuk menerima dan memasukkan beberapa data ke dalam stack melalui input pengguna.

#### stack.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top != -1) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

// Prosedur baru: membaca input karakter sampai ENTER
void getInputStream(Stack &S) {
    cout << "Masukkan input: ";
    char ch;
    while (true) {
        ch = cin.get(); // membaca satu karakter
        if (ch == '\n') break; // berhenti saat user tekan ENTER
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0';
            push(S, num);
        }
    }
}
```
Program di atas berisi implementasi lengkap ADT Stack berbasis array dengan berbagai operasi, termasuk createStack, push, pop, printInfo, balikStack, dan pushAscending. Tambahan prosedur baru getInputStream memungkinkan pengguna memasukkan deretan angka langsung dari keyboard; setiap digit yang diketik akan disimpan ke dalam stack sampai pengguna menekan tombol ENTER.

#### main.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Program akan menampilkan pesan sambutan, lalu meminta pengguna memasukkan deretan angka melalui keyboard. Angka-angka tersebut dimasukkan ke dalam stack menggunakan prosedur getInputStream, kemudian isi stack ditampilkan. Setelah itu, program membalik urutan stack menggunakan balikStack dan menampilkan hasil akhirnya.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan7_Modul7/Output/Output-Unguided3-Modul7.png)


## Kesimpulan
Dari ketiga soal, dapat disimpulkan bahwa program ini berfokus pada implementasi ADT Stack menggunakan array dengan berbagai pengembangan fungsional. Soal pertama membahas pembuatan dasar stack dengan operasi utama seperti push, pop, printInfo, dan balikStack. Soal kedua menambahkan prosedur pushAscending untuk menyimpan data secara terurut menaik di dalam stack. Sedangkan soal ketiga menambahkan getInputStream, yang memungkinkan pengguna memasukkan data langsung dari keyboard hingga menekan tombol Enter. Secara keseluruhan, ketiga soal ini menunjukkan pemahaman mendalam tentang konsep stack, manipulasi data, serta penerapan logika tambahan untuk memperluas fungsi dasar stack.

## Referensi
[1]Rustam, S. (2010). PERANCANGAN DAN IMPLEMENTASI PERANGKAT LUNAK PEMBELAJARAN BERBASIS MULTIMEDIA (STUDI KASUS: MATA KULIAH STRUKTUR DATA) (Doctoral dissertation, Universitas Islam Negeri Sultan Syarif Kasim Riau).<br>[2]Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. INFOKOM (Informatika & Komputer), 7(2), 15-24.<br>[3]Wahyanto, T. (2003). TA: Perancangan dan Pembuatan Program Yang Digunakan Untuk Koversi Notasi Prefix, Infix, dan Postfix Serta Simulasi Stack Dalam Struktur Data (Doctoral dissertation, STIKOM Surabaya).