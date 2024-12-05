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
	Stringa str;

	str.dynamicText = userStr.dynamicText;
	str.lenth = userStr.lenth;

	userStr.dynamicText = nullptr;
	userStr.lenth = 0;

	return str;
}

Stringa& Stringa::operator=(const Stringa& str) {
	Stringa strc;
	strc.lenth = str.lenth;
	strc.dynamicText = new char[lenth + 1];
	strcpy_s(strc.dynamicText, lenth + 1, str.dynamicText);
	return strc;
}

Stringa Stringa::operator+(const Stringa& str) {
	size_t newLength = this->lenth + str.lenth;
	char* newText = new char[newLength + 1];
	strcpy_s(newText, this->lenth + 1, this->dynamicText);
	strcat_s(newText, newLength + 1, str.dynamicText);

	Stringa result(newText);
	delete[] newText;
	return result;
}
  
Stringa& Stringa::operator+=(const Stringa& str) {
	size_t newLength = this->lenth + str.lenth;
	char* newText = new char[newLength + 1];
	strcpy_s(newText, this->lenth + 1, this->dynamicText);
	strcat_s(newText, newLength + 1, str.dynamicText);

	delete[] this->dynamicText;
	this->dynamicText = newText;
	lenth = newLength;
	return *this;
}

char& Stringa::operator[](size_t index) {
	return this->dynamicText[index];
}

std::ostream& operator<<(std::ostream& os, const Stringa& str) {
	os << str.dynamicText;
	return os;
}

bool Stringa::operator==(const Stringa& str) {
	for (size_t i = 0; i < this->lenth; i++)
	{
		if (this->dynamicText[i] != str.dynamicText[i]) {
			return false;
		}
	}
	return true;
}

bool Stringa::operator!=(const Stringa& str) {
	for (size_t i = 0; i < this->lenth; i++)
	{
		if (this->dynamicText[i] != str.dynamicText[i]) {
			return true;
		}
	}
	return false;
}

bool Stringa::operator>(const Stringa& str) {
	return lenth > str.lenth;
}

bool Stringa::operator<(const Stringa& str) {
	return lenth < str.lenth;
}