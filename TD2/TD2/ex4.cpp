#include <iostream>
#include <random>
#include "Point3D.hpp"

using namespace std;

	float randNbr() {
	
		random_device rd;
		default_random_engine eng(rd());
		uniform_real_distribution<float> distr(0, 100); // Random float whose value is between 0 and 100
		float a = distr(eng);
		return a;

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

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setX(const float& newx) {
	x = newx;
}

void Point3D::setY(const float& newy) {
	y = newy;
}

void Point3D::setZ(const float& newz) {
	z = newz; 
}

float Point3D::getX() {
	return x;
}

float Point3D::getY() {
	return y;
}

float Point3D::getZ() {
	return z;
}

void Point3D::print() {
	cout << "This point's coordinates are : \nX = " << x << "\nY = " << y << "\nZ = " << z << endl;
}

float Point3D::distanceTo(const Point3D &otherPoint3D) {
	float distance = sqrt(pow(2.0, (x - otherPoint3D.x)) + pow(2.0, (y - otherPoint3D.y)) + pow(2.0, (z - otherPoint3D.z)));
	return distance;
}

int main() {

	Point3D point1;
	Point3D point2(2.0, 15.0, 38.0);
	Point3D point3(50.0, 40.0, 24.0);

	float tempX, tempY, tempZ;

	point1.print();
	tempX = point2.getX();
	tempY = point2.getY();
	tempZ = point2.getZ();
	cout << tempX << " " << tempY << " " << tempZ << endl;
	point2.setXYZ(3.0, 16.0, 39.0);
	point2.print();
	tempX = point3.getX();
	tempY = point3.getY();
	tempZ = point3.getZ();
	cout << tempX << " " << tempY << " " << tempZ << endl;
	point3.setX(55.0);
	point3.setY(45.0);
	point3.setZ(29.0);
	point3.print();
	tempX = point2.distanceTo(point3);
	cout << tempX << endl;

	return EXIT_SUCCESS;

}