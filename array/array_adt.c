#include <stdio.h>
#include <stdlib.h>

struct arrayAdt
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct arrayAdt *a, int t_size, int u_size)
{
    // (*a).total_size = t_size;
    // (*a).used_size = u_size;
    // (*a).ptr = (int *)malloc(t_size * sizeof(int));

    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

void show(struct arrayAdt *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void setValue(struct arrayAdt *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element: %d ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct arrayAdt arr;
    createArray(&arr, 10, 2);
    printf("Before set value the array\n");
    setValue(&arr);
    printf("Before showing the array\n");
    show(&arr);
    return 0;
}