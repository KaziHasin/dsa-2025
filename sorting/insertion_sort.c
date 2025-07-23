#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, j, key, pass = 1;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        printf("Pass %d:\n", pass++);

        while (j >= 0 && arr[j] > key)
        {
            printf("  Compare %d > %d → shift %d to right\n", arr[j], key, arr[j]);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("  Insert %d at position %d\n", key, j + 1);
    }
}

int main()
{

    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting : \n");
    printArray(arr, size);
    insertionSort(arr, size);

    printf("After sorting : \n");
    printArray(arr, size);

    return 0;
}