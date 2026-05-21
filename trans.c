 /* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{ 
     if(M==32 &&N==32)
     {
      int t0,t1,t2,t3,t4,t5,t6,t7;
      int i,row,col;
      for(row=0;row<32;row+=8)
      {
        for(col=0;col<32;col+=8)
        {
          for(i=row;i<row+8;i++)
          {
            t0= A[i][col];
            t1= A[i][col+1];
            t2= A[i][col+2];
            t3= A[i][col+3];
            t4= A[i][col+4];
            t5= A[i][col+5];
            t6= A[i][col+6];
            t7= A[i][col+7];
            B[col][i] =t0;
            B[col+1][i] =t1;
            B[col+2][i] =t2;
            B[col+3][i] =t3;
            B[col+4][i] =t4;
            B[col+5][i] =t5;
            B[col+6][i] =t6;
            B[col+7][i] =t7;
            
          }
        }
      }
     }
     
     if(M==64 && N==64)
      {
       int t0,t1,t2,t3,t4,t5,t6,t7;
      int i,j,row,col;
      for(row=0;row<64;row+=8)
      {
        for(col=0;col<64;col+=8)
        {
          for(i=0;i<4;i++) // upper 4 rows
          {
              t0 = A[row + i][col + 0];
                t1 = A[row + i][col + 1];
                t2 = A[row + i][col + 2];
                t3 = A[row + i][col + 3];

                t4 = A[row + i][col + 4];
                t5 = A[row + i][col + 5];
                t6 = A[row + i][col + 6];
                t7 = A[row + i][col + 7];

                /* A block */
                B[col + 0][row + i] = t0;
                B[col + 1][row + i] = t1;
                B[col + 2][row + i] = t2;
                B[col + 3][row + i] = t3;

                /* temporarily store B block */
                B[col + 0][row + i + 4] = t4;
                B[col + 1][row + i + 4] = t5;
                B[col + 2][row + i + 4] = t6;
                B[col + 3][row + i + 4] = t7;
            }    
                for (j = 0; j < 4; j++)  //swap B and C 
            {
                t0 = A[row + 4][col + j];
                t1 = A[row + 5][col + j];
                t2 = A[row + 6][col + j];
                t3 = A[row + 7][col + j];

                t4 = B[col + j][row + 4];
                t5 = B[col + j][row + 5];
                t6 = B[col + j][row + 6];
                t7 = B[col + j][row + 7];

                /* move C block into correct place */
                B[col + j][row + 4] = t0;
                B[col + j][row + 5] = t1;
                B[col + j][row + 6] = t2;
                B[col + j][row + 7] = t3;

                /* move stored B block */
                B[col + 4 + j][row + 0] = t4;
                B[col + 4 + j][row + 1] = t5;
                B[col + 4 + j][row + 2] = t6;
                B[col + 4 + j][row + 3] = t7;
            }
            for (i = 4; i < 8; i++)  //process D
            {
                t4 = A[row + i][col + 4];
                t5 = A[row + i][col + 5];
                t6 = A[row + i][col + 6];
                t7 = A[row + i][col + 7];

                B[col + 4][row + i] = t4;
                B[col + 5][row + i] = t5;
                B[col + 6][row + i] = t6;
                B[col + 7][row + i] = t7;
            }
            
            
          }
          
          
        }
      }
      
    if(M==61 && N==67)
      {
    int row, col, i, j;

    for(row = 0; row < N; row += 16)
            {
                for(col = 0; col < M; col += 16)
                {
                    for(i = row; i < row + 16 && i < N; i++)
                    {
                        for(j = col; j < col + 16 && j < M; j++)
                        {
                            B[j][i] = A[i][j];
                        }
                    }
                }
            }
        }
      }


/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

