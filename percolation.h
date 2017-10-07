//
// Created by lachi on 5/10/2017.
//

#ifndef CITS3200_PERCOLATION_H
#define CITS3200_PERCOLATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <omp.h>

typedef struct _g{
    struct _g *north;
    struct _g *south;
    struct _g *east;
    struct _g *west;
    int occu;
    int visited;
    int nodei;
    int nodej;

}NODE;

typedef struct _p{
    struct _p *north;
    struct _p *south;
    struct _p *east;
    struct _p *west;
    int rBond;
    int bBond;
    int visited;
    int nodei;
    int nodej;
    int check[4];

}BOND;
extern int gridS;
extern float p;
extern int percT;
extern int lrgestCluster;
extern int trdCount;
#endif //CITS3200_PERCOLATION_H

void exitStatus(char *ex);
int occupancy(void);
int gridSize(void);
int percStatus(void);
int percType(void);
void joinGridN(NODE **grid);
void joinGridB(BOND **grid);
void sitePerc(NODE **grid);
void bondPerc(BOND **grid);
int siteDFS(NODE *gridPoint,int visitedRows[], int visitedCols[]);
int siteCheck(NODE **grid);
int bondDFS(BOND *gridPoint,int visitedRows[], int visitedCols[]);
int bondCheck(BOND **grid);