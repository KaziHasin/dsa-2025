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

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, pass = 1;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        printf("Pass %d:\n", pass++);

        for (j = i + 1; j < n; j++)
        {
            printf("  Compare %d and %d\n", arr[j], arr[minIndex]);
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
        else
        {
            printf("No swap needed\n");
        }
    }
}

int main()
{

    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting : \n");
    printArray(arr, size);
    selectionSort(arr, size);

    printf("After sorting : \n");
    printArray(arr, size);
    return 0;
}