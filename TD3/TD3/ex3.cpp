#include <iostream>
#include <random>
#include "vecteur.hpp"

using namespace std;

// Random float generator
float randNbr3() {

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(-50.f, 50.f); // Random float whose value is between -50 and 50
	float b = dis(gen);
	return b;

}

Vecteur::Vecteur() {
	x1_ = randNbr3();
	x2_ = randNbr3();
	y1_ = randNbr3();
	y2_ = randNbr3();
	z1_ = randNbr3();
	z2_ = randNbr3();
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

Vecteur::Vecteur(Point2D point1, Point2D point2) {
	x1_ = point1.getX();
	x2_ = point2.getX();
	y1_ = point1.getY();
	y2_ = point2.getY();
	z1_ = 0.f;
	z2_ = 0.f;
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = 0.f;
}

Vecteur::Vecteur(Point3D point1, Point3D point2) {
	x1_ = point1.getX();
	x2_ = point2.getX();
	y1_ = point1.getY();
	y2_ = point2.getY();
	z1_ = point1.getZ();
	z2_ = point2.getZ();
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

void Vecteur::setPoint1(Point2D point) {
	x1_ = point.getX();
	y1_ = point.getY();
	z1_ = 0.f;
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

void Vecteur::setPoint1(Point3D point) {
	x1_ = point.getX();
	y1_ = point.getY();
	z1_ = point.getZ();
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

void Vecteur::setPoint2(Point2D point) {
	x2_ = point.getX();
	y2_ = point.getY();
	z2_ = 0.f;
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

void Vecteur::setPoint2(Point3D point) {
	x2_ = point.getX();
	y2_ = point.getY();
	z2_ = point.getZ();
	lengthX_ = x2_ - x1_;
	lengthY_ = y2_ - y1_;
	lengthZ_ = z2_ - z1_;
}

Point3D Vecteur::getPoint1() {
	auto point3d = new Point3D(x1_, y1_, z1_);
	return *point3d;
}

Point3D Vecteur::getPoint2() {
	auto point3d = new Point3D(x2_, y2_, z2_);
	return *point3d;
}

void Vecteur::printInfo() {
	if (z1_ != 0.f) {
		cout << "Point 1 coordinates : x = " << x1_ << ", y = " << y1_ << ", z = " << z1_ << endl;
		cout << "Point 2 coordinates : x = " << x2_ << ", y = " << y2_ << ", z = " << z2_ << endl;
		cout << "The vector is (" << lengthX_ << "; " << lengthY_ << "; " << lengthZ_ << ")\n";
	}
	else {
		cout << "Point 1 coordinates : x = " << x1_ << ", y = " << y1_ << endl;
		cout << "Point 2 coordinates : x = " << x2_ << ", y = " << y2_ << endl;
		cout << "The vector is (" << lengthX_ << "; " << lengthY_ << ")\n";
	}
}

void Vecteur::sum(Vecteur vec) {
	float tempLenX = 0.f, tempLenY = 0.f, tempLenZ = 0.f;
	tempLenX = lengthX_ + vec.lengthX_;
	tempLenY = lengthY_ + vec.lengthY_;
	tempLenZ = lengthZ_ + vec.lengthZ_;
	if (tempLenZ != 0.f) {
		cout << "The sum of these two vectors is the vector (" << tempLenX << "; " << tempLenY << "; " << tempLenZ << ")" << endl;
	}
	else {
		cout << "The sum of these two vectors is the vector (" << tempLenX << "; " << tempLenY << ")" << endl;
	}
}

void Vecteur::factor(const int nbr) {
	if (lengthZ_ != 0.f) {
		cout << "The product of this vector and " << nbr << "is the vector (" << lengthX_ * nbr << "; " << lengthY_ * nbr << "; " << lengthZ_ * nbr << ")" << endl;
	}
	else {
		cout << "The product of this vector and " << nbr << "is the vector (" << lengthX_ * nbr << "; " << lengthY_ * nbr << ")" << endl;
	}
}

bool Vecteur::isEqualTo(Vecteur vec) {
	if (lengthX_ == vec.lengthX_ && lengthY_ == vec.lengthY_ && lengthZ_ == vec.lengthZ_) {
		cout << "These two vectors are equal." << endl;
		return true;
	}
	else {
		cout << "These two vectors are not equal." << endl;
		return false;
	}
}

int main() {

	auto point1 = new Point3D(5.f, 10.f, -10.f);
	auto point2 = new Point3D(-20.f, 0.f, 5.f);
	auto vecteur = new Vecteur(*point1, *point2);
	vecteur->printInfo();

	return EXIT_SUCCESS;

}