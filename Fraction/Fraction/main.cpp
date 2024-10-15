#include <iostream>
#include <fstream>

#include "Fraction.hpp"
#include "point2D-3D.hpp"

using namespace std;

Fraction::Fraction(const Fraction& fraction) {
	this->num_= fraction.num_;
	this->den_ = fraction.den_;
}

Fraction::Fraction(const int& num = 0, const int& den = 1) {
	this->num_ = num;
	this->den_ = den;
}

void Fraction::set_num(const int& num) {
	this->num_ = num;
}

void Fraction::set_den(const int& den) {
	this->den_ = den;
}

int Fraction::get_num() const {
	return this->num_;
}

int Fraction::get_den() const {
	return this->den_;
}

Fraction Fraction::operator+(const Fraction& fraction) {
	Fraction temp;
	temp.num_ = this->num_ * fraction.den_ + fraction.num_ * this->den_;
	temp.den_ = this->den_ * fraction.den_;
	return temp;
}

bool Fraction::operator<(const Fraction& fraction) const {
	return (this->num_ / this->den_ < fraction.num_ / fraction.den_);
}

bool Fraction::operator>(const Fraction& fraction) const {
	return !(this->num_ / this->den_ < fraction.num_ / fraction.den_);
}

bool Fraction::operator!=(const Fraction& fraction) const {
	return (this->num_ / this->den_ != fraction.num_ / fraction.den_); 
}

bool Fraction::operator<=(const Fraction& fraction) const {
	return (this->num_ / this->den_ <= fraction.num_ / fraction.den_);
}

bool Fraction::operator>=(const Fraction& fraction) const {
	return !(this->num_ / this->den_ <= fraction.num_ / fraction.den_);
}

bool Fraction::operator<(const int& val) const {
	return (static_cast<float>(this->num_ / this->den_) < static_cast<float>(val));
}

bool Fraction::operator>(const int& val) const {
	return !(static_cast<float>(this->num_ / this->den_) < static_cast<float>(val));
}

bool Fraction::operator!=(const int& val) const {
	return (static_cast<float>(this->num_ / this->den_) != static_cast<float>(val));
}

bool Fraction::operator<=(const int& val) const {
	return (static_cast<float>(this->num_ / this->den_) <= static_cast<float>(val));
}

bool Fraction::operator>=(const int& val) const {
	return !(static_cast<float>(this->num_ / this->den_) <= static_cast<float>(val));
}

bool operator<(const int& val, const Fraction& frac) {
	return (static_cast<float>(val) < static_cast<float>(frac.num_ / frac.den_));
}

int main()
{
	Point2D point1(1,2), point2(5,2), point3(1,2);

	if (point1<point2){
		cout << "point1<point2"<<endl;
	}	

	if (point1>point2){
		cout << "point1>point2"<<endl;
	}	

	if (point1==point3){
		cout << "point1==point3"<<endl;
	}	

	Fraction frac1{6, 2}, frac2{6, 2}, frac3{2, 6};

	int val1 = 3, val2 = 2;

	cout << val2 + frac1 << endl;
	cout << frac1 + val2 << endl;

	if (frac1 == frac2)
	{
		cout << "frac1 == frac2" << endl;
	}

	if (frac1 == frac3)
	{
		cout << "frac1 == frac3" << endl;
	}

	if (frac1 != frac3)
	{
		cout << "frac1 != frac3" << endl;
	}

	if (frac1 > frac3)
	{
		cout << "frac1 > frac3" << endl;
	}

	if (frac3 < frac2)
	{
		cout << "frac3 < frac2" << endl;
	}

	if (frac1 > frac3)
	{
		cout << "frac1 > frac3" << endl;
	}

	if (frac1 < val1)
	{
		cout << "val1 < frac1" << endl;
	}

	if (val1 == frac1)
	{
		cout << "val1 == frac1" << endl;
	}

	if (frac1 == val1)
	{
		cout << "frac1 == val1" << endl;
	}

	if (val1 < frac1)
	{
		cout << "val1 < frac1" << endl;
	}

	ifstream my_file("fraction.txt");

	Fraction my_fraction;

	if (my_file.is_open())
	{
		while (my_file >> my_fraction)
		{
			cout << my_fraction << endl;
		}
	}
	else
	{
		cout << "Cannot open fraction.txt" << endl;
	}
	my_file.close();

	// int val = 1;

	return 0;
}
