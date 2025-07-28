#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    printf("Pivot: %d\n", pivot);

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
}

int main()
{
    int arr[] = {8, 4, 7, 3, 10, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("\nSorted Array:\n");
    printArray(arr, size);
    return 0;
}
