// Create a class named ThreeDPoint to model a point in a three-dimensional space. Let ThreeDPoint be derived from MyPoint.
// x, y, z represent x-, y- and z-coordinates.

class MyPoint
{
private:
	double x, y;
public:
	// The no-arg constructor that contruccts a point with coordinates(0,0)
	MyPoint(){
		x = 0;
		y = 0;
	}

	MyPoint(double x, double y){
		this->x = x;
		this->y = y;
	}
	double getX() const{
		return x;
	}
	double getY() const{
		return y;
	}

	//display the distance between two points in two-dimensional space.
	double distance(const MyPoint &point){
		return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
	}
};

class ThreeDPoint : public MyPoint
{
private:
	double z;
public:
	// The no-arg constructor that contruccts a point with coordinates(0,0,0) 
	ThreeDPoint() : MyPoint(){
		z = 0;
	}

	ThreeDPoint(double x, double y, double z) :MyPoint(x, y){
		this->z = z;
	}
	double getZ() const{
		return z;
	}

	//display the distance between two points in Three-dimensional space.
	double distance(const ThreeDPoint &point){
		double xx = getX();
		double yy = getY();
		double zz = z;
		double pxx = point.getX();
		double pyy = point.getY();
		double pzz = point.z;
		return sqrt((xx - pxx) * (xx - pxx) + (yy - pyy) * (yy - pyy) + (zz - pzz) * (zz - pzz));
	}
};