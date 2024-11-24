#pragma once
class Stringa
{
	private:
		size_t lenth;
		char* dynamicText = new char[lenth];
	public:
		Stringa();
		Stringa(size_t lenth);
		Stringa(char* array);
		Stringa(char* array);
		Stringa(const Stringa &str);
};

