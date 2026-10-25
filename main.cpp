#include <stdio.h>
#include "header.hpp"

#define MAX_DON_HANG 100

void hienThiMenu() {
    printf("\n");
    printf("================ QUAN LY VAN CHUYEN BUU KIEN ==============\n");
    printf("| 1. Them moi don hang (Create)                           |\n");
    printf("| 2. Hien thi danh sach don hang (Read)                   |\n");
    printf("| 3. Tim kiem don hang (Search)                           |\n");
    printf("| 4. Chinh sua don hang (Edit)                            |\n");
    printf("| 0. Thoat chuong trinh                                   |\n");
    printf("===========================================================\n");
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
            case 2:
                hienThiDanhSach(danhSachDonHang, soLuongDonHang);
                break;
            case 3:
                timKiemDonHang(danhSachDonHang, soLuongDonHang);
                break;
            case 4:
                suaDonHang(danhSachDonHang, soLuongDonHang);
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