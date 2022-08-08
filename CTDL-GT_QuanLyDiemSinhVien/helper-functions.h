﻿#pragma once
#include "file-handling.h"
#include <iomanip>
#include <string>

using namespace std;
void listSinhVienTable(ListSinhVien& listSinhVien, IndexList& sortedListSinhVien, bool isSearch, char MALOP[15]);
void listLopTable2(ListLop& listLop, IndexListLop& indexListLop, bool isSearch);
int popUpThemSinhVien(ListSinhVien& listSinhVien, char MALOP[15]);
int popUpSuaSinhVien(ListSinhVien& listSinhVien, int indexSinhVien, IndexList& sortedListSinhVien);

ListSinhVien listSinhVien;
ListSinhVien listSinhVienTheoLop;
ListLop listLop;


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
		box(x, y + (i * 2), width, height, backgroundColor, textColor, text[i], TEXT_LEFT);
	}
}
void menu(boolean isInit) {
	ShowCur(0);
	int x = 2, y = 2, width = 50, height = 1;
	int textColor = 0;
	int backgroundColor = 14;
	int backgroundColorChoose = 15;

	if (isInit) {
		readFileSinhVien(listSinhVien, listLop);

		/*initProductList(productList);
		readProductFile(productList);*/
	}


	const int number = 12;
	string options[number] = {
		"1. QUAN LY LOP TIN CHI",
		"2. IN DSSV CON DANG KY LOP TIN CHI",
		"3. QUAN LY SINH VIEN",
		"4. QUAN LY MON HOC",
		"5. IN DANH SACH MON HOC",
		"6. DANG KY LOP TIN CHI",
		"7. HUY LOP TIN CHI",
		"8.NHAP DIEM",
		"09 IN BANG DIEM",
		"10. SINH VIEN HUY DANG KY",
		"11. IN DIEM TB KET THUC KHOA",
		"12. BANG DIEM TONG KET CUA CAC SV THUOC LOP",
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
			if (i == 0) { //QUAN LY VAT TU
				setBackgroundColor(COLOR_BLACK);

				//NodeIndexList sortedProductList;
				//productListToProductIndexList(productList, sortedProductList);
				//sortProductListByName(sortedProductList);

				clearConsole();
				//productTable(productList, sortedProductList, false);
			}
			else if (i == 1) { //QUAN LY SINH VIEN
				setBackgroundColor(COLOR_BLACK);



			}

			else if (i == 2) { //QUAN LY SINH VIEN
				setBackgroundColor(COLOR_BLACK);

				/*IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(listSinhVien, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);



				clearConsole();
				listSinhVienTable(listSinhVien, sortedListSinhVien, false);*/

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLopTable2(listLop, indexListLop, false);

			}

			else if (i == 3) { //IN HOA DON
				setBackgroundColor(COLOR_BLACK);
				clearConsole();
				/*invoicePopUp(productList, employeeList);*/
			}

			else if (i == 4) { //THONG KE HOA DON
				setBackgroundColor(COLOR_BLACK);
				clearConsole();
				//statisticialPopUp(employeeList);
			}

			else if (i == 5) { //TOP DOANH THU
				setBackgroundColor(COLOR_BLACK);
				clearConsole();
				//salesPopUp(productList, employeeList);
			}

			else if (i == 6) { //THOAT CHUONG TRINH
				clearConsole();
				setBackgroundColor(COLOR_BLACK);
				setTextColor(COLOR_BRIGHT_WHITE);
				//for (int i = 0; i < employeeList.number; i++) {
				//	delete employeeList.employee[i];
				//}
				exit(0);
			}
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == UP && i != 0)
			{
				yPointer -= 2;
				if (i > 0)
				{
					iOld = i;
					i--;
				}
				isClicked = true;
			}
			else if (c == DOWN && i != (number - 1))
			{
				yPointer += 2;
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
void listSinhVienTable(ListSinhVien& listSinhVien, IndexList& sortedListSinhVien, bool isSearch, char MALOP [15]) {
	ShowCur(0);
	titleBox(1, 3, "QUAN LY SINH VIEN");
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
	const int column = 7;
	string title[column] = { "STT", "MASV", "HO", "TEN", "PHAI", "SDT", "MALOP" };
	int cellWidth[column] = { 10, 20, 25, 15, 10, 15, 20 };

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

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listSinhVien.sinhvien[index].MASV);
						ix += cellWidth[1];

						coutBox(ix, iy, cellWidth[2], TEXT_LEFT, sortedListSinhVien.nodes[k].HO);
						ix += cellWidth[2];

						coutBox(ix, iy, cellWidth[3], TEXT_LEFT, sortedListSinhVien.nodes[k].TEN);
						ix += cellWidth[3];

						string strPhai = "Nam";
						if (listSinhVien.sinhvien[index].PHAI != true) {
							strPhai = "Nu";
						}
						coutBox(ix, iy, cellWidth[4], TEXT_LEFT, strPhai);
						ix += cellWidth[4];

						coutBox(ix, iy, cellWidth[5], TEXT_LEFT, listSinhVien.sinhvien[index].SODT);
						ix += cellWidth[5];

						coutBox(ix, iy, cellWidth[6], TEXT_LEFT, listSinhVien.sinhvien[index].MALOP);
						ix += cellWidth[6];
					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage, yPage);
				cout << generateSpace(10);
				gotoXY(xPage, yPage);
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
				cout << listSinhVien.sinhvien[index].MASV;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = sortedListSinhVien.nodes[i + currentIndex].index;
				cout << listSinhVien.sinhvien[index].MASV;

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
						listSinhVienToListIndexSinhVien(listSinhVien, sortedListSinhVien);
						sapXepListSinhVienTheoTen(sortedListSinhVien);

						clearConsole();
						listSinhVienTable(listSinhVien, sortedListSinhVien, false, MALOP);
					}
				}

				clearConsole();
				//employeeTable(employeeList, sortedListSinhVien, isSearch);
			}

			//XOA SINH VIEN
			else if (key == DELETE_KEY && !isSortedListSinhVienEmpty(sortedListSinhVien))
			{
				string message = "BAN MUON XOA SINH VIEN NAY?";
				bool isAccepted = warningPopUp(message);
				int index = sortedListSinhVien.nodes[i + currentIndex].index;
				if (isAccepted)
				{
					//------- sau này bắt trường hợp sinh viên đã có điểm
					/*if (isEmployeeHasInvoiceList(*employeeList.employee[index])) {
						string message = "SINH VIEN NAY DA LAP HOA DON, KHONG XOA DUOC.";
						int t = notificationPopUp(message);
						if (t == YES) {};
					}*/ 
					//else {//
						xoaSinhVienTheoMaSV(listSinhVien, listSinhVien.sinhvien[index].MASV);
						//writeEmployeeFile(employeeList);

						//delete[] sortedListSinhVien.nodes;
						clearIndexListSinhVien(sortedListSinhVien);
						listSinhVienToListIndexSinhVien(listSinhVien, sortedListSinhVien);
						sapXepListSinhVienTheoTen(sortedListSinhVien);

						clearConsole();
						listSinhVienTable(listSinhVien, sortedListSinhVien, false, MALOP);
					//}
				}
				//writeEmployeeFile(employeeList);
				clearConsole();
				listSinhVienTable(listSinhVien, sortedListSinhVien, isSearch, MALOP);
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

				listSinhVienToListIndexSinhVien(listSinhVien, sortedListSinhVien);
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

				IndexListLop indexListLop;
				listLopToIndexListLop(listLop, indexListLop);

				clearConsole();
				listLopTable2(listLop, indexListLop, false);

				//menu(false);
			}
			break;
		}

		case ENTER: // SUA SINH VIEN TRONG DANH SACH SINH VIEN
		{
			if (!isSortedListSinhVienEmpty(sortedListSinhVien))
			{
				int index = sortedListSinhVien.nodes[i + currentIndex].index;
				int k = popUpSuaSinhVien(listSinhVien, index, sortedListSinhVien);
				if (k == YES) { // DA HIEU CHINH SINH VIEN
					clearConsole();
					listSinhVienTable(listSinhVien, sortedListSinhVien, false, MALOP);
				}
				else {//NHAN ESC
					clearConsole();
					listSinhVienTable(listSinhVien, sortedListSinhVien, isSearch, MALOP);
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
			//upperCaseWhileTypingEnter(x + text.length() + 1, 5, name, c);

			if (c == ENTER) {
				delete[] sortedListSinhVien.nodes;
				//searchEmployeeListByName(employeeList, sortedListSinhVien, trim(name));

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


string convertToString(char* a)
{
	string s = a;
	return s;
}

//=================== THEM SINH VIEN ===================
int popUpThemSinhVien(ListSinhVien& listSinhVien, char MALOP [15]) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = 40;

	//char MASV[15]; /*= generateEmployeeId(employeeList);*/
	//char HO[30];
	//char TEN[10];
	//bool PHAI;
	//char SODT[15];
	
	string MASV_STR; /*= generateEmployeeId(employeeList);*/
	string HO_STR;
	string TEN_STR;
	string PHAI_STR;
	string SODT_STR;

	//ve bang pop up
	box(x, y, width, height, COLOR_WHITE, COLOR_BLACK, "", TEXT_CENTER);
	box(x, y, width, 1, COLOR_RED, COLOR_BRIGHT_WHITE, "THEM SINH VIEN VAO LOP "+ convertToString(MALOP), TEXT_CENTER);
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
			box(xInput, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
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
				box(xPointer, y + height - 6, widthInput, 5, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);

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

					if (PHAI_STR.compare("NAM")==0) {
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
int popUpSuaSinhVien(ListSinhVien& listSinhVien, int indexSinhVien, IndexList& sortedListSinhVien) {
	ShowCur(1);
	int height = HEIGHT_POP_UP;
	int width = WIDTH_POP_UP;
	int x = getCenterX(WIDTH_MAIN_FRAME, width);
	int y = getCenterY(HEIGHT_MAIN_FRAME, height);
	int xInput = x + 18;
	int widthInput = 40;
	const int number = 4; // số input field

	string oldMASV = listSinhVien.sinhvien[indexSinhVien].MASV;
	string MASV_STR = listSinhVien.sinhvien[indexSinhVien].MASV;
	string HO_STR = listSinhVien.sinhvien[indexSinhVien].HO;
	string TEN_STR = listSinhVien.sinhvien[indexSinhVien].TEN;
	string PHAI_STR = listSinhVien.sinhvien[indexSinhVien].PHAI == true? "NAM":"NU";
	string SODT_STR = listSinhVien.sinhvien[indexSinhVien].SODT;
	string MALOP_STR = listSinhVien.sinhvien[indexSinhVien].MALOP;


	string title[number] = { /*"MASV",*/ "HO", "TEN", "PHAI", "SODT" /*MALOP*/}; // không cho sửa MASV, MALOP
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

			box(xInput, y + 2 * (i + 1), widthInput, 1, COLOR_BLACK, COLOR_LIGHT_YELLOW, data[i], TEXT_LEFT);
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
				box(xPointer, y + height - 6, widthInput, 5, COLOR_RED, COLOR_LIGHT_YELLOW, "", TEXT_CENTER);
				
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

					strcpy_s(listSinhVien.sinhvien[indexSinhVien].HO, trim(HO_STR).c_str());
					strcpy_s(listSinhVien.sinhvien[indexSinhVien].TEN, trim(TEN_STR).c_str());
					strcpy_s(listSinhVien.sinhvien[indexSinhVien].SODT, trim(SODT_STR).c_str());

					if (trim(PHAI_STR).compare("NAM") == 0) {
						listSinhVien.sinhvien[indexSinhVien].PHAI = true;
					}
					else if (trim(PHAI_STR).compare("NU") == 0) {
						listSinhVien.sinhvien[indexSinhVien].PHAI = false;
					}

						for (int l = 0; l < sortedListSinhVien.number; l++) {
							if (sortedListSinhVien.nodes[l].index == indexSinhVien) {

								strcpy_s(sortedListSinhVien.nodes[indexSinhVien].HO, trim(HO_STR).c_str());
								strcpy_s(sortedListSinhVien.nodes[indexSinhVien].TEN, trim(TEN_STR).c_str());
								
								break;
							}
						}
						sapXepListSinhVienTheoTen(sortedListSinhVien);
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
			if (i == 0) upperCaseWhileTyping(xPointer, yPointer, HO_STR, c);
			else if (i == 1) upperCaseWhileTyping(xPointer, yPointer, TEN_STR, c);
			else if (i == 2) upperCaseWhileTyping(xPointer, yPointer, PHAI_STR, c);
			else if (i == 3) upperCaseWhileTyping(xPointer, yPointer, SODT_STR, c);
			break;
		}
		}
	}
}

//=================== BANG LOP2 ===================
void listLopTable2(ListLop& listLop, IndexListLop& indexListLop, bool isSearch) {
	ShowCur(0);
	titleBox(1, 3, "CHON LOP DE XEM");
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
	int cellWidth[column] = { 10, 60 };

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

						coutBox(ix, iy, cellWidth[1], TEXT_LEFT, listLop.lop[index].MALOP);
						ix += cellWidth[1];

					}
					iy = iy + 2;
				}

				setTextColor(COLOR_LIGHT_YELLOW);
				gotoXY(xPage, yPage);
				cout << generateSpace(10);
				gotoXY(xPage, yPage);
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
				cout << listLop.lop[index].MALOP;

				gotoXY(xPointer + cellWidth[0] + 1, yPointer);
				setBackgroundColor(COLOR_RED);
				setTextColor(COLOR_LIGHT_YELLOW);
				index = indexListLop.nodes[i + currentIndex].index;
				cout << listLop.lop[index].MALOP;

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

			//THEM LOP
			else if (key == INSERT_KEY)
			{
				//if (isListSinhVienFull(listSinhVien)) { //DANH SACH SINH VIEN DA DAY
				//	string message = "DANH SACH SINH VIEN DA DAY";
				//	int k = notificationPopUp(message);
				//	if (k == YES) {}
				//}
				//else { //DANH SACH SINH VIEN CHUA DAY
				//	/*int k = addEmployeePopUp(employeeList);
				//	if (k == YES) {
				//		delete[] indexListLop.nodes;
				//		employeeListToEmployeeIndexList(employeeList, indexListLop);
				//		sortEmployeeListByName(indexListLop);

				//		clearConsole();
				//		employeeTable(employeeList, indexListLop, false);
				//	}*/
				//}

				//clearConsole();
				//employeeTable(employeeList, indexListLop, isSearch);
			}

			//XOA LOP
			else if (key == DELETE_KEY /* && !isSortedListSinhVienEmpty(indexListLop)*/)
			{
				/*string message = "BAN MUON XOA SINH VIEN NAY?";
				bool isAccepted = warningPopUp(message);
				int index = indexListLop.nodes[i + currentIndex].index;
				if (isAccepted)
				{
					if (isEmployeeHasInvoiceList(*employeeList.employee[index])) {
						string message = "SINH VIEN NAY DA LAP HOA DON, KHONG XOA DUOC.";
						int t = notificationPopUp(message);
						if (t == YES) {};
					}
					else {
						deleteEmployee(employeeList, employeeList.employee[index]->employeeId);
						writeEmployeeFile(employeeList);

						delete[] indexListLop.nodes;
						employeeListToEmployeeIndexList(employeeList, indexListLop);
						sortEmployeeListByName(indexListLop);

						clearConsole();
						employeeTable(employeeList, indexListLop, false);
					}
				}
				writeEmployeeFile(employeeList);
				clearConsole();
				employeeTable(employeeList, indexListLop, isSearch);*/
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
				//sapXepListSinhVienTheoTen(indexListLop);

				ShowCur(0);
				isSearch = false;
				isInit = true;
				isLeftRight = true;
				isUpDown = true;
			}
			else {
				/*delete[] indexListLop.nodes;
				clearConsole();
				menu(false);*/
				//delete[] indexListLop.nodes;
				clearIndexListLop(indexListLop);
				clearConsole();
				menu(false);
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

			if (!isIndexListLopEmpty(indexListLop)) {
				int index = indexListLop.nodes[i + currentIndex].index;
				char MA_LOP_SELECTED[15];
				strcpy_s(MA_LOP_SELECTED, listLop.lop[index].MALOP);

				clearListSinhVien(listSinhVienTheoLop);

				locSinhVienTheoLop(listSinhVienTheoLop, listSinhVien, MA_LOP_SELECTED);

				IndexList sortedListSinhVien;
				listSinhVienToListIndexSinhVien(listSinhVienTheoLop, sortedListSinhVien);
				sapXepListSinhVienTheoTen(sortedListSinhVien);

				clearConsole();
				listSinhVienTable(listSinhVienTheoLop, sortedListSinhVien, false, MA_LOP_SELECTED);
			}
			break;
		}

		case CTRL_F: // TIM KIEM LOP
		{
			setTextColor(COLOR_BRIGHT_WHITE);
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
			}
			break;
		}

		default:
			break;
		}

	}

}
