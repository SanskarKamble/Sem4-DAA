#include <stdio.h>
#include <limits.h>
// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
int MatrixChainOrder(int p[], int i, int j)
{
    if (i==j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)+ MatrixChainOrder(p, k + 1, j)+ p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}
int main()
{
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
   for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);
    
    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(arr, 1, n-1));
    getchar();
    return 0;
}