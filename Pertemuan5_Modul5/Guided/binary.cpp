#include<iostream>
using namespace std;

//Definisi node
struct Node { //memiliki 2 bagian yaitu data dan pointer
    int data;
    Node *next; //pointer ke node berikutnya
};

void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr}; //newNode adalah pointer yang menunjuk ke node baru yang akan dibuat.
    //value == null karena node baru berada di paling akhir
    if(!head) head = newNode; // jika head null, head diisi node baru
    else{
        Node * temp = head; // mulai dari head
        while (temp -> next) temp = temp -> next; // pindah ke node berikutnya sampai ketemu node terakhir
        temp -> next = newNode; // node terakhir dihubungkan ke node baru
    }
}

Node * binarySearch(Node * head, int key){ //Node* ini pointer (kembalian) //head ini pointer ke node pertama // key ini data yang idcari
    int size = 0; //var disi 0
    for (Node *current = head; current; current = current -> next) size++; //current adalah pointer yang digunakan untuk menyusuri linked list

    Node* start = head; // start adlh pointer yang menunjuk ke node pertama
    Node* end = nullptr; // end adalah pointer yang menunjuk ke node terakhir(null karena linked list tidak emiliki node terakhir yang pasti)

    while(start != end){
        int mid = size / 2;
        Node* midNode = start;
        for(int i = 0; i < mid; i++) midNode = midNode -> next;

        if(midNode -> data == key) return midNode;
        if(midNode -> data < key){
            start = midNode -> next;
            size = size - mid - 1;
        }
        else{
            size = mid;
        }
    }
    
    if(start && start->data == key) return start;
    return nullptr; //Jika key tidak ditemukan
}

int main(){
    Node *head = nullptr;
    append(head, 10); append(head,20); append(head,30);
    append(head, 40); append(head,50);

    Node * result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}