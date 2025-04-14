#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// S?a c?u trúc sinhvien
typedef struct sinhvien 
{
    float Diemtb;   
    char hoten[40];   
    char maso[10];    // S?a t? char thành char[10] d? luu chu?i mã s?
} sinhvien;	

typedef struct Node 
{
    sinhvien Info;   
    struct Node* pNext;   
} Node;	

typedef struct List 
{
    Node* pHead;
    Node* pTail;   
} List;	

// Kh?i t?o danh sách r?ng
void InitList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// T?o node m?i
Node* GetNode(sinhvien x) 
{	
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL)   
    { 
        printf("Khong du bo nho\n"); 
        return NULL; 
    }
    p->Info = x;
    p->pNext = NULL;
    return p; 
}

// Thêm node vào d?u danh sách
void AddFirst(List &l, Node* new_ele)
{
    if (l.pHead == NULL)  
    {
        l.pHead = new_ele;
        l.pTail = l.pHead;
    }
    else 
    {	
        new_ele->pNext = l.pHead;  
        l.pHead = new_ele; 	
    }
}

// Nh?p thông tin sinh viên
void InputSinhVien(sinhvien &x)
{
    printf("Nhap ma so: ");
    scanf("%s", x.maso);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", x.hoten);  // Ð?c c? dòng k? c? kho?ng tr?ng
    printf("Nhap diem trung binh: ");
    scanf("%f", &x.Diemtb);
}

// Nh?p danh sách sinh viên
void InputHead(List &l)
{
    int n;
    sinhvien x;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        printf("\nNhap thong tin sinh vien thu %d:\n", i);
        InputSinhVien(x);
        Node* p = GetNode(x);
        if (p != NULL)
            AddFirst(l, p);
    }
}

// In thông tin m?t sinh viên
void ProcessNode(Node* p)
{
    printf("Ma so: %s, Ho ten: %s, Diem TB: %.2f\n", 
           p->Info.maso, p->Info.hoten, p->Info.Diemtb);
}

// Xu?t danh sách
void Output(List l)
{
    Node* p = l.pHead;
    if (p == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    printf("\nDanh sach sinh vien:\n");
    while(p != NULL)
    {
        ProcessNode(p);
        p = p->pNext;
    }
}

// Gi?i phóng b? nh?
void FreeList(List &l)
{
    Node* p = l.pHead;
    while(p != NULL)
    {
        l.pHead = p->pNext;
        free(p);
        p = l.pHead;
    }
    l.pTail = NULL;
}

int main()
{
    List l;
    InitList(l);
    
    // Nh?p danh sách
    InputHead(l);
    
    // Xu?t danh sách
    Output(l);
    
    // Gi?i phóng b? nh?
    FreeList(l);
    
    return 0;
}
