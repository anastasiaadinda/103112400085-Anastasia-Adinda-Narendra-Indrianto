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