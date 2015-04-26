/*
 *  Complex Number class implementation
 */

#include <bits/stdc++.h>
using namespace std;
/*
class Complex //复数类
{
public:
	Complex(double real = 0, double imag = 0);
	Complex operator+(Complex& com);
	Complex operator-(Complex& com);
	Complex operator*(Complex& com);
	Complex operator/(Complex& com);
	double& operator[](int i);
	double operator[](int i) const;
	friend ostream& operator<<(ostream& os, Complex& com); //友元函数重载提取运算符"<<"
	friend istream& operator>>(istream& is, Complex& com); //友元函数重载插入运算符">>"
private:
	double real; //实数
	double imag; //虚数
};
*/

#include <cmath>
bool equal(double a,double b){
    return fabs(a-b) < 1e-8;
}
Complex::Complex (double real, double imag){
    this->real = real;
    this->imag = imag;
}
Complex Complex::operator+ (Complex& com){

    return Complex(real + com.real,imag + com.imag);
}
Complex Complex::operator- (Complex& com){
    return Complex(real - com.real,imag - com.imag);
}
Complex Complex::operator* (Complex& com){
    return Complex(real*com.real - imag*com.imag,real*com.imag + imag*com.real);
}
Complex Complex::operator/ (Complex& com){
    // maybe using equal()
    if(!(com.real==0  && com.imag == 0)){
        Complex c;
        c.real = (real*com.real + imag*com.imag) / (com.real*com.real + com.imag*com.imag);
        c.imag = (com.real*imag - real*com.imag) / (com.real*com.real + com.imag*com.imag);
        return c;
    }
    //else error code; ?
}
double& Complex::operator[](int i){
    return i ? imag : real;
}
double Complex::operator[](int i) const{
    return i ? imag : real;
}
ostream& operator<< (ostream& os, Complex& com){
    // maybe using equal()
    if(com.real==0&&com.imag==0)   os << 0;
    if(com.real!=0){       // real part
        os << com.real;
        if(com.imag > 0)    os << "+";
    }
    if(com.imag!=0){       // imag part
        if(com.imag==1)
            os << "i";
        else if(com.imag == -1)
            os << "-i";
        else os << com.imag << "i";
    }
    return os;
}
istream& operator>>(istream& is, Complex& com){
    is >> com.real >> com.imag;
    return is;
}


/*
int main() {
	int T;
	cin >> T;
	while (T--) {
		Complex com1, com2;
		cin >> com1;
		cout << com1 << endl;
		cout << com1[0] << " " << com1[1] << endl;

		cin >> com2;
		cout << com2 << endl;
		cout << com2[0] << " " << com2[1] << endl;

		Complex c1 = com1 + com2;
		cout << "(" << com1 << ")+(" << com2 << ")=" << c1 << endl;

		Complex c2 = com1 - com2;
		cout << "(" << com1 << ")-(" << com2 << ")=" << c2 << endl;

		Complex c3 = com1 * com2;
		cout << "(" << com1 << ")*(" << com2 << ")=" << c3 << endl;

		Complex c4 = com1 / com2;
		cout << "(" << com1 << ")/(" << com2 << ")=" << c4 << endl;
	}
	return 0;
}
*/

