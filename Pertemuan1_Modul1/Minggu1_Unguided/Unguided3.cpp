#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = n; i >= 0; i--) {
        // spasi di awal baris (supaya rata miring kanan)
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // 2 spasi
        }

        // angka menurun (kiri bintang)
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang tengah
        cout << "*";

        // angka menaik (kanan bintang)
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}
