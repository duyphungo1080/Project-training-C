#include <stdio.h>
#include <string.h>
#include "header.hpp"

#define MAX_DON_HANG 100

void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int timViTriTheoMa(vanChuyen ds[], int soLuong, char maDon[]) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maDon, maDon) == 0) {
            return i;
        }
    }
    return -1;
}

void themDonHang(vanChuyen ds[], int *soLuong) {
    if (*soLuong >= MAX_DON_HANG) {
        printf("\nDanh sach don hang da dat gioi han!\n");
        return;
    }

    vanChuyen vcMoi;
    printf("\n================ NHAP THONG TIN DON HANG MOI ================\n");


    do {

        printf("Ten nguoi gui: ");
        fgets(vcMoi.nguoiGui, sizeof(vcMoi.nguoiGui), stdin);
        vcMoi.nguoiGui[strcspn(vcMoi.nguoiGui, "\n")] = 0;

        if (kiemTraNguoiGui(vcMoi.nguoiGui) == 0) {

            printf("-> Cu phap khong hop le\n");

        }
    } while (kiemTraNguoiGui(vcMoi.nguoiGui) == 0);

    int trungMa;
    do {

        trungMa = 0;
        printf("Ma don: ");
        scanf("%s", vcMoi.maDon);

        xoaBoNhoDem();

        if (kiemTraMD(vcMoi.maDon) == 0) {

            printf("-> Ma don khong hop le\n");

        } else if (timViTriTheoMa(ds, *soLuong, vcMoi.maDon) != -1) {

            printf("-> Ma don nay da ton tai\n");
            trungMa = 1;

        }

    } while (kiemTraMD(vcMoi.maDon) == 0 || trungMa == 1);

    do {

        printf("Ten don hang: ");
        fgets(vcMoi.donHang, sizeof(vcMoi.donHang), stdin);
        vcMoi.donHang[strcspn(vcMoi.donHang, "\n")] = 0;

        if (kiemTraDonHang(vcMoi.donHang) == 0) {

            printf("-> Cu phap khong hop le\n");

        }
        
    } while (kiemTraDonHang(vcMoi.donHang) == 0);

    int loaiHang;
    do {

        printf("Chon loai hang hoa (1: Tai lieu | 2: Hang hoa binh thuong): ");
        scanf("%d", &loaiHang);

        xoaBoNhoDem();

        if (loaiHang != 1 && loaiHang != 2) {

            printf("-> Lua chon khong hop le! Vui long chon 1 hoac 2.\n");

        }

    } while (loaiHang != 1 && loaiHang != 2);

    if (loaiHang == 1) {

        vcMoi.khoiLuong = 0;
        vcMoi.soTien = 25000;
        printf("-> Phi van chuyen: 25000 VND\n");

    } else {

        do {

            printf("Nhap khoi luong (kg): ");
            scanf("%f", &vcMoi.khoiLuong);

            xoaBoNhoDem();

            if (vcMoi.khoiLuong <= 0) {
                printf("Gia tri khong hop le!\n");
            }
            
        } while (vcMoi.khoiLuong <= 0);

        if (vcMoi.khoiLuong < 10) {
            vcMoi.soTien = vcMoi.khoiLuong * 3000;
        } else {
            vcMoi.soTien = vcMoi.khoiLuong * 4000;
        }
        printf("-> Phi van chuyen: %.0f VND)\n", vcMoi.soTien);
    }

    do {

        printf("Nhap ngay gui (DDMMYY): ");
        scanf("%s", vcMoi.ngayGui);

        xoaBoNhoDem();

        if (kiemTraNgayGui(vcMoi.ngayGui) == 0) {
            
            printf("-> Ngay gui khong hop le\n");

        }
    } while (kiemTraNgayGui(vcMoi.ngayGui) == 0);


    do {
        printf("Nhap ten nguoi nhan: ");

        fgets(vcMoi.nguoiNhan, sizeof(vcMoi.nguoiNhan), stdin);
        vcMoi.nguoiNhan[strcspn(vcMoi.nguoiNhan, "\n")] = 0;

        if (kiemTraNguoiNhan(vcMoi.nguoiNhan) == 0) {

            printf("-> Ten nguoi nhan khong duoc de trong! Nhap lai.\n");

        }
    } while (kiemTraNguoiNhan(vcMoi.nguoiNhan) == 0);


    do {

        printf("Nhap SDT nguoi nhan: ");
        scanf("%s", vcMoi.SDT);

        xoaBoNhoDem();

        if (kiemTraSDT(vcMoi.SDT) == 0) {

            printf("-> SDT khong hop le! Nhap lai.\n");

        }
    } while (kiemTraSDT(vcMoi.SDT) == 0);

    do {
        printf("Nhap ngay nhan du kien (DDMMYY): ");
        scanf("%s", vcMoi.ngayNhan);

        xoaBoNhoDem();

        if (kiemTraNgayNhan(vcMoi.ngayNhan) == 0) {

            printf("-> Ngay nhan khong hop le! Nhap lai.\n");

        }
    } while (kiemTraNgayNhan(vcMoi.ngayNhan) == 0);

    do {
        printf("Nhap tinh trang don (1: Chua giao | 2: Dang giao | 3: Da giao): ");
        scanf("%d", &vcMoi.tinhTrangDon);

        xoaBoNhoDem();

        if (kiemTraTinhTrangDon(vcMoi.tinhTrangDon) == 0) {

            printf("-> Lua chon khong hop le! Nhap lai.\n");

        }
    } while (kiemTraTinhTrangDon(vcMoi.tinhTrangDon) == 0);

    ds[*soLuong] = vcMoi;
    (*soLuong)++;

    printf("\n[Thanh cong] Da them don hang %s vao he thong! (Tong so don: %d)\n", vcMoi.maDon, *soLuong);
}

void hienThiMenu() {
    printf("\n================ QUAN LY VAN CHUYEN BUU KIEN ==============\n");
    printf("| 1. Them moi don hang (Create)                            |\n");
    printf("| 0. Thoat chuong trinh                                    |\n");
    printf("============================================================\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {

    vanChuyen danhSachDonHang[MAX_DON_HANG];
    int soLuongDonHang = 0;
    int luaChon;

    do {
        
        hienThiMenu();

        if (scanf("%d", &luaChon) != 1) {

            printf("\nCu phap khong hop le!\n");

            xoaBoNhoDem();
            luaChon = -1;
            continue;
        }

        xoaBoNhoDem();

        switch (luaChon) {
            case 1:
                themDonHang(danhSachDonHang, &soLuongDonHang);
                break;
            case 0:
                printf("\nKet thuc chuong trinh\n");
                break;
            default:
                printf("\nCu phap khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}
