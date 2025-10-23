#include<iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data; 
    Node *next; //Pointer ke node berikutnya
};

//FUngsi untuk pencarian
Node *linearSearch(Node *head, int key){
    Node *current = head;
    while (current != nullptr){
        if (current -> data == key) return current;
        current = current -> next; //Pindah ke node berikutnya
    }

    return nullptr; //Tidak ditemukan
}

//Prosedur untuk menambah node
void append(Node *& head, int value){
    Node * newNode = new Node{value, nullptr};

    if(!head) head = newNode;
    
    else{
        Node* temp = head; //mulai dari head
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

int main(){
    Node * head = nullptr; //inisialisasi head
    append(head, 10); append(head, 20); append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result ? "Found" : "Not Found") << endl; //condition? value_if_true : value_if_false;
    return 0;
}