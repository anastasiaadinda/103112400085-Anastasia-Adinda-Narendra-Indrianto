#include "bst.h"

Node* root = NULL;

void createTree() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Node* newNode(float berat, string nama, string tier) {
    Node* baru = new Node();
    baru->beratBadan = berat;
    baru->namaMember = nama;
    baru->tierMember = tier;
    baru->left = baru->right = NULL;
    return baru;
}

Node* insertRecursive(Node* node, float berat, string nama, string tier) {
    if (node == NULL) return newNode(berat, nama, tier);
    if (berat < node->beratBadan)
        node->left = insertRecursive(node->left, berat, nama, tier);
    else if (berat > node->beratBadan)
        node->right = insertRecursive(node->right, berat, nama, tier);
    return node;
}

void insertNode(float berat, string nama, string tier) {
    root = insertRecursive(root, berat, nama, tier);
}

void inOrder(Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << (int)node->beratBadan << " - ";
        inOrder(node->right);
    }
}

void mostLeft() {
    if (isEmpty()) return;
    Node* curr = root;
    while (curr->left != NULL) curr = curr->left;
    cout << "Node MostLeft : " << (int)curr->beratBadan << endl;
}

void mostRight() {
    if (isEmpty()) return;
    Node* curr = root;
    while (curr->right != NULL) curr = curr->right;
    cout << "Node MostRight : " << (int)curr->beratBadan << endl;
}

void searchByBeratBadan(Node* curr, float target, Node* parent) {
    if (curr == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }
    if (curr->beratBadan == target) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << curr->namaMember << endl;
        cout << "Berat Badan : " << (int)curr->beratBadan << endl;
        cout << "Tier Member : " << curr->tierMember << endl;
        cout << endl;

        if (parent) {
            cout << "--- Data Parent ---" << endl;
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << (int)parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
            cout << endl;

            if ((parent->left == curr && parent->right) || (parent->right == curr && parent->left))
                cout << "Memiliki Sibling" << endl;
            else
                cout << "Tidak Memiliki Sibling" << endl;
            cout << endl;
        }

        if (curr->left) {
            cout << "--- Data Child Kiri ---" << endl;
            cout << "Nama Member : " << curr->left->namaMember << endl;
            cout << "Berat Badan : " << (int)curr->left->beratBadan << endl;
            cout << "Tier Member : " << curr->left->tierMember << endl;
            cout << endl;
        }

        if (curr->right) {
            cout << "--- Data Child Kanan ---" << endl;
            cout << "Nama Member : " << curr->right->namaMember << endl;
            cout << "Berat Badan : " << (int)curr->right->beratBadan << endl;
            cout << "Tier Member : " << curr->right->tierMember << endl;
            cout << endl;
        }
        return;
    }
    if (target < curr->beratBadan) searchByBeratBadan(curr->left, target, curr);
    else searchByBeratBadan(curr->right, target, curr);
}