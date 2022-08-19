#pragma once
using namespace std;
#include "struct.h"
#include "string"
#include <iostream>

void khoiTaoCay(TREE& treeMonHoc) {
	treeMonHoc = NULL;
}

void themMonHocVaoCay(TREE& treeMonHoc, MonHoc monhoc) {
	//nếu cây rỗng
	if (treeMonHoc == NULL) {
		NodeMH* p = new NodeMH();
		strcpy_s(p->MH.MAMH, monhoc.MAMH);
		strcpy_s(p->MH.TENMH, monhoc.TENMH);
		p->MH.STCLT = monhoc.STCLT;
		p->MH.STCTH = monhoc.STCTH;

		p->left = NULL;
		p->right = NULL;

		treeMonHoc = p;
	}
	else {
		// nếu MAMH nhỏ hơn nút gốc qua trái đệ quy
		if (strcmp(monhoc.MAMH , treeMonHoc->MH.MAMH) < 0) {
			themMonHocVaoCay(treeMonHoc->left, monhoc);
		}// nếu MAMH >  nút gốc qua phải đệ quy
		else if (strcmp(monhoc.MAMH, treeMonHoc->MH.MAMH) > 0) {
			themMonHocVaoCay(treeMonHoc->right, monhoc);
		}// trùng mã mh thì k thêm
	}
}

TREE nodeMH_MaMHmin(TREE treeMonHoc) { // node trái nhất của cây môn học
	while (treeMonHoc->left != NULL) {
		treeMonHoc = treeMonHoc->left;
	}
	return treeMonHoc;
}

void timNodeTheMang(TREE& p, TREE& q) {
	if (q->left != NULL) {
		timNodeTheMang(p, q->left);//tim node trai nhat
	}
	else { // tim dc node trai nhat r
		p->MH = q->MH;// cập nhật data của node cần xóa = node trái nhất (nhỏ nhất của cây bên phải)
		p = q; // cho node cần xóa trỏ đến l
		q = q->right; // l->right : NULL // cập nhật lại liên kết node cha của node thay thế
	}
}

// xóa sao cho đảm bảo tính chất bên trái mã luôn nhỏ hơn bên phải
int xoaMonHocTrongCayByMAMH(TREE& treeMonHoc, char MAMH[15]) {
	//nếu cây rỗng
	if (treeMonHoc == NULL) {
		return 0;
	}
	else {
		// nếu MAMH nhỏ hơn nút gốc qua trái đệ quy
		if (strcmp(MAMH, treeMonHoc->MH.MAMH) < 0) {
			xoaMonHocTrongCayByMAMH(treeMonHoc->left, MAMH);
		}// nếu MAMH >  nút gốc qua phải đệ quy
		else if (strcmp(MAMH, treeMonHoc->MH.MAMH) > 0) {
			xoaMonHocTrongCayByMAMH(treeMonHoc->right, MAMH);
		}
		else { //strcmp(MAMH, treeMonHoc->MH.MAMH) == 0 nếu mã đang trỏ  =  mã cần tìm, trả kết quả
			NodeMH* p = treeMonHoc; // node sau này sẽ xóa

			if (treeMonHoc->left == NULL) { // nếu node k có bên trái, 
				//node cần xóa = node cần xóa trỏ đến right (h right đang ở chỗ của node)
				treeMonHoc = treeMonHoc->right;
			}
			else if (treeMonHoc->right == NULL) {// nếu node k có bên phải
				//node cần xóa = node cần xóa trỏ đến left (h left đang ở chỗ của node)
				treeMonHoc = treeMonHoc->left;
			}
			else {//node có 2 con
				//tìm sang bên trái cùng của nhánh phải, chính là node thay thế
				NodeMH* q = treeMonHoc->right; 
				timNodeTheMang(p, q);
				
			}
			delete p; //xóa node cần xóa, cho cả trường hợp node k có left right (không cần cập nhật liên kết)
			return 1;
		}
	}
}
// giải phóng vùng nhớ cho cây
void clearTreeMonHoc(TREE& treeMonHoc){
	while(treeMonHoc!=NULL){
		{
			NodeMH* p = treeMonHoc; // node sau này sẽ xóa

			if (treeMonHoc->left == NULL) { // nếu node k có bên trái, 
				//node cần xóa = node cần xóa trỏ đến right (h right đang ở chỗ của node)
				treeMonHoc = treeMonHoc->right;
			}
			else if (treeMonHoc->right == NULL) {// nếu node k có bên phải
				//node cần xóa = node cần xóa trỏ đến left (h left đang ở chỗ của node)
				treeMonHoc = treeMonHoc->left;
			}
			else {//node có 2 con
				//tìm sang bên trái cùng của nhánh phải, chính là node thay thế
				NodeMH* q = treeMonHoc->right;
				timNodeTheMang(p, q);

			}
			delete p; //xóa node cần xóa, cho cả trường hợp node k có left right (không cần cập nhật liên kết)
		}
	}
 }

// duyejt cây
void duyetCayNLR(TREE treeMonHoc) {
	if (treeMonHoc != NULL) {
		cout << treeMonHoc->MH.MAMH;
		cout << " ";
		duyetCayNLR(treeMonHoc->left); // duyệt qua trái
		duyetCayNLR(treeMonHoc->right); // duyệt qua phải
	}
}

// chuyển cây thành index list để so sánh
void treeMonHocToIndexListMonHoc(TREE& treeMonHoc, IndexListMonHoc& sortedListMonHoc, bool init)
{
	if (init) {
		sortedListMonHoc.nodes = new IndexMonHoc[200];
		sortedListMonHoc.number = 0;
	}

	if (treeMonHoc != NULL) {

		sortedListMonHoc.nodes[sortedListMonHoc.number].index = sortedListMonHoc.number;

		strcpy_s(sortedListMonHoc.nodes[sortedListMonHoc.number].MAMH, treeMonHoc->MH.MAMH);
		strcpy_s(sortedListMonHoc.nodes[sortedListMonHoc.number].TENMH, treeMonHoc->MH.TENMH);
		sortedListMonHoc.nodes[sortedListMonHoc.number].STCLT = treeMonHoc->MH.STCLT;
		sortedListMonHoc.nodes[sortedListMonHoc.number].STCTH = treeMonHoc->MH.STCTH;

		sortedListMonHoc.number = sortedListMonHoc.number + 1;

		treeMonHocToIndexListMonHoc(treeMonHoc->left, sortedListMonHoc, false); // duyệt qua trái
		treeMonHocToIndexListMonHoc(treeMonHoc->right, sortedListMonHoc, false); // duyệt qua phải
	}
}

//SAP XEP THEO TEN MONHOC
void sapXepListMonHocTheoTen(IndexListMonHoc& sortedListMonHoc)
{

	int i, j;
	for (i = 0; i < sortedListMonHoc.number - 1; i++) {
		for (j = 0; j < sortedListMonHoc.number - i - 1; j++) {
			if (_stricmp(sortedListMonHoc.nodes[j].TENMH, sortedListMonHoc.nodes[j + 1].TENMH) > 0) {
				swap(sortedListMonHoc.nodes[j], sortedListMonHoc.nodes[j + 1]);
			}
		}
	}
}

bool isSortedListMonHocEmpty(IndexListMonHoc& sortedListMonHoc) {
	return sortedListMonHoc.number == 0 ? true : false;
}

void clearIndexListMonHoc(IndexListMonHoc& indexListMonHoc) {
	indexListMonHoc.number = 0;
	delete[] indexListMonHoc.nodes;
}


// lấy ra môn học theo mã môn học
NodeMH* timMonHocTheoMaMonHoc(TREE treeMonHoc, string MAMH_STR) {

	if (treeMonHoc == NULL) {
		return NULL;
	}
	else {
		
		if (_stricmp(MAMH_STR.c_str(), treeMonHoc->MH.MAMH) < 0) { // nếu mã đang trỏ nhỏ hơn mã cần tìm, qua trái
			//return neeus k sau khi return se chay them lan nua
			return timMonHocTheoMaMonHoc(treeMonHoc->left, MAMH_STR); // duyệt qua trái
		}
		else if (_stricmp(MAMH_STR.c_str(), treeMonHoc->MH.MAMH) > 0) { // nếu mã đang trỏ lớn hơn mã cần tìm, qua phải
			//return neeus k sau khi return se chay them lan nua
			return timMonHocTheoMaMonHoc(treeMonHoc->right, MAMH_STR); // duyệt qua phải
		}
		else if (_stricmp(MAMH_STR.c_str(), treeMonHoc->MH.MAMH) == 0) { // nếu mã đang trỏ  =  mã cần tìm, trả kết quả
			//return neeus k sau khi return se chay them lan nua
			return treeMonHoc;
		}
	}
}

int laySoTinChiCuaMH(TREE treeMonHoc, char MAMH[15]) {
	int num = 0;
	NodeMH* monhoc = timMonHocTheoMaMonHoc(treeMonHoc, MAMH);
	if (monhoc != NULL) {
		num = monhoc->MH.STCLT + monhoc->MH.STCTH;
	}
	return num;
}

int suaMonHoc(TREE& treeMonHoc, MonHoc monhoc) {
	NodeMH* nodeMHCanSua = timMonHocTheoMaMonHoc(treeMonHoc, monhoc.MAMH);
	if (nodeMHCanSua == NULL) {
		return 0;
	}
	else {
		strcpy_s(nodeMHCanSua->MH.TENMH, monhoc.TENMH);
		nodeMHCanSua->MH.STCLT = monhoc.STCLT;
		nodeMHCanSua->MH.STCTH= monhoc.STCTH;
		return 1;
	}
}

//KIEM TRA MA MON HOC
string checkMaMonHoc(TREE& treeMonHoc, string MAMH_STR) {
	if (MAMH_STR.empty()) return "MA MON HOC khong duoc de trong";
	if (MAMH_STR.length() > 10) return "MA MON HOC khong duoc qua 10 ki tu ";

	NodeMH* s = NULL;
	s = timMonHocTheoMaMonHoc(treeMonHoc, MAMH_STR);
	if (s != NULL) return "MA MON HOC da ton tai";
	else return "";
}

//KIEM TRA MA MON HOC KHONG TON TAI
string checkMaMonHocKhongTonTai(TREE& treeMonHoc, string MAMH_STR) {
	if (MAMH_STR.empty()) return "MA MON HOC khong duoc de trong";
	NodeMH* s = timMonHocTheoMaMonHoc(treeMonHoc, MAMH_STR);
	if (s != 0) return "";
	else return "MA MON HOC khong ton tai";
}

//KIEM TRA TEN MON HOC
string checkTENMH(string TENMH) {
	if (TENMH.empty()) return "TEN MON HOC khong duoc de trong";
	if (TENMH.length() > 50) return "TEN MON HOC khong qua 50 ki tu";
	//tên môn học có thể chứa số (ví dụ đường lối 1, 2)
	/*for (int i = 0; i < TENMH.length(); i++) {
		if (isdigit(TENMH[i])) {
			return "TENMH khong duoc chua ki tu so";
		}
	}*/
	return "";
}

//KIEM TRA SO TC LY THUYET, SO TC THUC HANH
string checkSOTCLT_TH(string SOTC, string LTTH) {

	//LTTH truyền vào "SO TCLT" HOAC "SO TCTH"
	if (SOTC.empty()) return LTTH + " khong duoc de trong";
	for (int i = 0; i < SOTC.length(); i++) {
		if (SOTC[i] == 32 && isalpha(SOTC[i + 1])) {
			return LTTH + " khong chua khoang trang giua cac so";
		}
		else if (!isdigit(SOTC[i])) {
			return LTTH + " khong duoc chua ki tu chu";
		}
	}

	return "";
}


// tìm môn học theo tên
void searchTreeMonHocTheoTenMonHoc(TREE treeMonHoc, IndexListMonHoc& indexListMonHoc, string TENMH_STR, bool init) {
	if (init) {
		indexListMonHoc.nodes = new IndexMonHoc[200];
		indexListMonHoc.number = 0;
	}
	if (treeMonHoc == NULL) {
		return;
	}
	else {
		char* output = NULL;
		output = strstr(treeMonHoc->MH.TENMH, TENMH_STR.c_str());
		if (output) {
			IndexMonHoc indexMonHoc;
			indexMonHoc.index = indexListMonHoc.number;
			strcpy_s(indexMonHoc.TENMH, treeMonHoc->MH.TENMH);
			strcpy_s(indexMonHoc.MAMH, treeMonHoc->MH.MAMH);
			indexMonHoc.STCLT = treeMonHoc->MH.STCLT;
			indexMonHoc.STCTH = treeMonHoc->MH.STCTH;
			indexListMonHoc.nodes[indexListMonHoc.number] = indexMonHoc;
			indexListMonHoc.number++;
		}
			searchTreeMonHocTheoTenMonHoc(treeMonHoc->left, indexListMonHoc, TENMH_STR, false); // duyệt qua trái
			searchTreeMonHocTheoTenMonHoc(treeMonHoc->right, indexListMonHoc, TENMH_STR, false); // duyệt qua phải
	}
}
