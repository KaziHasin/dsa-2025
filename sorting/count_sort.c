#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maxNumber(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maxNumber(arr, n);

    // Create the count array
    int *countArr = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        countArr[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        countArr[arr[i]] = countArr[arr[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array A

    while (i <= max)
    {
        if (countArr[i] > 0)
        {
            arr[j] = i;
            countArr[i] = countArr[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {12, 11, 13, 7, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, size);

    countSort(arr, size);
    printf("Sorted array is \n");
    printArray(arr, size);
    return 0;
}
