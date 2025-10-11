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
