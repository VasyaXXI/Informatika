#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#define MAX 50
#define MIN -50

void quickSort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right]>=pivot) && (left<right))
        right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++; //
        }
        while ((numbers[left] <= pivot) && (left<right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left<pivot)
        quickSort(numbers, left, pivot - 1);
    if (right>pivot)
        quickSort(numbers, pivot + 1, right);
}

int main()
{
    srand(time(NULL));
    int min, max;
    int n, h;
    int j, i;
    int k, f, M, N1;
    printf("vvedite kol vo elementov v massive\n");
    while(!scanf("%d", &n) || n>100 || n<0)
    {
        printf("oshibka poprobuite eshe raz\n");
        fflush(stdin);
    }
    int a[n];

    min = -51;
    max = 51;
    int pick;
    printf("\n1 auto\n2 hand by\n");
    scanf("%d", &pick);
    switch(pick)
    {
        case 1:
        for(j = 0; j<n; j++)
        {
            a[j] = rand()%(MAX - MIN + 1) + MIN;
        }
        break;
    case 2:
        printf("\nVvodite elementi\n");
        for(j = 0; j<n; j++)
        {
            while(!scanf("%d", &a[j]))
            {
                printf("oshibka poprobuite eshe raz\n");
                fflush(stdin);
            }

        }
        break;
    }
    for(j = 0; j<n; j++)
    {
        printf("%3d ", a[j]);
    }
    printf("\n");
    f = 0;
    h = 0;
    while(h <= 100)
    {
        h++;
        for(i = 0; i<n; i++)
        {
            for(j = i+1; j<n; j++)
            {
                if(a[i] == a[j])
                {
                    for(k=j; k<n-1; k++)
                        a[k] = a[k+1];
                    n--;
                    f = 1;
                }
            }
        }
    }
    if(f==1)
    {
        printf("\nPoluchennyi massiv imeet vid:\n");
        for(j = 0; j<n; j++)
        {
            printf("%4d ", a[j]);
        }
        printf("\n");
    }
    else
    {
        printf("\nPovtoreniy v massive net.\n");
    }

    printf("\n Choose command\n1 puzirik\n2 Quick\n");
    scanf("%d", &pick);
    switch(pick)
    {
        case 1:
        for (i = n-1; i>=0; i--)
        {
            for (j = 0; j<i; j++)
            {
                if (a[j]>a[j+1])
                {
                    k = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = k;
                }
            }
    }
    break;
    case 2:
        quickSort(a, 0, n-1);
        break;
    }


    for(j = 0; j<n; j++)
    {
        printf("%3d ", a[j]);
    }
    printf("\n");

    printf("vvedite chisla M and N cherez Enter\n");
    while(!scanf("%d", &M))
    {
        printf("oshibka poprobuite eshe raz\n");
        fflush(stdin);
    }
    while(!scanf("%d", &N1))
    {
        printf("oshibka poprobuite eshe raz\n");
        fflush(stdin);
    }
    if(M<=n)
    {
        printf("\n%d minimum = %d", M, a[M-1]);
    }
    else
    {
        printf("\ntakogo elementa M net\n");
        fflush(stdin);
    }
    if(N1<=n)
    {
        printf("\n%d max = %d", N1, a[n-N1]);
    }
    else
    {
        printf("\ntakogo elementa N net\n");
        fflush(stdin);
    }


    return 0;
}
