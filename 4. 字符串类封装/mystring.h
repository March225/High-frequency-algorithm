#pragma once
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class MyString
{
	// ���� << ��Ԫ����
	friend ostream& operator<<(ostream& cout, MyString& mystr);

	// ���� >> ��Ԫ����
	friend istream& operator>>(istream& cin, MyString& mystr);
public:
	// Ĭ�Ϲ���
	MyString():m_Size(0), pString(nullptr) {};
	// �вι���
	MyString(const char *str);
	// ��������
	MyString(const MyString& mystr);
	// ����
	~MyString();

	// ���� = 
	MyString& operator=(const MyString& mystr);

	// ���� = (char* �汾)
	MyString& operator=(const char* str);

	// ���� [] 
	char& operator[](int idx);

	// ���� +
	MyString operator+(const MyString& mystr);

	// ���� + (char* �汾)
	MyString operator+(const char* str);

	// ���� ==
	bool operator==(const MyString& mystr);

	// ���� == (char* �汾)
	bool operator==(const char* str);

private:
	char* pString; // ά���ڶ������ٵ��ַ�����
	int m_Size;
};

