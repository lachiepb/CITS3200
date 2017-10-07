//
// Created by lachi on 5/10/2017.
//

#ifndef CITS3200_STACK_H
#define CITS3200_STACK_H
#include"percolation.h"

#endif //CITS3200_STACK_H
extern NODE** stackS;
extern int topS;
int pushSite(NODE *data);
NODE* popSite();
NODE* peekSite();
int isfullSite();
int isemptySite();