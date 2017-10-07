
#include"percolation.h"

int trdCount;

int main(int argc, char *argv[])
{
    // expected input =  program name + site/bond + probablility + gridsize + percolation type (0, horiz, 1, vert, 2 vert+horiz)
    //

    if(argc>6){
        printf("Too many arguments supplied! (Exiting)");
        exit(EXIT_SUCCESS);
    }

    if(argc<6){
        printf("too few arguments, treating you like a base level plebian");
        exit(EXIT_SUCCESS);
    }

    int valido=0;
    int validg=0;
    int validp;
    int validt=0;
    int validq=0;
    srand(time(NULL));


    if(strcmp("s",argv[1])==0){
        validp=0;

    } else if (strcmp("b",argv[1])==0){
        validp=1;
    } else {
        validp=2;
    }

    for (int i=0;i<strlen(argv[2]);i++){
        if (isdigit(argv[2][i]) == 0 && argv[2][i]!='.'){
            valido=1;
        }
    }

    if (valido==0) {
        p = atof(argv[2]);
        if (p < 0.0 || p > 1.0) {
            valido = 1;
        } else {
            valido = 0;
        }
    }

    //gridsize
    for(int i=0; i < strlen(argv[3]);i++) {
        if (isdigit(argv[3][i]) == 0) {
            validg = 1;
        }
    }
    //Check Validity of grid argument
    if (validg == 0){
        gridS=atoi(argv[3]);
    }
    // Check validity of Type Argument
    for (int i=0;i<strlen(argv[4]);i++) {
        if (isdigit(argv[4][i]) == 0) {
            validt = 1;
        }
    }

    if (validt == 0){
        percT=atoi(argv[4]);
    }

    for (int i=0; i < strlen(argv[5];i++) {
        if (isdigit(argv[5][i]==0){
            validq = 1;
        }
    }

    if (validq == 0){
        trdCount = atoi(argv[5]);
    }

    while (validp==2) {
        printf ("\nInput was incorrect,try again, or insert 'EXIT' to exit");
        validp = percStatus();
    }

    while (valido==1){
        printf("\nInput was incorrect,try again, or insert 'EXIT' to exit");
        valido = occupancy();
    }


    while (validg==1){
        printf("\nInput was incorrect,try again, or insert 'EXIT' to exit");
        validg = gridSize();
    }

    while (validt==1){
        printf ("\nInput was incorrect,try again, or insert 'EXIT' to exit");
        validt = percType();
    }

    while (validq==1){
         printf ("\nInput was incorrect,try again, or insert 'EXIT' to exit");
         validq = trdReturn();
    }

    omp_set_num_threads(trdCount);

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
            printf("\n The grid percolates with largest cluster %i\n",lrgestCluster);
        } else {
            printf("\n The grid does not percolate and has a largest cluster of %i\n",lrgestCluster);
        }
    } else {
        BOND **grid;
        grid = (BOND **) malloc(sizeof(BOND *) * gridS);
        for (int i=0; i < gridS; i++){
            grid[i]= (BOND *) malloc(sizeof(BOND) * gridS);
        }

        joinGridB(grid);
        bondPerc(grid);
        int ans = bondCheck(grid);

        if (ans==0){
            printf("\n The grid percolates with largest cluster %i",lrgestCluster,stdout);
        } else {
            printf("\n The grid does not percolate and has a largest cluster of %i",lrgestCluster,stdout);
        }
    }


    exit (EXIT_SUCCESS);
}

