#pragma once

#define MAXLOPTINCHI 10000
#define MAXDSSV 5000

//#define MAXLOPTINCHI 4000
//#define MAXDSSV 2000

#define WIDTH_MAIN_FRAME 160
#define HEIGHT_MAIN_FRAME 41

//=================== POP UP ===================
#define WIDTH_POP_UP 75;
#define HEIGHT_POP_UP 25;
#define BACKGROUND_COLOR_POP_UP 7;
#define WIDTH_INPUT 50;
#define COLOR_BLACK 0
#define COLOR_DEFAULT 51
#define COLOR_BACKGROUND_DEFAULT 51
#define COLOR_RED 4
#define COLOR_LIGHT_RED 12
#define COLOR_GREEN_LIGHT 2
#define COLOR_YELLOW 6
#define COLOR_LIGHT_YELLOW 14
#define COLOR_WHITE 7
#define COLOR_BRIGHT_WHITE 15

#define TEXT_LEFT -1
#define TEXT_CENTER 0
#define TEXT_RIGHT 1


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define BACKSPACE 8
#define ESC 27
#define TAB 9
#define ENTER 13
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define DELETE_KEY 83
#define INSERT_KEY 82
#define YES 1
#define NO 0
#define CTRL_F 6

/*
* — Cau truc Danh Sach Sinh Vien —
*/

struct SinhVien {
	char MASV[15]; //Ma Sinh Vien
	char HO[30]; //Ho Va Ten Lot
	char TEN[10]; //Ten
	bool PHAI; //Gioi tinh
	char SODT[15]; // So Dien Thoai
	char MALOP[15]; //Ma lop
};

struct ListSinhVien {
	int number = 0;
	SinhVien* sinhvien[MAXDSSV];
};

struct Index {
	int index; //vi tri cua sinh vien trong danh sach sinh vien
	char HO[30]; //Ho Va Ten Lot
	char TEN[10]; //ten

};

struct IndexList { //DANH SACH TUYEN TINH CAP PHAT DONG
	int number = 0;
	Index* nodes;
};


/*
* — Cau truc Danh Sach Dang Ky —
*/

struct DangKy {
	char MASV[15];
	float DIEM;

};

struct NodeDK {
	DangKy dangky;
	NodeDK* next;
};

typedef NodeDK* LISTDANGKY;

struct IndexDangKy {
	int index; 
	char MASV[15]; //Ma sinh Vien
	char HO[30];
	char TEN[10];
	float DIEM;
};

struct IndexListDangKy { //
	int number = 0;
	IndexDangKy* nodes;
};

/*
* — Cau truc Danh Sach Lop Tin Chi —
*/

struct LopTinChi {
	int MALOPTC; // Ma lop Tin Chi
	char MAMH[10]; //Ma Mon Hoc
	char NIENKHOA[15]; //Nien Khoa
	int HOCKY; //Hoc Ky (1 hoac 2 hoac 3)
	int NHOM; //Nhom
	int MINSV; //So Sinh Vien Toi Thieu
	int MAXSV; //So Sinh Vien Toi Da
	bool HUYLOP; //(true= Giu lop; false= xoa lop)
	LISTDANGKY DSDK;
};

struct DSLOPTINCHI {
	int number = 0;
	LopTinChi* loptinchi[MAXLOPTINCHI];
};

struct IndexLopTinChi {
	int index; //vi tri cua mon hoc trong cay mon hoc
	char NIENKHOA[15];
};

struct IndexListLopTinChi { //
	int number = 0;
	IndexLopTinChi* nodes;
};

/*
* — Cau truc Danh Sach Mon Hoc —
*/
struct MonHoc {
	char MAMH[10]; //Ma Mon Hoc
	char TENMH[50]; //ten Mon Hoc
	unsigned int STCLT;   // So TC Ly Thuyet
	unsigned int STCTH;   // So Tc Thuc Hanh

};

struct NodeMH {
	MonHoc MH;
	int bf;
	NodeMH* left, * right;
};
typedef NodeMH* TREE;

struct IndexMonHoc {
	int index; //vi tri cua mon hoc trong cay mon hoc
	char MAMH[15]; //Ma lop
	char TENMH[50];
	int STCLT;
	int STCTH;
};

struct IndexListMonHoc { //
	int number = 0;
	IndexMonHoc* nodes;
};

/*
* — Cau truc Danh Sach Lop —
*/

struct Lop {
	char MALOP[15]; //Ma lop
};

struct ListLop {
	int number = 0;
	Lop* lop[200];
};

struct IndexLop {
	int index; //vi tri cua lop trong ds lop
	char MALOP[15]; //Ma lop
};

struct IndexListLop { //
	int number = 0;
	IndexLop* nodes;
};

