// Design a class named Triangle that extends GeometricObject class.

class Triangle :public GeometricObject
{
private:
	double side1, side2, side3;
public:
	Triangle(){ side1 = 1.0; side2 = 1.0; side3 = 1.0; }
	Triangle(int a, int b, int c)
	{
		if (a + b > c && a + c > b && b + c> a)
		{
			side1 = a;
			side2 = b;
			side3 = c;
		}
		else
		{
			cout << "illegal sides!" << endl;
			side1 = 1.0;
			side2 = 1.0;
			side3 = 1.0;
		}
	}
	double getside1(){ return side1; }
	double getside2(){ return side2; }
	double getside3(){ return side3; }
	double getArea()
	{
		double p = (side1 + side2 + side3) / 2;
		return sqrt(p*(p - side1)*(p - side2)*(p - side3));
	}
	double getPerimeter()
	{
		return side1 + side2 + side3;
	}
};