#include "stack.h"

int MAXSIZE = 200000000;
NODE* stack[200000000];
int top = -1;

int isemptySite() {
    if(top == -1)
        return 0;
    else
        return 1;
}

int isfullSite() {
    if(top == MAXSIZE)
        return 0;
    else
        return 1;
}

NODE* peekSite() {
    return stack[top];
}

NODE* popSite() {
    NODE* data;

    if(isemptySite()==1) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int pushSite(NODE* data) {

    if(isfullSite()==1) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}