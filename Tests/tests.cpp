#define _CRT_SECURE_NO_WARNINGS

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "App.h"
#include "ISolution.h"
#include "Solution.h"

#include <sstream>

bool CStringStdinStdoutEN() {
	FILE* input = fopen("test_input.txt", "w");
	if (!input) return false;

	const char* test_string = "Test2XSt 0r3i 8ng1";
	fputs(test_string, input);
	fclose(input);
	
	input = fopen("test_input.txt", "r");
	FILE* output = fopen("test_output.txt", "w");
	if (!input && !output) return false;

	Solution solt;
	App app(&solt, input, output, TypeOfString::CString);
	app.Run();

	output = fopen("test_output.txt", "r");
	char result[4096] = { 0 };
	fgets(result, 4096, output);
	fclose(output);

	const char * expected_result = "TestTWOXSt ZEROr#6i EIGHTng#2";

	return strcmp(expected_result, result) == 0;
}


bool CStringStdinStdoutRU() {
	FILE* input = fopen("test_input.txt", "w");
	if (!input) return false;

	const char* test_string = "Привет, мир 1002 34!";
	fputs(test_string, input);
	fclose(input);

	input = fopen("test_input.txt", "r");
	FILE* output = fopen("test_output.txt", "w");
	if (!input && !output) return false;

	Solution solt;
	App app(&solt, input, output, TypeOfString::CString);
	app.Run();

	output = fopen("test_output.txt", "r");
	char result[4096] = { 0 };
	fgets(result, 4096, output);
	fclose(output);

	const char* expected_result = "Привет, мир #2ZEROZEROTWO #6FOUR!";

	return strcmp(expected_result, result) == 0;
}

bool StringStdinStdoutEN() {
	FILE* input = fopen("test_input.txt", "w");
	if (!input) return false;

	const char test_string[] = {'A', '2', '3', '1'};
	fwrite(test_string, 1, sizeof(test_string), input);
	fclose(input);

	input = fopen("test_input.txt", "r");
	FILE* output = fopen("test_output.txt", "w");
	if (!input && !output) return false;

	Solution solt;
	App app(&solt, input, output, TypeOfString::CString);
	app.Run();

	output = fopen("test_output.txt", "r");
	char result[4096] = { 0 };
	fgets(result, 4096, output);
	fclose(output);

	const char* expected_result = "ATWO#6#2";

	return strcmp(expected_result, result) == 0;
}

bool StringStdinStdoutRU() {
	FILE* input = fopen("test_input.txt", "w");
	if (!input) return false;

	const char test_string[] = { 'П', '2', 'Р', '3', '1' };
	fwrite(test_string, 1, sizeof(test_string), input);
	fclose(input);

	input = fopen("test_input.txt", "r");
	FILE* output = fopen("test_output.txt", "w");
	if (!input && !output) return false;

	Solution solt;
	App app(&solt, input, output, TypeOfString::CString);
	app.Run();

	output = fopen("test_output.txt", "r");
	char result[4096] = { 0 };
	fgets(result, 4096, output);
	fclose(output);

	const char* expected_result = "ПTWOР#6#2";

	return strcmp(expected_result, result) == 0;
}

TEST_CASE("C String FILE Pointer input english", "[CStringStdinStdoutEN]") {
	REQUIRE(CStringStdinStdoutEN() == true);
}

TEST_CASE("C String FILE Pointer input russian", "[CStringStdinStdoutRU]") {
	REQUIRE(CStringStdinStdoutRU() == true);
}

TEST_CASE("String FILE Pointer input english", "[CStringStdinStdoutEN]") {
	REQUIRE(StringStdinStdoutEN() == true);
}
TEST_CASE("String FILE Pointer input russian", "[CStringStdinStdoutRU]") {
	REQUIRE(StringStdinStdoutRU() == true);
}