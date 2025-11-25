#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

const int MAX = 5;

struct Paket {
    char KodeResi[10];
    char NamaPengirim[50];
    int BeratBarang; // dalam kg
    char Tujuan[50];
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head; // Head diam di -1 atau 0
    int Tail;
};

void createQueue(QueueEkspedisi *Q);
bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void enQueue(QueueEkspedisi *Q, Paket data_baru);
void deQueue(QueueEkspedisi *Q);
void viewQueue(QueueEkspedisi Q);

// Deklarasi fungsi TotalBiayaPengiriman (Bagian B)
float TotalBiayaPengiriman(QueueEkspedisi Q); 

#endif