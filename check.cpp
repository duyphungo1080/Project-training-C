#include <stdio.h>
#include <string.h>
#include "header.h"

vanChuyen VC;
int hopLe, ngay, thang, nam, soNgay, soThang;
void kiemTraNguoiGui(){
    printf("Nhap nguoi gui: ");
    scanf("%s", &VC.nguoiGui);
    if(strlen(VC.nguoiGui) == 0){
        printf("Ten khong hop le");
    }
    else{
        printf("%s\n", VC.nguoiGui);
    }
}
void kiemTraMD(){
    do{
        hopLe = 1;
        printf("Nhap ma don: ");
        scanf("%s", &VC.maDon);
        if(strlen(VC.maDon) != 7){
            hopLe = 0;
        }
        else{
            if(VC.maDon[0] != '#' || VC.maDon[1] != 'M' || VC.maDon[2] != 'D'){
                hopLe = 0;
            }
            for (int i = 3; i < 7; i++){
                if(VC.maDon[i] < '0' || VC.maDon[i] > '9'){
                    hopLe = 0;
                    break;
                }
            }
        }
        if(hopLe == 0){
            printf("Ma khong hop le \n");
        }
    }while(hopLe == 0);
    printf("Ma don hop le: %s\n", VC.maDon);
}
void kiemTraDonHang(){
    printf("Nhap don hang: ");
    scanf("%s", &VC.donHang);
    if(strlen(VC.donHang) == 0){
        printf("Ten khong hop le\n");
    }
    else{
        printf("%s\n", VC.donHang);
    }
}
void kiemTraNgayGui(){
    do{
        hopLe = 1;
        printf("Nhap ngay gui: ");
        scanf("%s", &VC.ngayGui);
        if(strlen(VC.ngayGui) != 6){
            hopLe = 0;
        }
        for(int i = 0; i < 6; i++){
            if(VC.ngayGui[i] < '0' || VC.ngayGui[i] > '9'){
                hopLe = 0;
                break;
            }
        }
        if(hopLe == 1){
            ngay = (VC.ngayGui[0] - '0') * 10 + (VC.ngayGui[1] - '0');
            thang = (VC.ngayGui[2] - '0') * 10 + (VC.ngayGui[3] - '0');
            nam = (VC.ngayGui[4] - '0') * 10 + (VC.ngayGui[5] - '0');
            if(thang < 1 || thang > 12){
                hopLe = 0;
            }
            else{
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
                    hopLe = 0;
                }
            }
        }
        if(hopLe == 0){
            printf("Ngay gui khong hop le\n");
        }
    }while(hopLe == 0);
    printf("Ngay gui hop le: %s\n", VC.ngayGui);
}
void kiemTraKL(){
    printf("Nhap khoi luong(kg): ");
    scanf("%f", &VC.khoiLuong);
    printf("Khoi luong la: %.2f\n", VC.khoiLuong);
}
void kiemTraNguoiNhan(){
    printf("Nhap nguoi nhan: ");
    scanf("%s", &VC.nguoiNhan);
    if(strlen(VC.nguoiNhan) == 0){
        printf("Ten khong hop le\n");
    }
    else{
        printf("%s\n", VC.nguoiNhan);
    }
}
void kiemTraSDT(){
    do{
        hopLe = 1;
        printf("Nhap SDT: ");
        scanf("%s", &VC.SDT);
        if(strlen(VC.SDT) != 10){
            hopLe = 0;
            printf("So dien thoai khong hop le\n");
        }
        else{
            if(VC.SDT[0] != '0'){
                hopLe = 0;
            }
            for(int j = 1; j < 10; j++){
                if(VC.SDT[j] < '0' || VC.SDT[j] > '9'){
                    hopLe = 0;
                    break;
                }
            }
        }
        if(hopLe == 0){
            printf("So dien thoai khong hop le\n");
        }
    }while(hopLe == 0);
    printf("So dien thoai: %s\n", VC.SDT);
}
void kiemTraDiaChi(){
    printf("Nhap dia chi: ");
    scanf("%s", &VC.diaChi);
    if(strlen(VC.diaChi) == 0){
        printf("Dia chi khong hop le\n");
    }
    else{
        printf("%s\n", VC.diaChi);
    }
}
void kiemTraNgayNhan(){
    do{
        hopLe = 1;
        printf("Nhap du kien ngay nhan: ");
        scanf("%s", &VC.ngayNhan);
        if(strlen(VC.ngayNhan) != 6){
            hopLe = 0;
        }
        for(int i = 0; i < 6; i++){
            if(VC.ngayNhan[i] < '0' || VC.ngayNhan[i] > '9'){
                hopLe = 0;
                break;
            }
        }
        if(hopLe == 1){
            ngay = (VC.ngayNhan[0] - '0') * 10 + (VC.ngayNhan[1] - '0');
            thang = (VC.ngayNhan[2] - '0') * 10 + (VC.ngayNhan[3] - '0');
            nam = (VC.ngayNhan[4] - '0') * 10 + (VC.ngayNhan[5] - '0');
            if(thang < 1 || thang > 12){
                hopLe = 0;
            }
            else{
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
                    hopLe = 0;
                }
            }
        }
        if(hopLe == 0){
            printf("Ngay nhan khong hop le\n");
        }
    }while(hopLe == 0);
    printf("Ngay nhan hop le: %s\n", VC.ngayNhan);
}
void kiemTraSoTien(){
    printf("Nhap so tien: ");
    scanf("%f", &VC.sotien);
    printf("So tien phai tra: %.1f\n", VC.sotien);
}
void kiemTraTinhTrangDon(){
    do{
        printf("1. Chua giao\n");
        printf("2. Dang Giao\n");
        printf("3. Da Giao\n");
        printf("Nhap gia tri: ");
        scanf("%d", &VC.tinhTrangDon);
        switch(VC.tinhTrangDon){
            case 1:
                printf("Tinh trang hien tai: Chua giao");
                break;
            case 2:
                printf("Tinh trang hien tai: Dang giao");
                break;
            case 3:
                printf("Tinh trang hien tai: Da giao");
                break;
            default:
                break;
        }
    }while(VC.tinhTrangDon != 1 && VC.tinhTrangDon != 2 && VC.tinhTrangDon != 3);
}
int main(){
    kiemTraNguoiGui();
    kiemTraMD();
    kiemTraDonHang();
    kiemTraNgayGui();
    kiemTraKL();
    kiemTraNguoiNhan();
    kiemTraSDT();
    kiemTraDiaChi();
    kiemTraNgayNhan();
    kiemTraSoTien();
    kiemTraTinhTrangDon();
    return 0;
}