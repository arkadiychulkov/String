#pragma once
class Stringa
{
	private:
		size_t lenth;
		char* dynamicText = new char[lenth];
	public:
		Stringa();
		Stringa(size_t lenth);
		Stringa(const char* array);
		Stringa(const Stringa &str);
		void Show(); 
		size_t getLength();
};

