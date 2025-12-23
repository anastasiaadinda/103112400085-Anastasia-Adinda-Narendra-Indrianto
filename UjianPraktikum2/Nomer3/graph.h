#ifndef GRAPH_H
#define GRAPH_H

struct Edge;

struct Node {
    char nama;
    bool sedangLockdown;
    bool visited;
    Edge* firstEdge;
    Node* next;
};

struct Edge {
    Node* destination;
    Edge* next;
};

#endif