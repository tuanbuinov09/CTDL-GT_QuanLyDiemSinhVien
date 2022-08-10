#pragma once
using namespace std;
#include "struct.h"
#include "string"
#include <iostream>

void khoiTaoCay(TREE& treeMonHoc) {
	treeMonHoc = NULL;
}
void themMonHocVaoCayOrderByMAMH(TREE& treeMonHoc, MonHoc monhoc) {
	//nếu cây rỗng
	if (treeMonHoc == NULL) {
		NodeMH* p = new NodeMH();
		strcpy_s(p->MH.MAMH, monhoc.MAMH);
		strcpy_s(p->MH.TENMH, monhoc.TENMH);
		p->MH.STCLT, monhoc.STCLT;
		p->MH.STCTH, monhoc.STCTH;

		p->left = NULL;
		p->right = NULL;

		//bây h p là nút gốc của cây
		treeMonHoc = p;
	}
	else {
		// nếu MAMH nhỏ hơn nút gốc qua trái đệ quy
		if (strcmp(monhoc.MAMH , treeMonHoc->MH.MAMH) < 0) {
			themMonHocVaoCayOrderByMAMH(treeMonHoc->left, monhoc);
		}// nếu MAMH >  nút gốc qua phải đệ quy
		else if (strcmp(monhoc.MAMH, treeMonHoc->MH.MAMH) > 0) {
			themMonHocVaoCayOrderByMAMH(treeMonHoc->right, monhoc);
		}// trùng mã mh thì k thêm
	}
}
// duyejt cây
void duyetCayNLR(TREE& treeMonHoc) {
	if (treeMonHoc != NULL) {
		cout << treeMonHoc->MH.MAMH;
		cout << " ";
		duyetCayNLR(treeMonHoc->left); // duyệt qua trái
		duyetCayNLR(treeMonHoc->right); // duyệt qua phải
	}
}

// chuyển cây thành index list để so sánh
void treeMonHocToIndexListMonHoc(TREE& treeMonHoc, IndexListMonHoc& sortedListMonHoc)
{

	if (treeMonHoc != NULL) {

		sortedListMonHoc.nodes[sortedListMonHoc.number].index = sortedListMonHoc.number;

		strcpy_s(sortedListMonHoc.nodes[sortedListMonHoc.number].MAMH, treeMonHoc->MH.MAMH);
		strcpy_s(sortedListMonHoc.nodes[sortedListMonHoc.number].TENMH, treeMonHoc->MH.TENMH);
		sortedListMonHoc.nodes[sortedListMonHoc.number].STCLT = treeMonHoc->MH.STCLT;
		sortedListMonHoc.nodes[sortedListMonHoc.number].STCTH = treeMonHoc->MH.STCTH;

		sortedListMonHoc.number = sortedListMonHoc.number + 1;

		treeMonHocToIndexListMonHoc(treeMonHoc->left, sortedListMonHoc); // duyệt qua trái
		treeMonHocToIndexListMonHoc(treeMonHoc->right, sortedListMonHoc); // duyệt qua phải
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
}