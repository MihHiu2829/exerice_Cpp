#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct quyenSach
{
    string maSach, tenSach, tacGia;
    bool loaiSach; // gom 2 loai tu nhien va xa hoi
    int namSuatBan, giaTien, soLuong;
} book;
void nhap1quyensach(book &a)
{
    cout << "Nhap ma sach: \n";
    fflush(stdin);
    getline(cin, a.maSach);
    cout << "Nhap ten sach: ";
    getline(cin, a.tenSach);
    cout << "Nhap ten tac gia: ";
    getline(cin, a.tacGia);
    cout << "Loai sach gom 2 loai:" << endl
         << "Chon '0': neu la sach tu nhien. " << endl
         << "Chon '1': neu la sach xa hoi. " <<endl << "Vui long chon: ";  

    int sellect;
    cin >> sellect;
    if (sellect == 0)
        a.loaiSach = false; // tu nhien
    else if (sellect == 1)
        a.loaiSach = true; // xa hoi
    cout << "Nhap nam xuat ban: ";
    cin >> a.namSuatBan;
    cout << "Nhap gia tien cua sach: ";
    cin >> a.giaTien;
    cout << "Nhap so luong sach: ";
    cin >> a.soLuong;
}
void nhapNhungQuyenSach(book a[], int n)
{
    cout << "Hay nhap vao nhung quyen sach!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Quyen sach " << i + 1 << ":";
        nhap1quyensach(a[i]);
    }
}
void xuatThongTin1quyenSach(book a)
{
    printf("%20s %20s %20s %15d %12d %15d %10d\n", a.maSach.c_str(), a.tenSach.c_str(), a.tacGia.c_str(), a.loaiSach, a.namSuatBan, a.giaTien, a.soLuong);
}
void xuatthongtinNhungCuonSach(book a[], int n)
{
    printf("%20s %20s %20s %15s %12s %15s %10s\n", "Ma sach", "Ten sach", "Tac gia", "Loai sach", "Nam xuat ban", "Gia tien", "So luong");
    for (int i = 0; i < n; i++)
    {
        xuatThongTin1quyenSach(a[i]);
    }
}
void them1quyensach(book a[], int &n)
{
    cout << "Hay nhap thong tin quyen sach! " << endl;
    nhap1quyensach(a[n]);
    n++;
}
int tongTien(book a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].giaTien;
    }
    return sum;
}
void sort(book a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].maSach.compare(a[j].maSach) < 0)
                swap(a[i], a[j]);
        }
    }
}
void timSachTheoTen(book a[], int n)
{
    cout << "Nhap ten sach ban muon tim: " << endl;
    string ten;
    int flag = 0;
    fflush(stdin);
    getline(cin, ten);
    for (int i = 0; i < n; i++)
    {
        if (a[i].tenSach.compare(ten) == 0)
        {
            cout << "Tim thay ten sach ban can! " << endl;
            xuatThongTin1quyenSach(a[i]);
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "Khong tim thay ten sach ban can! " << endl;
}
void xuatSachCoNamTrc2000(book a[], int n)
{
    cout << "Nhung quyen sach xuat ban truoc nam 2000: ";
    printf("%20s %20s %20s %15s %12s %15s %10s\n", "Ma sach", "Ten sach", "Tac gia", "Loai sach", "Nam xuat ban", "Gia tien", "So luong");
    for (int i = 0; i < n; i++)
    {
        if (a[i].namSuatBan < 2000) xuatThongTin1quyenSach(a[i]) ; 
    }
}
int demSoLuongSachcoGiaTren50000(book a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].giaTien > 50000)
            dem++;
    }
    return dem;
}
void xuatsachtheoloai(book a[], int n)
{
here:;
    cout << "Vui long chon loai sach de xuat cac quyen sach ra man hinh: " << endl
         << "chon '1': de xuat sach xa hoi." << endl
         << "chon '2': de xuat sach tu nhien." << endl;
    int select;
         cin>>select;
    if (select == 1)
    {
        printf("%20s %20s %20s %15s %12s %15s %10s\n", "Ma sach", "Ten sach", "Tac gia", "Loai sach", "Nam xuat ban", "Gia tien", "So luong");
        for (int i = 0; i < n; i++)
        {
            if (a[i].loaiSach == 1)
                xuatThongTin1quyenSach(a[i]);
        }
    }
    else if (select == 0)
    {
        printf("%20s %20s %20s %15s %12s %15s %10s\n", "Ma sach", "Ten sach", "Tac gia", "Loai sach", "Nam xuat ban", "Gia tien", "So luong");
        for (int i = 0; i < n; i++)
        {
            if (a[i].loaiSach == 0)
                xuatThongTin1quyenSach(a[i]);
        }
    }
    else
    {
        cout << "Khong co thong tin ve loai sach ban chon," << endl
             << "Vui long nhap lai!" << endl;
        goto here;
    }
}
int main()
{
    int n = 0;
    book a[100];
    cout << "Nhap so luong sach muon co trong cua hang! ";
    cin >> n;
    int luachon;
    do
    {
        cout << "\t\tBang thong tin chuc nang !\n";
        cout << "\t1. Nhap thong tin cac cuon sach.\n"
             << "\t2. Xuat thong tin cac cuon sach.\n"
             << "\t3. Them 1 cuon sach.\n"
             << "\t4. Tinh tong thanh tien cua tat ca cac cuon sach.\n"
             << "\t5. Sap xep cac cuon sach theo ma sach\n"
             << "\t6. Tim sach theo te sach.\n"
             << "\t7. Xuat cac cuon sach co nam xuat ban truoc nam 2000.\n"
             << "\t8. So luong sach co gia lon hon 50000.\n"
             << "\t9. Xuat cac cuon sach theo loai(xuat loai nao la do nguoi dung chon).\n"
             << "\t0. Thoat.\n"
             << "\tChon chuc nang: \n";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
            nhapNhungQuyenSach(a, n);
            break;
        case 2:
            xuatthongtinNhungCuonSach(a, n);
            break;
        case 3:
            them1quyensach(a, n);
            break;
        case 4:
            cout << "Tong tien nhung quyen sach:" << tongTien(a, n);
            break;
        case 5:
            sort(a, n);
            cout << "Da sap xep! " << endl;
            ;
            break;
        case 6:
            timSachTheoTen(a, n);
            break;
        case 7:
            xuatSachCoNamTrc2000(a, n);
            break;
        case 8:
            cout << "So sach co gia lon hon 50000: \n" << demSoLuongSachcoGiaTren50000(a, n) << endl;
            break;
        case 9:
            xuatsachtheoloai(a, n);
            break;
        default:
            cout << "Nhap sai so roi, ban hay nhap lai :v\n";
            break;
        }

    } while (luachon != 0);
}