// Write a program that uses the class SafeIntArray which this class will 
// check if the index is valid when call its get/set function. 
// Write another class called IndexIntArray, which is derived from SafeIntArray
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class SafeIntArray
{
public:
	SafeIntArray(int n)
	{
		array = new int[n];
		for (int x = 0; x<n; x++)
			array[x] = 0;
		size = n;
	}

	void set(int a, int b)
	{
		if (a >= 0 && a<size)
			array[a] = b;
		else
			cout << "Outside the boundary!" << endl;
	}

	int get(int i)
	{
		if (i >= 0 && i<size)
			return array[i];
		else
		{
			cout << "Outside the boundary!" << endl;
			return -1;
		}
	}

	~SafeIntArray()
	{
		delete array;
	}
private:
	int *array;
	int size;
};

class IndexIntArray : public SafeIntArray
{
public:
	IndexIntArray(int a, int b) :SafeIntArray(b - a + 1)
	{
		begin = a;
	}
	void set(int a, int b)
	{
		SafeIntArray::set(a - begin, b);
	}

	int get(int i)
	{
		return SafeIntArray::get(i - begin);
	}
private:
	int begin;
	int end;

};

/*
int main(int argc, char** argv) {
    
    int test;
    cin >> test;
    while (test --) {
        int size, n;
        cin >> size;
        SafeIntArray sia(size);
        // test SafeIntArray::set(int,int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            sia.set(index, data);
        }
        // test SafeIntArray::get(int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = sia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
 
        int begin, end;
        cin >> begin >> end;
        IndexIntArray iia(begin, end);
        // test IndexIntArray::set(int,int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            iia.set(index, data);
        }
        // test IndexIntArray::get(int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = iia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
    }
 
    return 0;
}
*/