#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <conio.h>

#define MAXLOPTINCHI 10000

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

struct NodeSV
{
	SinhVien SV;
	NodeSV* next;
};

typedef NodeSV* LISTSV;

/*
* — Cau truc Danh Sach Dang Ky —
*/

struct DANGKY {
	char MASV[15];
	float DIEM;

};
struct NodeDK {
	DANGKY SV;
	NodeDK* next;
};

typedef NodeDK* LISTDK;

/*
* — Cau truc Danh Sach Lop Tin Chi —
*/

struct LopTinChi {
	unsigned int MALOPTC; // Ma lop Tin Chi
	char MAMH[10]; //Ma Mon Hoc
	char NIENKHOA[15]; //Nien Khoa
	int HOCKY; //Hoc Ky (1 hoac 2 hoac 3)
	int NHOM; //Nhom
	int MINSV; //So Sinh Vien Toi Thieu
	int MAXSV; //So Sinh Vien Toi Da
	bool HUYLOP; //(true= Giu lop; false= xoa lop)
	LISTDK DSDK;
	LopTinChi() { static int id = 1; MALOPTC = id++; }
};

struct DSLOPTINCHI {
	unsigned int N;
	LopTinChi* LOP[MAXLOPTINCHI];
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



/*
* — Cau truc Danh Sach Lop —
*/

struct NodeLop {
	char MALOP[15];
	NodeLop* next;
};
typedef NodeLop* DSLOPPTR;
