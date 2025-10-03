#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //Pointer yg menunjukan elemn pertama array

    //Mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i + 1 << " menggunakan pointer: " << *(ptr + i) << endl;
    }

    //Mengakses elemen array menggunakan indeks
    for( int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}