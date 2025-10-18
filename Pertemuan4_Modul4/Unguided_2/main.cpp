#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    // Membuat linked list: 9 -> 12 -> 8 -> 0 -> 2
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // Hapus node 9 (awal)
    delFirst(L);

    // Hapus node 2 (akhir)
    delLast(L);

    // Hapus node 8 (setelah 12)
    address P = L.First;
    delAfter(L, P->next, P);

    // Cetak hasil akhir
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << " \n" << endl;

    // Hapus seluruh list
    deleteList(L);

    cout << "- List Berhasil Terhapus - " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
