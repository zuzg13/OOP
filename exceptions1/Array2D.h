#pragma once
#include <iostream>
#include "BadDimsException.h"


class Array2D {

public:
    Array2D(int x, int y) :  m_x(x), m_y(y)
    {
        m_tab = new int[x*y];
        for(int i=0;i<x*y;i++)
            m_tab[i]=i+1;
    }

    Array2D& operator=(const Array2D& arr)
    {
        if(this != &arr)
        {
            m_x = arr.getX();
            m_y = arr.getY();
            for(int i=0;i<m_x*m_y;i++)
               m_tab[i]=arr.getEl(i);
        }
        return *this;
    }

    int getEl(int indx) const
    {
        return m_tab[indx];
    }

    void reshape(int x, int y)
    {
        if(x*y == m_x*m_y)
        {
            m_x = x;
            m_y = y;
        }
        else
        {
            std::string tmp = "dimensions " + std::to_string(x) + " and " + std::to_string(y) +
                     " do not conform with " + std::to_string(m_x) + " and " +  std::to_string(m_y);
            throw BadDimsException(tmp);
        }
    }
    std::string print(int k) const
    {
        return std::to_string(m_tab[k]);
    }
    int getX() const
    {
        return m_x;
    }
    int getY() const
    {
        return m_y;
    }

    int * operator[](int indx)
    {
        return &(m_tab[m_y*indx]);
    }


    int at(int x, int y) const
    {
        if(x>=m_x)
            throw std::out_of_range("out of range at i=" + std::to_string(x));
        else if(y>=m_y)
            throw std::out_of_range("out of range at j=" + std::to_string(y));
        else
            return m_tab[x*y + y+1];
    }
    int& at(int x, int y)
    {
        if(x>=m_x)
            throw std::out_of_range("out of range at i=" + std::to_string(x));
        else if(y>=m_y)
            throw std::out_of_range("out of range at j=" + std::to_string(y));
        else
            return m_tab[x*y + y];
    }





private:
    int *m_tab;
    int m_x, m_y;

};

std::ostream& operator<<(std::ostream& ostr, Array2D arr)
{
    int k = 0;
    for(int i=0; i<arr.getX();i++)
    {
        for(int j=0;j<arr.getY();j++)
        {
            ostr << arr.print(k) << "\t";
            k++;
        }
        if(i!=arr.getX()-1)
            ostr << std :: endl;
    }
    return ostr;
}
