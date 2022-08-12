#pragma once
using namespace std;
#include "string"
#include "DangKyHandler.h"
#include <iostream>

//THEM LOP TIN CHI
void themLopTinChiOrderByMaLTC(DSLOPTINCHI& listLopTinChi, LopTinChi& lopTinChi) {
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

