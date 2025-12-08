# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Tree<br/>
Struktur data tree (pohon) adalah pemodelan khas yang digunakan untuk menggambarkan hierarki hubungan elemen. Dalam sistem informasi ini, tree memodelkan Upacara Yadnya untuk mengetahui keterkaitannya dan membuat standar umum properti upacara. Properti dasar meliputi kelompok yadnya, deskripsi, waktu pelaksanaan, dan tingkatan upacara. Cabang tree berakar pada tingkatan upacara, yang kemudian mengarah ke detail seperti pemuput, tempat pelaksanaan, dan tata cara. Konsep penggunaan tree untuk memodelkan hal serupa (bebantenan/upacara) diungkapkan oleh Anak Agung K. Oka Sudana[1].

### B. Kelebihan & Kekurangan Rekursif<br/>
Rekursif memungkinkan program menjadi lebih singkat dan mudah dibaca. Dalam beberapa kasus, seperti pengurutan, pencarian, dan pemecahan masalah kombinatorial, fungsi rekursif dapat bekerja lebih efisien dan cepat dibandingkan proses iteratif. Namun, rekursif memiliki kekurangan yaitu memakan memori lebih besar karena memerlukan sejumlah ruang memori untuk penyimpanan setiap bagian dari dirinya(I Made Wahyu Saputra, A.A.). Kekurangan serius lainnya adalah risiko rekursif tidak dapat berhenti, yang dapat menyebabkan memori terpakai habis dan program menjadi hang. Selain itu, rekursif juga bisa sulit di-debug jika terjadi kesalahan berulang[2].

### C. Operasi-operasi dalam Tree<br/>
Operasi Dasar pada Tree (Pohon)[3]:
1. Penyisipan (Insertion)
Proses menambahkan node (simpul) baru ke dalam struktur tree sambil mempertahankan properti hierarki dan urutan yang ditentukan (misalnya, nilai yang lebih kecil di kiri, nilai yang lebih besar di kanan untuk BST).
2. Penghapusan (Deletion)
Proses menghapus node tertentu dari tree. Operasi ini adalah yang paling kompleks karena harus memastikan tree tetap terstruktur dengan benar setelah node dihapus (misalnya, menata ulang anak-anak dari node yang dihapus).
3. Pencarian (Search)
Proses menemukan node yang berisi nilai data tertentu. Dalam tree terurut (search tree), operasi ini sangat efisien karena navigasi dilakukan secara hierarkis, mengabaikan sebagian besar node yang tidak relevan.
4. Penelusuran (Traversal)
Proses mengunjungi setiap node dalam tree secara sistematis, biasanya untuk menampilkan atau memproses data. Ada tiga metode utama:
5. In-order: Mengunjungi node dari kiri ke akar, lalu ke kanan (biasanya menghasilkan data terurut).
6. Pre-order: Mengunjungi akar terlebih dahulu, lalu kiri, kemudian kanan.
7. Post-order: Mengunjungi kiri dan kanan terlebih dahulu, baru kemudian akar.
8. Pembuatan (Creation)
Proses membuat struktur tree baru, yang biasanya dimulai dengan pembuatan node akar (root).

## Guided 

### BST

#### BST1.h

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

//alokasi & insert
address newNode(infotype x);
address insertNode(address root, infotype x);

// Traversal
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

//Utilities
int countNodes(address root);
int treeDepth(address root);

#endif
```
Program ini mendefinisikan struktur data Binary Search Tree menggunakan linked list, lengkap dengan fungsi untuk membuat tree, menambah node, melakukan traversal, serta menghitung jumlah node dan kedalaman tree. File header ini menjadi dasar operasi BST untuk pengolahan data bertipe integer.

#### BST1.cpp

```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
Program ini mengimplementasikan Binary Search Tree dengan operasi membuat tree, menambah node, traversal, serta menghitung jumlah node dan kedalaman tree menggunakan fungsi rekursif.

#### main.cpp

```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini membuat sebuah Binary Search Tree, kemudian memasukkan beberapa nilai ke dalam tree, menampilkan hasil traversal (InOrder, PreOrder, PostOrder), serta menghitung jumlah node dan kedalaman tree. Program menggunakan fungsi‐fungsi BST dari header untuk menjalankan proses secara rekursif.

### BST2

#### BST2.h

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

//alokasi & insert
address newNode(infotype x);
address insertNode(address root, infotype x);

// Traversal
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

//Utilities
int countNodes(address root);
int treeDepth(address root);

// FUNCTION PROSEDUR BARU
// Searching
void searchByData(address root, infotype x);

//mostleft & mostright
address mostleft(address root);
address mostright(address root);

//delete
bool deleteNode(address & root, infotype x);
void deleteTree(address & root);

#endif
```
Header ini berisi struktur Node serta deklarasi fungsi dasar untuk membuat, memasukkan, menelusuri, mencari, dan menghapus data pada Binary Search Tree.

#### BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
Kode di atas berisi fungsi‐fungsi BST untuk membuat tree, insert, traversal, mencari data beserta parent/sibling/child, mencari nilai terkecil/terbesar, dan menghapus node termasuk semua kasus delete.

#### main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostleft(root)->info << endl;
    cout << "Node mostright : " << mostright(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;

    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program main ini melakukan insert beberapa data ke dalam BST, menampilkan traversal dan informasi tree, mencari data tertentu, menampilkan node terkecil dan terbesar, menghapus node berdasarkan input user, lalu menampilkan hasil akhir serta menghapus seluruh tree.

### Rekursif

#### rekursif_pangkat2.cpp
```C++
#include <iostream>
using namespace std;

int pangkat_2(int x) { //  adalah pangkatnya
    if (x == 0) { // basis
        return 1;
    } else if (x > 0){ //rekurens
        return 2 * pangkat_2(x - 1);
    }
    return 1; // perbaikan: menghilangkan warning kuning
}

int main() {
    cout << " === REKURSIF PANGKAT 2 === " << endl;

    int x;
    cout << "Masukan nilai x: ";
    cin >> x;
    cout << endl;

    cout << " Nilai 2 pangkat " << x << " adalah " << pangkat_2(x) << endl;

    return 0;
}
```
Program ini menghitung nilai 2^x menggunakan fungsi rekursif yang memanggil dirinya sendiri hingga mencapai nilai dasar, kemudian menampilkan hasil pangkat dua dari angka yang dimasukkan user.

## Unguided 

### 1. Soal1
Buatlah ADT Binary Search Tree menggunakan Linked list

#### bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// fungsi & prosedur
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```
Header ini mendefinisikan struktur node dan deklarasi fungsi untuk membuat, menyisipkan, mencari, dan menampilkan data pada Binary Search Tree, sehingga operasi dasar BST dapat dipanggil dari file program utama.

#### bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } else {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(root->info == x){
        return root;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
```
Program ini mengimplementasikan operasi dasar pada Binary Search Tree berupa alokasi node, insert, pencarian node, dan pencetakan data secara inorder menggunakan konsep rekursif. Struktur ini memungkinkan data disimpan dan diakses secara terurut sesuai aturan BST.

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main(){
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    printInorder(root);

    return 0;
}
```
Program ini membuat sebuah Binary Search Tree, kemudian memasukkan beberapa nilai ke dalam tree dan menampilkan hasilnya secara inorder sehingga data tercetak dalam urutan terurut. Program juga mencetak “Hello world!” di awal eksekusi.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan10_Modul10/Output/Output-Soal1-Modul10.png)

### 2. Soal2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi yang diminta.

#### bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```
Program ini membuat dan mengolah Binary Search Tree untuk menyimpan data, menelusuri, serta menghitung jumlah node, total nilai, dan kedalaman pohon.

#### bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } else if(x > root->info){
            insertNode(root->right, x);
        }
    }
}


address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(root->info == x){
        return root;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start){
    if(root == Nil) return start;
    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

int hitungKedalaman(address root, int start){
    if(root == Nil) return start;
    int left = hitungKedalaman(root->left, start + 1);
    int right = hitungKedalaman(root->right, start + 1);
    return (left > right ? left : right);
}
```
Program ini membuat Binary Search Tree, lalu menampilkan isi tree secara inorder serta menghitung kedalaman, jumlah node, dan total nilai yang tersimpan. Program juga menunjukkan bagaimana penyisipan dan traversal dilakukan di BST.

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    printInorder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}
```
Program ini membangun Binary Search Tree dari beberapa angka, lalu mencetak urutan inorder, kedalaman tree, jumlah node, dan total semua nilai dalam tree.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan10_Modul10/Output/Output-Soal2-Modul10.png)


### 3. Soal3
Print tree secara pre-order dan post-order.

#### bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

// traversal
void printInorder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

// hitung
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```
Program ini mendefinisikan struktur dan fungsi‐fungsi dasar Binary Search Tree untuk menyimpan data, traversal (inorder, preorder, postorder), pencarian node, serta perhitungan jumlah node, total nilai, dan kedalaman tree. Semua operasi dilakukan secara rekursif melalui pointer address.

#### bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// insert tanpa duplikasi
void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } else if(x > root->info){
            insertNode(root->right, x);
        }
        // jika x == root->info, abaikan (tidak simpan duplikat)
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(root->info == x){
        return root;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

// Traversal: InOrder
void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Traversal: PreOrder
void printPreOrder(address root){
    if(root != Nil){
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Traversal: PostOrder
void printPostOrder(address root){
    if(root != Nil){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

// hitung jumlah node
int hitungJumlahNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// hitung total isi node
int hitungTotalInfo(address root, int start){
    if(root == Nil) return start;
    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

// kedalaman maksimum
int hitungKedalaman(address root, int start){
    if(root == Nil) return start;
    int left = hitungKedalaman(root->left, start + 1);
    int right = hitungKedalaman(root->right, start + 1);
    return (left > right ? left : right);
}
```
Program ini mengolah Binary Search Tree tanpa duplikasi, menyediakan fungsi insert, pencarian, traversal (inorder, preorder, postorder), serta perhitungan jumlah node, total nilai, dan kedalaman maksimum secara rekursif.

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {

    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,2);
    insertNode(root,1);
    insertNode(root,3);
    insertNode(root,5);
    insertNode(root,7);

    cout << "InOrder : ";
    printInorder(root);
    cout << endl;

    cout << "PreOrder : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root,0)+1 << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root,0) << endl;

    return 0;
}
```
Program ini membuat dan menelusuri Binary Search Tree lalu menampilkan traversal serta menghitung kedalaman, jumlah node, dan total nilainya.

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan10_Modul10/Output/Output-Soal3-Modul10.png)


## Kesimpulan
Dari ketiga soal, dapat disimpulkan bahwa Binary Search Tree (BST) dapat dibangun dengan struktur node berbasis pointer, kemudian dilakukan penyisipan data secara terurut, serta ditelusuri menggunakan inorder, preorder, dan postorder. Selain itu, BST juga memungkinkan dilakukan perhitungan jumlah node, total nilai informasi, dan kedalaman pohon secara rekursif sehingga pemrosesan data menjadi lebih sistematis dan efisien.

## Referensi
[1]Saputra, I. M. W., Sudana, A. K. O., & Sukarsa, I. M. (2014). Implementasi Struktur Data tree pada Sistem Informasi Upacara yadnya Berbasis Android. Merpati, 2(3).<br>[2]Rahmawati, E., Medina, P., & Azhari, D. S. (2024). Rekursif Dalam Pemrograman Teori Dan Praktek. Innovative: Journal Of Social Science Research, 4(4), 5622-5630.<br>[3]Latifah, F. (2016). Penerapan Algorithma Pohon untuk Operasi Pengolahan dan Penyimpanan Data Dalam Teknik Pemrograman (Kajian Algorithma Pohon pada Teknik Pemrograman). Jurnal Techno Nusa Mandiri, 13(2), 111-120.