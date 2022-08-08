#pragma once
using namespace std;
#include "struct.h"
#include "string"

int timMaLopTrongListLop(ListLop& listLop, char MALOP[15]) {
	for (int i = 0; i < listLop.number; i++) {
		if (_stricmp(listLop.lop[i].MALOP, MALOP) == 0) {
			return 1;
		}
	}
	return 0;
}

void insertLopOrder(ListLop& listLop, Lop& lop/*, string type*/) {
	if (timMaLopTrongListLop(listLop, lop.MALOP) == 1) {
		return;
	}
	int i, j;
	//TIM KIEM VI TRI SE THEM VAO
	for (i = 0; i < listLop.number && _stricmp(listLop.lop[i].MALOP, lop.MALOP) < 0; i++);

	//TINH TIEN TU VI TRI THU I DO
	for (j = listLop.number - 1; j >= i; j--) {
		listLop.lop[j + 1] = listLop.lop[j];
	}
	//THEM LOP VAO
	listLop.lop[i] = lop;
	listLop.number++;
}



void listLopToIndexListLop(ListLop& listLop, IndexListLop& indexListLop)
{
	indexListLop.number = listLop.number;
	//sortedListSinhVien.nodes =  Index[listSinhVien.number];

	for (int i = 0; i < listLop.number; i++) {
		indexListLop.nodes[i].index = i;
		strcpy_s(indexListLop.nodes[i].MALOP, listLop.lop[i].MALOP);

	}
}

bool isIndexListLopEmpty(IndexListLop& indexListLop) {
	return indexListLop.number == 0 ? true : false;
}

void searchListLopByMaLop(ListLop& listLop, IndexListLop& indexListLop, string maLop) {
	indexListLop.number = 0;

	for (int i = 0; i < listLop.number; i++) {
		char* output = NULL;
		output = strstr(listLop.lop[i].MALOP, maLop.c_str());
		if (output) {
			IndexLop indexLop;
			indexLop.index = i;
			strcpy_s(indexLop.MALOP, listLop.lop[i].MALOP);
			indexListLop.nodes[indexListLop.number] = indexLop;
			indexListLop.number++;
		}
	}
	
}

int deleteItem(IndexListLop& indexListLop, int i)
{
	if (i < 0 || i >= indexListLop.number || indexListLop.number == 0)
		return 0;
	for (int j = i + 1; j < indexListLop.number; j++)
		indexListLop.nodes[j - 1] = indexListLop.nodes[j];
	
	indexListLop.number--;
	return 1;
}

void clearIndexListLop(IndexListLop& indexListLop) {
	indexListLop.number = 0;
}