#include <stdio.h>
#include <string.h>
#include "header.hpp"

int hopLe, ngay, thang, nam, soNgay;

int kiemTraNguoiGui(char nguoiGui[]) {
    if (strlen(nguoiGui) == 0) return 0;
    return 1;
}

int kiemTraDonHang(char donHang[]) {
    if (strlen(donHang) == 0) return 0;
    return 1;
}

int kiemTraNguoiNhan(char nguoiNhan[]) {
    if (strlen(nguoiNhan) == 0) return 0;
    return 1;
}

int kiemTraMD(char maDon[]) {
    if (strlen(maDon) != 7) {
        return 0;
    }
    if (maDon[0] != '#' || maDon[1] != 'M' || maDon[2] != 'D') {
        return 0;
    }
    for (int i = 3; i < 7; i++) {
        if (maDon[i] < '0' || maDon[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int kiemTraNgayGui(char ngayGui[]) {
    if (strlen(ngayGui) != 6) return 0;
    for (int i = 0; i < 6; i++) {
        if (ngayGui[i] < '0' || ngayGui[i] > '9') return 0;
    }
    ngay = (ngayGui[0] - '0') * 10 + (ngayGui[1] - '0');
    thang = (ngayGui[2] - '0') * 10 + (ngayGui[3] - '0');
    nam = (ngayGui[4] - '0') * 10 + (ngayGui[5] - '0');

    if (thang < 1 || thang > 12) return 0;

    switch (thang) {
        case 4: case 6: case 9: case 11:
            soNgay = 30;
            break;
        case 2:
            if ((nam + 2000) % 400 == 0 || ((nam + 2000) % 4 == 0 && (nam + 2000) % 100 != 0)) {
                soNgay = 29;
            } else {
                soNgay = 28;
            }
            break;
        default:
            soNgay = 31;
    }
    if (ngay < 1 || ngay > soNgay) return 0;
    return 1;
}

int kiemTraNgayNhan(char ngayNhan[]) {
    if (strlen(ngayNhan) != 6) return 0;
    for (int i = 0; i < 6; i++) {
        if (ngayNhan[i] < '0' || ngayNhan[i] > '9') return 0;
    }
    ngay = (ngayNhan[0] - '0') * 10 + (ngayNhan[1] - '0');
    thang = (ngayNhan[2] - '0') * 10 + (ngayNhan[3] - '0');
    nam = (ngayNhan[4] - '0') * 10 + (ngayNhan[5] - '0');

    if (thang < 1 || thang > 12) return 0;

    switch (thang) {
        case 4: case 6: case 9: case 11:
            soNgay = 30;
            break;
        case 2:
            if ((nam + 2000) % 400 == 0 || ((nam + 2000) % 4 == 0 && (nam + 2000) % 100 != 0)) {
                soNgay = 29;
            } else {
                soNgay = 28;
            }
            break;
        default:
            soNgay = 31;
    }
    if (ngay < 1 || ngay > soNgay) return 0;
    return 1;
}

int kiemTraSDT(char SDT[]) {
    if (strlen(SDT) != 10) return 0;
    if (SDT[0] != '0') return 0;
    for (int j = 1; j < 10; j++) {
        if (SDT[j] < '0' || SDT[j] > '9') return 0;
    }
    return 1;
}

int kiemTraTinhTrangDon(int trangThai) {
    if (trangThai < 1 || trangThai > 3) return 0;
    return 1;
}
