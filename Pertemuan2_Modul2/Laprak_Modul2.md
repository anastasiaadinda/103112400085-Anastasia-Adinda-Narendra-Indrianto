# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Pengertian Array<br/>
Array adalah suatu struktur data yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama, di mana elemen-elemen tersebut tersusun secara sekuensial dalam memori komputer. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal, dengan karakteristik utama yaitu bersifat homogen , statis, dan dapat diakses secara acak(A. S. Putra)[1]. Fungsi array adalah untuk menyimpan dan mengelola kumpulan data dengan tipe yang sama secara terstruktur dan efisien, sehingga memudahkan programmer dalam melakukan operasi pemrosesan data dan menjadikan program secara keseluruhan lebih sederhana(O. M. Febriani dan A. S. Putra).

#### Jenis-jenis Array
Array adalah sebuah tipe data bentukan atau terstruktur yang terdiri dari sejumlah komponen dengan tipe yang sama. Array dapat dikategorikan berdasarkan dimensinya menjadi beberapa jenis[2](Uce Indahyanti, M.Kom):
1. Array Berdimensi Satu (One-Dimensional Array)
Array berdimensi satu mewakili bentuk suatu vektor, yaitu kumpulan elemen-elemen identik yang tersusun dalam satu baris. Elemen-elemen di dalamnya boleh berbeda nilai meskipun tipe datanya sama.
2. Array Berdimensi Dua (Two-Dimensional Array)
Array berdimensi dua mewakili bentuk dari suatu matriks atau tabel, yang terdiri dari beberapa baris dan beberapa kolom dengan elemen bertipe sama.
3. Array Berdimensi Tiga (Three-Dimensional Array)
Array berdimensi tiga mewakili bentuk suatu ruang, digunakan untuk mengelola data dalam bentuk tiga dimensi atau tiga sisi.
4. Array Bertipe Terstruktur (Record/Struct)
Array juga dapat menyimpan sejumlah elemen bertipe terstruktur (rekaman/record). Record disusun oleh satu atau lebih field, dimana tiap field menyimpan data dari tipe dasar tertentu atau tipe bentukan.
Secara keseluruhan, array berfungsi sebagai struktur data yang memungkinkan penyimpanan sementara untuk data-data bertipe sama di dalam memori, yang selanjutnya dapat dimanipulasi atau diproses lebih lanjut dalam program[2].

### B. Pengertian dan Fungsi Pointer<br/>
Pointer adalah suatu variabel penunjuk yang berisi alamat pada suatu lokasi memori tertentu. Pointer tidak berisi nilai dari sebuah variabel yang telah dideklarasikan, melainkan berisi suatu alamat memori[3](M. Taufik Dwi Putra, dkk., M.Kom (Dosen Tekkom UPI)). Fungsi Pointer:
1. Mengakses alamat memori - Dengan menggunakan pointer, dimungkinkan untuk mendapatkan atau mengubah isi dari memori yang ditunjuk.
2. Meningkatkan performa - Penggunaan pointer akan meningkatkan performa secara signifikan dikarenakan tidak ada proses pengalokasian alamat memori baru.
3. Efisiensi memori - Meskipun penggunaannya lebih sulit dibandingkan tanpa menggunakan pointer, pointer lebih efisien karena tidak membuat alokasi memori baru.

#### Hubungan Array dengan Alamat Memori
Pointer menyimpan alamat memori dari variabel lain, sehingga pointer tidak menyimpan nilai data secara langsung, tetapi menyimpan lokasi (alamat) dimana data tersebut berada di dalam memori komputer[4]. Hubungan pointer dengan alamat(D. M Janah (Fakultas Komputer)):
1. Pointer bukan berisi data - Variabel pointer sebenarnya bukan berisi data, melainkan berisi alamat dari suatu data.
2. Pointer menunjuk lokasi data - Secara singkat pointer artinya menunjuk ke suatu lokasi data di memori.
3. Pengaksesan tidak langsung - Satu-satunya cara untuk mengakses variabel dinamis adalah dengan menggunakan pointer, karena pada saat kita mengakses record kita tidak tahu dimana record tersebut secara eksak diletakkan di dalam memori.
4. Sistem mengatur lokasi - Dengan menggunakan pointer kita membiarkan sistem komputer mengatur letak record tersebut ketika diperlukan.

### C. Pengertian Prosedur dan Function C++<br/>
Fungsi merupakan blok program yang melakukan suatu aksi tertentu berdasarkan input yang diterima dan mengembalikan sebuah nilai ketika deklarasinya dipanggil dalam sebuah program. Fungsi dapat dipanggil atau digunakan di dalam blok kode yang sama maupun di blok kode program utama[5](U. Indahyanti, M.Kom., dkk. (2020).):
Karakteristik Fungsi:
1. Wajib mengembalikan nilai keluaran menggunakan perintah return
2. Nilai yang dikembalikan harus memiliki tipe data yang sama dengan tipe data fungsi itu sendiri
3. Proses pencetakan hasil dilakukan di program utama saat pemanggilan fungsi

Prosedur adalah blok program yang bisa mengembalikan atau tidak mengembalikan nilai hasil, berbeda dengan fungsi yang wajib mengembalikan nilai. Prosedur dalam C++ menggunakan kata kunci void sebagai tipe kembalian.
Karakteristik Prosedur(U. Indahyanti, M.Kom., dkk. (2020).):[5]
1. Tidak wajib mengembalikan nilai (menggunakan keyword void)
2. Proses pencetakan hasil berada dalam blok subrutinnya sendiri
3. Dipanggil namanya di dalam program utama


## Guided 

### 1. Array Pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //Pointer yg menunjukan elemn pertama array

    //Mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i + 1 << " menggunakan pointer: " << *(ptr + i) << endl;
    }

    //Mengakses elemen array menggunakan indeks
    for( int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
Program tersebut menampilkan elemen array dengan dua cara, yaitu menggunakan pointer dan menggunakan indeks.


### 2. Pointer

```C++
#include<iostream>
using namespace std;

void ubahNilai(int * ptr){
    *ptr = 20; //Mengubah nilai yang ditunjuk oleh pointer
}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(&x); //Mengirimkan alamat memori x ke fungsi
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Program tersebut menunjukkan penggunaan pointer untuk mengubah nilai variabel melalui fungsi, di mana nilai awal x adalah 10 lalu diubah menjadi 20 setelah dipanggil dengan pointer.


### 3. Refrensi

```C++
#include<iostream>
using namespace std;

void ubahNilai(int & ref){
    ref = 20; //mengubah nilai melalui refrensi

}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(x); //mengirimkan refrensi ke x
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Program ini mendemonstrasikan penggunaan referensi untuk mengubah nilai variabel, di mana nilai awal x adalah 10 lalu berubah menjadi 20 setelah dipanggil melalui fungsi.


### 4. Function Prosedur

```C++
#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan: " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini menerima input array, mencari nilai terbesar, lalu menampilkan hasil penjumlahan dan perkalian semua elemennya.


## Unguided 

### 1. Soal Unguided 1

 Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan kurangMatriks()untuk pengurangan, dan kaliMatriks() untuk perkalian.

```C++
#include <iostream>
using namespace std;

const int N = 3;

int matriksA[N][N] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int matriksB[N][N] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

void jumlahMatriks() {
    int hasil[N][N];
    cout << "\nHasil Penjumlahan Matriks A + B:\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}


void kurangMatriks() {
    int hasil[N][N];
    cout << "\nHasil Pengurangan Matriks A - B:\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}


void kaliMatriks() {
    int hasil[N][N] = {0};
    cout << "\nHasil Perkalian Matriks A x B:\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {
    int pilihan;
    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                jumlahMatriks();
                break;
            case 2:
                kurangMatriks();
                break;
            case 3:
                kaliMatriks();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan2_Modul2/Output_Modul2/Output_Unguided1-1_Modul2.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan2_Modul2/Output_Modul2/Output_Unguided1-2_Modul2.png)

Program tersebut merupakan aplikasi sederhana operasi matriks berordo 3x3. Terdapat dua matriks (matriksA dan matriksB) yang sudah diinisialisasi nilainya. Melalui menu, pengguna dapat memilih untuk melakukan penjumlahan, pengurangan, atau perkalian matriks. Hasil operasi ditampilkan dalam bentuk matriks baru di layar, sedangkan opsi keluar akan menghentikan program.


### 2. Soal Unguided 2

Program ini menghitung luas dan keliling persegi panjang menggunakan pointer, lalu mengubah nilai panjang dan lebar melalui pointer untuk menghitung ulang hasilnya.

```C++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel
    int panjang = 10, lebar = 5, luas = 0, keliling = 0;

    // Deklarasi pointer
    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;


    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan2_Modul2/Output_Modul2/Output_Unguided2-1_Modul2.png)

Program ini menghitung luas dan keliling persegi panjang dengan menggunakan pointer untuk mengakses nilai panjang dan lebar. Awalnya, panjang dan lebar diatur masing-masing 10 dan 5, lalu hasil perhitungannya ditampilkan. Selanjutnya, nilai panjang dan lebar diubah melalui pointer menjadi 12 dan 6, kemudian luas dan keliling dihitung ulang dan hasilnya ditampilkan, sehingga program menunjukkan bagaimana pointer dapat digunakan untuk mengubah nilai variabel secara langsung.


## Kesimpulan
Kedua program ini mengajarkan konsep penting dalam pemrograman C++. Program pertama memperlihatkan penggunaan prosedur untuk melakukan operasi matriks seperti penjumlahan, pengurangan, dan perkalian, serta bagaimana menampilkan hasilnya melalui menu interaktif. Program kedua menunjukkan penggunaan pointer untuk mengakses dan mengubah nilai variabel secara langsung, serta menghitung ulang luas dan keliling persegi panjang, sehingga memperkuat pemahaman tentang manipulasi data menggunakan pointer.


## Referensi
[1]Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.<br>[2]Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146.<br>[3]Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023). BELAJAR PEMROGRAMAN LANJUT DENGAN C++.<br>[4]Janah, D. M. (2019). DINAMIS POINTER.<br>[5]Saptadi, A. H., & Sari, D. W. (2012). Analisis algoritma insertion sort, merge sort dan implementasinya dalam bahasa pemrograman c++. Jurnal Infotel, 4(2), 10-17.