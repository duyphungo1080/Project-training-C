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
int main(){
    struct nganSach NS = {0};
    thuNhapThang(&NS);
    return 0;   
}
