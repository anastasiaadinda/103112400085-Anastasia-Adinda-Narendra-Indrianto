#include <iostream>
using namespace std;

string satuan(int n) {
    switch (n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
    }
    return "";
}

string angkaKeTulisan(int n) {
    if (n < 10) {
        return satuan(n);
    } else if (n == 10) {
        return "sepuluh";
    } else if (n == 11) {
        return "sebelas";
    } else if (n < 20) {
        return satuan(n % 10) + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan(puluh) + " puluh";
        if (sisa > 0) hasil += " " + satuan(sisa);
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "Angka harus antara 0 sampai 100";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus antara 0 sampai 100" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}
