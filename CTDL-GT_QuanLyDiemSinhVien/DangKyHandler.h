#pragma once

using namespace std;
#include "struct.h"
#include "string"

//KIEM TRA DANH SACH RONG
bool isListDangKyEmpty(LISTDANGKY& first) {
	if (first == NULL) return true;
	return false;
}
LISTDANGKY initListDangKy() {
	LISTDANGKY DSDK = NULL;
	return DSDK;
}
//Them tat ca cac truong hop trong danh sach dang ky
void themVaoListDangKy(LISTDANGKY& first, DangKy dangky)
{
	NodeDK* p = new NodeDK;
	NodeDK* t = new NodeDK;
	NodeDK* s = new NodeDK;  // t la nut truoc, s la nut sau
	p->dangky = dangky;
	
	for (s = first; s != NULL && strcmp(s->dangky.MASV, dangky.MASV) > 0; t = s, s = s->next);
	if (s == first)  // them nut vao dau danh sach lien ket
	{
		p->next = first;
		first = p;
	}
	else // them nut p vao truoc nut s
	{
		p->next = s;
		t->next = p;
	}
}

void duyetListDangKy(LISTDANGKY first) {
	for (NodeDK* k = first; k != NULL; k = k->next) {
		cout << k->dangky.MASV << " ";
	}
	cout << "\n";
}

void listDangKyToIndexListDangKy(LISTDANGKY listDangKy, IndexListDangKy& indexListDangKy, int MAXSV, ListSinhVien listSinhVien)
{
	indexListDangKy.number = 0;
	indexListDangKy.nodes = new IndexDangKy[MAXSV];
	for (NodeDK* k = listDangKy; k!=NULL; k=k->next) {
		indexListDangKy.nodes[indexListDangKy.number].index = indexListDangKy.number;
		strcpy_s(indexListDangKy.nodes[indexListDangKy.number].MASV, k->dangky.MASV);
		int indexSV = timIndexSinhVienTheoMASV(listSinhVien, k->dangky.MASV);
		strcpy_s(indexListDangKy.nodes[indexListDangKy.number].HO, listSinhVien.sinhvien[indexSV].HO);
		strcpy_s(indexListDangKy.nodes[indexListDangKy.number].TEN, listSinhVien.sinhvien[indexSV].TEN);

		indexListDangKy.number++;
	}
}
void clearIndexListDangKy(IndexListDangKy& indexListDangKy) {
	indexListDangKy.number = 0;
	delete[] indexListDangKy.nodes;
}
//SAP XEP THEO TEN SINHVIEN
void sapXepListDangKyTheoHOTENSV(IndexListDangKy& sortedListDangKy)
{
	int i, j;
	for (i = 0; i < sortedListDangKy.number - 1; i++) {
		for (j = 0; j < sortedListDangKy.number - i - 1; j++) {
			if (_stricmp(sortedListDangKy.nodes[j].TEN, sortedListDangKy.nodes[j + 1].TEN) > 0) {
				swap(sortedListDangKy.nodes[j], sortedListDangKy.nodes[j + 1]);
			}
			else if (_stricmp(sortedListDangKy.nodes[j].TEN, sortedListDangKy.nodes[j + 1].TEN) == 0) {
				if (_stricmp(sortedListDangKy.nodes[j].HO, sortedListDangKy.nodes[j + 1].HO) > 0) {
					swap(sortedListDangKy.nodes[j], sortedListDangKy.nodes[j + 1]);
				}
				else if (_stricmp(sortedListDangKy.nodes[j].HO, sortedListDangKy.nodes[j + 1].HO) == 0) {
					if (sortedListDangKy.nodes[j].index > (sortedListDangKy.nodes[j + 1].index)) {
						swap(sortedListDangKy.nodes[j], sortedListDangKy.nodes[j + 1]);
					}
					//if (_stricmp(listSinhVien.sinhvien[j].MASV, listSinhVien.sinhvien[j + 1].MASV) > 0) {// nếu họ tên giống nhau thì sắp theo mã
					//	swap(listSinhVien.sinhvien[j], listSinhVien.sinhvien[j + 1]);
					//}
				}
			}
		}
	}
}

bool isSortedListDangKyEmpty(IndexListDangKy& sortedListDangKy) {
	return sortedListDangKy.number == 0 ? true : false;
}

int kiemTraSinhVienCoDangKy(LISTDANGKY listDangKy, char MASV[15])
{
	for (NodeDK* k = listDangKy; k != NULL; k = k->next) {
		if (strcmp(k->dangky.MASV, MASV) == 0){
			return 1;
		}
	}
	return 0;
}