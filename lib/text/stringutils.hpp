#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

int string_length(const char* str) {
	int length = 0;
	while(str[length] != '\0') {
		length++;
	}
	return length;
}

#endif