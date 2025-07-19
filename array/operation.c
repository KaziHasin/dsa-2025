#include <stdio.h>

// Traversal array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion array
int insertInd(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

// deletion array
int deleteInd(int arr[], int size, int index)
{
    if (index >= size)
    {
        return -1;
    }

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{

    int arr[10] = {3, 5, 7, 8, 9};
    int size = 5, element = 11, capacity = 10, index = 3;

    printf("Array Traversal: \n");
    display(arr, size);
    insertInd(arr, size, element, capacity, index);
    printf("Array Insertion: \n");
    size += 1;
    display(arr, size);

    deleteInd(arr, size, 1);
    printf("Array Deletion: \n");

    size -= 1;
    display(arr, size);

    return 0;
}