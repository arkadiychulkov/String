#include "Stringa.h"
#include<iostream>
#include<cstring>

Stringa::Stringa() {
	lenth = 80;
	dynamicText = new char[lenth + 1];
	dynamicText[0] = '\0';
}

Stringa::Stringa(size_t _lenth) {
	lenth = _lenth;
	dynamicText = new char[lenth + 1];
	dynamicText[0] = '\0';
}

Stringa::Stringa(const char* array) {
	lenth = strlen(array);
	dynamicText = new char[lenth + 1];
	strcpy_s(dynamicText, lenth + 1 ,array);
}

Stringa::Stringa(const Stringa &strus)
{
	lenth = strus.lenth;
	dynamicText = new char[lenth + 1];
	strcpy_s(dynamicText, lenth + 1,strus.dynamicText);
}

void Stringa::Show() {
	std::cout << dynamicText << std::endl;
}
size_t Stringa::getLength() {
	return this->lenth;
}