#include <stdio.h>
#include <string.h>
#include "header.h"

vanChuyen VC;
int hopLe, ngay, thang, nam, soNgay, soThang;
int kiemTraNguoiGui(char nguoiGui[]){
    if(strlen(nguoiGui) == 0){
        return 0;
    }
    return 1;
}
void nhapNguoiGui() {
    char nguoiGui[35];
    do {
        printf("Nhap nguoi gui: ");
        scanf("%s", nguoiGui);
        if (kiemTraNguoiGui(nguoiGui) == 1) {
            strcpy(VC.nguoiGui, nguoiGui);
        }
        else {
            printf("Ten khong hop le\n");
        }
    } while (kiemTraNguoiGui(nguoiGui) == 0);
}
int kiemTraMD(char maDon[]){
    if(strlen(maDon) != 7){
        return 0;
    }
    else{
        if(maDon[0] != '#' || maDon[1] != 'M' || maDon[2] != 'D'){
            return 0;
        }
        for (int i = 3; i < 7; i++){
            if(maDon[i] < '0' || maDon[i] > '9'){
                return 0;
            }
        }
    }
    return 1;
}
void nhapMaDon() {
    char maDon[8];
    do {
        hopLe = 1;
        printf("Nhap ma don: ");
        scanf("%s", maDon);
        hopLe = kiemTraMD(maDon);
        if (hopLe == 0) {
            printf("Ma don khong hop le! Nhap lai.\n");
        }
    } while (hopLe == 0);
    strcpy(VC.maDon, maDon);
    printf("Ma don hop le: %s\n", VC.maDon);
}
int kiemTraDonHang(char donHang[]){
    if(strlen(donHang) == 0){
        return 0;
    }
    return 1;
}
void nhapDonHang(){
    char donHang[50];
    do {
        printf("Nhap ten don hang: ");
        scanf("%s", donHang);
        if (kiemTraDonHang(donHang) == 1) {
            strcpy(VC.donHang, donHang);
        }
        else {
            printf("Ten khong hop le\n");
        }
    } while (kiemTraDonHang(donHang) == 0);
}
int kiemTraNgayGui(char ngayGui[]){
    if(strlen(ngayGui) != 6){
        return 0;
    }
    for(int i = 0; i < 6; i++){
        if(ngayGui[i] < '0' || ngayGui[i] > '9'){
            return 0;
        }
    }
    ngay = (ngayGui[0] - '0') * 10 + (ngayGui[1] - '0');
    thang = (ngayGui[2] - '0') * 10 + (ngayGui[3] - '0');
    nam = (ngayGui[4] - '0') * 10 + (ngayGui[5] - '0');
    if(thang < 1 || thang > 12){
        return 0;
    }
    switch (thang){
        case 4:
        case 6:
        case 9:
        case 11:
            soNgay = 30;
            break;
        case 2:
            if ((nam + 2000) % 400 == 0 || ((nam + 2000) % 4 == 0 && (nam + 2000) % 100 != 0)){
                soNgay = 29;
            }
            else {
                soNgay = 28;
            }
            break;
        default:
            soNgay = 31;
    }
    if(ngay < 1 || ngay > soNgay){
        return 0;
    }
    return 1;
}
void nhapNgayGui() {
    char ngayGui[7];
    do {
        printf("Nhap ngay gui (DDMMYY): ");
        scanf("%s", ngayGui);
        if (kiemTraNgayGui(ngayGui) == 0) {
            printf("Ngay gui khong hop le\n");
        }
    } while (kiemTraNgayGui(ngayGui) == 0);
    strcpy(VC.ngayGui, ngayGui);
}
void kiemTraKL(){
    printf("Nhap khoi luong(kg): ");
    scanf("%f", &VC.khoiLuong);
    printf("Khoi luong la: %.2f\n", VC.khoiLuong);
}
int kiemTraNguoiNhan(char nguoiNhan[]){
    if(strlen(nguoiNhan) == 0){
        return 0;
    }
    return 1;
}
void nhapNguoiNhan() {
    char nguoiNhan[35];
    do {
        printf("Nhap nguoi nhan: ");
        scanf("%s", nguoiNhan);
        if (kiemTraNguoiNhan(nguoiNhan) == 1) {
            strcpy(VC.nguoiNhan, nguoiNhan);
        }
        else {
            printf("Ten khong hop le\n");
        }
    } while (kiemTraNguoiNhan(nguoiNhan) == 0);
}
int kiemTraSDT(char SDT[]){
    if(strlen(SDT) != 10){
        return 0;
    }
    if(SDT[0] != '0'){
        return 0;
    }
    for(int j = 1; j < 10; j++){
        if(SDT[j] < '0' || SDT[j] > '9'){
            return 0;
        }
    }
    return 1;
}
void nhapSDT(){
    char SDT[11];
    do {
        printf("Nhap SDT: ");
        scanf("%s", SDT);
        hopLe = kiemTraSDT(SDT);
        if (hopLe == 0) {
            printf("SDT khong hop le\n");
        }
    } while (hopLe == 0);
    strcpy(VC.SDT, SDT);
}
int kiemTraNgayNhan(char ngayNhan[]){
    if(strlen(ngayNhan) != 6){
        return 0;
    }
    for(int i = 0; i < 6; i++){
        if(ngayNhan[i] < '0' || ngayNhan[i] > '9'){
            return 0;
        }
    }
    ngay = (ngayNhan[0] - '0') * 10 + (ngayNhan[1] - '0');
    thang = (ngayNhan[2] - '0') * 10 + (ngayNhan[3] - '0');
    nam = (ngayNhan[4] - '0') * 10 + (ngayNhan[5] - '0');
    if(thang < 1 || thang > 12){
        return 0;
    }
    switch (thang){
        case 4:
        case 6:
        case 9:
        case 11:
            soNgay = 30;
            break;
        case 2:
            if ((nam + 2000) % 400 == 0 || ((nam + 2000) % 4 == 0 && (nam + 2000) % 100 != 0)){
                soNgay = 29;
            }
            else {
                soNgay = 28;
            }
            break;
        default:
            soNgay = 31;
    }
    if(ngay < 1 || ngay > soNgay){
        return 0;
    }
    return 1;
}
void nhapNgayNhan(){
    char ngayNhan[7];
    do {
        printf("Nhap ngay nhan (DDMMYY): ");
        scanf("%s", ngayNhan);
        if (kiemTraNgayNhan(ngayNhan) == 0) {
            printf("Ngay nhan khong hop le\n");
        }
    } while (kiemTraNgayNhan(ngayNhan) == 0);
    strcpy(VC.ngayNhan, ngayNhan);
}
int kiemTraTinhTrangDon(int trangThai){
    if(trangThai < 1 || trangThai > 3){
        return 0;
    }
    return 1;
}
void nhapTinhTrangDon(){
    int trangThai;
    do{
        printf("====Menu====");
        printf("1. Chua giao\n");
        printf("2. Dang Giao\n");
        printf("3. Da Giao\n");
        printf("Nhap gia tri: ");
        scanf("%d", &trangThai);
    } while (kiemTraTinhTrangDon(trangThai) == 0);
    VC.tinhTrangDon = trangThai;        
}