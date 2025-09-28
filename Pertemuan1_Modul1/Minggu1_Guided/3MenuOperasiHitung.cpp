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