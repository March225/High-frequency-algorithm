/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ×Ö·û´®Àà·â×°Ö÷ÎÄ¼þ
 *  @version   1.0
 *  @date	   2020-11-05
 */
#include <iostream>
#include "mystring.h"
using namespace std;

void test01() {
	MyString str = "µÂÂêÎ÷ÑÇ!";

	// ¼üÅÌÊäÈë×Ö·û´®ÔÙÊä³ö
	cin >> str;
	cout << "str:" << str << endl;

	// ¿½±´×Ö·û´®
	MyString str2 = str;
	cout << "str2:" << str2 << endl;
}

void test02() {
	MyString str = "hyhyh";
	MyString str2("");

	// ×Ö·û´®¸³Öµ
	str2 = "yyyyyy";
	cout << "str2:" << str2 << endl;

	// ×Ö·û´®ÐÞ¸Ä
	str2[0] = '0';
	cout << "str2:" << str2 << endl;

	// ×Ö·û´®Ïà¼Ó
	MyString str3 = "-*+++";
	MyString str4 = "-*+++";
	MyString str5 = str3 + "+777";
	cout << "str5:" << str5 << endl;

	// ×Ö·û´®±È½Ï
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