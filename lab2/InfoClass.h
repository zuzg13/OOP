#include <iostream>
#include <string>
#pragma once

using std::string;

class InfoClass{

public:
    //InfoClass() = default;
    InfoClass(string napis);
    virtual ~InfoClass();
    virtual const string info() const;
    void info(const string& a);

protected:
    string mnapis;

};


class InfoSuperClass : public InfoClass {

public:
    InfoSuperClass(string napis, int liczba) : InfoClass(napis), mliczba{liczba}
    {
        //std :: cout << "++Tworze obiekt InfoClass: info = " << mnapis << std :: endl;
    }
    ~InfoSuperClass()
    {
        //std :: cout << "++Usuwam obiekt InfoClass: info = " << mnapis << std :: endl;
    }
    const string info() const;

private:
    int mliczba;


};
