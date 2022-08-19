#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* vectorReading(int n);
int* dynamic_int(int size);
int searchInsert(int* nums, int numsSize, int target);

int main(void)
{
    int n, findIT;

    printf("nr of elements: ");
    scanf("%d", &n);

    int* vector = vectorReading(n);

    printf("\nThe number who are looking for: ");
    scanf("%d", &findIT);

    int pos = searchInsert(vector, n, findIT);

    printf("the corresponding position is: %d", pos);

    return 0;
}

int* vectorReading(int n)
{
    int* vec = dynamic_int(n);
    int i;

    for (i = 0; i < n; ++i)
    {
        printf("vector[%d] = ", i);
        scanf("%d", vec + i);
    }
    return vec;
}

int* dynamic_int(int size)
{
    int* vector = malloc(size * sizeof(int));

    if (!vector)
    {
        fprintf(stderr,"Allocation Failed!/n");
        exit(EXIT_FAILURE);
    }
    return vector;
}

int searchInsert(int* nums, int numsSize, int target)
{
    int i, val = 0;

    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] == target)
        {
            return i;
        }
        else if (target > nums[i])
        {
            val = i + 1;
        }
    }
    return val;
}