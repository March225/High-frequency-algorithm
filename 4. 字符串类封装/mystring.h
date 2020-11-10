#pragma once
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class MyString
{
	// 重载 << 友元声明
	friend ostream& operator<<(ostream& cout, MyString& mystr);

	// 重载 >> 友元声明
	friend istream& operator>>(istream& cin, MyString& mystr);
public:
	// 默认构造
	MyString():m_Size(0), pString(nullptr) {};
	// 有参构造
	MyString(const char *str);
	// 拷贝构造
	MyString(const MyString& mystr);
	// 析构
	~MyString();

	// 重载 = 
	MyString& operator=(const MyString& mystr);

	// 重载 = (char* 版本)
	MyString& operator=(const char* str);

	// 重载 [] 
	char& operator[](int idx);

	// 重载 +
	MyString operator+(const MyString& mystr);

	// 重载 + (char* 版本)
	MyString operator+(const char* str);

	// 重载 ==
	bool operator==(const MyString& mystr);

	// 重载 == (char* 版本)
	bool operator==(const char* str);

private:
	char* pString; // 维护在堆区开辟的字符数组
	int m_Size;
};

