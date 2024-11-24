#include "Stringa.h"
#include<iostream>
#include<cstring>

Stringa::Stringa() {
	this->lenth = 80;
}

Stringa::Stringa(size_t _lenth) {
	this->lenth = lenth;
}

Stringa::Stringa(char* array) {
	this->dynamicText = array;
}

Stringa::Stringa(const Stringa &str)
{
	this->dynamicText = str.dynamicText;
}

void Stringa::Show() const{
	std::cout << dynamicText << std::endl;
}
size_t Stringa::getLength() const {
	return this->lenth;
}