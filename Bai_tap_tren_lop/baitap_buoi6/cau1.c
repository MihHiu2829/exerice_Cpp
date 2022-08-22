#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int timkiemtuantu(int a[100], int n, int x)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
            return 1;
    }
    return 0;
}
void quicksort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i < j);
    if (left < j)
        quicksort(a, left, j);
    if (right > i)
        quicksort(a, i, right);
}
int timkiemnhiphan(int a[100], int n, int x)
{
    quicksort(a, 0, n - 1);
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return 1;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}
int main()
{
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int a[100];
    srand((int)time(0));
    for (i = 0; i < n; i++)
    {
        a[i] = -100 + rand() % (100 + 1 + 100);
    }
    printf("Nhap phan tu muon tim: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    if (timkiemnhiphan(a, n, x))
        printf("\nco phan tu %d trong mang phat sinh ngau nhien.\n", x);
    else
        printf("\nKhong co phan tu %d trong mang phat sinh ngau nhien.\n", x);
        
    if (timkiemtuantu(a, n, x))
        printf("\nco phan tu %d trong mang phat sinh ngau nhien.\n", x);
    else
        printf("\nKhong co phan tu %d trong mang phat sinh ngau nhien.\n", x);
}