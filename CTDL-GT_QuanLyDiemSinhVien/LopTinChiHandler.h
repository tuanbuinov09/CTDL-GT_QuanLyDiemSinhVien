#pragma once
using namespace std;
#include "string"
#include "DangKyHandler.h"
#include "MonHocHandler.h"
#include <iostream>

//THEM LOP TIN CHI
void insertLopTinChiOrderByMaLTC(DSLOPTINCHI& listLopTinChi, LopTinChi& lopTinChi) {
	int i, j;
	//TIM KIEM VI TRI SE THEM VAO
	for (i = 0; i < listLopTinChi.number && listLopTinChi.loptinchi[i]->MALOPTC < lopTinChi.MALOPTC; i++);

	//TINH TIEN TU VI TRI THU I DO
	for (j = listLopTinChi.number - 1; j >= i; j--) {
		listLopTinChi.loptinchi[j + 1] = listLopTinChi.loptinchi[j];
	}

	//TAO LOP TIN CHI MOI VA THEM VAO VI TRI DO
	listLopTinChi.loptinchi[i] = new LopTinChi();
	*listLopTinChi.loptinchi[i] = lopTinChi;
	listLopTinChi.number++;
}

void duyetLopTinChi(DSLOPTINCHI listLopTinChi) {
	for (int i = 0; i < listLopTinChi.number; i++) {
		cout << listLopTinChi.loptinchi[i]->MALOPTC << " ";
		cout << "\n";
		duyetListDangKy(listLopTinChi.loptinchi[i]->DSDK);
	}
}


void listLopTinChiToIndexListLopTinChi(DSLOPTINCHI listLopTinChi, IndexListLopTinChi& indexListLopTinChi)
{
	indexListLopTinChi.number = listLopTinChi.number;
	indexListLopTinChi.nodes = new IndexLopTinChi[listLopTinChi.number];

	for (int i = 0; i < listLopTinChi.number; i++) {
		indexListLopTinChi.nodes[i].index = i;
		strcpy_s(indexListLopTinChi.nodes[i].NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
	}
}
//SAP XEP THEO NIEN KHOA GIAM DAN
void sapXepListLopTinChiNienKhoaDESC(IndexListLopTinChi& sortedListLopTinChi)
{
	int i, j;
	for (i = 0; i < sortedListLopTinChi.number - 1; i++) {
		for (j = 0; j < sortedListLopTinChi.number - i - 1; j++) {
			if (_stricmp(sortedListLopTinChi.nodes[j].NIENKHOA, sortedListLopTinChi.nodes[j + 1].NIENKHOA) < 0) {
				swap(sortedListLopTinChi.nodes[j], sortedListLopTinChi.nodes[j + 1]);
			}

		}
	}
}

bool isSortedListLopTinChiEmpty(IndexListLopTinChi indexListLopTinChi) {
	return indexListLopTinChi.number == 0 ? true : false;
}

bool isListLopTinChiFull(DSLOPTINCHI listLopTinChi) {
	return listLopTinChi.number == MAXLOPTINCHI ? true : false;
}

void clearIndexListLopTinChi(IndexListLopTinChi& listLopTinChi) {
	listLopTinChi.number = 0;
	delete[] listLopTinChi.nodes;
}

int timIndexLopTinChiTheoMALTC(DSLOPTINCHI listLopTinChi, int MALOPTC) {
	int index = -1;
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (listLopTinChi.loptinchi[i]->MALOPTC == MALOPTC) {
			index = i;
			return index;
		}
	}
}

//KIEM TRA HOCKY, MINSV, MAXSV
string checkHK_MIN_MAXSV(string number, string message) {

	//LTTH truyền vào "NHOM", "HOCKY" HOAC "MAXSV", "MINSV"
	if (number.empty()) return message + " khong duoc de trong";
	for (int i = 0; i < number.length(); i++) {
		if (number[i] == 32 && isalpha(number[i + 1])) {
			return message + " khong chua khoang trang giua cac so";
		}
		else if (!isdigit(number[i])) {
			return message + " khong duoc chua ki tu chu";
		}
	}

	return "";
}

//KIEM TRA MA MON HOC CO NHAP DUNG VA TON TAI K
string checkMaMonHocLopTinChi(TREE& treeMonHoc, string MAMH_STR) {
	if (MAMH_STR.empty()) return "MA MON HOC khong duoc de trong";
	if (MAMH_STR.length() > 10) return "MA MON HOC khong duoc qua 10 ki tu";

	NodeMH* s = NULL;
	s = timMonHocTheoMaMonHoc(treeMonHoc, MAMH_STR);
	if (s == NULL) return "MA MON HOC khong ton tai";
	else return "";
}
// KIEM TRA TO HOP KHOA (MAMH, NIENKHOA, HOCKY, NHOM)
string checkToHopKeyLopTinChi(DSLOPTINCHI listLopTinChi, string MAMH_STR, string NIENKHOA_STR, string HOCKY_STR, string NHOM_STR) {
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (
			(strcmp(listLopTinChi.loptinchi[i]->MAMH, MAMH_STR.c_str()) == 0)
			&& (strcmp(listLopTinChi.loptinchi[i]->NIENKHOA, NIENKHOA_STR.c_str()) == 0)
			&& (listLopTinChi.loptinchi[i]->HOCKY == stoi(HOCKY_STR))
			&& (listLopTinChi.loptinchi[i]->NHOM == stoi(NHOM_STR))
			) {
			return "MAMH-NIENKHOA-HOCKY-NHOM da ton tai";
		}
	}
	return "";
}

//KIEM TRA NIEN KHOA
string checkNIENKHOA(string NIENKHOA_STR) {
	if (NIENKHOA_STR.empty()) return "NIENKHOA khong duoc de trong";
	if (NIENKHOA_STR.length() > 15) return "NIENKHOA khong qua 15 ki tu";
	for (int i = 0; i < NIENKHOA_STR.length(); i++) {
		if (NIENKHOA_STR[i] == 32 && isalpha(NIENKHOA_STR[i + 1])) {
			return "NIEN KHOA khong chua khoang trang giua cac so";
		}
		else if (!isdigit(NIENKHOA_STR[i])) {
			return "NIEN KHOA khong duoc chua ki tu chu";
		}
	}
	return "";
}

int timSoLuongSinhVienDaDangKyLTC(LopTinChi* lopTinChi) {
	int dem = 0;
	for (NodeDK* k = lopTinChi->DSDK; k != NULL; k = k->next) {
		dem++;
	}
	return dem;
}

string checkHUYLOPTC(DSLOPTINCHI listLopTinChi, int maLopTinChi, string oldHUYLOP_STR, string HUYLOP_STR) {
	//KIEM TRA HUY LOP
	string moLop = "MO";
	string huyLop = "HUY";
	if (oldHUYLOP_STR.compare(HUYLOP_STR) == 0) {
		return "";
	}
	if (HUYLOP_STR.empty()) return "HUYLOP khong duoc de trong";
	if (HUYLOP_STR.compare(moLop) != 0 && HUYLOP_STR.compare(huyLop) != 0) {
		return "HUYLOP la MO hoac HUY";
	}
	else {
		int i = timIndexLopTinChiTheoMALTC(listLopTinChi, maLopTinChi);
		LopTinChi* ltc = listLopTinChi.loptinchi[i];
		if (timSoLuongSinhVienDaDangKyLTC(ltc) != 0) {
			return "Khong the thay doi tt HUYLOP (LTC da co dang ky)";
		}
	}
	return "";
}

int suaLopTinChi(DSLOPTINCHI& listLopTinChi, LopTinChi lopTinChi) {
	int i = timIndexLopTinChiTheoMALTC(listLopTinChi, lopTinChi.MALOPTC);
	LopTinChi* ltcCanSua = listLopTinChi.loptinchi[i];
	if (ltcCanSua == NULL) {
		return 0;
	}
	else {
		ltcCanSua->MINSV = lopTinChi.MINSV;
		ltcCanSua->MAXSV = lopTinChi.MAXSV;
		ltcCanSua->HUYLOP = lopTinChi.HUYLOP;
		return 1;
	}
}
string kiemTraXoaLopTinChi(DSLOPTINCHI& listLopTinChi, int MALTC) {
	int i = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC);
	LopTinChi* ltcCanXoa = listLopTinChi.loptinchi[i];
	if (ltcCanXoa == NULL) {
		return "Khong tim thay LTC";
	}
	else {
		if (timSoLuongSinhVienDaDangKyLTC(ltcCanXoa) > 0)
			return "Lop da co dang ky, khong the xoa";
		return "";
	}
}

string kiemTraSuaMAXSV(DSLOPTINCHI& listLopTinChi, int MALTC, string MAXSV_STR) {
	int i = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC);
	LopTinChi* ltcCanSua = listLopTinChi.loptinchi[i];
	if (timSoLuongSinhVienDaDangKyLTC(ltcCanSua) > stoi(MAXSV_STR))
		return "So SV da dang ky > MAXSV";
	return "";
}

int xoaLopTinChiTheoMaLTC(DSLOPTINCHI& listLopTinChi, int MALTC)
{
	if (listLopTinChi.number == 0)
		return 0;
	int i = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC);
	delete listLopTinChi.loptinchi[i];

	for (int k = i; k < listLopTinChi.number - 1; k++) {
		listLopTinChi.loptinchi[k] = listLopTinChi.loptinchi[k + 1];
	}
	listLopTinChi.number = listLopTinChi.number--;
	return 1;
}

//TIM KIEM DANH SACH LTC THEO NIEN KHOA
void seachListLopTinChiTheoNienKhoa(DSLOPTINCHI listLopTinChi, IndexListLopTinChi& sortedListLopTinChi, string NIENKHOA_STR) {
	sortedListLopTinChi.number = 0;
	sortedListLopTinChi.nodes = new IndexLopTinChi[listLopTinChi.number];

	for (int i = 0; i < listLopTinChi.number; i++) {
		char* output = NULL;
		output = strstr(listLopTinChi.loptinchi[i]->NIENKHOA, NIENKHOA_STR.c_str());
		if (output) {
			IndexLopTinChi indexLopTinChi;
			indexLopTinChi.index = i;
			strcpy_s(indexLopTinChi.NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
			sortedListLopTinChi.nodes[sortedListLopTinChi.number] = indexLopTinChi;
			sortedListLopTinChi.number++;
		}
	}
}

int deleteItem(DSLOPTINCHI& listLopTinChi, int i)
{
	if (i < 0 || i >= listLopTinChi.number || listLopTinChi.number == 0)
		return 0;
	for (int j = i + 1; j < listLopTinChi.number; j++)
		listLopTinChi.loptinchi[j - 1] = listLopTinChi.loptinchi[j];

	listLopTinChi.number--;
	return 1;
}

void clearListLopTinChi(DSLOPTINCHI& listLopTinChi) {
	while (listLopTinChi.number != 0) {
		deleteItem(listLopTinChi, 0);
	}
	listLopTinChi.number = 0;
//	delete[] listLopTinChi.loptinchi;

}

int sinhVienDaDangKyLopTinChi(DSLOPTINCHI listLopTinChi, char MASV[15]) {
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[i]->DSDK, MASV) == 1) {
			return 1;
		}
	}
	return 0;
}

int monHocDaDuocDungDeDangKyLTC(DSLOPTINCHI listLopTinChi, char MAMH[10]) {
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (strcmp(listLopTinChi.loptinchi[i]->MAMH, MAMH) == 0) {
			return 1;
		}
	}
	return 0;
}


void timLopTinChiSinhVienDaDangKy(DSLOPTINCHI listLopTinChi, DSLOPTINCHI& listLopTinChiSinhVienDaDangKy, char MASV[15]) {
	listLopTinChiSinhVienDaDangKy.number = 0;
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[i]->DSDK, MASV) == 1) {
			LopTinChi lopTinChi; 
			lopTinChi.MALOPTC = listLopTinChi.loptinchi[i]->MALOPTC;
			strcpy_s(lopTinChi.MAMH, listLopTinChi.loptinchi[i]->MAMH);
			strcpy_s(lopTinChi.NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
			lopTinChi.HOCKY = listLopTinChi.loptinchi[i]->HOCKY;
			lopTinChi.NHOM = listLopTinChi.loptinchi[i]->NHOM;
			lopTinChi.MINSV = listLopTinChi.loptinchi[i]->MINSV;
			lopTinChi.MAXSV = listLopTinChi.loptinchi[i]->MAXSV;
			lopTinChi.HUYLOP = listLopTinChi.loptinchi[i]->HUYLOP;

			insertLopTinChiOrderByMaLTC(listLopTinChiSinhVienDaDangKy, lopTinChi);
		}
	}
}

//void timLopTinChiSinhVienCoTheDangKy(DSLOPTINCHI listLopTinChi, DSLOPTINCHI& listLopTinChiSinhVienCoTheDangKy, char MASV[15]) {
//	listLopTinChiSinhVienCoTheDangKy.number = 0;
//	for (int i = 0; i < listLopTinChi.number; i++) {
//		if (kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[i]->DSDK, MASV) == 0) {
//			LopTinChi lopTinChi;
//			lopTinChi.MALOPTC = listLopTinChi.loptinchi[i]->MALOPTC;
//			strcpy_s(lopTinChi.MAMH, listLopTinChi.loptinchi[i]->MAMH);
//			strcpy_s(lopTinChi.NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
//			lopTinChi.HOCKY = listLopTinChi.loptinchi[i]->HOCKY;
//			lopTinChi.NHOM = listLopTinChi.loptinchi[i]->NHOM;
//			lopTinChi.MINSV = listLopTinChi.loptinchi[i]->MINSV;
//			lopTinChi.MAXSV = listLopTinChi.loptinchi[i]->MAXSV;
//			lopTinChi.HUYLOP = listLopTinChi.loptinchi[i]->HUYLOP;
//
//			insertLopTinChiOrderByMaLTC(listLopTinChiSinhVienCoTheDangKy, lopTinChi);
//		}
//	}
//}

//KIEM TRA DANH SACH DANG KY RONG
bool isDanhSachDangKyEmpty(LISTDANGKY first) {
	if (first == NULL) return true;
	return false;
}

// sinh viên hủy đăng ký
//Xoa tat ca cac truong hop trong danh sach dang ky cua lop tin chi
void xoaTrongDanhSachDangKyTheoMaSinhVien(LISTDANGKY& first, char MASV[15]) {
	if (isDanhSachDangKyEmpty(first)) return;

	if (strcmp(first->dangky.MASV, MASV) == 0) {
		NodeDK* p = first;    // nut can xoa la nut dau
		first = p->next;
		delete p;
		return;
	}

	NodeDK* q = nullptr;
	NodeDK* p = nullptr; //node dung truoc node q;
	for (q = first; q != NULL; q = q->next) {
		if (strcmp(q->dangky.MASV, MASV) == 0) {
			break;
		}
		p = q;
	}

	if (q != nullptr) {
		if (q->next != NULL) { //DELETE AFTER
			p->next = q->next;
		}
		else { //DELETE LAST
			p->next = NULL;
		}
		delete q;
	}
}
void timLopTinChiConMoTheoNienKhoa(DSLOPTINCHI listLopTinChi, DSLOPTINCHI& listLopTinChiTheoNienKhoa, int current_NIENKHOA) {
	listLopTinChiTheoNienKhoa.number = 0;
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (strcmp(listLopTinChi.loptinchi[i]->NIENKHOA, std::to_string(current_NIENKHOA).c_str()) == 0
			&& listLopTinChi.loptinchi[i]->HUYLOP == 0) {
			LopTinChi lopTinChi;
			lopTinChi.MALOPTC = listLopTinChi.loptinchi[i]->MALOPTC;
			strcpy_s(lopTinChi.MAMH, listLopTinChi.loptinchi[i]->MAMH);
			strcpy_s(lopTinChi.NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
			lopTinChi.HOCKY = listLopTinChi.loptinchi[i]->HOCKY;
			lopTinChi.NHOM = listLopTinChi.loptinchi[i]->NHOM;
			lopTinChi.MINSV = listLopTinChi.loptinchi[i]->MINSV;
			lopTinChi.MAXSV = listLopTinChi.loptinchi[i]->MAXSV;
			lopTinChi.HUYLOP = listLopTinChi.loptinchi[i]->HUYLOP;

			insertLopTinChiOrderByMaLTC(listLopTinChiTheoNienKhoa, lopTinChi);
		}
	}
}
void timLopTinChiConMoTheoNienKhoaHK(DSLOPTINCHI listLopTinChi, DSLOPTINCHI& listLopTinChiTheoNienKhoa, char NIENKHOA[15], int HOCKY) {
	listLopTinChiTheoNienKhoa.number = 0;
	for (int i = 0; i < listLopTinChi.number; i++) {
		if (strcmp(listLopTinChi.loptinchi[i]->NIENKHOA, NIENKHOA) == 0
			&& listLopTinChi.loptinchi[i]->HOCKY == HOCKY
			&& listLopTinChi.loptinchi[i]->HUYLOP == 0) {
			LopTinChi lopTinChi;
			lopTinChi.MALOPTC = listLopTinChi.loptinchi[i]->MALOPTC;
			strcpy_s(lopTinChi.MAMH, listLopTinChi.loptinchi[i]->MAMH);
			strcpy_s(lopTinChi.NIENKHOA, listLopTinChi.loptinchi[i]->NIENKHOA);
			lopTinChi.HOCKY = listLopTinChi.loptinchi[i]->HOCKY;
			lopTinChi.NHOM = listLopTinChi.loptinchi[i]->NHOM;
			lopTinChi.MINSV = listLopTinChi.loptinchi[i]->MINSV;
			lopTinChi.MAXSV = listLopTinChi.loptinchi[i]->MAXSV;
			lopTinChi.HUYLOP = listLopTinChi.loptinchi[i]->HUYLOP;

			insertLopTinChiOrderByMaLTC(listLopTinChiTheoNienKhoa, lopTinChi);
		}
	}
}
void sinhVienDangKyLopTinChi(DSLOPTINCHI& listLopTinChi, int MALTC_CANDANGKY, char MASV_DANGKY[15]) {
	int index = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC_CANDANGKY);
	DangKy dangky;
	strcpy_s(dangky.MASV, MASV_DANGKY);
	dangky.DIEM = 0;
	themVaoListDangKy(listLopTinChi.loptinchi[index]->DSDK, dangky);
}

int sinhVienDaDangKyMonNayNienKhoaHKNay(DSLOPTINCHI listLopTinChi, char MASV[15], LopTinChi* loptinchi) {
	for (int i = 0; i < listLopTinChi.number;i++) {
		// tìm tới 1 môn có cùng niên khóa, môn học, học kỳ(k cần tính tới nhóm vì k thể học 2 nhóm được)
		if (strcmp(listLopTinChi.loptinchi[i]->NIENKHOA, loptinchi->NIENKHOA) == 0
			&& strcmp(listLopTinChi.loptinchi[i]->MAMH, loptinchi->MAMH) == 0
			&& listLopTinChi.loptinchi[i]->HOCKY == loptinchi->HOCKY) {
			//kiểm tra xem danh sách đăng ký của lớp đó có sinh viên này k
			if (kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[i]->DSDK, MASV) == 1) {
				return 1;
			}
		}
	}
	return 0;
}


float tinhDiemTrungBinhKhoaHocCuaSinhVien(DSLOPTINCHI listLopTinChi, TREE treeMonHoc, char MASV[15]) {
	float avg = 0;
	float total = 0;
	float tongSoTinChi = 0;

	for (int i = 0; i < listLopTinChi.number; i++) {
		if (kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[i]->DSDK, MASV) == 1) {
			int soTinChiCuaMH = laySoTinChiCuaMH(treeMonHoc, listLopTinChi.loptinchi[i]->MAMH);

			total = total + ((layDiemCuaSinhVienTrongDSDK(listLopTinChi.loptinchi[i]->DSDK, MASV) * soTinChiCuaMH));
			tongSoTinChi = tongSoTinChi + soTinChiCuaMH;
		}
	}
	if (tongSoTinChi != 0) {
		avg = total / tongSoTinChi;
		return avg;
	}
	else {
		return -99;
	}
}