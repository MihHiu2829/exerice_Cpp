#include <stdio.h>
#include <stdlib.h>
static int length = 0;
typedef struct date
{
    int ngay, thang, nam;
} date;
typedef struct quanlikhachhang
{
    char maKhachhang[10], hoVaTen[30];
    long tongChiTieu;
    date ngaysinh, ngayGiaNhap;
} ql;
ql a[100];
void nhap1KhachHang(ql *a)
{
    printf("Nhap ho ten khach hang: \n");
    fflush(stdin);
    gets(a->hoVaTen);
    printf("Nhap ma khach hang: \n");
    fflush(stdin);
    gets(a->maKhachhang);
    printf("Nhap ngay thang nam sinh cua khach hang %s :\n", a->hoVaTen);
    scanf("%d/%d/%d", &a->ngaysinh.ngay, &a->ngaysinh.thang, &a->ngaysinh.nam);
    printf("Nhap ngay gia nhap cua khach hang: \n");
    scanf("%d/%d/%d", &a->ngayGiaNhap.ngay, &a->ngayGiaNhap.thang, &a->ngayGiaNhap.nam);
    printf("Nhap tong chi tieu cua khach hang: \n");
    scanf("%d", &a->tongChiTieu);
}
void nhapKhachHang(ql a[])
{
    int i;
    printf("Nhap so luong khach hang: \n");
    scanf("%d", &length);
    for (i = 0; i < length; i++)
    {
        printf("Nhap thong tin khach hang thu %d\n", i + 1);
        nhap1KhachHang(&a[i]);
    }
}
void luuDanhSachKhachHangXuongFile(ql a[], int n)
{
    FILE *p;
    p = fopen("khachhang.inp", "w");
    fprintf(p, "Danh sach thong tin khach hang!\n");
    fprintf(p, "%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(p, "%-20s %-20s %-2d/%-2d/%-12d   %-2d/%-2d/%-5d   %10d\n", a[i].hoVaTen, a[i].maKhachhang, a[i].ngayGiaNhap.ngay, a[i].ngayGiaNhap.thang, a[i].ngayGiaNhap.nam, a[i].ngaysinh.ngay, a[i].ngaysinh.thang, a[i].ngaysinh.nam, a[i].tongChiTieu);
    }
    fclose(p);
}
void xuat1KhachHang(ql a)
{
    printf("%-20s %-20s %-2d/%-2d/%-12d   %-2d/%-2d/%-5d   %10d\n", a.hoVaTen, a.maKhachhang, a.ngayGiaNhap.ngay, a.ngayGiaNhap.thang, a.ngayGiaNhap.nam, a.ngaysinh.ngay, a.ngaysinh.thang, a.ngaysinh.nam, a.tongChiTieu);
}
ql Max(int n)
{
    if (n == 1)
        return a[0];
    else
    {
        if (a[n - 1].tongChiTieu > Max(n - 1).tongChiTieu)
            return a[n - 1];
        else
            return Max(n - 1);
    }
}
double sotientrungbih()
{
    int sum = 0, i;
    for (i = 0; i < length; i++)
    {
        sum += a[i].tongChiTieu;
    }
    return ((float)sum / length);
}
void themKhachHangOViTriX(int x)
{
    int i;
    for (i = length; i > x; i--)
    {

        a[i] = a[i - 1];
    }
    ql pa;
    nhap1KhachHang(&pa);
    a[x] = pa;
    length++;
    printf("%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
    for (i = 0; i < length; i++)
    {
        xuat1KhachHang(a[i]);
    }
}
void xoa1khachhang(int x)
{
    int i;
    for (i = x; i < length - 1; i++)
    {
        a[i] = a[i + 1];
    }
    length--;
}
void swap(ql *xp, ql *yp)
{
    ql temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort()
{
    int i, j;
    for (i = 0; i < length - 1; i++)
        for (j = 0; j < length - i - 1; j++)
            if (a[j].tongChiTieu < a[j + 1].tongChiTieu)
                swap(&a[j], &a[j + 1]);
}
void funtion_1()
{
    nhapKhachHang(a);
    luuDanhSachKhachHangXuongFile(a, length);
}

void funtion_2()
{
    int n = length;
    printf("Khach hang co luong chi tieu nhieu nhat.\n");
    printf("%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
    xuat1KhachHang(Max(n));
}
void funtion_3()
{
    printf("Danh sach khach hang sinh vao thang 1! \n");
    int i, flag = 0;
    printf("%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
    for (i = 0; i < length; i++)
    {
        if (a[i].ngaysinh.thang == 1)
        {
            xuat1KhachHang(a[i]);
            flag = 1;
        }
    }
    if (!flag)
        printf("KHONG CO KHACH HANG SINH THANG 1! \n");
}
void funtion_4()
{
    double money = sotientrungbih();
    printf("So tien trung binh tat ca cac khach hang chi tieu la: %f\n", money);
}
void funtion_5()
{
    int x;
    do
    {
        printf("Nhap vi tri ban muon them khanh hang: \n");
        scanf("%d", &x);
        if (x > length)
            printf("Nhap sai, nhap lai!\n");
    } while (x > length);
    themKhachHangOViTriX(x);
}
void funtion_6()
{
    int i, flag = 0;
    for (i = 0; i < length; i++)
    {
        if (2020 - a[i].ngaysinh.nam > 60)
        {
            xoa1khachhang(i);
            flag = 1;
        }
    }
    if (flag)
    {
        printf("%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
        for (i = 0; i < length; i++)
        {
            xuat1KhachHang(a[i]);
        }
    }
    else
        printf("KHong co khach hang nao lon don 60 tuoi de xoa! \n");
}
void funtion_7()
{
    bubbleSort();
    int i;
    FILE *p;
    p = fopen("khachhang.out", "w");
    fprintf(p, "Danh sach thong tin khach hang!\n");
    fprintf(p, "%-20s %-20s %-20s %-18s %s\n ", "Ho va ten", "Ma khach hang", "Ngay Gia nhap", "Ngay sinh", "Chi tieu");
    for (i = 0; i < length; i++)
    {
        fprintf(p, "%-20s %-20s %-2d/%-2d/%-12d   %-2d/%-2d/%-5d   %10d\n", a[i].hoVaTen, a[i].maKhachhang, a[i].ngayGiaNhap.ngay, a[i].ngayGiaNhap.thang, a[i].ngayGiaNhap.nam, a[i].ngaysinh.ngay, a[i].ngaysinh.thang, a[i].ngaysinh.nam, a[i].tongChiTieu);
    }
    fclose(p);
}
int main()
{
    int luachon;
    printf("Chuong trinh quan li danh sach khach hang.\n");
    do
    {
        printf("1. Nhap vao ho so cua cac thuong de va luu vao ta\n");
        printf("2. Tim khach hang co tong chi tieu cao nhat bang ky thuat de quy. \n");
        printf("3. Cho biet co bao nhieu khach hang sinh vao thag mot, in danh sach cac khach hang do\n");
        printf("4. Tinh trung binh so tien chi tieu cua mot khach hang. \n");
        printf("5. Them mot khach hang moi vao danh sach o vi tri x. \n");
        printf("6. Xoa cac khach hang co tuoi lon hon 60 trong danh sach. \n");
        printf("7. Sap xep danh sach khach giam dan theo tong chi tieu bang phuong phap Noi Bot (Bubble sort) va luu vao file khachhang.out\n");
        printf("0. Thoat chuong trinh. \n");
        printf("Vui long chon chuc nang: ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 1:
            funtion_1();
            break;
        case 2:
            funtion_2();
            break;
        case 3:
            funtion_3();
            break;
        case 4:
            funtion_4();
            break;
        case 5:
            funtion_5();
            break;
        case 6:
            funtion_6();
            break;
        case 7:
            funtion_7();
            break;
        }
    } while (luachon != 0);
    printf("Chuong trinh da thoat\n"); 
}