#pragma once

#include <iostream>
#include <vector>
#include "Stan.h"

class Stan;

class MaszynaStanow{

public:
    MaszynaStanow()=default;
    ~MaszynaStanow();


    /**
     * @brief umozliwia poruszanie sie po odpowiednich stnach w maszynie stanow
     * @param st - wskaznik na odpowiedni stan
     * @return this
     */
    MaszynaStanow & operator+= (Stan *st);
    /**
     * @brief umozliwia wykonanie odpowiednich operacji na stanach
     * @return stan, ktory aktualnie wykonuje operacje
     */
    Stan& operator()();

    /**
     * uruchamia maszyne stanow i wyswietla odpowiedni komunikat
     */
    void start();
    /**
     * przeładowany operator++ pozwala poruszac sie po stanach w prawo
    */
    void operator++();
    /**
     * przeładowany operator-- pozwala poruszac sie po stanach w lewo
    */
    void operator--();
    /**
     * wyswietla odpowiednio sformatowane nazwy stanow, jako panel z wybranym aktualnie stanem
     */
    void print(std::ostream & ostr) const;
    /**
     * wyswietla wszystkie informacje zapisane przez stany
     */
    void podsumowanie() const;

private:
    std::vector<Stan*> mlistastanow;
    unsigned int mcurelement;
};


inline std::ostream & operator<< (std::ostream & ostr, const MaszynaStanow & m)
{
    m.print(ostr);
    return ostr;
}
