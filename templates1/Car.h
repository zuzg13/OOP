#pragma once
#include <iostream>
#include <string>

class Car {

public:
    Car(const std::string& marka="") : m_marka(marka) {}
    void print() const
    {
        std :: cout << "Car: " << m_marka << std :: endl;
    }

private:
    std::string m_marka;


};


