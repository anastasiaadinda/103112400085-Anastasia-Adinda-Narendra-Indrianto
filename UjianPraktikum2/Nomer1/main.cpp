#include "bst.h"

int main() {
    createTree();

    insertNode(60, "Rizkina Azizah", "Basic");
    insertNode(50, "Hakan Ismail", "Bronze");
    insertNode(65, "Olivia Saevali", "Silver");
    insertNode(47, "Felix Pedrosa", "Gold");
    insertNode(56, "Gamel Al Ghifari", "Platinum");
    insertNode(70, "Hanif Al Faiz", "Basic");
    insertNode(52, "Mutiara Fauziah", "Bronze");
    insertNode(68, "Davi Ilyas", "Silver");
    insertNode(81, "Abdad Mubarok", "Gold");

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << "\n" << endl;

    mostLeft();
    mostRight();
    cout << endl;

    searchByBeratBadan(root, 70, NULL);

    return 0;
}