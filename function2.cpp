#include <stdio.h>
#include <string.h>
#include "header.hpp"

void nhapDiaChi(char diaChi[], int kichThuoc) {
    if (diaChi == NULL || kichThuoc <= 1) {
        return;
    }

    do {
        printf("Nhap dia chi giao hang: ");
        if (fgets(diaChi, kichThuoc, stdin) == NULL) {
            diaChi[0] = '\0';
            return;
        }

        size_t doDai = strlen(diaChi);
        if (doDai > 0 && diaChi[doDai - 1] == '\n') {
            diaChi[doDai - 1] = '\0';
        } else {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (diaChi[0] == '\0') {
            printf("Vui long nhap lai.\n");
        }
    } while (diaChi[0] == '\0');
}

void hienThiDiaChi(const char diaChi[]) {
    if (diaChi == NULL || diaChi[0] == '\0') {
        printf("Chua co dia chi");
        return;
    }
    printf("%s", diaChi);
}