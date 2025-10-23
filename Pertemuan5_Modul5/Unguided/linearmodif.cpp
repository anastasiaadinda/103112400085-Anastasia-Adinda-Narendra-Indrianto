#include <iostream>
#include <iomanip> // untuk format alamat memori (hex)
using namespace std;

// Struktur node: menyimpan data dan pointer ke node berikutnya
struct Node {
    int data;
    Node* next;
};

// Tambah node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;            // jika kosong, node baru jadi head
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; // cari node terakhir
        temp->next = newNode;                 // hubungkan node terakhir ke node baru
    }
}

// Fungsi Linear Search
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* current = head;
    int index = 1;

    // Telusuri satu per satu node
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr; // jika tidak ditemukan
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";

    // Buat linked list
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        append(head, arr[i]);
        cout << arr[i];
        if (i != n - 1) cout << " -> ";
    }
    cout << " -> NULL\n";

    // Cari nilai yang ada
    int cari = 30;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = linearSearch(head, cari);

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
    hasil = linearSearch(head, cari);

    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << showbase << hex << (uintptr_t)hasil << dec << endl;
        cout << "Data node: " << hasil->data << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
