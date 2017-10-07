#include "stackSite.h"
// Awful space performance, we know. we have plenty of memory though.
int MAXSIZES = 100000000;
NODE** stackS;
//NODE* stackS[100000000];
int topS = -1;

int isemptySite() {
    if(topS == -1)
        return 0;
    else
        return 1;
}

int isfullSite() {
    if(topS == MAXSIZES)
        return 0;
    else
        return 1;
}

NODE* peekSite() {
    return stackS[topS];
}

NODE* popSite() {
    NODE* data;

    if(isemptySite()==1) {
        data = stackS[topS];
        topS = topS - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int pushSite(NODE* data) {

    if(isfullSite()==1) {
        topS = topS + 1;
        stackS[topS] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}