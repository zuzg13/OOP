#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#pragma once

using std::vector;
using std::string;

class ListaString{

public:
    /**
     * Glosne konstruktory i destruktory
     */
    ListaString() { std::cout << "(list-def-ctor)" << std::endl; }
    ~ListaString() { std::cout << "(list-dtor)" << std::endl; }
    ListaString(const ListaString& cp) : napisy(cp.napisy) { std::cout << "(list-copy-ctor)" << std ::endl;}
    ListaString(ListaString&& mv) noexcept : napisy(std::move(mv.napisy)) { std::cout << "(list-move-ctor)" << std ::endl;}

    static void rob_halas(bool val) {}

    /**
     * @brief Przeładowany operator <<, wczytuje nowe napisy do listy napisow
     * @param ls  - lista napisow
     * @param str - nowy napis
     * @return this
     */
    friend ListaString& operator<<(ListaString &ls, std::string str);
    /**
     * @brief Przeladowany operator<<, pozwala na odpowiednie wyswietlanie listy napisow
     * @param ostr - ostream
     * @param ls - lista napisow do wyswietlenia
     * @return ostr
     */
    friend std::ostream& operator<<(std::ostream& ostr, ListaString &ls);

    /**
     * @brief Przeladowany operator[]
     * @param indx
     * @return element listy o indeksie indx
     */
    string operator[](unsigned int indx) const
    {
        return napisy[indx];
    }

private:
    vector<string> napisy;
};

ListaString& operator<<(ListaString &ls, std::string str)
{
    ls.napisy.push_back(str);
    return ls;
}

std::ostream& operator<<(std::ostream& ostr, ListaString &ls){
    int k=1;
    for(string n : ls.napisy)
    {
        ostr <<k <<". " <<  n << std::endl;
        k++;
    }
    return ostr;
}