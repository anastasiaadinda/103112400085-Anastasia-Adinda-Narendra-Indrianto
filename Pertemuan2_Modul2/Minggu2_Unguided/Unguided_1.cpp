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