#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Zwierz.h"

class Farma{
    
    ///klasa reprezentujaca farmę ze zwierzętami i umożliwiająca wykonywanie 
    ///różnych czynności
    
public:
    Farma() = default;
    ~Farma();
    
    /**
     * @brief funkcja dodająca nowe zwierzę do farmy
     * @param zw - nowe zwierze
     */ 
    void dodaj(std::unique_ptr<Zwierz> zw);
    /**
     * @brief funkcja wypisujaca aktualnie znajdujace sie na farmie zwierzeta 
     * oraz dodatkowy naglowek
     * @param str - naglowek do wypisania
     */
    void wypisz(const std::string& str) const;
    /**
     * @brief funkcja zliczaja ilosc wystapien imienia wsrod zwierzat na farmie
     * @str - imie ktorego powtorzenia sa zliczane
     * @return ilosc powtorzen imienia, 0 gdy nie ma imienia wsrod imion zwierzat
     */ 
    int zliczImie(const std::string& imie) const;
    /**
     * @brief wyswietla statystyke imion zwierzat w formie posortowanej alfabetycznie
     * imie: liczba powtorzen
     */
    void statystykaImion() const;
    /**
     * @brief funkcja wyprowadzajaca owce i tworzaca z nich stado
     * @return wektor z ze stadem owiec
     */
    std::vector<Owca*> wyprowadzOwce();

private:
    std::vector<std::shared_ptr<Zwierz>> m_zwierzaki;
    
};
