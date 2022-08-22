#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SumCur(int n)
{
    if (n == 0  )
        return 0  ;         `
    return pow(-1, n) * n + SumCur(n - 1);
}
int SumBaSic(int n)
{
    int i, sum = 0;
    for ( i = 1 ; i <= n; i++)
    {
        sum += pow(-1, i) * i;          
    }
    return sum;
}
int main()
{
    int n;
    printf("Nhap 1 so nguyen duong: ");
    scanf("%d", &n);
    printf("Tong day so  giai theo de quy : %d\n", SumCur(n));
    printf("Tong day so giai thep cach thong thuong : %d", SumBaSic(n));
}
