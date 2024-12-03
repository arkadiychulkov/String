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

Stringa::Stringa(Stringa&& str) :dynamicText(str.dynamicText), lenth(str.lenth) {
	str.dynamicText = nullptr;
	str.lenth = 0;
}










void Stringa::Show() {
	std::cout << dynamicText << std::endl;
}

size_t Stringa::getLength() {
	return this->lenth;
}

Stringa& Stringa::operator=(Stringa&& userStr) {
	Stringa str(1);

	str.dynamicText = userStr.dynamicText;
	str.lenth = userStr.lenth;

	userStr.dynamicText = nullptr;
	userStr.lenth = 0;

	return str;
}