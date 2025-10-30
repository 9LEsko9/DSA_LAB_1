#include "App.h"

void App::Run() {
#if _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	unsigned real_size = 0;

	if (!InputStream || !OutputStream) {
		std::cout << "Wrong Input/Output stream, please set correct IO streams" << std::endl;
		return;
	};

	if (fgets(buffer, buffer_size, InputStream) == nullptr) {
		std::cout << "Failed to read data from input stream" << std::endl;
		return;
	};

	while (buffer[real_size] != 0) {
		real_size++;
	}

	if (SolutionAlgorithm->useSolutionAlghorithm(buffer, _type, buffer_size, real_size) == -1) {
		std::cout << "Solution failed" << std::endl;
		return;
	}

	fputs(buffer, OutputStream);

	if (InputStream != stdin) fclose(InputStream);
	if (OutputStream != stdout) fclose(OutputStream);
	return;
}