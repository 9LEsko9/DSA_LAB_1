#pragma once

#if _WIN32

#include <windows.h>

#endif

#include "ISolution.h"
#include <iostream>


class App
{
private:
	char buffer[4096] = {0};
	unsigned buffer_size = 4096;

	ISolution* SolutionAlgorithm;

	TypeOfString _type;

	FILE* InputStream = NULL;
	FILE* OutputStream = NULL;

public:
	App(ISolution* sol_alg, FILE* istream, FILE* ostream, TypeOfString type_string) :
		SolutionAlgorithm(sol_alg), InputStream(istream), OutputStream(ostream), _type(type_string) {
	};

	~App() = default;
	
	void Run();

};


