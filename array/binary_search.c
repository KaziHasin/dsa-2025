#include <stdio.h>

int searchIndex(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 5;
    int searchedIndex = searchIndex(arr, size, element);

    if (searchedIndex != -1)
    {
        printf("Element %d found at index %d.\n", element, searchedIndex);
    }
    else
    {
        printf("Element %d not found in the array.\n", element);
    }
    return 0;
}