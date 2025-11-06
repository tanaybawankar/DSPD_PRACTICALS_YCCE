#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, n;
    int arr1[n];
    int sum_even = 0;
    int sum_odd = 0;
    printf("\nENTER THE SIZE OF ARREY:");
    scanf("%d", &n);

    printf("ENTER THE ELEMENT:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // perform sum operation of element of arrey
    // even index add
    for (i = 0; i <= n; i += 2)
    {
        sum_even = sum_even + arr1[i];
    }
    // odd index add
    for (j = 1; j <= n; j += 2)
    {
        sum_odd = sum_odd + arr1[j];
    }
    printf("\nSUMMESSSION_OF_ODD_INDEX_ARREY_ELEMENT:%d", sum_odd);
    printf("\nSUMMESSION_OF_EVEN_INDEX_ARREY_ELEMENT;%d", sum_even);
    return 0;
}