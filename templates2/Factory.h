#pragma once
#include <stdexcept>


template <class T>
static bool isInitialized(bool r, bool val)
{
    static bool init=false;
    if(!r)
    {
        init=val;
    }
    return init;
}

template <class T>
static T& object(bool r, T obj)
{
    static T pom;
    if(!r)
    {
        pom = obj;
    }
    return pom;
}

class Factory {

public:
    template <typename T>
    void prototype(T obj)
    {
        isInitialized<T>(false, true);
        object<T>(false, obj);
    }

    template <typename T>
    T& manufacture()
    {
        if(isInitialized<T>(true, true))
        {
            static T tmp;
            return object<T>(true, tmp);
        }
        else
        {
            std::runtime_error e("no prototype for this type");
            throw e;
        }
    }

};


