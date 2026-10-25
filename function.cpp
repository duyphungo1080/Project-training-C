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

    vcMoi.loai = loaiHang;

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
        printf("-> Phi van chuyen: %.0f VND\n", vcMoi.soTien);
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

void hienThiDanhSach(vanChuyen ds[], int soLuong) {
    if (soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    printf("\n================================================================== DANH SACH DON HANG ==================================================================\n");
    printf("%-4s | %-8s | %-18s | %-18s | %-12s | %-10s | %-10s | %-10s | %-12s | %-12s\n", 
           "STT", "Ma don", "Nguoi gui", "Ten hang", "Loai", "Khoi luong", "Ngay gui", "SDT nhan", "So tien", "Tinh trang");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soLuong; i++) {
        char tt[20];
        if (ds[i].tinhTrangDon == 1) {
            strcpy(tt, "Chua giao");
        } else if (ds[i].tinhTrangDon == 2) {
            strcpy(tt, "Dang giao");
        } else {
            strcpy(tt, "Da giao");
        }

        char tenLoai[20];
        if (ds[i].loai == 1) {
            strcpy(tenLoai, "Tai lieu");
        } else {
            strcpy(tenLoai, "Hang hoa");
        }

        if (ds[i].loai == 1) {
            printf("%-4d | %-8s | %-18s | %-18s | %-12s | %-10s | %-10s | %-10s | %-12.0f | %-12s\n",
                   i + 1, 
                   ds[i].maDon, 
                   ds[i].nguoiGui, 
                   ds[i].donHang, 
                   tenLoai,
                   "X", 
                   ds[i].ngayGui, 
                   ds[i].SDT, 
                   ds[i].soTien, 
                   tt);
        } else {
            printf("%-4d | %-8s | %-18s | %-18s | %-12s | %-10.2f | %-10s | %-10s | %-12.0f | %-12s\n",
                   i + 1, 
                   ds[i].maDon, 
                   ds[i].nguoiGui, 
                   ds[i].donHang, 
                   tenLoai,
                   ds[i].khoiLuong, 
                   ds[i].ngayGui, 
                   ds[i].SDT, 
                   ds[i].soTien, 
                   tt);
        }
    }
    printf("========================================================================================================================================================\n");
}

void timKiemDonHang(vanChuyen ds[], int soLuong) {
    if (soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    char tuKhoa[35];
    printf("\nNhap ma don hoac SDT can tim: ");
    scanf("%s", tuKhoa);
    xoaBoNhoDem();

    int dem = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maDon, tuKhoa) == 0 || strcmp(ds[i].SDT, tuKhoa) == 0) {
            dem++;
        }
    }

    if (dem == 0) {
        printf("\nKhong tim thay don hang nao phu hop!\n");
        return;
    }

    printf("\n================================================================== KET QUA TIM KIEM ==================================================================\n");
    printf("%-4s | %-8s | %-18s | %-18s | %-12s | %-10s | %-10s | %-10s | %-12s | %-12s\n", 
           "STT", "Ma don", "Nguoi gui", "Ten hang", "Loai", "Khoi luong", "Ngay gui", "SDT nhan", "So tien", "Tinh trang");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maDon, tuKhoa) == 0 || strcmp(ds[i].SDT, tuKhoa) == 0) {
            char tt[20];
            if (ds[i].tinhTrangDon == 1) {
                strcpy(tt, "Chua giao");
            } else if (ds[i].tinhTrangDon == 2) {
                strcpy(tt, "Dang giao");
            } else {
                strcpy(tt, "Da giao");
            }

            char tenLoai[20];
            if (ds[i].loai == 1) {
                strcpy(tenLoai, "Tai lieu");
            } else {
                strcpy(tenLoai, "Hang hoa");
            }

            if (ds[i].loai == 1) {
                printf("%-4d | %-8s | %-18s | %-18s | %-12s | %-10s | %-10s | %-10s | %-12.0f | %-12s\n",
                       i + 1, 
                       ds[i].maDon, 
                       ds[i].nguoiGui, 
                       ds[i].donHang, 
                       tenLoai,
                       "X", 
                       ds[i].ngayGui, 
                       ds[i].SDT, 
                       ds[i].soTien, 
                       tt);
            } else {
                printf("%-4d | %-8s | %-18s | %-18s | %-12s | %-10.2f | %-10s | %-10s | %-12.0f | %-12s\n",
                       i + 1, 
                       ds[i].maDon, 
                       ds[i].nguoiGui, 
                       ds[i].donHang, 
                       tenLoai,
                       ds[i].khoiLuong, 
                       ds[i].ngayGui, 
                       ds[i].SDT, 
                       ds[i].soTien, 
                       tt);
            }
        }
    }
    printf("========================================================================================================================================================\n");
}

void suaHoacXoaDonHang(vanChuyen ds[], int *soLuong) {
    if (*soLuong == 0) {
        printf("\nDanh sach don hang hien dang trong!\n");
        return;
    }

    hienThiDanhSach(ds, *soLuong);

    char maCanTim[8];
    printf("\nNhap ma don can chinh sua hoac xoa: ");
    scanf("%s", maCanTim);
    xoaBoNhoDem();

    int vt = timViTriTheoMa(ds, *soLuong, maCanTim);
    if (vt == -1) {
        printf("\nKhong tim thay don hang co ma %s!\n", maCanTim);
        return;
    }

    int luaChonHD;
    do {
        printf("\n================ CHINH SUA HOAC XOA DON HANG ================\n");
        printf("1. Chinh sua don hang\n");
        printf("2. Xoa don hang\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");
        if (scanf("%d", &luaChonHD) != 1) {
            printf("\nCu phap khong hop le!\n");
            xoaBoNhoDem();
            continue;
        }
        xoaBoNhoDem();

        if (luaChonHD == 1) {
            printf("\n================ NHAP LAI THONG TIN DON HANG ================\n");
            
            do {
                printf("Ten nguoi gui: ");
                fgets(ds[vt].nguoiGui, sizeof(ds[vt].nguoiGui), stdin);
                ds[vt].nguoiGui[strcspn(ds[vt].nguoiGui, "\n")] = 0;
                if (kiemTraNguoiGui(ds[vt].nguoiGui) == 0) {
                    printf("-> Cu phap khong hop le\n");
                }
            } while (kiemTraNguoiGui(ds[vt].nguoiGui) == 0);

            do {
                printf("Ten don hang: ");
                fgets(ds[vt].donHang, sizeof(ds[vt].donHang), stdin);
                ds[vt].donHang[strcspn(ds[vt].donHang, "\n")] = 0;
                if (kiemTraDonHang(ds[vt].donHang) == 0) {
                    printf("-> Cu phap khong hop le\n");
                }
            } while (kiemTraDonHang(ds[vt].donHang) == 0);

            int loaiHang;
            do {
                printf("Chon loai hang hoa (1: Tai lieu | 2: Hang hoa binh thuong): ");
                scanf("%d", &loaiHang);
                xoaBoNhoDem();
                if (loaiHang != 1 && loaiHang != 2) {
                    printf("-> Lua chon khong hop le! Vui long chon 1 hoac 2.\n");
                }
            } while (loaiHang != 1 && loaiHang != 2);

            ds[vt].loai = loaiHang;

            if (loaiHang == 1) {
                ds[vt].khoiLuong = 0;
                ds[vt].soTien = 25000;
                printf("-> Phi van chuyen: 25000 VND\n");
            } else {
                do {
                    printf("Nhap khoi luong (kg): ");
                    scanf("%f", &ds[vt].khoiLuong);
                    xoaBoNhoDem();
                    if (ds[vt].khoiLuong <= 0) {
                        printf("Gia tri khong hop le!\n");
                    }
                } while (ds[vt].khoiLuong <= 0);

                if (ds[vt].khoiLuong < 10) {
                    ds[vt].soTien = ds[vt].khoiLuong * 3000;
                } else {
                    ds[vt].soTien = ds[vt].khoiLuong * 4000;
                }
                printf("-> Phi van chuyen: %.0f VND\n", ds[vt].soTien);
            }

            do {
                printf("Nhap ngay gui (DDMMYY): ");
                scanf("%s", ds[vt].ngayGui);
                xoaBoNhoDem();
                if (kiemTraNgayGui(ds[vt].ngayGui) == 0) {
                    printf("-> Ngay gui khong hop le\n");
                }
            } while (kiemTraNgayGui(ds[vt].ngayGui) == 0);

            do {
                printf("Nhap ten nguoi nhan: ");
                fgets(ds[vt].nguoiNhan, sizeof(ds[vt].nguoiNhan), stdin);
                ds[vt].nguoiNhan[strcspn(ds[vt].nguoiNhan, "\n")] = 0;
                if (kiemTraNguoiNhan(ds[vt].nguoiNhan) == 0) {
                    printf("-> Ten nguoi nhan khong duoc de trong! Nhap lai.\n");
                }
            } while (kiemTraNguoiNhan(ds[vt].nguoiNhan) == 0);

            do {
                printf("Nhap SDT nguoi nhan: ");
                scanf("%s", ds[vt].SDT);
                xoaBoNhoDem();
                if (kiemTraSDT(ds[vt].SDT) == 0) {
                    printf("-> SDT khong hop le! Nhap lai.\n");
                }
            } while (kiemTraSDT(ds[vt].SDT) == 0);

            do {
                printf("Nhap ngay nhan du kien (DDMMYY): ");
                scanf("%s", ds[vt].ngayNhan);
                xoaBoNhoDem();
                if (kiemTraNgayNhan(ds[vt].ngayNhan) == 0) {
                    printf("-> Ngay nhan khong hop le! Nhap lai.\n");
                }
            } while (kiemTraNgayNhan(ds[vt].ngayNhan) == 0);

            do {
                printf("Nhap tinh trang don (1: Chua giao | 2: Dang giao | 3: Da giao): ");
                scanf("%d", &ds[vt].tinhTrangDon);
                xoaBoNhoDem();
                if (kiemTraTinhTrangDon(ds[vt].tinhTrangDon) == 0) {
                    printf("-> Lua chon khong hop le! Nhap lai.\n");
                }
            } while (kiemTraTinhTrangDon(ds[vt].tinhTrangDon) == 0);

            printf("\n[Thanh cong] Da cap nhat thong tin don hang %s!\n", ds[vt].maDon);
            break;
        } else if (luaChonHD == 2) {
            int xacNhan;
            do {
                printf("\nBan co chac chan muon xoa don hang nay?\n");
                printf("1: Xac nhan xoa\n");
                printf("0: Tro lai menu chinh sua hoac xoa\n");
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
                    break;
                } else {
                    printf("\nLua chon khong hop le!\n");
                }
            } while (xacNhan != 0 && xacNhan != 1);

            if (xacNhan == 1) {
                break;
            }
        } else if (luaChonHD == 0) {
            break;
        } else {
            printf("\nLua chon khong hop le!\n");
        }
    } while (1);
}