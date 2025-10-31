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

    return 0;
}
