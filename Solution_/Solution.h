#pragma once
#include "ISolution.h"
#include <cctype>
#include <cstring>
#include <stdlib.h>

class Solution : public ISolution
{
private:

	int CStringSolution(char* buffer,unsigned buffer_size, unsigned real_size);
	int StringSolution(char* buffer, unsigned buffer_size, unsigned real_size);

public:
	Solution() = default;
	~Solution() = default;

	int useSolutionAlghorithm(char buffer[], TypeOfString type_string,
		unsigned buffer_size, unsigned real_size) override;

};

