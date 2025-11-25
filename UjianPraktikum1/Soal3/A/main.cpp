#include "StackMahasiswa.h"

Mahasiswa buat_data(const char* nama, const char* nim, float tugas, float uts, float uas) {
    Mahasiswa mhs;
    strcpy(mhs.Nama, nama);
    strcpy(mhs.NIM, nim);
    mhs.NilaiTugas = tugas;
    mhs.NilaiUTS = uts;
    mhs.NilaiUAS = uas;
    return mhs;
}

int main() {
    StackMahasiswa stack_mhs;
    
    // 1) Create Stack
    cout << endl;
    cout << "1) CREATE STACK" << endl;
    createStack(&stack_mhs);
    cout << endl;

    // 2) Input data mahasiswa
    cout << "\n2) PUSH 6 DATA MAHASISWA:" << endl;
    Push(&stack_mhs, buat_data("Venti", "11111", 75.7, 82.1, 65.5));
    Push(&stack_mhs, buat_data("Xiao", "22222", 87.4, 88.9, 81.9));
    Push(&stack_mhs, buat_data("Kazuha", "33333", 92.3, 88.8, 82.4));
    Push(&stack_mhs, buat_data("Wanderer", "44444", 95.5, 85.5, 90.5));
    Push(&stack_mhs, buat_data("Lynette", "55555", 77.7, 65.4, 79.9));
    Push(&stack_mhs, buat_data("Chasca", "66666", 99.9, 93.6, 87.3));
    cout << endl;
    
    // 3) Tampilkan stack
    cout << "\n3) TAMPILKAN STACK AWAL:" << endl;
    TampilkanStack(stack_mhs);
    cout << endl;

    // 4) Lakukan pop sebanyak 1x
    cout << "\n4) LAKUKAN POP 1X (Chasca):" << endl;
    Pop(&stack_mhs);
    cout << endl;

    // 5) Tampilkan stack setelah pop 1x
    cout << "\n5) TAMPILKAN STACK SETELAH POP:" << endl;
    TampilkanStack(stack_mhs);
    cout << endl;

    // 6) Lakukan update data pada posisi ke 3
    cout << "\n6) LAKUKAN UPDATE DATA POSISI KE-3 (Kazuha -> Heizou):" << endl;
    Mahasiswa data_heizou = buat_data("Heizou", "77777", 99.9, 88.8, 77.7);
    Update(&stack_mhs, 3, data_heizou);
    cout << endl;
    
    // 7) Tampilkan stack yang sudah dilakukan update
    cout << "\n7) TAMPILKAN STACK SETELAH UPDATE:" << endl;
    TampilkanStack(stack_mhs);
    cout << endl;

    // 8) Lakukan searching data mahasiswa
    cout << "\n8) LAKUKAN SEARCHING DATA (Nilai Akhir 85.5 s/d 95.5):" << endl;
    Searching(stack_mhs);
    cout << endl;
    
    return 0;
}