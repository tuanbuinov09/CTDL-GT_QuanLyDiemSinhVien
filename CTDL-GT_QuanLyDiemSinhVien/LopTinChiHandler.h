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
	//tên môn học có thể chứa số (ví dụ đường lối 1, 2)
	/*for (int i = 0; i < TENMH.length(); i++) {
		if (isdigit(TENMH[i])) {
			return "TENMH khong duoc chua ki tu so";
		}
	}*/
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