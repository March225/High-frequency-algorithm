#include "mystring.h"

// 重载 <<
ostream& operator<<(ostream& cout, MyString& mystr) {
	cout << mystr.pString;
	return cout;
}

// 重载 >>
istream& operator>>(istream& cin, MyString& mystr) {
	// 先释放原来的字符串
	if (mystr.pString) {
		delete[] mystr.pString;
		mystr.pString = nullptr;
	}

	char tmp[1024];
	cin >> tmp;
	mystr.m_Size = strlen(tmp);
	mystr.pString = new char[mystr.m_Size + 1];
	strcpy_s(mystr.pString, mystr.m_Size + 1, tmp);
	return cin;
}

MyString::MyString(const char* str)
{
	cout << "MyString有参构造函数调用" << endl;
	m_Size = strlen(str);
	pString = new char[m_Size + 1];
	strcpy_s(pString, m_Size + 1, str);
}

MyString::MyString(const MyString& mystr)
{
	cout << "MyString拷贝构造函数调用" << endl;
	m_Size = mystr.m_Size;
	pString = new char[m_Size + 1];
	strcpy_s(pString, m_Size + 1, mystr.pString);

}

MyString::~MyString()
{
	if (pString != nullptr) {
		cout << "析构调用" << endl;
		delete[] pString;
		pString = nullptr;
	}
}

char& MyString::operator[](int idx)
{
	return pString[idx];
}

MyString MyString::operator+(const MyString& mystr)
{
	MyString tmp;
	tmp.m_Size = m_Size + mystr.m_Size;
	tmp.pString = new char[tmp.m_Size + 1];
	auto p = tmp.pString;
	strncpy_s(p, m_Size + 1, pString, m_Size);
	p += m_Size;
	strncpy_s(p, mystr.m_Size + 1, mystr.pString, mystr.m_Size + 1);
	return tmp;
}

MyString MyString::operator+(const char* str)
{
	MyString tmp;
	tmp.m_Size = m_Size + strlen(str);
	tmp.pString = new char[tmp.m_Size + 1];
	auto p = tmp.pString;
	strncpy_s(p, m_Size + 1, pString, m_Size);
	p += m_Size;
	strncpy_s(p, strlen(str) + 1, str, strlen(str) + 1);
	return tmp;
}

bool MyString::operator==(const char* str)
{
	if (strcmp(pString, str) == 0) return true;
	else return false;
}

bool MyString::operator==(const MyString& mystr)
{
	if (strcmp(pString, mystr.pString) == 0) return true;
	else return false;
}

MyString& MyString::operator=(const MyString& mystr)
{
	// 先释放原来的字符串
	if (pString) {
		delete[] pString;
		pString = nullptr;
	}

	m_Size = mystr.m_Size;
	pString = new char[m_Size + 1];
	strcpy_s(pString, m_Size + 1, mystr.pString);
	return *this;
}

MyString& MyString::operator=(const char* str)
{
	// 先释放原来的字符串
	if (pString) {
		delete[] pString;
		pString = nullptr;
	}

	m_Size = strlen(str);
	pString = new char[m_Size + 1];
	strcpy_s(pString, m_Size + 1, str);
	return *this;
}

