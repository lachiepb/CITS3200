#include "percolation.h"
#include "stackSite.h"
#include "stackBond.h"

#define CHARLEN 20

//global variables, gridS = grid size, p = probability
//perc = site/bond perc., percT = top to bottom/ left to right/ both
int gridS = 0;
float p = 0.0;
int percT;
int lrgestCluster;

//struct for each grid node


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

//percolation type input
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

            gp->west = &grid[NSEW[3]][j];
            gp->east = &grid[NSEW[2]][j];
            gp->south = &grid[i][NSEW[1]];
            gp->north = &grid[i][NSEW[0]];
            gp->visited = 1;
        }
    }
}

void joinGridB(BOND **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            BOND *gp = &grid[i][j];
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

            gp->west = &grid[NSEW[3]][j];
            gp->east = &grid[NSEW[2]][j];
            gp->south = &grid[i][NSEW[1]];
            gp->north = &grid[i][NSEW[0]];
            gp->visited = 1;
            for (int k=0;k < 4; k++){
                gp->check[k]=1;
            }
        }
    }
}
//function for determining if a grid node is occupied for site percolation 
void sitePerc(NODE **grid){
    for (int i=0; i < gridS; i++){
        for (int j=0; j < gridS; j++){
            NODE *gp = &grid[i][j];
            float occup;

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

            rOccup = rand();
            rOccup /= (RAND_MAX);
            bOccup = rand();
            bOccup /= (RAND_MAX);

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
// fetch from queue, add to queue.
int siteDFS(NODE *gridPoint){
    if(gridPoint->occu==1) return 0;
    
    
    

    return 1;
}

int siteCheck(NODE **grid){ 
    // exhaustively check every node (skip if visited)
    int percolates=1;

    for(int i=0;i<gridS;i++){
        for(int j=0;j<gridS;j++){
            NODE *gridPoint=&grid[i][j];
            if(gridPoint->visited==0) continue;

            int visitedRows[gridS];
            int visitedCols[gridS];

            for (int p=0;p < gridS; p++){
                visitedRows[p]=1;
                visitedCols[p]=1;
            }

            visitedRows[i]=0;
            visitedCols[j]=0;
            // fill 0's
            int clusterSize=0;
            if(gridPoint->occu==0) pushSite(gridPoint);
            printf(" i %i j %i \n" ,i,j);

            while(isemptySite()==1){
                #pragma omp parallel reduction(+:clusterSize) shared(i,j,visitedRows,visitedCols)
                {
                
                    NODE *site;
                    int temp=1;
                    #pragma omp critical
                    {
                        if(isemptySite()==1){
                            site = popSite();
                            if (site->visited==1){
                                site->visited=0;
                                visitedRows[site->nodei]=0;
                                visitedCols[site->nodej]=0;
                                
                                temp=0;
                            }
                            
                        }
                    }
                    //printf("%i\n",topS);
                    printf("%i  i %i j %i \n" ,isemptySite(),i,j);
                    #pragma omp barrier
                    if (temp == 0){
                        if(site->north->visited==1 && site->north->occu==0){
                            pushSite(site->north);
                        }

                        if(site->south->visited==1 && site->south->occu==0){
                        pushSite(site->south);
                        }

                        if(site->east->visited==1 && site->east->occu==0){
                        pushSite(site->east);
                        }

                        if(site->west->visited==1 && site->west->occu==0){
                        pushSite(site->west);
                        }
                        clusterSize+=1;
                    }
                }
            }

            if (clusterSize>lrgestCluster)lrgestCluster=clusterSize;
            if (percolates==1) {
                if (percT == 0) {
                    for (int e = 0; e < gridS; e++) {
                        if (visitedRows[e] == 1){
                            break;
                        }

                        if (e ==  gridS - 1){
                            percolates = 0;
                        }
                    }
                } else if (percT == 1){
                    for (int e = 0; e < gridS; e++) {
                        if (visitedCols[e] == 1){
                            break;
                        }

                        if (e ==  gridS - 1){
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
            //Clear the array
        }
    }
    return percolates;
}

int bondDFS(BOND *gridPoint,int visitedRows[], int visitedCols[]){
    if(gridPoint->visited==0) return 0;
    gridPoint->visited = 0;
    if(gridPoint->rBond == 0 && gridPoint->check[0] == 1){
        gridPoint->check[0] = 0;
        gridPoint->east->check[2] = 0;
        pushBond(gridPoint->east);
    } else {
        gridPoint->check[0] = 0;
        gridPoint->east->check[2] = 0;
    }

    if(gridPoint->bBond == 0 && gridPoint->check[1] == 1){
        gridPoint->check[1] = 0;
        gridPoint->south->check[3] = 0;
        pushBond(gridPoint->south);
    } else {
        gridPoint->check[1] = 0;
        gridPoint->south->check[3] = 0;
    }

    if(gridPoint->west->rBond == 0 && gridPoint->check[2] == 1) {
        gridPoint->check[2] = 0;
        gridPoint->west->check[0] = 0;
        pushBond(gridPoint->west);
    } else {
        gridPoint->check[2] = 0;
        gridPoint->west->check[0] = 0;
    }

    if(gridPoint->north->bBond == 0 && gridPoint->check[3] == 1) {
        gridPoint->check[3] = 0;
        gridPoint->north->check[1] = 0;
        pushBond(gridPoint->north);
    } else {
        gridPoint->check[3] = 0;
        gridPoint->north->check[1] = 0;
    }
    return 1;
}

int bondCheck(BOND **grid){
    int  percolates = 1;

    for(int i=0;i<gridS;i++) {
        for (int j = 0; j < gridS; j++) {
            BOND *gridPoint = &grid[i][j];
            if (gridPoint->visited == 0) continue;

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
                #pragma omp parallel reduction(+:clusterSize) shared(visitedRows,visitedCols)
                {
                    BOND *bond;
                    int temp;
                    #pragma omp critical 
                    {
                        if(isemptyBond()==1){
                            bond = popBond();
                            visitedRows[bond->nodei]=0;
                            visitedCols[bond->nodej]=0;
                            temp=0;
                        }
                    }

                    if (temp == 0){
                        clusterSize += bondDFS(bond, visitedRows, visitedCols);
                    }
                }
            }

            if (clusterSize>lrgestCluster)lrgestCluster=clusterSize;
            if (percolates==1) {
                if (percT == 0) {
                    for (int e = 0; e < gridS; e++) {
                        if (visitedRows[e] == 1){
                            break;
                        }

                        if (e ==  gridS - 1){
                            percolates = 0;
                        }
                    }                
                } else if (percT == 1){
                    for (int e = 0; e < gridS; e++) {
                        if (visitedCols[e] == 1){
                            break;
                        }

                        if (e ==  gridS - 1){
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
    return percolates;
}


