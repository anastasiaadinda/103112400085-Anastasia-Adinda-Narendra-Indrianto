#include "StackMahasiswa.h"

void createStack(StackMahasiswa *MHS) {
    MHS->Top = -1;
    cout << "Stack berhasil dibuat. Top = " << MHS->Top << endl;
}

bool isEmpty(StackMahasiswa MHS) {
    return MHS.Top == -1;
}

bool isFull(StackMahasiswa MHS) {
    return MHS.Top == MAX - 1;
}

float HitungNilaiAkhir(Mahasiswa mhs) {
    return (0.20 * mhs.NilaiTugas) + (0.40 * mhs.NilaiUTS) + (0.40 * mhs.NilaiUAS);
}

void Push(StackMahasiswa *MHS, Mahasiswa data_baru) {
    if (isFull(*MHS)) {
        cout << "Stack penuh! Push gagal." << endl;
    } else {
        MHS->Top++;
        MHS->dataMahasiswa[MHS->Top] = data_baru;
        cout << "Berhasil Push data " << data_baru.Nama << endl;
    }
}

void Pop(StackMahasiswa *MHS) {
    if (isEmpty(*MHS)) {
        cout << "Stack kosong! Pop gagal." << endl;
    } else {
        cout << "Berhasil Pop data " << MHS->dataMahasiswa[MHS->Top].Nama << endl;
        MHS->Top--;
    }
}

void Update(StackMahasiswa *MHS, int posisi, Mahasiswa data_update) {
    int index = posisi - 1; 

    if (posisi < 1 || posisi > MHS->Top + 1) {
        cout << "Posisi " << posisi << " tidak ada atau tidak valid untuk diupdate." << endl;
    } else {
        MHS->dataMahasiswa[index] = data_update;
        cout << "Data pada posisi ke-" << posisi << " berhasil diupdate menjadi " << data_update.Nama << endl;
    }
}

void TampilkanStack(StackMahasiswa MHS) {
    if (isEmpty(MHS)) {
        cout << "\nStack saat ini KOSONG." << endl;
        return;
    }

    cout << "\n--- ISI STACK MAHASISWA --- (Top = " << MHS.Top << ")" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << left << setw(5) << "POS"
         << setw(15) << "NAMA" 
         << setw(10) << "NIM" 
         << setw(10) << "TUGAS" 
         << setw(10) << "UTS" 
         << setw(10) << "UAS" 
         << setw(10) << "AKHIR" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int i = 0; i <= MHS.Top; i++) {
        float nilai_akhir = HitungNilaiAkhir(MHS.dataMahasiswa[i]);
        cout << fixed << setprecision(1);
        cout << left << setw(5) << i + 1 
             << setw(15) << MHS.dataMahasiswa[i].Nama 
             << setw(10) << MHS.dataMahasiswa[i].NIM 
             << setw(10) << MHS.dataMahasiswa[i].NilaiTugas 
             << setw(10) << MHS.dataMahasiswa[i].NilaiUTS 
             << setw(10) << MHS.dataMahasiswa[i].NilaiUAS 
             << setw(10) << nilai_akhir << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

void Searching(StackMahasiswa MHS) {
    float batas_bawah = 85.5;
    float batas_atas = 95.5;
    bool ditemukan = false;

    cout << "\n--- HASIL SEARCHING (Nilai Akhir " << batas_bawah << " s/d " << batas_atas << ") ---" << endl;
    
    for (int i = 0; i <= MHS.Top; i++) {
        float nilai_akhir = HitungNilaiAkhir(MHS.dataMahasiswa[i]);

        if (nilai_akhir >= batas_bawah && nilai_akhir <= batas_atas) {
            cout << "Ditemukan di Posisi ke-" << i + 1 << ": " 
                 << MHS.dataMahasiswa[i].Nama << " (Nilai Akhir: " << fixed << setprecision(1) << nilai_akhir << ")" << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada data yang ditemukan dalam rentang nilai tersebut." << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}