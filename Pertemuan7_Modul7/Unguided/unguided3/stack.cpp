#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top != -1) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

// Prosedur baru: membaca input karakter sampai ENTER
void getInputStream(Stack &S) {
    cout << "Masukkan input: ";
    char ch;
    while (true) {
        ch = cin.get(); // membaca satu karakter
        if (ch == '\n') break; // berhenti saat user tekan ENTER
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0';
            push(S, num);
        }
    }
}
