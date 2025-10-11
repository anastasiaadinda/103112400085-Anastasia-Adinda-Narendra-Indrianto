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
