#include<iostream>
#include<cstring>
using namespace std;

class MyVector{
private:
    double *data;
    int size;
public:
    MyVector(){
        data = NULL;
        size = 0;
    }

    MyVector(int size){
        this->size = size;
        data = new double[size];
        memset(data, 0, size);
    }

    void create(int size){
        this->size = size;
        delete data;
        data = new double[size];
        memset(data, 0, size);
    }

    void setValue(double value, int index){
        *(data + index) = value;
    }

    void multiply(double k){
        for(int i = 0; i < size; i++){
            *(data + i) = *(data + i) * k;
        }
    }

    void display(){
        cout << "(";
        for(int i = 0; i < size; i++){
            if(i == size - 1)
                cout << *(data + i);
            else
                cout << *(data + i) << ",";
        }
        cout << ")\n";
    }

    ~MyVector(){
        if(data != NULL){
			delete data;
			data = NULL;
		}
		size = 0;
    }
};                                 ;                                 
