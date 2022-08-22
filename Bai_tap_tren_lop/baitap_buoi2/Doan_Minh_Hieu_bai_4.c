#include <stdio.h>
#include <stdlib.h>
int a[100][100];
int d, c;
void input()
{ // cau a
    printf("Nhap so dong cua ma tran: ");
    scanf("%d", &d);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &c);
    int i, j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void display()
{ // cau b
    int i, j;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
int sum()
{ // cau c
    int i, j, sum = 0;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}
double avg()
{ // cau d
    int tmp = sum();
    return (double)(tmp / (d * c));
}
double trungBinhCongPhanTuDuong()
{ // cau e
    int i, j, sum = 0, count = 0;
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] > 0)
            {
                sum += a[i][j];
                count++;
            }
        }
    }
    return (double)sum / count;
}
void xuatPhanTuNamTrenDongK()
{ // cau f
    int k, i;
    printf("Nhap vao dong k: ");
    scanf("%d", &k);
    printf("cac phan tu tren dong k: \n");
    for (i = 0; i < c; i++)
    {
        printf("%d\t", a[k][i]);
    }
}
int sumCot(int k)
{ // cau g
    int sum, i = 0;
    for (i = 0; i < d; i++)
    {
        sum += a[i][k];
    }
    return sum;
}
int phantulonnhat()
{ // cau h
    int max, i, j = a[0][0];
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}
int main()
{
    input();
    display();
    printf("Tong phan tu trong ma tran: %d\n", sum());
    printf("Trung binh cong cac phan tu trong mang: %f\n", avg());

    printf("Phan tu duong trong mang: %f", trungBinhCongPhanTuDuong());
}
