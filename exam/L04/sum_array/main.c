#include <stdio.h>

int get_sum(int len, int arr[len], int idx, int sum)
{
    if (idx == len)
        return (sum);
    sum += arr[idx];
    return(get_sum(len, arr, idx+1, sum));
}

int main(void)
{
    int arr[4] = {5, 2, 4, 8};

    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += arr[i];
    printf("sum: %d\n", sum);
    printf("sum: %d\n", get_sum(4, arr, 0, 0));
    return (0);
}