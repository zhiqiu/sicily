// Problem#: 14406
// Submission#: 3695374
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 14406
// Submission#: 3695163
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
* A cpp file to test copying pointer to class member like "s = a.s;"
* and show the need of const operator[] func
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
    Test(const Test &a){
        s = a.s;
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
