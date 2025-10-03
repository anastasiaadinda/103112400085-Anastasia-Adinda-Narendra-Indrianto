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