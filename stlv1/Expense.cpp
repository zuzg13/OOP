//
// Created by Zuzia on 06/05/2020.
//

#include "Expense.h"


void Expense :: print() const
{
    std :: cout << m_name << ": ";
    std::for_each(m_tab.begin(), m_tab.end(), [](float el){std::cout << std::setw(6) << el;});
    std :: cout << std :: endl;
}

double Expense :: mean() const
{
    double m = std::accumulate(m_tab.begin(), m_tab.end(), 0.);
    m = m/m_tab.size();
    return m;
}

unsigned int Expense :: size() const
{
    return m_tab.size();
}

double Expense :: operator[](unsigned int indx) const
{
    return m_tab[indx];
}