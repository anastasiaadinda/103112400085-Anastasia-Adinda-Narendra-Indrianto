#include <iostream>
#include <iomanip>  // untuk std::hex dan std::showbase
using namespace std;

// Struktur node: menyimpan data dan pointer ke node berikutnya
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; // buat node baru
    if (!head) head = newNode;                // jika list kosong, node baru jadi head
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari node terakhir
        temp->next = newNode;                 // hubungkan node terakhir ke node baru
    }
}

// Fungsi untuk menghitung panjang linked list
int getSize(Node* head) {
    int size = 0;
    for (Node* curr = head; curr; curr = curr->next) size++;
    return size;
}

// Fungsi untuk mengambil node di posisi ke-n (0-based)
Node* getNodeAt(Node* head, int index) {
    Node* curr = head;
    for (int i = 0; i < index && curr; i++)
        curr = curr->next;
    return curr;
}

// Fungsi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    int size = getSize(head);
    int left = 0;
    int right = size - 1;
    int iteration = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iteration++ << ": Mid = "
             << midNode->data << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        } else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan\n";
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    return nullptr; // jika tidak ditemukan
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";

    // Membuat linked list dengan data terurut
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        append(head, arr[i]);
        cout << arr[i];
        if (i != n - 1) cout << " -> ";
    }
    cout << " -> NULL\n";

    // Cari nilai yang ada
    int cari = 40;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    // Cari nilai yang tidak ada
    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = binarySearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
        if (hasil->next)
            cout << "Node berikutnya: " << hasil->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
