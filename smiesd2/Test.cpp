/*
* A cpp file to test copying pointer to class member like "s = a.s;"
* and show the need of two operator[] func overloading
* 2015.4.20
*/

#include <iostream>
#include <cstring>
using namespace std;

class Test{
    public:
    char *s;
    
	Test(char *str){
        s = new char[strlen(str)+1];
        strcpy(s,str);
    }

	// copy constructor, 
	// if write like this, s and s.s will point to the same memory block, Wrong
	//
    Test(const Test &a){
        s = a.s;
		// right way is : 
		// s = new [strlen(a.s)+1];
		// strcpy(s,a.s);
    }
    void modify(){
        s[1] = '0';
    }
    char & operator[](int i){
        return s[i];
    }

// without the function below, the program cant compile, because the display func is const, it cant call the non-const []
    char & operator[](int i) const{
        return s[i];
    }
    friend void display(const Test& a){
        for(int i=0;i<strlen(a.s);i++)
            cout << a[i] << endl;
    }
};



int main(){
    Test a("abc");
    Test b(a);
    cout << a.s << endl;
    cout << b.s << endl;
    

    // after call the a.modify() func, a and b are changed both.
    a.modify();
    cout << a.s << endl;
    cout << b.s << endl;
    
    display(a);
    return 0;
}                                 
