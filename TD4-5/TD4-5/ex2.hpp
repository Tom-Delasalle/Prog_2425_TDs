#pragma once

#include <iostream>
#include <set>

class Fraction
{
private:
    int num_ = 0, den_ = 1;

public:
    Fraction(const Fraction& fraction);
    Fraction(const int& num = 0, const int& den = 1);
    void set_num(const int& num);
    void set_den(const int& den);
    int get_num() const;
    int get_den() const;
};