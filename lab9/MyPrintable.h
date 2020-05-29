#pragma once
#include <string>

class MyPrintable{
    ///klasa umozliwiajaca prawidlowe przygotowanie tekstu do wydruku
public:  

    /**
     * @brief funkcja zwracająca gotowy do wydruku tekst, w zaleznosci od tego czy jest to teskt czy linia
     * @return - tekst
     */
    virtual std::string rawString() const = 0;
    /**
     * @brief funckja zwracajaca dlugosc tekstu ktory będzie drukowany
     * @return - dlugosc tesktu
     */ 
    virtual unsigned int getLength() const = 0;
};

