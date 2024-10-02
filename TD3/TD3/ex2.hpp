#include <iostream>

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
		Circle(Point2D &center, float radius);
		void print_data();
		float get_area();
		void set_radius(float radius);
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

