#include<stdio.h>
int main()
{
    int m,n,p,l,sum=0;
    printf("Enter the number of row and colum for A matrix:");
    scanf("%d%d",&m,&n);
    int A[m][n];
    printf("Enter the elements of A matrinx:\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the number of row and colum for B matrix:");
    scanf("%d%d",&p,&l);
    int B[p][l];
    printf("Enter the elements of B matrinx:\n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<l; j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    int C[m][l];
    if(n!=p)
    {
        printf("Multiplication is not possible");
    }

    else
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<l; j++)
            {
                for(int k=0; k<n; k++)
                {
                    sum+=A[i][k]*B[k][j];
                }
                C[i][j]=sum;
                    sum=0;
            }
        }
        printf("The multiplication matrix C is:\n");
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<l; j++)
            {
                printf("%d ",C[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
