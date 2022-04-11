#include "Mystring.h"

//ostream
mystd::ostream& mystd::ostream::operator<< (char* str)
{
	printf("%s", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (const char* str)
{
	printf("%s", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (char str)
{
	printf("%c", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (ostream& (*fp)(ostream& ostm))
{
	return fp(*this);
}

mystd::ostream& mystd::endl(ostream& ostm)
{
	ostm << '\n';
	fflush(stdout);
	return ostm;
}

//istream
void mystd::istream::operator>> (char*& str)
{
	char* temp = new char[100];
	gets_s(temp, 100);
	delete[] str;
	str = temp;
}

mystd::ostream& my::operator<< (mystd::ostream& os, const my::string& string)
{
	os << string.str;
	return os;
}

mystd::istream& my::operator>> (mystd::istream& is, my::string& string)
{
	is >> string.str;
	return is;
}

//string
my::string::string() : str(nullptr), strLen(0)
{
}

my::string::string(const char* str)
{
	strLen = (int)strlen(str) + 1;	
	this->str = new char[strLen];
	strcpy_s(this->str, strLen, str);
}

my::string::string(const string& ref)
{
	strLen = ref.strLen;
	str = new char[strLen];
	strcpy_s(str, strLen, ref.str);
}

my::string my::string::operator+ (const string& substr)
{
	char* temp = new char[strLen + substr.strLen - 1];
	strcpy_s(temp, strLen + substr.strLen - 1, str);
	strcat_s(temp, strLen + substr.strLen - 1, substr.str);
	
	string stemp(temp);

	delete[] temp;

	return stemp;
}

my::string& my::string::operator= (const string& substr)
{
	strLen = substr.strLen;
	str = new char[strLen];
	strcpy_s(str, strLen, substr.str);
	return *this;
}

my::string& my::string::operator+= (const string& substr)
{
	strLen += substr.strLen - 1;
	char* temp = new char[strLen];
	strcpy_s(temp, strLen, str);
	strcat_s(temp, strLen, substr.str);

	if (str != nullptr)
	{
		delete[] str;
	}
	str = temp;

	return *this;
}

bool my::string::operator== (const string substr)
{
	return strcmp(this->str, substr.str) ? false : true;
}

my::string::~string()
{
	if (str != nullptr)
	{
		delete[] str;
	}
	
}