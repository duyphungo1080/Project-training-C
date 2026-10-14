#include <stdio.h>
#include <string.h>

struct thu_chi
{
    int loai;
    char tenGD[100];
    float soTien;
    char ghiChu[200];
};
struct nganSach{
    float thuNhapThang;
    float tongThu;
    float tongChi;
    float nganSachThietYeu;
    float nganSachCaNhan;
    float nganSachTietKiem;
    float chiThietYeu;
    float chiCaNhan;
    float chiTietKiem;
};
void nganSach(struct nganSach *NS){
    NS->tongThu = NS->thuNhapThang;
    NS->tongChi = 0;
    NS->nganSachThietYeu = NS->thuNhapThang * 0.50;
    NS->nganSachCaNhan = NS->thuNhapThang * 0.30;
    NS->nganSachTietKiem = NS->thuNhapThang * 0.20;
    NS->chiThietYeu = 0;
    NS->chiCaNhan = 0;
    NS->chiTietKiem = 0;
};
void thuNhapThang(struct nganSach *NS){
    do{
        printf("Nhap thu nhap thang: ");
        scanf("%f", &NS->thuNhapThang);
        if (NS->thuNhapThang <= 0) {
            printf("SOS!!! Thông báo tìm người! Đặc điểm nhận dạng: Chất liệu Polymer màu xanh mệnh giá cao nhất.\n");
        }
    }
    while (NS->thuNhapThang <= 0);
    nganSach(NS);
    printf("\nNGAN SACH THANG\n");
    printf("Thu nhap ban dau: %.1f VND\n",
           NS->thuNhapThang);

    printf("Thiet yeu: %.1f\n",
           NS->nganSachThietYeu);

    printf("Nhu cau ca nhan: %.1f\n",
           NS->nganSachCaNhan);

    printf("Tiet kiem: %.1f\n",
           NS->nganSachTietKiem);        
}
void menu(struct nganSach *NS){
    int luaChon;
    do{
        printf("1. Thu tien\n");
        printf("2. Chi tien\n");
        printf("3. Xem ngan sach\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        if (scanf("%d", &luaChon) != 1) {
            printf("Error\n");
        }
         switch (luaChon) {
            case 1:
                printf("Ban da chon thu tien.\n");
                break;
            case 2:
                printf("Ban da chon chi tien.\n");
                break;
            case 3:
                printf("Ban da chon xem ngan sach");
                break;
            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    while (luaChon != 0);
}
int main(){
    struct nganSach NS = {0};
    menu(&NS);
    return 0;   
}
