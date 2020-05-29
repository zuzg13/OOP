#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <class T> struct A{
    static T val;
    static bool v;
};

template<typename T> T A<T>::val;
template<typename T> bool A<T>::v = false;

class Factory {

public:
    template<typename T>
    void prototype(T obj)
    {
        A<T> t;
        t.val = obj;
        t.v = true;
    }
    template<typename T>
    T& manufacture()
    {
        A<T> t;
        if(t.v)
        {
            A<T> t;
            return t.val;
        }
        else
        {
            std::runtime_error e("no prototype for this type");
            throw e;
        }
    }



};



