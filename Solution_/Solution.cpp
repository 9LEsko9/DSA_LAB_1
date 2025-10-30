#include "Solution.h"

int Solution::CStringSolution(char* buffer, unsigned buffer_size, unsigned real_size) {
	char* c_ptr = buffer;

	while (*c_ptr != '\0' ) {

		if ((unsigned char) *c_ptr >= 0x80) {
			c_ptr++;
			continue;
		}

		if (isdigit(*c_ptr)) {
			int digit = (unsigned char) *c_ptr - '0';

			if (digit % 2 == 0) {
				const char* DigitWords[] = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT"};
				const char* Word = DigitWords[digit / 2];

				unsigned word_len = strlen(Word);

				if (strlen(buffer) + strlen(Word) >= buffer_size) return -1;
				std::memmove(c_ptr + word_len, c_ptr + 1, strlen(c_ptr + 1) + 1);
				std::memcpy(c_ptr, Word, word_len);
				c_ptr += word_len;
			} 
			else {
				if (digit >= 5) {
					if (strlen(buffer) + 3 >= buffer_size) return -1;
					std::memmove(c_ptr + 3, c_ptr + 1, strlen(c_ptr + 1) + 1);
					*c_ptr = '#'; *(c_ptr + 1) = '1';
					switch (digit) {
						case 5: *(c_ptr + 2) = '0'; break;
						case 7: *(c_ptr + 2) = '4'; break;
						case 9: *(c_ptr + 2) = '8'; break;
						}
					c_ptr += 3;
				}
				else {
					if (strlen(buffer) + 2 >= buffer_size) return -1;
					std::memmove(c_ptr + 2, c_ptr + 1, strlen(c_ptr + 1) + 1);
					*c_ptr = '#';
					switch (digit) {
						case 1: *(c_ptr + 1) = '2'; break;
						case 3: *(c_ptr + 1) = '6'; break;
					}
					c_ptr += 2;
				}
			}		
		} else c_ptr++;
	}

	return 0;
}

int Solution::StringSolution(char* buffer, unsigned buffer_size, unsigned real_size) {
	for (int c_index = 0; c_index < real_size; c_index++) {
		
		unsigned char symbol = (unsigned char) buffer[c_index];

		if (symbol >= 0x80) {
			continue;
		}

		if (isdigit(symbol)) {
			int digit = symbol - '0';

			if (digit % 2 == 0) {
				const char* DigitWords[] = { "ZERO", "TWO", "FOUR", "SIX", "EIGHT" };
				const char* Word = DigitWords[digit / 2];

				unsigned word_len = strlen(Word);

				if (real_size + word_len > buffer_size ) return -1;

				for (int i = real_size; i >= c_index + 1; i--) {
					buffer[i + word_len - 1] = buffer[i];
				}

				for (int i = 0; i < word_len; i++) {
					buffer[c_index + i] = Word[i];
				}

				real_size += word_len - 1;
				c_index += word_len - 1;
			}
			else {

				if (digit >= 5) {
					if (real_size + 2 >= buffer_size)
						return -1;

					for (int i = real_size; i >= c_index + 1; i--) {
						buffer[i + 2] = buffer[i];
					}

					buffer[c_index] = '#';
					buffer[c_index + 1] = '1';
					switch (digit) {
					case 5: buffer[c_index + 2] = '0'; break;
					case 7: buffer[c_index + 2] = '4'; break;
					case 9: buffer[c_index + 2] = '8'; break;
					}

					real_size += 2;
					c_index += 2;
				}

				else {
					if (real_size + 2 > buffer_size)
						return -1;

					for (int i = real_size; i >= (int)c_index + 1; i--) {
						buffer[i + 1] = buffer[i];
					}

					buffer[c_index] = '#';
					switch (digit) {
					case 1: buffer[c_index + 1] = '2'; break;
					case 3: buffer[c_index + 1] = '6'; break;
					}

					real_size += 2;
					c_index += 1;
				}
			}

		}
	} return 0;
}

int Solution::useSolutionAlghorithm(char* buffer, TypeOfString type_string, unsigned buffer_size, unsigned real_size) {
	if (buffer == nullptr) return -1;
	return (type_string == TypeOfString::String) ? 
		StringSolution(buffer, buffer_size, real_size) : CStringSolution(buffer, buffer_size, real_size);
}

