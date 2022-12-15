#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void quickSort(int *a, int FI, int LI);

int quickPart(int *a, int FI, int LI);

int main()
{
    int n, i, *a, FI, LI;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    FI = 0;
    LI = n - 1;
    printf("Enter Elements of Array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array Before Quick Sort:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    quickSort(a, FI, LI);
    printf("\nArray After Quick Sort:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    getch();
    clrscr();
    return 0;
}

void quickSort(int *a, int FI, int LI)
{
    int Q;
    if (FI < LI)
    {
        Q = quickPart(a, FI, LI);
        quickSort(a, FI, Q - 1);
        quickSort(a, Q + 1, LI);
    }
}

int quickPart(int *a, int FI, int LI)
{
    int p, i, j, temp;
    p = a[LI];
    i = FI;
    j = FI - 1;

    while (i < LI)
    {
        if (a[i] > p)
        {
            i++;
        }
        else
        {
            j++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    temp = a[i];
    a[i] = a[j + 1];
    a[j + 1] = temp;
    return j + 1;
}