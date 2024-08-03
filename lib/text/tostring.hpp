#ifndef TO_STRING_HPP
#define TO_STRING_HPP

#include "stringutils.hpp"

void toString(int num, char* str) {
	int i = 0;
	int sign = num < 0 ? -1 : 1;
	num *= sign;
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while(num != 0);

	if(sign < 0) str[i++] = '-';

	str[i] = '\0';

	for(int j = 0; j < i / 2; j++) {
		char tmp = str[j];
		str[j] = str[i - 1 - j];
		str[i - 1 - j] = tmp;
	}
}

void toString(float num, char* str, int precision = 6) {
	// Handle integer part
	int intPart = static_cast<int>(num);
	float fractionalPart = num - intPart;

	int len = 0;
	toString(intPart, str);
	len = string_length(str);
	// Add decimal point
	str[len++] = '.';
	str[len] = '\0';

	// Handle fractional part
	for(int i = 0; i < precision; ++i) {
		fractionalPart *= 10;
		int digit = static_cast<int>(fractionalPart);
		str[len++] = digit + '0';
		fractionalPart -= digit;
	}
	str[len] = '\0';
}

void toString(double num, char* str, int precision = 6) {
	// Handle integer part
	int intPart = static_cast<int>(num);
	double fractionalPart = num - intPart;

	int len = 0;
	toString(intPart, str);
	len = string_length(str);
	// Add decimal point
	str[len++] = '.';
	str[len] = '\0';

	// Handle fractional part
	for(int i = 0; i < precision; ++i) {
		fractionalPart *= 10;
		int digit = static_cast<int>(fractionalPart);
		str[len++] = digit + '0';
		fractionalPart -= digit;
	}
	str[len] = '\0';
}

#endif