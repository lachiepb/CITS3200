#include "stackBond.h"
// Awful space performance, we know. we have plenty of memory though.
int MAXSIZEB = 100000000;
BOND* stackB[100000000];
int topB = -1;

int isemptyBond() {
    if(topB == -1)
        return 0;
    else
        return 1;
}

int isfullBond() {
    if(topB == MAXSIZEB)
        return 0;
    else
        return 1;
}

BOND* peekBond() {
    return stackB[topB];
}

BOND* popBond() {
    BOND* data;

    if(isemptyBond()==1) {
        data = stackB[topB];
        topB = topB - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int pushBond(BOND* data) {

    if(isfullBond()==1) {
        topB = topB + 1;
        stackB[topB] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}