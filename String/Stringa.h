#pragma once
#include<iostream>
#include"ISerializable.h"

class Stringa : ISerializable
{
	private:
		size_t lenth;
		char* dynamicText = new char[lenth];
	public:
		Stringa();
		Stringa(size_t lenth);
		Stringa(const char* array);
		Stringa(const Stringa &str);
		Stringa(Stringa&& str);

		void Show(); 
		size_t getLength();
		Stringa& operator=(const Stringa& str);
		Stringa& operator=(Stringa&& str);
		Stringa operator+(const Stringa& str);
		Stringa& operator+=(const Stringa& str);
		char& operator[](size_t index);
		friend std::ostream& operator<<(std::ostream& os, const Stringa& str);
		bool operator==(const Stringa& str);
		bool operator!=(const Stringa& str);
		bool operator>(const Stringa& str);
		bool operator<(const Stringa& str);

		std::ostream& Serialize(std::ostream& output);
		std::istream& Deserialize(std::istream& input);

		std::ostream& Serialize(std::string& Path);
		std::istream& Deserialize(std::string& Path);

		std::ostream& Serialize();
		std::istream& Deserialize();
};