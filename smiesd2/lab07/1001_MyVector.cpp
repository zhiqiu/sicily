#include <iostream>
using namespace std;

class MyVector{
    public:
        MyVector(int = 0, int = 0, int = 0);
        MyVector(const MyVector &);
        void display();
        friend MyVector add(MyVector &v1, MyVector &v2);
        friend MyVector sub(MyVector &v1, MyVector &v2);
        friend int dot(MyVector &v1, MyVector &v2);
        friend MyVector cross(MyVector &v1, MyVector &v2);
    private:
        int x, y, z;
};

MyVector::MyVector(int a, int b, int c){
    this->x = a;
    this->y = b;
    this->z = c;
}

MyVector::MyVector(const MyVector & myvector){
    this->x = myvector.x;
    this->y = myvector.y;
    this->z = myvector.z;
}

void MyVector::display(){
    cout << "(" << x << "," << y << "," << z << ")" << endl;
}

MyVector add(MyVector &v1, MyVector &v2){
    MyVector my;
    my.x = v1.x + v2.x;
    my.y = v1.y + v2.y;
    my.z = v1.z + v2.z;
    return my;
}

MyVector sub(MyVector &v1, MyVector &v2){
    MyVector my;
    my.x = v1.x - v2.x;
    my.y = v1.y - v2.y;
    my.z = v1.z - v2.z;
    return my;
}

int dot(MyVector &v1, MyVector &v2){
    int res;
    res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return res;
}

MyVector cross(MyVector &v1, MyVector &v2){
    MyVector my;
    my.x = v1.y * v2.z - v2.y * v1.z;
    my.y = v1.z * v2.x - v2.z * v1.x;
    my.z = v1.x * v2.y - v2.x * v1.y;
    return my;
}                                 
