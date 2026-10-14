#include <stdio.h>
#include <string.h>

struct thu_chi{
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
void menu(struct nganSach *NS){
    int luaChon;
    struct thu_chi GD;
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
                printf("Nhap thu nhap thang: ");
                scanf("%f", &NS->thuNhapThang);
                printf("Thu nhap ngoai them: ");
                scanf("%f",&NS->tongThu);
                printf("Ten Giao Dich: ");
                scanf("%c[^\n]", GD.tenGD);                
                break;
            case 2:
                printf("Ban da chon chi tien.\n");
                printf("Da chi so tien la: ");
                scanf("%f", &NS->tongChi);
                printf("ten giao Dich");
                scanf("%c[^\n]", GD.ghiChu);
                break;
            case 3:
                printf("Ban da chon xem ngan sach");
                printf("\n===== NGAN SACH THANG =====\n");
                printf("Thu nhap ban dau: %.0f VND\n",
                    NS->thuNhapThang);
                printf("Tong thu: %.1f VND\n", NS->tongThu);
                printf("Tong chi: %.1f VND\n", NS->tongChi);
                printf("Thiet yeu: %.1f VND\n",
                    NS->nganSachThietYeu);
                printf("Nhu cau ca nhan: %.1f VND\n",
                    NS->nganSachCaNhan);
                printf("Tiet kiem: %.1f VND\n",
                    NS->nganSachTietKiem);
                break;
            case 0:
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