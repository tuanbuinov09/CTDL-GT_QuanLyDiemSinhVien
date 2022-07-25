#pragma once
#include "SinhVienHandler.h"
#include <fstream>
#include <string>
using namespace std;
//=================== DOC FILE SINH VIEN ===================
void readFileSinhVien(ListSinhVien& listSinhVien) {
	//ifstream fileIn;
	//fileIn.open("DSSV.txt", ios_base::in);
	//int fileSinhVienPointer = 0;

	//if (fileIn.fail()) return;
	//if (fileIn.peek() == fstream::traits_type::eof()) {
	//	return;
	//}
	//while (fileIn.eof() != true)
	//{
	//	string sinhVienNumberString;
	//	SinhVien sinhVien;
	//	string temp;
	//	getline(fileIn, temp, '|');
	//	if (temp.compare("") == 0) break;//stricmp compare char array
	//	strcpy_s(sinhVien.MASV, temp.c_str());

	//	getline(fileIn, temp, '|');
	//	strcpy_s(sinhVien.HO, temp.c_str());
	//	getline(fileIn, temp, '|');
	//	strcpy_s(sinhVien.TEN, temp.c_str());
	//	getline(fileIn, temp, '|');
	//	strcpy_s(sinhVien.MALOP, temp.c_str());
	//	getline(fileIn, temp, '|');
	//	sinhVien.PHAI = stoi(temp); // chueyern sang int
	//	getline(fileIn, temp, '|');
	//	strcpy_s(sinhVien.SODT, temp.c_str());

	//	getline(fileIn, sinhVienNumberString, '|');
	//	int invoiceNumber = stoi(sinhVienNumberString);

	//	insertSinhVienOrder(listSinhVien, sinhVien);
	//	fileIn.ignore();
	//}
	//fileIn.close();


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
			fileIn.ignore();
	}
	fileIn.close();
}