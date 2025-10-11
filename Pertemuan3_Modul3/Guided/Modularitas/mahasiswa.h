#ifndef MAHASISWA_H
#define MAHASISWA_H

// Definisi Tipe (Struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// Deklarasi Primitif (Fungsi)
void inputMhs(struct mahasiswa &m);
float rata2(struct mahasiswa m);

#endif
