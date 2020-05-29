#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "MaszynaStanow.h"

#define STATE_TYPE(napis) class napis : public Stan
using std::string;
using std::vector;

class MaszynaStanow;

class Stan {
public:
    Stan() = default;
    virtual ~Stan() = default;

    /**
     * @brief ustawia wskaznik, element klasy by wskazywal na odpowiednia maszyne stanow
     * @param s - wskaznik na maszyne stanow
     */
    void set(MaszynaStanow *s)
    {
        ms = s;
    }
    ///Funkcje wirtualne umozliwiajace obsluge stanow

    /**
     * umozliwia wykonanie operacji odpowiednich dla danego stanu
     */
    virtual void operator ()() = 0;
    /**
     * wyswietla informacje na temat danego stanu, zebranych danych
    */
    virtual const char* nazwa() const = 0;
    virtual void podsumowanie() const = 0;

protected:
    string mnazwa;
    MaszynaStanow *ms;
};


STATE_TYPE(ZbieranieDanych){

///Stan umozliwiajacy zbieranie danych np. adresu email

public:
    /**
     * konstruktor, wczytujacy odpowiedni adres mailowy
     * @param mail adres
     */
    explicit ZbieranieDanych(string mail);
    /**
     * @return nazwa klasy - stanu
     */
    virtual const char* nazwa() const;
    virtual void podsumowanie() const;
    virtual void operator()();

private:
    string adres;

};

STATE_TYPE(Podsumowanie){

public:
    virtual void podsumowanie() const;
    virtual const char* nazwa() const;
    virtual void operator()();

};

