#pragma once
#include <cstdio>

enum TypeOfString {
	CString,
	String,
};

class ISolution
{
public:
	virtual int useSolutionAlghorithm(char buffer[], TypeOfString type_string, unsigned buffer_size, unsigned real_size) = 0;
	virtual ~ISolution() {};
};

