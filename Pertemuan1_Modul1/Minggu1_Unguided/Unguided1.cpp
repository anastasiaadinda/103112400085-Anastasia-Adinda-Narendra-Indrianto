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