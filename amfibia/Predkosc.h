#pragma once

#include <iostream>
#include <string>

class PredkoscMaksymalna{
    
    ///klasa reprezentująca predkosc maksymalna
    
public:
    /**
     * @brief konstruktor ustawiajacy predkosc maksymalna
     * @param predkosc - predkosc maksymalna do ustawienia
     */ 
    PredkoscMaksymalna(int predkosc) : m_predkosc(predkosc) {}

    /**
     * @brief zaprzyjazniona funkcja umozliwiajaca wypisywanie informacji o predkosci na ekran
     * @param ostr - strumien wyjsciowy do ktorego przekazujemy informacje do wypisania
     * @param pr - obiekt klasy, o ktorym informacje wypisujemy
     * @return ostr - strumien wyjsciowy do ktorego przekazano informacje
     */ 
    friend std::ostream& operator<<(std::ostream &ostr, PredkoscMaksymalna pr)
    {
        return ostr << pr.predkoscMaksymalna();
    }
    /**
     * @brief funkcja zwracająca informacje o prędkości maksymalnej z dopisaną jednostką
     * @return wartość prędkości maksymalnej z jednostką
     */ 
    std::string predkoscMaksymalna() const
    {
        return std::to_string(m_predkosc) + " km/h";
    }
    
    
private:
    int m_predkosc;
    
    
};
