#include "graph.h"

struct Graph { Node* head; };
void inisialisasiGraph(Graph &g);
void tambahKota(Graph &g, char nama);
void tambahJalur(Graph &g, char asal, char tujuan);
void analisisKotaKritis(Graph &g);
void cetakJaringan(Graph &g);

int main() {
    Graph g;
    inisialisasiGraph(g);

    tambahKota(g, 'A');
    tambahKota(g, 'B');
    tambahKota(g, 'C');
    tambahKota(g, 'D');
    tambahKota(g, 'E');

    tambahJalur(g, 'B', 'E');
    tambahJalur(g, 'B', 'C');
    tambahJalur(g, 'A', 'B');
    tambahJalur(g, 'C', 'D');

    cetakJaringan(g);
    analisisKotaKritis(g);

    return 0;
}