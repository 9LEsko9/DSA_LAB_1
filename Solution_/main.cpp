#define _CRT_SECURE_NO_WARNINGS

#include "Solution.h"
#include "App.h"


int main(void) {
	Solution solt;
	App app(&solt, stdin, stdout, TypeOfString::CString);
	
	app.Run();
	return 0;
}