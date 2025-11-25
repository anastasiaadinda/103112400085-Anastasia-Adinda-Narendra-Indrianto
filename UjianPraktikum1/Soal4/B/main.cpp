#include "QueuePengiriman.h"

// Fungsi bantu untuk membuat data Paket
Paket buat_paket(const char* resi, const char* nama, int berat, const char* tujuan) {
    Paket p;
    strcpy(p.KodeResi, resi);
    strcpy(p.NamaPengirim, nama);
    p.BeratBarang = berat;
    strcpy(p.Tujuan, tujuan);
    return p;
}

int main() {
    QueueEkspedisi Q;
        
    cout << "SKENARIO OTOMATIS SOAL NOMOR 4 (QUEUE)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "1) CREATE QUEUE:" << endl;
    createQueue(&Q);
    cout << "-----------------------------------------------------------------" << endl;

    cout << "3) ENQUEUE 5 DATA PAKET:" << endl;
    enQueue(&Q, buat_paket("123456", "Hutao", 14, "Sumeru"));
    enQueue(&Q, buat_paket("234567", "Ayaka", 10, "Fontaine"));
    enQueue(&Q, buat_paket("345678", "Bennet", 7, "Natlan"));
    enQueue(&Q, buat_paket("456789", "Furina", 16, "Liyue"));
    enQueue(&Q, buat_paket("567890", "Nefer", 6, "Inazuma"));
    cout << "-----------------------------------------------------------------" << endl;

    cout << "4) TAMPILKAN QUEUE AWAL (5 data):" << endl;
    viewQueue(Q);
    cout << "-----------------------------------------------------------------" << endl;

    cout << "5) LAKUKAN DEQUEUE 1X (Paket Hutao/Head):" << endl;
    deQueue(&Q);
    cout << "-----------------------------------------------------------------" << endl;

    cout << "6) TAMPILKAN QUEUE SETELAH DEQUEUE 1X (Sisa 4 data):" << endl;
    viewQueue(Q);
    cout << "-----------------------------------------------------------------" << endl;

    // =================================================================
    // BAGIAN B: Hitung Total Biaya Pengiriman
    // =================================================================
    cout << "\n*** BAGIAN B: HITUNG TOTAL BIAYA PENGIRIMAN ***" << endl;
    float total_biaya = TotalBiayaPengiriman(Q); // Panggil fungsi Bagian B
    float total_berat = 0.0;
    
    // Hitung total berat sisa paket untuk ditampilkan
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total_berat += Q.dataPaket[i].BeratBarang;
    }
    
    cout << fixed << setprecision(2);
    cout << "Total Berat Semua Paket Saat Ini : " << total_berat << " kg" << endl;
    cout << "Biaya per kg                       : Rp 8250.00" << endl;
    cout << "TOTAL BIAYA PENGIRIMAN             : Rp " << total_biaya << endl;
    
    return 0;
}