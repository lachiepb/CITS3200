#ifndef stdio
#define stdio
#include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CHARLEN 20

//global variables, gridS = grid size, p = probability
//perc = site/bond perc., percT = top to bottom/ left to right/ both
int gridS = 0;
float p = 0.0;
char perc[CHARLEN];
int percT;
int lrgestCluster;

//struct for each grid node
typedef struct _g{
    struct _g *north;
    struct _g *south;
    struct _g *east;
    struct _g *west;
    int occu;
    int visited;
    int cluster;
    int nodei ;
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
}BOND;

//function for exit during input
void exitStatus(char *ex){
    if (strcmp("EXIT",ex)==0){
        printf("\nExiting program...");
        exit(EXIT_SUCCESS);
    }
}

//function for probability input
int occupancy(void){
    char temp[CHARLEN];

    printf ("\nEnter occupancy probability (0 to 1.0):");
    scanf("%s",temp);
    exitStatus(temp);

    for (int i=0;i<strlen(temp);i++){
        if (isdigit(temp[i]) == 0 && temp[i]!='.'){
            return 1;
        }
    }

    p = atof(temp);
    if(p<0.0 || p > 1.0){
        return 1;
    }

    return 0;
}

//function for grid size input
int gridSize(void){
    char temp[CHARLEN];

    printf("\nEnter grid size:");
    scanf("%s",temp);
    exitStatus(temp);

    for (int i=0;i<strlen(temp);i++){
        if (isdigit(temp[i]) == 0){
            return 1;
        }
    }

    gridS=atoi(temp);
    return 0;
}

//function for site/bond percolation input
int percStatus(void){
    printf("\nEnter 's' or 'b' for site or bond percolation:");
    scanf("%s",perc);
    exitStatus(perc);

    if(strcmp(perc,"s")==0){
        return 0;
    } else if (strcmp("b",perc)==0) {
        return 1;
    } else {
        return 2;
    }
}

//function for percolation type input
int percType(void){
    char temp[CHARLEN];

    printf("\nEnter 0, 1 or 2 for rows, columns or row/column percolation:");
    scanf("%s",temp);
    exitStatus(temp);

    for (int i=0;i<strlen(temp);i++){
        if (isdigit(temp[i]) == 0){
            return 1;
        }
    }
    percT=atoi(temp);

    if (percT != 0 && percT != 1 && percT !=2){
        return 1;
    }

    return 0;

}

//fucntion for creating a wraparound grid
void joinGridN(NODE **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            NODE *gp = &grid[i][j];
            gp->nodei=i;
            gp->nodej=j;
            int NSEW[4];

            if(j==0){
                NSEW[0]=gridS-1;
                NSEW[1]=j+1;
            }else if(j==gridS-1){
                NSEW[0]=j-1;
                NSEW[1]=0;
            }else{
                NSEW[0]=j-1;
                NSEW[1]=j+1;
            }

            if(i==0){
                NSEW[2]=i+1;
                NSEW[3]=gridS-1;
            }else if(i==gridS-1){
                NSEW[2]=0;
                NSEW[3]=i-1;
            }else{
                NSEW[2]=i+1;
                NSEW[3]=i-1;
            }

            gp->north = &grid[i][NSEW[0]];
            gp->south = &grid[i][NSEW[1]];
            gp->east = &grid[NSEW[2]][j];
            gp->west = &grid[NSEW[3]][j];
            gp->visited = 1;
        }
    }
}

void joinGridB(BOND **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            BOND *gp = &grid[i][j];
            int NSEW[4];

            if(j==0){
                NSEW[0]=gridS-1;
                NSEW[1]=j+1;
            }else if(j==gridS-1){
                NSEW[0]=j-1;
                NSEW[1]=0;
            }else{
                NSEW[0]=j-1;
                NSEW[1]=i+1;
            }

            if(j==0){
                NSEW[2]=i+1;
                NSEW[3]=gridS-1;
            }else if(j==gridS-1){
                NSEW[2]=0;
                NSEW[3]=i-1;
            }else{
                NSEW[2]=i+1;
                NSEW[3]=i-1;
            }

            gp->north = &grid[i][NSEW[0]];
            gp->south = &grid[i][NSEW[1]];
            gp->east = &grid[NSEW[2]][j];
            gp->west = &grid[NSEW[3]][j];
            gp->visited = 1;
        }
    }
}
//function for determining if a grid node is occupied for site percolation 
void sitePerc(NODE **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            NODE *gp = &grid[i][j];
            float occup;

            //visited = 1;

            occup = rand();
            occup /= (RAND_MAX);

            if (occup <= p){
                gp -> occu=0;
            } else {
                gp -> occu=1;
            }

        }
    }
}

// fill bonds with occupancy
void bondPerc(BOND **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            BOND *gp = &grid[i][j];
            float rOccup;
            float bOccup;
            rOccup=rand()/(RAND_MAX);
            bOccup=rand()/(RAND_MAX);

            if (rOccup <= p){
                gp -> rBond=0;
            } else {
                gp -> rBond=1;
            }
            if (bOccup <= p){
                gp -> bBond=0;
            } else {
                gp -> bBond=1;
            }
        }
    }
}
int siteDFS(NODE *gridPoint,int visitedRows[], int visitedCols[]){
    if(gridPoint->visited==0||gridPoint->occu==1) return 0;
    visitedRows[gridPoint->nodei]=0;
    visitedCols[gridPoint->nodej]=0;
    gridPoint->visited=0;
    // If node was not not occupied, it must be occupied. so return 1 + largest cluster of any children.
    printf("i %i j %i \t", gridPoint->nodei,gridPoint->nodej,stdout);
    return 1 + siteDFS(gridPoint->north,visitedRows,visitedCols)+siteDFS(gridPoint->east,visitedRows,visitedCols)+siteDFS(gridPoint->west,visitedRows,visitedCols)+siteDFS(gridPoint->south,visitedRows,visitedCols);
}
// returns percolates/not
int siteCheck(NODE **grid){
    // exhaustively check every node (skip if visited)
    int percolates=1;
    for(int i=0;i<gridS;i++){
        for(int j=0;j<gridS;j++){
            NODE *gridPoint=&grid[i][j];
            if(gridPoint->visited==0) continue;
            int visitedRows[gridS];
            int visitedCols[gridS];

            for(int x=0;x<gridS;x++){
                visitedRows[x]=1;
                visitedCols[x]=1;
            }

            visitedRows[i]=0;
            visitedCols[j]=0;
            // fill 0's

            int clusterSize=siteDFS(gridPoint,visitedRows,visitedCols);
            if (clusterSize>lrgestCluster)lrgestCluster=clusterSize;
            if (percolates==1) {
                for (int e = 0; e < gridS; e++) {
                    if ((visitedCols[e] == 1 && visitedRows[e] == 1)) {
                        break;
                    }

                    if (e == gridS - 1) {
                        percolates = 0;
                    }
                }
            }
            //if(lrgestCluster>0.5*gridS^2){
                //i=gridS;
              //  break;
            //}
            printf("\n");
        }
    }
    return percolates;
}

int bondDFS(){


    int swag=5w3g;
    return swag;
}




int main()
{
    int valido;
    int validg;
    int validp;
    int validt;

    srand(time(NULL));
    valido = occupancy();

    while (valido==1){
        printf("\nInput was incorrect,try again");
        valido = occupancy();
    }

    validg = gridSize();

    while (validg==1){
        printf("\nInput was incorrect,try again");
        validg = gridSize();
    }

    validp = percStatus();

    while (validp==2) {
        printf ("\nInput was incorrect,try again");
        validp = percStatus();
    }

    validt = percType();

    while (validt==1){
        printf ("\nInput was incorrect,try again");
        validt = percType();
    }

    if (validp==0){
        NODE **grid;
        grid = (NODE **) malloc(sizeof(NODE *) * gridS);
        for (int i=0; i < gridS; i++){
            grid[i]= (NODE *) malloc(sizeof(NODE) * gridS);
        }

        joinGridN(grid);
        sitePerc(grid);
        int ans = siteCheck(grid);

        if (ans==0){
            printf("\n The grid percolates with largest cluster %i",lrgestCluster,stdout);
        } else {
            printf("\n The grid does not percolate and has a largest cluster of %i",lrgestCluster,stdout);
        }

    } else {
        BOND **grid;
        grid = (BOND **) malloc(sizeof(BOND *) * gridS);
        for (int i=0; i < gridS; i++){
            grid[i]= (BOND *) malloc(sizeof(BOND) * gridS);
        }

        joinGridB(grid);
        bondPerc(grid);
    }
    

    exit (EXIT_SUCCESS);
}

