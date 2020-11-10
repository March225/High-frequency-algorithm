/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   �ַ������װ���ļ�
 *  @version   1.0
 *  @date	   2020-11-05
 */
#include <iostream>
#include "mystring.h"
using namespace std;

void test01() {
	MyString str = "��������!";

	// ���������ַ��������
	cin >> str;
	cout << "str:" << str << endl;

	// �����ַ���
	MyString str2 = str;
	cout << "str2:" << str2 << endl;
}

void test02() {
	MyString str = "hyhyh";
	MyString str2("");

	// �ַ�����ֵ
	str2 = "yyyyyy";
	cout << "str2:" << str2 << endl;

	// �ַ����޸�
	str2[0] = '0';
	cout << "str2:" << str2 << endl;

	// �ַ������
	MyString str3 = "-*+++";
	MyString str4 = "-*+++";
	MyString str5 = str3 + "+777";
	cout << "str5:" << str5 << endl;

	// �ַ����Ƚ�
	if(str3==str4) cout << "str3 == str4"<< endl;
	else cout << "str3 != str4" << endl;

	if (str3 == "+++") cout << "str3 == +++" << endl;
	else cout << "str3 != +++" << endl;
}

int main() {
	//test01();
	test02();
	return 0;
}