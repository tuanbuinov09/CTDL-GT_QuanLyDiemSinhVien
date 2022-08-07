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
	//sortedListSinhVien.nodes =  Index[listSinhVien.number];

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
	for (int i = 0;i < indexListSinhVien.number;i++) {
		deleteItem(indexListSinhVien, i);
	}
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