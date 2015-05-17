/*
 *  String class implementation
 */

#include <bits/stdc++.h>
using namespace std;
/*
class String {
public:
	String();             // str = ""
	String(const char*);    // str = "abc"
	String(const String&);   // str = other_string
	String& operator=(const char *);
	String& operator=(const String&);
	String operator+(const String&);
	~String();

	char& operator[](int i);
	char operator[](int i) const;

	int size() const;

	String& operator+=(const String&);
	String& operator+=(const char*);

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

	friend bool operator==(const String& x, const char* s);
	friend bool operator==(const String& x, const String& y);
	friend bool operator!=(const String& x, const char* s);
	friend bool operator!=(const String& x, const String& y);
private:
	char *str;
};
*/

#include <cstring>
String::String() {
	str = new char[1];
	*str = '\0';
}
String::String(const char* c) {
	int len = strlen(c);
	str = new char[len + 1];
	strcpy(str, c);
}
String::String(const String& s) {
	int len = strlen(s.str);
	str = new char[len + 1];
	strcpy(str, s.str);
}
String& String::operator=(const char *c) {
	int len = strlen(c);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, c);
	return *this;
}

String& String::operator=(const String& s) {
	if (str == s.str)  // same pointer
		return *this;

	int len = strlen(s.str);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(const String& s) {
	int len1 = strlen(s.str);
	int len2 = strlen(str);
	String ss;
	ss.str = new char[len1 + len2 + 1];
	strcpy(ss.str, str);
	strcat(ss.str, s.str);
	return ss;
}

String::~String() {
	delete[] str;
	str = NULL;
}
char& String::operator[](int i) {
	return str[i];
}

char String::operator[](int i) const {
	return str[i];
}

int String::size() const {
	return strlen(str);
}

String& String::operator+=(const String& s) {
	return *this = *this + s;
}

String& String::operator+=(const char* s) {
	return *this = *this + s;
}

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {
	char tmp[1024];
	is >> tmp;
	delete[] s.str;
	s.str = new char[strlen(tmp) + 1];
	strcpy(s.str, tmp);
	return is;
}

bool operator==(const String& s, const char* str) {
	return strcmp(s.str, str) == 0;
}

bool operator==(const String& s1, const String& s2) {
	return strcmp(s1.str, s2.str) == 0;
}

bool operator!=(const String& s1, const char* str) {
	return strcmp(s1.str, str) != 0;
}

bool operator!=(const String& s1, const String& s2) {
	return strcmp(s1.str, s2.str) != 0;
}
/*
String f1(String a, String b) {
	a[2] = 'x';
	char c = b[2];
	cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
	return b;
}

void f2(String s, const String& r) {
	char c1 = s[1];  // c1 = s.operator[](1).operator char()
	s[1] = 'c';    // s.operator[](1).operator=('c')

	char c2 = r[1];  // c2 = r.operator[](1)
//  r[1] = 'd';    // error: assignment to non-lvalue char, r.operator[](1) = 'd'
}

void f() {
	String x, y, s;
	cout << "Please enter two strings\n";
	cin >> x >> y;
	cout << "x= " << x << " , y = " << y << '\n';

	y = f1(x, y);
	cout << y << endl;

	f2(x, y);

	cout << "s = \"" << s << "\"" << endl;
	s = "abc";
	cout << "s = \"" << s << "\"" << endl;

	cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x + y << "\"\n";
	String z = x;
	if (x != z)
		cout << "x corrupted!\n";
	x[0] = '!';
	if (x == z)
		cout << "write failed!\n";
	cout << "exit: " << x << ' ' << z << '\n';

	z = s;
	if (s != z)
		cout << "s corrupted!\n";
	s[0] = '!';
	if (s == z)
		cout << "write failed!\n";
	cout << "exit: " << s << ' ' << z << '\n';

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		f();
	}
}
*/

