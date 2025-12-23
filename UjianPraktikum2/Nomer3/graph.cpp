#include <iostream>
#include "graph.h"

using namespace std;

struct Graph {
    Node* head;
};

void inisialisasiGraph(Graph &g) {
    g.head = nullptr;
}

void tambahKota(Graph &g, char nama) {
    Node* newNode = new Node{nama, false, false, nullptr, nullptr};
    if (!g.head) {
        g.head = newNode;
    } else {
        Node* temp = g.head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* cariKota(Graph &g, char nama) {
    Node* temp = g.head;
    while (temp) {
        if (temp->nama == nama) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void tambahKeListEdge(Node* asal, Node* tujuan) {
    Edge* newEdge = new Edge{tujuan, nullptr};
    if (!asal->firstEdge) {
        asal->firstEdge = newEdge;
    } else {
        Edge* temp = asal->firstEdge;
        while (temp->next) temp = temp->next;
        temp->next = newEdge;
    }
}

void tambahJalur(Graph &g, char asal, char tujuan) {
    Node* u = cariKota(g, asal);
    Node* v = cariKota(g, tujuan);
    if (u && v) {
        tambahKeListEdge(u, v);
        tambahKeListEdge(v, u);
    }
}

void resetStatus(Graph &g) {
    Node* temp = g.head;
    while (temp) {
        temp->visited = false;
        temp = temp->next;
    }
}

void telusuriJaringan(Node* kotaSekarang) {
    if (!kotaSekarang || kotaSekarang->sedangLockdown || kotaSekarang->visited) return;
    kotaSekarang->visited = true;
    Edge* e = kotaSekarang->firstEdge;
    while (e) {
        if (!e->destination->sedangLockdown && !e->destination->visited) {
            telusuriJaringan(e->destination);
        }
        e = e->next;
    }
}

int hitungKotaAktif(Graph &g) {
    int count = 0;
    Node* temp = g.head;
    while (temp) {
        if (!temp->sedangLockdown) count++;
        temp = temp->next;
    }
    return count;
}

int hitungKotaTerjangkau(Graph &g) {
    int count = 0;
    Node* temp = g.head;
    while (temp) {
        if (temp->visited) count++;
        temp = temp->next;
    }
    return count;
}

void analisisKotaKritis(Graph &g) {
    cout << "Analisis Kota Kritis (Single Point of Failure)" << endl;
    Node* currentCheck = g.head;
    while (currentCheck) {
        resetStatus(g);
        currentCheck->sedangLockdown = true;
        Node* startNode = nullptr;
        Node* temp = g.head;
        while (temp) {
            if (temp != currentCheck) {
                startNode = temp;
                break;
            }
            temp = temp->next;
        }
        if (startNode) telusuriJaringan(startNode);
        if (hitungKotaTerjangkau(g) < hitungKotaAktif(g)) {
            cout << "[PERINGATAN] Kota " << currentCheck->nama << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << currentCheck->nama << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << currentCheck->nama << " aman (redundansi oke)." << endl;
        }
        currentCheck->sedangLockdown = false;
        currentCheck = currentCheck->next;
    }
}

void cetakJaringan(Graph &g) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* n = g.head;
    while (n) {
        cout << "Node " << n->nama << " terhubung ke:";
        Edge* e = n->firstEdge;
        while (e) {
            cout << " " << e->destination->nama;
            e = e->next;
        }
        cout << endl;
        n = n->next;
    }
    cout << endl;
}