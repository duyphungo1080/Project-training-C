#ifndef HEADER_H
#define HEADER_H

typedef struct {
    char nguoiGui[35];
    char maDon[8];
    char donHang[50];
    char ngayGui[7];
    int loai;
    float khoiLuong;
    char nguoiNhan[35];
    char SDT[11];
    char diaChi[70];
    char ngayNhan[7];
    float soTien;
    int tinhTrangDon;
} vanChuyen;

int kiemTraNguoiGui(char nguoiGui[]);
int kiemTraDonHang(char donHang[]);
int kiemTraNguoiNhan(char nguoiNhan[]);
int kiemTraMD(char maDon[]);
int kiemTraNgayGui(char ngayGui[]);
int kiemTraNgayNhan(char ngayNhan[]);
int kiemTraSDT(char SDT[]);
int kiemTraTinhTrangDon(int trangThai);

void xoaBoNhoDem();
int timViTriTheoMa(vanChuyen ds[], int soLuong, char maDon[]);
void themDonHang(vanChuyen ds[], int *soLuong);
void hienThiDanhSach(vanChuyen ds[], int soLuong);

#endif