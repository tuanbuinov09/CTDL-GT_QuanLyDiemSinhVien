﻿#pragma once
#include "file-handler.h"
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;
void listSinhVienTable(ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]);
void listLop_ChonLopTable(ListLop& listLop, IndexListLop& indexListLop, string viewMode, bool isSearch);
void treeMonHocTable(TREE& treeMonHoc, IndexListMonHoc& sortedListMonHoc, bool isSearch);
int popUpThemSinhVien(ListSinhVien& listSinhVien, char MALOP[15]);
int popUpSuaSinhVien(ListSinhVien& listSinhVien, char MASV[15]);
int popUpThemMonHoc(TREE& treeMonHoc);
int popUpSuaMonHoc(TREE& treeMonHoc, char MAMH_CANSUA[15], IndexListMonHoc& sortedListMonHoc);
void listLopTinChiTable(ListLopTinChi& listLopTinChi, IndexListLopTinChi& sortedListLopTinChi, bool isSearch);
int popUpThemLopTinChi(ListLopTinChi& listLopTinChi, char MAMH[15]);
int popUpSuaLopTinChi(ListLopTinChi& listLopTinChi, int indexLopTinChiCanSua, IndexListLopTinChi& sortedListLopTinChi);
void listSinhVienDangKyTable(ListDangKy& listLop, IndexListDangKy& sortedListDangKy, bool isSearch, string tabletitle);
char* popUpNhapMaSinhVien();
void popUpNhapNienKhoaHocKy(SinhVien sinhvien);
void listLopTinChiSinhVienDangKyTable(ListLopTinChi& listLopTinChi, ListLopTinChi& listLopTinChiSinhVienDaDangKy, IndexListLopTinChi& sortedListLopTinChiSinhVienDaDangKy, SinhVien sinhvien, bool isSearch);
void tree_ChonMonHocTable(TREE treeMonHoc, IndexListMonHoc& sortedListMonHoc, bool isSearch);
void listLopTinChi_ChonLopTinChiTable(ListLopTinChi& listLopTinChi, IndexListLopTinChi& sortedListLopTinChi, bool isSearch);
void bangDiemLTCTable(ListDangKy& listDangKy, IndexListDangKy& sortedListDangKy, bool isSearch, string tabletitle);
void listBangDiemTBSinhVienTable(ListLopTinChi listLopTinChi, TREE treeMonHoc, ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]);
void listBangDiemTongKetSinhVienTable(ListLopTinChi listLopTinChi, IndexListMonHoc& indexListMonHocSVLopDADK, ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]);
int notificationPopUp(string message);

TREE treeMonHoc;
ListSinhVien listSinhVien;
ListLop listLop;
ListLopTinChi listLopTinChi;
int maxMALOPTC;

string convertToString(char* a)
{
	string s = a;
	return s;
}

string floatToStringMark(float diem) {
	char diemTB_STR[5];
	snprintf(diemTB_STR, 5, "%0.1f", diem); // lấy 1 chữ số sau dấu .
	std::string str(diemTB_STR);
	return diemTB_STR;
}

int getCurrentYear() {
	time_t current_time;
	current_time = time(NULL);
	int a;
	a = 1970 + current_time / 31537970;
	return a;
}
void upperCaseWhileTyping(int x, int y, string& text, char& key) {
	ShowCur(1);
	setTextColor(COLOR_LIGHT_YELLOW);
	setBackgroundColor(COLOR_BLACK);

	if (!text.empty()) {
		gotoXY(x, y);
		cout << text;
	}
	else {
		gotoXY(x, y);
	}
	while (true) { // Note: chua xu li duoc truong hop nhan nhieu backspace lien tiep
		if (key == -32 || key == ESC || key == F4) {
			return;
		}
		else if (key == BACKSPACE)
		{
			if (text.empty()) {
				key = _getch();
			}
			else {
				text.pop_back();
				gotoXY(x + text.length(), y);
				cout << char(32);
				gotoXY(x + text.length(), y);
			}
		}
		else if (key >= 1 && key <= 255 && isprint(key) != 0) {
			text.push_back(char(toupper(key)));
			cout << char(toupper(key));
		}
		key = _getch();

	}
}

void upperCaseWhileTypingEnter(int x, int y, string& text, char& key) {
	ShowCur(1);
	setTextColor(COLOR_LIGHT_YELLOW);
	setBackgroundColor(COLOR_BLACK);

	if (!text.empty()) {
		gotoXY(x, y);
		cout << text;
	}
	else {
		gotoXY(x, y);
	}
	while (true) { // Note: chua xu li duoc truong hop nhan nhieu backspace lien tiep
		if (key == ENTER || key == ESC) {
			return;
		}
		else if (key == UP || key == DOWN || key == LEFT || key == RIGHT) {}
		else if (key == BACKSPACE)
		{
			if (text.empty()) {
				key = _getch();
			}
			else {
				text.pop_back();
				gotoXY(x + text.length(), y);
				cout << char(32);
				gotoXY(x + text.length(), y);
			}
		}
		else if (key >= 1 && key <= 255 && isprint(key) != 0) {
			text.push_back(char(toupper(key)));
			cout << char(toupper(key));
		}
		key = _getch();

	}
}

string trim(string s) {
	if (s.empty()) return s;
	//xu ly khoang trang dau
	while (s[0] == ' ')
		s.erase(s.begin() + 0);

	//xu ly khoang trang cuoi
	while (s[s.length() - 1] == ' ')
		s.erase(s.length() - 1);

	return s;
}

string generateSpace(int length) {
	string s;
	while (s.length() < length - 1) {
		s += " ";
	}
	return s;
}
void box(int x, int y, int width, int height, int backgroundColor, int textColor, string text, int textAlignment) {
	setTextColor(backgroundColor);
	for (int j = y; j <= y + height - 1; j++) {
		for (int i = x; i <= x + width - 1; i++) {
			gotoXY(i, j);
			cout << char(219);
		}
	}

	setBackgroundColor(backgroundColor);
	setTextColor(textColor);

	if (textAlignment == TEXT_LEFT) {
		gotoXY(x + 2, y + height / 2);
		cout << text;
	}

	else if (textAlignment == TEXT_CENTER) {
		gotoXY(x + getCenterX(width, text.length()), y + height / 2);
		cout << text;
	}

	else {
		gotoXY(x + width - text.length() - 1, y + height / 2);
		cout << text;
	}
}
void n_box(int x, int y, int width, int height, int backgroundColor, int textColor, string* text, int number) {
	for (int i = 0; i < number; i++) {
		box(x, y + (i * 4), width, height, backgroundColor, textColor, text[i], TEXT_LEFT);
	}
}

void menu(boolean isInit) {
	ShowCur(0);
	int x = 2, y = 1, width = 50, height = 3;
	int textColor = 0;
	int backgroundColor = 14;
	int backgroundColorChoose = 15;

	if (isInit) {
		readFileSinhVien(listSinhVien, listLop);

		khoiTaoCay(treeMonHoc);
		readFileMonHoc(treeMonHoc);

		maxMALOPTC = readFileLopTinChi(listLopTinChi);
		//duyetCayNLR(treeMH)

	}


	const int number = 9;
	string options[number] = {
		"1. QUAN LY LOP TIN CHI",
		"2. QUAN LY SINH VIEN",
		"3. QUAN LY MON HOC",
		"4. SINH VIEN DANG KY/ HUY DANG KY LOP TIN CHI",
		"5. HUY LOP TIN CHI",
		"6. IN/ NHAP BANG DIEM",
		"7. IN DIEM TB KET THUC KHOA CUA SV THUOC LOP",
		"8. BANG DIEM TONG KET CUA CAC SV THUOC LOP",
		"9. THOAT"
	};

	n_box(x, y, width, height, backgroundColor, textColor, options, number);

	int xPointer = x;
	int yPointer = y;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isClicked = true;
	bool flag = true;

	while (flag)
	{
		if (isClicked)
		{
			box(xPointerOld, yPointerOld, width, height, backgroundColor, textColor, options[iOld], TEXT_LEFT);
			box(xPointer, yPointer, width, height, backgroundColorChoose, textColor, options[i], TEXT_LEFT);
			xPointerOld = xPointer;
			yPointerOld = yPointer;
			isClicked = false;
		}

		char c = _getch();
		if (c == ENTER) {
			if (i == 0) { //QUAN LY LOP TIN CHI
				setBackgroundColor(COLOR_BLACK);

				IndexListLopTinChi sortedListLopTinChi;
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				clearConsole();
				listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);
			}
			else if (i == 1) {//QUAN LY SINH VIEN THEO LOP
				setBackgroundColor(COLOR_BLACK);

				/*IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(listSinhVien, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				clearConsole();
				listSinhVienTable(listSinhVien, sortedListSinhVien, false);*/

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "QLSV", false);

			}

			else if (i == 2) { //QUAN LY MON HOC
				setBackgroundColor(COLOR_BLACK);

				setBackgroundColor(COLOR_BLACK);
				clearConsole();

				IndexListMonHoc sortedListMonHoc;
				treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
				sapXepListMonHocTheoTen(sortedListMonHoc);

				clearConsole();
				treeMonHocTable(treeMonHoc, sortedListMonHoc, false);
			}

			else if (i == 3) {// sinh vien dang ky, huy dang ky ltc

				char MASV[15];
				strcpy_s(MASV, popUpNhapMaSinhVien());
				if (convertToString(MASV) == "") {
					clearConsole();
					menu(false);
				}

				int index = timIndexSinhVienTheoMASV(listSinhVien, MASV);
				SinhVien sinhvien = *listSinhVien.sinhvien[index];

				popUpNhapNienKhoaHocKy(sinhvien);

				//trước đây hiển thị các ltc còn mở trong năm hiện tại, h thì chuyển thành nhập niên khóa học kỳ trước
				//ListLopTinChi listLopTinChiTheoNienKhoa;
				//timLopTinChiConMoTheoNienKhoa(listLopTinChi, listLopTinChiTheoNienKhoa, getCurrentYear());

				//IndexListLopTinChi sortedListLopTinChiTheoNienKhoa;
				//listLopTinChiToIndexListLopTinChi(listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa);
				////sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChiTheoNienKhoa);

				//clearConsole();
				//listLopTinChiSinhVienDangKyTable(listLopTinChi, listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa, sinhvien, false);

			
			}

			else if (i == 4) { //HUY LOP TIN CHI
				setBackgroundColor(COLOR_BLACK);
				int k = notificationPopUp("CHUC NANG NAY CHUA DUOC PHAT TRIEN");
				if (k == YES) {

				}
				clearConsole();
				menu(false);
			}

			else if (i == 5) { //IN/ NHAP BANG DIEM
				setBackgroundColor(COLOR_BLACK);
				IndexListLopTinChi sortedListLopTinChi;
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				clearConsole();
				listLopTinChi_ChonLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);
			}
			else if (i == 6) { //IN BANG DIEM TB KET THUC KHOA HOC CUA SV THUOC LOP
				setBackgroundColor(COLOR_BLACK);

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "BANGDIEMTB", false);
			}
			else if (i == 7) { //IN BANG DIEM TONG KET CAC MON CUA SINH VIEN THUOC LOP
				setBackgroundColor(COLOR_BLACK);

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "BANGDIEMTKCACMON", false);
			}

			else if (i == 8) { //THOAT CHUONG TRINH
				clearConsole();
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);

				//lưu file và giải phóng các vùng nhớ tại đây
				writeFileSinhVien(listSinhVien);
				writeFileLopTinChi(listLopTinChi);
				writeFileMonHoc(treeMonHoc);

				clearListLopTinChi(listLopTinChi);
				clearListLop(listLop);
				clearListSinhVien(listSinhVien);
				clearTreeMonHoc(treeMonHoc);

				exit(0);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == UP && i != 0)
			{
				yPointer -= 4;
				if (i > 0)
				{
					iOld = i;
					i--;
				}
				isClicked = true;
			}
			else if (c == DOWN && i != (number - 1))
			{
				yPointer += 4;
				if (i < number)
				{
					iOld = i;
					i++;

				}
				isClicked = true;
			}
		}

	}
}

//==================== VE HOP ====================

void box2(int x, int y, int width, int height, int backgroundColor, int textColor, string text) {
	setTextColor(backgroundColor);
	for (int ix = x; ix < x + width; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + height);
		cout << char(196);
	}

	for (int iy = y; iy < y + height; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width, iy);
		cout << char(179);
	}

	gotoXY(x, y); cout << char(218);
	gotoXY(x + width, y); cout << char(191);
	gotoXY(x, y + height); cout << char(192);
	gotoXY(x + width, y + height); cout << char(217);

	/*setTextColor(textColor);
	gotoXY(x + getCenterX(width, text.length()), y + height / 2);
	setBackgroundColor(backgroundColor);
	cout << text;*/
}

void box3(int x, int y, int width, int height, int backgroundColor, int textColor, string text) {
	setTextColor(backgroundColor);
	/*if (height <= 1 || width <= 1) return;*/

	for (int iy = y; iy <= y + height; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width, iy);
		cout << char(179);
	}

	setTextColor(textColor);
	gotoXY(x + 1, y + 1);
	cout << text;
}

int warningPopUp(string message) {
	ShowCur(0);
	int height = 10;
	int width = 50; //50
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 9;
	int yInput = y + 6;
	int boxWidth = 12;
	int boxHeight = 3;
	int boxDistance = 10;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THONG BAO", TEXT_CENTER);
	box(x, y + 3, width, 1, COLOR_WHITE, COLOR_BLACK, message, TEXT_CENTER);

	const int number = 2;
	string data[number] = { "CO" , "KHONG" };
	box(xInput, yInput, boxWidth, boxHeight, COLOR_RED, COLOR_BRIGHT_WHITE, data[0], TEXT_CENTER);
	box(xInput + boxDistance * 2, yInput, boxWidth, boxHeight, COLOR_RED, COLOR_BRIGHT_WHITE, data[1], TEXT_CENTER);

	int xPointer = xInput;
	int yPointer = yInput;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	int iOld = i;
	bool isClicked = true;


	while (true)
	{
		if (isClicked)
		{
			box(xPointerOld, yPointerOld, boxWidth, boxHeight, COLOR_RED, COLOR_BRIGHT_WHITE, data[iOld], TEXT_CENTER);
			box(xPointer, yPointer, boxWidth, boxHeight, COLOR_LIGHT_YELLOW, COLOR_BLACK, data[i], TEXT_CENTER);
			xPointerOld = xPointer;
			iOld = i;
			isClicked = false;
		}

		char key = _getch();
		switch (key)
		{
		case -32:
			isClicked = true;
			key = _getch();
			if (key == LEFT && i != 0)
			{
				xPointer -= boxDistance * 2;
				if (i > 0) i--;
			}
			else if (key == RIGHT && i < (number - 1))
			{
				xPointer += boxDistance * 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;

		case ESC:
			return NO;
			break;

		case ENTER:
		{
			if (i == 0) return YES;
			if (i == 1) return NO;
			break;
		}
		default:
			break;
		}
	}
}

int notificationPopUp(string message) {
	ShowCur(0);
	int height = 10;
	int width = 50; //50
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 19;
	int yInput = y + 6;
	int boxWidth = 12;
	int boxHeight = 3;
	int boxDistance = 10;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THONG BAO", TEXT_CENTER);
	box(x, y + 3, width, 1, COLOR_WHITE, COLOR_BLACK, message, TEXT_CENTER);

	const int number = 1;
	string data[number] = { "OK" };
	box(xInput, yInput, boxWidth, boxHeight, COLOR_RED, COLOR_BRIGHT_WHITE, data[0], TEXT_CENTER);

	int xPointer = xInput;
	int yPointer = yInput;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	int iOld = i;
	bool isClicked = true;


	while (true)
	{
		if (isClicked)
		{
			//box(xPointerOld, yPointerOld, boxWidth, boxHeight, COLOR_RED, COLOR_BRIGHT_WHITE, data[iOld]);
			box(xPointer, yPointer, boxWidth, boxHeight, COLOR_LIGHT_YELLOW, COLOR_BLACK, data[i], TEXT_CENTER);
			//xPointerOld = xPointer;
			//iOld = i;
			isClicked = false;
		}

		char key = _getch();
		switch (key)
		{
		case -32:
			break;

		case ESC:
			return YES;
			break;

		case ENTER:
			return YES;
			break;

		default:
			break;
		}
	}
}

void titleBox(int y, int height, string text) {
	int x = getCenterX(WIDTH_MAIN_FRAME, text.length() + 4);
	int width = text.length() + 4;
	box(x, y, width, height, COLOR_LIGHT_YELLOW, COLOR_BLACK, text, TEXT_CENTER);
}

void titleBoxLeft(int y, int height, string text) {
	int x = 10;
	int width = text.length() + 10;
	box(x, y, width, height, COLOR_LIGHT_YELLOW, COLOR_BLACK, text, TEXT_CENTER);
}

int hotKeyBox(int x, int y, string hotkey, string text) {
	gotoXY(x, y);
	setBackgroundColor(COLOR_RED);
	setTextColor(COLOR_LIGHT_YELLOW);
	cout << " " + hotkey + " ";
	gotoXY(x + hotkey.length() + 2 + 1, y);
	setBackgroundColor(COLOR_BLACK);
	setTextColor(COLOR_LIGHT_YELLOW);
	cout << text;

	return text.length() + 2 + 1 + hotkey.length();
}

void box4(int x, int y, int width, int height, int backgroundColor, int textColor, string text) {
	setTextColor(backgroundColor);
	if (height <= 1 || width <= 1) return;
	for (int ix = x; ix <= x + width; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + height);
		cout << char(196);
	}

	gotoXY(x, y);
	cout << char(193);
	gotoXY(x + width, y);
	cout << char(193);
	gotoXY(x, y + height);
	cout << char(196);
	gotoXY(x + width, y + height);
	cout << char(196);

}

void box5(int x, int y, int width, int height, int backgroundColor, int textColor, string text) {
	setTextColor(backgroundColor);
	if (height <= 1 || width <= 1) return;
	//VE CANH TREN DUOI CUA HINH HOP
	for (int ix = x; ix <= x + width; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + height);
		cout << char(196);
	}

	//VE 2 CANH BEN CUA HINH HOP
	for (int iy = y; iy <= y + height; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width, iy);
		cout << char(179);
	}
	gotoXY(x, y);
	cout << char(194);
	gotoXY(x + width, y);
	cout << char(194);
	gotoXY(x, y + height);
	cout << char(197);
	gotoXY(x + width, y + height);
	cout << char(197);

	setTextColor(textColor);
	gotoXY(x + 1, y + 1);

	int centerX = getCenterX(width, text.length());
	cout << generateSpace(centerX) << text;

}
void tableFooter(int x, int y, int* width, int column, int backgroundColor, int textColor, string text) {
	int height = 2;
	int ix = x;

	for (int i = 0; i <= column; i++) {
		if (i == column) {
			gotoXY(x, y);
			cout << char(195);
			gotoXY(x, y + 1);
			cout << char(179);
			gotoXY(x, y + 2);
			cout << char(192);

			gotoXY(ix, y);
			cout << char(180);
			gotoXY(ix, y + 1);
			cout << char(179);
			gotoXY(ix, y + 2);
			cout << char(217);
		}
		else {
			box4(ix, y, width[i], height, backgroundColor, textColor, "");
			ix += width[i];
		}

	}
}

void tableHeader(int x, int y, int* width, int column, int backgroundColor, int textColor, string* text) {
	int height = 2;
	int ix = x;
	for (int i = 0; i <= column; i++) {
		if (i == column) {
			setTextColor(backgroundColor);
			gotoXY(x, y);
			cout << char(218);
			gotoXY(x, y + 1);
			cout << char(179);
			gotoXY(x, y + 2);
			cout << char(195);

			setTextColor(backgroundColor);
			gotoXY(ix, y);
			cout << char(191);
			gotoXY(ix, y + 1);
			cout << char(179);
			gotoXY(ix, y + 2);
			cout << char(180);
		}
		else {
			box5(ix, y, width[i], height, backgroundColor, COLOR_LIGHT_YELLOW, text[i]);
			ix += width[i];
		}
	}
}
void tableHeaderForMAMH(int x, int y, int width, int column, int backgroundColor, int textColor, IndexListMonHoc indexListMonHoc) {
	int height = 2;
	int ix = x;
	for (int i = 0; i <= column; i++) {
		if (i == column) {
			setTextColor(backgroundColor);
			gotoXY(x, y);
			cout << char(218);
			gotoXY(x, y + 1);
			cout << char(179);
			gotoXY(x, y + 2);
			cout << char(195);

			setTextColor(backgroundColor);
			gotoXY(ix, y);
			cout << char(191);
			gotoXY(ix, y + 1);
			cout << char(179);
			gotoXY(ix, y + 2);
			cout << char(180);
		}
		else {
			box5(ix, y, width, height, backgroundColor, COLOR_LIGHT_YELLOW, indexListMonHoc.nodes[i].MAMH);
			ix += width;
		}
	}
}

void tableFooterForMAMH(int x, int y, int width, int column, int backgroundColor, int textColor, string text) {
	int height = 2;
	int ix = x;

	for (int i = 0; i <= column; i++) {
		if (i == column) {
			gotoXY(x, y);
			cout << char(195);
			gotoXY(x, y + 1);
			cout << char(179);
			gotoXY(x, y + 2);
			cout << char(192);

			gotoXY(ix, y);
			cout << char(180);
			gotoXY(ix, y + 1);
			cout << char(179);
			gotoXY(ix, y + 2);
			cout << char(217);
		}
		else {
			box4(ix, y, width, height, backgroundColor, textColor, "");
			ix += width;
		}

	}
}


void coutBox(int x, int y, int width, int align, string text) {
	gotoXY(x, y);
	cout << fixed << setprecision(2);
	if (align == TEXT_RIGHT) {
		int num = width - 2;
		cout << std::right << setw(num);
		cout << text;
	}
	else {
		cout << " " << text;
	}

}


//=================== BANG SINH VIEN ===================
void listSinhVienTable(ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]) {
	ShowCur(0);
	/*titleBox(1, 3, "QUAN LY SINH VIEN LOP " + convertToString(MALOP));*/
	titleBoxLeft(1, 3, "QUAN LY SINH VIEN LOP " + convertToString(MALOP));
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 6;
	string title[column] = { "STT", "MASV", "HO", "TEN", "PHAI", "SDT"/*, "MALOP"*/ };
	int cellWidth[column] = { 10, 20, 30, 15, 15, 25/*, 20*/ };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "HIEU CHINH"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListSinhVienEmpty(sortedListSinhVien)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListSinhVien.number) break;
					else {
						index = sortedListSinhVien.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listSinhVienTheoLop.sinhvien[index]->MASV);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListSinhVien.nodes[k].HO);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListSinhVien.nodes[k].TEN);
						ix += cellWidth[3];

						string strPhai = "NAM";
						if (listSinhVienTheoLop.sinhvien[index]->PHAI != true) {
							strPhai = "NU";
						}
						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, strPhai);
						ix += cellWidth[4];

						coutBox(ix, iy, cellWidth[5], TEXT_LEFT, listSinhVienTheoLop.sinhvien[index]->SODT);
						ix += cellWidth[5];

						/*	coutBox(ix, iy, cellWidth[6], TEXT_LEFT, listSinhVienTheoLop.sinhvien[index]->MALOP);
							ix += cellWidth[6];*/
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 17, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 17, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListSinhVien.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListSinhVien.nodes[iOld + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListSinhVien.nodes[i + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListSinhVien.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListSinhVien.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//THEM SINH VIEN
			else if (key == INSERT_KEY)
			{
				if (isListSinhVienFull(listSinhVien)) { //DANH SACH SINH VIEN DA DAY
					string message = "DANH SACH SINH VIEN DA DAY";
					int k = notificationPopUp(message);
					if (k == YES) {}
				}
				else { //DANH SACH SINH VIEN CHUA DAY
					int k = popUpThemSinhVien(listSinhVien, MALOP);
					if (k == YES) {
						clearIndexListSinhVien(sortedListSinhVien);
						clearListSinhVien(listSinhVienTheoLop);
						locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
						listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
						sapXepListSinhVienTheoTen(sortedListSinhVien);

						/*	clearConsole();
							listSinhVienTable(listSinhVien, sortedListSinhVien, false, MALOP);*/
					}
				}

				clearConsole();
				listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
			}

			//XOA SINH VIEN
			else if (key == DELETE_KEY && !isSortedListSinhVienEmpty(sortedListSinhVien))
			{
				string message = "BAN MUON XOA SINH VIEN NAY?";
				bool isAccepted = warningPopUp(message);
				int index = sortedListSinhVien.nodes[i + currentIndex].index;
				if (isAccepted)
				{
					//------- sau này bắt trường hợp sinh viên đã đăng ký lớp tín chỉ
					if (sinhVienDaDangKyLopTinChi(listLopTinChi, listSinhVienTheoLop.sinhvien[index]->MASV) == 1) {
						string message = "SINH VIEN NAY DA DANG KY LTC, KHONG THE XOA";
						int t = notificationPopUp(message);
						if (t == YES) {};
					}
					else {//
						xoaSinhVienTheoMaSV(listSinhVien, listSinhVienTheoLop.sinhvien[index]->MASV);
						//writeEmployeeFile(employeeList);

						//delete[] sortedListSinhVien.nodes;
						clearIndexListSinhVien(sortedListSinhVien);
						clearListSinhVien(listSinhVienTheoLop);
						locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
						listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
						sapXepListSinhVienTheoTen(sortedListSinhVien);

					}
				}
				//writeEmployeeFile(employeeList);
				clearConsole();
				listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);
				locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);

				listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/
				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);
				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "QLSV", false);

				//menu(false);
			}
			break;
		}

		case ENTER: // SUA SINH VIEN TRONG DANH SACH SINH VIEN
		{
			if (!isSortedListSinhVienEmpty(sortedListSinhVien))
			{
				int index = sortedListSinhVien.nodes[i + currentIndex].index;
				int k = popUpSuaSinhVien(listSinhVien, listSinhVienTheoLop.sinhvien[index]->MASV);
				if (k == YES) { // DA HIEU CHINH SINH VIEN
					clearIndexListSinhVien(sortedListSinhVien);
					clearListSinhVien(listSinhVienTheoLop);
					locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
					listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
					sapXepListSinhVienTheoTen(sortedListSinhVien);

					clearConsole();
					listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, false, MALOP);
				}
				else {//NHAN ESC
					clearConsole();
					listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
				}
			}
			break;
		}

		case CTRL_F: // TIM KIEM SINH VIEN
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP TEN: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				//delete[] sortedListSinhVien.nodes;
				clearIndexListSinhVien(sortedListSinhVien);
				searchListSinhVienByTen(listSinhVienTheoLop, sortedListSinhVien, trim(name));
				//sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}

//=================== THEM SINH VIEN ===================
int popUpThemSinhVien(ListSinhVien& listSinhVien, char MALOP[15]) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;

	//char MASV[15]; /*= generateEmployeeId(employeeList);*/
	//char HO[30];
	//char TEN[10];
	//bool PHAI;
	//char SODT[15];

	string MASV_STR; 
	string HO_STR;
	string TEN_STR;
	string PHAI_STR;
	string SODT_STR;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THEM SINH VIEN VAO LOP " + convertToString(MALOP), TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "", TEXT_CENTER);
	gotoXY(x + 1, y + height);
	cout << "ESC : QUAY LAI";

	const int number = 5;
	// đã thêm theo lớp đang chọn
	string title[number] = { "MASV", "HO", "TEN", "PHAI", "SODT" };
	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];
			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char key = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * 6, 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, key);
			isClicked = false;
		}
		if (i == 5) key = _getch();// = số field input
		switch (key)
		{
		case -32: //DIEU HUONG LEN/XUONG
		{
			isClicked = true;
			key = _getch();
			if (key == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * 6 /*6 là số input field + 1*/, 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (key == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;
		}


		case ENTER: //NHAN OK DE THEM SINH VIEN VAO DANH SACH SINH VIEN
		{
			if (i == 5) {// = số field input
				box(xPointer, y + height - 6, widthInput, 5/*số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//KIEM TRA THONG TIN NHAP VAO
				string e1 = checkMaSinhVien(listSinhVien, trim(MASV_STR));
				string e2 = checkHO(trim(HO_STR));
				string e3 = checkTEN(trim(TEN_STR));
				string e4 = checkGioiTinh(trim(PHAI_STR));
				string e5 = checkSODT(trim(SODT_STR));

				int iy = y + height - 6;
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
				if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }
				if (!e4.empty()) { gotoXY(xPointer + 1, iy); cout << e4; iy += 1; }
				if (!e5.empty()) { gotoXY(xPointer + 1, iy); cout << e5; iy += 1; }

				if (e1.empty() && e2.empty() && e3.empty() && e4.empty() && e5.empty()) {

					//THEM SINH VIEN MOI VAO DANH SACH SINH VIEN
					SinhVien sinhvien;
					strcpy_s(sinhvien.MALOP, MALOP);
					strcpy_s(sinhvien.MASV, MASV_STR.c_str());
					strcpy_s(sinhvien.HO, HO_STR.c_str());
					strcpy_s(sinhvien.TEN, TEN_STR.c_str());
					strcpy_s(sinhvien.SODT, SODT_STR.c_str());

					if (PHAI_STR.compare("NAM") == 0) {
						sinhvien.PHAI = true;
					}
					else if (PHAI_STR.compare("NU") == 0) {
						sinhvien.PHAI = false;
					}

					insertSinhVienOrder(listSinhVien, sinhvien);

					//	//GHI LAI FILE
					//	//writeEmployeeFile(employeeList);
					return YES;
				}
			}
			else {
				continue;
			}
			break;
		}

		case ESC: //THOAT POP UP
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		default: //NHAP CAC FIELD TRONG POP UP
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, MASV_STR, key);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, HO_STR, key);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, TEN_STR, key);
			else if (i == 3) upperCaseWhileTyping(xPointer, yPointer, PHAI_STR, key);
			else if (i == 4) upperCaseWhileTyping(xPointer, yPointer, SODT_STR, key);

			break;
		}
		}
	}
}


//=================== SUA SINH VIEN =================== 
// MAU DE LAM POP UP
int popUpSuaSinhVien(ListSinhVien& listSinhVien, char MASV[15]) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;
	const int number = 4; // số input field

	int indexSinhVien = timIndexSinhVienTheoMASV(listSinhVien, MASV);

	string MASV_STR = listSinhVien.sinhvien[indexSinhVien]->MASV;
	string HO_STR = listSinhVien.sinhvien[indexSinhVien]->HO;
	string TEN_STR = listSinhVien.sinhvien[indexSinhVien]->TEN;
	string PHAI_STR = listSinhVien.sinhvien[indexSinhVien]->PHAI == false ? "NU" : "NAM";
	string SODT_STR = listSinhVien.sinhvien[indexSinhVien]->SODT;
	string MALOP_STR = listSinhVien.sinhvien[indexSinhVien]->MALOP;


	string title[number] = { /*"MASV",*/ "HO", "TEN", "PHAI", "SODT" /*MALOP*/ }; // không cho sửa MASV, MALOP
	string data[number] = { HO_STR, TEN_STR, PHAI_STR, SODT_STR };

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "SUA SINH VIEN " + MASV_STR, TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, " ESC : QUAY LAI", TEXT_LEFT);

	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];

			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, data[i], TEXT_LEFT);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char c = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, c);
			isClicked = false;
		}
		if (i == number) c = _getch();

		switch (c)
		{
		case -32:
			isClicked = true;
			c = _getch();
			if (c == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (c == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < 5) i++;
			}
			c = char();
			break;

		case ESC:
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		case ENTER:
		{
			if (i == number) {
				box(xPointer, y + height - 6, widthInput, 4/*số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//string e1 = checkMaSinhVien(listSinhVien, trim(MASV_STR));
				string e1 = checkHO(trim(HO_STR));
				string e2 = checkTEN(trim(TEN_STR));
				string e3 = checkGioiTinh(trim(PHAI_STR));
				string e4 = checkSODT(trim(SODT_STR));

				int iy = y + height - 6;
				setTextColor(COLOR_BRIGHT_WHITE);


				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
				if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }
				if (!e4.empty()) { gotoXY(xPointer + 1, iy); cout << e4; iy += 1; }

				if (e1.empty() && e2.empty() && e3.empty() && e4.empty()) {
					//if (employeeId == oldEmployeeId) { //KHONG THAY DOI MA NHAN VIEN

					strcpy_s(listSinhVien.sinhvien[indexSinhVien]->HO, trim(HO_STR).c_str());
					strcpy_s(listSinhVien.sinhvien[indexSinhVien]->TEN, trim(TEN_STR).c_str());
					strcpy_s(listSinhVien.sinhvien[indexSinhVien]->SODT, trim(SODT_STR).c_str());

					if (trim(PHAI_STR).compare("NAM") == 0) {
						listSinhVien.sinhvien[indexSinhVien]->PHAI = true;
					}
					else if (trim(PHAI_STR).compare("NU") == 0) {
						listSinhVien.sinhvien[indexSinhVien]->PHAI = false;
					}

					/*	for (int l = 0; l < sortedListSinhVien.number; l++) {
							if (sortedListSinhVien.nodes[l].index == indexSinhVien) {

								strcpy_s(sortedListSinhVien.nodes[indexSinhVien].HO, trim(HO_STR).c_str());
								strcpy_s(sortedListSinhVien.nodes[indexSinhVien].TEN, trim(TEN_STR).c_str());

								break;
							}
						}*/

					return YES;
				}
			}
			break;
		}

		default:
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, HO_STR, c);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, TEN_STR, c);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, PHAI_STR, c);
			else if (i == 3) upperCaseWhileTyping(xPointer, yPointer, SODT_STR, c);
			break;
		}
		}
	}
}
//=================== BANG DIEM TB CUOI KHOA CUA SV THUOC LOP===================
void listBangDiemTBSinhVienTable(ListLopTinChi listLopTinChi, TREE treeMonHoc, ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]) {
	ShowCur(0);
	//titleBox(1, 3, "BANG DIEM TB KHOA HOC CUA SV LOP " + convertToString(MALOP));
	titleBoxLeft(1, 3, "BANG DIEM TB KHOA HOC CUA SV LOP " + convertToString(MALOP));
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 5;
	string title[column] = { "STT", "MASV", "HO", "TEN", "DIEM" };
	int cellWidth[column] = { 10, 20, 25, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "HIEU CHINH"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListSinhVienEmpty(sortedListSinhVien)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListSinhVien.number) break;
					else {
						index = sortedListSinhVien.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listSinhVienTheoLop.sinhvien[index]->MASV);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListSinhVien.nodes[k].HO);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListSinhVien.nodes[k].TEN);
						ix += cellWidth[3];

						float diemTB = tinhDiemTrungBinhKhoaHocCuaSinhVien(listLopTinChi, treeMonHoc, listSinhVienTheoLop.sinhvien[index]->MASV);
			
						//X tương đương với sinh viên k đăng ký môn nào
						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, diemTB == -99 ? "X" : floatToStringMark(diemTB));
						ix += cellWidth[4];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 48, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 48, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListSinhVien.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListSinhVien.nodes[iOld + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListSinhVien.nodes[i + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListSinhVien.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListSinhVien.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
			
			}

			//
			else if (key == DELETE_KEY && !isSortedListSinhVienEmpty(sortedListSinhVien))
			{
	
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);
				locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);

				listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/
				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);
				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "BANGDIEMTB", false);

				//menu(false);
			}
			break;
		}

		case ENTER: //
		{
			
			break;
		}

		case CTRL_F: // TIM KIEM SINH VIEN
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP TEN: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				//delete[] sortedListSinhVien.nodes;
				clearIndexListSinhVien(sortedListSinhVien);
				searchListSinhVienByTen(listSinhVienTheoLop, sortedListSinhVien, trim(name));
				//sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}
//=================== BANG DIEM TONG KET CUA SV THUOC LOP===================
void listBangDiemTongKetSinhVienTable(ListLopTinChi listLopTinChi, IndexListMonHoc& indexListMonHocSVLopDADK, ListSinhVien& listSinhVien, ListSinhVien& listSinhVienTheoLop, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]) {
	ShowCur(0);
	//titleBox(1, 3, "BANG DIEM TONG KET SV LOP " + convertToString(MALOP));
	titleBoxLeft(1, 3, "BANG DIEM TONG KET SV LOP " + convertToString(MALOP));
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 4;
	string title[column] = { "STT", "MASV", "HO", "TEN"};
	int cellWidth[column] = { 10, 15, 25, 15};

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}

	
	//kẻ cho cột các môn
	iy = iy - 24;
	for (int k = currentIndex; k < row; k++) {
		int ix = x + 65;// x+65 là x của cột tĩnh cuối
		for (int j = 0; j < indexListMonHocSVLopDADK.number; j++) {
			box3(ix, iy, 10, height, backgroundColor, textColor, "");
			ix += 10;
		}
		iy = iy + 2;
	}

	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");

	tableHeaderForMAMH(x + 65 /* tổng width những cột tĩnh*/, y, 10, indexListMonHocSVLopDADK.number, backgroundColor, textColor, indexListMonHocSVLopDADK);
	tableFooterForMAMH(x + 65/* tổng width những cột tĩnh*/, iy + 1, 10, indexListMonHocSVLopDADK.number, backgroundColor, textColor, "");

	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "HIEU CHINH"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			// clear cho các cột động MAMH
			iy = iy - 24; // -24 để reset y lên đầu
			for (int k = 0; k < row; k++) {
				int ix = xPointer + 65; // + 65 là x cuối của những cột tĩnh
				for (int j = 0; j < indexListMonHocSVLopDADK.number; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(10);
					ix += 10;
				}
				iy = iy + 2;
			}

			isInit = false;
		}

		if (!isSortedListSinhVienEmpty(sortedListSinhVien)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListSinhVien.number) break;
					else {
						index = sortedListSinhVien.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listSinhVienTheoLop.sinhvien[index]->MASV);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListSinhVien.nodes[k].HO);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListSinhVien.nodes[k].TEN);
						ix += cellWidth[3];


						for (int l = 0; l < indexListMonHocSVLopDADK.number; l++) {
							float diemMaxMotMonCuaSV = layDiemCaoNhatMotMonCuaSinhVienTheoMonHoc(listLopTinChi, indexListMonHocSVLopDADK.nodes[l].MAMH, listSinhVienTheoLop.sinhvien[index]->MASV);
							
							//X tương đương sinh viên k có đăng ký lớp tc nào có môn này
							coutBox(ix, iy, 10, TEXT_LEFT, diemMaxMotMonCuaSV == -99 ? "X" : floatToStringMark(diemMaxMotMonCuaSV));
							ix += 10;
						}

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 55, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 55, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListSinhVien.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListSinhVien.nodes[iOld + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListSinhVien.nodes[i + currentIndex].index;
				cout << listSinhVienTheoLop.sinhvien[index]->MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListSinhVien.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListSinhVien.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
				//if (isListSinhVienFull(listSinhVien)) { //DANH SACH SINH VIEN DA DAY
				//	string message = "DANH SACH SINH VIEN DA DAY";
				//	int k = notificationPopUp(message);
				//	if (k == YES) {}
				//}
				//else { //DANH SACH SINH VIEN CHUA DAY
				//	int k = popUpThemSinhVien(listSinhVien, MALOP);
				//	if (k == YES) {
				//		clearIndexListSinhVien(sortedListSinhVien);
				//		clearListSinhVien(listSinhVienTheoLop);
				//		locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
				//		listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				//		sapXepListSinhVienTheoTen(sortedListSinhVien);

				//		/*	clearConsole();
				//			listSinhVienTable(listSinhVien, sortedListSinhVien, false, MALOP);*/
				//	}
				//}

				//clearConsole();
				//listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
			}

			//
			else if (key == DELETE_KEY && !isSortedListSinhVienEmpty(sortedListSinhVien))
			{
				//string message = "BAN MUON XOA SINH VIEN NAY?";
				//bool isAccepted = warningPopUp(message);
				//int index = sortedListSinhVien.nodes[i + currentIndex].index;
				//if (isAccepted)
				//{
				//	//------- sau này bắt trường hợp sinh viên đã đăng ký lớp tín chỉ
				//	if (sinhVienDaDangKyLopTinChi(listLopTinChi, listSinhVienTheoLop.sinhvien[index]->MASV) == 1) {
				//		string message = "SINH VIEN NAY DA DANG KY LTC, KHONG THE XOA";
				//		int t = notificationPopUp(message);
				//		if (t == YES) {};
				//	}
				//	else {//
				//		xoaSinhVienTheoMaSV(listSinhVien, listSinhVienTheoLop.sinhvien[index]->MASV);
				//		//writeEmployeeFile(employeeList);

				//		//delete[] sortedListSinhVien.nodes;
				//		clearIndexListSinhVien(sortedListSinhVien);
				//		clearListSinhVien(listSinhVienTheoLop);
				//		locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
				//		listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				//		sapXepListSinhVienTheoTen(sortedListSinhVien);

				//	}
				//}
				////writeEmployeeFile(employeeList);
				//clearConsole();
				//listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);
				locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);

				listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/
				//delete[] sortedListSinhVien.nodes;

				clearIndexListSinhVien(sortedListSinhVien);
				clearListSinhVien(listSinhVienTheoLop);
				clearIndexListMonHoc(indexListMonHocSVLopDADK);

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLop_ChonLopTable(listLop, indexListLop, "BANGDIEMTKCACMON", false);

				//menu(false);
			}
			break;
		}

		case ENTER: // 
		{
			//if (!isSortedListSinhVienEmpty(sortedListSinhVien))
			//{
			//	int index = sortedListSinhVien.nodes[i + currentIndex].index;
			//	int k = popUpSuaSinhVien(listSinhVien, listSinhVienTheoLop.sinhvien[index]->MASV);
			//	if (k == YES) { // DA HIEU CHINH SINH VIEN
			//		clearIndexListSinhVien(sortedListSinhVien);
			//		clearListSinhVien(listSinhVienTheoLop);
			//		locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MALOP);
			//		listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
			//		sapXepListSinhVienTheoTen(sortedListSinhVien);

			//		clearConsole();
			//		listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, false, MALOP);
			//	}
			//	else {//NHAN ESC
			//		clearConsole();
			//		listSinhVienTable(listSinhVien, listSinhVienTheoLop, sortedListSinhVien, isSearch, MALOP);
			//	}
			//}
			break;
		}

		case CTRL_F: // TIM KIEM SINH VIEN
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP TEN: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				//delete[] sortedListSinhVien.nodes;
				clearIndexListSinhVien(sortedListSinhVien);
				searchListSinhVienByTen(listSinhVienTheoLop, sortedListSinhVien, trim(name));
				//sapXepListSinhVienTheoTen(sortedListSinhVien);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}
//=================== BANG CHON LOP DE XEM SINH VIEN ===================
void listLop_ChonLopTable(ListLop& listLop, IndexListLop& indexListLop, string viewMode, bool isSearch) {
	ShowCur(0);
	//titleBox(1, 3, "CHON LOP DE XEM");
	titleBoxLeft(1, 3, "CHON LOP DE XEM");
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 2;
	string title[column] = { "STT", "MALOP" };
	int cellWidth[column] = { 10, 62 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "CHON"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isIndexListLopEmpty(indexListLop)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= indexListLop.number) break;
					else {
						index = indexListLop.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listLop.lop[index]->MALOP);
						ix += cellWidth[1];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 59, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 59, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << indexListLop.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = indexListLop.nodes[iOld + currentIndex].index;
				cout << listLop.lop[index]->MALOP;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = indexListLop.nodes[i + currentIndex].index;
				cout << listLop.lop[index]->MALOP;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA LOP
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < indexListLop.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < indexListLop.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
				break;
			}

			//
			else if (key == DELETE_KEY /* && !isSortedListSinhVienEmpty(indexListLop)*/)
			{
				break;
			}
			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] indexListLop.nodes;
				clearIndexListLop(indexListLop);
				listLopToIndexListLop(listLop, indexListLop);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				
				clearIndexListLop(indexListLop);
				clearConsole();
				menu(false);
			}
			break;
		}

		case ENTER: // CHON LOP NAY DE XEM
		{
			
			if (!isIndexListLopEmpty(indexListLop) && viewMode.compare("QLSV") == 0) { // trường hợp xem danh sách quản lý sinh viên
				int index = indexListLop.nodes[i + currentIndex].index;
				char MA_LOP_SELECTED[15];
				strcpy_s(MA_LOP_SELECTED, listLop.lop[index]->MALOP);
				// khai báo new để k dính lỗi stack overflow (test case nhấn enter esc liên tục)
				ListSinhVien* listSinhVienTheoLop = new ListSinhVien;
				locSinhVienTheoLop(*listSinhVienTheoLop, listSinhVien, MA_LOP_SELECTED);
				clearIndexListLop(indexListLop);

				IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(*listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				clearConsole();
				listSinhVienTable(listSinhVien, *listSinhVienTheoLop, sortedListSinhVien, false, MA_LOP_SELECTED);
			}
			else if(!isIndexListLopEmpty(indexListLop) && viewMode.compare("BANGDIEMTB") == 0) {// trường hợp xem bảng điểm trung bình kết thúc khóa học
				int index = indexListLop.nodes[i + currentIndex].index;
				char MA_LOP_SELECTED[15];
				strcpy_s(MA_LOP_SELECTED, listLop.lop[index]->MALOP);

				ListSinhVien* listSinhVienTheoLop = new ListSinhVien;
				locSinhVienTheoLop(*listSinhVienTheoLop, listSinhVien, MA_LOP_SELECTED);
				clearIndexListLop(indexListLop);

				IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(*listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				clearConsole();
				listBangDiemTBSinhVienTable(listLopTinChi, treeMonHoc, listSinhVien, *listSinhVienTheoLop, sortedListSinhVien, false, MA_LOP_SELECTED);
			}
			else if (!isIndexListLopEmpty(indexListLop) && viewMode.compare("BANGDIEMTKCACMON") == 0) {// trường hợp xem bảng điểm tổng kết khóa học
				int index = indexListLop.nodes[i + currentIndex].index;
				char MA_LOP_SELECTED[15];
				strcpy_s(MA_LOP_SELECTED, listLop.lop[index]->MALOP);

				ListSinhVien* listSinhVienTheoLop = new ListSinhVien;
				locSinhVienTheoLop(*listSinhVienTheoLop, listSinhVien, MA_LOP_SELECTED);

				IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(*listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				IndexListMonHoc indexListMonHoc;
				layTatCaMonHocSinhVienTrongListThamGia(listLopTinChi, indexListMonHoc, *listSinhVienTheoLop);

				if (isSortedListMonHocEmpty(indexListMonHoc)) {
						string message = "SINH VIEN LOP NAY CHUA DANG KY MON NAO";
						int k = notificationPopUp(message);
						if (k == YES) {
						}

						clearConsole();
						listLop_ChonLopTable(listLop, indexListLop, "BANGDIEMTKCACMON", false);
				}
				else {
					clearIndexListLop(indexListLop);

					clearConsole();
					listBangDiemTongKetSinhVienTable(listLopTinChi, indexListMonHoc, listSinhVien, *listSinhVienTheoLop, sortedListSinhVien, false, MA_LOP_SELECTED);
				}
			}
			break;
		}

		case CTRL_F: // TIM KIEM LOP
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP MALOP: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string keyword = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, keyword, c);

			if (c == ENTER) {
				clearIndexListLop(indexListLop);
				searchListLopByMaLop(listLop, indexListLop, trim(keyword));

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}

// Tree MON HOC TABLE

//=================== BANG MON HOC ===================
void treeMonHocTable(TREE& treeMonHoc, IndexListMonHoc& sortedListMonHoc, bool isSearch) {
	ShowCur(0);
	/*titleBox(1, 3, "QUAN LY MON HOC");*/
	titleBoxLeft(1, 3, "QUAN LY MON HOC");
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 5;
	string title[column] = { "STT", "MAMH", "TENMH", "SO TCLT", "SO TCTH" };
	int cellWidth[column] = { 10, 15, 60, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "HIEU CHINH"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListMonHocEmpty(sortedListMonHoc)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;


				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListMonHoc.number) break;
					else {
						index = sortedListMonHoc.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, sortedListMonHoc.nodes[k].MAMH);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListMonHoc.nodes[k].TENMH);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, std::to_string(sortedListMonHoc.nodes[k].STCLT));
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, std::to_string(sortedListMonHoc.nodes[k].STCTH));
						ix += cellWidth[4];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 18, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 18, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListMonHoc.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				// chữ trắng nền đen (ui hiển thị như đang bỏ chọn dòng hiện tại)
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				//int index = sortedListMonHoc.nodes[iOld + currentIndex].index;
				int index = iOld + currentIndex;

				//cout << listSinhVien.sinhvien[index]->MASV;
				// đọc thẳng từ sortedListMonHoc luôn
				cout << sortedListMonHoc.nodes[index].MAMH;

				// chuyển đến dòng kế chữ vàng nền đỏ (ui hiển thị như đang chọn dòng đang đi tới (gotoXY))
				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = i + currentIndex;

				// đọc thẳng từ sortedListMonHoc luôn, vẽ nó lên console như đang chọn
				cout << sortedListMonHoc.nodes[index].MAMH;
				//cout << listSinhVien.sinhvien[index]->MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA MON HOC
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListMonHoc.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListMonHoc.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//THEM MON HOC
			else if (key == INSERT_KEY)
			{
				// lớp thì không tính trường hợp đầy
				// 
				//if (isListMonHocFull(treeMonHoc)) { //DANH SACH SINH VIEN DA DAY
				//	string message = "DANH SACH MON HOC DA DAY";
				//	int k = notificationPopUp(message);
				//	if (k == YES) {}
				//}
				//else { //DANH SACH CHUA DAY

				int k = popUpThemMonHoc(treeMonHoc);
				//thêm xong
				if (k == YES) {
					clearIndexListMonHoc(sortedListMonHoc);
					treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
					sapXepListMonHocTheoTen(sortedListMonHoc);

					/*clearConsole();
					treeMonHocTable(treeMonHoc, sortedListMonHoc, false);*/
				}
				//}

				clearConsole();
				treeMonHocTable(treeMonHoc, sortedListMonHoc, isSearch);
			}

			//XOA MON HOC
			else if (key == DELETE_KEY && !isSortedListMonHocEmpty(sortedListMonHoc))
			{
				string message = "BAN MUON XOA MON HOC NAY?";
				bool isAccepted = warningPopUp(message);

				if (isAccepted)
				{

					//------- sau này bắt trường hợp môn này đã dùng để tạo lớp tín chỉ
					if (monHocDaDuocDungDeDangKyLTC(listLopTinChi, sortedListMonHoc.nodes[i + currentIndex].MAMH) == 1) {
						string message = "MON HOC DA DUNG DE TAO LTC, KHONG THE XOA";
						int t = notificationPopUp(message);
						if (t == YES) {};
					}
					else {//
						char MAMH_CANXOA[15];
						strcpy_s(MAMH_CANXOA, sortedListMonHoc.nodes[i + currentIndex].MAMH);
						xoaMonHocTrongCayByMAMH(treeMonHoc, MAMH_CANXOA);

						clearIndexListMonHoc(sortedListMonHoc);
						treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
						sapXepListMonHocTheoTen(sortedListMonHoc);

						/*clearConsole();
						treeMonHocTable(treeMonHoc, sortedListMonHoc, false);*/

					}
				}

				clearConsole();
				treeMonHocTable(treeMonHoc, sortedListMonHoc, isSearch);
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] sortedListSinhVien.nodes;

				clearIndexListMonHoc(sortedListMonHoc);

				treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
				sapXepListMonHocTheoTen(sortedListMonHoc);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/

				clearIndexListMonHoc(sortedListMonHoc);
				clearConsole();
				menu(false);
			}
			break;
		}

		case ENTER: // SUA MON HOC  TRONG CAY MON HOC
		{
			if (!isSortedListMonHocEmpty(sortedListMonHoc))
			{
				char MAMH_CANSUA[15];
				strcpy_s(MAMH_CANSUA, sortedListMonHoc.nodes[i + currentIndex].MAMH);
				int k = popUpSuaMonHoc(treeMonHoc, MAMH_CANSUA, sortedListMonHoc);
				if (k == YES) { // DA HIEU CHINH MON HOC
					clearConsole();
					treeMonHocTable(treeMonHoc, sortedListMonHoc, false);
				}
				else {//NHAN ESC
					clearConsole();
					treeMonHocTable(treeMonHoc, sortedListMonHoc, isSearch);
				}
			}

			break;
		}

		case CTRL_F: // TIM KIEM MON HOC
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP TENMH: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				//delete[] sortedListSinhVien.nodes;
				//searchEmployeeListByName(employeeList, sortedListSinhVien, trim(name));
				clearIndexListMonHoc(sortedListMonHoc);
				searchTreeMonHocTheoTenMonHoc(treeMonHoc, sortedListMonHoc, name, true);
				//sapXepListMonHocTheoTen(sortedListMonHoc);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}

//=================== THEM MON HOC ===================
int popUpThemMonHoc(TREE& treeMonHoc) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;

	//char MASV[15]; /*= generateEmployeeId(employeeList);*/
	//char HO[30];
	//char TEN[10];
	//bool PHAI;
	//char SODT[15];

	string MAMH_STR; /*= generateEmployeeId(employeeList);*/
	string TENMH_STR;
	string SOTCLT_STR;
	string SOTCTH_STR;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THEM MON HOC", TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "", TEXT_CENTER);
	gotoXY(x + 1, y + height);
	cout << "ESC : QUAY LAI";

	// số input field
	const int number = 4;

	string title[number] = { "MAMH", "TENMH", "SOTCLT", "SOTCTH" };
	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];
			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char key = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, key);
			isClicked = false;
		}
		if (i == number) key = _getch();// = số field input
		switch (key)
		{
		case -32: //DIEU HUONG LEN/XUONG
		{
			isClicked = true;
			key = _getch();
			if (key == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1) /*6 là số input field + 1*/, 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (key == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;
		}


		case ENTER: //NHAN OK DE THEM MON HOC VAO TREE
		{
			if (i == number) {// = số field input
				box(xPointer, y + height - (number + 1), widthInput, 4 /*số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//KIEM TRA THONG TIN NHAP VAO
				string e1 = checkMaMonHoc(treeMonHoc, trim(MAMH_STR));
				string e2 = checkTENMH(trim(TENMH_STR));
				string e3 = checkSOTCLT_TH(trim(SOTCLT_STR), "SO TCLT");
				string e4 = checkSOTCLT_TH(trim(SOTCTH_STR), "SO TCTH");

				int iy = y + height - 6;
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
				if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }
				if (!e4.empty()) { gotoXY(xPointer + 1, iy); cout << e4; iy += 1; }

				// nếu k có lỗi nào
				if (e1.empty() && e2.empty() && e3.empty() && e4.empty()) {

					//THEM MON HOC VAO CAY MON HOC
					MonHoc monhoc;
					strcpy_s(monhoc.MAMH, MAMH_STR.c_str());
					strcpy_s(monhoc.TENMH, TENMH_STR.c_str());
					monhoc.STCLT = stoi(trim(SOTCLT_STR));
					monhoc.STCTH = stoi(trim(SOTCTH_STR));

					themMonHocVaoCay(treeMonHoc, monhoc);

					//thêm xong tăng mã lên cho lần thêm tiếp theo
					maxMALOPTC = maxMALOPTC + 1;

					//	//GHI LAI FILE
					//	//writeEmployeeFile(employeeList);
					return YES;
				}
			}
			else {
				continue;
			}
			break;
		}

		case ESC: //THOAT POP UP
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		default: //NHAP CAC FIELD TRONG POP UP
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, MAMH_STR, key);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, TENMH_STR, key);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, SOTCLT_STR, key);
			else if (i == 3) upperCaseWhileTyping(xPointer, yPointer, SOTCTH_STR, key);

			break;
		}
		}
	}
}


//=================== SUA MON HOC =================== 
// MAU DE LAM POP UP
int popUpSuaMonHoc(TREE& treeMonHoc, char MAMH_CANSUA[15], IndexListMonHoc& sortedListMonHoc) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;
	const int number = 3; // số input field

	//string MAMH_STR = listSinhVien.sinhvien[indexSinhVien]->MASV;

	NodeMH* nodeMHCanSua = timMonHocTheoMaMonHoc(treeMonHoc, convertToString(MAMH_CANSUA));

	string TENMH_STR = nodeMHCanSua->MH.TENMH;
	string SOTCLT_STR = std::to_string(nodeMHCanSua->MH.STCLT);
	string SOTCTH_STR = std::to_string(nodeMHCanSua->MH.STCTH);


	string title[number] = { /*"MAMH",*/ "TENMH", "SOTCLT", "SOTCTH" }; // không cho sửa MAMH
	string data[number] = { TENMH_STR, SOTCLT_STR, SOTCTH_STR };

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "SUA MON HOC " + convertToString(MAMH_CANSUA), TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, " ESC : QUAY LAI", TEXT_LEFT);

	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];

			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, data[i], TEXT_LEFT);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char c = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, c);
			isClicked = false;
		}
		if (i == number) c = _getch();

		switch (c)
		{
		case -32:
			isClicked = true;
			c = _getch();
			if (c == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (c == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < 5) i++;
			}
			c = char();
			break;

		case ESC:
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		case ENTER:
		{
			if (i == number) {
				box(xPointer, y + height - (number + 1), widthInput, 3 /*số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//string e1 = checkMaSinhVien(listSinhVien, trim(MASV_STR));
				string e1 = checkTENMH(trim(TENMH_STR));
				string e2 = checkSOTCLT_TH(trim(SOTCLT_STR), "SO TCLT");
				string e3 = checkSOTCLT_TH(trim(SOTCTH_STR), "SO TCTH");

				int iy = y + height - (number + 1);
				setTextColor(COLOR_BRIGHT_WHITE);


				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
				if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }

				if (e1.empty() && e2.empty() && e3.empty()) {
					//if (employeeId == oldEmployeeId) { //KHONG THAY DOI MA NHAN VIEN
					MonHoc monhoc;
					strcpy_s(monhoc.MAMH, MAMH_CANSUA);
					strcpy_s(monhoc.TENMH, trim(TENMH_STR).c_str());
					monhoc.STCLT = stoi(trim(SOTCLT_STR));
					monhoc.STCTH = stoi(trim(SOTCTH_STR));

					suaMonHoc(treeMonHoc, monhoc);
					clearIndexListMonHoc(sortedListMonHoc);
					treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
					sapXepListMonHocTheoTen(sortedListMonHoc);
					//}
					//else { //THAY DOI MA NHAN VIEN
					//	employeeList.employee[employeeIndex]->employeeId = trim(employeeId);
					//	employeeList.employee[employeeIndex]->firstname = trim(firstname);
					//	employeeList.employee[employeeIndex]->lastname = trim(lastname);
					//	employeeList.employee[employeeIndex]->gender = trim(gender);

					//	sortEmployeeListByEmployeeId(employeeList);

					//	delete[] sortedEmployeeList.nodes;
					//	employeeListToEmployeeIndexList(employeeList, sortedEmployeeList);
					//	sortEmployeeListByName(sortedEmployeeList);
					//}

					//writeEmployeeFile(employeeList);
					return YES;
				}
			}
			break;
		}

		default:
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, TENMH_STR, c);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, SOTCLT_STR, c);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, SOTCTH_STR, c);
			break;
		}
		}
	}
}


//=================== BANG CHON MON HOC DE TAO LTC ===================
void tree_ChonMonHocTable(TREE treeMonHoc, IndexListMonHoc& sortedListMonHoc, bool isSearch) {
	ShowCur(0);
	/*titleBox(1, 3, "CHON MON HOC DE TAO LTC");*/
	titleBoxLeft(1, 3, "CHON MON HOC DE TAO LTC");
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 5;
	string title[column] = { "STT", "MAMH", "TENMH", "SO TCLT", "SO TCTH" };
	int cellWidth[column] = { 10, 15, 60, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "CHON"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListMonHocEmpty(sortedListMonHoc)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;


				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListMonHoc.number) break;
					else {
						index = sortedListMonHoc.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, sortedListMonHoc.nodes[k].MAMH);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListMonHoc.nodes[k].TENMH);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, std::to_string(sortedListMonHoc.nodes[k].STCLT));
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, std::to_string(sortedListMonHoc.nodes[k].STCTH));
						ix += cellWidth[4];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 17, yPage);
				cout << generateSpace(10);
				gotoXY(xPage - 17, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListMonHoc.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				// chữ trắng nền đen (ui hiển thị như đang bỏ chọn dòng hiện tại)
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				//int index = sortedListMonHoc.nodes[iOld + currentIndex].index;
				int index = iOld + currentIndex;

				//cout << listSinhVien.sinhvien[index]->MASV;
				// đọc thẳng từ sortedListMonHoc luôn
				cout << sortedListMonHoc.nodes[index].MAMH;

				// chuyển đến dòng kế chữ vàng nền đỏ (ui hiển thị như đang chọn dòng đang đi tới (gotoXY))
				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = i + currentIndex;

				// đọc thẳng từ sortedListMonHoc luôn
				cout << sortedListMonHoc.nodes[index].MAMH;
				//cout << listSinhVien.sinhvien[index]->MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA MON HOC
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListMonHoc.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListMonHoc.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
			
			}

			else if (key == DELETE_KEY /*&& !isSortedListMonHocEmpty(sortedListMonHoc)*/) {
			}
			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
				//delete[] sortedListSinhVien.nodes;

				clearIndexListMonHoc(sortedListMonHoc);

				treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
				sapXepListMonHocTheoTen(sortedListMonHoc);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/

				clearIndexListMonHoc(sortedListMonHoc);

				IndexListLopTinChi sortedListLopTinChi;
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				clearConsole();
				listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);

				/*menu(false);*/
			}
			break;
		}

		case ENTER: // CHON MON HOC DE THEM LOP TIN CHI
		{
			if (!isSortedListMonHocEmpty(sortedListMonHoc))
			{
				char MAMH_DUOCCHON[15];
				strcpy_s(MAMH_DUOCCHON, sortedListMonHoc.nodes[i + currentIndex].MAMH);
				int k = popUpThemLopTinChi(listLopTinChi, MAMH_DUOCCHON);
				if (k == YES) {
					clearIndexListMonHoc(sortedListMonHoc);
					IndexListLopTinChi sortedListLopTinChi;
					listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
					sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

					clearConsole();
					listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);
				}
			}
			
			break;
		}

		case CTRL_F: // TIM KIEM MON HOC
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP TENMH: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				clearIndexListMonHoc(sortedListMonHoc);
				searchTreeMonHocTheoTenMonHoc(treeMonHoc, sortedListMonHoc, name, true);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}

		default:
			break;
		}

	}

}

void listLopTinChiTable(ListLopTinChi& listLopTinChi, IndexListLopTinChi& sortedListLopTinChi, bool isSearch) {
	ShowCur(0);
	/*titleBox(1, 3, "QUAN LY LOP TIN CHI");*/
	titleBoxLeft(1, 3, "QUAN LY LOP TIN CHI");
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 9;
	string title[column] = { "STT", "MALTC", "MAMH", "NIENKHOA", "HOCKY", "NHOM", "MINSV", "MAXSV", "HUYLOP" };
	int cellWidth[column] = { 10, 15, 20, 20, 15, 15, 15, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "HIEU CHINH"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "F3", "DSSV DK"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListLopTinChiEmpty(sortedListLopTinChi)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListLopTinChi.number) break;
					else {
						index = sortedListLopTinChi.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MALOPTC));
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, listLopTinChi.loptinchi[index]->MAMH);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListLopTinChi.nodes[k].NIENKHOA);
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->HOCKY));
						ix += cellWidth[4];

						coutBox(ix, iy, cellWidth[5], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->NHOM));
						ix += cellWidth[5];

						coutBox(ix, iy, cellWidth[6], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MINSV));
						ix += cellWidth[6];

						coutBox(ix, iy, cellWidth[7], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MAXSV));
						ix += cellWidth[7];

						string HUYLOP = "";
						if (listLopTinChi.loptinchi[index]->HUYLOP == 0) {
							HUYLOP = "MO";
						}
						else if (listLopTinChi.loptinchi[index]->HUYLOP == 1) {
							HUYLOP = "HUY";
						}

						coutBox(ix, iy, cellWidth[8], TEXT_LEFT, HUYLOP);
						ix += cellWidth[8];
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage + 8, yPage);
				cout << generateSpace(10);
				gotoXY(xPage + 8, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListLopTinChi.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListLopTinChi.nodes[iOld + currentIndex].index;
				cout << listLopTinChi.loptinchi[index]->MALOPTC;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListLopTinChi.nodes[i + currentIndex].index;
				cout << listLopTinChi.loptinchi[index]->MALOPTC;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListLopTinChi.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListLopTinChi.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//THEM LOP TIN CHI
			else if (key == INSERT_KEY)
			{
				if (isListLopTinChiFull(listLopTinChi)) { //DANH SACH LOP TIN CHI DA DAY
					string message = "DANH SACH LOP TIN CHI DA DAY";
					int k = notificationPopUp(message);
					if (k == YES) {}
				}
				else { //DANH SACH LOP TIN CHI CHUA DAY
					IndexListMonHoc sortedListMonHoc;
					treeMonHocToIndexListMonHoc(treeMonHoc, sortedListMonHoc, true);
					sapXepListMonHocTheoTen(sortedListMonHoc);

					clearIndexListLopTinChi(sortedListLopTinChi);
					clearConsole();
;					tree_ChonMonHocTable(treeMonHoc, sortedListMonHoc, false);

					// bây h hiển thị bảng môn học để chọn
					// 
					//int k = popUpThemLopTinChi(listLopTinChi);
					//if (k == YES) {
					//	clearIndexListLopTinChi(sortedListLopTinChi);
					//	listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
					//	sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

					//	/*clearConsole();
					//	listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);*/
					//}
				}
				/*clearConsole();
				listLopTinChiTable(listLopTinChi, sortedListLopTinChi, isSearch);*/
			}

			//XOA LOP TIN CHI
			else if (key == DELETE_KEY && !isSortedListLopTinChiEmpty(sortedListLopTinChi))
			{
				string message = "BAN MUON XOA LOP TIN CHI NAY?";
				bool isAccepted = warningPopUp(message);
				int index = sortedListLopTinChi.nodes[i + currentIndex].index;
				if (isAccepted)
				{
					//------- sau này bắt trường hợp lớp đã có sinh viên đăng ký

					string message = kiemTraXoaLopTinChi(listLopTinChi, listLopTinChi.loptinchi[index]->MALOPTC);
					if (!message.empty()) {
						int t = notificationPopUp(message);
						if (t == YES) {};
					}
					else {
						xoaLopTinChiTheoMaLTC(listLopTinChi, listLopTinChi.loptinchi[index]->MALOPTC);

						clearIndexListLopTinChi(sortedListLopTinChi);
						listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
						sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

					}

				}
				clearConsole();
				listLopTinChiTable(listLopTinChi, sortedListLopTinChi, isSearch);
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				clearIndexListLopTinChi(sortedListLopTinChi);
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/

				clearIndexListLopTinChi(sortedListLopTinChi);
				clearConsole();
				menu(false);
			}
			break;
		}

		case ENTER: // SUA LOP TIN CHI
		{
			if (!isSortedListLopTinChiEmpty(sortedListLopTinChi))
			{
				int index = sortedListLopTinChi.nodes[i + currentIndex].index;
				int k = popUpSuaLopTinChi(listLopTinChi, index, sortedListLopTinChi);
				if (k == YES) { // DA HIEU CHINH LTC
					clearConsole();
					listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);
				}
				else {//NHAN ESC
					clearConsole();
					listLopTinChiTable(listLopTinChi, sortedListLopTinChi, isSearch);
				}
			}
			break;
		}

		case CTRL_F: // TIM KIEM LOP TIN CHI
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP NIENKHOA: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				clearIndexListLopTinChi(sortedListLopTinChi);
				seachListLopTinChiTheoNienKhoa(listLopTinChi, sortedListLopTinChi, trim(name));
				//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}
		case F3: // DANH SACH SV DANG KY LOP TC
		{

			if (!isSortedListLopTinChiEmpty(sortedListLopTinChi)) {
				int index = sortedListLopTinChi.nodes[i + currentIndex].index;
				int MALTC_SELECTED = -1;
				MALTC_SELECTED = listLopTinChi.loptinchi[index]->MALOPTC;
				int MAXSV = -1;
				MAXSV = listLopTinChi.loptinchi[index]->MAXSV;
				IndexListDangKy sortedListDangKy;
				listDangKyToIndexListDangKy(listLopTinChi.loptinchi[index]->DSDK, sortedListDangKy, MAXSV, listSinhVien);
				sapXepListDangKyTheoHOTENSV(sortedListDangKy);

				string title = "MAMH: "+convertToString(listLopTinChi.loptinchi[index]->MAMH) + "   NIENKHOA: " +
					convertToString(listLopTinChi.loptinchi[index]->NIENKHOA) + "   HK: " +
					std::to_string(listLopTinChi.loptinchi[index]->HOCKY) + "   NHOM: " +
					std::to_string(listLopTinChi.loptinchi[index]->NHOM);

				clearConsole();
				clearIndexListLopTinChi(sortedListLopTinChi);

				listSinhVienDangKyTable(listLopTinChi.loptinchi[index]->DSDK, sortedListDangKy, false, title);
			}
			break;
		}
		default:
			break;
		}

	}

}

void listLopTinChi_ChonLopTinChiTable(ListLopTinChi& listLopTinChi, IndexListLopTinChi& sortedListLopTinChi, bool isSearch) {
	ShowCur(0);
	//titleBox(1, 3, "DANH SACH LOP TIN CHI");
	titleBoxLeft(1, 3, "DANH SACH LOP TIN CHI");
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 9;
	string title[column] = { "STT", "MALTC", "MAMH", "NIENKHOA", "HOCKY", "NHOM", "MINSV", "MAXSV", "HUYLOP" };
	int cellWidth[column] = { 10, 15, 20, 20, 15, 15, 15, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "XEM BANG DIEM"); keyBoxWidth += 5;
	/*keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;*/
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "F3", "DSSV DK"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListLopTinChiEmpty(sortedListLopTinChi)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListLopTinChi.number) break;
					else {
						index = sortedListLopTinChi.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MALOPTC));
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, listLopTinChi.loptinchi[index]->MAMH);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListLopTinChi.nodes[k].NIENKHOA);
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->HOCKY));
						ix += cellWidth[4];

						coutBox(ix, iy, cellWidth[5], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->NHOM));
						ix += cellWidth[5];

						coutBox(ix, iy, cellWidth[6], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MINSV));
						ix += cellWidth[6];

						coutBox(ix, iy, cellWidth[7], TEXT_LEFT, std::to_string(listLopTinChi.loptinchi[index]->MAXSV));
						ix += cellWidth[7];

						string HUYLOP = "";
						if (listLopTinChi.loptinchi[index]->HUYLOP == 0) {
							HUYLOP = "MO";
						}
						else if (listLopTinChi.loptinchi[index]->HUYLOP == 1) {
							HUYLOP = "HUY";
						}

						coutBox(ix, iy, cellWidth[8], TEXT_LEFT, HUYLOP);
						ix += cellWidth[8];
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage + 7, yPage);
				cout << generateSpace(10);
				gotoXY(xPage + 7, yPage);
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListLopTinChi.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListLopTinChi.nodes[iOld + currentIndex].index;
				cout << listLopTinChi.loptinchi[index]->MALOPTC;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListLopTinChi.nodes[i + currentIndex].index;
				cout << listLopTinChi.loptinchi[index]->MALOPTC;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListLopTinChi.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListLopTinChi.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//THEM LOP TIN CHI
			else if (key == INSERT_KEY)
			{
				break;
			}

			//XOA LOP TIN CHI
			else if (key == DELETE_KEY && !isSortedListLopTinChiEmpty(sortedListLopTinChi))
			{
				break;
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
				//delete[] sortedListSinhVien.nodes;

				clearIndexListLopTinChi(sortedListLopTinChi);
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/
				//delete[] sortedListSinhVien.nodes;
				clearIndexListLopTinChi(sortedListLopTinChi);
				clearConsole();
				menu(false);
			}
			break;
		}

		case ENTER: // XEM BANG DIEM
		{
			if (!isSortedListLopTinChiEmpty(sortedListLopTinChi)) {
				int index = sortedListLopTinChi.nodes[i + currentIndex].index;
				int MALTC_SELECTED = -1;
				MALTC_SELECTED = listLopTinChi.loptinchi[index]->MALOPTC;
				int MAXSV = -1;
				MAXSV = listLopTinChi.loptinchi[index]->MAXSV;

				int indexLopTinChiCanXem = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC_SELECTED);

				IndexListDangKy sortedListDangKy;
				listDangKyToIndexListDangKy(listLopTinChi.loptinchi[indexLopTinChiCanXem]->DSDK, sortedListDangKy, MAXSV, listSinhVien);
				sapXepListDangKyTheoHOTENSV(sortedListDangKy);

				if (isSortedListDangKyEmpty(sortedListDangKy)) {
					int k = notificationPopUp("LTC NAY KHONG CO SV");
					if (k == YES) {

					}

					clearConsole();
					listLopTinChi_ChonLopTinChiTable(listLopTinChi, sortedListLopTinChi, isSearch);
				}
				else {

					string title = "MAMH: " + convertToString(listLopTinChi.loptinchi[index]->MAMH) + "   NIENKHOA: " +
						convertToString(listLopTinChi.loptinchi[index]->NIENKHOA) + "   HK: " +
						std::to_string(listLopTinChi.loptinchi[index]->HOCKY) + "   NHOM: " +
						std::to_string(listLopTinChi.loptinchi[index]->NHOM);

					clearConsole();
					clearIndexListLopTinChi(sortedListLopTinChi);

					bangDiemLTCTable(listLopTinChi.loptinchi[index]->DSDK, sortedListDangKy, false, title);
				}
				
			}
			break;
		}

		case CTRL_F: // TIM KIEM LOP TIN CHI
		{
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP NIENKHOA: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string name = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				//delete[] sortedListSinhVien.nodes;
				clearIndexListLopTinChi(sortedListLopTinChi);
				seachListLopTinChiTheoNienKhoa(listLopTinChi, sortedListLopTinChi, trim(name));
				//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}
			break;
		}
		case F3: //
		{

			break;
		}
		default:
			break;
		}

	}

}

//=================== THEM LOP TIN CHI ===================
int popUpThemLopTinChi(ListLopTinChi& listLopTinChi, char MAMH[15]) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;

	//char MASV[15];
	//char HO[30];
	//char TEN[10];
	//bool PHAI;
	//char SODT[15];

	int newMALOPTC = maxMALOPTC + 1;

	string MAMH_STR = convertToString(MAMH);
	string NIENKHOA_STR = std::to_string(getCurrentYear());
	string HOCKY_STR;
	string NHOM_STR;
	string MINSV_STR;
	string MAXSV_STR;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THEM LOP TIN CHI MONHOC: "+ convertToString(MAMH) + "; NIEN KHOA: "+ std::to_string(getCurrentYear()), TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "", TEXT_CENTER);
	gotoXY(x + 1, y + height);
	cout << "ESC : QUAY LAI";

	const int number = 4;

	string title[number] = { /*"MAMH", "NIENKHOA",*/ "HOCKY", "NHOM", "MINSV", "MAXSV" }; //Mã lớp tín chỉ tự sinh, khi thêm thì mặc định HUYLOP = 0 (đang mở)
	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];
			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char key = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, key);
			isClicked = false;
		}
		if (i == number) key = _getch();// = số field input
		switch (key)
		{
		case -32: //DIEU HUONG LEN/XUONG
		{
			isClicked = true;
			key = _getch();
			if (key == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1) /*6 là số input field + 1*/, 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (key == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;
		}


		case ENTER: //NHAN OK DE THEM LOP TIN CHI VAO DANH SACH
		{
			if (i == number) {// = số field input
				box(xPointer, y + height - (number + 1), widthInput, 5/* chiều cao thông báo lỗi (số thông báo lỗi có thể có cùng lúc)*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//KIEM TRA THONG TIN NHAP VAO
				// 
				// Bây h đã chọn môn trước khi hiện pop up, và mặc định niên khóa = năm nay
				//string e1 = checkMaMonHocLopTinChi(treeMonHoc, trim(MAMH_STR));
				//string e2 = checkNIENKHOA(trim(NIENKHOA_STR));
				string e3 = checkHK_MIN_MAXSV(trim(HOCKY_STR), "HOC KY");
				string e4 = checkHK_MIN_MAXSV(trim(NHOM_STR), "NHOM");
				string e5 = checkHK_MIN_MAXSV(trim(MINSV_STR), "MINSV");
				string e6 = checkHK_MIN_MAXSV(trim(MAXSV_STR), "MAXSV");
				string e7 = checkToHopKeyLopTinChi(listLopTinChi, trim(MAMH_STR), trim(NIENKHOA_STR), trim(HOCKY_STR), trim(NHOM_STR));
				string e8 = "";

				int iy = y + height - (number + 1);
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e7.empty()) { gotoXY(xPointer + 1, iy); cout << e7; iy += 1; }
				else {
					//if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
					//if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
					if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }
					if (!e4.empty()) { gotoXY(xPointer + 1, iy); cout << e4; iy += 1; }
					// nếu MINSV MAXSV đúng là số
					if (e5.empty() && e6.empty()) {
						//kiểm tra xem min có <= max k
						if (stoi(trim(MINSV_STR)) > stoi(trim(MAXSV_STR))) {
							e8 = "MINSV khong duoc vuot qua MAXSV";
							gotoXY(xPointer + 1, iy); cout << e8; iy += 1;
						}
					}
					else {
						if (!e5.empty()) { gotoXY(xPointer + 1, iy); cout << e5; iy += 1; }
						if (!e6.empty()) { gotoXY(xPointer + 1, iy); cout << e6; iy += 1; }
					}

				}

				if (/*e1.empty() && e2.empty() && */e3.empty() && e4.empty() && e5.empty() && e6.empty() && e7.empty() && e8.empty()) {

					//THEM LOP TIN CHI MOI
					LopTinChi lopTinChi;
					lopTinChi.MALOPTC = newMALOPTC;
					strcpy_s(lopTinChi.MAMH, trim(MAMH_STR).c_str());
					strcpy_s(lopTinChi.NIENKHOA, trim(NIENKHOA_STR).c_str());
					lopTinChi.NHOM = stoi(trim(NHOM_STR));
					lopTinChi.HOCKY = stoi(trim(HOCKY_STR));
					lopTinChi.MINSV = stoi(trim(MINSV_STR));
					lopTinChi.MAXSV = stoi(trim(MAXSV_STR));
					lopTinChi.HUYLOP = 0; // default lúc tạo là lớp đang mở

					//// khởi tạo danh sách đăng ký, tránh trường hợp truy cập đăng ký lớp vừa thêm để xem sinh viên đã đăng ký chưa bị lỗi
					lopTinChi.DSDK = initListDangKy();

					insertLopTinChiOrderByMaLTC(listLopTinChi, lopTinChi);

					//cập nhật maxMALopTC cho lần thêm tiếp theo
					maxMALOPTC = maxMALOPTC + 1;
					//	//GHI LAI FILE
					//	//writeEmployeeFile(employeeList);
					return YES;
				}
			}
			else {
				continue;
			}
			break;
		}

		case ESC: //THOAT POP UP
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		default: //NHAP CAC FIELD TRONG POP UP
		{
			/*if (i == 0) upperCaseWhileTyping(xPointer, yPointer, MAMH_STR, key);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, NIENKHOA_STR, key);
			else*/ if (i == 0) upperCaseWhileTyping(xPointer, yPointer, HOCKY_STR, key);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, NHOM_STR, key);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, MINSV_STR, key);
			else if (i == 3) upperCaseWhileTyping(xPointer, yPointer, MAXSV_STR, key);

			break;
		}
		}
	}
}


//=================== SUA LOP TIN CHI =================== 
// MAU DE LAM POP UP
int popUpSuaLopTinChi(ListLopTinChi& listLopTinChi, int indexLopTinChiCanSua, IndexListLopTinChi& sortedListLopTinChi) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;
	const int number = 3; // số input field

	int maLTC_CANSUA = listLopTinChi.loptinchi[indexLopTinChiCanSua]->MALOPTC;

	string MINSV_STR = std::to_string(listLopTinChi.loptinchi[indexLopTinChiCanSua]->MINSV);
	string MAXSV_STR = std::to_string(listLopTinChi.loptinchi[indexLopTinChiCanSua]->MAXSV);
	string HUYLOP_STR = listLopTinChi.loptinchi[indexLopTinChiCanSua]->HUYLOP == 0 ? "MO" : "HUY";
	string oldHUYLOP_STR = HUYLOP_STR;

	string title[number] = { /*"MAMH",*/ "MINSV", "MAXSV", "HUYLOP" }; // không cho sửa MAMH
	string data[number] = { MINSV_STR, MAXSV_STR, HUYLOP_STR };

	string editTitle = convertToString(listLopTinChi.loptinchi[indexLopTinChiCanSua]->MAMH) + "-" +
		convertToString(listLopTinChi.loptinchi[indexLopTinChiCanSua]->NIENKHOA) + "-HK:" +
		std::to_string(listLopTinChi.loptinchi[indexLopTinChiCanSua]->HOCKY) + "-NHOM:" +
		std::to_string(listLopTinChi.loptinchi[indexLopTinChiCanSua]->NHOM);
	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "SUA LTC " + editTitle, TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, " ESC : QUAY LAI", TEXT_LEFT);

	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];

			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, data[i], TEXT_LEFT);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char c = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, c);
			isClicked = false;
		}
		if (i == number) c = _getch();

		switch (c)
		{
		case -32:
			isClicked = true;
			c = _getch();
			if (c == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_RED, COLOR_BRIGHT_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (c == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < 5) i++;
			}
			c = char();
			break;

		case ESC:
		{
			setBackgroundColor(COLOR_BLACK);
			return NO;
			break;
		}

		case ENTER:
		{
			if (i == number) {
				box(xPointer, y + height - (number + 1), widthInput, 4 /*số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				string e1 = checkHK_MIN_MAXSV(trim(MINSV_STR), "MINSV");
				string e2 = checkHK_MIN_MAXSV(trim(MAXSV_STR), "MAXSV");
				string e3 = checkHUYLOPTC(listLopTinChi, maLTC_CANSUA, oldHUYLOP_STR, trim(HUYLOP_STR));
				string e4 = "";
				string e5 = "";
				int iy = y + height - (number + 1);
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				// nếu MINSV MAXSV đúng là số
				if (e2.empty() && e3.empty()) {


					//kiểm tra xem min có <= max k
					if (stoi(trim(MINSV_STR)) > stoi(trim(MAXSV_STR))) {
						e4 = "MINSV khong duoc vuot qua MAXSV";
						gotoXY(xPointer + 1, iy); cout << e4; iy += 1;
					}
					else {
						e5 = kiemTraSuaMAXSV(listLopTinChi, maLTC_CANSUA, trim(MAXSV_STR));
						if (!e5.empty()) { gotoXY(xPointer + 1, iy); cout << e5; iy += 1; }
					}
				}
				else {
					if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
					if (!e3.empty()) { gotoXY(xPointer + 1, iy); cout << e3; iy += 1; }
				}

				if (e1.empty() && e2.empty() && e3.empty() && e4.empty() && e5.empty()) {
					LopTinChi lopTinChi;
					lopTinChi.MALOPTC = maLTC_CANSUA;
					/*strcpy_s(lopTinChi.MAMH, trim(MAMH_STR).c_str());
					strcpy_s(lopTinChi.NIENKHOA, trim(NIENKHOA_STR).c_str());
					lopTinChi.NHOM = stoi(trim(NHOM_STR));
					lopTinChi.HOCKY = stoi(trim(HOCKY_STR));*/
					lopTinChi.MINSV = stoi(trim(MINSV_STR));
					lopTinChi.MAXSV = stoi(trim(MAXSV_STR));

					if (HUYLOP_STR.compare("HUY") == 0) {
						lopTinChi.HUYLOP = 1;
					}
					else if (HUYLOP_STR.compare("MO") == 0) {
						lopTinChi.HUYLOP = 0;
					}

					suaLopTinChi(listLopTinChi, lopTinChi);

					clearIndexListLopTinChi(sortedListLopTinChi);
					listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
					sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);
					
					return YES;
				}
			}
			break;
		}

		default:
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, MINSV_STR, c);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, MAXSV_STR, c);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, HUYLOP_STR, c);
			break;
		}
		}
	}
}


//=================== BANG SINH VIEN DANG KY LOP TC ===================
void listSinhVienDangKyTable(ListDangKy& listDangKy, IndexListDangKy& sortedListDangKy, bool isSearch, string tabletitle) {
	ShowCur(0);
	//titleBox(1, 3, "DSSV DANG KY LOP: " + tabletitle);
	titleBoxLeft(1, 3, "DSSV DANG KY LOP: " + tabletitle);
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 4;
	string title[column] = { "STT", "MASV", "HO", "TEN" };
	int cellWidth[column] = { 10, 15, 30, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "CHON"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListDangKyEmpty(sortedListDangKy)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListDangKy.number) break;
					else {
						index = sortedListDangKy.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, sortedListDangKy.nodes[index].MASV);
						ix += cellWidth[1];
						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListDangKy.nodes[index].HO);
						ix += cellWidth[2];
						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListDangKy.nodes[index].TEN);
						ix += cellWidth[3];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 62, yPage);//-62 để thụt trang hiện tại vào trong
				cout << generateSpace(10);
				gotoXY(xPage - 62, yPage);//-62 để thụt trang hiện tại vào trong
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListDangKy.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListDangKy.nodes[iOld + currentIndex].index;
				cout << sortedListDangKy.nodes[index].MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListDangKy.nodes[i + currentIndex].index;
				cout << sortedListDangKy.nodes[index].MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA LOP
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListDangKy.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListDangKy.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
				
			}

			//
			else if (key == DELETE_KEY /* && !isSortedListSinhVienEmpty(indexListLop)*/)
			{
				
			}
			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				//ShowCur(0);
				//setBackgroundColor(COLOR_BLACK);
				//gotoXY(x + 1, 5);
				//cout << generateSpace(50);

				//clearIndexListDangKy(sortedListDangKy);
				//////delete[] indexListLop.nodes;
				////clearIndexListLop(indexListLop);
				////listLopToIndexListLop(listLop, indexListLop);
				//////sapXepListSinhVienTheoTen(indexListLop);

				//ShowCur(0);
				//isSearch = false;
				//isInit = true;
				//isLeftRight = true;
				//isUpDown = true;
			}
			else {
				/*delete[] indexListLop.nodes;
				clearConsole();
				menu(false);*/
				//delete[] indexListLop.nodes;
				clearIndexListDangKy(sortedListDangKy);

				IndexListLopTinChi sortedListLopTinChi;
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				clearConsole();
				listLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);

				//menu(false);
			}
			break;
		}

		case ENTER: // SUA SINH VIEN TRONG DANH SACH SINH VIEN
		{
			//if (!isSortedEmployeeListEmpty(indexListLop))
			//{
			//	int index = indexListLop.nodes[i + currentIndex].index;
			//	int k = editEmployeePopUp(employeeList, index, indexListLop);
			//	if (k == YES) { // DA HIEU CHINH SINH VIEN
			//		clearConsole();
			//		employeeTable(employeeList, indexListLop, false);
			//	}
			//	else {//NHAN ESC
			//		clearConsole();
			//		employeeTable(employeeList, indexListLop, isSearch);
			//	}
			//}

			/*if (!isIndexListLopEmpty(indexListLop)) {
				int index = indexListLop.nodes[i + currentIndex].index;
				char MA_LOP_SELECTED[15];
				strcpy_s(MA_LOP_SELECTED, listLop.lop[index]->MALOP);

				clearListSinhVien(listSinhVienTheoLop);

				locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MA_LOP_SELECTED);

				IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				clearConsole();
				listSinhVienTable(listSinhVienTheoLop, sortedListSinhVien, false, MA_LOP_SELECTED);
			}*/
			break;
		}

		case CTRL_F: // TIM KIEM LOP
		{
			/*setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP MA LOP: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string keyword = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, keyword, c);

			if (c == ENTER) {
				clearIndexListLop(indexListLop);
				searchListLopByMaLop(listLop, indexListLop, trim(keyword));

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}*/
			break;
		}

		default:
			break;
		}

	}

}

//=================== NHAP MA SINH VIEN ===================
char* popUpNhapMaSinhVien() {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;

	string MASV_STR; /*= generateEmployeeId(employeeList);*/

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "NHAP MA SINH VIEN", TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "", TEXT_CENTER);
	gotoXY(x + 1, y + height);
	cout << "ESC : QUAY LAI";

	const int number = 1;
	string title[number] = { "MASV" };
	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];
			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char key = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, key);
			isClicked = false;
		}
		if (i == number) key = _getch();// = số field input
		switch (key)
		{
		case -32: //DIEU HUONG LEN/XUONG
		{
			isClicked = true;
			key = _getch();
			if (key == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (key == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;
		}


		case ENTER: //NHAN OK DE NHAP MASV SINH VIEN
		{
			if (i == number) {// = số field input (đang ở nơi báo lỗi)
				box(xPointer, y + height - 5 - (number + 1), widthInput, 1 /* số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//KIEM TRA THONG TIN NHAP VAO
				string e1 = checkMaSVKhongTonTai(listSinhVien, trim(MASV_STR));

				int iy = y + height - 5 - (number + 1); //pop up height khá cao nên giảm xuống
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }

				if (e1.empty()) {
					char MASV[15];
					strcpy_s(MASV, MASV_STR.c_str());
					return MASV;
				}
			}
			else {
				continue;
			}
			break;
		}

		case ESC: //THOAT POP UP
		{
			MASV_STR = "";
			char MASV[15];
			strcpy_s(MASV, MASV_STR.c_str());
			setBackgroundColor(COLOR_BLACK);
			return MASV;
			break;
		}

		default: //NHAP CAC FIELD TRONG POP UP
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, MASV_STR, key);
			break;
		}
		}
	}
}
//=================== NHAP NIEN KHOA HOC KY ===================
void popUpNhapNienKhoaHocKy(SinhVien sinhvien) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = WIDTH_INPUT;

	string NIENKHOA_STR = std::to_string(getCurrentYear());
	string HOCKY_STR;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "NHAP NIEN KHOA, HOC KY", TEXT_CENTER);
	box(x, y + height, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "", TEXT_CENTER);
	gotoXY(x + 1, y + height);
	cout << "ESC : QUAY LAI";

	const int number = 2;
	string title[number] = { "NIEN KHOA", "HOC KY"};

	for (int i = 0; i <= number; i++) {
		if (i == number) {
			box(xInput, y + 2 * (i + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
		}
		else {
			gotoXY(x + 2, y + 2 * (i + 1));
			setBackgroundColor(COLOR_WHITE);
			setTextColor(COLOR_BLACK);
			cout << title[i];
			box(xInput - 2, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
		}
	}

	int xPointer = xInput;
	int yPointer = y + 2;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int backgroundColorChoose = 7;
	int i = 0;
	bool isClicked = true;
	char key = char();

	while (true)
	{
		if (isClicked)
		{
			ShowCur(1);
			if (i == number) {
				ShowCur(0);
				box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_LIGHT_YELLOW, COLOR_BLACK, "OK", TEXT_CENTER);
			};
			//if (i == 0) upperCaseWhileTyping(xPointer, yPointer, employeeId, key);
			isClicked = false;
		}
		if (i == number) key = _getch();// = số field input
		switch (key)
		{
		case -32: //DIEU HUONG LEN/XUONG
		{
			isClicked = true;
			key = _getch();
			if (key == UP && yPointer != y + 2)
			{
				yPointer -= 2;
				if (i == number) box(xPointer, y + 2 * (number + 1), 10, 3, COLOR_RED, COLOR_WHITE, "OK", TEXT_CENTER);
				if (i > 0) i--;
			}
			else if (key == DOWN && yPointer != y + 2 * (number + 1))
			{
				yPointer += 2;
				if (i < (number + 1)) i++;
			}
			key = char();
			break;
		}


		case ENTER: //NHAN OK DE NHAP NIEN KHOA HOC KY
		{
			if (i == number) {// = số field input (đang ở nơi báo lỗi)
				box(xPointer, y + height - 5 - (number + 1), widthInput, 2 /* số thông báo lỗi có thể có cùng lúc*/, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

				//KIEM TRA THONG TIN NHAP VAO
				string e1 = checkNIENKHOA(trim(NIENKHOA_STR));
				string e2 = checkHK_MIN_MAXSV(trim(HOCKY_STR), "HOC KY");

				int iy = y + height - 5 - (number + 1); //pop up height khá cao nên giảm xuống
				setTextColor(COLOR_BRIGHT_WHITE);

				if (!e1.empty()) { gotoXY(xPointer + 1, iy); cout << e1; iy += 1; }
				if (!e2.empty()) { gotoXY(xPointer + 1, iy); cout << e2; iy += 1; }
				if (e1.empty()&&e2.empty()) {

					char NIENKHOA[15];
					strcpy_s(NIENKHOA, trim(NIENKHOA_STR).c_str());

					ListLopTinChi listLopTinChiTheoNienKhoaHK;
					timLopTinChiConMoTheoNienKhoaHK(listLopTinChi, listLopTinChiTheoNienKhoaHK, NIENKHOA, stoi(trim(HOCKY_STR)));

					IndexListLopTinChi sortedListLopTinChiTheoNienKhoaHK;
					listLopTinChiToIndexListLopTinChi(listLopTinChiTheoNienKhoaHK, sortedListLopTinChiTheoNienKhoaHK);
					//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChiTheoNienKhoa);

					clearConsole();
					listLopTinChiSinhVienDangKyTable(listLopTinChi, listLopTinChiTheoNienKhoaHK, sortedListLopTinChiTheoNienKhoaHK, sinhvien, false);
				}
			}
			else {
				continue;
			}
			break;
		}

		case ESC: //THOAT POP UP
		{
			setBackgroundColor(COLOR_BLACK);
			clearConsole();
			menu(false);
			break;
		}

		default: //NHAP CAC FIELD TRONG POP UP
		{
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, NIENKHOA_STR, key);
			if (i == 1) upperCaseWhileTyping(xPointer, yPointer, HOCKY_STR, key);
			break;
		}
		}
	}
}
//=================== DANH SACH LTC SINH VIEN DA DANG KY, CO THE DANG KY TRONG NIEN KHOA HIEN TAI ===========
void listLopTinChiSinhVienDangKyTable(ListLopTinChi& listLopTinChi, ListLopTinChi& listLopTinChiTheoNienKhoa, IndexListLopTinChi& sortedListLopTinChiTheoNienKhoa, SinhVien sinhvien, bool isSearch) {
	ShowCur(0);
	string ttsv = "MASV: " + convertToString(sinhvien.MASV) +
		"   HO TEN: " + convertToString(sinhvien.HO) + " " + convertToString(sinhvien.TEN) +
		"   PHAI: " + (sinhvien.PHAI == 0 ? "NU" : "NAM") + "   SDT:" + convertToString(sinhvien.SODT) + "   MALOP: " + convertToString(sinhvien.MALOP);
	titleBoxLeft(1, 3, ttsv);

	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 9;
	string title[column] = { "STT", "MALTC", "TENMH", "NIENKHOA", "HOCKY", "NHOM","DA DK", "SL CON", "SV DA DK"};// chỉ hiện ra lớp còn mở 
	int cellWidth[column] = { 10, 10, 55, 15, 10, 10, 10 , 10, 10 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "DANG KY"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "DANG KY"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "HUY DANG KY"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "F3", "DSSV DK"); keyBoxWidth += 5;

	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListLopTinChiEmpty(sortedListLopTinChiTheoNienKhoa)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListLopTinChiTheoNienKhoa.number) break;
					else {
						index = sortedListLopTinChiTheoNienKhoa.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, std::to_string(listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC));
						ix += cellWidth[1];

					/*	coutBox(ix, iy, cellWidth[2], TEXT_LEFT, listLopTinChiTheoNienKhoa.loptinchi[index]->MAMH);
						ix += cellWidth[2];*/
						NodeMH* monhoc = timMonHocTheoMaMonHoc(treeMonHoc, listLopTinChiTheoNienKhoa.loptinchi[index]->MAMH);

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, monhoc->MH.TENMH);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListLopTinChiTheoNienKhoa.nodes[k].NIENKHOA);
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, std::to_string(listLopTinChiTheoNienKhoa.loptinchi[index]->HOCKY));
						ix += cellWidth[4];

						coutBox(ix, iy, cellWidth[5], TEXT_LEFT, std::to_string(listLopTinChiTheoNienKhoa.loptinchi[index]->NHOM));
						ix += cellWidth[5];

						int indexLTCCANKTRA = timIndexLopTinChiTheoMALTC(listLopTinChi, listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC);
						int soLuongSVdaDangKy = laySoLuongSVDaDK(listLopTinChi.loptinchi[indexLTCCANKTRA]->DSDK);

						coutBox(ix, iy, cellWidth[6], TEXT_LEFT, std::to_string(soLuongSVdaDangKy));
						ix += cellWidth[6];

						coutBox(ix, iy, cellWidth[7], TEXT_LEFT, std::to_string(listLopTinChiTheoNienKhoa.loptinchi[index]->MAXSV - soLuongSVdaDangKy));
						ix += cellWidth[7];

						int daDangKy = kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[indexLTCCANKTRA]->DSDK, sinhvien.MASV);

						coutBox(ix, iy, cellWidth[8], TEXT_LEFT, daDangKy == 1 ? "X" : "");
						ix += cellWidth[8];

					
						/*coutBox(ix, iy, cellWidth[6], TEXT_LEFT, std::to_string(listLopTinChiSinhVienDaDangKy.loptinchi[index]->MINSV));
						ix += cellWidth[6];

						coutBox(ix, iy, cellWidth[7], TEXT_LEFT, std::to_string(listLopTinChiSinhVienDaDangKy.loptinchi[index]->MAXSV));
						ix += cellWidth[7];

						string HUYLOP = "";
						if (listLopTinChiSinhVienDaDangKy.loptinchi[index]->HUYLOP == 1) {
							HUYLOP = "MO";
						}
						else if (listLopTinChiSinhVienDaDangKy.loptinchi[index]->HUYLOP == 0) {
							HUYLOP = "HUY";
						}

						coutBox(ix, iy, cellWidth[8], TEXT_LEFT, HUYLOP);
						ix += cellWidth[8];*/
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 10, yPage);//-10 để thụt trang hiện tại vào trong
				cout << generateSpace(10);
				gotoXY(xPage - 10, yPage); //-10 để thụt trang hiện tại vào trong
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListLopTinChiTheoNienKhoa.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListLopTinChiTheoNienKhoa.nodes[iOld + currentIndex].index;
				cout << listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListLopTinChiTheoNienKhoa.nodes[i + currentIndex].index;
				cout << listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA SINH VIEN
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListLopTinChiTheoNienKhoa.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListLopTinChiTheoNienKhoa.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			
			else if (key == INSERT_KEY)
			{
			
			}

			//XOA LOP TIN CHI
			else if (key == DELETE_KEY && !isSortedListLopTinChiEmpty(sortedListLopTinChiTheoNienKhoa))
			{
				int index = sortedListLopTinChiTheoNienKhoa.nodes[i + currentIndex].index;
				int MALTC_SV_CANHUYDANGKY = listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC;
				int indexLTCCANKTRA = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC_SV_CANHUYDANGKY);
				int daDangKy = kiemTraSinhVienCoDangKy(listLopTinChi.loptinchi[indexLTCCANKTRA]->DSDK, sinhvien.MASV);

				if (daDangKy == 0) {
					string message = "BAN CHUA DANG KY LTC NAY";
					bool isAccepted = notificationPopUp(message);
					clearConsole();
					listLopTinChiSinhVienDangKyTable(listLopTinChi, listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa, sinhvien, false);
				}
				else {
					string message = "BAN MUON HUY DANG KY LOP TIN CHI NAY?";
					bool isAccepted = warningPopUp(message);
					int index = sortedListLopTinChiTheoNienKhoa.nodes[i + currentIndex].index;
					int MALTC_SV_CANHUYDANGKY = listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC;
					if (isAccepted)
					{
						//cần bắt trường hợp sinh viên đã có điểm
						int indexLTCTrongListAll = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC_SV_CANHUYDANGKY);
						LopTinChi* lopTinChiSVCanHuyDK = new LopTinChi;
						lopTinChiSVCanHuyDK = listLopTinChi.loptinchi[indexLTCTrongListAll];
						xoaTrongDanhSachDangKyTheoMaSinhVien(lopTinChiSVCanHuyDK->DSDK, sinhvien.MASV);

					/*	clearListLopTinChi(listLopTinChiTheoNienKhoa);
						clearIndexListLopTinChi(sortedListLopTinChiTheoNienKhoa);
						timLopTinChiSinhVienDaDangKy(listLopTinChi, listLopTinChiTheoNienKhoa, sinhvien.MASV);
						listLopTinChiToIndexListLopTinChi(listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa);*/
						
						//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChiTheoNienKhoa);

						clearConsole();
						listLopTinChiSinhVienDangKyTable(listLopTinChi, listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa, sinhvien, false);
					}
				}

				//writeEmployeeFile(employeeList);
			}

			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);

				//delete[] sortedListSinhVien.nodes;

				clearIndexListLopTinChi(sortedListLopTinChiTheoNienKhoa);
				listLopTinChiToIndexListLopTinChi(listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa);
				//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChiSinhVienDaDangKy);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] sortedListSinhVien.nodes;
				clearConsole();
				menu(false);*/
				//delete[] sortedListSinhVien.nodes;
				clearIndexListLopTinChi(sortedListLopTinChiTheoNienKhoa);
				clearListLopTinChi(listLopTinChiTheoNienKhoa);//15-8
				clearConsole();
				menu(false);
			}
			break;
		}

		case ENTER: // DANG KY LOP TC NAY
		{
			if (!isSortedListLopTinChiEmpty(sortedListLopTinChiTheoNienKhoa))
			{
				int index = sortedListLopTinChiTheoNienKhoa.nodes[i + currentIndex].index;
				int MALTC_SV_CANDANGKY = listLopTinChiTheoNienKhoa.loptinchi[index]->MALOPTC;

				if (sinhVienDaDangKyMonNayNienKhoaHKNay(listLopTinChi, sinhvien.MASV, listLopTinChiTheoNienKhoa.loptinchi[index]) == 1) {
					string message = "SV DA DANG KY MH NAY TRONG NIEN KHOA HOC KY NAY";
					int t = notificationPopUp(message);
					if (t == YES) {};
				}
				else {
					int indexLTCCANKTRA = timIndexLopTinChiTheoMALTC(listLopTinChi, MALTC_SV_CANDANGKY);

					if (laySoLuongSVDaDK(listLopTinChi.loptinchi[indexLTCCANKTRA]->DSDK) == listLopTinChi.loptinchi[indexLTCCANKTRA]->MAXSV) {
						string message = "LOP TC DA DU SO LUONG DANG KY";
						int t = notificationPopUp(message);
						if (t == YES) {};
					}
					else {
						sinhVienDangKyLopTinChi(listLopTinChi, MALTC_SV_CANDANGKY, sinhvien.MASV);

					}
				}
			}
			clearConsole();
			listLopTinChiSinhVienDangKyTable(listLopTinChi, listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa, sinhvien, false);
			break;
		}

		case CTRL_F: // TIM KIEM LOP TIN CHI, trường hợp này k cần vì chỉ hiển thị ltc niên khóa được chọn
		{
			//setTextColor(COLOR_BRIGHT_WHITE);
			//setBackgroundColor(COLOR_BLACK);
			//string text = "NHAP NIENKHOA: ";
			//gotoXY(x + 1, 5);
			//cout << text << generateSpace(30);

			//string name = "";
			//gotoXY(x + text.length() + 1, 5);
			//char c = char();
			//upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			//if (c == ENTER) {
			//	//delete[] sortedListSinhVien.nodes;
			//	clearIndexListLopTinChi(sortedListLopTinChiTheoNienKhoa);
			//	seachListLopTinChiTheoNienKhoa(listLopTinChiTheoNienKhoa, sortedListLopTinChiTheoNienKhoa, trim(name));
			//	//sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

			//	ShowCur(0);
			//	isInit = true;
			//	isLeftRight = true;
			//	isUpDown = true;
			//	isSearch = true;

			//}
			//else if (c == ESC) {
			//	ShowCur(0);
			//	setBackgroundColor(COLOR_BLACK);
			//	gotoXY(x + 1, 5);
			//	cout << generateSpace(50);
			//}
			break;
		}
		case F3: // 
		{

			break;
		}
		default:
			break;
		}

	}
}

//=================== BANG DIEM CUA LOP TC ===================
void bangDiemLTCTable(ListDangKy& listDangKy, IndexListDangKy& sortedListDangKy, bool isSearch, string tabletitle) {
	ShowCur(0);
	//titleBox(1, 3, "BANG DIEM LTC: " + tabletitle);
	titleBoxLeft(1, 3, "BANG DIEM LTC: " + tabletitle);
	int width = 20;
	int height = 2;
	int x = getCenterX(WIDTH_MAIN_FRAME, width * 7);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height * 13);
	int backgroundColor = COLOR_WHITE; // chinh mau vien table
	int textColor = COLOR_RED;
	setBackgroundColor(0);
	setTextColor(COLOR_WHITE);

	int currentIndex = 0;
	int row = 12;
	const int column = 5;
	string title[column] = { "STT", "MASV", "HO", "TEN", "DIEM"};
	int cellWidth[column] = { 10, 15, 30, 15, 15 };

	int iy = y + 2;

	for (int k = currentIndex; k < row; k++) {
		int ix = x;
		for (int j = 0; j < column; j++) {
			box3(ix, iy, cellWidth[j], height, backgroundColor, textColor, "");
			ix += cellWidth[j];
		}
		iy = iy + 2;
	}
	tableHeader(x, y, cellWidth, column, backgroundColor, textColor, title);
	tableFooter(x, iy + 1, cellWidth, column, backgroundColor, textColor, "");


	int keyBoxWidth = hotKeyBox(x + 1, iy + 2, "ESC", "QUAY LAI"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "INSERT", "THEM"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "ENTER", "CHON"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "DELETE", "XOA"); keyBoxWidth += 5;
	//keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "CTRL + F", "TIM KIEM"); keyBoxWidth += 5;
	keyBoxWidth += hotKeyBox(x + keyBoxWidth, iy + 2, "F3", "NHAP DIEM"); keyBoxWidth += 5;
	int xPage = x + 120 + 1;
	int yPage = iy + 2;

	int xPointer = x + 1;
	int yPointer = y + 3;
	int xPointerOld = xPointer;
	int yPointerOld = yPointer;
	int i = 0;
	int iOld = i;
	bool isUpDown = true;
	bool isLeftRight = true;
	bool isInit = false;
	bool isFromUp = false;

	while (true) {
		if (isInit) {
			setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			int iy = y + 3;
			for (int k = 0; k < row; k++) {
				int ix = xPointer;
				for (int j = 0; j < column; j++) {
					gotoXY(ix, iy);
					cout << generateSpace(cellWidth[j]);
					ix += cellWidth[j];
				}
				iy = iy + 2;
			}
			isInit = false;
		}

		if (!isSortedListDangKyEmpty(sortedListDangKy)) {
			if (isLeftRight) {
				setTextColor(COLOR_BRIGHT_WHITE);
				setBackgroundColor(COLOR_BLACK);

				int ix;
				int index;
				iy = y + 3;
				for (int k = currentIndex; k < row + currentIndex; k++) {
					if (k >= sortedListDangKy.number) break;
					else {
						index = sortedListDangKy.nodes[k].index;
						ix = x + 1;

						coutBox(ix, iy, cellWidth[0], TEXT_RIGHT, to_string(k + 1));
						ix += cellWidth[0];

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, sortedListDangKy.nodes[index].MASV);
						ix += cellWidth[1];
						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListDangKy.nodes[index].HO);
						ix += cellWidth[2];
						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListDangKy.nodes[index].TEN);
						ix += cellWidth[3];

						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, floatToStringMark(sortedListDangKy.nodes[index].DIEM));
						ix += cellWidth[4];
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage - 48, yPage);//-62 để thụt trang hiện tại vào trong
				cout << generateSpace(10);
				gotoXY(xPage - 48, yPage);//-62 để thụt trang hiện tại vào trong
				cout << "TRANG " << currentIndex / row + 1 << "/" << sortedListDangKy.number / row + 1;

				i = 0;
				iOld = i;
				yPointer = y + 3;
				yPointerOld = yPointer;
				if (isFromUp) {
					yPointer = y + 3 + 2 * (row - 1);
					yPointerOld = yPointer;
					i = row - 1;
					iOld = i;
					isFromUp = false;
				}
				isLeftRight = false;
			}

			if (isUpDown) {
				gotoXY(xPointerOld + cellWidth[0] + 1, yPointerOld);
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				int index = sortedListDangKy.nodes[iOld + currentIndex].index;
				cout << sortedListDangKy.nodes[index].MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListDangKy.nodes[i + currentIndex].index;
				cout << sortedListDangKy.nodes[index].MASV;

				xPointerOld = xPointer;
				yPointerOld = yPointer;

				isUpDown = false;

			}
		}

		char key = _getch();
		switch (key)
		{
		case -32: //DIEU HUONG, THEM, SUA LOP
		{
			key = _getch();
			if (key == LEFT && currentIndex != 0)
			{
				currentIndex -= row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == RIGHT && (currentIndex + row) < sortedListDangKy.number) {
				currentIndex += row;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else if (key == UP)
			{
				if (i == 0 && currentIndex != 0)
				{
					isLeftRight = true;
					isFromUp = true;
					isInit = true;
					currentIndex -= row;

				}
				else if (i > 0)
				{
					yPointer -= 2;
					iOld = i;
					i--;
				}
				isUpDown = true;
			}
			else if (key == DOWN && (i + currentIndex) < sortedListDangKy.number - 1)
			{
				if (i == row - 1) {
					isInit = true;
					isLeftRight = true;
					currentIndex += row;
				}
				else if (i < row)
				{
					yPointer += 2;
					iOld = i;
					i++;
				}
				isUpDown = true;
			}

			//
			else if (key == INSERT_KEY)
			{
				
			}

			//
			else if (key == DELETE_KEY /* && !isSortedListSinhVienEmpty(indexListLop)*/)
			{

			}
			break;
		}

		case ESC: //QUAY LAI
		{
			if (isSearch) {
				//ShowCur(0);
				//setBackgroundColor(COLOR_BLACK);
				//gotoXY(x + 1, 5);
				//cout << generateSpace(50);

				//clearIndexListDangKy(sortedListDangKy);
				//////delete[] indexListLop.nodes;
				////clearIndexListLop(indexListLop);
				////listLopToIndexListLop(listLop, indexListLop);
				//////sapXepListSinhVienTheoTen(indexListLop);

				//ShowCur(0);
				//isSearch = false;
				//isInit = true;
				//isLeftRight = true;
				//isUpDown = true;
			}
			else {
				/*delete[] indexListLop.nodes;
				clearConsole();
				menu(false);*/
				//delete[] indexListLop.nodes;
				clearIndexListDangKy(sortedListDangKy);

				IndexListLopTinChi sortedListLopTinChi;
				listLopTinChiToIndexListLopTinChi(listLopTinChi, sortedListLopTinChi);
				sapXepListLopTinChiNienKhoaDESC(sortedListLopTinChi);

				clearConsole();
				listLopTinChi_ChonLopTinChiTable(listLopTinChi, sortedListLopTinChi, false);

				//menu(false);
			}
			break;
		}

		case ENTER: //
		{
			
			break;
		}

		case CTRL_F: // TIM KIEM LOP
		{
			/*setTextColor(COLOR_BRIGHT_WHITE);
			setBackgroundColor(COLOR_BLACK);
			string text = "NHAP MA LOP: ";
			gotoXY(x + 1, 5);
			cout << text << generateSpace(30);

			string keyword = "";
			gotoXY(x + text.length() + 1, 5);
			char c = char();
			upperCaseWhileTypingEnter(x + text.length() + 1, 5, keyword, c);

			if (c == ENTER) {
				clearIndexListLop(indexListLop);
				searchListLopByMaLop(listLop, indexListLop, trim(keyword));

				ShowCur(0);
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
				isSearch = true;

			}
			else if (c == ESC) {
				ShowCur(0);
				setBackgroundColor(COLOR_BLACK);
				gotoXY(x + 1, 5);
				cout << generateSpace(50);
			}*/
			break;
		}
		case F3: // BAT DAU NHAP/ CHINH SUA DIEM
		{
			setBackgroundColor(COLOR_BLACK);
			int k = notificationPopUp("CHUC NANG NAY CHUA DUOC PHAT TRIEN");
			if (k == YES) {

			}

			clearConsole();
			bangDiemLTCTable(listDangKy, sortedListDangKy, isSearch, tabletitle);
			
			break;
		}
		default:
			break;
		}

	}

}
