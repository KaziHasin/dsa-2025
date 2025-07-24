#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    int isSortted;
    for (i = 0; i < n - 1; i++)
    {
        printf("Number of pass %d: \n", i + 1);
        isSortted = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSortted = 1;
            }
        }
        if (!isSortted)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 4, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting the array: \n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("After sorting the array: \n");
    printArray(arr, size);
    return 0;
}