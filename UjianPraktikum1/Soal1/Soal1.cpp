#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node *next;
};

Node *head = NULL;

void insertLast(string x) {
    Node *p = new Node;
    p->nama = x;
    p->next = NULL;
    if (head == NULL) head = p;
    else {
        Node *q = head;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

void deleteFirstMatch(string x) {
    if (head == NULL) return;
    if (head->nama == x) {
        Node *del = head;
        head = head->next;
        delete del;
        return;
    }
    Node *q = head;
    while (q->next != NULL && q->next->nama != x) q = q->next;
    if (q->next != NULL) {
        Node *del = q->next;
        q->next = q->next->next;
        delete del;
    }
}

void view() {
    Node *q = head;
    while (q != NULL) {
        cout << q->nama << endl;
        q = q->next;
    }
}

void hitungGenap() {
    Node *q = head;
    int count = 0;
    while (q != NULL) {
        if (q->nama.length() % 2 == 0) count++;
        q = q->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int pilihan;
    string x;
    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> pilihan;
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            cin >> x;
            insertLast(x);
        } else if (pilihan == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> x;
            deleteFirstMatch(x);
        } else if (pilihan == 3) {
            view();
        } else if (pilihan == 4) {
            hitungGenap();
        }
    } while (pilihan != 0);
}
