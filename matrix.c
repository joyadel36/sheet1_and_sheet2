#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// variables
int c1,r1,c2,r2,numofthread;
int matA[10][10];
int matB[10][10];
int matC[10][10];
int step=0;

//take matrixes from user
void read_matrixes()
{
//enter size of matrix A
		printf("\n enter size of matrix A \n");
		printf("enter number of columns    ");
	    scanf("%d",&c1);
	    printf("enter number of rows    ");
	    scanf("%d",&r1);

//enter matrix A
		 printf("\n enter Matrix A \n");

		    for(int i = 0; i <r1; i++ )
		    {
		        for( int j = 0; j <c1; j++ )
		        {
		            scanf("%d",&matA[i][j]);
		            printf("\n");
		        }
		    }
//enter size of matrix B
			printf("\n enter size of  matrix B \n");
				printf("enter number of columns    ");
				scanf("%d",&c2);
				printf("enter number of rows    ");
				 scanf("%d",&r2);
//enter matrix B
	    printf("\n enter Matrix B \n");
	  	    for(int i = 0; i <r2; i++ )
	  	    {
	  	        for( int j = 0; j <c2; j++ )
	  	        {
	  	            scanf("%d",&matB[i][j]);
	  	          printf("\n");
	  	        }
	  	    }

	  	  numofthread=r1;  //number of threads =number of matrix a rows

	}
//print all matrixes
void print_matrixes()
{
	 // Displaying matA
    printf("\n Matrix A \n");
    for (int i = 0; i <r1; i++) {
        for (int j = 0; j < c1; j++)
        	printf("%d ", matA[i][j] );
        printf("\n");
    }

    // Displaying matB
    printf("\n Matrix b \n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j <c2; j++)
        	 printf("%d ", matB[i][j] );
        printf("\n");
    }
    // Displaying the result matrix
       printf("\n Matrix A x Matrix B \n");
       for (int i = 0; i < r1; i++) {
           for (int j = 0; j < c2; j++)
           	printf("%d ", matC[i][j]);
           printf("\n");

       }
}
//thread function
void* multi(void* arg)
{
	int i = step;
    for (int k = 0; k< c2; k++)
    for (int j = 0; j<r2; j++)
     matC[i][k] += matA[i][j] * matB[j][k];
    step++;
}

int main()
{
	read_matrixes() ;

if(c1==r2){

    // declaring four threads
    pthread_t threads[ numofthread];

    // Creating four threads, each evaluating its own part
    for (int i = 0; i < numofthread; i++) {
        pthread_create(&threads[i], NULL, multi, (void*)i);
    }

    // joining and waiting for all threads to complete
    for (int i = 0; i <  numofthread; i++)
        pthread_join(threads[i], NULL);

    print_matrixes();
}
else
{
	printf("error rows of matrix A must equal columns of matrix B \n");
}

    return 0;
}

