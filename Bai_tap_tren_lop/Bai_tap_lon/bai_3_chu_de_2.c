#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang2Chieu(int a[][10], int *n, int *m)
{
    do
    {
        printf("Nhap so dong cho ma tran: ");
        scanf("%d", n);
        printf("Nhap so cot cho ma tran: ");
        scanf("%d", m);

    } while (n < 0 || m < 0);
    int i, j;
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void xuatMang2Chieu(int a[][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n\n");
    }
}
double GiuatriTrungBinh(int a[][10], int n, int m)
{
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum += a[i][j];
        }
    }
    return (float)sum / (n * m);
}
int tichUocSo(int n)
{
    int i, mutil = n;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            mutil *= i;
    }
    return mutil;
}
void tichPhanTuUocSoCuaTongPhanTuTrenDongDo(int a[][10], int n, int m)
{
    int i, k, sum;
    do
    {
        printf("Nhap dong ban muon de tinh tong phan tu uoc so cua cac phan tu tren dong ban vua nhap : ");
        scanf("%d", &k);
    } while (k < 0 || k > n - 1);
    for (i = 0; i < m; i++)
        sum += a[k][i];
    printf("Vay tich phan tu cua uoc so tren dong %d la : %d\n", k, tichUocSo(sum));
}

int demSoLuongSoChanTren1Cot(int a[][10], int n, int k)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        if ((a[i][k]) % 2 == 0)
            count++;
    return count;
}
void demSoLuongSoChanTrenMoiCot(int a[][10], int n, int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        printf("So phan tu chan tren cot %d la: %d\n", i, demSoLuongSoChanTren1Cot(a, n, i));
    }
}
int isPrime(int n)
{

    if (n < 2)
        return 0;
    int i;
    for (i = 2; i <= sqrt(n); i++)
        if ((n % i) == 0)
            return 0;
    return 1;
}
void sort(int A[], int n)
{
    int key;
    int i, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[i] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
int soNguyenToLonNhiTrongmang(int A[][10], int n, int m)
{
    int i, j, a[100], size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (isPrime(A[i][j]))
                a[size++] = A[i][j];
        }
    }
    sort(a, size);
    return a[size - 2];
}
int is9phuong(int n)
{
    int i = 1;
    while (i * i > n)
    {
        if (i * i == n)
            return 1;
        i++;
    }
    return 0;
}
void Sort9Phuong(int A[][10], int n, int m)
{
    int i, a, b;
    for (i = 0; i < m; i++)
    {
        int haveSwap = 0;
        for (a = 0; a < n - 1; a++)
        {
            haveSwap = 0;
            for (b = 0; b < n - a - 1; b++)
            {
                if (is9phuong(A[b][i]) == 1 && is9phuong(A[b + 1][i]) == 1)
                    if (A[b][i] > A[b + 1][i])
                    {
                        int tmp = A[b][i];
                        A[b][i] = A[b + 1][i];
                        A[b + 1][i] = tmp;
                        haveSwap = 1;
                    }
            }

            if (haveSwap == 0)
                break;
        }
    }
}
int main()
{
    int A[10][10];
    int n, m;
    nhapMang2Chieu(A, &n, &m);
    xuatMang2Chieu(A, n, m);
    printf("Gia tri trung binh cua cac phan tu trong mang: %f\n", GiuatriTrungBinh(A, n, m));
    tichPhanTuUocSoCuaTongPhanTuTrenDongDo(A, n, m);
    demSoLuongSoChanTrenMoiCot(A, n, m);
    printf("Gia tri nguyen to lon thu hai trong mang la: %d\n", soNguyenToLonNhiTrongmang(A, n, m));
    Sort9Phuong(A, n, m);
    printf("Mang sau khi xap xep: \n");
    xuatMang2Chieu(A, n, m);
}