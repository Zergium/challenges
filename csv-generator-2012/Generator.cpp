#include "StdAfx.h"
#include "Generator.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

Generator::Generator(void)
{
}

Generator::~Generator(void)
{
}

void Generator::generate() {
	//std::wstring sBaseFileName(L"FileFöléФайл");
	std::wstring sBaseFileName(L"set");

	//types
	typedef std::vector<int> Vec;
	typedef Vec::const_iterator Itr;


	const bool bGenerateStringTables = false;

	//rows
	Vec vecRows;
	//vecRows.push_back(1000);
	//vecRows.push_back(50000);
	vecRows.push_back(100000);
	vecRows.push_back(200000);
	vecRows.push_back(500000);
	vecRows.push_back(1000000);
	vecRows.push_back(1500000);
	vecRows.push_back(2000000);
	vecRows.push_back(5000000);
	vecRows.push_back(7500000);
	vecRows.push_back(10000000);
	//vecRows.clear();
	//vecRows.push_back(100000);
	//for (int i=100000; i<350001; i+=50000) {
	//	vecRows.push_back(i);
	//}

	//columns
	Vec vecCols;
	vecCols.push_back(14);
	//for (int i=40; i<68; i+=1) {
	//	vecCols.push_back(i);
	//}

	//col width
	Vec vecColWidths;
	vecColWidths.push_back(12);
	//for (int i=12; i<64; i+=2) {
	//	vecColWidths.push_back(i);
	//}

	for (Itr itRow = vecRows.begin(); itRow != vecRows.end(); ++itRow) {
		for (Itr itCol = vecCols.begin(); itCol != vecCols.end(); ++itCol) {
			if (bGenerateStringTables) {
				for (Itr itWidth = vecColWidths.begin(); itWidth != vecColWidths.end(); ++itWidth) {
					//strings
					generateFile(*itRow, *itCol, *itWidth, true, false, sBaseFileName);
					generateFile(*itRow, *itCol, *itWidth, false, false, sBaseFileName);
				}
			}
			//numbers
			//generateFile(*itRow, *itCol, 1, true, true, sBaseFileName);
			//numbers
			generateFile(*itRow, *itCol, 12, true, true, sBaseFileName);
		}
	}
}

std::string wstr2str(const std::wstring& str) {
    const size_t iBufSize = str.length();
    size_t convertedChars = 0;
    char* pBuf = new char[iBufSize + 5];
	const wchar_t* pSrc = str.c_str();
	wcstombs_s(&convertedChars, pBuf, iBufSize, pSrc, _TRUNCATE);
	std::string result(pBuf);
	delete[] pBuf;
	return result;
}

void Generator::generateFile(int iRows, int iCols, int iColWidth, bool bUniqueRows, bool bNumeric, const std::wstring& sBaseFileName) {
	//prepare file name
	const int iKBytes = iCols * (iColWidth+1) * iRows / 1024;
	std::wstringstream ssFileName;
	ssFileName << sBaseFileName;
	ssFileName << "_" << (bUniqueRows?"uniq":"same");
	ssFileName << "_" << (bNumeric?"num":"str");
	ssFileName << "_" << std::setfill(L'0') << std::setw(8) << iRows << std::setw(0) << "Rx";
	ssFileName << iCols << "Cx" << iColWidth << "B";
	ssFileName << "_" << iKBytes << "KB";
	ssFileName << ".csv";

	//open a file for writing
	std::ofstream os(ssFileName.str().c_str(), std::ios::out);
	const int iBufSize = 32*1024*1024;
	char* pBuffer = new char[iBufSize];
	os.rdbuf()->pubsetbuf(pBuffer, iBufSize);

	std::cout << "Writing the \"" << wstr2str(ssFileName.str()) << "\"...";
	const clock_t timeStart = clock();

	const std::string COL_SEPARATOR = ";";
	
	//write header
	for (int iCol = 0; iCol < iCols; iCol++) {
		if (0 != iCol) {
			os << COL_SEPARATOR.c_str();
		}
		os << "Column " << (iCol+1);
	}
	os << std::endl;

	//write data
	for (int iRow = 0; iRow < iRows; iRow++) {
		for (int iCol = 0; iCol < iCols; iCol++) {
			if (0 != iCol) {
				os << COL_SEPARATOR.c_str();
			}

			std::stringstream ss;
			if (bNumeric) {
				ss << ( iCol+1 + (bUniqueRows ? iRow * iCols : 0));
				ss << ".0";
			} else {
				ss << "value-" << (iCol+1);
				if (bUniqueRows) {
					ss << "-" << (iRow+1);
				}
				ss << "-";
			}
			while (ss.tellp() < iColWidth) {
				ss << "0";
			}
			os << ss.str().c_str();
		}
		os << std::endl;
	}

	if (NULL != pBuffer) {
		delete[] pBuffer;
	}


	//close file
	os.close();

	float passedSeconds =((clock()-timeStart) / (CLOCKS_PER_SEC/10))/10.0f;
	std::cout << "done, " << passedSeconds << " seconds." << std::endl;
}