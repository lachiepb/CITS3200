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
#include <math.h>
#include <mpi.h>

//Struct for site percolation
typedef struct _g{
    struct _g *north;
    struct _g *south;
    struct _g *east;
    struct _g *west;
    struct _g *parent;
    //int clusterNum;
    int occu;
    int nodei;
    int nodej;

}NODE;

//Struct for bond percolation
typedef struct _p{
    struct _p *north;
    struct _p *south;
    struct _p *east;
    struct _p *west;
    struct _g *parent;
    //int clusterNum;
    int rBond;
    int bBond;
    int nodei;
    int nodej;

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
int trdReturn(void);
void joinGridN(NODE **grid);
void joinGridB(BOND **grid);
void sitePerc(NODE **grid);
void bondPerc(BOND **grid);
int siteCheck(NODE **grid);
int bondCheck(BOND **grid);