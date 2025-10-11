# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Abstract Data Type (ADT)<br/>
Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan suatu konsep dalam pemrograman yang mendefinisikan struktur data beserta operasi-operasinya[1]. Dapat dilakukan pada semua data tersebut, tanpa menjelaskan secara rinci bagaimana cara implementasinya(Jusuf Wahyudi, 2013). Dengan demikian, ADT menekankan pada apa yang dapat dilakukan oleh suatu data, bukan bagaimana cara melakukannya. Konsep ini digunakan untuk menyederhanakan proses perancangan program agar lebih terstruktur, mudah dipahami, serta memudahkan proses pengembangan perangkat lunak.

#### ADT Terdapat 2 Bagian Utama
Abstract Data Type (ADT) adalah definisi dari sebuah tipe data beserta serangkaian operasi dasar yang dilakukan pada tipe tersebut. Dalam sebuah ADT yang utuh, terdapat pula invarian, constraint yang harus selalu dipenuhi, dan aksioma, aturan dasar yang berlaku pada tipe data tersebut. ADT bersifat abstrak dan statis, artinya ia mendeskripsikan bentuk dan perilaku data secara logis dan tidak masuk ke dalam detail implementasi dalam bahasa pemrograman tertentu(Tim Pengajar ITB, 2003). ADT dapat tersusun dari beberapa ADT lainnya, seperti ADT Time yang tersusun dari ADT JAM dan ADT DATE, atau ADT Line, yang tersusun dari dua ADT POINT. Dalam perancangan yang sesungguhnya, konsep ADT akan membuat proses perancangan program menjadi lebih terstruktur dan modular, serta lebih mudah untuk diuji: setiap tipe data dapat didefinisikan dan kemudian diimplementasikan secara penuh sebelum modul apa pun dapat menggunakannya[2].

### B. Fungsi Abstrack Data Type (ADT)<br/>
(Asrianda, 2020), fungsi utama ADT (Abstract Data Type) adalah untuk mengelola dan menyederhanakan data dalam proses pemrograman agar lebih terstruktur, efisien, serta mudah dipahami oleh programmer. ADT berperan penting dalam membantu proses perancangan program karena memberikan batasan yang jelas antara bagaimana data disimpan dengan bagaimana data tersebut digunakan dalam operasi tertentu. Dengan menggunakan konsep ADT, programmer dapat membuat sistem yang lebih terorganisir, di mana setiap bagian dari program memiliki tanggung jawab dan fungsi yang spesifik[3]. Hal ini tidak hanya memudahkan dalam proses pengembangan, tetapi juga mempercepat tahap perbaikan atau pembaruan kode di masa mendatang. Selain itu, ADT juga berfungsi sebagai sarana untuk mewujudkan prinsip abstraksi dan modularitas dalam pemrograman. Artinya, programmer dapat fokus pada apa yang dilakukan oleh suatu struktur data tanpa perlu memahami detail teknis dari implementasinya. Hal ini menjadikan program lebih fleksibel, mudah diuji, serta dapat digunakan kembali (reusable) dalam berbagai proyek lain.

### C. Tujuan Abstract Data Type<br/>
Tujuan dari ADT (Abstract Data Type) adalah untuk mengoptimalkan pengelolaan data dalam pemrograman agar lebih efisien, terstruktur, dan mudah dipelihara. ADT berfungsi sebagai dasar dalam pengembangan sistem yang kompleks dengan menyediakan cara untuk mendefinisikan data serta operasi yang dapat dilakukan terhadapnya tanpa harus menampilkan detail implementasi secara langsung(Moch. Syahrir, Dosen Universitas Bumigora). Dengan adanya ADT, proses pemrograman menjadi lebih terarah karena setiap komponen memiliki tanggung jawab yang jelas. Programmer dapat fokus pada bagaimana data digunakan dan dimanipulasi tanpa perlu mengetahui bagaimana data tersebut disimpan di dalam memori. Hal ini tidak hanya mempercepat proses pengembangan program, tetapi juga mengurangi risiko kesalahan yang terjadi akibat pengelolaan data yang tidak konsisten[4].


## Guided 

### 1. Modularitas 

#### Modularitas (mahasiswa.h)

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

// Definisi Tipe (Struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// Deklarasi Primitif (Fungsi)
void inputMhs(struct mahasiswa &m);
float rata2(struct mahasiswa m);

#endif
```
Program mahasiswa.h berfungsi untuk mendefinisikan ADT Mahasiswa menggunakan bahasa C++. Struktur mahasiswa memiliki tiga atribut yaitu NIM, nilai1, dan nilai2. Selain itu, terdapat dua fungsi utama: inputMhs() untuk menginput data mahasiswa dan rata2() untuk menghitung nilai rata-rata dari dua nilai yang dimiliki mahasiswa.

#### Modularitas (mahasiswa.cpp)

```C++
#include<iostream>
#include"mahasiswa.h"

using namespace std;

//Realisasi dari fungsi inputMhs
void inputMhs(mahasiswa & m){
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari fungsi rata2
float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2)/2;
}
```
Program ini merupakan realisasi dari fungsi-fungsi yang telah dideklarasikan dalam ADT Mahasiswa.
Fungsi inputMhs() digunakan untuk menerima input dari pengguna berupa NIM, nilai1, dan nilai2, kemudian menyimpannya ke dalam struktur mahasiswa. Sedangkan rata2() digunakan untuk menghitung serta mengembalikan nilai rata-rata dari dua nilai yang telah dimasukkan

#### Modularitas (main.cpp)

```C++
#include<iostream>
#include"mahasiswa.h"
#include<cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");

    return 0;
}
```
Program ini merupakan bagian utama (main program) yang memanggil dan menjalankan fungsi-fungsi dari ADT Mahasiswa.
Pada program ini, dideklarasikan sebuah variabel bertipe mahasiswa untuk menyimpan data yang diinput.
Fungsi inputMhs() digunakan untuk menerima data mahasiswa berupa NIM dan dua nilai, kemudian hasilnya diolah oleh fungsi rata2() untuk menghitung dan menampilkan nilai rata-rata ke layar. Program diakhiri dengan perintah system("pause") agar hasil keluaran dapat terlihat sebelum program ditutup.


### 2. Struct

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2; 
};

void inputMhs(mahasiswa &m){
    cout << "Masukan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukan nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari fungsi rata2
float rata2(mahasiswa m){
    return float (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; //Pemanggilan Struct
    inputMhs(mhs); //Pemanggilan Prosedur
    cout << "Rata-rata: " << rata2(mhs);
    return 0;
}
```
Struktur mahasiswa digunakan untuk menyimpan data berupa nama, nilai1, dan nilai2.
Fungsi inputMhs() berfungsi untuk menerima input dari pengguna, sedangkan fungsi rata2() digunakan untuk menghitung rata-rata dari dua nilai yang telah dimasukkan. Pada fungsi main(), program memanggil kedua fungsi tersebut secara berurutan dan menampilkan hasil rata-rata nilai mahasiswa ke layar.


## Unguided 

### 1. Soal Unguided 1

Program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus 0.3 *uts+0.4 *uas+0.3 *tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah melebihi batas maksimal (10)!" << endl;
        return 0;
    }

    cout << "\n=== Input Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama\t: ";

        cin.ignore();

        getline(cin, mhs[i].nama);
        cout << "NIM\t: ";
        getline(cin, mhs[i].nim);
        cout << "Nilai UTS\t: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS\t: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas\t: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    cout << "-------------------------------------------------------------\n";
    cout << "No\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t" << mhs[i].nama << "\t\t" 
             << mhs[i].nilaiAkhir << endl;
    }
    cout << "-------------------------------------------------------------\n";

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan3_Modul3/Output/Output_Unguided1-1_Modul3.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan3_Modul3/Output/Output_Unguided1-2_Modul3.png)

Struktur Mahasiswa digunakan untuk menyimpan data mahasiswa yang terdiri dari nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir. Fungsi hitungNilaiAkhir() berfungsi untuk menghitung nilai akhir berdasarkan bobot masing-masing komponen, yaitu 30% UTS, 40% UAS, dan 30% tugas. Program meminta pengguna untuk memasukkan jumlah mahasiswa (maksimal 10 orang) serta data masing-masing mahasiswa. Selanjutnya, program akan menampilkan tabel berisi NIM, nama, dan nilai akhir dari setiap mahasiswa.


### 2. Soal Unguided 2

Program ini dibuat untuk menerapkan konsep Abstract Data Type (ADT) pada entitas Pelajaran.
Dalam file pelajaran.h, didefinisikan struktur pelajaran yang memiliki dua atribut, yaitu namaMapel dan kodeMapel.
Fungsi create_pelajaran() digunakan untuk membuat objek pelajaran baru berdasarkan nama dan kode yang diberikan, sedangkan tampil_pelajaran() berfungsi untuk menampilkan data pelajaran ke layar. Pada file main.cpp, program menguji implementasi ADT tersebut dengan membuat data pelajaran bernama “Struktur Data” dan kode “STD”, kemudian menampilkan hasilnya ke layar.

#### Unguided 2 (pelajaran.h)

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

#### Unguided 2 (pelajaran.cpp)

```C++
#include <iostream>
#include "pelajaran.h" 
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;                
    p.namaMapel = namapel;       
    p.kodeMapel = kodepel;       
    return p;                    
}

// Prosedur untuk menampilkan pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

```

#### Unguided 2 (main.cpp)

```C++
#include <iostream>
#include "pelajaran.h" 
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan3_Modul3/Output/Output_Unguided2-1_Modul3.png)

File pelajaran.h berisi deklarasi struktur pelajaran dengan atribut namaMapel dan kodeMapel, serta deklarasi dua fungsi: create_pelajaran() untuk membuat data pelajaran dan tampil_pelajaran() untuk menampilkannya.
Pada file pelajaran.cpp, kedua fungsi tersebut diimplementasikan — fungsi create_pelajaran() menginisialisasi data pelajaran, sedangkan tampil_pelajaran() menampilkan nama dan kode pelajaran ke layar.
File main.cpp berfungsi sebagai program utama untuk menguji ADT dengan membuat objek pelajaran “Struktur Data” berkode “STD” dan menampilkannya ke layar.


### 3. Soal Unguided 3

Program ini menggunakan dua array 2D berukuran 3x3 dan dua pointer integer. Program memiliki fungsi untuk menampilkan isi array 2D, menukar elemen pada dua array di posisi tertentu, serta menukar nilai yang ditunjuk oleh dua pointer. Tujuan program ini adalah untuk memahami cara kerja array dua dimensi, penggunaan pointer, dan penerapan fungsi dalam pengolahan data di C++.

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemen(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "\nArray B:" << endl;
    tampilArray(B);

    // Menukar elemen di posisi baris ke-1 dan kolom ke-2 (ingat indeks 0-based)
    int baris = 1;
    int kolom = 2;
    tukarElemen(A, B, baris, kolom);

    cout << "\nSetelah elemen posisi (" << baris << "," << kolom << ") ditukar:" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "\nArray B:" << endl;
    tampilArray(B);

    int x = 10, y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "Nilai x = " << *ptr1 << ", y = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "Nilai x = " << *ptr1 << ", y = " << *ptr2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan3_Modul3/Output/Output_Unguided3-1_Modul3.png)

Program ini menggunakan dua array 2D berukuran 3x3 dan dua pointer integer. Fungsi tampilArray() digunakan untuk menampilkan isi array 2D ke layar, tukarElemen() digunakan untuk menukar elemen dari dua array pada posisi baris dan kolom tertentu, sedangkan tukarPointer() berfungsi menukar nilai yang ditunjuk oleh dua pointer. Program ini menunjukkan cara kerja manipulasi data menggunakan array dua dimensi serta penggunaan pointer untuk pertukaran nilai dalam bahasa C++.


## Kesimpulan
Dari ketiga program yang dibuat, dapat disimpulkan bahwa penerapan struktur data dan ADT (Abstract Data Type) mempermudah pengelolaan data agar lebih terstruktur dan efisien.
Program pertama mengelola data mahasiswa menggunakan struct dan fungsi perhitungan nilai akhir, program kedua menerapkan konsep ADT pada entitas pelajaran, sedangkan program ketiga menunjukkan penggunaan array 2D dan pointer untuk manipulasi data.
Secara keseluruhan, ketiga program ini membantu memahami dasar pemrograman terstruktur melalui penerapan fungsi, array, pointer, dan ADT dalam bahasa C++.


## Referensi
[1]Wahyudi, J., Berlian, B., & Rosdiana, R. (2013). Instruksi bahasa pemrograman ADT (Abstract Data Type) pada virus dan loop batch. Jurnal Media Infotama, 9(2).<br>[2]Rachman, D. A. Perkenalan Abstrak Data Type.<br>[3]Fitrianti, U., & Ula, M. (2017). Implementasi algoritma levenshtein distance dan algoritma knuth morris pratt pada aplikasi asmaul husna berbasis android. Sisfo: Jurnal Ilmiah Sistem Informasi, 1(2).<br>[4]Syahrir, M., & Fatimatuzzahra, F. (2020). Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer, 20(1), 149-158.