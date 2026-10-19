#include <stdio.h>
#include <string.h>
#include "header.hpp"

#define MAX_DON_HANG 100

// Hàm xóa sạch bộ nhớ đệm (tránh trôi lệnh)
void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm tìm vị trí đơn hàng theo mã
int timViTriTheoMa(vanChuyen ds[], int soLuong, char maDon[]) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maDon, maDon) == 0) {
            return i;
        }
    }
    return -1;
}

// Chức năng: Thêm mới đơn hàng (Create)
void themDonHang(vanChuyen ds[], int *soLuong) {
    if (*soLuong >= MAX_DON_HANG) {
        printf("\n[Loi] Danh sach da day! Khong the them don hang moi.\n");
        return;
    }

    vanChuyen vcMoi;
    printf("\n================ NHAP THONG TIN DON HANG MOI ================\n");

    // 1. Nhập Người gửi
    do {
        printf("Ten nguoi gui: ");
        fgets(vcMoi.nguoiGui, sizeof(vcMoi.nguoiGui), stdin);
        vcMoi.nguoiGui[strcspn(vcMoi.nguoiGui, "\n")] = 0;
        if (kiemTraNguoiGui(vcMoi.nguoiGui) == 0) {
            printf("-> Cu phap khong hop le\n");
        }
    } while (kiemTraNguoiGui(vcMoi.nguoiGui) == 0);

    // 2. Nhập Mã đơn
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

    // 3. Nhập Tên đơn hàng
    do {
        printf("Ten don hang: ");
        fgets(vcMoi.donHang, sizeof(vcMoi.donHang), stdin);
        vcMoi.donHang[strcspn(vcMoi.donHang, "\n")] = 0;
        if (kiemTraDonHang(vcMoi.donHang) == 0) {
            printf("-> Cu phap khong hop le\n");
        }
    } while (kiemTraDonHang(vcMoi.donHang) == 0);

    // 4. Chọn loại đơn trước (nếu là tài liệu thì không cần nhập khối lượng)
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
        vcMoi.khoiLuong = 0;   // Tài liệu không cần khối lượng
        vcMoi.soTien = 25000;  // Đồng giá 25k
        printf("-> Ap dung gia: Tai lieu (Dong gia 25,000 VND)\n");
    } else {
        // Nếu là hàng hóa bình thường thì bắt buộc nhập khối lượng và tính tiền
        do {
            printf("Nhap khoi luong (kg): ");
            scanf("%f", &vcMoi.khoiLuong);
            xoaBoNhoDem();
            if (vcMoi.khoiLuong <= 0) {
                printf("-> Khoi luong phai lon hon 0! Nhap lai.\n");
            }
        } while (vcMoi.khoiLuong <= 0);

        if (vcMoi.khoiLuong < 10) {
            vcMoi.soTien = vcMoi.khoiLuong * 3000;
        } else {
            vcMoi.soTien = vcMoi.khoiLuong * 4000;
        }
        printf("-> Ap dung gia: Hang hoa binh thuong (Tong tien: %.0f VND)\n", vcMoi.soTien);
    }

    // 5. Nhập Ngày gửi
    do {
        printf("Nhap ngay gui (DDMMYY): ");
        scanf("%s", vcMoi.ngayGui);
        xoaBoNhoDem();
        if (kiemTraNgayGui(vcMoi.ngayGui) == 0) {
            printf("-> Ngay gui khong hop le hoac sai dinh dang! Nhap lai.\n");
        }
    } while (kiemTraNgayGui(vcMoi.ngayGui) == 0);

    // 6. Nhập Người nhận
    do {
        printf("Nhap ten nguoi nhan: ");
        fgets(vcMoi.nguoiNhan, sizeof(vcMoi.nguoiNhan), stdin);
        vcMoi.nguoiNhan[strcspn(vcMoi.nguoiNhan, "\n")] = 0;
        if (kiemTraNguoiNhan(vcMoi.nguoiNhan) == 0) {
            printf("-> Ten nguoi nhan khong duoc de trong! Nhap lai.\n");
        }
    } while (kiemTraNguoiNhan(vcMoi.nguoiNhan) == 0);

    // 7. Nhập Số điện thoại
    do {
        printf("Nhap SDT nguoi nhan (10 so, bat dau bang 0): ");
        scanf("%s", vcMoi.SDT);
        xoaBoNhoDem();
        if (kiemTraSDT(vcMoi.SDT) == 0) {
            printf("-> SDT khong hop le! Nhap lai.\n");
        }
    } while (kiemTraSDT(vcMoi.SDT) == 0);

    // 8. Nhập Ngày nhận dự kiến
    do {
        printf("Nhap ngay nhan du kien (DDMMYY): ");
        scanf("%s", vcMoi.ngayNhan);
        xoaBoNhoDem();
        if (kiemTraNgayNhan(vcMoi.ngayNhan) == 0) {
            printf("-> Ngay nhan khong hop le! Nhap lai.\n");
        }
    } while (kiemTraNgayNhan(vcMoi.ngayNhan) == 0);

    // 9. Nhập Tình trạng đơn
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

// Hiển thị Menu tinh gọn
void hienThiMenu() {
    printf("\n================ QUAN LY VAN CHUYEN BUU KIEN ===============\n");
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
            printf("\n[Loi] Vui long nhap vao mot so nguyen hop le!\n");
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
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\n[Loi] Lua chon khong hop le! Vui long chon 1 hoac 0.\n");
        }
    } while (luaChon != 0);

    return 0;
}