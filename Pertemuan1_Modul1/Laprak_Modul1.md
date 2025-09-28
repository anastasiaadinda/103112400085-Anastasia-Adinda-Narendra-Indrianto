# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Anastasia Adinda Narendra Indrianto - 103112400085</p>

## Dasar Teori

### A. Bahasa Pemrograman C++<br/>
C++ adalah bahasa pemrograman hasil pengembangan dari bahasa C dengan menambahkan konsep pemrograman berorientasi objek (OOP), seperti class, objek, enkapsulasi, dan pewarisan. Bahasa ini pertama kali diperkenalkan oleh Bjarne Stroustrup pada tahun 1979 di Bell Labs sebagai perluasan dari bahasa C untuk menggabungkan efisiensi pemrograman prosedural dengan fleksibilitas OOP [1]. Fungsi C++ adalah untuk membangun perangkat lunak yang efisien, terstruktur, dan mudah dikelola, sehingga banyak digunakan dalam pengembangan aplikasi maupun sistem berskala besar.
#### 1. Operator C++
Menurut Luh Joni Erawati Dewi, dalam bahasa pemrograman C++ terdapat berbagai operator yang digunakan untuk melakukan operasi pada data, seperti operator aritmatika, percabangan, perulangan, array, dan fungsi. Operator-operator ini memudahkan programmer dalam melakukan perhitungan maupun pengendalian alur program [3]. Secara keseluruhan, operator pada C++ berfungsi sebagai sarana utama untuk memudahkan proses perhitungan dan pengaturan logika program sehingga pengembangan aplikasi dapat dilakukan secara lebih sistematis dan efisien.
#### 2. Kelebihan dan Kekurangan C++
Menurut Eko Budi Setiawan, S.Kom, setiap bahasa pemrograman memiliki kelebihan dan kekurangan;
Kelebihan C++: memiliki banyak operator untuk mengolah data, mendukung pemrograman terstruktur dan OOP, sintaks lebih dekat dengan bahasa manusia, serta memiliki kecepatan eksekusi yang tinggi.
Kekurangan C++: sintaks cukup kompleks sehingga dapat membingungkan pemula, serta bersifat case sensitive sehingga membutuhkan ketelitian tinggi dalam penulisan kode [4]. Secara keseluruhan, C++ unggul karena cepat dan mendukung OOP, namun cukup sulit dipelajari bagi pemula karena sintaksnya kompleks dan sensitif.

### B. Code::Blocks IDE<br/>
Code::Blocks adalah sebuah IDE (Integrated Development Environment) yang bersifat gratis dan open-source, digunakan untuk menulis, mengompilasi, dan menjalankan program. Menurut Andy Prasetyo, ST., M.Kom, Code::Blocks merupakan perangkat lunak yang dibuat oleh komunitas Linux/IGS untuk memudahkan proses pengembangan aplikasi [2]. Hubungannya dengan C++ adalah Code::Blocks berfungsi sebagai alat bantu utama dalam pembuatan program berbasis C++, karena menyediakan compiler, editor, dan debugger dalam satu paket. Dengan IDE ini, pengembang dapat menulis kode C++ secara lebih terstruktur, efisien, dan minim kesalahan.
#### 1. Efektivitas Penggunaan
Berdasarkan penelitian oleh Ariapuri & Prasetyo, penggunaan Code Blocks berbasis C++ pada sistem kasir terbukti lebih efektif, efisien, dan minim kesalahan dibandingkan perhitungan manual, karena perhitungan dilakukan otomatis melalui program [1].

## Guided 

### 1. Input Angka

```C++
#include<iostream>
using namespace std;

int main(){
    int angka;
    cout << "masukan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukan " << angka << endl;
    return 0;
}
```
Program dibuat untuk memasukan input dari user berupa angka dengan tipe data integer.

### 2. Operasi Hitung

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukan angka 1 :";
    cin >> angka1;
    cout << "masukan angka 2 :";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;
}
```
Program dibuat dengan tujuan membuat operasi hitung penjumlahan, pengurangan, perkalian dan pembagian. User meminta memasukan dua input berupa angka atau integer.

### 3. Menu Operasi Hitung

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2, pilihan;    
    cout << " Masukan angka 1 : ";
    cin >> angka1;
    cout << " Masukan angka 2 : ";
    cin >> angka2;

    cout << "MENU" << endl;
    cout << " 1, Penjumlahan" << endl;
    cout << " 2, Pengurangan" << endl;
    cout << " Masukan pilihan : ";
    cin >> pilihan;

    switch(pilihan){
    case 1:
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    cout << endl;
    break;

    case 2:
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << endl;
    break;
    default :
    cout << "Pilihan salah " << endl;
}
    return 0;
}
```
Program dibuat dengan tujuan operasi hitung dengan membuat menu yang dibuat untuk user memasukan input yang diinginkan dari penjumlahan atau pengurangan.

### 4. Perbandingan Lebih Dari dan Sama Besar

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << " Masukan angka 1 : ";
    cin >> angka1;
    cout << " Masukan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " Kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " Lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " Sama dengan " << angka2 << endl;
    } else if (angka1 != angka2){
        cout << "Angka berbeda " << endl;
    }

}
```
Program ini membandingkan dua angka yang dimasukkan user, lalu menampilkan apakah angka pertama lebih kecil, lebih besar, sama dengan, atau berbeda dari angka kedua.

### 5. Input Data Nilai Siswa

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        char nama[3];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++) {
        cout << "Masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while (j < MAX) {
        cout << "Nama siswa : "<< siswa[j].nama << ", Nilai " << siswa[j].nilai << endl;
        j++;

    }
    return 0;
}
```
Program ini menginput data tiga siswa berupa nama dan nilai, kemudian menampilkan kembali nama dan nilai siswa tersebut.

### 6. Perulangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;    
    cout << " Masukan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 20;
    while (j > angka1){
        cout << j << " - ";
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka1);
    
    return 0;
}
```
Program ini meminta satu angka dari pengguna, lalu menampilkan deretan angka dengan tiga jenis perulangan: for dari nol sampai sebelum angka input, while dari 20 turun hingga lebih besar dari angka input, dan do-while yang mencetak angka 10 minimal sekali.


## Unguided 

### 1. Soal Unguided 1

 Program yang menerima input-an dua buah bilangan betipe float kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian

```C++
#include<iostream>
using namespace std;

int main(){
    float a, b;

    cout << "Masukan Angka 1: ";
    cin >> a;
    cout << "Masukan Angka 2: ";
    cin >> b;

    cout << "\nHasil Operasi Hitungan: " << endl;
    cout << " Penjumlahan: " << a + b << endl;
    cout << " Pengurangan: " << a - b << endl;
    cout << " Perkalian : " << a * b << endl;

    if (b != 0){
        cout << " Pembagian: " << a / b << endl;
    } else {
        cout << "Pembagian: Angka tidak bisa dibagi nol " << endl;
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan1_Modul1/Output_Unguided_Modul1/Output-Unguided-1.png)

Program ini meminta dua bilangan bertipe float dari user, lalu menghitung hasil penjumlahan, pengurangan, perkalian, dan pembagian. Jika bilangan kedua bernilai nol, program menampilkan pesan bahwa pembagian tidak bisa dilakukan.


### 2. Soal Unguided 2

Program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

string satuan(int n) {
    switch (n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
    }
    return "";
}

string angkaKeTulisan(int n) {
    if (n < 10) {
        return satuan(n);
    } else if (n == 10) {
        return "sepuluh";
    } else if (n == 11) {
        return "sebelas";
    } else if (n < 20) {
        return satuan(n % 10) + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan(puluh) + " puluh";
        if (sisa > 0) hasil += " " + satuan(sisa);
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "Angka harus antara 0 sampai 100";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 sampai 100" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan1_Modul1/Output_Unguided_Modul1/Output-Unguided-2.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan1_Modul1/Output_Unguided_Modul1/Output-Unguided-2-1.png)

##### Output 3
![Screenshot Output Unguided 2_3](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan1_Modul1/Output_Unguided_Modul1/Output-Unguided-2-2.png)

Program ini meminta input bilangan bulat 0–100 dari pengguna, lalu mengubahnya menjadi bentuk tulisan. Program menangani kasus khusus seperti 10, 11, dan 100, serta menggunakan aturan “belas” untuk 12–19 dan “puluh” untuk 20–99. Hasil akhirnya ditampilkan dalam format angka diikuti dengan tulisannya.


### 3. Soal Unguided 3

Program yang menerima input sebuah bilangan bulat n, lalu mencetak pola segitiga terbalik dengan angka dan tanda * 

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = n; i >= 0; i--) {
        // spasi di awal baris (supaya rata miring kanan)
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // 2 spasi
        }

        // angka menurun (kiri bintang)
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang tengah
        cout << "*";

        // angka menaik (kanan bintang)
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/anastasiaadinda/103112400085-Anastasia-Adinda-Narendra-Indrianto/blob/main/Pertemuan1_Modul1/Output_Unguided_Modul1/Output-Unguided-3.png)

Program ini menerima sebuah angka sebagai input, lalu mencetak pola segitiga terbalik. Di tiap baris, angka dicetak menurun di sebelah kiri tanda * dan menaik di sebelah kanannya, dengan spasi di awal baris untuk membentuk segitiga.


## Kesimpulan
Ketiga program C++ yang telah dibuat memiliki tujuan berbeda namun sama-sama melatih logika pemrograman dasar. Program pertama digunakan untuk melakukan operasi aritmatika sederhana (penjumlahan, pengurangan, perkalian, dan pembagian) pada dua bilangan bertipe float dengan pengecekan pembagian nol. 
Program kedua mengubah bilangan bulat dari 0 hingga 100 menjadi bentuk tulisan dalam bahasa Indonesia dengan menangani kasus khusus seperti sepuluh, sebelas, belas, puluh, dan seratus. 
Program ketiga menghasilkan pola segitiga terbalik menggunakan angka dan tanda *, dengan logika perulangan dan pengaturan spasi agar bentuk segitiga tercetak rapi. Secara keseluruhan, ketiga program ini memperlihatkan penerapan konsep input-output, percabangan, dan perulangan dalam C++.


## Referensi
[1]Ariapuri, N., & Prasetyo, A. (2018). Efektivitas Aplikasi Kasir Menggunakan Code Blocks Berbasis C++. Teknik Informatika Politeknik Purbaya.<br>[2]Andaria, A. C., Ardhana, V. Y. P., Nugroho, A. Y., Prastyo, D., Bakhtiar, M. Y., Martawireja, A. R. H., ... & Fatich, E. V. L. N. (2025). PENGENALAN BAHASA PEMPROGRAMAN UNTUK PEMULA.<br>[3]Dewi, L. J. E. (2010). Media Pembelajaran Bahasa Pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan, 7(1).<br>[4]BAB, I. Pengenalan Bahasa C+.