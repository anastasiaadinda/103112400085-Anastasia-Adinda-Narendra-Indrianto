#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

void createTree();
bool isEmpty();
Node* newNode(float berat, string nama, string tier);
void insertNode(float berat, string nama, string tier);
void inOrder(Node* node);
void mostLeft();
void mostRight();
void searchByBeratBadan(Node* curr, float target, Node* parent);

extern Node* root;

#endif