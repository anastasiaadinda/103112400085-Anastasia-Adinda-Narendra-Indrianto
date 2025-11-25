#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void insertLast(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    p->prev = tail;
    if (tail == NULL) head = p;
    else tail->next = p;
    tail = p;
}

void deleteLast() {
    if (tail == NULL) return;
    Node *del = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    else head = NULL;
    delete del;
}

void viewForward() {
    Node *q = head;
    while (q != NULL) {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

void viewBackward() {
    Node *q = tail;
    while (q != NULL) {
        cout << q->data << " ";
        q = q->prev;
    }
    cout << endl;
}

void reverseList() {
    Node *q = head;
    Node *temp = NULL;
    while (q != NULL) {
        temp = q->prev;
        q->prev = q->next;
        q->next = temp;
        q = q->prev;
    }
    if (temp != NULL) head = temp->prev;
    Node *p = head;
    while (p->next != NULL) p = p->next;
    tail = p;
}

int main() {
    int pilih, x;
    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> pilih;
        if (pilih == 1) {
            cout << "Masukkan angka: ";
            cin >> x;
            insertLast(x);
        } else if (pilih == 2) {
            deleteLast();
        } else if (pilih == 3) {
            viewForward();
        } else if (pilih == 4) {
            reverseList();
            viewForward();
        }
    } while (pilih != 0);
}
