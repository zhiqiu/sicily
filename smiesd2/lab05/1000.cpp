#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class MyInteger{
    private:
        int value;
    public:
        MyInteger(int);
        int getValue();
        bool isEven();
        bool isOdd();
        bool isPrime();
        static bool isEven(int);
        static bool isOdd(int);
        static bool isPrime(int);
        static bool isEven(MyInteger&);
        static bool isOdd(MyInteger&);
        static bool isPrime(MyInteger&);
        bool equals(int);
        bool equals(MyInteger& );
        static int parseInt(string&);
};

MyInteger::MyInteger(int par_value){
    this->value = par_value;
}

int MyInteger::getValue(){
    return this->value;
}

bool MyInteger::isEven(){
    return (this->value % 2 != 0);
}

bool MyInteger::isOdd(){
    return (this->value % 2 == 0);
}

bool MyInteger::isPrime(){
    for(int i = 2; i <= sqrt(this->value); i += 2){
        if(this->value % i == 0)
            return false;
    }
    return true;
}

bool MyInteger::isEven(int para){
    return (para % 2 != 0);
}

bool MyInteger::isOdd(int para){
    return (para % 2 == 0);
}

bool MyInteger::isPrime(int para){
    for(int i = 2; i <= sqrt(para); i += 2){
        if(para % i == 0)
            return false;
    }
    return true;
}

bool MyInteger::isEven(MyInteger& other){
    return (other.value % 2 != 0);
}

bool MyInteger::isOdd(MyInteger& other){
    return (other.value % 2 == 0);
}

bool MyInteger::isPrime(MyInteger& other){
    return isPrime(other.value);
}

bool MyInteger::equals(int para){
    return (this->value == para);
}

bool MyInteger::equals(MyInteger &other){
    return (this->value == other.value);
}

int MyInteger::parseInt(string& str){
    int len = str.length();
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum *= 10;
        int digit = str[i] - '0';
        sum += digit;
    }
    return sum;
}                                 
