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