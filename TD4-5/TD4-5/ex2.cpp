#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "ex2.hpp"

using namespace std;

Fraction::Fraction(const Fraction& fraction) {
	this->num_ = fraction.num_;
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
	if (den != 0) {
		this->den_ = den;
	}
	else {
		cout << "/!\\ You tried to make a den equal to 0 /!\\\n";
	}
}

int Fraction::get_num() const {
	return this->num_;
}

int Fraction::get_den() const {
	return this->den_;
}

int main() {

	ifstream file("../../../../TD4-5/fractionTextFile.txt"); // Opens the file
	if (!file.is_open()) { // If file failed to open, send an error
		cerr << "Failed to open the file." << endl;
		return EXIT_FAILURE;
	}
	
	Fraction frac(1, 1);
	auto& tab = new Fraction;
	char c;
	string line;
	getline(file, line);

	while (c != NULL) {



	}
	

	file.close();
	return EXIT_SUCCESS;

}