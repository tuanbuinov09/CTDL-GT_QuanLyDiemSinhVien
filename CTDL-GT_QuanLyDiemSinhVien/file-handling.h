#pragma once
#include "SinhVienHandler.h"
#include <fstream>
#include <string>
#include "LopHandler.h"
#include "MonHocHandler.h"
using namespace std;



//=================== DOC FILE SINH VIEN ===================
void readFileSinhVien(ListSinhVien& listSinhVien, ListLop& listLop) {
	
	ifstream fileIn;
	fileIn.open("data/DSSV.txt", ios_base::in);

	if (fileIn.fail()) return;
	if (fileIn.peek() == fstream::traits_type::eof()) {
		return;
	}
	while (fileIn.eof() != true)
	{
		//string sinhVienNumberString;
			SinhVien sinhVien;
			string temp;
			getline(fileIn, temp, '|');
			if (temp.compare("") == 0) break;//stricmp compare char array
			strcpy_s(sinhVien.MASV, temp.c_str());

			getline(fileIn, temp, '|');
			strcpy_s(sinhVien.HO, temp.c_str());

			getline(fileIn, temp, '|');
			strcpy_s(sinhVien.TEN, temp.c_str());

			getline(fileIn, temp, '|');
			strcpy_s(sinhVien.MALOP, temp.c_str());

			Lop lop;

			strcpy_s(lop.MALOP, sinhVien.MALOP);
			insertLopOrder(listLop, lop);

			getline(fileIn, temp, '|');
			sinhVien.PHAI = true;
			if (stoi(temp) == 0) {
				sinhVien.PHAI = false;
			}

			getline(fileIn, temp);//sdt ở cuối k cần '|'
			strcpy_s(sinhVien.SODT, temp.c_str());

			//getline(fileIn, sinhVienNumberString, '|');
			//int invoiceNumber = stoi(sinhVienNumberString);

			insertSinhVienOrder(listSinhVien, sinhVien);

			//fileIn.ignore();// dùng khi dòng có ngăn cách ở cuối cùng, bỏ qua 1 kí tự ấy // ví dụ nếu a|b|cd| thì cần, a|b|cd thì k
	}
	fileIn.close();
}

void readFileMonHoc(TREE& treeMonHoc) {

	ifstream fileIn;
	fileIn.open("data/DSMH.txt", ios_base::in);

	if (fileIn.fail()) return;
	if (fileIn.peek() == fstream::traits_type::eof()) {
		return;
	}
	while (fileIn.eof() != true)
	{
		//string sinhVienNumberString;
		MonHoc monHoc;
		string temp;
		getline(fileIn, temp, '|');
		if (temp.compare("") == 0) break;//stricmp compare char array
		strcpy_s(monHoc.MAMH, temp.c_str());

		getline(fileIn, temp, '|');
		monHoc.STCLT = stoi(temp);// stoi chuyeenr thanh int

		getline(fileIn, temp, '|');
		monHoc.STCTH = stoi(temp);

		getline(fileIn, temp);//tên mh ở cuối k cần '|'
		strcpy_s(monHoc.TENMH, temp.c_str());

		//getline(fileIn, sinhVienNumberString, '|');
		//int invoiceNumber = stoi(sinhVienNumberString);

		themMonHocVaoCay(treeMonHoc, monHoc);
		//fileIn.ignore();// dùng khi dòng có ngăn cách ở cuối cùng, bỏ qua 1 kí tự ấy // ví dụ nếu a|b|cd| thì cần, a|b|cd thì k

	}
	fileIn.close();
}