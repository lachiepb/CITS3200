#include "stackBond.h"

BOND** stackB;
int topB = -1;

int isemptyBond() {
    if(topB == -1)
        return 0;
    else
        return 1;
}


BOND* popBond() {
    BOND* data;
    if(isemptyBond()==1) {
        data = stackB[topB];
        topB = topB - 1;
        return data;
    }
}

int pushBond(BOND* data) {
    topB = topB + 1;
    stackB[topB] = data;
}