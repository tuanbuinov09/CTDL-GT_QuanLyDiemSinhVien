#pragma once
#include "SinhVienHandler.h"
#include <fstream>
#include <string>
#include "LopHandler.h"
#include "LopTinChiHandler.h"
#include "MonHocHandler.h"
#include "DangKyHandler.h"
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
		sinhVien.PHAI = stoi(temp);
		
		/*sinhVien.PHAI = false;
		if (stoi(temp) == 0) {
			sinhVien.PHAI = false;
		}*/

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

//=================== DOC FILE DANH SACH DANG KY ===================
void readFileDanhsachDangKyTheoLopTinChi(LopTinChi& lopTinChi) {
	ifstream fileIn;
	fileIn.open("data/DSDK.txt", ios_base::in);

	if (fileIn.fail()) return;
	if (fileIn.peek() == fstream::traits_type::eof()) {
		return;
	}
	while (fileIn.eof() != true)
	{
		DangKy dangky;
		string temp;
		getline(fileIn, temp, '|');
		if (temp.compare("") == 0) break;//stricmp compare char array
		int maltc = stoi(temp);
		//
		//int flag = 0;
		//if (maltc == 7) {
		//	flag = 1;
		//}
		getline(fileIn, temp, '|');
		strcpy_s(dangky.MASV, temp.c_str());

		getline(fileIn, temp);
		 
			dangky.DIEM = stof(temp);// stof chuyeenr thanh float // nếu = -99 thì sinh viên chưa có điểm
		
		if (maltc == lopTinChi.MALOPTC)
		{
			themVaoListDangKy(lopTinChi.DSDK, dangky);
		}
		//fileIn.ignore();// dùng khi dòng có ngăn cách ở cuối cùng, bỏ qua 1 kí tự ấy // ví dụ nếu a|b|cd| thì cần, a|b|cd thì k
	}
	fileIn.close();
}

int readFileLopTinChi(DSLOPTINCHI& listLopTinChi) {

	ifstream fileIn;
	fileIn.open("data/DSLOPTC.txt", ios_base::in);

	if (fileIn.fail()) return 0;
	if (fileIn.peek() == fstream::traits_type::eof()) {
		return 0;
	}

	int maxMALOPTC = 0;
	while (fileIn.eof() != true)
	{
		LopTinChi lopTinChi;
		string temp;
		getline(fileIn, temp, '|');
		if (temp.compare("") == 0) break;//stricmp compare char array
		lopTinChi.MALOPTC = stoi(temp);// stoi chuyeenr thanh int
		maxMALOPTC = lopTinChi.MALOPTC;
		getline(fileIn, temp, '|');
		strcpy_s(lopTinChi.MAMH, temp.c_str());

		getline(fileIn, temp, '|');
		strcpy_s(lopTinChi.NIENKHOA, temp.c_str());

		getline(fileIn, temp, '|');
		lopTinChi.HOCKY = stoi(temp);

		getline(fileIn, temp, '|');
		lopTinChi.NHOM = stoi(temp);

		getline(fileIn, temp, '|');
		lopTinChi.MINSV = stoi(temp);

		getline(fileIn, temp, '|');
		lopTinChi.MAXSV = stoi(temp);

		getline(fileIn, temp);
		lopTinChi.HUYLOP = false;
		if (stoi(temp) == 1) {
			lopTinChi.HUYLOP = true;
		}
		lopTinChi.DSDK = initListDangKy();

		readFileDanhsachDangKyTheoLopTinChi(lopTinChi);
		insertLopTinChiOrderByMaLTC(listLopTinChi, lopTinChi);
		//fileIn.ignore();// dùng khi dòng có ngăn cách ở cuối cùng, bỏ qua 1 kí tự ấy // ví dụ nếu a|b|cd| thì cần, a|b|cd thì k
	}
	return maxMALOPTC; // trả về maxMALOPTC
	fileIn.close();
}

//=================== GHI FILE SINH VIEN ===================
void writeFileSinhVien(ListSinhVien& listSinhVien) {
	fstream fileDSSVOut;
	fileDSSVOut.open("data/DSSV.txt", ios_base::out);

	if (fileDSSVOut.fail()) return;
	for (int i = 0; i < listSinhVien.number; i++)
	{
		SinhVien sinhvien = listSinhVien.sinhvien[i];

		fileDSSVOut << sinhvien.MASV << "|";
		fileDSSVOut << sinhvien.HO << "|";
		fileDSSVOut << sinhvien.TEN << "|";
		fileDSSVOut << sinhvien.MALOP << "|";
		fileDSSVOut << sinhvien.PHAI << "|";
		fileDSSVOut << sinhvien.SODT;

		if (i == listSinhVien.number - 1) break;
		fileDSSVOut << endl;
	}
	fileDSSVOut.close();
}


//=================== GHI FILE LOP TIN CHI ===================
void writeFileLopTinChi(DSLOPTINCHI& listLopTinChi) { // ghi cả dsdk
	fstream fileDSLTCOut;
	fileDSLTCOut.open("data/DSLOPTC.txt", ios_base::out);
	fstream fileDSDKOut;
	fileDSDKOut.open("data/DSDK.txt", ios_base::out);

	if (fileDSLTCOut.fail()) return;
	for (int i = 0; i < listLopTinChi.number; i++)
	{
		LopTinChi lopTinChi = *listLopTinChi.loptinchi[i];

		fileDSLTCOut << lopTinChi.MALOPTC << "|";
		fileDSLTCOut << lopTinChi.MAMH << "|";
		fileDSLTCOut << lopTinChi.NIENKHOA << "|";
		fileDSLTCOut << lopTinChi.HOCKY << "|";
		fileDSLTCOut << lopTinChi.NHOM << "|";
		fileDSLTCOut << lopTinChi.MINSV << "|";
		fileDSLTCOut << lopTinChi.MAXSV << "|";
		fileDSLTCOut << lopTinChi.HUYLOP;

		//=================== GHI FILE DSDK ===================
		for (NodeDK* p = lopTinChi.DSDK; p != NULL; p = p->next)
		{
			fileDSDKOut << lopTinChi.MALOPTC << "|";
			fileDSDKOut << p->dangky.MASV << "|";
			fileDSDKOut << p->dangky.DIEM;
			fileDSDKOut << endl;
		}
		if (i == listLopTinChi.number - 1) break;
		fileDSLTCOut << endl;
	}
	fileDSLTCOut.close();
}

//=================== GHI FILE MON HOC ===================
void writeFileMonHocNLR(TREE& treeMonhoc, fstream& monHocFileOut) {
	if (treeMonhoc != NULL) {
		monHocFileOut << treeMonhoc->MH.MAMH << "|";
		monHocFileOut << treeMonhoc->MH.STCLT << "|";
		monHocFileOut << treeMonhoc->MH.STCTH << "|";
		monHocFileOut << treeMonhoc->MH.TENMH;
		monHocFileOut << endl;

		writeFileMonHocNLR(treeMonhoc->left, monHocFileOut);
		writeFileMonHocNLR(treeMonhoc->right, monHocFileOut);
	}

}

void writeFileMonHoc(TREE& treeMonhoc) {
	fstream fileMonHocOut;
	fileMonHocOut.open("data/DSMH.txt", ios_base::out);
	if (fileMonHocOut.fail()) return;

	writeFileMonHocNLR(treeMonhoc, fileMonHocOut);
	fileMonHocOut.close();
}