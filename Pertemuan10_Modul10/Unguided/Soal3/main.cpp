#include <iostream>
#include "bstree.h"
using namespace std;

int main() {

    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,2);
    insertNode(root,1);
    insertNode(root,3);
    insertNode(root,5);
    insertNode(root,7);

    cout << "InOrder : ";
    printInorder(root);
    cout << endl;

    cout << "PreOrder : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root,0)+1 << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root,0) << endl;

    return 0;
}
