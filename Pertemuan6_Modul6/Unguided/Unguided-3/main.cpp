#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    infotype x;
    int n = 4; // contoh input 4 kendaraan

    for (int i = 0; i < n; i++) {
        cout << "\nmasukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        // cek duplikasi nopol
        if (isExist(L, x.nopol)) {
            cout << "\nnomor polisi sudah terdaftar\n";
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    // Tampilkan hasil akhir
    printInfo(L);

    // Tambahan supaya daftar kendaraan ditampilkan
    // Cari elemen berdasarkan nomor polisi
    infotype cari;
    cout << "\n\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);
    if (hasil != nullptr) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << cari.nopol << " tidak ditemukan.\n";
    }

    // ================================
    // Tambahan: Hapus data kendaraan
    // ================================
    string hapusNopol;
    cout << "\n\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address P = L.First;

    while (P != nullptr && P->info.nopol != hapusNopol) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Data dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n";
    }

    // Tampilkan list setelah penghapusan
    printInfo(L);

    return 0;
}
