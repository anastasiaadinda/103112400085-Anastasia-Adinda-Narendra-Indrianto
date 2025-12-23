#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    NodeParent* g4 = alokasiNodeParent("G004", "Romance");
    NodeParent* g3 = alokasiNodeParent("G003", "Horror");
    NodeParent* g2 = alokasiNodeParent("G002", "Comedy");
    NodeParent* g1 = alokasiNodeParent("G001", "Action");

    insertFirstParent(LP, g4);
    insertFirstParent(LP, g3);
    insertFirstParent(LP, g2);
    insertFirstParent(LP, g1);

    insertLastChild(g1->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(g2->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(g2->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(g3->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(g4->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(g4->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    NodeParent* pDel;
    deleteAfterParent(LP, g1, pDel);
    if (pDel != NULL) delete pDel;

    printStrukturMLL(LP);

    return 0;
}