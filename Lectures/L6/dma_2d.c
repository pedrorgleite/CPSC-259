/*   Dynamic Allocation of a 2-D Array*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ** 	myArray;    /* pointer to a pointer */
    int		j, k, dim_m, dim_n;
    dim_m = 10;
    dim_n = 10;
    
    myArray = (int **) malloc(dim_m * sizeof(int *));
    if (myArray == NULL){
        /* print error message, and probably quit */
        printf("Not enough memory! Goodbye");
    }
    
    /* allocate m rows containing n columns */
    for (k = 0; k < dim_m; k++){
        myArray[k] = (int *) malloc(dim_n * sizeof(int));
        if (myArray[k] == NULL){
            /* print error message, and probably quit */
            printf("Not enough memory! Goodbye");
        }
    }
    
    
    for (j=0; j<dim_n; j++) {
        for (k=0; k<dim_m; k++) {
            myArray[j][k] =j*k;
            printf( "%4.0d", myArray[j][k]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}


/************ output**************
 1   2   3   4   5   6   7   8   9
 2   4   6   8  10  12  14  16  18
 3   6   9  12  15  18  21  24  27
 4   8  12  16  20  24  28  32  36
 5  10  15  20  25  30  35  40  45
 6  12  18  24  30  36  42  48  54
 7  14  21  28  35  42  49  56  63
 8  16  24  32  40  48  56  64  72
 9  18  27  36  45  54  63  72  81
 *********************************/