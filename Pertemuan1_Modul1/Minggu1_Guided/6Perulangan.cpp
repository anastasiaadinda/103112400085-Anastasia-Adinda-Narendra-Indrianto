#include<iostream>
using namespace std;

int main(){
    int angka1;    
    cout << " Masukan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 20;
    while (j > angka1){
        cout << j << " - ";
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka1);
    
    return 0;
}