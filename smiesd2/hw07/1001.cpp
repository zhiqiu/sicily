#include <iostream>
using namespace std;

class Number{
    public:
        Number(int num = 0){
            number = num;
        }
        Number& add(int num){
            number += num;
            return *this;
        }
        Number& sub(int num){
            number -= num;
            return *this;
        }
        void print(){
            cout << number;
        }
    private:
        int number;
};                                 
