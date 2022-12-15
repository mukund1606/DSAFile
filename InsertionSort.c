#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int *insertionSort(int n);

int main()
{
    int n, i, *a;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    a = insertionSort(n);
    printf("Array After Insertion Sort:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    getch();
    clrscr();
    return 0;
}

int *insertionSort(int n)
{
    int *a, b, i, j;
    a = (int *)malloc(n * sizeof(int));
    printf("Enter Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b);
        // If Elem = 1;
        if (i == 0)
        {
            a[i] = b;
        }
        else
        {
            j = i - 1;
            while (j >= 0 && a[j] > b)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = b;
        }
    }
    return a;
}
