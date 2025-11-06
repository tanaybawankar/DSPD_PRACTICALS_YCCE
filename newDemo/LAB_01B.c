#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int *SearchList, int size, int target)
{
    if (SearchList == NULL || size == 0)
    {
        return 0; // NULL equivalent for boolean return
    }

    int start = 0;
    int end = size;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        printf("Examining value: %d\n", SearchList[mid]);

        if (SearchList[mid] == target)
        {
            return 1; // Found
        }
        else if (SearchList[mid] < target)
        {
            start = mid + 1;
            printf("Adjusting start to index: %d\n", start);
        }
        else
        {
            end = mid;
            printf("Adjusting end to index: %d\n", end);
        }
    }

    return 0; // Not found
}

int main()
{
    int SearchList[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(SearchList) / sizeof(SearchList[0]);
    int target = 7;

    int result = binarySearch(SearchList, size, target);
    if (result)
    {
        printf("Target %d found.\n", target);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }

    return 0;
}