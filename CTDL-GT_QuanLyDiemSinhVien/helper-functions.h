#pragma once
#include "struct.h"
#include <rpcndr.h>
#include "mylib.h"
#include <iomanip> 

using namespace std;
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
		gotoXY(x, y + height / 2);
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
		box(x, y + (i * 4), width, height, backgroundColor, textColor, text[i], TEXT_CENTER);
	}
}
void menu(boolean isInit) {
	ShowCur(0);
	int x = 2, y = 1, width = 40, height = 1;
	int textColor = 0;
	int backgroundColor = 14;
	int backgroundColorChoose = 15;

	if (isInit) {
	/*	readEmployeeFile(employeeList);

		initProductList(productList);
		readProductFile(productList);*/
	}

	
	const int number = 13;
	string options[number] = {
		"1. QUAN LY LOP TIN CHI",
		"2. IN DSSV CON DANG KY LOP TIN CHI",
		"3. QUAN LY SINH VIEN",
		"4. IN DANH SACH SINH VIEN",
		"5. QUAN LY MON HOC",
		"6. IN DANH SACH MON HOC",
		"7. DANG KY LOP TIN CHI",
		"8. HUY LOP TIN CHI",
		"9. NHAP DIEM",
		"10. IN BANG DIEM",
		"11. SINH VIEN HUY DANG KY",
		"12. IN DIEM TB KET THUC KHOA",
		"13. BANG DIEM TONG KET CUA CAC SV THUOC LOP",
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
			box(xPointerOld, yPointerOld, width, height, backgroundColor, textColor, options[iOld], TEXT_CENTER);
			box(xPointer, yPointer, width, height, backgroundColorChoose, textColor, options[i], TEXT_CENTER);
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
			else if (i == 1) { //QUAN LY NHAN VIEN
				setBackgroundColor(COLOR_BLACK);

			/*	IndexList sortedEmployeeList;
				employeeListToEmployeeIndexList(employeeList, sortedEmployeeList);
				sortEmployeeListByName(sortedEmployeeList);*/

				clearConsole();
				//employeeTable(employeeList, sortedEmployeeList, false);
			}

			else if (i == 2) { //TAO HOA DON MOI
				//Invoice invoice;
				setBackgroundColor(COLOR_BLACK);
				clearConsole();
				//InvoiceDetailList invoiceDetailList;/*
				//addInvoicePopUp(productList, employeeList, -1);*/
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