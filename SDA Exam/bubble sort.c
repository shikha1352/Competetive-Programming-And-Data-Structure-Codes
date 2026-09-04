#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("The elements are:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int p=0;
    for(int i=0;i<n-1;i++)
    {
        p++;
        printf("\nThe number of pass %d:",p);
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
            printf("\n");
            for(int k=0;k<n;k++)
            {
                printf("%d ",a[k]);
            }

        }
        if(flag==0)
        {
            break;
        }
    }
    printf("\nThe array after bubble sort:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
