#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    //Inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);

    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);

    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //Memasukan Data Child (Menu Makanan) ke kategori tertentu

    //-> Isi Kategori Makanan Berat
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);

    // -> Isi Kategori Minuman
    NodeChild D02 = alokasiNodeChild("N02", "Just Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01); 

    cout << endl;

    // -> Print MLL setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    // -> Searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    // -> Delete node child
    deleteAfterChild(K01 -> L_Anak, M01);
    cout << endl;

    // -> Delete node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;

    // -> print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
