# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Graph<br/>
Graf adalah struktur data yang digunakan untuk menggambarkan hubungan atau relasi antar objek dari sebuah koleksi objek tertentu1. Secara matematis, graf didefinisikan sebagai pasangan himpunan G = (V, E), di mana V merupakan himpunan tidak kosong dari simpul-simpul (vertices atau nodes) dan E adalah himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul tersebut[1]. Dalam representasi visualnya, graf biasanya ditampilkan sebagai kumpulan titik yang melambangkan simpul dan garis yang melambangkan sisi, yang secara keseluruhan berfungsi untuk memvisualisasikan data beserta keterkaitannya.

### B. Komponen dan Operasi dalam Graph<br/>
Komponen Utama
- Simpul (Vertex/Node): Objek atau titik dalam koleksi.
- Sisi (Edge/Arc): Garis yang menghubungkan sepasang simpul.
- Busur (Arc): Sebutan khusus untuk sisi pada graf berarah yang memiliki titik asal dan tujuan.
Operasi Dasar[2]
- Inisialisasi (Init): Graph() digunakan untuk membuat objek graf baru dan menyiapkan struktur data Adjacency Map menggunakan HashMap.
- Tambah Sisi (Edge): addEdge(v1, v2) berfungsi menambahkan hubungan antar simpul. Operasi ini otomatis menambahkan simpul jika belum ada dalam graf.
- Informasi/Cetak: Meskipun fungsi print khusus tidak dirinci kodenya, graf menyediakan operasi size() untuk jumlah simpul dan getEdgeCount() untuk menghitung total sisi guna melihat struktur internalnya.

### C. Kelebihan dan Kekurangan Graph<br/>
Graf adalah struktur data yang menggambarkan hubungan antar objek menggunakan kumpulan simpul (titik) dan sisi (garis). Berikut adalah ringkasan komponen, operasi, serta kelebihan dan kekurangannya[3]:
- Komponen & Operasi: Graf terdiri dari simpul sebagai objek dan sisi sebagai penghubungnya. Untuk mengelolanya, terdapat operasi inisialisasi untuk membuat graf baru, operasi addEdge untuk menambah hubungan antar titik, serta fungsi untuk menghitung jumlah simpul dan sisi yang ada.
- Kelebihan: Penggunaan model daftar (adjacency list) sangat hemat memori karena hanya menyimpan hubungan yang benar-benar ada. Sementara itu, model tabel (adjacency matrix) sangat cepat dalam mengecek hubungan antar dua titik karena data bisa langsung diakses melalui indeksnya.
- Kekurangan: Model daftar sulit digunakan jika kita ingin menyimpan informasi tambahan seperti jarak atau beban pada garis penghubungnya. Di sisi lain, model tabel sangat boros tempat jika jumlah garis penghubungnya sedikit karena komputer tetap dipaksa menyimpan banyak data kosong.

## Guided 

#### graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {        // Tambahkan definisi lengkap ElmEdge
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

// Prototypes
void createGraph(Graph & G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph & G, infoGraph X);
void connectNode(Graph & G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
Program ini mengimplementasikan ADT Graph tidak berarah menggunakan linked list dalam bahasa C++.
Graph dapat menyimpan node, menghubungkan antar node, dan menampilkan hubungan antar node.

#### graph_edge.cpp

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```
Kode ini berfungsi untuk mencari node tertentu dalam graph dan menghubungkan dua node dengan sebuah edge.
Fungsi connectNode menambahkan sisi dari node awal ke node tujuan jika kedua node ditemukan.

#### graph_init.cpp

```C++
#include "graph.h"

void createGraph(Graph & G){
    G.first = NULL;
}

adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph & G, infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
Kode ini berfungsi untuk membuat graph kosong, mengalokasikan node baru, dan menambahkan node ke dalam graph.
Node disisipkan di akhir linked list graph dengan nilai info dan status awal belum dikunjungi.

#### graph_print.cpp

```C++
#include "graph.h"
#include <iostream>
using namespace std;

void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```
Kode ini berfungsi untuk menampilkan isi graph dengan mencetak setiap node beserta node-node yang terhubung dengannya.
Traversal dilakukan melalui linked list node dan edge untuk menunjukkan hubungan antar node.

#### main.cpp

```C++
#include <iostream>
#include "graph.h"
using namespace std;

int main(){
    Graph G;
    createGraph(G);

    // Menambahkan node A,B,C,D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph: " << endl;
    printGraph(G);

    return 0;
}
```
Program utama ini membuat sebuah graph, menambahkan beberapa node, lalu menghubungkan node-node tersebut.
Hasil akhir graph ditampilkan ke layar untuk menunjukkan hubungan antar node.



## Unguided 

### Graph
1. Buatlah ADT Graph tidak berarah pada file graph.h sesuai struktur yang diberikan, kemudian implementasikan pada graph.cpp dan uji program pada main.cpp.
2. Buatlah prosedur penelusuran Depth First Search (DFS) untuk menampilkan hasil traversal graph.
3. Buatlah prosedur penelusuran Breadth First Search (BFS) untuk menampilkan hasil traversal graph.

#### graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
Program ini mendefinisikan ADT Graph tidak berarah menggunakan linked list dengan dukungan penelusuran DFS dan BFS.
Graph dapat menyimpan node, menghubungkan antar node, serta menampilkan struktur dan hasil traversal graph.

#### graph.cpp

```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = G.first;
    G.first = P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    adrNode queue[50];
    int front = 0, rear = 0;

    N->visited = 1;
    queue[rear++] = N;

    while (front < rear) {
        adrNode P = queue[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                queue[rear++] = E->Node;
            }
            E = E->Next;
        }
    }
}
```
Program ini mengimplementasikan ADT Graph tidak berarah lengkap dengan operasi pembuatan graph, penambahan node, penghubungan node, dan penampilan isi graph.
Selain itu, program menyediakan penelusuran DFS dan BFS untuk menampilkan urutan kunjungan node pada graph.

#### main.cpp

```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'E'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'F'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'G'));
    ConnectNode(FindNode(G,'D'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'E'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'F'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'G'), FindNode(G,'H'));

    cout << "Adjacency List:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, FindNode(G,'A'));

    // Reset visited
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "\nBFS dari A: ";
    PrintBFS(G, FindNode(G,'A'));

    return 0;
}
```
Program ini mengimplementasikan ADT Graph tidak berarah lengkap dengan operasi pembuatan graph, penambahan node, penghubungan node, dan penampilan isi graph.
Selain itu, program menyediakan penelusuran DFS dan BFS untuk menampilkan urutan kunjungan node pada graph.

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1-1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan12_Modul14/Output/Output-Guided-Modul14.png)

## Kesimpulan
Kesimpulannya, program-program di atas berhasil mengimplementasikan ADT Graph tidak berarah menggunakan struktur linked list yang memungkinkan pengelolaan node dan hubungan antar node secara terstruktur. Selain operasi dasar graph, program ini juga mampu melakukan penelusuran DFS dan BFS untuk menampilkan urutan kunjungan node, sehingga memudahkan pemahaman struktur dan alur traversal pada graph.

## Referensi
[1]Anggara, F. D. (2009). Studi dan Implementasi Struktur Data Graf. Jurnal Sekolah Teknik Elektro dan Informatika Institut Teknologi Bandung, Bandung.<br>[2]Adilah, I. (2018). Efisiensi komputasi pada aplikasi penjadwalan matakuliah dengan pengurangan looping dan penggunaan struktur data arraylist dan graph (Doctoral dissertation, Universitas Islam Negeri Maulana Malik Ibrahim)<br>[3]Wicaksono, N., Sarwosri, S., & Sunaryono, D. (2018). Rancang Bangun Web Kustom Menggunakan Open Graph Protokol pada Studi Kasus Web Jurusan Teknik Informatika. Jurnal Teknik ITS, 7(1), A214-A218.