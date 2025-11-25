#include "QueuePengiriman.h"

void createQueue(QueueEkspedisi *Q) {
    Q->Head = -1;
    Q->Tail = -1;
    cout << "Queue berhasil dibuat. Head=" << Q->Head << ", Tail=" << Q->Tail << endl;
}

bool isEmpty(QueueEkspedisi Q) {
    return Q.Tail == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1;
}

void enQueue(QueueEkspedisi *Q, Paket data_baru) {
    if (isFull(*Q)) {
        cout << "Queue penuh! EnQueue gagal." << endl;
    } else {
        if (isEmpty(*Q)) {
            Q->Head = 0; 
        }
        Q->Tail++;
        Q->dataPaket[Q->Tail] = data_baru;
        cout << "Berhasil EnQueue paket Resi: " << data_baru.KodeResi << " (" << data_baru.NamaPengirim << ")" << endl;
    }
}

void deQueue(QueueEkspedisi *Q) {
    if (isEmpty(*Q)) {
        cout << "Queue kosong! DeQueue gagal." << endl;
    } else {
        cout << "Berhasil DeQueue paket Resi: " << Q->dataPaket[Q->Head].KodeResi << " (" << Q->dataPaket[Q->Head].NamaPengirim << ")" << endl;
        
        for (int i = Q->Head; i < Q->Tail; i++) {
            Q->dataPaket[i] = Q->dataPaket[i+1];
        }
        
        Q->Tail--;
        
        if (Q->Tail == -1) {
            Q->Head = -1;
        }
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "\nQueue saat ini KOSONG." << endl;
        return;
    }

    cout << "\n--- ISI QUEUE EKSPEDISI --- (Head=" << Q.Head << ", Tail=" << Q.Tail << ")" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << left << setw(5) << "POS"
         << setw(15) << "KODE RESI" 
         << setw(15) << "PENGIRIM" 
         << setw(15) << "BERAT (kg)" 
         << setw(15) << "TUJUAN" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << left << setw(5) << i + 1 
             << setw(15) << Q.dataPaket[i].KodeResi
             << setw(15) << Q.dataPaket[i].NamaPengirim
             << setw(15) << Q.dataPaket[i].BeratBarang
             << setw(15) << Q.dataPaket[i].Tujuan << endl;
    }
    cout << "----------------------------------------------------------------------------------" << endl;
}

// =================================================================
// BAGIAN B: IMPLEMENTASI TotalBiayaPengiriman()
// =================================================================

float TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        return 0.0;
    }

    float total_berat = 0.0;
    const float BIAYA_PER_KG = 8250.0;

    // Menghitung total berat dari semua paket yang masih ada di queue (Head sampai Tail)
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total_berat += Q.dataPaket[i].BeratBarang;
    }

    // Menghitung total biaya
    float total_biaya = total_berat * BIAYA_PER_KG;
    return total_biaya;
}