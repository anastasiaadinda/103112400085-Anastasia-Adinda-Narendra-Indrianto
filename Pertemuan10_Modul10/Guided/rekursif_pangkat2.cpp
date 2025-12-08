#include <iostream>
using namespace std;

int pangkat_2(int x) { //  adalah pangkatnya
    if (x == 0) { // basis
        return 1;
    } else if (x > 0){ //rekurens
        return 2 * pangkat_2(x - 1);
    }
    return 1; // perbaikan: menghilangkan warning kuning
}

int main() {
    cout << " === REKURSIF PANGKAT 2 === " << endl;

    int x;
    cout << "Masukan nilai x: ";
    cin >> x;
    cout << endl;

    cout << " Nilai 2 pangkat " << x << " adalah " << pangkat_2(x) << endl;

    return 0;
}
