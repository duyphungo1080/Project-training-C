#include <stdio.h>
#include <string.h>
#include "header.hpp"

void xoaDonHang(vanChuyen ds[], int *soLuong) {
    if (*soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    hienThiDanhSach(ds, *soLuong);

    char maCanXoa[8];
    printf("\nNhap ma don can xoa: ");
    scanf("%s", maCanXoa);
    xoaBoNhoDem();

    int vt = timViTriTheoMa(ds, *soLuong, maCanXoa);
    if (vt == -1) {
        printf("\nKhong tim thay don hang co ma %s!\n", maCanXoa);
        return;
    }

    int xacNhan;
    do {
        printf("\nBan co chac chan muon xoa don hang nay?\n");
        printf("1: Xac nhan xoa\n");
        printf("0: Tro lai\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &xacNhan) != 1) {
            printf("\nCu phap khong hop le!\n");
            xoaBoNhoDem();
            xacNhan = -1;
            continue;
        }
        xoaBoNhoDem();

        if (xacNhan == 1) {
            for (int i = vt; i < *soLuong - 1; i++) {
                ds[i] = ds[i + 1];
            }
            (*soLuong)--;
            printf("\n[Thanh cong] Da xoa don hang khoi he thong!\n");
            break;
        } else if (xacNhan == 0) {
            printf("\nHuy thao tac xoa.\n");
            break;
        } else {
            printf("\nLua chon khong hop le!\n");
        }
    } while (1);
}

void traCuuPhiVanChuyen(vanChuyen ds[], int soLuong) {
    if (soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    char maDon[8];
    printf("\nNhap ma don can tra cuu phi van chuyen: ");
    scanf("%s", maDon);
    xoaBoNhoDem();

    int vt = timViTriTheoMa(ds, soLuong, maDon);
    if (vt == -1) {
        printf("\nKhong tim thay don hang co ma %s!\n", maDon);
        return;
    }

    printf("\nPhi van chuyen cua don hang %s la: %.0f VND\n", ds[vt].maDon, ds[vt].soTien);
}

void xemTinhTrangDonHang(vanChuyen ds[], int soLuong) {
    if (soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    char maDon[8];
    printf("\nNhap ma don can xem tinh trang: ");
    scanf("%s", maDon);
    xoaBoNhoDem();

    int vt = timViTriTheoMa(ds, soLuong, maDon);
    if (vt == -1) {
        printf("\nKhong tim thay don hang co ma %s!\n", maDon);
        return;
    }

    char tt[20];
    if (ds[vt].tinhTrangDon == 1) {
        strcpy(tt, "Chua giao");
    } else if (ds[vt].tinhTrangDon == 2) {
        strcpy(tt, "Dang giao");
    } else {
        strcpy(tt, "Da giao");
    }

    printf("\nTinh trang cua don hang %s la: %s\n", ds[vt].maDon, tt);
}