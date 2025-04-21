#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cấu trúc biểu diễn một hạng tử trong đa thức
struct HangTu {
    int heSo;             // Hệ số
    int soMu;             // Số mũ
    struct HangTu* tiep;  // Con trỏ tới hạng tử tiếp theo
};

// Cấu trúc biểu diễn một đa thức
struct DaThuc {
    struct HangTu* dau;   // Con trỏ đến đầu danh sách
};

// Khởi tạo đa thức rỗng
void khoiTaoDaThuc(struct DaThuc* p) {
    p->dau = NULL;
}

// Thêm hạng tử vào cuối đa thức
void chenHangTu(struct DaThuc* p, int heSo, int soMu) {
    struct HangTu* moi = (struct HangTu*)malloc(sizeof(struct HangTu));
    moi->heSo = heSo;
    moi->soMu = soMu;
    moi->tiep = NULL;

    if (p->dau == NULL) {
        p->dau = moi;
        return;
    }

    struct HangTu* hienTai = p->dau;
    while (hienTai->tiep) {
        hienTai = hienTai->tiep;
    }
    hienTai->tiep = moi;
}

// In đa thức
void inDaThuc(struct DaThuc* p) {
    if (!p->dau) {
        printf("0\n");
        return;
    }

    struct HangTu* hienTai = p->dau;
    int laDauTien = 1;

    while (hienTai) {
        if (hienTai->heSo != 0) {
            if (!laDauTien && hienTai->heSo > 0)
                printf("+");

            if (hienTai->heSo != 1 && hienTai->heSo != -1)
                printf("%d", hienTai->heSo);
            else if (hienTai->heSo == -1)
                printf("-");

            if (hienTai->soMu > 0) {
                printf("x");
                if (hienTai->soMu > 1)
                    printf("^%d", hienTai->soMu);
            } else if (hienTai->soMu == 0 && abs(hienTai->heSo) == 1)
                printf("1");

            laDauTien = 0;
        }
        hienTai = hienTai->tiep;
    }

    printf("\n");
}

// Tính giá trị đa thức tại x
int tinhGiaTri(struct DaThuc* p, int x) {
    int ketQua = 0;
    struct HangTu* hienTai = p->dau;

    while (hienTai) {
        ketQua += hienTai->heSo * (int)pow(x, hienTai->soMu);
        hienTai = hienTai->tiep;
    }

    return ketQua;
}

// Rút gọn đa thức (gộp các hạng tử cùng số mũ)
void rutGon(struct DaThuc* p) {
    if (!p->dau) return;

    struct HangTu* hienTai = p->dau;
    while (hienTai) {
        struct HangTu* chay = hienTai->tiep;
        struct HangTu* truoc = hienTai;

        while (chay) {
            if (chay->soMu == hienTai->soMu) {
                hienTai->heSo += chay->heSo;
                truoc->tiep = chay->tiep;
                free(chay);
                chay = truoc->tiep;
            } else {
                truoc = chay;
                chay = chay->tiep;
            }
        }

        hienTai = hienTai->tiep;
    }

    // Xóa các hạng tử có hệ số bằng 0
    struct HangTu* truoc = NULL;
    hienTai = p->dau;

    while (hienTai) {
        if (hienTai->heSo == 0) {
            if (truoc) {
                truoc->tiep = hienTai->tiep;
                free(hienTai);
                hienTai = truoc->tiep;
            } else {
                p->dau = hienTai->tiep;
                free(hienTai);
                hienTai = p->dau;
            }
        } else {
            truoc = hienTai;
            hienTai = hienTai->tiep;
        }
    }
}

// Giải phóng bộ nhớ
void giaiPhong(struct DaThuc* p) {
    struct HangTu* hienTai = p->dau;
    while (hienTai) {
        struct HangTu* tam = hienTai;
        hienTai = hienTai->tiep;
        free(tam);
    }
    p->dau = NULL;
}

// Chương trình chính
int main() {
    struct DaThuc P;
    khoiTaoDaThuc(&P);

    int n;
    printf("Nhap so luong hang tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int heSo, soMu;
        printf("Nhap he so va so mu cua hang tu %d: ", i + 1);
        scanf("%d %d", &heSo, &soMu);
        chenHangTu(&P, heSo, soMu);
    }

    printf("Da thuc vua nhap: ");
    inDaThuc(&P);

    rutGon(&P);
    printf("Da thuc sau khi rut gon: ");
    inDaThuc(&P);

    int x;
    printf("Nhap gia tri x de tinh P(x): ");
    scanf("%d", &x);
    printf("P(%d) = %d\n", x, tinhGiaTri(&P, x));

    giaiPhong(&P);
    return 0;
}
