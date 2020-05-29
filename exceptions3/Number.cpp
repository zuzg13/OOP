#include "Number.h"


Number::Number(double n)
{
    if(n<=rangeMin || n>=rangeMax)
        throw std::out_of_range("Out of range during construction");
    else
        m_n = n;
}

void Number :: print() const
{
    std :: cout << "Number: " << m_n <<" is in the range [" << rangeMin <<", " << rangeMax << "]" << std :: endl;
}

Number& Number :: value()
{
    return *this;
}

void Number :: operator=(double n)
{
    if(n<=rangeMin || n>=rangeMax)
        throw std::out_of_range("Out of range during assignment");
    else
        m_n = n;
}

double Number ::value() const
{
    return m_n;
}

void Number ::setRange(double min, double max)
{
    rangeMin = min;
    rangeMax = max;
}

double Number :: rangeMin = 0.;
double Number :: rangeMax = 0.;