#include "stackSite.h"

int MAXSIZES;
MAXSIZES=4*gridS*gridS;
NODE** stackS;
int topS = -1;

//Check if stack is empty
int isemptySite() {
    if(topS == -1)
        return 0;
    else
        return 1;
}

//Check if stack is full
int isfullSite() {
    if(topS == MAXSIZES)
        return 0;
    else
        return 1;
}

//Return and remove top of the stack
NODE* popSite() {
    NODE* data;

    if(isemptySite()==1) {
        data = stackS[topS];
        topS = topS - 1;
        return data;
    } 
}

//Push onto the top of the stack
int pushSite(NODE* data) {

    if(isfullSite()==1) {
        topS = topS + 1;
        stackS[topS] = data;
    } 
}