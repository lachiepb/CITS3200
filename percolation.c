#include "percolation.h"
#include "stackSite.h"
#include "stackBond.h"

#define CHARLEN 20

//global variables, gridS = grid size, p = probability
//percT = top to bottom/ left to right/ both, lrgestCluster = largest cluster size
int gridS = 0;
float p = 0.0;
int percT;
int lrgestCluster;
int currentCluster=0;

//Function for exit status
void exitStatus(char *ex){
    if (strcmp("EXIT",ex)==0){
        printf("\nExiting program...");
        exit(EXIT_SUCCESS);
    }
}

//Function for probability input
int occupancy(void){
    char temp[CHARLEN];
    printf ("\nEnter occupancy probability (0 to 1.0):");
    scanf("%s",temp);
    exitStatus(temp);
    for (int i=0;i<strlen(temp);i++){
        if (isdigit(temp[i]) ==0  && temp[i]!='.'){
            return 1;
        }
    }
    p = atof(temp);
    if(p<0.0 || p > 1.0){
        return 1;
    }
    return 0;
}

//Function for grid size input
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

//Function for site/bond percolation input
int percStatus(void){
    char perc[CHARLEN];
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

//Function for percolation type input
int percType(void){
    char temp[CHARLEN];
    printf("\nEnter 0, 1 or 2 for vertical, horizontal or vertical/horizontal percolation:");
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

//Function for thread count input
int trdReturn(void){
    char temp[CHARLEN];
    printf("\nEnter number of desired threads:");
    scanf("%s",temp);
    exitStatus(temp);
    for (int i=0;i<strlen(temp);i++){
        if (isdigit(temp[i]) == 0){
            return 1;
        }
    }
    trdCount=atoi(temp);
    return 0;
}

//Fucntion for creating a wraparound site percolation grid
void joinGridN(NODE **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            NODE *gp = &grid[i][j];
            int NSEW[4];
            //Determining the 'j' of north and south component
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
            //Determining the 'i' of east and west component
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
            //Updating fields in the structure
            gp->west = &grid[NSEW[3]][j];
            gp->east = &grid[NSEW[2]][j];
            gp->south = &grid[i][NSEW[1]];
            gp->north = &grid[i][NSEW[0]];
            gp->nodei=i;
            gp->nodej=j;
        }
    }
}

//function for creating a wraparound bond percolation grid
void joinGridB(BOND **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            BOND *gp = &grid[i][j];
            int NSEW[4];
            //Determining the 'j' of north and south component
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
            //Determining the 'i' of east and west component
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
            //Updating fields in the structure
            gp->west = &grid[NSEW[3]][j];
            gp->east = &grid[NSEW[2]][j];
            gp->south = &grid[i][NSEW[1]];
            gp->north = &grid[i][NSEW[0]];
            gp->nodei=i;
            gp->nodej=j;
        }
    }
}

//function for determining if a grid node is occupied for site percolation 
void sitePerc(NODE **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            NODE *gp = &grid[i][j];
            float occup;
            //Generate random number from 0 to 1 for node occupancy
            occup = rand();
            occup /= (RAND_MAX);
            //Check if node is occupied
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
            //Generate random number from 0 to 1 for bond occupancy
            rOccup = rand();
            rOccup /= (RAND_MAX);
            bOccup = rand();
            bOccup /= (RAND_MAX);
            //Check if bonds are occupied
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

int siteCheck(NODE **grid){
    int percolates=1;
    for(int i=0;i<gridS;i++){
#pragma omp parallel for
        for(int j=0;j<gridS;j++){
            NODE *gridPoint=&grid[i][j];
            NODE *startPoint=&grid[i][j];
            int clusterSize=0;
            //Push site onto stack
            if (gridPoint->occu==0){
                pushSite(gridPoint);
            }else{
                continue;
            }

            //Array for checking if it percolates
            int visitedRows[gridS];
            int visitedCols[gridS];
            //Initialise the array with 1s (not seen)
            for (int p=0;p < gridS; p++){
                visitedRows[p]=1;
                visitedCols[p]=1;
            }
            //Set the current grid row and column to 0 (seen)
            visitedRows[i]=0;
            visitedCols[j]=0;

            int visitGrid [gridS][gridS];
            for (int k=0;k<gridS;k++){
                for (int p=0;p<gridS;p++){
                    visitGrid[k][p]=1;
                }
            }
            visitGrid[i][j]=0;

            while(isemptySite()==1){
                NODE *site;
                site = popSite();
                visitedRows[site->nodei]=0;
                visitedCols[site->nodej]=0;

                if(site->north->occu==0 && visitGrid[site->north->nodei][site->north->nodej]==1){
                    pushSite(site->north);
                    visitGrid[site->north->nodei][site->north->nodej]=0;
                }

                if(site->south->occu==0 && visitGrid[site->south->nodei][site->south->nodej]==1){
                    pushSite(site->south);
                    visitGrid[site->south->nodei][site->south->nodej]=0;
                }

                if(site->east->occu==0 && visitGrid[site->east->nodei][site->east->nodej]==1){
                    pushSite(site->east);
                    visitGrid[site->east->nodei][site->east->nodej]=0;
                }

                if(site->west->occu==0 && visitGrid[site->west->nodei][site->west->nodej]==1){
                    pushSite(site->west);
                    visitGrid[site->west->nodei][site->west->nodej]=0;
                }
                //Increase cluster size
                clusterSize+=1;
            }
            //If grid hasn't percolate yet, execute the following
            if (percolates == 1) {
                int tempPerc = 1;
                //If vertical percolation
                if (percT == 0) {
                    //If any element in array is 1, exit loop
                    for (int e = 0; e < gridS; e++) {
                        if (visitedRows[e] == 1) {
                            break;
                        }
                        //Update percolate if reached the final element
                        if (e == gridS - 1) {
                            tempPerc = 0;
                        }
                    }
                    //If horizontal percolation
                } else if (percT == 1) {
                    for (int e = 0; e < gridS; e++) {
                        if (visitedCols[e] == 1) {
                            break;
                        }

                        if (e == gridS - 1) {
                            tempPerc = 0;
                        }
                    }
                    //If vertical/ horizontal percolation
                } else {
                    for (int e = 0; e < gridS; e++) {
                        if ((visitedCols[e] == 1 || visitedRows[e] == 1)) {
                            break;
                        }

                        if (e == gridS - 1) {
                            tempPerc = 0;
                        }
                    }
                }
            }
#pragma omp critical
            {
                //Update largest cluster, if current cluster is larger
                if (clusterSize > lrgestCluster)lrgestCluster = clusterSize;
                if (tempPerc == 0){
                    percolates = 0;
                }
            }
        }
    }
    //Return if grid percolates or not
    return percolates;
}


int bondCheck(BOND **grid){
    int  percolates = 1;
    for(int i=0;i<gridS;i++) {
#pragma omp parallel for
        for (int j = 0; j < gridS; j++) {
            BOND *gridPoint = &grid[i][j];
            int visitedRows[gridS];
            int visitedCols[gridS];
            for (int p=0;p < gridS; p++){
                visitedRows[p]=1;
                visitedCols[p]=1;
            }
            visitedRows[i]=0;
            visitedCols[j]=0;
            int clusterSize=0;
            pushBond(gridPoint);
            while(isemptyBond()==1){
                    BOND *bond;
                            bond = popBond();
                                visitedRows[bond->nodei]=0;
                                visitedCols[bond->nodej]=0;
                        //Check each bond, update check array and push node onto stack
                        if(bond->rBond == 0){
                            pushBond(bond->east);
                        }
                        if(bond->bBond == 0){
                            pushBond(bond->south);
                        }
                        if(bond->west->rBond == 0) {
                            pushBond(bond->west);
                        }
                        if(bond->north->bBond == 0) {
                            pushBond(bond->north);
                        }
                        clusterSize +=1;
                    }
#pragma omp critical
            {
                if (clusterSize > lrgestCluster)lrgestCluster = clusterSize;
                if (percolates == 1) {
                    if (percT == 0) {
                        for (int e = 0; e < gridS; e++) {
                            if (visitedRows[e] == 1) {
                                break;
                            }
                            if (e == gridS - 1) {
                                percolates = 0;
                            }
                        }
                    } else if (percT == 1) {
                        for (int e = 0; e < gridS; e++) {
                            if (visitedCols[e] == 1) {
                                break;
                            }
                            if (e == gridS - 1) {
                                percolates = 0;
                            }
                        }
                    } else {
                        for (int e = 0; e < gridS; e++) {
                            if ((visitedCols[e] == 1 || visitedRows[e] == 1)) {
                                break;
                            }
                            if (e == gridS - 1) {
                                percolates = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return percolates;
}
