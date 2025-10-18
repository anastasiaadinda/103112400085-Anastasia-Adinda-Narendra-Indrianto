#include "Singlylist.h"
#include <iostream>
#include <chrono> // for measuring execution time
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now(); // start time measurement

    List L;
    CreateList(L); // create empty list

    // insert data into list
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // display list data
    printInfo(L);

    // add blank line for spacing
    cout << endl;

    auto end = chrono::high_resolution_clock::now(); // end time measurement
    chrono::duration<double> duration = end - start; // calculate execution time

    // display output similar to IDE format
    cout << "Process returned 0 (0x0) execution time : " 
         << duration.count() << " s" << endl;
    cout << "Press any key to continue." << endl;

    return 0;
}
