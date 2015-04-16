#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class MyString{
	public:
		MyString(const char* st);
		MyString(int = 0, char = '\0'); //initialize size_t number of char, terminated with '\0'    
		MyString(const MyString& mystring); //copy constructor
		~MyString(); //destructor
		const char* c_str(); //return private char*
		static int getNumberOfObjects();
	private:
		char *str;
		static int numberOfObjects; //count the number of MyString objects
};

int MyString::numberOfObjects = 0;

MyString::MyString(const char* st){
	this->str = new char[strlen(st) + 1];
	for(int i = 0; i <= strlen(st); i++){
		str[i] = st[i];
	}
	str[strlen(st)] = '\0';
	numberOfObjects ++;
}

MyString::MyString(int size, char st){
	this->str = new char[size + 1];
	for(int i = 0; i < size; i++)
		str[i] = st;
	str[size] = '\0';
	numberOfObjects ++;
}

MyString::MyString(const MyString& mystring){
	int len = strlen(mystring.str);
	str = new char[len + 1];
	for(int i = 0; i < len; i++){
		str[i] = mystring.str[i];
	}
	numberOfObjects ++;
}

const char* MyString::c_str(){
	return this->str;
}

MyString::~MyString(){
	if(this->str != NULL){
		delete[] this->str;
		this->str = NULL;
	}
	numberOfObjects--;
}

int MyString::getNumberOfObjects(){
	return numberOfObjects;
}                                 
