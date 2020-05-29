#pragma once
#include <iostream>
#include <exception>



class Number {

public:
    explicit Number(double n);
    void print() const;
    Number& value();
    void operator=(double val);
    double value() const;
    static void setRange(double min, double max);


private:
    double m_n;
    static double rangeMin;
    static double rangeMax;
};


