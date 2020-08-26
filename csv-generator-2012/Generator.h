#pragma once

#include <string>

class Generator
{
public:
	Generator(void);
	virtual ~Generator(void);

public:
	void generate();

public:
	void generateFile(int iRows, int iCols, int iColWidth, bool bUniqueRows, bool bNumeric, const std::wstring& sBaseFileName);
};
