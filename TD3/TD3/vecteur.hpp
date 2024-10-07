#include <iostream>
#include "point2D-3D.hpp"

class Vecteur {
private:
	float x1_, x2_, y1_, y2_, z1_, z2_;
	float lengthX_, lengthY_, lengthZ_;
public:
	// constructors
	Vecteur();
	Vecteur(Point2D point1, Point2D point2);
	Vecteur(Point3D point1, Point3D point2);
	// setters and getters
	void setPoint1(Point2D point);
	void setPoint1(Point3D point);
	void setPoint2(Point2D point);
	void setPoint2(Point3D point);
	Point3D getPoint1();
	Point3D getPoint2();
	// other methods
	void printInfo();
	void sum(Vecteur vec);
	void factor(const int nbr);
	bool isEqualTo(Vecteur vec);
};