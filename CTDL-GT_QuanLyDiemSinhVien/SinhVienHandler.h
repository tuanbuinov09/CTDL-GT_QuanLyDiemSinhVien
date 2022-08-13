#pragma once

using namespace std;
#include "string"

//KIEM TRA DANH SACH SINH VIEN DAY
bool isListSinhVienFull(ListSinhVien& listSinhVien) {
	return listSinhVien.number == MAXDSSV ? true : false;
}
//THEM SINH VIEN
void insertSinhVienOrder(ListSinhVien& listSinhVien, SinhVien& sinhVien/*, string type*/) {
	int i, j;
	//TIM KIEM VI TRI SE THEM VAO
	for (i = 0; i < listSinhVien.number && _stricmp(listSinhVien.sinhvien[i].MASV, sinhVien.MASV) < 0; i++);

	//TINH TIEN TU VI TRI THU I DO
	for (j = listSinhVien.number - 1; j >= i; j--) {
		listSinhVien.sinhvien[j + 1] = listSinhVien.sinhvien[j];
	}

	//TAO SINH VIEN MOI VA THEM VAO VI TRI DO
	listSinhVien.sinhvien[i] = sinhVien;
	listSinhVien.number++;
}
//SAP XEP THEO TEN SINHVIEN
void sapXepListSinhVienTheoTen(IndexList& sortedListSinhVien)
{

	int i, j;
	for (i = 0; i < sortedListSinhVien.number - 1; i++) {
		for (j = 0; j < sortedListSinhVien.number - i - 1; j++) {
			if (_stricmp(sortedListSinhVien.nodes[j].TEN, sortedListSinhVien.nodes[j + 1].TEN) > 0) {
				swap(sortedListSinhVien.nodes[j], sortedListSinhVien.nodes[j + 1]);
			}
			else if (_stricmp(sortedListSinhVien.nodes[j].TEN, sortedListSinhVien.nodes[j + 1].TEN) == 0) {
				if (_stricmp(sortedListSinhVien.nodes[j].HO, sortedListSinhVien.nodes[j + 1].HO) > 0) {
					swap(sortedListSinhVien.nodes[j], sortedListSinhVien.nodes[j + 1]);
				}
				else if (_stricmp(sortedListSinhVien.nodes[j].HO, sortedListSinhVien.nodes[j + 1].HO) == 0) {
					if (sortedListSinhVien.nodes[j].index > (sortedListSinhVien.nodes[j + 1].index)) {
						swap(sortedListSinhVien.nodes[j], sortedListSinhVien.nodes[j + 1]);
					}
					//if (_stricmp(listSinhVien.sinhvien[j].MASV, listSinhVien.sinhvien[j + 1].MASV) > 0) {// nếu họ tên giống nhau thì sắp theo mã
					//	swap(listSinhVien.sinhvien[j], listSinhVien.sinhvien[j + 1]);
					//}
				}
			}
		}
	}
}

bool isSortedListSinhVienEmpty(IndexList& sortedListSinhVien) {
	return sortedListSinhVien.number == 0 ? true : false;
}

void listSinhVienToListIndexSinhVien(ListSinhVien& listSinhVien, IndexList& sortedListSinhVien)
{
	sortedListSinhVien.number = listSinhVien.number;
	sortedListSinhVien.nodes =  new Index[listSinhVien.number];

	for (int i = 0; i < listSinhVien.number; i++) {
		sortedListSinhVien.nodes[i].index = i;
		strcpy_s(sortedListSinhVien.nodes[i].HO, listSinhVien.sinhvien[i].HO);
		strcpy_s(sortedListSinhVien.nodes[i].TEN, listSinhVien.sinhvien[i].TEN);
	}
}

void locSinhVienTheoLop(ListSinhVien& listSinhVienTheoLop, ListSinhVien& listSinhVien, char MALOP[15]) {

	for (int i = 0; i < listSinhVien.number; i++) {
		if (_stricmp(listSinhVien.sinhvien[i].MALOP, MALOP) == 0) {
			insertSinhVienOrder(listSinhVienTheoLop, listSinhVien.sinhvien[i]);
		}
	}
}
int deleteItem(IndexList& indexListSinhVien, int i)
{
	if (i < 0 || i >= indexListSinhVien.number || indexListSinhVien.number == 0)
		return 0;
	for (int j = i + 1; j < indexListSinhVien.number; j++)
		indexListSinhVien.nodes[j - 1] = indexListSinhVien.nodes[j];
	indexListSinhVien.number--;
	return 1;
}

void clearIndexListSinhVien(IndexList& indexListSinhVien) {
	indexListSinhVien.number = 0;
	delete[] indexListSinhVien.nodes;
}

int deleteItem(ListSinhVien& listSinhVien, int i)
{
	if (i < 0 || i >= listSinhVien.number || listSinhVien.number == 0)
		return 0;
	for (int j = i + 1; j < listSinhVien.number; j++)
		listSinhVien.sinhvien[j - 1] = listSinhVien.sinhvien[j];
		listSinhVien.number--;
	return 1;
}

void clearListSinhVien(ListSinhVien& listSinhVien) {
	listSinhVien.number = 0;
}

//==================== KIEM TRA DU LIEU NHAP VAO ====================

//TAO MA SINH VIEN
//char[] generateMaSinhVien(ListSinhVien& listSinhVien) {
//	char employeeId = "NVxxx";
//	do
//	{
//		srand(time(NULL));
//		for (int i = 2; i < employeeId.length(); i++) {
//			employeeId[i] = rand() % (57 - 48 + 1) + 48;
//		}
//	} while (searchEmployee(employeeList, employeeId) != -1);
//
//	return employeeId;
//}


int xoaSinhVienTheoMaSV(ListSinhVien& listSinhVien, char MASV[15])
{
	if (listSinhVien.number == 0)
		return 0;
	for (int i=0; i < listSinhVien.number; i++)
		if (_stricmp(listSinhVien.sinhvien[i].MASV, MASV) == 0) {
			deleteItem(listSinhVien, i);
			break;
		}
	return 1;
}

int maSinhVienDaTonTai(ListSinhVien& listSinhVien, string MASV) {

	for (int i = 0; i < listSinhVien.number; i++) {
		if (_stricmp(listSinhVien.sinhvien[i].MASV, MASV.c_str()) == 0) {
			return 1;
		}
	}
	return 0;
}

//KIEM TRA MA SINH VIEN
string checkMaSinhVien(ListSinhVien& listSinhVien, string MASV_STR) {
	if (MASV_STR.empty()) return "MA SINH VIEN khong duoc de trong";
	if (MASV_STR.length() > 15) return "MA SINH VIEN khong duoc qua 15 ki tu ";

	int s = maSinhVienDaTonTai(listSinhVien, MASV_STR);
	if (s != 0) return "MA SINH VIEN da ton tai";
	else return "";
}

//KIEM TRA MASV KHONG TON TAI
string checkMaSVKhongTonTai(ListSinhVien& listSinhVien, string MASV_STR) {
	if (MASV_STR.empty()) return "MA SINH VIEN khong duoc de trong";
	int s = maSinhVienDaTonTai(listSinhVien, MASV_STR);
	if (s != 0) return "";
	else return "MA SINH VIEN khong ton tai";
}

//KIEM TRA HO
string checkHO(string HO) {
	if (HO.empty()) return "HO khong duoc de trong";
	if (HO.length() > 30) return "HO khong qua 30 ki tu";
	for (int i = 0; i < HO.length(); i++) {
		if (isdigit(HO[i])) {
			return "HO khong duoc chua ki tu so";
		}
	}
	return "";
}

//KIEM TRA TEN
string checkTEN(string TEN) {
	if (TEN.empty()) return "TEN khong duoc de trong";
	if (TEN.length() > 10) return "TEN khong qua 10 ki tu";
	for (int i = 0; i < TEN.length(); i++) {
		if (TEN[i] == 32 && isalpha(TEN[i + 1])) {
			return "TEN chi duoc dien 1 tu";
		}
		else if (isdigit(TEN[i])) {
			return "TEN khong duoc chua ki tu so";
		}
	}
	return "";
}

//KIEM TRA GIOI TINH
string checkGioiTinh(string gender) {
	string male = "NAM";
	string female = "NU";

	if (gender.empty()) return "PHAI khong duoc de trong";
	if (gender.compare(male) != 0 && gender.compare(female) != 0) {
		return "PHAI chi la NAM hoac NU";
	}
	return "";
}

//KIEM TRA SDT
string checkSODT(string SODT) {
	if (SODT.empty()) return "SODT khong duoc de trong";
	if (SODT.length() > 15) return "SODT khong qua 15 ki tu";
	for (int i = 0; i < SODT.length(); i++) {
		if (SODT[i] == 32 && isalpha(SODT[i + 1])) {
			return "SODT khong chua khoang trang giua cac so";
		}
		else if (!isdigit(SODT[i])) {
			return "SODT khong duoc chua ki tu chu";
		}
	}
	return "";
}


void searchListSinhVienByTen(ListSinhVien& listSinhVien, IndexList& indexListSinhVien, string tenSinhVien) {
	indexListSinhVien.number = 0;

	for (int i = 0; i < listSinhVien.number; i++) {
		char* output = NULL;
		output = strstr(listSinhVien.sinhvien[i].TEN, tenSinhVien.c_str());
		if (output) {
			Index indexSinhVien;
			indexSinhVien.index = i;
			strcpy_s(indexSinhVien.TEN, listSinhVien.sinhvien[i].TEN);
			strcpy_s(indexSinhVien.HO, listSinhVien.sinhvien[i].HO);
			indexListSinhVien.nodes[indexListSinhVien.number] = indexSinhVien;
			indexListSinhVien.number++;
		}
	}

}