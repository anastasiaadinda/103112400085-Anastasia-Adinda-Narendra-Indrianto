#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

// insert tanpa duplikasi
void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } else if(x > root->info){
            insertNode(root->right, x);
        }
        // jika x == root->info, abaikan (tidak simpan duplikat)
    }
}

address findNode(infotype x, address root){
    if(root == Nil){
        return Nil;
    } else if(root->info == x){
        return root;
    } else if(x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

// Traversal: InOrder
void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Traversal: PreOrder
void printPreOrder(address root){
    if(root != Nil){
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Traversal: PostOrder
void printPostOrder(address root){
    if(root != Nil){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}

// hitung jumlah node
int hitungJumlahNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// hitung total isi node
int hitungTotalInfo(address root, int start){
    if(root == Nil) return start;
    start += root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

// kedalaman maksimum
int hitungKedalaman(address root, int start){
    if(root == Nil) return start;
    int left = hitungKedalaman(root->left, start + 1);
    int right = hitungKedalaman(root->right, start + 1);
    return (left > right ? left : right);
}
