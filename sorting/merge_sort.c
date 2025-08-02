#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
    int size = 100;
    int i = low, j = mid + 1, k = low, b[size];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8, 3, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting : \n");
    printArray(arr, size);

    mergeSort(arr, 0, size);

    printf("After sorting : \n");
    printArray(arr, size);
    return 0;
}