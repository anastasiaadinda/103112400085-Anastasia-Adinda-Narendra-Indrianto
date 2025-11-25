#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

const int MAX = 6;

struct Mahasiswa {
    char Nama[50];
    char NIM[10];
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

void createStack(StackMahasiswa *MHS);
bool isEmpty(StackMahasiswa MHS);
bool isFull(StackMahasiswa MHS);
float HitungNilaiAkhir(Mahasiswa mhs);
void Push(StackMahasiswa *MHS, Mahasiswa data_baru);
void Pop(StackMahasiswa *MHS);
void Update(StackMahasiswa *MHS, int posisi, Mahasiswa data_update);
void TampilkanStack(StackMahasiswa MHS);
void Searching(StackMahasiswa MHS);

// BAGIAN B: Deklarasi Prosedur MaxNilaiAkhir
void MaxNilaiAkhir(StackMahasiswa MHS); 

#endif