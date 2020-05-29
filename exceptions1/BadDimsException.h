#pragma once
#include <string>
#include <iostream>

class BadDimsException {

public:
    BadDimsException(std::string exc) : m_exception(exc) {}
    std::string what() const
    {
        return m_exception;
    }

private:
    std::string m_exception;


};

