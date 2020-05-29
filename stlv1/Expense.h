#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

class Expense {

public:
    Expense(std::string name, std::initializer_list<double> list) : m_tab(list), m_name(name) {}

    void print() const;
    double mean() const;
    unsigned int size() const;
    double operator[](unsigned int indx) const;


private:
    std::vector<double> m_tab;
    std::string m_name;

};


