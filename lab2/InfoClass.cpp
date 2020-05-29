#include "InfoClass.h"

InfoClass :: InfoClass(string napis)
{   
    mnapis = napis;
    std :: cout << "++ Tworze obiekt InfoClass: info = " << mnapis << std :: endl;
}
InfoClass :: ~InfoClass()
{
    std :: cout << "++ Usuwam obiekt InfoClass: info = "<< mnapis << std :: endl;
}
const string InfoClass :: info() const
{
    return "info = " + mnapis;
}

void InfoClass :: info(const string& a)
{
    mnapis = a;
}

const string InfoSuperClass::info() const
{
    std :: cout << "info = " << mnapis << ", num = " << mliczba << std ::  endl;
    return "info = " + mnapis + ", num = " + std::to_string(mliczba);
}

