#include "Stringa.h"
#include "ISerializable.h"
#include <stdexcept>
#include<iostream>
#include<cstring>
#include<fstream>

Stringa::Stringa() {
	try
	{
		lenth = 80;
		dynamicText = new char[lenth + 1];
		dynamicText[0] = '\0';
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
}

Stringa::Stringa(size_t _lenth) {
	try
	{
		lenth = _lenth;
		dynamicText = new char[lenth + 1];
		dynamicText[0] = '\0';
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
}

Stringa::Stringa(const char* array) {
	try
	{
		lenth = strlen(array);
		dynamicText = new char[lenth + 1];
		strcpy_s(dynamicText, lenth + 1, array);
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error("Copy Efailed" + std::string(e.what()));
	}
}

Stringa::Stringa(const Stringa &strus)
{
	try
	{
		lenth = strus.lenth;
		dynamicText = new char[lenth + 1];
		strcpy_s(dynamicText, lenth + 1, strus.dynamicText);
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
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
	try
	{
		Stringa str;

		str.dynamicText = userStr.dynamicText;
		str.lenth = userStr.lenth;

		userStr.dynamicText = nullptr;
		userStr.lenth = 0;

		return str;
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
}

Stringa& Stringa::operator=(const Stringa& str) {
	try
	{
		Stringa strc;
		strc.lenth = str.lenth;
		strc.dynamicText = new char[lenth + 1];
		strcpy_s(strc.dynamicText, lenth + 1, str.dynamicText);
		return strc;
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
}

Stringa Stringa::operator+(const Stringa& str) {
	try
	{
		size_t newLength = this->lenth + str.lenth;
		char* newText = new char[newLength + 1];
		strcpy_s(newText, this->lenth + 1, this->dynamicText);
		strcat_s(newText, newLength + 1, str.dynamicText);

		Stringa result(newText);
		delete[] newText;
		return result;
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
}
  
Stringa& Stringa::operator+=(const Stringa& str) {
	try
	{
		size_t newLength = this->lenth + str.lenth;
		char* newText = new char[newLength + 1];
		strcpy_s(newText, this->lenth + 1, this->dynamicText);
		strcat_s(newText, newLength + 1, str.dynamicText);

		delete[] this->dynamicText;
		this->dynamicText = newText;
		lenth = newLength;
		return *this;
	}
	catch (const std::bad_alloc&)
	{
		throw std::runtime_error("Memory failed");
	}
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


std::ostream& Stringa::Serialize(std::ostream& output) {
	output.write(reinterpret_cast<const char*>(&lenth), sizeof(lenth));
	output.write(reinterpret_cast<const char*>(dynamicText), sizeof(char) * lenth);

	return output;
}

std::istream& Stringa::Deserialize(std::istream& input) {
	size_t newlenth;
	input.read(reinterpret_cast<char*>(&newlenth), sizeof(newlenth));

	char* arr = new char[newlenth+1];
	input.read(reinterpret_cast<char*>(arr), newlenth);
	arr[newlenth] = '\0';

	dynamicText = arr;
	lenth = newlenth;

	return input;
}

std::ostream& Stringa::Serialize(std::string& Path) {
	std::ofstream output(Path);
	output.write(reinterpret_cast<const char*>(&lenth), sizeof(lenth));
	output.write(reinterpret_cast<const char*>(dynamicText), sizeof(char) * lenth);

	return output;
}

std::istream& Stringa::Deserialize(std::string& Path) {
	std::ifstream input(Path);

	size_t newlenth;
	input.read(reinterpret_cast<char*>(&newlenth), sizeof(newlenth));

	char* arr = new char[newlenth + 1];
	input.read(reinterpret_cast<char*>(arr), newlenth);
	arr[newlenth] = '\0';

	dynamicText = arr;
	lenth = newlenth;

	return input;
}

std::ostream& Stringa::Serialize() {
	std::ofstream output("output.txt");
	output.write(reinterpret_cast<const char*>(&lenth), sizeof(lenth));
	output.write(reinterpret_cast<const char*>(dynamicText), sizeof(char) * lenth);

	output.close();
	return output;
}

std::istream& Stringa::Deserialize() {
	std::ifstream input("output.txt");

	size_t newlenth;
	input.read(reinterpret_cast<char*>(&newlenth), sizeof(newlenth));

	char* arr = new char[newlenth + 1];
	input.read(reinterpret_cast<char*>(arr), newlenth);
	arr[newlenth] = '\0';

	dynamicText = arr;
	lenth = newlenth;

	input.close();
	return input;
}