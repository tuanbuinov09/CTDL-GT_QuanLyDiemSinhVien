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