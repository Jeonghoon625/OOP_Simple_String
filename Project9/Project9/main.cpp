#include "MyString.h"

using namespace my;

int main(void)
{
	mystd::ostream cout;
	mystd::istream cin;

	string str;
	string str1("I like ");
	string str2 = "string class";
	string str3 = str1 + str2;

	cout << str1 << mystd::endl;
	cout << str2 << mystd::endl;
	cout << str3 << mystd::endl;

	str1 += str2;
	if (str1 == str3)
	{
		cout << "���� ���ڿ�!" << mystd::endl;
	}
		
	else
	{
		cout << "�������� ���� ���ڿ�!" << mystd::endl;
	}
		
	string str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << mystd::endl;
	return 0;
}