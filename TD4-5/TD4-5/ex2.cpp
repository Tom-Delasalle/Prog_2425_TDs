#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ex2.hpp"


Fraction::Fraction(const Fraction& fraction) {
	this->num_ = fraction.num_;
	this->den_ = fraction.den_;
}

Fraction::Fraction(const int& num, const int& den) {
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

ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.get_num() << "/" << f.get_den() << " ";
	return os;
}

int main() {

	ifstream file("../../../../TD4-5/fractionTextFile.txt"); // Opens the file
	if (!file.is_open()) { // If file failed to open, send an error
		cerr << "Failed to open the file." << endl;
		return EXIT_FAILURE;
	}
	
	vector<Fraction> tab;
	Fraction frac(1, 1);
	char c;
	int mult = 1, tempNum = 0, tempDen = 0;
	bool isNum = true;

	while (file.get(c)) { // As long as c != NULL 

		if (c >= '0' && c <= '9') {
			if (isNum) {
				tempNum += static_cast<int>((c - 48) * mult); // Converts char into int with the right value thanks to -48
			}
			else {
				tempDen += static_cast<int>((c - 48) * mult); // Converts char into int with the right value thanks to -48
			}
			mult *= 10;
		}
		else if (c == '/') {
			mult = 1;
			!isNum;
			tempNum = 0;
			tempDen = 0;
		}
		else if (c == ',') {
			mult = 1;
			!isNum;
			tempNum = 0;
			tempDen = 0;
			frac.set_num(tempNum);
			frac.set_den(tempDen);
			tab.push_back(frac);
		}
		else {
			cout << "Error : the syntax used in the text file is not respected\n";
			return EXIT_FAILURE;
		}

	}

	// find a way to sort the vector and print it
	sort(tab.begin(), tab.end());
	auto iter = tab.begin();
	while (iter != tab.end()) {
		cout << *iter;
		++iter;
		
	}
	// Fuck this exercise it's pissing me off
	
	file.close();
	return EXIT_SUCCESS;

}