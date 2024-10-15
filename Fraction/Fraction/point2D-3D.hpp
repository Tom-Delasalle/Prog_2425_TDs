#include <iostream>
#include <random>

const float pi = 3.1416f;

using namespace std;

class Point2D {
	protected:
		float x, y; // protected attributes
	public:
		// constuctors
		Point2D(); // fill X Y with random values (from 0 to 100)
		Point2D(const float& newx, const float& newy); // fill XY values
		// Setters and getters
		void setXY(const float& newx, const float& newy);
		void setX(const float& newx);
		void setY(const float& newy);
		float getX();
		float getY();
		// other methods
		void print(); // prints the coordinates of the point
		float distanceTo(Point2D &otherPoint2D);
};

class Point3D : public Point2D {
	private:
		float z; // private attributes
	public:
		// constuctors
		Point3D(); // fill X Y Z with random values (from 0 to 100)
		Point3D(const float& newx, const float& newy, const float& newz); // fill XYZ values
		Point3D(Point2D& point2D, const float& newz); // fill XYZ values with the XY from a Point2D
		// Setters and getters
		void setXYZ(const float& newx, const float& newy, const float& newz);
		void setZ(const float& newz);
		float getZ();
		// other methods
		void print(); // prints the coordinates of the point
		float distanceTo(Point3D &otherPoint3D);
};

class Rectangle : public Point2D
{
	private:
		float length_;
		float width_;
		Point2D pointLowerLeft_; // pointLowerLeft_.x must lower than pointUpperRight_.x and same thing for .y
		Point2D pointUpperRight_;
	public:
		Rectangle(Point2D &pointLowerLeft, Point2D &pointUpperRight);
		float get_area();
		void print_data();
		void set_point_lower_left(Point2D &pointLowerLeft);
		void set_point_upper_right(Point2D &pointUpperRight);
};

class Circle : public Point2D
{
	private:
		float radius_;
		Point2D center_;
	public:
		Circle(Point2D &center,const float radius);
		void print_data();
		float get_area();
		void set_radius(const float radius);
		void set_center(Point2D &center);
};

class Triangle : public Point2D {

	private:
		float side1;
		float side2;
		float side3;
		Point2D point1_;
		Point2D point2_;
		Point2D point3_;
	public:
		Triangle(Point2D &point1, Point2D &point2, Point2D &point3);
		void print_data();
		float get_area();
		void set_points(Point2D &point1, Point2D &point2, Point2D &point3);
};

float randNbr() {

	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<float> distr(0, 100); // Random float whose value is between 0 and 100
	float a = distr(eng);
	return a;

}

// Same as randNbr() but way more faster to run
float randNbr2() {

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.f, 1.f); // Random float whose value is between 0 and 1
	float b = dis(gen);
	return b;

}

Point2D::Point2D() {
	x = randNbr();
	y = randNbr();
}

Point2D::Point2D(const float& newx, const float& newy) {
	x = newx;
	y = newy;
}

void Point2D::setXY(const float& newx, const float& newy) {
	x = newx;
	y = newy;
}

void Point2D::setX(const float& newx) {
	x = newx;
}

void Point2D::setY(const float& newy) {
	y = newy;
}

float Point2D::getX() {
	return x;
}

float Point2D::getY() {
	return y;
}

void Point2D::print() {
	cout << "This 2D point's coordinates are : \nX = " << x << "\nY = " << y << endl;
}

float Point2D::distanceTo(Point2D& otherPoint2D) {
	float distance = sqrt(pow((x - otherPoint2D.getX()), 2.f) + pow((y - otherPoint2D.getY()), 2.f));
	return distance;
}

Point3D::Point3D() {
	x = randNbr();
	y = randNbr();
	z = randNbr();
}

Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
	x = newx;
	y = newy;
	z = newz;
}

Point3D::Point3D(Point2D& point2D, const float& newz) {
	x = point2D.getX();
	y = point2D.getY();
	z = newz;
}

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setZ(const float& newz) {
	z = newz;
}

float Point3D::getZ() {
	return z;
}

void Point3D::print() {
	cout << "This 3D point's coordinates are : \nX = " << x << "\nY = " << y << "\nZ = " << z << endl;
}

float Point3D::distanceTo(Point3D& otherPoint3D) {
	float distance = sqrt(pow((x - otherPoint3D.getX()), 2.f) + pow((y - otherPoint3D.getY()), 2.f) + pow((z - otherPoint3D.getZ()), 2.f));
	return distance;
}

Rectangle::Rectangle(Point2D& pointLowerLeft, Point2D& pointUpperRight) {
	pointLowerLeft_.setXY(pointLowerLeft.getX(), pointLowerLeft.getY());
	pointUpperRight_.setXY(pointUpperRight.getX(), pointUpperRight.getY());
	length_ = pointUpperRight.getX() - pointLowerLeft.getX();
	width_ = pointUpperRight.getY() - pointLowerLeft.getY();
}

float Rectangle::get_area() {
	return (length_ * width_);
}

void Rectangle::print_data() {
	cout << "Length : " << length_ << " | Width : " << width_ << "\nLower left point's coordinates : ";
	pointLowerLeft_.print();
	cout << "Upper right point's coordinates : ";
	pointUpperRight_.print();
}

void Rectangle::set_point_lower_left(Point2D& pointLowerLeft) {
	pointLowerLeft_.setXY(pointLowerLeft.getX(), pointLowerLeft.getY());
}

void Rectangle::set_point_upper_right(Point2D& pointUpperRight) {
	pointUpperRight_.setXY(pointUpperRight.getX(), pointUpperRight.getY());
}

Circle::Circle(Point2D& center, float radius) {
	center_.setXY(center.getX(), center.getX());
	radius_ = radius;
}

void Circle::print_data() {
	cout << "Circle radius : " << radius_ << "\nCenter point's coordinates : ";
	center_.print();
}

float Circle::get_area() {
	return (radius_ * radius_ * pi);
}

void Circle::set_radius(float radius) {
	radius_ = radius;
}

void Circle::set_center(Point2D& center) {
	center_.setXY(center.getX(), center.getY());
}

Triangle::Triangle(Point2D& point1, Point2D& point2, Point2D& point3) {
	point1_.setXY(point1.getX(), point1.getY());
	point2_.setXY(point2.getX(), point2.getY());
	point3_.setXY(point3.getX(), point3.getY());
	side1 = sqrt(pow((point2.getX() - point1.getX()), 2.f) + pow((point2.getY() - point1.getY()), 2.f));
	side2 = sqrt(pow((point3.getX() - point2.getX()), 2.f) + pow((point3.getY() - point2.getY()), 2.f));
	side3 = sqrt(pow((point1.getX() - point3.getX()), 2.f) + pow((point1.getY() - point3.getY()), 2.f));
}

void Triangle::print_data() {
	cout << "Side 1 : " << side1 << " | Side 2 : " << side2 << " | Side 3 : " << side3 << "\n Point 1's coordinates : ";
	point1_.print();
	cout << "Point 2's coordinates : ";
	point2_.print();
	cout << "Point 3's coordinates : ";
	point3_.print();
}

float Triangle::get_area() {
	float temp = (side1 + side2 + side3) / 2.f;
	return (sqrtf(temp * (temp - side1) * (temp - side2) * (temp - side3))); // sqrtf is the same as sqrt except it only accepts float numbers
}

void Triangle::set_points(Point2D& point1, Point2D& point2, Point2D& point3) {
	point1_.setXY(point1.getX(), point1.getY());
	point2_.setXY(point2.getX(), point2.getY());
	point3_.setXY(point3.getX(), point3.getY());
}

// Monte Carlo method to determine an approximation of pi
float monteCarlo(unsigned int iteration) {

	if (iteration > 0) {
		float conditionIsTrue = 0;
		Point2D m(randNbr2(), randNbr2());
		for (unsigned int i = 0; i < iteration; ++i) {
			if ((pow(m.getX(), 2.f) + pow(m.getY(), 2.f)) <= 1) { // x^2 + y^2 <= 1
				conditionIsTrue++;
			}
			m.setXY(randNbr2(), randNbr2());
		}
		return (conditionIsTrue / static_cast<float>(iteration) * 4.f); // pi/4 * 4
	}
	else {
		return -1;
	}

}
